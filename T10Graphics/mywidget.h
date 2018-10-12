#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItemAnimation>    //动画
#include <QPixmap>
#include <QTimer>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    QGraphicsScene* _scene;
    QGraphicsView* _view;
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent*);
signals:

public slots:
    void slotTimeout();
};

#endif // MYWIDGET_H
