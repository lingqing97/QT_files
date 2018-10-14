#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "MyWidget2.h"
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MYWIDGET_H
