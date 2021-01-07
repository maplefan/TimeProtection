#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent * event);//鼠标点击事件
    void mouseMoveEvent(QMouseEvent * event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent * e);//鼠标松开事件
    void wheelEvent(QWheelEvent *event);//鼠标滚轮事件
    void keyPressEvent(QKeyEvent * event);//键盘事件

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
