#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "radionodedeviceinfo.h"
#include "serialport.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList nameList = ::radioNodeDevPorts();
    QStringListIterator iter(nameList);
    while (iter.hasNext()) {
        QString portName = iter.next();
        portName.remove("/");
        portName.remove("dev");
        QString msg = "[FOUND] comport [" + portName + "]";
        logMessage(msg);

        SerialPort* serial = new SerialPort(this);

        if (serial->open(portName)) {
            connect(serial, SIGNAL(readComm(SerialPort*)), this, SLOT(readComm(SerialPort*)));
            serial->writeData("ATCMODEL\r\n");

            m_listSerialport << serial;

            QString msg = "[OPEN SUCCESS!] comport [" + portName + "]";
            logMessage(msg);
        } else {
            delete serial;
            QString msg = "[OPEN FAILED!] comport [" + portName + "]";
            logMessage(msg);
        }
    }

    commandTimer = new QTimer(this);
    connect(commandTimer, SIGNAL(timeout()), this, SLOT(writeCommAll()));
    commandTimer->start(1000);
}

MainWindow::~MainWindow()
{
    QVectorIterator<SerialPort*> iter(m_listSerialport);
    while (iter.hasNext()) {
        SerialPort* serial = iter.next();
        serial->close();
        delete serial;
    }
    m_listSerialport.clear();
    delete ui;
}

void MainWindow::readComm(SerialPort* serial)
{
    QByteArray arr;
    while (!serial->queue().isEmpty()) {
        quint8 aByte = serial->queue().dequeue();
        if (aByte != '\r' && aByte != '\n')
        arr.append(aByte);
    }
    if (QString(arr).contains("ATCMODEL")) {
        QString serialno(arr);
        serialno.remove("ATCMODEL ");
        serial->setSerialNo(serialno);
    }

    QString msg = "readComm() [" + serial->portName() + "][" + serial->serialNo() + "] : " + arr;
    logMessage(msg);
}

void MainWindow::writeCommAll()
{
    QString cmd = "ATCD\r\n";
    QVectorIterator<SerialPort*> iter(m_listSerialport);
    while (iter.hasNext()) {
        SerialPort* serial = iter.next();
        serial->writeData(cmd.toLatin1());
        QString msg = "WriteComm() [" + serial->portName() + "][" + serial->serialNo() + "] : " + cmd;
    }
}

void MainWindow::logMessage(const QString& str)
{
    ui->textEdit->append(str + "\r\n");
}
