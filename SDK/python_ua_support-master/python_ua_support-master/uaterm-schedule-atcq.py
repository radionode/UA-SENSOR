#!/usr/bin/python

import serial, time, schedule
# for import pySerial --> pip install pyserial
# for import schedule --> pip install schedule
from serial.tools.list_ports import comports

#initialization and open the port
class AtCommand:
	"""Wrapper for accessing serial devices."""
	def __init__(self, port, baud):
		self.__port = port
		self.__baud = baud
		self.__connection = serial.Serial(port, baud, timeout=1)
		self.motd = "\n".join([line.strip() for line in self.__connection.readlines()])
		self.__connection.timeout = 0
		if not (self.__connection.readable() and self.__connection.writable()):
			raise IOError("Insufficient read/write permissions for port %s." % port)
		if not self.__connection.isOpen():
			print("cannot open serial port")

	def isConnected(self):
		return self.__connection.isOpen()

	def disconnect(self, disconnected=False):
		"""Close the serial connection."""
		if not disconnected:
			self.__connection.flushOutput()
		self.__connection.close()

	def flush(self):
		"""Empties the output buffer."""
		self.__connection.flushOutput()

	def poll(self, wait_for_ok=False):
		"""Poll the serial port for new data."""
		buf = ""
		timeout = 1000
		while True:
			response = self.__connection.readline()
			if response:
				buf = response
				break
			elif not wait_for_ok:
				if timeout > 0:
					timeout -= 1
				else:
					break;
		return buf.strip()

	def send(self, line):
		"""Send a line of text to the serial port.  Will automatically
		be terminated with a line end."""
		self.__connection.write((line.strip() + "\r\n").encode("ASCII"))
		#print("serial.send : " + line.strip())

class PollingService:
	""" params : serial port, baud rate, ap ssid, ap pwd, server url, checkin, datain, interval minutes """
	def __init__(self, port, baud, interval_sec):
		self.__port = port
		"""set interval seconds"""
		self.__interval = interval_sec

		""" rpi & esp32 serial connect """
		self.__serial = AtCommand(port, baud)

		""" serial connect check """
		if not self.__serial.isConnected():
			print("serial disconnected")
			exit()

		print("interval : %d seconds" % self.interval())
		print("### PollingService start ###")
		print("")
		print("")
    
	def interval(self):
		return self.__interval

	""" serial & sensor disconnect """
	def disconnect(self):
		self.__serial.disconnect()

	""" AtCommand version check """
	def getVersion(self):
		self.__serial.flush()
		self.__serial.send("ATCVER")
		res = self.__serial.poll()
		print("%s" % res.decode("ASCII"))
		#print("DEBUG Tuple : %s" % (res,))

	def sensing(self):
		self.__serial.flush()
		self.__serial.send("ATCQ")
		res = self.__serial.poll()
		if res:
			now = time.localtime()
			print("[%04d/%02d/%02d %02d:%02d:%02d]: %s" % (now.tm_year, now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec, res.decode("ASCII")))
			#print("DEBUG Tuple : %s" % (res,))
		else:
			print("timeout\r\n")

if __name__ == '__main__':

	portnames = []
	for port in list(comports()):
		if port[2].startswith("USB VID:PID=04D8:000A"):
			portnames.append(port)
			print(port[0])
			print(port[1])
			print(port[2])

	if len(portnames) >= 1:
		portname = portnames[0][0]
	else:
		portname = "COM3"

	print(portname)
	""" params : serial port, baud rate, interval seconds """
	polling = PollingService(portname, 19200, 1)
	
	polling.getVersion()

	""" seconds timer handler. for sensing AtCommand """
	schedule.every().seconds.do(polling.sensing)

	while True:
		schedule.run_pending()
		time.sleep(1)

	polling.disconnect()
