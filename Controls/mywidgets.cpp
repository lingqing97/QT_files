#include "mywidgets.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>   //标题框
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton> //单点框
#include <QCheckBox>    //勾选框
#include <QPushButton>  //按钮
#include <QComboBox>    //下拉框
#include <QCompleter>
#include <QTextEdit>   //多行文本框
#include <QGroupBox>   //划分框架框
#include <QSlider>    //拉动条
#include <QSpinBox>   //递增框
#include <QDateTimeEdit> //时间日期递增框
#include <QLCDNumber>   //lcd样式显示框
#include <QDebug>   //使用记录日志输出实时状态
Mywidgets::Mywidgets(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* layout=new QVBoxLayout(this);   //在类中定义布局管理器的方法

    QLabel* label;
    QPushButton* button;
    QRadioButton* radio;
    QTextEdit* textedit;
    QComboBox* combo;
    QGroupBox* box;
    layout->addWidget(label=new QLabel("<h1>lable</h1>"));

    label->setPixmap(QPixmap("../bbb.jpg"));  //往标签栏添加图片

    layout->addWidget(button=new QPushButton("button"));
    button->setStyleSheet("QPushButton {color:red; font:10px;}");  //可是使用css样式对一些控件进行样式的设计

    layout->addWidget(radio=new QRadioButton("radio"));
    radio->setStyleSheet("QRadioButton {color:red;}");
    connect(radio,&QRadioButton::clicked,[](bool b){
        qDebug()<<b;
    });     //[](){}c++lambo表达式,使用时需要在pro文件中添加CONFIG+=C11

    layout->addWidget(new QCheckBox("checkbox"));

    layout->addWidget(combo=new QComboBox);
    combo->addItem("aaa");
    combo->addItem("bbb");
    combo->addItem("ccc");      //设置下拉框选项
    combo->setEditable(true);    //将下拉框设置为可编辑
    combo->setCompleter(new QCompleter(QStringList()<<"123"<<"abc"<<"123456"));   //对可编辑的下拉框添加自动匹配功能
    connect(combo,SIGNAL(currentTextChanged(QString)),this,SLOT(currentTextChangedDisplay(QString)));  //自定义一个槽处理函数来显示实时的下拉框输入内容

    layout->addWidget(textedit=new QTextEdit);
    textedit->setText("<table border=1>"
                      "<tr><th>head1</th><th>head2</th></tr>"
                      "<tr><td>value1</td><td>value2</td></tr>"
                      "</table>"
                      "<img src=../aaa.jpg></img>");   //可以使用html作为text的内容
    _edit=textedit;
    connect(textedit,&QTextEdit::textChanged,[&](){
        qDebug()<<_edit->toPlainText();
    }); //通过lambo表达式实时显示文本框中的内容

    QHBoxLayout* hboxlay=new QHBoxLayout;
    layout->addWidget(box=new QGroupBox("group"));
    box->setLayout(hboxlay);             //在框架中新建一个水平布局
    hboxlay->addWidget(new QPushButton("button1"));
    hboxlay->addWidget(new QPushButton("button2"));


    QSlider* slider;
    layout->addWidget(slider=new QSlider(Qt::Orientation::Horizontal));   //将拉动条设置为水平放置
    slider->setMaximum(100);
    slider->setMinimum(0);    //设置最大值和最小值

    QSpinBox* spinbox;
    layout->addWidget(spinbox=new QSpinBox);
    spinbox->setMaximum(100);
    spinbox->setMinimum(0);

    connect(slider,SIGNAL(valueChanged(int)),spinbox,SLOT(setValue(int)));
    connect(spinbox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));

    QDateTimeEdit* datetimeedit;
    layout->addWidget(datetimeedit=new QDateTimeEdit);

    QLCDNumber* lcd;
    layout->addWidget(lcd=new QLCDNumber);
    lcd->display("12134");
    lcd->setMode(QLCDNumber::Hex);   //以十六进制显示

}
void Mywidgets::currentTextChangedDisplay(const QString str)
{
    qDebug()<<"currentTextChangedDisplay "<<str;
}
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    Mywidgets w;
    w.show();
    w.setWindowTitle("controls");

    return app.exec();
}
