#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QWidget>
#include <mybutton.h>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent *event);
    QVector<QVector<QPoint>> _lines;

signals:

public slots:
};

#endif // MYWIDGETS_H
