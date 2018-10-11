#include "myslot.h"
#include <QDebug>
MySlot::MySlot(QObject *parent) : QObject(parent)
{

}
void MySlot::slo()
{
    qDebug()<<"slot function happen!";
}
