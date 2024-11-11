#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SerialPort;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void logMessage(const QString& str);

private Q_SLOTS:
    void readComm(SerialPort*);
    void writeCommAll(void);

private:
    Ui::MainWindow *ui;

    QTimer* commandTimer;

    QVector< SerialPort* > m_listSerialport;
};
#endif // MAINWINDOW_H
