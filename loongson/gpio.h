#ifndef GPIO_H
#define GPIO_H


class Gpio
{
public:
    int m_ngpionum;//Gpio引脚号
    bool m_bvalue;//高低电平

    Gpio();//构造函数，调用该函数可以给Gpio类成员赋初值

    void Export(int GpioNum);//引脚向外引出，用户可操作

    void Direction(int GpioNum);//定义io口 in/out

    void Value(bool value);//定义Gpio口的高低电平


    void Init_1(int gpionum, bool value);
};

#endif // GPIO_H
