#include "classicmodescene.h"
#include "ui_classicmodescene.h"
#include <QPainter>
#include <QLabel>
#include "bglabel.h"
#include <QDebug>
#include "ptnpushbutton.h"
#include <QTimer>
#include <QTime>  //产生随机数
#include <QRandomGenerator>  //产生随机数
#include "extern1.h"

//第541行的290和第561行的300可以再调整一下

ClassicModeScene::ClassicModeScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClassicModeScene)
{
    ui->setupUi(this);

    //经典模式游戏界面设置
    setFixedSize(1200,900);  //设置界面固定大小
    setWindowIcon(QIcon(":/happyelimres/happyelim0001.png"));  //设置界面图标
    setWindowTitle("开心消消乐");  //设置界面标题

    score = 0;

    //设置与分数相关的标签label1图片
    QLabel * label1 = new QLabel;
    QPixmap pix1;
    bool ret1 = pix1.load(":/happyelimres/happyelim0031.png");
    if(!ret1)  //异常处理
    {
        qDebug() << "图片加载失败";
        return;
    }
    pix1=pix1.scaled(157,126);  //实现图片缩放为指定大小,该图片为5:4
    label1->setFixedSize(157,126);  //设置固定长宽
    label1->move(750,10);  //设置位置
    label1->setPixmap(pix1);  //把图片安入标签
    label1->setParent(this);

    //设置与分数相关的标签label2剩余步数
    QLabel * label2 = new QLabel;
    label2->setParent(this);
    label2->setFixedSize(100,30);  //设置固定长宽
    label2->move(778,35);  //设置位置
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font2;
    font2.setFamily("微软雅黑");  //设置字体
    font2.setPointSize(13);  //设置字号
    label2->setFont(font2);  //使用font
    QPalette pe2;
    pe2.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label2->setPalette(pe2);  //使用pe
    label2->setText("分数");

    //设置与分数相关的标签label3数字
    QLabel * label3 = new QLabel;
    label3->setParent(this);
    label3->setFixedSize(100,100);  //设置固定长宽
    label3->move(778,35);  //设置位置
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font3;
    font3.setFamily("微软雅黑");  //设置字体
    font3.setPointSize(20);  //设置字号
    label3->setFont(font3);  //使用font
    QPalette pe3;
    pe3.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label3->setPalette(pe3);  //使用pe
    label3->setText(QString::number(score));  //强制类型转化

    //设置与剩余步数相关的标签label4
    QLabel * label4 = new QLabel;
    QPixmap pix4;
    bool ret4 = pix4.load(":/happyelimres/happyelim0031.png");
    if(!ret4)  //异常处理
    {
        qDebug() << "图片加载失败";
        return;
    }
    pix4=pix4.scaled(157,126);  //实现图片缩放为指定大小,该图片为5:4
    label4->setFixedSize(157,126);  //设置固定长宽
    label4->move(380,10);  //设置位置
    label4->setPixmap(pix4);  //把图片安入标签
    label4->setParent(this);

    //设置与剩余步数相关的标签label5
    QLabel * label5 = new QLabel;
    label5->setParent(this);
    label5->setFixedSize(100,30);  //设置固定长宽
    label5->move(408,35);  //设置位置
    label5->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font5;
    font5.setFamily("微软雅黑");  //设置字体
    font5.setPointSize(13);  //设置字号
    label5->setFont(font5);  //使用font
    QPalette pe5;
    pe5.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label5->setPalette(pe5);  //使用pe
    label5->setText("剩余步数");

    //设置与剩余步数相关的标签label6
    QLabel * label6 = new QLabel;
    label6->setParent(this);
    label6->setFixedSize(100,100);  //设置固定长宽
    label6->move(408,35);  //设置位置
    label6->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //设置label上的文字的对齐方式为水平居中和垂直居中
    QFont font6;
    font6.setFamily("微软雅黑");  //设置字体
    font6.setPointSize(20);  //设置字号
    label6->setFont(font6);  //使用font
    QPalette pe6;
    pe6.setColor(QPalette::WindowText, Qt::yellow);  //设置文字颜色
    label6->setPalette(pe6);  //使用pe
    label6->setText(QString::number(step));  //强制类型转化

    //设置标签label7图片(藤蔓)
    QLabel * label7 = new QLabel;
    QPixmap pix7;
    bool ret7 = pix7.load(":/happyelimres/happyelim0032.png");
    if(!ret7)  //异常处理
    {
        qDebug() << "图片加载失败";
        return;
    }
    pix7=pix7.scaled(180,900);  //实现图片缩放为指定大小
    label7->setFixedSize(180,900);  //设置固定长宽
    label7->move(60,0);  //设置位置
    label7->setPixmap(pix7);  //把图片安入标签
    label7->setParent(this);

    //画背景方块
    BgLabel * bglabel[10][10];  //指针数组
    for(int i = 0; i <= 8; i++)
        for(int j = 0; j <= 8; j++)
        {
            //加载背景方块标签
            bglabel[i][j] = new BgLabel(i,j);
            bglabel[i][j]->setParent(this);  //把标签安入界面
            bglabel[i][j]->move(300 + j*75 , 150 + i*75);
        }

    //初始化图案内容，即随机地初始化block[i][j]
    for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                block[i][j] = QRandomGenerator::global()->bounded(1, 7);  //产生1~6的随机数
    check();  //检查，实现初始化的方块不会自己消除，并不含特殊方块
    score = 0;

    //画图案方块，即把block二维数组存储的数字对接图片    
    for(int i = 0; i <= 8; i++)
        for(int j = 0; j <= 8; j++)
        {
            QString btnI;  //设置字符串来存储图片路径
            switch(block[i][j])
            {
                //存入字符串，十位数字:1为青蛙,2为狐狸,3为熊,4为河马,5为小鸟,6为猫头鹰
                //个位数字:1为行消,2为列消,3为炸弹
                //0为空（消除)
                case 1: btnI += ":/happyelimres/happyelim0007.png"; break;
                case 2: btnI += ":/happyelimres/happyelim0008.png"; break;
                case 3: btnI += ":/happyelimres/happyelim0009.png"; break;
                case 4: btnI += ":/happyelimres/happyelim0010.png"; break;
                case 5: btnI += ":/happyelimres/happyelim0011.png"; break;
                case 6: btnI += ":/happyelimres/happyelim0012.png"; break;
                default: qDebug() << "错误" ; return; break;  //异常处理，此处不确定用法是否正确
            }
            ptnBtn[i][j] = new PtnPushButton(btnI);
            ptnBtn[i][j]->setParent(this);
            ptnBtn[i][j]->move(300 + j*75 , 150 + i*75);
        }

    //背景方块接收信号使图案方块移动
    for(int i = 0; i <= 8; i++)
        for(int j = 0; j <= 8; j++)
        {
            connect(bglabel[i][j],&BgLabel::exchangeright,[=](){
                if(bglabel[i][j]->numY != 8 )  //与右侧的方块交换
                {
                    for(int k = 0; k <= 8; k++)  //使全部方块的鼠标交换失效
                        for(int t = 0; t <= 8; t++)
                            bglabel[k][t]->ex1 = false;
                    ptnBtn[i][j]->mymove(1);
                    ptnBtn[i][j+1]->mymove(2);
                    imove = i;  //记录i,j,交换方向,便于如果无消除则交换回来
                    jmove = j;
                    directmove = 1;
                    int exb = block[i][j];
                    block[i][j] = block[i][j+1];
                    block[i][j+1] = exb;
                    QTimer::singleShot(250,this,[=](){  //延时0.25秒
                        this->exfinish();  //方块交换完成后发送信号
                    });
                }
            });
            connect(bglabel[i][j],&BgLabel::exchangeleft,[=](){
                if(bglabel[i][j]->numY != 0 )  //与左侧的方块交换
                {
                    for(int k = 0; k <= 8; k++)  //使全部方块的鼠标交换失效
                        for(int t = 0; t <= 8; t++)
                            bglabel[k][t]->ex1 = false;
                    ptnBtn[i][j]->mymove(2);
                    ptnBtn[i][j-1]->mymove(1);
                    imove = i;  //记录i,j,交换方向,便于如果无消除则交换回来
                    jmove = j;
                    directmove = 2;
                    int exb = block[i][j];
                    block[i][j] = block[i][j-1];
                    block[i][j-1] = exb;
                    QTimer::singleShot(250,this,[=](){  //延时0.225秒
                        this->exfinish();  //方块交换完成后发送信号
                    });
                }
            });
            connect(bglabel[i][j],&BgLabel::exchangedown,[=](){
                if(bglabel[i][j]->numX != 8 )  //与下侧的方块交换
                {
                    for(int k = 0; k <= 8; k++)  //使全部方块的鼠标交换失效
                        for(int t = 0; t <= 8; t++)
                            bglabel[k][t]->ex1 = false;
                    ptnBtn[i][j]->mymove(3);
                    ptnBtn[i+1][j]->mymove(4);
                    imove = i;  //记录i,j,交换方向,便于如果无消除则交换回来
                    jmove = j;
                    directmove = 3;
                    int exb = block[i][j];
                    block[i][j] = block[i+1][j];
                    block[i+1][j] = exb;
                    QTimer::singleShot(250,this,[=](){  //延时0.225秒
                       this->exfinish();  //方块交换完成后发送信号
                    });
                }
            });
            connect(bglabel[i][j],&BgLabel::exchangeup,[=](){
                if(bglabel[i][j]->numX != 0 )  //与上侧的方块交换
                {
                    for(int k = 0; k <= 8; k++)  //使全部方块的鼠标交换失效
                        for(int t = 0; t <= 8; t++)
                            bglabel[k][t]->ex1 = false;
                    ptnBtn[i][j]->mymove(4);
                    ptnBtn[i-1][j]->mymove(3);
                    imove = i;  //记录i,j,交换方向,便于如果无消除则交换回来
                    jmove = j;
                    directmove = 4;
                    int exb = block[i][j];
                    block[i][j] = block[i-1][j];
                    block[i-1][j] = exb;
                    QTimer::singleShot(250,this,[=](){  //延时0.225秒
                        this->exfinish();  //方块交换完成后发送信号
                    });
                }
            });
        }



    connect(this,&ClassicModeScene::exfinish,[=](){
        //block[i][j]由交换后的内容变为一小轮消除后的内容
        for(int i = 0; i <= 8; i++)
            for (int j = 0; j <= 8; j++)
            {
                if(block[i][j] <= 10)
                    blockc[i][j] = block[i][j];
                else
                    blockc[i][j] = block[i][j]/10;
            }
        bombc();  //对blockc[i][j]消除并产生炸弹
        rowc();  //对blockc[i][j]消除并产生行消
        columnc();  //对blockc[i][j]消除并产生列消
        threeconc();  //对blockc[i][j]消除三连的方块
        for (int i = 0; i <= 8; i++)
            for (int j = 0; j <= 8; j++)
            {
                if(blockc[i][j] > 10)
                    block[i][j] = blockc[i][j];
            }
        for (int i = 0; i <= 8; i++)
            for (int j = 0; j <= 8; j++)
            {
                if(blockc[i][j] == 0 && block[i][j] > 10)
                {
                    if(block[i][j] %10 == 1)  //使用行消
                    {
                        for (int n = 0; n <= 8; n++)
                        {
                            blockc[i][n] = 0;
                            score += 3;
                        }
                        score += 10;
                    }
                    if(block[i][j] %10 == 2)  //使用列消
                    {
                        for (int m = 0; m <= 8; m++)
                        {
                            blockc[m][j] = 0;
                            score += 3;
                        }
                        score += 10;
                    }
                    if(block[i][j] %10 == 3)  //使用炸弹
                    {
                        for (int m = i - 1; m <= i + 1; m++)
                            for (int n = j - 1; n <= j + 1; n++)
                            {
                                if(m >= 0 && m <=8 && n >= 0 && n <= 8)
                                {
                                    blockc[m][n] = 0;
                                    score += 3;
                                }
                            }
                        score += 20;
                    }
                }
            }
        for (int i = 0; i <= 8; i++)
            for (int j = 0; j <= 8; j++)
            {
                if(blockc[i][j] == 0)
                    block[i][j] = 0;
            }
        //检查能否消除
        for(int i = 0; i <= 8; i++)
        {
            for(int j = 0; j <= 8; j++)
            {
                if(block[i][j]==0)
                {
                    this->exreturn = false;
                    break;
                }
            }
            if(this->exreturn == false)
                break;
        }
        if(this->exreturn == true)  //如果没有消除
        {
            if(myevent == 1)  //如果没有消除需要交换回来
            {
                if(this->directmove == 1)  //原为向右交换
                {
                    int exb = block[imove][jmove];
                    block[imove][jmove] = block[imove][jmove + 1];
                    block[imove][jmove + 1] = exb;
                    ptnBtn[imove][jmove]->mymove(2);
                    ptnBtn[imove][jmove + 1]->mymove(1);

                }
                if(this->directmove == 2)  //原为向左交换
                {
                    int exb = block[imove][jmove];
                    block[imove][jmove] = block[imove][jmove - 1];
                    block[imove][jmove - 1] = exb;
                    ptnBtn[imove][jmove]->mymove(1);
                    ptnBtn[imove][jmove - 1]->mymove(2);
                }
                if(this->directmove == 3)  //原为向下交换
                {
                    int exb = block[imove][jmove];
                    block[imove][jmove] = block[imove + 1][jmove];
                    block[imove + 1][jmove] = exb;
                    ptnBtn[imove][jmove]->mymove(4);
                    ptnBtn[imove + 1][jmove]->mymove(3);
                }
                if(this->directmove == 4)  //原为向上交换
                {
                    int exb = block[imove][jmove];
                    block[imove][jmove] = block[imove - 1][jmove];
                    block[imove - 1][jmove] = exb;
                    ptnBtn[imove][jmove]->mymove(3);
                    ptnBtn[imove - 1][jmove]->mymove(4);
                }
                //延时0.225秒,进行下一次的初始化
                QTimer::singleShot(225,this,[=](){
                    for(int i = 0; i <= 8; i++)  //使全部方块的鼠标交换可用
                        for(int j = 0; j <= 8; j++)
                            bglabel[i][j]->ex1 = true;
                    this->exreturn = true;  //exreturn为交换回来
                });
            }
            else if(myevent == 2)  //一大轮消除结束
            {
                //进行下一大轮的初始化
                for(int i = 0; i <= 8; i++)  //使全部方块的鼠标交换可用
                    for(int j = 0; j <= 8; j++)
                        bglabel[i][j]->ex1 = true;
                this->exreturn = true;  //exreturn为交换回来
                myevent = 1;
                step--;
                label6->setText(QString::number(step));  //强制类型转化
                label3->setText(QString::number(score));  //强制类型转化
                if(step == 0)  //游戏结束
                {
                    for(int i = 0; i <= 8; i++)  //使全部方块的鼠标交换失效
                        for(int j = 0; j <= 8; j++)
                            bglabel[i][j]->ex1 = false;
                    gameoverScene = new GameoverScene;
                    QTimer::singleShot(1000,this,[=](){  //延时1秒
                        this->close();  //自身关闭
                        gameoverScene->show();
                    });
                }
            }
        }
        else  //否则有消除
        {
            if(myevent == 1)  //如果为方块交换后
            {
                //更新PtnPushButton * ptnBtn[10][10]
                PtnPushButton * ptnBtnmiddle;
                if(this->directmove == 1)  //原为向右交换
                {
                    ptnBtnmiddle = ptnBtn[imove][jmove];
                    ptnBtn[imove][jmove] = ptnBtn[imove][jmove + 1];
                    ptnBtn[imove][jmove + 1] = ptnBtnmiddle;
                }
                if(this->directmove == 2)  //原为向左交换
                {
                    ptnBtnmiddle = ptnBtn[imove][jmove];
                    ptnBtn[imove][jmove] = ptnBtn[imove][jmove - 1];
                    ptnBtn[imove][jmove - 1] = ptnBtnmiddle;
                }
                if(this->directmove == 3)  //原为向下交换
                {
                    ptnBtnmiddle = ptnBtn[imove][jmove];
                    ptnBtn[imove][jmove] = ptnBtn[imove + 1][jmove];
                    ptnBtn[imove + 1][jmove] = ptnBtnmiddle;
                }
                if(this->directmove == 4)  //原为向上交换
                {
                    ptnBtnmiddle = ptnBtn[imove][jmove];
                    ptnBtn[imove][jmove] = ptnBtn[imove - 1][jmove];
                    ptnBtn[imove - 1][jmove] = ptnBtnmiddle;
                }
            }
            //以下myevent为1与为2都需要使用
            //消除方块或产生特殊方块
            for(int i = 0; i <= 8; i++)
                for(int j = 0; j <= 8; j++)
                {
                    if(block[i][j] == 0)  //消除方块
                    {
                        ptnBtn[i][j]->hide();
                        // // //消除动画未实现
                    }
                    else if(block[i][j] >= 11)  //产生特殊方块
                    {
                        ptnBtn[i][j]->hide();
                        QString btnI;  //设置字符串来存储图片路径
                        switch(block[i][j])
                        {
                            case 11: btnI += ":/happyelimres/happyelim0013.png"; break;
                            case 12: btnI += ":/happyelimres/happyelim0014.png"; break;
                            case 13: btnI += ":/happyelimres/happyelim0015.png"; break;
                            case 21: btnI += ":/happyelimres/happyelim0016.png"; break;
                            case 22: btnI += ":/happyelimres/happyelim0017.png"; break;
                            case 23: btnI += ":/happyelimres/happyelim0018.png"; break;
                            case 31: btnI += ":/happyelimres/happyelim0019.png"; break;
                            case 32: btnI += ":/happyelimres/happyelim0020.png"; break;
                            case 33: btnI += ":/happyelimres/happyelim0021.png"; break;
                            case 41: btnI += ":/happyelimres/happyelim0022.png"; break;
                            case 42: btnI += ":/happyelimres/happyelim0023.png"; break;
                            case 43: btnI += ":/happyelimres/happyelim0024.png"; break;
                            case 51: btnI += ":/happyelimres/happyelim0025.png"; break;
                            case 52: btnI += ":/happyelimres/happyelim0026.png"; break;
                            case 53: btnI += ":/happyelimres/happyelim0027.png"; break;
                            case 61: btnI += ":/happyelimres/happyelim0028.png"; break;
                            case 62: btnI += ":/happyelimres/happyelim0029.png"; break;
                            case 63: btnI += ":/happyelimres/happyelim0030.png"; break;
                        }
                        ptnBtn[i][j] = new PtnPushButton(btnI);
                        ptnBtn[i][j]->setParent(this);
                        ptnBtn[i][j]->move(300 + j*75 , 150 + i*75);
                        ptnBtn[i][j]->show();
                    }
                }
            for(int i = 0; i <= 8; i++)  //将消除并可能产生特殊方块后的ptnBtn[i][j]备份
                for(int j = 0; j <= 8; j++)
                {
                    if(block[i][j] != 0)
                        ptnBtnb[i][j] = ptnBtn[i][j];
                }
            //方块的随机产生和下落
            for(int i = 0; i <= 8; i++)  //将block[i][j]备份
                for(int j = 0; j <= 8; j++)
                    blockb[i][j]=block[i][j];
            for(int i = 0; i <= 8 ; i++)
                numzero[i]=0;
            for(int j = 0; j <= 8 ; j++)
            {
                //原方块的结果，运动
                t = 8;
                for(int i = 8; i >= 0; i--)  //同时开始下落，t为下落后方块纵向个数，i为原纵向个数
                {
                    if(blockb[i][j] != 0)
                    {
                        block[t][j] = blockb[i][j];  //存入block二维数组（结果）
                        ptnBtn[i][j]->mymove(3,t-i);  //（运动）
                        t--;
                    }
                }
                //求一列的含有0的个数
                for(int i = 0 ; i <= 8 ; i++)
                {
                    if(blockb[i][j]==0)
                        numzero[j]++;
                }
                //新产生的方块的结果，运动
                for(int i = 1; i<= numzero[j] ; i++)  //i表示第i个下落的方块
                {
                    QTimer::singleShot(225*i,this,[=](){
                        block[numzero[j]-i][j] = QRandomGenerator::global()->bounded(1, 7);  //（结果）
                        QString btnI;  //设置字符串来存储图片路径
                        switch(block[numzero[j]-i][j])  //产生随机数1~6
                        {
                            //存入字符串，1为青蛙,2为狐狸,3为熊,4为河马,5为小鸟,6为猫头鹰
                            case 1: btnI += ":/happyelimres/happyelim0007.png"; break;
                            case 2: btnI += ":/happyelimres/happyelim0008.png"; break;
                            case 3: btnI += ":/happyelimres/happyelim0009.png"; break;
                            case 4: btnI += ":/happyelimres/happyelim0010.png"; break;
                            case 5: btnI += ":/happyelimres/happyelim0011.png"; break;
                            case 6: btnI += ":/happyelimres/happyelim0012.png"; break;
                            default: qDebug() << "错误" ; return; break;  //异常处理，此处不确定用法是否正确
                        }
                        ptnBtnnew[9-i][j] = new PtnPushButton(btnI);
                        ptnBtnnew[9-i][j]->setParent(this);
                        ptnBtnnew[9-i][j]->move(300 + j*75 , 150 + 0*75);
                        ptnBtnnew[9-i][j]->show();
                        ptnBtnnew[9-i][j]->mymove(3,numzero[j]-i);  //（运动）
                    });
                }
            }
            int numzeromax = numzero[0];
            for(int j = 1; j <= 8 ; j++)  //求出numzeromax,即一列中含有0的最大个数，用于延时
            {
                if(numzero[j] > numzeromax)
                    numzeromax = numzero[j];
            }
            for(int j = 0; j <= 8 ; j++)
            {
                QTimer::singleShot(290*numzeromax,this,[=](){  //延时，等待延时的ptnBtnnew[9-i][j] = new PtnPushButton(btnI);
                    //原方块在ptnBtn[i][j]的更新
                    t=8;
                    for(int i = 8; i >= 0; i--)
                    {
                        if(blockb[i][j] != 0)
                        {
                            ptnBtn[t][j]=ptnBtnb[i][j];
                            t--;
                        }
                    }
                    //新产生的方块在ptnBtn[i][j]的更新
                    y=0;
                    for(; t >= 0; t--)
                    {
                        ptnBtn[t][j]=ptnBtnnew[8-y][j];
                        y++;
                    }
                });
            }
            QTimer::singleShot(300*numzeromax,this,[=](){
                myevent = 2;
                exreturn = true;  //下一小轮的初始化，exreturn为交换回来
                this->exfinish();  //发送信号，进行下一小轮消除
            });
        }
    });

}

