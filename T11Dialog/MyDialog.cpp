#include "MyDialog.h"
#include <QDialog>
#include <QApplication>
#include <QPushButton>
#include <QDebug>
MyDialog::MyDialog(QDialog *parent) : QDialog(parent)
{
    QPushButton* button=new QPushButton("click",this);
    this->connect(button,SIGNAL(click()),this,SLOT(slotClick()));
}
void MyDialog::slotClick()
{
    QDialog* dec=new QDialog;
    QPushButton* button=new QPushButton("click",dec);
    dec->exec();
    qDebug()<<"click";
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MyDialog dialog;
    dialog.show();

    return app.exec();
}
