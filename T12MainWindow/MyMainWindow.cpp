#include "MyMainWindow.h"
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QMouseEvent>
#include <QCursor>
MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent)
{
    /* add menu */
    QMenuBar* menubar=menuBar();
    QMenu* menu=menubar->addMenu("&File");  //注意:菜单栏名称是以"&"开头
    _menu=menu;
    QAction* openAction=menu->addAction("&Open",this,SLOT(slotOpen()),QKeySequence::Open);
    menu->addSeparator();   //添加分隔线
    QAction* saveAction=menu->addAction("&save",this,SLOT(slotOpen()),QKeySequence::Save);
    menu->addSeparator();
    QAction* closeAction=menu->addAction("&Exit",this,SLOT(close()),QKeySequence::Close);
    closeAction->setToolTip("close window");
    /* add toolBar */
    QToolBar* tool=this->addToolBar("MyToolBar");   //添加工具栏
    tool->addAction(openAction);
    tool->addSeparator();   //添加分隔线
    tool->addAction(saveAction);
    tool->addSeparator();
    tool->addAction(closeAction);
    /* add statesBar */
    QStatusBar* statusBar=this->statusBar();
    QLabel* line;
    statusBar->addWidget(line=new QLabel("<font color=red>processing</font>"));

    _view=new MyView;
    this->setCentralWidget(_view);  //将剩余的空间设置为中央主窗口

    /* 设置系统图标 */
    _icon=new QSystemTrayIcon(this);
    _icon->setIcon(QIcon("../ddd.ico"));
    _icon->setToolTip("this is a icon");
    _icon->show();
    _icon->setContextMenu(_menu);
    //当鼠标点击图标时做出反应
    connect(_icon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(slotActivated(QSystemTrayIcon::ActivationReason)));

}
void MyMainWindow::slotOpen()
{
    QString filename=QFileDialog::getOpenFileName(NULL,"open file","","Pic file(*.png *jpg)");
    qDebug()<<filename;
}
void MyMainWindow::mousePressEvent(QMouseEvent* ev)
{
    //执行隐藏菜单的方法
    if(ev->button()==Qt::RightButton)
        _menu->exec(QCursor::pos());    //QCursor::pos()返回鼠标相对于桌面系统的位置
}
void MyMainWindow::slotActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason==QSystemTrayIcon::ActivationReason::Trigger)  //如果点击图标
    {
        //如何窗口是隐藏的，则打开窗口；否则，隐藏窗口
        if(this->isHidden()) this->show();
        else this->hide();
    }
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    MyMainWindow w;
    w.show();

    return app.exec();
}
