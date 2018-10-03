#include <QApplication>
#include <QPushButton>
#include <QtWidgets>
#include <QLineEdit>
#include <QCompleter>
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    QWidget w;
    w.show();

    /*设置输入框*/
    QLineEdit line;
    line.setParent(&w);
    line.show();

//    /*设置输入密码*/
//    line.setEchoMode(QLineEdit::Password);

//    line.text();

    /*定义匹配的字符列表*/
    QStringList str;
    str<<"1213"<<"abc"<<"deg";
    /*定义匹配对象*/
    QCompleter completer(str);
    /*设置匹配提示*/
    line.setCompleter(&completer);



    w.setWindowTitle("hello world");

    return app.exec();
}
