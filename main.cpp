#include "mainwindow.h"
#include <QApplication>

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
    MainWindow w;
    w.showFullScreen();
    w.show();
    return a.exec();
}