void ClassicModeScene::bomb()  //对block[i][j]消除并产生炸弹,共8种情况
{
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 6; j++)
        {
            if (block[i][j] == block[i][j + 1] && block[i][j + 1] == block[i][j + 2] && block[i][j] != 0)
            {
                if(i <= 6)
                {
                    if (block[i][j] == block[i + 1][j] && block[i + 1][j] == block[i + 2][j] && block[i][j] != 0)
                    {
                        block[i + 2][j] = 0;
                        block[i][j + 1] = 0;
                        block[i][j + 2] = 0;
                        block[i + 1][j] = 0;
                        block[i][j] = block[i][j] * 10 + 3;
                        score += 15;
                    }
                    if (block[i][j + 2] == block[i + 1][j + 2] && block[i + 1][j + 2] == block[i + 2][j + 2] && block[i][j + 2] != 0)
                    {
                        block[i][j] = 0;
                        block[i][j + 1] = 0;
                        block[i + 2][j + 2] = 0;
                        block[i + 1][j + 2] = 0;
                        block[i][j + 2] = block[i][j + 2] * 10 + 3;
                        score += 15;
                    }
                }
                if(i >= 2)
                {
                    if (block[i][j] == block[i - 1][j] && block[i - 1][j] == block[i - 2][j] && block[i][j] != 0)
                    {
                        block[i][j] = block[i][j] * 10 + 3;
                        block[i][j + 1] = 0;
                        block[i][j + 2] = 0;
                        block[i - 1][j] = 0;
                        block[i - 2][j] = 0;
                        score += 15;
                    }
                    if (block[i][j + 1] == block[i - 1][j + 1] && block[i - 1][j + 1] == block[i - 2][j + 1] && block[i][j + 1] != 0)
                    {
                        block[i][j] = 0;
                        block[i][j + 1] = block[i][j + 1] * 10 + 3;
                        block[i][j + 2] = 0;
                        block[i - 1][j + 1] = 0;
                        block[i - 2][j + 1] = 0;
                        score += 15;
                    }
                    if (block[i][j + 1] == block[i + 1][j + 1] && block[i + 1][j + 1] == block[i + 2][j + 1] && block[i][j + 1] != 0)
                    {
                        block[i][j] = 0;
                        block[i + 2][j + 1] = 0;
                        block[i][j + 2] = 0;
                        block[i + 1][j + 1] = 0;
                        block[i][j + 1] = block[i][j + 1] * 10 + 3;
                        score += 15;
                    }
                    if (block[i][j + 2] == block[i - 1][j + 2] && block[i - 1][j + 2] == block[i - 2][j + 2] && block[i][j + 2] != 0)
                    {
                        block[i][j] = 0;
                        block[i][j + 1] = 0;
                        block[i][j + 2] = block[i][j + 2] * 10 + 3;
                        block[i - 1][j + 2] = 0;
                        block[i - 2][j + 2] = 0;
                        score += 15;
                    }
                }
                if(i >= 1 && i <= 7)
                {
                    if (block[i][j] == block[i - 1][j] && block[i - 1][j] == block[i + 1][j] && block[i][j] != 0)
                    {
                        block[i][j] = block[i][j] * 10 + 3;
                        block[i - 1][j] = 0;
                        block[i + 1][j] = 0;
                        block[i][j + 1] = 0;
                        block[i][j + 2] = 0;
                        score += 15;
                    }
                    if (block[i][j + 2] == block[i - 1][j + 2] && block[i - 1][j + 2] == block[i + 1][j + 2] && block[i][j + 2] != 0)
                    {
                        block[i][j + 2] = block[i][j + 2] * 10 + 3;
                        block[i - 1][j + 2] = 0;
                        block[i + 1][j + 2] = 0;
                        block[i][j] = 0;
                        block[i][j + 1] = 0;
                        score += 15;
                    }
                }
            }
        }
}

