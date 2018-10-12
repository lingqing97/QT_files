#ifndef MYVIEW_H
#define MYVIEW_H

#include <QWidget>

class MyView : public QWidget
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:

public slots:
};

#endif // MYVIEW_H
