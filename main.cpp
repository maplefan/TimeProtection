#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{

    if ( *argv[0] == '/')
    {
        if (*argv[1] == 'p')
        {
            return 0;
        }
        if (*argv[1] == 'c')
        {
        }
    }
    QApplication a(argc, argv);
    QDesktopWidget *qdw = QApplication::desktop();
    int screenCount = qdw->screenCount();//获得屏幕数量
    for(int i = 0; i < screenCount ;i++){
        MainWindow *w = new MainWindow;
        w->setGeometry(qdw->screenGeometry(i));
        w->setWindowFlag(Qt::Tool);//不在任务栏显示
        w->showFullScreen();
        w->show();
    }

    return a.exec();
}
