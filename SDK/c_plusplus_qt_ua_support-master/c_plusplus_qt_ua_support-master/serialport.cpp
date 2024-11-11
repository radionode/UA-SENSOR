// SerialPort.cpp: implementation of the SerialPort class.
//
//////////////////////////////////////////////////////////////////////

#include "serialport.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
SerialPort::SerialPort(QObject* parent)
	: QObject(parent)
{
	m_sPortName = "";
	m_bConnected = false;

	m_serial = new QSerialPort(this);
	connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));

	memset(&Settings, 0, sizeof(PortSettings));
	// default setting
	Settings.BaudRate = BAUD19200;
	Settings.DataBits = DATA_8;
	Settings.Parity = PAR_NONE;
	Settings.StopBits = STOP_1;
	Settings.FlowControl = FLOW_OFF;
	Settings.Timeout_Sec = 1;
	Settings.Timeout_Millisec = 1000;
}

SerialPort::~SerialPort()
{
	close();
}

bool SerialPort::open(QString& sPortName)
{
	if (isConnected()) close();

	m_serial->setBaudRate(getBaudRate(Settings.BaudRate));
	m_serial->setDataBits(getDataBits(Settings.DataBits));
	m_serial->setParity(getParity(Settings.Parity));
	m_serial->setStopBits(getStopBits(Settings.StopBits));
	m_serial->setFlowControl(getFlowControl(Settings.FlowControl));

qDebug() << "MainController serial port:[" << sPortName << "] opening...";
	m_serial->setPortName(sPortName);
	m_bConnected = m_serial->open(QSerialPort::ReadWrite);
    if (m_bConnected) m_sPortName = sPortName;
    flush();
	return m_bConnected;
}

void SerialPort::close()
{
	m_bConnected = false;

	m_serial->close();
}

void SerialPort::flush()
{
	if (isConnected())
		m_serial->flush();
}

bool SerialPort::writeData(const QByteArray &data)
{
	bool ret = false;
	if (!m_serial->isOpen()) return ret;
	if (m_serial->write(data) > 0) {
		qDebug() << "SerialPort writeData() : [" << m_sPortName << "] :" << QString(data).replace("\n", "");
		ret = true;
	} else {
		qDebug() << "SerialPort write error.[" << m_sPortName << "]";
	}
	return ret;
}

void SerialPort::readData()
{
	QByteArray output(m_serial->readAll());
	//qDebug()<< "SerialPort readData() : [" << m_sPortName << "] :" << output;

	foreach (quint8 byte, output) {
		queue().enqueue(byte);
	}

    emit readComm(this);
}

void SerialPort::waitForBytesWritten(int msec)
{
	if (isConnected())
		m_serial->waitForBytesWritten(msec);
}

qint32 SerialPort::getBaudRate(BaudRateType type)
{
	qint32 ret = 0;
	switch (type) {
	//case BAUD50: ret = 50; break;                //POSIX ONLY
	//case BAUD75: ret = 75; break;                //POSIX ONLY
	case BAUD110: ret = 110; break;
	//case BAUD134: ret = 134; break;               //POSIX ONLY
	//case BAUD150: ret = 150; break;               //POSIX ONLY
	//case BAUD200: ret = 200; break;               //POSIX ONLY
	case BAUD300: ret = 300; break;
	case BAUD600: ret = 600; break;
	case BAUD1200: ret = 1200; break;
	//case BAUD1800: ret = 1800; break;              //POSIX ONLY
	case BAUD2400: ret = 2400; break;
	case BAUD4800: ret = 4800; break;
	case BAUD9600: ret = 9600; break;
	case BAUD14400: ret = 14400; break;     //WINDOWS ONLY
	case BAUD19200: ret = 19200; break;
	case BAUD38400: ret = 38400; break;
	case BAUD56000: ret = 56000; break;             //WINDOWS ONLY
	case BAUD57600: ret = 57600; break;
	//case BAUD76800: ret = 76800; break;             //POSIX ONLY
	case BAUD115200: ret = 115200; break;
	case BAUD128000: ret = 128000; break;            //WINDOWS ONLY
	case BAUD256000: ret = 256000; break;             //WINDOWS ONLY
	}
	return ret;
}

