#!/usr/bin/python

import serial, time
#python -m pip install pyserial
#initialization and open the port

from serial.tools.list_ports import comports

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

#possible timeout values:
#    1. None: wait forever, block call
#    2. 0: non-blocking mode, return immediately
#    3. x, x is bigger than 0, float allowed, timeout block call

ser = serial.Serial()
ser.port = portname
ser.baudrate = 19200
ser.bytesize = serial.EIGHTBITS #number of bits per bytes
ser.parity = serial.PARITY_NONE #set parity check: no parity
ser.stopbits = serial.STOPBITS_ONE #number of stop bits
#ser.timeout = None          #block read
ser.timeout = 1            #non-block read
#ser.timeout = 2              #timeout block read
ser.xonxoff = False     #disable software flow control
ser.rtscts = False     #disable hardware (RTS/CTS) flow control
ser.dsrdtr = False       #disable hardware (DSR/DTR) flow control
ser.writeTimeout = 2     #timeout for write

try: 
	ser.open()
except Exception as e:
	print("error open serial port: " + str(e))
	exit()

if ser.isOpen():
	try:
		while True:
			ser.flushInput() #flush input buffer, discarding all its contents
			ser.flushOutput() #flush output buffer, aborting current output 
			#and discard all that is in buffer

			#write data
			ser.write("ATCD\r\n".encode("ASCII"))
			print("write data: ATCD")

			#time.sleep(0.5)  #give the serial port sometime to receive the data

			numOfLines = 0

			while True:
				response = ser.readline()
				now = time.localtime()

				print("[%04d/%02d/%02d %02d:%02d:%02d]: %s" % (now.tm_year, now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec, response.decode("ASCII")))

				numOfLines = numOfLines + 1

				if (numOfLines >= 1):
					break

			time.sleep(1)

		ser.close()
	except Exception as e1:
		ser.close()
		print("error communicating...: " + str(e1))

else:
	print("cannot open serial port ")