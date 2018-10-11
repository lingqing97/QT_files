#include <QCoreApplication>
#include "mysignal.h"
#include "myslot.h"
/*
    1)信号的定义必须在signals下，并且不需要实现
    2)槽的定义必须在slots下，并且需要实现
    3)信号和槽通过QObject::connect()连接
    4)当信号被触发时，槽函数被调用

    注意:
    1)实现信号和槽的类，必须是QObject的子类
    2)实现信号和槽的类，必须以宏Q_OBJECT开始
    3)连接信号和槽，要使用SIGNAL和SLOT函数，转换函数为字符串
    4)一个信号可以和多个槽连接，槽函数的调用是不确定的
    5)多个信号可以同时连接一个槽
    6)信号可以连接信号，实现信号的传导
    7)信号和槽的参数应该一样多，且参数类型应该相同
    8)信号和槽都可以重载
    9)信号和槽都可以有默认参数
    10)槽函数可以被普通调用
    11)在槽函数中使用sender可以得到信号调用者

    总结:
    一个类:QObject
    三个宏:Q_OBJECT,SIGNAL,SLOT
    三个保留字:signals,slots,emit
*/
int main(int argc,char** argv)
{
    QCoreApplication app(argc,argv);
    MySignal signal;
    MySlot slot;
    app.connect(&signal,SIGNAL(sig()),&slot,SLOT(slo()));
    emit signal.sig();      //发送一个信号，触发信号槽

    return app.exec();
}