QSerialPort::FlowControl SerialPort::getFlowControl(FlowType type)
{
	QSerialPort::FlowControl ret;
	switch (type) {
	case FLOW_OFF: ret = QSerialPort::NoFlowControl; break;
	case FLOW_HARDWARE: ret = QSerialPort::HardwareControl; break;
	case FLOW_XONXOFF: ret = QSerialPort::SoftwareControl; break;
	}
	return ret;
}

QSerialPort::Parity SerialPort::getParity(ParityType type)
{
	QSerialPort::Parity ret;
	switch (type) {
	case PAR_NONE: ret = QSerialPort::NoParity; break;
	case PAR_ODD: ret = QSerialPort::OddParity; break;
	case PAR_EVEN: ret = QSerialPort::EvenParity; break;
	case PAR_MARK: ret = QSerialPort::MarkParity; break;
	case PAR_SPACE: ret = QSerialPort::SpaceParity; break;
	}
	return ret;
}

QSerialPort::DataBits SerialPort::getDataBits(DataBitsType type)
{
	QSerialPort::DataBits ret;
	switch (type) {
	case DATA_5: ret = QSerialPort::Data5; break;
	case DATA_6: ret = QSerialPort::Data6; break;
	case DATA_7: ret = QSerialPort::Data7; break;
	case DATA_8: ret = QSerialPort::Data8; break;
	}
	return ret;
}

QSerialPort::StopBits SerialPort::getStopBits(StopBitsType type)
{
	QSerialPort::StopBits ret;
	switch (type) {
	case STOP_1: ret = QSerialPort::OneStop; break;
	case STOP_1_5: ret = QSerialPort::OneAndHalfStop; break;
	case STOP_2: ret = QSerialPort::TwoStop; break;
	}
	return ret;
}

/*!
\fn void SerialPort::setTimeout(ulong sec, ulong millisec);
Sets the read and write timeouts for the port to sec seconds and millisec milliseconds.
*/
void SerialPort::setTimeout(ulong /*sec*/, ulong /*millisec*/)
{
}

void SerialPort::setFlowControl(FlowType flow)
{
    if (Settings.FlowControl!=flow) {
        Settings.FlowControl=flow;
    }
}

/*!
\fn void SerialPort::setParity(ParityType parity)
Sets the parity associated with the serial port.  The possible values of parity are:
\verbatim
    PAR_SPACE       Space Parity
    PAR_MARK        Mark Parity
    PAR_NONE        No Parity
    PAR_EVEN        Even Parity
    PAR_ODD         Odd Parity
\endverbatim
*/
void SerialPort::setParity(ParityType parity)
{
    if (Settings.Parity!=parity) {
        Settings.Parity=parity;
    }
}

/*!
\fn void SerialPort::setDataBits(DataBitsType dataBits)
Sets the number of data bits used by the serial port.  Possible values of dataBits are:
\verbatim
    DATA_5      5 data bits
    DATA_6      6 data bits
    DATA_7      7 data bits
    DATA_8      8 data bits
\endverbatim

\note
This function is subject to the following restrictions:
\par
    5 data bits cannot be used with 2 stop bits.
\par
    1.5 stop bits can only be used with 5 data bits.
\par
    8 data bits cannot be used with space parity on POSIX systems.

*/
void SerialPort::setDataBits(DataBitsType dataBits)
{
    if (Settings.DataBits != dataBits) {
        if ((Settings.StopBits == STOP_2 && dataBits == DATA_5) ||
            (Settings.StopBits == STOP_1_5 && dataBits != DATA_5)) {
        } else {
            Settings.DataBits=dataBits;
        }
    }
}

