#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    turn_flag=FORWARD_WAY;

    video_ini();
    uart_ini();
    pwm_gpio_ini();
    turn_pTimer = new QTimer(this);
    connect(turn_pTimer, SIGNAL(timeout()), this, SLOT(turn_pro()));
    turn_pTimer->start(100); // ms     1000 =1s
    picture_pTimer = new QTimer(this);
    connect(picture_pTimer, SIGNAL(timeout()), this, SLOT(picture_pro()));
    picture_pTimer->start(1000); // ms

    normal_pTimer = new QTimer(this);
    connect(normal_pTimer, SIGNAL(timeout()), this, SLOT(normal_pro()));
    normal_pTimer->start(100);
}
void MainWindow::normal_pro()
{
    serial3.write("O_12\r\n");

    QString tmp_data_read;
    if(QR_data.contains("floor"))
    {
        ui->tmp_show;
    }

 //   tmp_data_read=ui->tmp_read->toPlainText();
}

void MainWindow::turn_pro()
{

    switch(turn_flag)
    {

    case STOP_WAY:
    {
        gpio_l_1.Value(0);
        gpio_l_2.Value(0);
        gpio_l_1.Value(0);
        gpio_l_2.Value(0);
        break;
     }
    case FORWARD_WAY:
    {
        gpio_l_1.Value(0);
        gpio_l_2.Value(1);
        gpio_l_1.Value(1);
        gpio_l_2.Value(0);
            break;
     }
    case BACK_WAY:
    {
        gpio_l_1.Value(1);
        gpio_l_2.Value(0);
        gpio_l_1.Value(0);
        gpio_l_2.Value(1);
            break;
     }
    case LEFT_WAY:
    {
        gpio_l_1.Value(1);
        gpio_l_2.Value(0);
        gpio_l_1.Value(1);
        gpio_l_2.Value(0);
            break;
     }
    case RIGHT_WAY:
    {
        gpio_l_1.Value(0);
        gpio_l_2.Value(1);
        gpio_l_1.Value(0);
        gpio_l_2.Value(1);
            break;
     }
      }



    /*
    if( tmp_data_read.isEmpty())
    {

    }
    else {
        turn_flag=tmp_data_read.toInt();
    }

    */
}

void MainWindow::picture_pro()
{

    QImage Qtemp ;

    read_frame(&pd);

    Qtemp.load("/home/loongson/s.jpg");
  //  Qtemp.loadFromData((const uchar *)pd.buffers[pd.buf.index].start,pd.buffers[pd.buf.index].length);
    return_data(&pd);
    if(Qtemp.isNull())
    {
        qDebug("empty image" );

    }
    Qtemp.save("/home/loongson/s.jpg", "JPG", -1);

    QMatrix matrix;
        matrix.rotate(180.0);
        Qtemp = Qtemp.transformed(matrix,Qt::FastTransformation);

    QImage newImg = Qtemp.scaled(ui->show_label->width(), ui->show_label->height());
    ui->show_label->setPixmap(QPixmap::fromImage(newImg));

    QZXing decoder;
      decoder.setDecoder(QZXing::DecoderFormat_QR_CODE);
     QR_data= decoder.decodeImage(Qtemp);
    ui->tmp_read->setText(QR_data);
}







void MainWindow::video_ini()
{
    pd.dev_name =  "/dev/video0";
    int flag = init_dev(&pd);
    printf("01");
    if(flag ==-1)
    {
        qDebug("no device");
    }
    else if (flag == -2)
    {

        qDebug("device is wrong");
    }
    else if (flag== -3)
    {

        qDebug("can not open device");
    }

   /*
    pd_QR.dev_name =  "/dev/video1";
      init_dev(&pd_QR);

   */




}
void MainWindow::uart_ini()
{
    QList<QSerialPortInfo>  infos = QSerialPortInfo::availablePorts();
    if(infos.isEmpty())
        {

             printf("error");
            return ;
        }

    serial3.close();
    serial3.setPort(infos[3]);
    serial3.open(QIODevice::ReadWrite);         //????????????

    serial3.setBaudRate(QSerialPort::Baud115200);  //?????????
    serial3.setDataBits(QSerialPort::Data8);     //?????????
    serial3.setParity(QSerialPort::NoParity);    //???????????????
    serial3.setStopBits(QSerialPort::OneStop);   //????????????
    serial3.setFlowControl(QSerialPort::NoFlowControl);  //?????????

}
void MainWindow::pwm_gpio_ini()
{
    pwm_l.Init(1,5000000,1500000,1);
    pwm_r.Init(2,5000000,1500000,1);

    gpio_l_1.Init_1(49,0);
    gpio_l_2.Init_1(48,1);
    gpio_r_1.Init_1(50,1);
    gpio_r_2.Init_1(51,0);


    pwm_water.Init(3,5000000,1500000,1);
    gpio_water_1.Init_1(52,1);
    gpio_water_2.Init_1(53,0);

    /*
    pwm_l.Config(5000000,1500000);
    pwm_r.Config(5000000,1500000);
    gpio_l_1.Value(1);
    gpio_l_2.Value(0);
     */
}


MainWindow::~MainWindow()
{
    delete ui;
    stop_dev(&pd);
    gpio_l_1.Init_1(51,0);
    gpio_l_2.Init_1(50,0);
    gpio_r_1.Init_1(48,0);
    gpio_r_2.Init_1(49,0);
    gpio_water_1.Init_1(52,0);
    gpio_water_2.Init_1(53,0);
}
