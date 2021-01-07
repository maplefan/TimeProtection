#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDateTime>
#include <QTimer>
#include <QMouseEvent>
#include <Windows.h>
#include <windowsx.h>  //提供消息关键字的识别

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setMouseTracking(true);
    setMouseTracking(true);
    setWindowFlags (Qt::FramelessWindowHint);
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRect(rect());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    //字体
    QFont font;
    font.setFamily("Microsoft YaHei");
    // 设置字符间距
    // 大小
    font.setPointSize(120);
    //font.setLetterSpacing(QFont::AbsoluteSpacing, 20);
    // 设置加粗
    //font.setBold(true);
    // 使用字体
    painter.setFont(font);
    QPainterPath path;
    QDateTime *datetime=new QDateTime(QDateTime::currentDateTime());
    //QString timeStr = datetime->toString("HH:mm:ss"); //设置显示格式 12小时制
    QString timeStr = datetime->toString("hh:mm:ss"); //设置显示格式 24小时制
    QString dateStr = datetime->toString("yyyy-MM-dd");
    QRect rect(0,0,this->width(),this->height());
    painter.setPen(Qt::white);
    painter.drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, timeStr);
    QFontMetrics fm = painter.fontMetrics();
    int fontHeight = fm.ascent()+fm.descent();
    font.setPointSize(50);
    painter.setFont(font);
    QRect rect1(0,fontHeight,this->width(),this->height());
    painter.drawText(rect1, Qt::AlignHCenter | Qt::AlignVCenter , dateStr);
    QTimer *timer;
    timer = new QTimer();
    timer->start(1000);//一秒钟
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    this->setCursor(Qt::BlankCursor);//隐藏鼠标
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRect(rect());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    //字体
    QFont font;
    font.setFamily("Microsoft YaHei");
    // 设置字符间距
    // 大小
    font.setPointSize(120);
    //font.setLetterSpacing(QFont::AbsoluteSpacing, 20);
    // 设置加粗
    //font.setBold(true);
    // 使用字体
    painter.setFont(font);
    QPainterPath path;
    QDateTime *datetime=new QDateTime(QDateTime::currentDateTime());
    //QString timeStr = datetime->toString("HH:mm:ss"); //设置显示格式 12小时制
    QString timeStr = datetime->toString("hh:mm:ss"); //设置显示格式 24小时制
    QString dateStr = datetime->toString("yyyy-MM-dd");
    QRect rect(0,0,this->width(),this->height());
    painter.setPen(Qt::white);
    painter.drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, timeStr);
    QFontMetrics fm = painter.fontMetrics();
    int fontHeight = fm.ascent()+fm.descent();
    font.setPointSize(50);
    painter.setFont(font);
    QRect rect1(0,fontHeight,this->width(),this->height());
    painter.drawText(rect1, Qt::AlignHCenter | Qt::AlignVCenter , dateStr);
}

//鼠标 点击
void MainWindow::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton)
    {
        this->setCursor(Qt::ArrowCursor);  //显示正常鼠标
        exit(0);
    }
    else if(e->button() == Qt::RightButton)
    {
        this->setCursor(Qt::ArrowCursor);  //显示正常鼠标
        exit(0);
    }
}

//鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent * e)
{
    this->setCursor(Qt::ArrowCursor);  //显示正常鼠标
     exit(0);
}

//鼠标松开事件
void MainWindow::mouseReleaseEvent(QMouseEvent * e)
{
    this->setCursor(Qt::ArrowCursor);  //显示正常鼠标
     exit(0);
}

//鼠标滚轮事件
void MainWindow::wheelEvent(QWheelEvent *e)
{
    this->setCursor(Qt::ArrowCursor);  //显示正常鼠标
     exit(0);
}

void MainWindow::keyPressEvent(QKeyEvent * e)
{
    this->setCursor(Qt::ArrowCursor);  //显示正常鼠标
     exit(0);
}
