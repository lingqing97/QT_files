#include "mywidget.h"
#include <QApplication>
#include <QTimeLine>
#include <QMouseEvent>
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QGraphicsLineItem* line;
    QGraphicsTextItem* text;
    _view=new QGraphicsView(this);
    _scene=new QGraphicsScene(this);
    _view->setScene(_scene);
    _scene->addItem(line=new QGraphicsLineItem(QLineF(QPointF(300,300),QPointF(450,450))));
    _scene->addItem(text=new QGraphicsTextItem("hello world"));
    text->setPos(QPointF(200,200));
    text->setFont(QFont("aaa",50,100,true));
    QGraphicsPixmapItem* pixmap;
    _scene->addItem(pixmap=new QGraphicsPixmapItem(QPixmap("../aaa.jpg")));
    pixmap->setPos(QPointF(200,200));

    /*设置一段图片沿直线运动的动画*/
    QGraphicsItemAnimation* animation=new QGraphicsItemAnimation;
    animation->setItem(pixmap);
    QTimeLine* timeline=new QTimeLine;
    timeline->setLoopCount(2);
    animation->setTimeLine(timeline);
    animation->setTranslationAt(1,400,400);
    timeline->start();
#if 0
    //计时器不断执行,不停打印time out
    QTimer* timer=new QTimer(this);
    timer->setInterval(1000);   //设置计时时间
    this->connect(timer,SIGNAL(timeout()),this,SLOT(slotTimeout()));
    timer->start();
#endif
    QTimer::singleShot(1000,this,SLOT(slotTimeout()));      //使用singleShot只执行一次计时器s
}
void MyWidget::resizeEvent(QResizeEvent *event)
{
    _view->setGeometry(0,0,size().width(),size().height());
}
void MyWidget::mousePressEvent(QMouseEvent* ev)
{
    if(ev->button()==Qt::RightButton)
    {
        QPixmap pixmap(size()); //使用QPixmap时需要注意需要初始化大小，否则无法执行接下来的画图动作
        QPainter p(&pixmap);
        p.fillRect(QRect(0,0,size().width(),size().height()),Qt::white);
        _view->render(&p);  //render函数，将scene中的情景渲染到pixmap中
        pixmap.save("../ccc.jpg");
    }
}
void MyWidget::slotTimeout()
{
    qDebug()<<"time out";
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MyWidget w;
    w.show();

    return app.exec();
}
