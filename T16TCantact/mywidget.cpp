#include "mywidget.h"
#include <QApplication>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlRecord>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    _model=new QSqlTableModel;
    _model->setTable("tcantact");
    _model->select();
    _model->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    _view=new QTableView;
    _view->setModel(_model);

    QVBoxLayout* layout=new QVBoxLayout(this);
    QHBoxLayout* hlayout=new QHBoxLayout;

#if 0
    QPushButton* _add;
    QPushButton* _del;
    QPushButton* _submit;
    QPushButton* _reset;
#endif
    _edit=new QLineEdit(this);
    _add=new QPushButton("add",this);
    _del=new QPushButton("del",this);
    _submit=new QPushButton("submit",this);
    _reset=new QPushButton("reset",this);

    layout->addWidget(_view);
    layout->addLayout(hlayout);

    hlayout->addWidget(_edit,2);
    hlayout->addWidget(_add);
    hlayout->addWidget(_del);
    hlayout->addWidget(_submit);
    hlayout->addWidget(_reset);

    connect(_add,&QPushButton::clicked,[&](){
        QSqlRecord record=_model->record();
        _model->insertRecord(-1,record);
    });
    connect(_submit,&QPushButton::clicked,[&](){
        _model->submitAll();
    });
    connect(_del,&QPushButton::clicked,[&](){

    });
    connect(_reset,&QPushButton::clicked,[&](){

    });
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("wsk201607");
    db.setDatabaseName("TCantact");
    bool open=db.open();
    if(open)
    {
        qDebug()<<"open database successfully!";
    }
    else
    {
        QMessageBox::critical(nullptr,"error",db.lastError().text());
        exit(0);
    }
    MyWidget w;
    w.show();

    return app.exec();
}
