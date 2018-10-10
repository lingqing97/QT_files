#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QWidget>

class MyWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidgets(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // MYWIDGETS_H
