#include "mywidgets.h"
#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
MyWidgets::MyWidgets(QWidget *parent) : QWidget(parent)
{

}
void MyWidgets::paintEvent(QPaintEvent* ev)
{
    QPainter p(this);   //init painter

    p.setRenderHint(QPainter::Antialiasing);        //消除锯齿边缘，使图形更优美
    p.translate(100,100);   //向下移动(100,100)
    p.setPen(Qt::SolidLine);
    p.setBrush(Qt::yellow);
    p.setFont(QFont("aaa",40,700,true));

    p.drawLine(QPoint(0,0),QPoint(100,100));
    p.drawEllipse(QPoint(100,100),50,50);
    p.drawPixmap(QPoint(300,0),QPixmap("../aaa.jpg"));
    p.drawText(QPoint(100,300),"hello world");
    p.drawRect(200,200,50,50);
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    MyWidgets w;
    w.show();

    return app.exec();
}
