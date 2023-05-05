#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton  //一张或两张图片的按钮类
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);  //系统自带构造函数，未使用
    MyPushButton(int widthb,int heightb,QString normalImg, QString pressImg = "");  //实现按钮动画，按下状态默认为空，按下之后是否进行选择图片
    QString normalImgPath;
    QString pressImgPath;
    int widthbt,heightbt;

    //重写按钮按下和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
