#ifndef PWM_H
#define PWM_H


class Pwm
{
public:
    int m_nPwmNum;//定义使用的pwm的编号

    unsigned int m_uPeriod;//周期
    unsigned int m_uduty_cycle;//高电平持续时间

    bool m_bpolarity;//极性

    Pwm();//构造函数，给成员变量赋初值

    void Export(int PwmNum);//引出pwm接口

    void UnExport(int PwmNum);//关闭pwm接口

    void EnAble(int PwmNum);//使能pwm

    void DisAble(int PwmNum);//不使能pwm

    void Config( unsigned int period , unsigned int duty_cycle);//pwm设置占空比

    void Polarity(int PwmNum ,bool polarity );//高低电平极性


    void Init(int PwmNum, unsigned int period, unsigned int duty_cycle, bool polarity);
};

#endif // PWM_H
