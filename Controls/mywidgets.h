#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QWidget>
#include <QTextEdit>
class Mywidgets : public QWidget
{
    Q_OBJECT
public:
    explicit Mywidgets(QWidget *parent = nullptr);
    QTextEdit* _edit;
signals:

public slots:
    void currentTextChangedDisplay(const QString str);
};

#endif // MYWIDGETS_H
