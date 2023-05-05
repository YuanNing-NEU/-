#include "helpwindow.h"
#include "ui_helpwindow.h"
#include<QPainter>
#include<QPushButton>
#include<QAction>
#include<QLabel>
#include<QBitmap>
#include<QWidget>
#include<QTimer>
#include<QPropertyAnimation>
#include<QFile>
#include<QTextEdit>
#include<QLineEdit>
#include<QString>
#include<QDebug>
#include<QTabWidget>

Helpwindow::Helpwindow(QWidget *parent)  //游戏帮助界面
    : QWidget(parent)
    , ui(new Ui::Helpwindow)
{
    ui->setupUi(this);
    //界面图标、大小、名称
    this->setFixedSize(1200,900);
    this->setWindowIcon(QIcon(":/happyelimres/happyelim0001.png"));
    this->setWindowTitle("开心消消乐");


    //设置标签头名称
    ui->tabWidget->setTabText(0,"玩法介绍");
    ui->tabWidget->setTabText(1,"得分规则");
    ui->tabWidget->setTabText(2,"关于游戏");
    //设置默认的标签页
    ui->tabWidget->setCurrentWidget(ui->play_introduction);


}

Helpwindow::~Helpwindow()
{
    delete ui;
}
void Helpwindow::paintEvent(QPaintEvent *)  //重写paintEvent事件，画背景图
{
    QPainter help_painter(this);
    QPixmap help_pix;
    help_pix.load(":/happyelimres/happyelim0033.jpg");
    help_painter.drawPixmap(0,0,this->width(),this->height(),help_pix);

}