void ClassicModeScene::bombc()  //对blockc[i][j]消除并产生炸弹,共8种情况
{
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 6; j++)
        {
            if (blockc[i][j] == blockc[i][j + 1] && blockc[i][j + 1] == blockc[i][j + 2] && blockc[i][j] != 0)
            {
                if(i <= 6)
                {
                    if (blockc[i][j] == blockc[i + 1][j] && blockc[i + 1][j] == blockc[i + 2][j] && blockc[i][j] != 0)
                    {
                        blockc[i + 2][j] = 0;
                        blockc[i][j + 1] = 0;
                        blockc[i][j + 2] = 0;
                        blockc[i + 1][j] = 0;
                        blockc[i][j] = blockc[i][j] * 10 + 3;
                        score += 15;
                    }
                    if (blockc[i][j + 2] == blockc[i + 1][j + 2] && blockc[i + 1][j + 2] == blockc[i + 2][j + 2] && blockc[i][j + 2] != 0)
                    {
                        blockc[i][j] = 0;
                        blockc[i][j + 1] = 0;
                        blockc[i + 2][j + 2] = 0;
                        blockc[i + 1][j + 2] = 0;
                        blockc[i][j + 2] = blockc[i][j + 2] * 10 + 3;
                        score += 15;
                    }
                }
                if(i >= 2)
                {
                    if (blockc[i][j] == blockc[i - 1][j] && blockc[i - 1][j] == blockc[i - 2][j] && blockc[i][j] != 0)
                    {
                        blockc[i][j] = blockc[i][j] * 10 + 3;
                        blockc[i][j + 1] = 0;
                        blockc[i][j + 2] = 0;
                        blockc[i - 1][j] = 0;
                        blockc[i - 2][j] = 0;
                        score += 15;
                    }
                    if (blockc[i][j + 1] == blockc[i - 1][j + 1] && blockc[i - 1][j + 1] == blockc[i - 2][j + 1] && blockc[i][j + 1] != 0)
                    {
                        blockc[i][j] = 0;
                        blockc[i][j + 1] = blockc[i][j + 1] * 10 + 3;
                        blockc[i][j + 2] = 0;
                        blockc[i - 1][j + 1] = 0;
                        blockc[i - 2][j + 1] = 0;
                        score += 15;
                    }
                    if (blockc[i][j + 1] == blockc[i + 1][j + 1] && blockc[i + 1][j + 1] == blockc[i + 2][j + 1] && blockc[i][j + 1] != 0)
                    {
                        blockc[i][j] = 0;
                        blockc[i + 2][j + 1] = 0;
                        blockc[i][j + 2] = 0;
                        blockc[i + 1][j + 1] = 0;
                        blockc[i][j + 1] = blockc[i][j + 1] * 10 + 3;
                        score += 15;
                    }
                    if (blockc[i][j + 2] == blockc[i - 1][j + 2] && blockc[i - 1][j + 2] == blockc[i - 2][j + 2] && blockc[i][j + 2] != 0)
                    {
                        blockc[i][j] = 0;
                        blockc[i][j + 1] = 0;
                        blockc[i][j + 2] = blockc[i][j + 2] * 10 + 3;
                        blockc[i - 1][j + 2] = 0;
                        blockc[i - 2][j + 2] = 0;
                        score += 15;
                    }
                }
                if(i >= 1 && i <= 7)
                {
                    if (blockc[i][j] == blockc[i - 1][j] && blockc[i - 1][j] == blockc[i + 1][j] && blockc[i][j] != 0)
                    {
                        blockc[i][j] = blockc[i][j] * 10 + 3;
                        blockc[i - 1][j] = 0;
                        blockc[i + 1][j] = 0;
                        blockc[i][j + 1] = 0;
                        blockc[i][j + 2] = 0;
                        score += 15;
                    }
                    if (blockc[i][j + 2] == blockc[i - 1][j + 2] && blockc[i - 1][j + 2] == blockc[i + 1][j + 2] && blockc[i][j + 2] != 0)
                    {
                        blockc[i][j + 2] = blockc[i][j + 2] * 10 + 3;
                        blockc[i - 1][j + 2] = 0;
                        blockc[i + 1][j + 2] = 0;
                        blockc[i][j] = 0;
                        blockc[i][j + 1] = 0;
                        score += 15;
                    }
                }
            }
        }
}

