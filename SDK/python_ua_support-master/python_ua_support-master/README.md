# python_ua_support

Radionode UA Series spec

1. usb cdc class 로 windows, mac, linux 에서 cdc driver 로 잡힌다.
2. VID:04D8, PID:000A usb list description 에서 Vendor id 와 Product id 로 serial port 를 가져온다.
3. 가져온 serial port 로 baudrate : 19200, 1byte to 8bits, parity none, stop 1 bit, flow control OFF 로 접속한다.
4. "ATCD\r\n" machine(windows, mac, linux) --> UA series device 로 전송하면, "ATCD 25.5,30.0\r\n" 으로 UA series device --> machine(windows, mac, linux) 값이 날라온다.

