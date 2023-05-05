#include "choosemodescene.h"
#include "ui_choosemodescene.h"
#include <QPainter>
#include <mypushbutton.h>
#include <QLabel>
#include <QTimer>

ChooseModeScene::ChooseModeScene(QWidget *parent) :  //该界面实际为登录后的界面，不为选择模式界面
    QMainWindow(parent),
    ui(new Ui::ChooseModeScene)
{
    ui->setupUi(this);

    //开始界面设置
    this->setFixedSize(1200,900);  //设置开始界面固定大小
    this->setWindowIcon(QIcon(":/happyelimres/happyelim0001.png"));  //设置开始界面图标
    this->setWindowTitle("开心消消乐");  //设置开始界面标题

    //设置有按下动画的按钮signinBtn登录
    MyPushButton * signinBtn1 = new MyPushButton(600,80,":/happyelimres/happyelim0003.png",":/happyelimres/happyelim0004.png");  //600为按钮长度，80为按钮宽度
    signinBtn1->setParent(this);
    signinBtn1->move(this->width() * 0.5 - signinBtn1->width() * 0.5,350);  //中间位置
    //设置写有按钮文字的标签label
    QLabel * label1 = new QLabel;
    label1->setParent(this);
    label1->setFixedSize(600,80);  //设置固定长宽
    label1->move(this->width() * 0.5 - signinBtn1->width() * 0.5,350);  //设置位置
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font1;
    font1.setFamily("华文琥珀");  //设置字体
    font1.setPointSize(40);  //设置字号
    label1->setFont(font1);  //使用font
    QPalette pe1;
    pe1.setColor(QPalette::WindowText, Qt::cyan);  //设置文字颜色为青色
    label1->setPalette(pe1);  //使用pe
    label1->setText("开始游戏");
    //设置让鼠标穿透标签label
    label1->setAttribute(Qt::WA_TransparentForMouseEvents);

    //设置有按下动画的按钮signinBtn注册
    MyPushButton * signinBtn2 = new MyPushButton(600,80,":/happyelimres/happyelim0003.png",":/happyelimres/happyelim0004.png");  //600为按钮长度，80为按钮宽度
    signinBtn2->setParent(this);
    signinBtn2->move(this->width() * 0.5 - signinBtn2->width() * 0.5,450);  //中间位置
    //设置写有按钮文字的标签label
    QLabel * label2 = new QLabel;
    label2->setParent(this);
    label2->setFixedSize(600,80);  //设置固定长宽
    label2->move(this->width() * 0.5 - signinBtn2->width() * 0.5,450);  //设置位置
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font2;
    font2.setFamily("华文琥珀");  //设置字体
    font2.setPointSize(40);  //设置字号
    label2->setFont(font1);  //使用font
    QPalette pe2;
    pe2.setColor(QPalette::WindowText, Qt::cyan);  //设置文字颜色为青色
    label2->setPalette(pe2);  //使用pe
    label2->setText("排行榜");
    //设置让鼠标穿透标签label
    label2->setAttribute(Qt::WA_TransparentForMouseEvents);

    //设置有按下动画的按钮signinBtn游戏帮助
    MyPushButton * signinBtn3 = new MyPushButton(600,80,":/happyelimres/happyelim0003.png",":/happyelimres/happyelim0004.png");  //600为按钮长度，80为按钮宽度
    signinBtn3->setParent(this);
    signinBtn3->move(this->width() * 0.5 - signinBtn3->width() * 0.5,550);  //中间位置
    //设置写有按钮文字的标签label
    QLabel * label3 = new QLabel;
    label3->setParent(this);
    label3->setFixedSize(600,80);  //设置固定长宽
    label3->move(this->width() * 0.5 - signinBtn3->width() * 0.5,550);  //设置位置
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font3;
    font3.setFamily("华文琥珀");  //设置字体
    font3.setPointSize(40);  //设置字号
    label3->setFont(font3);  //使用font
    QPalette pe3;
    pe3.setColor(QPalette::WindowText, Qt::cyan);  //设置文字颜色为青色
    label3->setPalette(pe3);  //使用pe
    label3->setText("游戏帮助");
    //设置让鼠标穿透标签label
    label3->setAttribute(Qt::WA_TransparentForMouseEvents);

    //设置有按下动画的按钮signinBtn退出游戏
    MyPushButton * signinBtn4 = new MyPushButton(600,80,":/happyelimres/happyelim0003.png",":/happyelimres/happyelim0004.png");  //600为按钮长度，80为按钮宽度
    signinBtn4->setParent(this);
    signinBtn4->move(this->width() * 0.5 - signinBtn4->width() * 0.5,650);  //中间位置
    //设置写有按钮文字的标签label
    QLabel * label4 = new QLabel;
    label4->setParent(this);
    label4->setFixedSize(600,80);  //设置固定长宽
    label4->move(this->width() * 0.5 - signinBtn1->width() * 0.5,650);  //设置位置
    label4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font4;
    font4.setFamily("华文琥珀");  //设置字体
    font4.setPointSize(40);  //设置字号
    label4->setFont(font4);  //使用font
    QPalette pe4;
    pe4.setColor(QPalette::WindowText, Qt::cyan);  //设置文字颜色为青色
    label4->setPalette(pe4);  //使用pe
    label4->setText("退出游戏");
    //设置让鼠标穿透标签label
    label4->setAttribute(Qt::WA_TransparentForMouseEvents);

    //开始游戏
    connect(signinBtn1,&MyPushButton::clicked,[=](){
        classicModeScene = new ClassicModeScene;
        QTimer::singleShot(200,this,[=](){  //延时0.2秒
            this->close();  //自身关闭
            classicModeScene->show();  // //临时使用
        });
    });

    //排行榜
    connect(signinBtn2,&MyPushButton::clicked,[=](){
        widgetwi = new Widget;
        QTimer::singleShot(200,this,[=](){  //延时0.2秒
            this->close();  //自身关闭
            widgetwi->show();  // //临时使用
        });
    });

    //游戏帮助
    connect(signinBtn3,&MyPushButton::clicked,[=](){
        helpwindow = new Helpwindow;
        QTimer::singleShot(200,this,[=](){  //延时0.2秒
            this->close();  //自身关闭
            helpwindow->show();
        });
    });

    //退出游戏
    connect(signinBtn4,&QPushButton::clicked,this,&ChooseModeScene::close);

}

void ChooseModeScene::paintEvent(QPaintEvent *)  //重写paintEvent事件，画背景图  
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/happyelimres/happyelim0002.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

ChooseModeScene::~ChooseModeScene()
{
    delete ui;
}