void ClassicModeScene::row()  //对block[i][j]消除并产生行消
{
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 5; j++)
        {
            if (block[i][j] == block[i][j + 1] && block[i][j + 1] == block[i][j + 2] && block[i][j + 2] == block[i][j + 3] && block[i][j] != 0)
            {
                if(j != 5)  //五连的情况
                {
                    if(block[i][j + 3] == block[i][j + 4])
                        block[i][j + 4] = 0;
                }
                block[i][j + 2] = 10 * block[i][j + 2] + 1;
                block[i][j] = block[i][j + 1] = block[i][j + 3] = 0;
                score += 8;              
            }           
        }
}

void ClassicModeScene::rowc()  //对blockc[i][j]消除并产生行消
{
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 5; j++)
        {
            if (blockc[i][j] == blockc[i][j + 1] && blockc[i][j + 1] == blockc[i][j + 2] && blockc[i][j + 2] == blockc[i][j + 3] && blockc[i][j] != 0)
            {
                if(j != 5)  //五连的情况
                {
                    if(blockc[i][j + 3] == blockc[i][j + 4])
                        blockc[i][j + 4] = 0;
                }
                blockc[i][j + 2] = 10 * blockc[i][j + 2] + 1;
                blockc[i][j] = blockc[i][j + 1] = blockc[i][j + 3] = 0;
                score += 8;
            }
        }
}

