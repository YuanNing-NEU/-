#ifndef BGLABEL_H
#define BGLABEL_H

#include <QLabel>

class BgLabel : public QLabel
{
    Q_OBJECT
public:
    //explicit BgLabel(QWidget *parent = nullptr);  //系统自带构造函数，未使用
    BgLabel(int x,int y);  //构造函数
    void mouseMoveEvent(QMouseEvent *ev);  //重写鼠标移动事件
    int posX,posY;  //鼠标相对于一个方块的X,Y坐标
    int numX,numY;  //图案方块属性，背景方块在数组中的第X行，第Y列（从0开始）
    bool ex1 = true;  //可交换为true,不可交换为false,交换方块后true变为false

signals:
    void exchangeright();  //将该方块与右侧方块交换的信号
    void exchangeleft();  //将该方块与左侧方块交换的信号
    void exchangedown();  //将该方块与下侧方块交换的信号
    void exchangeup();  //将该方块与上侧方块交换的信号
};

#endif // BGLABEL_H
