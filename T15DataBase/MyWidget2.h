#ifndef MYWIDGET2_H
#define MYWIDGET2_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QItemDelegate>
#include <QComboBox>
class ReadOnlyDelegate:public QItemDelegate
{
public:
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &,
                          const QModelIndex &) const override
    {
        return nullptr;
    }
};

class MyDelegate:public QItemDelegate   //继承代理器类,用于设置view的显示格式
{
public:
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &,
                          const QModelIndex &) const override
    {
            QComboBox* box=new QComboBox(parent);
            box->addItem("男");
            box->addItem("女");
            return box;
    }
};
class MySqlTableModel:public QSqlTableModel     //将用多选框选择的数据翻译
{
public:
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override    //对从数据库中读取的数据进行处理
    {
      if(idx.column()!=1)
        return QSqlTableModel::data(idx,role);
      QVariant var=QSqlTableModel::data(idx,role);
       if(var==0)
         {
            return "女";
          }
       else
            return "男";
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override //对发送回数据库的数据进行处理
    {
        if(index.column()!=1)
            return QSqlTableModel::setData(index,value,role);
        else
        {
            if(value=="男")
                return QSqlTableModel::setData(index,1,role);
            return QSqlTableModel::setData(index,0,role);
        }
    }
};

class MyWidget2 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget2(QWidget *parent = nullptr);
    MySqlTableModel* _model;
    QTableView* _view;
signals:

public slots:
    void slotsubmit();
    void slotdel();
    void slotadd();
};

#endif // MYWIDGET2_H
