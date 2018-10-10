#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QWidget>
#include <QPushButton>
class MyWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidgets(QWidget *parent = nullptr);
    QPushButton* _button;
    bool eventFilter(QObject* ,QEvent*);
signals:

public slots:
};

#endif // MYWIDGETS_H
