#ifndef MYSLOT_H
#define MYSLOT_H

#include <QObject>

class MySlot : public QObject
{
    Q_OBJECT
public:
    explicit MySlot(QObject *parent = nullptr);

signals:

public slots:
    void slo();
};

#endif // MYSLOT_H
