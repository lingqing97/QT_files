#include "MyWidget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QModelIndex>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("wsk201607");
    db.setDatabaseName("takeout_system");
    bool open=db.open();
    if(open)
    {
        qDebug()<<"open db successfully";
    }
    else
    {
        qDebug()<<"error open db "<<db.lastError().text();
        exit(0);
    }
    QSqlTableModel model;
    model.setTable("buy_sent"); //打开数据库中的表
    model.select();     //自动加载数据库表中数据，之后便可以进行读写操作
    int row=model.rowCount();
    for(int i=0;i<row;i++)
    {
        QSqlRecord recode=model.record(i);
        for(int j=0;j<recode.count();j++)
            qDebug()<<recode.value(j);
    }
#if 0
    model.setData(model.index(1,0),"2016201366");
    model.submitAll();  //修改完以后需要提交
#endif

}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MyWidget w;
    w.show();



    return app.exec();
}
