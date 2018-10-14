#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QSqlDatabase>

#include <QSqlTableModel>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    QSqlTableModel* _model;
    QTableView* _view;

    QLineEdit* _edit;
    QPushButton* _add;
    QPushButton* _del;
    QPushButton* _submit;
    QPushButton* _reset;
signals:

public slots:
};

#endif // MYWIDGET_H
