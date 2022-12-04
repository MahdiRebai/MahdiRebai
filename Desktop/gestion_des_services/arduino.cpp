#include "arduino.h"

#include <QDebug>

arduino::arduino()
{

  data = "";
  arduino_port_name="";
  arduino_is_available=false;
  serial= new QSerialPort;

}
QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}
QSerialPort *arduino::getserial()
{
    return serial;
}
int arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &Serial_port_info,QSerialPortInfo::availablePorts()){
        if(Serial_port_info.hasVendorIdentifier() && Serial_port_info.hasProductIdentifier()){
            if(Serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && Serial_port_info.productIdentifier()==arduino_uno_producy_id){
                arduino_is_available=true;
                arduino_port_name=Serial_port_info.portName();
            }
        }
    }
    qDebug() <<"arduino_port_name is:"<<arduino_port_name;
    if(arduino_is_available){
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}
int arduino::close_arduino()
{
    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;

}
QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable()){
        data=serial->readAll();
        return data;
    }
}

bool arduino::read_bool_from_arduino()
{
    if(serial->waitForReadyRead(3000)){
        QByteArray var = serial->read(1);
        return (bool)var[0];
    }
    qDebug() << "can't read";
    return false;

}


int arduino::write_to_arduino(const char *data)
{

        return serial->write(data);

}
