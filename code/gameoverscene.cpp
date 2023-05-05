#include "gameoverscene.h"
#include "ui_gameoverscene.h"
#include <QPainter>
#include <QLabel>
#include <QDebug>
#include "extern1.h"
#include <mypushbutton.h>

GameoverScene::GameoverScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameoverScene)
{
    ui->setupUi(this);

    this->setFixedSize(1200,900);  //设置开始界面固定大小
    this->setWindowIcon(QIcon(":/happyelimres/happyelim0001.png"));  //设置开始界面图标
    this->setWindowTitle("开心消消乐");  //设置开始界面标题

    QLabel * label1 = new QLabel;
    QPixmap pix1;
    bool ret1 = pix1.load(":/happyelimres/happyelim0039.jpg");
    if(!ret1)  //异常处理
    {
        qDebug() << "图片加载失败";
        return;
    }
    pix1=pix1.scaled(600,480);  //实现图片缩放为指定大小
    label1->setFixedSize(600,480);  //设置固定长宽
    label1->move(300,300);  //设置位置
    label1->setPixmap(pix1);  //把图片安入标签
    label1->setParent(this);

    QLabel * label2 = new QLabel;
    label2->setParent(this);
    label2->setFixedSize(600,480);  //设置固定长宽
    label2->move(290,130);  //设置位置
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font2;
    font2.setFamily("微软雅黑");  //设置字体
    font2.setPointSize(40);  //设置字号
    label2->setFont(font2);  //使用font
    QPalette pe2;
    pe2.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label2->setPalette(pe2);  //使用pe
    label2->setText("所得分数");

    QLabel * label3 = new QLabel;
    label3->setParent(this);
    label3->setFixedSize(600,480);  //设置固定长宽
    label3->move(290,250);  //设置位置
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font3;
    font3.setFamily("微软雅黑");  //设置字体
    font3.setPointSize(40);  //设置字号
    label3->setFont(font3);  //使用font
    QPalette pe3;
    pe3.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label3->setPalette(pe3);  //使用pe
    label3->setText(QString::number(score));  //强制类型转化

    //设置有按下动画的按钮signinBtn登录
    MyPushButton * signinBtn4 = new MyPushButton(260,80,":/happyelimres/happyelim0003.png",":/happyelimres/happyelim0004.png");  //600为按钮长度，80为按钮宽度
    signinBtn4->setParent(this);
    signinBtn4->move(320,560);  //中间位置

    //设置写有按钮文字的标签label
    QLabel * label4 = new QLabel;
    label4->setParent(this);
    label4->setFixedSize(260,80);  //设置固定长宽
    label4->move(320,560);  //设置位置
    label4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font4;
    font4.setFamily("华文琥珀");  //设置字体
    font4.setPointSize(30);  //设置字号
    label4->setFont(font4);  //使用font
    QPalette pe4;
    pe4.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label4->setPalette(pe4);  //使用pe
    label4->setText("重新开始");
    //设置让鼠标穿透标签label
    label4->setAttribute(Qt::WA_TransparentForMouseEvents);

    MyPushButton * signinBtn5 = new MyPushButton(260,80,":/happyelimres/happyelim0003.png",":/happyelimres/happyelim0004.png");  //600为按钮长度，80为按钮宽度
    signinBtn5->setParent(this);
    signinBtn5->move(600,560);  //中间位置
    QLabel * label5 = new QLabel;
    label5->setParent(this);
    label5->setFixedSize(260,80);  //设置固定长宽
    label5->move(600,560);  //设置位置
    label5->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font5;
    font5.setFamily("华文琥珀");  //设置字体
    font5.setPointSize(30);  //设置字号
    label5->setFont(font5);  //使用font
    QPalette pe5;
    pe5.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label5->setPalette(pe5);  //使用pe
    label5->setText("返回菜单");
    //设置让鼠标穿透标签label
    label5->setAttribute(Qt::WA_TransparentForMouseEvents);


}

void GameoverScene::paintEvent(QPaintEvent *)  //重写paintEvent事件，画背景图
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/happyelimres/happyelim0002.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

GameoverScene::~GameoverScene()
{
    delete ui;
}
