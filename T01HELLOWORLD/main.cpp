
#include <QApplication>
/*add a widget class*/
#include <QWidget>
/* add a button */
#include <QPushButton>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    QWidget w;

//    /*按钮也是一个窗口*/
//    /*没有父窗口的窗口称为主窗口*/
//    QPushButton button;
//    button.setText("pushbutton");
//    /*设置父窗口*/
//    button.setParent(&w);

    w.show();  /*能够将子窗口同时显示*/

    QPushButton button;
    button.setText("pushbotton");
    button.setParent(&w);
    button.show();/*由于是在父窗口显示后定义的，所以需要单独使用show显示*/

    /*定义信号槽将两个控件建立联系*/
    QObject::connect(&button,SIGNAL(clicked()),&w,SLOT(close()));

     w.setWindowTitle("Hello world");

     /*返回app的消息循环*/
    return app.exec();
}
