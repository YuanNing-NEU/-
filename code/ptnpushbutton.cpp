#include "ptnpushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>  //实现按钮移动用到的头文件

//PtnPushButton::PtnPushButton(QWidget *parent) : QPushButton(parent)  //系统自带构造函数，未使用
//{

//}

//方块图案按钮类
PtnPushButton::PtnPushButton(QString btnImg)  //构造函数
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)  //异常处理
    {
        qDebug() << "图片加载失败";
        return;
    }
    pix=pix.scaled(75,75);  //实现图片缩放为指定大小
    this->setFixedSize(75,75);  //设置按钮大小
    this->setStyleSheet("QPushButton{border:0px;}");  //设置边框为0像素，使之显示不规则图形
    this->setIcon(pix);  //设置图标
    this->setIconSize(QSize(75,75));  //设置图标大小
    this->setAttribute(Qt::WA_TransparentForMouseEvents);  //设置让鼠标穿透按钮
}

void PtnPushButton::mymove(int direction,int nmove)  //nmove默认值为1(见函数声明),实参传入1或2或3或4 1为向右，2为向左，3为向下，4为向上
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(225*nmove);
    animation->setStartValue(QRect(this->x(),this->y(),75,75));
    switch(direction)
    {
        case 1: animation->setEndValue(QRect(this->x()+75*nmove,this->y(),75,75)); break;
        case 2: animation->setEndValue(QRect(this->x()-75*nmove,this->y(),75,75)); break;
        case 3: animation->setEndValue(QRect(this->x(),this->y()+75*nmove,75,75)); break;
        case 4: animation->setEndValue(QRect(this->x(),this->y()-75*nmove,75,75)); break;
    }
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}
