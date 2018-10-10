#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H
#include <QApplication>
#include <QDebug>
class MyApplication : public QApplication
{
public:
    MyApplication(int argc,char** argv):QApplication(argc,argv){}
    virtual bool notify(QObject*,QEvent*);
};

#endif // MYAPPLICATION_H
