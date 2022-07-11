#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "v4l2.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<QTimer>
#include "QLabel"
#include "QZXing.h"
#include "pwm.h"
#include "gpio.h"

#define STOP_WAY 0
#define FORWARD_WAY 1
#define BACK_WAY 2
#define LEFT_WAY 3
#define RIGHT_WAY 4



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void video_ini();
    void uart_ini();
    void pwm_gpio_ini();
    void timer_ini();
    pass_data pd;
    pass_data pd_QR;
    QSerialPort  serial3,serial4,serial5;

    Pwm pwm_l,pwm_r,pwm_water;
    Gpio gpio_l_1,gpio_l_2,gpio_r_1,gpio_r_2; //0 1 1 0 forward
    Gpio gpio_water_1,gpio_water_2;

    QTimer *turn_pTimer;
    QTimer *picture_pTimer;
    QTimer *normal_pTimer;

    int turn_flag;
    QString QR_data;

public slots:
    void turn_pro();
    void picture_pro();
    void normal_pro();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