void ClassicModeScene::column()  //对block[i][j]消除并产生列消
{
    for (int j = 0; j <= 8; j++)
        for (int i = 0; i <= 5; i++)
        {
            if (block[i][j] == block[i + 1][j] && block[i + 1][j] == block[i + 2][j] && block[i + 2][j] == block[i + 3][j] && block[i][j] != 0)
            {
                if(i != 5)  //五连的情况
                {
                    if(block[i + 3][j] == block[i + 4][j])
                        block[i + 4][j] = 0;
                }
                block[i + 2][j] = 10 * block[i + 2][j] + 2;
                block[i][j] = block[i + 1][j] = block[i + 3][j] = 0;
                score += 8;
            }
        }
}

void ClassicModeScene::columnc()  //对blockc[i][j]消除并产生列消
{
    for (int j = 0; j <= 8; j++)
        for (int i = 0; i <= 5; i++)
        {
            if (blockc[i][j] == blockc[i + 1][j] && blockc[i + 1][j] == blockc[i + 2][j] && blockc[i + 2][j] == blockc[i + 3][j] && blockc[i][j] != 0)
            {
                if(i != 5)  //五连的情况
                {
                    if(blockc[i + 3][j] == blockc[i + 4][j])
                        blockc[i + 4][j] = 0;
                }
                blockc[i + 2][j] = 10 * blockc[i + 2][j] + 2;
                blockc[i][j] = blockc[i + 1][j] = blockc[i + 3][j] = 0;
                score += 8;
            }
        }
}

