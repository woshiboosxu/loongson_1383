#include "gpio.h"
#include <QFile>
#include <QTextStream>
Gpio::Gpio()
{

}

void Gpio::Init_1(int gpionum, bool value)
{
    m_ngpionum = gpionum;
    m_bvalue = value;
    Gpio::Export(m_ngpionum);
    Gpio::Direction(m_ngpionum);
    Gpio::Value(m_bvalue);
}

void Gpio::Export(int GpioNum)
{
    switch(GpioNum)
    {
        case 48:
        {
                QFile file("/sys/class/gpio/export");
                file.open(QIODevice::WriteOnly);
                file.write("48");
                file.close();
                break;
         }
        case 49:
        {
                QFile file("/sys/class/gpio/export");
                file.open(QIODevice::WriteOnly);
                file.write("49");
                file.close();
                break;
         }
    case 50:
    {
            QFile file("/sys/class/gpio/export");
            file.open(QIODevice::WriteOnly);
            file.write("50");
            file.close();
            break;
     }
    case 51:
    {
            QFile file("/sys/class/gpio/export");
            file.open(QIODevice::WriteOnly);
            file.write("51");
            file.close();
            break;
     }
    case 52:
    {
            QFile file("/sys/class/gpio/export");
            file.open(QIODevice::WriteOnly);
            file.write("52");
            file.close();
            break;
     }
    case 53:
    {
            QFile file("/sys/class/gpio/export");
            file.open(QIODevice::WriteOnly);
            file.write("53");
            file.close();
            break;
     }
      }
}

void Gpio::Direction(int GpioNum)
{
    switch(GpioNum)
    {
        case 48:
        {
                QFile file("/sys/class/gpio/gpio48/direction");
                file.open(QIODevice::WriteOnly);
                file.write("out");
                file.close();
                break;
         }
        case 49:
        {
                QFile file("/sys/class/gpio/gpio49/direction");
                file.open(QIODevice::WriteOnly);
                file.write("out");
                file.close();
                break;
         }
    case 50:
    {
            QFile file("/sys/class/gpio/gpio50/direction");
            file.open(QIODevice::WriteOnly);
            file.write("out");
            file.close();
            break;
     }
    case 51:
    {
            QFile file("/sys/class/gpio/gpio51/direction");
            file.open(QIODevice::WriteOnly);
            file.write("out");
            file.close();
            break;
     }
    case 52:
    {
            QFile file("/sys/class/gpio/gpio52/direction");
            file.open(QIODevice::WriteOnly);
            file.write("out");
            file.close();
            break;
     }
    case 53:
    {
            QFile file("/sys/class/gpio/gpio53/direction");
            file.open(QIODevice::WriteOnly);
            file.write("out");
            file.close();
            break;
     }
      }
}

void Gpio::Value(bool value)
{
    switch(m_ngpionum)
    {
        case 48:
        {
                QFile file("/sys/class/gpio/gpio48/value");
                file.open(QIODevice::WriteOnly);
                if(value) file.write("1");
                else file.write("0");
                file.close();
                break;
         }
        case 49:
        {
                QFile file("/sys/class/gpio/gpio49/value");
                file.open(QIODevice::WriteOnly);
                if(value) file.write("1");
                else file.write("0");
                file.close();
                break;
         }
    case 50:
    {
            QFile file("/sys/class/gpio/gpio50/value");
            file.open(QIODevice::WriteOnly);
            if(value) file.write("1");
            else file.write("0");
            file.close();
            break;
     }
    case 51:
    {
            QFile file("/sys/class/gpio/gpio51/value");
            file.open(QIODevice::WriteOnly);
            if(value) file.write("1");
            else file.write("0");
            file.close();
            break;
     }
    case 52:
    {
            QFile file("/sys/class/gpio/gpio52/value");
            file.open(QIODevice::WriteOnly);
            if(value) file.write("1");
            else file.write("0");
            file.close();
            break;
     }
    case 53:
    {
            QFile file("/sys/class/gpio/gpio53/value");
            file.open(QIODevice::WriteOnly);
            if(value) file.write("1");
            else file.write("0");
            file.close();
            break;
     }
      }
}


