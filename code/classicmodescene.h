#ifndef CLASSICMODESCENE_H
#define CLASSICMODESCENE_H

#include <QMainWindow>
#include "ptnpushbutton.h"
#include "gameoverscene.h"

namespace Ui {
class ClassicModeScene;
}

class ClassicModeScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClassicModeScene(QWidget *parent = nullptr);
    ~ClassicModeScene();

    void paintEvent(QPaintEvent *);  //重写paintEvent事件，画背景图
    int block[10][10],blockb[10][10];  //取8会出现错误，取9正确，保险起见取10
    PtnPushButton * ptnBtn[10][10];  //图案方块
    PtnPushButton * ptnBtnb[10][10];  //图案方块备份
    PtnPushButton * ptnBtnnew[10][10];  //新产生的图案方块
    int imove,jmove,directmove;  //标记发起交换的方块的i,j和交换方向，便于如果无消除则交换回来
    bool exreturn = true; //需要交换回来为true
    int numzero[10];  //一列中0的个数
    int t,y;  //t为下落后方块纵向个数
    int myevent = 1;
    int step = 20;  //步数
    int blockc[10][10];
    void bomb();  //对block[i][j]消除并产生炸弹
    void bombc();  //对blockc[i][j]消除并产生炸弹
    void row();  //对block[i][j]消除并产生行消
    void rowc();  //对blockc[i][j]消除并产生行消
    void column();  //对block[i][j]消除并产生列消
    void columnc();  //对blockc[i][j]消除并产生列消
    void threecon();  //对block[i][j]消除三连的方块
    void threeconc();  //对blockc[i][j]消除三连的方块
    void check();  //检查是否会产生行列消炸弹，如果会，把产生的行列消炸弹替换为新方块，并再次检查，直至没有产生行列消炸弹

    GameoverScene * gameoverScene = NULL;

signals:
    void exfinish();
private:
    Ui::ClassicModeScene *ui;
};

#endif // CLASSICMODESCENE_H
