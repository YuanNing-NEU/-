#include "mypushbutton.h"
#include <QDebug>

//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)  //系统自带构造函数，未使用
//{

//}

//一张或两张图片的按钮类
MyPushButton::MyPushButton(int widthb,int heightb,QString normalImg, QString pressImg)  //构造函数实现按钮动画，前两个参数为按钮大小，默认值在函数的声明和实现中只能有一个
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;
    widthbt=widthb;
    heightbt=heightb;
    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret)  //异常处理
    {
        qDebug() << "图片加载失败";
        return;
    }
    pix=pix.scaled(widthb,heightb);  //实现图片缩放为指定大小
    this->setFixedSize(widthb,heightb);  //设置按钮大小
    this->setStyleSheet("QPushButton{border:0px;}");  //设置边框为0像素，使之显示不规则图形
    this->setIcon(pix);  //设置图标
    this->setIconSize(QSize(widthb,heightb));  //设置图标大小


}

void MyPushButton::mousePressEvent(QMouseEvent *e)  //重写按钮按下事件
{
    if(this->pressImgPath != "")  //传入的按下图片不为空，说明需要有按下状态，切换图片
    {
        QPixmap pix;
        bool ret = pix.load(pressImgPath);
        if(!ret)  //异常处理
        {
            qDebug() << "图片加载失败";
            return;
        }
        pix=pix.scaled(widthbt,heightbt);  //实现图片缩放为指定大小
        this->setFixedSize(widthbt,heightbt);  //设置按钮大小
        this->setStyleSheet("QPushButton{border:0px;}");  //设置边框为0像素，使之显示不规则图形
        this->setIcon(pix);  //设置图标
        this->setIconSize(QSize(widthbt,heightbt));  //设置图标大小
    }
    return QPushButton::mousePressEvent(e);  //让父类执行其他内容
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)  //重写按钮释放事件
{
    if(this->pressImgPath != "")  //传入的按下图片不为空，说明需要有按下状态，切换为初始图片
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)  //异常处理
        {
            qDebug() << "图片加载失败";
            return;
        }
        pix=pix.scaled(widthbt,heightbt);  //实现图片缩放为指定大小
        this->setFixedSize(widthbt,heightbt);  //设置按钮大小
        this->setStyleSheet("QPushButton{border:0px;}");  //设置边框为0像素，使之显示不规则图形
        this->setIcon(pix);  //设置图标
        this->setIconSize(QSize(widthbt,heightbt));  //设置图标大小
    }
    return QPushButton::mouseReleaseEvent(e);  //让父类执行其他内容
}
