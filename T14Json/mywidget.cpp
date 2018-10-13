#include "mywidget.h"
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCryptographicHash>
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QByteArray md5=QCryptographicHash::hash(QByteArray("wushukun"),QCryptographicHash::Md5);
    QJsonObject obj;
    obj.insert("username",QString("wushukun"));
    obj.insert("password",QString(md5.toHex()));    //使用toHex()将"0x"去掉
    obj.insert("height",170);
    QJsonDocument dcm(obj);
    QByteArray json=dcm.toJson(QJsonDocument::Compact);   //转化为字符串
    qDebug()<<json;

    QJsonDocument dcm2=QJsonDocument::fromJson(json);   //将字符串转化为json文件
    QJsonObject obj2=dcm2.object();
    if(obj2.value("username")=="wushukun")
    {
        qDebug()<<"yes";
    }
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MyWidget w;
    w.show();

    return app.exec();
}
