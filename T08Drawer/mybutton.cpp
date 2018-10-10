#include "mybutton.h"
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
MyButton::MyButton(QWidget *parent) : QWidget(parent)
{
    _press=false;
    update();
}
MyButton::MyButton(const QString& string,QWidget* parent):QWidget(parent),_string(string),_rect(0,0,100,50)
{
    _press=false;
    this->setGeometry(_rect);
    update();
}
void MyButton::paintEvent(QPaintEvent* ev)
{
    QPainter p(this);
    p.setPen(Qt::black);
    if(_press==true)
        p.setBrush(Qt::yellow);
    else
        p.setBrush(Qt::blue);
    p.drawRect(_rect);
    p.drawText(_rect,_string,QTextOption(Qt::AlignCenter)); //设置字体居中
}
void MyButton::mousePressEvent(QMouseEvent* ev)
{
    _press=true;
    update();
}
void MyButton::mouseReleaseEvent(QMouseEvent* ev)
{
    _press=false;
    update();
}
