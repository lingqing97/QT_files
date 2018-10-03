#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
/*引用竖直放置规则类文件*/
#include <QVBoxLayout>
/*引用水平放置规则类文件*/
#include <QHBoxLayout>
/*引用格子放置规则类文件*/
#include <QGridLayout>
/*引用条目栏*/
#include <QLabel>
#include <QCompleter>
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    QWidget w;

//    QVBoxLayout layout;
//    /*使用放置规则的子窗口不用再声明父窗口*/
//    layout.addWidget(new QLineEdit());
//    /*在两个窗口间添加50像素的空白距离*/
//    layout.addSpacing(50);
//    layout.addWidget(new QPushButton("pushbutton"));

//    QHBoxLayout layout;
//    /*添加一个隐藏的权重为1的窗口，类似于'弹簧'*/
//    layout.addStretch(1);
//    /*第二个参数为设置窗口权重*/
//    layout.addWidget(new QLineEdit(),1);
//    layout.addSpacing(10);
//    layout.addWidget(new QPushButton("pushbutton"),1);
//    layout.addStretch(1);
#if 0
    QGridLayout layout;
    layout.addWidget(new QPushButton("1,1"),1,1);
    layout.addWidget(new QLineEdit(),1,2);
    layout.addWidget(new QPushButton("2,1"),2,1);
    layout.addWidget(new QLineEdit(),2,2);

    /*在第0和第3列设置弹簧*/
    /*列方向的弹簧控制水平方向的比例*/
    layout.setColumnStretch(0,1);
    layout.setColumnStretch(3,1);

    /*行方向的弹簧控制竖直方向的比例*/
    layout.setRowStretch(0,1);
    layout.setRowStretch(3,1);

#endif
    /*
     *
     *
     * 设置一个登陆框
    */

    QGridLayout layout;
    QLineEdit* edit;
    QLineEdit* user;
    layout.setColumnStretch(0,1);
    layout.setColumnStretch(3,1);

    layout.addWidget(new QLabel("username:"),1,1);
    layout.addWidget(user=new QLineEdit,1,2);
    /*设置自动匹配*/
    QStringList str;
    str<<"wsk"<<"123456";
    QCompleter completer(str);
    user->setCompleter(&completer);


    layout.addWidget(new QLabel("password:"),2,1);
    layout.addWidget(edit=new QLineEdit,2,2);
    edit->setEchoMode(QLineEdit::Password);

    layout.setRowStretch(0,1);
    layout.setRowStretch(4,1);

    /*在layout中嵌套layout*/
    QPushButton* button;
    QHBoxLayout hbox;
    layout.addLayout(&hbox,3,2);
    hbox.addStretch(1);
    hbox.addWidget(button=new QPushButton("Login"));

    /*设置消息槽*/
    QObject::connect(button,SIGNAL(clicked()),&w,SLOT(close()));


    w.show();
    /*在窗口中定义放置规则*/
    w.setLayout(&layout);
    return app.exec();
}