void ClassicModeScene::threecon()  //对block[i][j]消除三连的方块
{
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            if (block[i][j] == block[i][j + 1] && block[i][j + 1] == block[i][j + 2] && block[i][j] != 0)
            {
                block[i][j] = block[i][j + 1] = block[i][j + 2] = 0;
                score += 3;
            }
        }
    }
    for (int j = 0; j <= 8; j++)
    {
        for (int i = 0; i <= 6; i++)
        {
            if (block[i][j] == block[i + 1][j] && block[i + 1][j] == block[i + 2][j] && block[i][j] != 0)
            {
                block[i][j] = block[i + 1][j] = block[i + 2][j] = 0;
                score += 3;
            }
        }
    }
}

void ClassicModeScene::threeconc()  //对blockc[i][j]消除三连的方块
{
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            if (blockc[i][j] == blockc[i][j + 1] && blockc[i][j + 1] == blockc[i][j + 2] && blockc[i][j] != 0)
            {
                blockc[i][j] = blockc[i][j + 1] = blockc[i][j + 2] = 0;
                score += 3;
            }
        }
    }
    for (int j = 0; j <= 8; j++)
    {
        for (int i = 0; i <= 6; i++)
        {
            if (blockc[i][j] == blockc[i + 1][j] && blockc[i + 1][j] == blockc[i + 2][j] && blockc[i][j] != 0)
            {
                blockc[i][j] = blockc[i + 1][j] = blockc[i + 2][j] = 0;
                score += 3;
            }
        }
    }
}

