#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QObject>
#include <QDialog>

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    MyDialog(QDialog *parent = nullptr);

signals:

public slots:
    void slotClick();
};

#endif // MYDIALOG_H