/*!
\fn void SerialPort::setStopBits(StopBitsType stopBits)
Sets the number of stop bits used by the serial port.  Possible values of stopBits are:
\verbatim
    STOP_1      1 stop bit
    STOP_1_5    1.5 stop bits
    STOP_2      2 stop bits
\endverbatim

\note
This function is subject to the following restrictions:
\par
    2 stop bits cannot be used with 5 data bits.
\par
    1.5 stop bits cannot be used with 6 or more data bits.
\par
    POSIX does not support 1.5 stop bits.
*/
void SerialPort::setStopBits(StopBitsType stopBits)
{
    if (Settings.StopBits!=stopBits) {
        if ((Settings.DataBits==DATA_5 && stopBits==STOP_2) ||
            (stopBits==STOP_1_5 && Settings.DataBits!=DATA_5)) {
        }
        else {
            Settings.StopBits=stopBits;
        }
    }
}

/*!
\fn void SerialPort::setBaudRate(BaudRateType baudRate)
Sets the baud rate of the serial port.  Note that not all rates are applicable on
all platforms.  The following table shows translations of the various baud rate
constants on Windows(including NT/2000) and POSIX platforms.  Speeds marked with an *
are speeds that are usable on both Windows and POSIX.
\verbatim

  RATE          Windows Speed   POSIX Speed
  -----------   -------------   -----------
   BAUD50                 110          50
   BAUD75                 110          75
  *BAUD110                110         110
   BAUD134                110         134.5
   BAUD150                110         150
   BAUD200                110         200
  *BAUD300                300         300
  *BAUD600                600         600
  *BAUD1200              1200        1200
   BAUD1800              1200        1800
  *BAUD2400              2400        2400
  *BAUD4800              4800        4800
  *BAUD9600              9600        9600
   BAUD14400            14400        9600
  *BAUD19200            19200       19200
  *BAUD38400            38400       38400
   BAUD56000            56000       38400
  *BAUD57600            57600       57600
   BAUD76800            57600       76800
  *BAUD115200          115200      115200
   BAUD128000          128000      115200
   BAUD256000          256000      115200
\endverbatim
*/
void SerialPort::setBaudRate(BaudRateType baudRate)
{
	if (Settings.BaudRate != baudRate) {
		Settings.BaudRate = baudRate;
	}
}

/*!
\fn void SerialPort::setDtr(bool set)
Sets DTR line to the requested state (high by default).  This function will have no effect if
the port associated with the class is not currently open.
*/
void SerialPort::setDtr(bool set)
{
	m_serial->setDataTerminalReady(set);
}

/*!
\fn void SerialPort::setRts(bool set)
Sets RTS line to the requested state (high by default).  This function will have no effect if
the port associated with the class is not currently open.
*/
void SerialPort::setRts(bool set)
{
	m_serial->setRequestToSend(set);
}

/*!
\fn ulong SerialPort::lineStatus(void)
returns the line status as stored by the port function.  This function will retrieve the states
of the following lines: DCD, CTS, DSR, and RI.  On POSIX systems, the following additional lines
can be monitored: DTR, RTS, Secondary TXD, and Secondary RXD.  The value returned is an unsigned
long with specific bits indicating which lines are high.  The following constants should be used
to examine the states of individual lines:

\verbatim
Mask        Line
------      ----
LS_CTS      CTS
LS_DSR      DSR
LS_DCD      DCD
LS_RI       RI
\endverbatim

This function will return 0 if the port associated with the class is not currently open.
*/
ulong SerialPort::lineStatus(void)
{
	unsigned long Status = 0;
	if (m_serial->isRequestToSend()) {
        Status |= LS_CTS;
    }
	if (m_serial->isDataTerminalReady()) {
        Status |= LS_DSR;
    }
    return Status;
}
