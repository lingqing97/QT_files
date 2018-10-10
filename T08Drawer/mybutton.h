#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QString>
class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    MyButton(const QString& string,QWidget* parent=nullptr);
    bool _press;
    QRect _rect;
    QString _string;
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
signals:

public slots:
};

#endif // MYBUTTON_H
