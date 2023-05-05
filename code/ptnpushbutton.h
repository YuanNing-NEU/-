#ifndef PTNPUSHBUTTON_H
#define PTNPUSHBUTTON_H

#include <QPushButton>

class PtnPushButton : public QPushButton  //方块图案按钮类
{
    Q_OBJECT
public:
    //explicit PtnPushButton(QWidget *parent = nullptr);  //系统自带构造函数，未使用

    PtnPushButton(QString btnImg);  //构造函数
    void mymove(int direction,int nmove = 1);  //实参传入1或2或3或4 1为向右，2为向左，3为向下，4为向上

signals:

};

#endif // PTNPUSHBUTTON_H