void ClassicModeScene::check()  //检查是否会产生行列消炸弹，如果会，把产生的行列消炸弹替换为新方块，并再次检查，直至没有产生行列消炸弹
{
    bool ok = false;
    do
    {
        int count = 0;
        bomb();
        row();
        column();
        threecon();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                if ((block[i][j] >= 10) && (block[i][j] % 10 == 3 || block[i][j] % 10 == 2 ||block[i][j] % 10 == 1))
                {
                    count++;
                    break;
                }
                else if (block[i][j] == 0)
                {
                    count++;
                    break;
                }
            if (count > 0)
                break;
        }
        if (count == 0)
            ok = true;
        else
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                {
                    if ((block[i][j] >= 10) && (block[i][j] % 10 == 3 || block[i][j] % 10 == 2 || block[i][j] % 10 == 1))
                        block[i][j] = QRandomGenerator::global()->bounded(1, 7);  //产生1~6的随机数
                    else if (block[i][j] == 0)
                        block[i][j] = QRandomGenerator::global()->bounded(1, 7);  //产生1~6的随机数
                }
        }
    } while (!ok);
}

void ClassicModeScene::paintEvent(QPaintEvent *)  //重写paintEvent事件，画背景图,一般是静态图片写到这个函数里，按钮等可以写到构造函数里
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/happyelimres/happyelim0005.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

ClassicModeScene::~ClassicModeScene()
{
    delete ui;
}
