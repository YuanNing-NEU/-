#include "bglabel.h"
#include <QMouseEvent>
#include <QDebug>

//BgLabel::BgLabel(QWidget *parent) : QLabel(parent)  //系统自带构造函数，未使用
//{

//}

BgLabel::BgLabel(int x,int y)  //构造函数
{
    numX=x;
    numY=y;
    //加载图片
    QPixmap pix;
    bool ret = pix.load(":/happyelimres/happyelim0006.png");
    if(!ret)  //异常处理
    {
        qDebug() << "图片加载失败";
        return;
    }
    pix=pix.scaled(75,75);  //实现图片缩放为指定大小
    //设置背景方块标签
    this->setFixedSize(75,75);  //设置标签大小
    this->setPixmap(pix);  //把图片安入标签
}

void BgLabel::mouseMoveEvent(QMouseEvent *ev)  //重写鼠标移动事件
{
    posX=ev->x();  //鼠标相对于一个方块的X,Y坐标
    posY=ev->y();
    if(posX>=76 && ex1==true)
    {
        ex1=false;  //防止一直移动
        emit this->exchangeright();
    }
    if(posX<=-1 && ex1==true)
    {
        ex1=false;
        emit this->exchangeleft();
    }
    if(posY>=76 && ex1==true)
    {
        ex1=false;
        emit this->exchangedown();
    }
    if(posY<=-1 && ex1==true)
    {
        ex1=false;
        emit this->exchangeup();
    }
}
