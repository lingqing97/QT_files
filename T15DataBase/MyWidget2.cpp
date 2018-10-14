#include "MyWidget2.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
MyWidget2::MyWidget2(QWidget *parent) : QWidget(parent)
{
    _model=new MySqlTableModel;
    _model->setTable("menu");
    _model->select();   //要先加载数据
    _model->setHeaderData(0,Qt::Horizontal,"菜单");   //设置在视图上显示的标题栏
    _model->setHeaderData(1,Qt::Horizontal,"价格");
    _model->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);   //设置在视图上修改数据后的提交策略，本例设置为手动提交

    _view=new QTableView;
    _view->setModel(_model);
    _view->setItemDelegateForColumn(1,new MyDelegate);   //设置代理
    _view->setItemDelegateForColumn(0,new ReadOnlyDelegate);    //使用只读代理，将第0列设置为只读
    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->addWidget(_view);

    QHBoxLayout* hlayout=new QHBoxLayout(this);
    QPushButton* button1=new QPushButton("submit",this);
    QPushButton* button2=new QPushButton("del",this);
    QPushButton* button3=new QPushButton("add",this);
    layout->addLayout(hlayout); //在竖直布局中放置一个水平布局
    hlayout->addStretch();
    hlayout->addWidget(button1);
    hlayout->addWidget(button2);
    hlayout->addWidget(button3);

    connect(button1,SIGNAL(clicked()),this,SLOT(slotsubmit()));
    connect(button2,SIGNAL(clicked()),this,SLOT(slotdel()));
    connect(button3,SIGNAL(clicked()),this,SLOT(slotadd()));
}
void MyWidget2::slotsubmit()
{
    bool submit=_model->submitAll();
    if(!submit)
    {
        QMessageBox::critical(this,"error","submit error");
    }
}
void MyWidget2::slotdel()
{
   QItemSelectionModel* selectmodel=_view->selectionModel();    //获取选择的单元格
   QModelIndexList indexlist=selectmodel->selectedIndexes();    //获取选中单元格的索引
   QList<int> list;
   for(int i=0;i<indexlist.size();i++)
   {
       int row=indexlist.at(i).row();
       list.append(row);
   }
   while(!list.empty())
   {
       int row=list[0];
       _model->removeRow(row);  //从数据库中删除指定的行
       list.removeAll(row);     //去除重复的行号
   }
   _model->submitAll();     //修改以后记住一定要提交才会生效!!!!
}
void MyWidget2::slotadd()
{
    QSqlRecord record=_model->record();
    _model->insertRecord(-1,record);
    _model->submitAll();
}
