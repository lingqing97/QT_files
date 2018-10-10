#include "mywidgets.h"
#include "myapplication.h"
#include <QApplication>
#include <QDebug>
#include <QPushButton>
MyWidgets::MyWidgets(QWidget *parent) : QWidget(parent)
{
    QPushButton* button;
    button=new QPushButton("button",this);
    connect(button,SIGNAL(click()),this,SLOT(close()));
    //对button安装消息过滤器，对特定的消息进行截取
    _button=button;
    button->installEventFilter(this);
}
bool MyWidgets::eventFilter(QObject* o,QEvent* e)
{
    if(o==_button&&(e->type()==QEvent::MouseButtonPress
            ||e->type()==QEvent::MouseButtonRelease
                    ||e->type()==QEvent::MouseButtonDblClick))
    {
        qDebug()<<"mouse click";
        return true;    //设置为true，对鼠标点击消息进行劫持
    }
    return QWidget::eventFilter(o,e);   //特别注意，需要返回父类的返回值
}
int main(int argc,char** argv)
{
    MyApplication app(argc,argv);
    MyWidgets w;
    qDebug()<<"start event";
    app.postEvent(&w,new QEvent(QEvent::User));     //使用postEvent后，程序继续往下执行，传递给w的消息在w的消息队列中等待
/*    app.sendEvent(&w,new QEvent(QEvent::User)); */    //使用sendEvent后，程序等待，直到消息被w处理
    qDebug()<<"end event";
    w.show();
    return app.exec();
}
