#include "mywidget.h"
#include <QApplication>
#include <QLabel>
#include <QIODevice>
#include <QFile>
#include <QBuffer>
#include <QDebug>
#include <QPixmap>
/*
    QIODevice inclode:
    1)QFile
    2)QBuffer
    3)QTcpSocket
    4)QUdpSocket
    5)QDataStream  //QTextStream能做的事情QDataStream都能做。
    6)QTextStream
*/
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
#if 0
    //文件的读写
    QFile file("../eee.txt");
    file.open(QIODevice::ReadWrite);
    file.write("aaa");
    file.write("bbb");
    file.close();
#endif
#if 0
    //内存的读写
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    buffer.write("aaa");
    buffer.write("bbb");
    qDebug()<<buffer.buffer();
    buffer.close();
#endif
#if 0
    //利用内存存发图片
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    QPixmap pic("../aaa.jpg");
    pic.save(&buffer,"JPG");    //将图片数据保存到内存
    buffer.close();

    QPixmap pic2;
    pic2.loadFromData(buffer.buffer(),"JPG");
    QLabel* lable=new QLabel(this);
    lable->setPixmap(pic2);
#endif
#if 0
    QFile file("../test.txt");
    file.open(QIODevice::ReadWrite);
    QDataStream stream(&file);
    stream<<1<<"aaa"<<12.5<<QPoint(1,3);
    int i;
    char* c;
    double d;
    QPoint pt;
    stream>>i>>c>>d>>pt;
    qDebug()<<i<<c<<d<<pt;
    file.close();
#endif
    QFile file("../fff.txt");
    file.open(QIODevice::ReadWrite);
    file.seek(65535);   //不能是空文件，否则无法分配内存
    file.write("1");
    file.close();
    file.open(QIODevice::ReadWrite);
    uchar* ptr=file.map(0,65535);   //申请虚拟内存,返回申请到内存首地址
    *ptr='a';
    ptr[1]='b';
    file.unmap(ptr);    //关闭虚拟内存
    file.close();


}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    MyWidget w;
    w.show();

    return app.exec();
}
