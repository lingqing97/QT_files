#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "MyView.h"
#include <QSystemTrayIcon>
class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    MyView* _view;
    QMenu* _menu;
    QSystemTrayIcon* _icon;
    void mousePressEvent(QMouseEvent*);
signals:

public slots:
    void slotOpen();
    void slotActivated(QSystemTrayIcon::ActivationReason);
};

#endif // MYMAINWINDOW_H
