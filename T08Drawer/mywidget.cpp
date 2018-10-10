#include "mywidget.h"
#include <QApplication>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    MyButton* button=new MyButton("button",this);
}
void MyWidget::paintEvent(QPaintEvent* ev)  //被调用的三种情况:1.窗口初始化时被调用 2.程序调用update时调用 3.系统认为需要调用时（窗口放大，缩小等）
{
    QPainter p(this);
    for(int i=0;i<_lines.size();i++)
    {
        QVector<QPoint> line=_lines.at(i);
        for(int j=0;j<line.size()-1;j++)
            p.drawLine(line[j],line[j+1]);
    }
}
void MyWidget::mouseMoveEvent(QMouseEvent* ev)
{
    QVector<QPoint>& lastline=_lines.last();
    lastline.append(ev->pos());
    update();       //鼠标移动，调用paintevent函数刷新窗口
}
void MyWidget::mousePressEvent(QMouseEvent* ev)
{
    QVector<QPoint> line;
    _lines.append(line);
    QVector<QPoint>& lastline=_lines.last();
    lastline.append(QPoint(ev->pos()));
}
void MyWidget::mouseReleaseEvent(QMouseEvent* ev)
{
    if(_lines.size()==0)    //防止在鼠标从子窗口移动到父窗口后释放
    {
        QVector<QPoint> line;
        _lines.append(line);
    }
    QVector<QPoint>& lastline=_lines.last();
    lastline.append(QPoint(ev->pos()));
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    MyWidget w;
    w.show();

    return app.exec();
}
