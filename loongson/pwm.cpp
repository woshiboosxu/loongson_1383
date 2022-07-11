#include "pwm.h"
#include <QFile>
#include <QTextStream>
#include <fcntl.h>
#include <stdlib.h>
#define  MAX_BUF     100
Pwm::Pwm()
{

}
void Pwm::Init(int PwmNum, unsigned int period, unsigned int duty_cycle, bool polarity)
{
    m_nPwmNum = PwmNum;
    m_uPeriod = period;
    m_uduty_cycle = duty_cycle;
    m_bpolarity = polarity;
    Pwm::Export(m_nPwmNum);
    Pwm::EnAble(m_nPwmNum);
    Pwm::Config(m_uPeriod , duty_cycle);
    Pwm::Polarity(m_nPwmNum,m_bpolarity);
}
void Pwm::Export(int PwmNum)
{
    switch(PwmNum)
    {
        case 1:
        {
                QFile file("/sys/class/pwm/pwmchip1/export");
                file.open(QIODevice::WriteOnly);
                file.write("0");
                file.close();
                break;
         }
        case 2:
        {
                QFile file("/sys/class/pwm/pwmchip2/export");
                file.open(QIODevice::WriteOnly);
                file.write("0");
                file.close();
                break;
         }
    case 3:
    {
            QFile file("/sys/class/pwm/pwmchip3/export");
            file.open(QIODevice::WriteOnly);
            file.write("0");
            file.close();
            break;
     }
      }
}

void Pwm::UnExport(int PwmNum)
{
    switch(PwmNum)
    {
        case 1:
        {
                QFile file("/sys/class/pwm/pwmchip1/export");
                file.open(QIODevice::WriteOnly);
                file.write("1");
                file.close();
                break;
         }
        case 2:
        {
                QFile file("/sys/class/pwm/pwmchip2/export");
                file.open(QIODevice::WriteOnly);
                file.write("1");
                file.close();
                break;
         }
    case 3:
    {
            QFile file("/sys/class/pwm/pwmchip3/export");
            file.open(QIODevice::WriteOnly);
            file.write("1");
            file.close();
            break;
     }
      }
}

void Pwm::EnAble(int PwmNum)
{
    switch(PwmNum)
        #include <QTextStream>
        #include <fcntl.h>
        #include <stdlib.h>
    {
        case 1:
        {
                QFile file("/sys/class/pwm/pwmchip1/pwm0/enable");
                file.open(QIODevice::WriteOnly);
                file.write("1");
                file.close();
                break;
         }
        case 2:
        {
                QFile file("/sys/class/pwm/pwmchip2/pwm0/enable");
                file.open(QIODevice::WriteOnly);
                file.write("1");
                file.close();
                break;
         }
    case 3:
    {
            QFile file("/sys/class/pwm/pwmchip3/pwm0/enable");
            file.open(QIODevice::WriteOnly);
            file.write("1");
            file.close();
            break;
     }
      }
}


void Pwm::DisAble(int PwmNum)
{
    switch(PwmNum)
    {
        case 1:
        {
                QFile file("/sys/class/pwm/pwmchip1/pwm0/enable");
                file.open(QIODevice::WriteOnly);
                file.write("0");
                file.close();
                break;
         }
        case 2:
        {
                QFile file("/sys/class/pwm/pwmchip2/pwm0/enable");
                file.open(QIODevice::WriteOnly);
                file.write("0");
                file.close();
                break;
         }
    case 3:
    {
            QFile file("/sys/class/pwm/pwmchip3/pwm0/enable");
            file.open(QIODevice::WriteOnly);
            file.write("0");
            file.close();
            break;
     }
      }
}

void Pwm::Config(  unsigned int period , unsigned int duty_cycle)
{

    char buf_p[MAX_BUF];
    char buf_d[MAX_BUF];
    snprintf(buf_p, sizeof(buf_p), "%d", period);
    snprintf(buf_d, sizeof(buf_d), "%d", duty_cycle);
    switch(m_nPwmNum)
    {
        case 1:
        {
                QFile file("/sys/class/pwm/pwmchip1/pwm0/period");
                file.open(QIODevice::WriteOnly);
                file.write(buf_p);
                file.close();

                QFile file1("/sys/class/pwm/pwmchip1/pwm0/duty_cycle");
                file1.open(QIODevice::WriteOnly);
                file1.write(buf_d);
                file1.close();
                break;
         }
        case 2:
        {
                QFile file("/sys/class/pwm/pwmchip2/pwm0/period");
                file.open(QIODevice::WriteOnly);
                file.write(buf_p);
                file.close();

                QFile file1("/sys/class/pwm/pwmchip2/pwm0/duty_cycle");
                file1.open(QIODevice::WriteOnly);
                file1.write(buf_d);
                file1.close();
                break;
         }
    case 3:
    {
            QFile file("/sys/class/pwm/pwmchip3/pwm0/period");
            file.open(QIODevice::WriteOnly);
            file.write(buf_p);
            file.close();

            QFile file1("/sys/class/pwm/pwmchip3/pwm0/duty_cycle");
            file1.open(QIODevice::WriteOnly);
            file1.write(buf_d);
            file1.close();
            break;
     }
      }
}

void Pwm::Polarity(int PwmNum ,bool polarity )
{
    switch(PwmNum)
    {
        case 1:
        {
                QFile file("/sys/class/pwm/pwmchip1/pwm0/polarity");
                file.open(QIODevice::WriteOnly);
                if(polarity)file.write("normal");
                else file.write("inversed");
                file.close();
                break;
         }
        case 2:
        {
                QFile file("/sys/class/pwm/pwmchip2/pwm0/polarity");
                file.open(QIODevice::WriteOnly);
                if(polarity)file.write("normal");
                else file.write("inversed");
                file.close();
                break;
         }
    case 3:
    {
            QFile file("/sys/class/pwm/pwmchip3/pwm0/polarity");
            file.open(QIODevice::WriteOnly);
            if(polarity)file.write("normal");
            else file.write("inversed");
            file.close();
            break;
     }
      }
}

