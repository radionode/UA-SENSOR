#include "radionodedeviceinfo.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

/* Public methods */
const QString radioNodeDevPort()
{
    QString portName;

	QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();

	foreach (QSerialPortInfo info, serialPortInfoList) {
		QString vid, pid;
		vid.sprintf("%04X", info.vendorIdentifier());
		pid.sprintf("%04X", info.productIdentifier());
		if (vid.toUpper().contains(QLatin1String("04D8")) &&
				pid.toUpper().contains(QLatin1String("000A"))) {
            portName = info.portName();
            if (portName.contains(QLatin1String("cu."))) continue;
            return portName;
		}
	}

    return portName;
}

const QStringList radioNodeDevPorts()
{
    QStringList nameList;

	QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();

	foreach (QSerialPortInfo info, serialPortInfoList) {
		QString vid, pid;
		vid.sprintf("%04X", info.vendorIdentifier());
		pid.sprintf("%04X", info.productIdentifier());
		if (vid.toUpper().contains(QLatin1String("04D8")) &&
				pid.toUpper().contains(QLatin1String("000A"))) {
			QString portName = info.portName();
            if (portName.contains(QLatin1String("cu."))) continue;
            nameList << portName;
		}
	}

    return nameList;
}
