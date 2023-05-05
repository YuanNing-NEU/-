#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include "helpwindow.h"  //游戏帮助界面
#include "regis.h"  //注册界面
#include "choosemodescene.h"  //登录后界面

QT_BEGIN_NAMESPACE
namespace Ui { class StartScene; }
QT_END_NAMESPACE

class StartScene : public QMainWindow
{
    Q_OBJECT

public:
    StartScene(QWidget *parent = nullptr);
    ~StartScene();

    void paintEvent(QPaintEvent *);  //重写paintEvent事件，画背景图
    Helpwindow * helpwindow = NULL;
    regis * regisre = NULL;
    ChooseModeScene * chooseModeScene = NULL;

private:
    Ui::StartScene *ui;
};
#endif // STARTSCENE_H
