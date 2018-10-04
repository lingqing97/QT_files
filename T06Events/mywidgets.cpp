#include "mywidgets.h"
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
MyWidgets::MyWidgets(QWidget *parent) : QWidget(parent)
{

}
/* QApplication截取所有消息 -> 所在应用程序::event函数处理消息 -> event函数调用其他特定的消息处理函数 */
/* 用于截取消息 */
#if 0
bool MyWidgets::event(QEvent* ev)
{

    if(ev->type()==QEvent::MouseButtonPress)    //截取鼠标消息，对鼠标点击消息进行屏蔽
        return true;
    return QWidget::event(ev);
}
#endif
void MyWidgets::mousePressEvent(QMouseEvent* ev)    //鼠标点击消息
{
    QPoint point=ev->pos();     //获取鼠标点击的坐标
    qDebug()<<point;
    if(ev->modifiers()==Qt::ShiftModifier)   //判断是否同时按下了shift键
    {
        qDebug()<<"shift";
    }
    if(ev->modifiers()==Qt::ControlModifier)
    {
        qDebug()<<"ctrl";
    }
    if(ev->modifiers()==Qt::AltModifier)
    {
        qDebug()<<"alt";
    }
}
void MyWidgets::mouseReleaseEvent(QMouseEvent*)
{

}
void MyWidgets::mouseMoveEvent(QMouseEvent *)
{

}
void MyWidgets::KeyPressEvent(QKeyEvent*)
{

}
void MyWidgets::keyReleaseEvent(QKeyEvent*)
{

}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    MyWidgets w;
    w.show();

    return app.exec();
}
