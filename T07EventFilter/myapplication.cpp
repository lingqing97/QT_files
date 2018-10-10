#include "myapplication.h"
#include <QDebug>
#include <QApplication>
bool MyApplication::notify(QObject *o, QEvent *e)
{
    if(this->topLevelWidgets().count()>0)
    {
        QWidget* mainWidget=this->topLevelWidgets().at(0);   //获取主窗口
        if(o==(QObject*)mainWidget&&(e->type()==QEvent::MouseButtonDblClick
                ||e->type()==QEvent::MouseButtonPress
                ||e->type()==QEvent::MouseButtonRelease))
        {
            qDebug()<<"moust click";

        }
    }
    return QApplication::notify(o,e);
}
