#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPushButton>
#include<QAction>
#include<QLabel>
#include<QBitmap>
#include<QWidget>
#include<QTimer>
#include<QPropertyAnimation>
#include<QFile>
#include<QString>
#include<QDebug>
#include<QPalette>
#include<QFont>

Widget::Widget(QWidget *parent)  //排行榜类
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //界面图标、大小、名称
    this->setFixedSize(1200,900);
    this->setWindowIcon(QIcon(":/happyelimres/happyelim0001.png"));
    this->setWindowTitle("开心消消乐");


    //读取成绩文件
    QFile * ranklist_file=new QFile(":/happyelimres/data_of_ranklist.txt");
    ranklist_file -> open(QIODevice::ReadOnly);
    QString * rank = new QString[20];//前面10个位账号的，后10个位对应的成绩
    //读取前十个数据
    for(int i = 0 ; i < 10 && (!ranklist_file->atEnd()) ; i++)
    {
        QString temp = ranklist_file->readLine();
        for(int j = 0 ; j < 9 ; j++)
            rank[i]+=temp[j];

        for(int j=10;temp[j]>='0'&&temp[j]<='9';j++)
            rank[i+10]+=temp[j];
    }
    ranklist_file->close();
    //显示成绩的标签，前面10个位账号的，后10个位对应的成绩
    QLabel *rank_label=new QLabel[20];
    for(int i = 0 ; i < 10 ; i++)
    {
        //使成绩及账号投映到标签上
        rank_label[i].setText(rank[i]);
        rank_label[i+10].setText(rank[i+10]);
        //设置标签的格式
        rank_label[i].resize(180,53);
        rank_label[i+10].resize(100,53);
        rank_label[i].move(459,189+i*59);
        rank_label[i+10].move(639,189+i*59);
        rank_label[i].setParent(this);
        rank_label[i+10].setParent(this);
        //设置边框为空
        rank_label[i].setFrameStyle(0);
        rank_label[i+10].setFrameStyle(0);
        //设置label上的文字的对齐方式为水平居中和垂直居中
        rank_label[i].setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        rank_label[i+10].setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置字体
        QFont rank_font;
        rank_font.setFamily("MV Boli");
        rank_font.setPointSize(12);
        QPalette rank_color;
        rank_color.setColor(QPalette::WindowText, Qt::Key_LightBulb);//账号字体蓝色
        rank_label[i].setPalette(rank_color);
        rank_color.setColor(QPalette::WindowText, Qt::red);//成绩字体红色
        rank_label[i+10].setPalette(rank_color);
        rank_label[i].setFont(rank_font);
        rank_label[i+10].setFont(rank_font);
        qDebug()<<rank_label[i].text()<<'_'<<rank_label[i+10].text();

    }


}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent*)
{
    //界面背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/happyelimres/happyelim0034.jpg");
    painter.drawPixmap(0,0,1200,900,pix);
    //榜单背景
    QPainter painter_ranklist_background(ui->rank_list_background);
    QPixmap pix_ranklist_background;
    pix_ranklist_background.load(":/happyelimres/happyelim0035.png");
    pix_ranklist_background = pix_ranklist_background.scaled(ui->rank_list_background->width(), ui->rank_list_background->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter_ranklist_background.drawPixmap(0,0,pix_ranklist_background.mask());
    ui->rank_list_background->setPixmap(pix_ranklist_background);
}

