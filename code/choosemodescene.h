#ifndef CHOOSEMODESCENE_H
#define CHOOSEMODESCENE_H

#include <QMainWindow>
#include "helpwindow.h"  //游戏帮助界面
#include "classicmodescene.h"  //经典模式界面
#include "widget.h"  //排行榜界面
namespace Ui {
class ChooseModeScene;
}

class ChooseModeScene : public QMainWindow  //该界面实际为登录后的界面，不为选择模式界面
{
    Q_OBJECT

public:
    explicit ChooseModeScene(QWidget *parent = nullptr);
    ~ChooseModeScene();

    void paintEvent(QPaintEvent *);  //重写paintEvent事件，画背景图
    ClassicModeScene * classicModeScene = NULL;
    Helpwindow * helpwindow = NULL;
    Widget * widgetwi = NULL;
private:
    Ui::ChooseModeScene *ui;
};

#endif // CHOOSEMODESCENE_H
