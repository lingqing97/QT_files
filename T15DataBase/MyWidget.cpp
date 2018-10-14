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
    QSqlTableModel model;
    model.setTable("menu"); //打开数据库中的表
    model.setFilter("M_name='milk'");   //设置过滤器，注意字符串需要使用单引号
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
    /* insert data */
    QSqlRecord record=model.record();   //申请一条空的记录
    record.setValue("M_name","aaa");
    record.setValue("M_price",12);
    model.insertRecord(-1,record);
    model.submitAll();

}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
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
    MyWidget2 w;
    w.show();



    return app.exec();
}
