#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QByteArray>

namespace Ui {
class temperature;
}

class temperature : public QDialog
{
    Q_OBJECT

public:
    explicit temperature(QWidget *parent = 0);
    ~temperature();



private slots:
    void readSerial();
    void updateTemperature(QString);

private:
     Ui::temperature *ui;


    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    double temperature_value;
};

#endif // TEMPERATURE_H




