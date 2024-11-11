// serialport.h: interface for the SerialPort class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SERIALPORT_H
#define SERIALPORT_H

//------------------------------------------------------//
#define ASCII_LF	0x0a
#define ASCII_CR	0x0d
#define ASCII_XON	0x11
#define ASCII_XOFF	0x13

/*line status constants*/
#define LS_CTS  0x01
#define LS_DSR  0x02
#define LS_DCD  0x04
#define LS_RI   0x08
#define LS_RTS  0x10
#define LS_DTR  0x20
#define LS_ST   0x40
#define LS_SR   0x80

#include <QtCore>
#include <QQueue>

#if QT_VERSION >= 0x050000
#include <QtSerialPort>
#elif QT_VERSION < 0x050000
#include <QtSerialPort/QSerialPort>
#endif

enum BaudRateType {
//	BAUD50,                //POSIX ONLY
//		BAUD75,                //POSIX ONLY
		BAUD110,
//		BAUD134,               //POSIX ONLY
//		BAUD150,               //POSIX ONLY
//		BAUD200,               //POSIX ONLY
		BAUD300,
		BAUD600,
		BAUD1200,
//		BAUD1800,              //POSIX ONLY
		BAUD2400,
		BAUD4800,
		BAUD9600,
		BAUD14400,     //WINDOWS ONLY
		BAUD19200,
		BAUD38400,
		BAUD56000,             //WINDOWS ONLY
		BAUD57600,
//		BAUD76800,             //POSIX ONLY
		BAUD115200,
		BAUD128000,            //WINDOWS ONLY
		BAUD256000             //WINDOWS ONLY
};

enum DataBitsType {
	DATA_5,
		DATA_6,
		DATA_7,
		DATA_8
};

enum ParityType {
	PAR_NONE,
		PAR_ODD,
		PAR_EVEN,
		PAR_MARK,               //WINDOWS ONLY
		PAR_SPACE
};

enum StopBitsType {
	STOP_1,
		STOP_1_5,               //WINDOWS ONLY
		STOP_2
};

enum FlowType {
	FLOW_OFF,
		FLOW_HARDWARE,
		FLOW_XONXOFF
};


class SerialPort : public QObject
{
	Q_OBJECT

	/*structure to contain port settings*/
	struct PortSettings {
		BaudRateType BaudRate;
		DataBitsType DataBits;
		ParityType Parity;
		StopBitsType StopBits;
		FlowType FlowControl;
		ulong Timeout_Sec;
		ulong Timeout_Millisec;
	};

	public:
		SerialPort(QObject* parent = 0);
		~SerialPort();	
		
		QObject* Parent() const { return parent; }
		bool isConnected() const { return m_bConnected; }
		QQueue<quint8>& queue() { return m_QueueRead; }

		void setParent(QObject* p) { parent = p; }
		bool open(QString&);
		void close();

		bool writeData(const QByteArray &);
		void waitForBytesWritten(int);
		void flush();

		void setPortName(QString portname) { m_sPortName = portname; }
        void setSerialNo(QString serialno) { m_sSerialNo = serialno; }
		void setFlowControl(FlowType);
		void setParity(ParityType);
		void setDataBits(DataBitsType);
		void setStopBits(StopBitsType);
		void setBaudRate(BaudRateType);
		void setDtr(bool set=true);
		void setRts(bool set=true);
		ulong lineStatus(void);
		void setTimeout(ulong, ulong);

		QString portName() const { return m_sPortName; }
        QString serialNo() const { return m_sSerialNo; }
		BaudRateType baudRate() const { return Settings.BaudRate; }
		DataBitsType dataBits() const { return Settings.DataBits; }
		ParityType parity() const { return Settings.Parity; }
		StopBitsType stopBits() const { return Settings.StopBits; }
		FlowType flowControl() const { return Settings.FlowControl; }

	signals:
        void readComm(SerialPort*);

	private slots:
		void readData();

	private:
		QSerialPort* m_serial;

		QString m_sPortName;
        QString m_sSerialNo;
		bool m_bConnected;

		PortSettings Settings;
		QQueue<quint8> m_QueueRead;
		QObject* parent;

		qint32 getBaudRate(BaudRateType);
		QSerialPort::FlowControl getFlowControl(FlowType);
		QSerialPort::Parity getParity(ParityType);
		QSerialPort::DataBits getDataBits(DataBitsType);
		QSerialPort::StopBits getStopBits(StopBitsType);
};

#endif // SERIALPORT_H
