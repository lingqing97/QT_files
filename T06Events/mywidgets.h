#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QWidget>

class MyWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidgets(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent *);

    void KeyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
signals:

public slots:
};

#endif // MYWIDGETS_H
