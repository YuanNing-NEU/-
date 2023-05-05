#include "regis.h"
#include "ui_regis.h"
#include<QAction>
#include<QIcon>
#include<QMessageBox>
#include<QDebug>
#include<QAction>
#include<QString>
#include <iostream>
#include <fstream>
#include<QDebug>
#include<QFile>
#include <QPainter>
#include<qdebug.h>
#include<QFileDialog>
#include<QMessageBox>
#include<QPushButton>

using namespace std;

regis::regis(QWidget *parent)  //注册界面类
    : QMainWindow(parent)
    , ui(new Ui::regis)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/happyelimres/happyelim0001.png"));
    this->setWindowTitle("开心消消乐");

    ui->lineEdit->setEchoMode(QLineEdit::Normal);
    ui->lineEdit->setPlaceholderText("请创建8位数字账号");//输入账号框

    ui->lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->lineEdit_2->setPlaceholderText("请创建6位密码");//输入密码框

    //创建并保存账号
    connect(ui->asd,&QPushButton::clicked,[=](){
        QString  pas;
        pas= ui->lineEdit->text();//读取文本框字符串

        QFile file_account("D:/Qtproject/happyelim/happyelimres/account.txt");//使用前需检查路径
        if(file_account.open(QIODevice::Append))
        {
            file_account.write(pas.toUtf8());
            pas='\n';
            file_account.write(pas.toUtf8());
            qDebug()<<"ok";
        }
        else qDebug()<<"no";
        file_account.close();
    });
    //创建并保存密码
    connect(ui->asd,&QPushButton::clicked,[=](){
        QString  passer;
        passer= ui->lineEdit_2->text();//读取文本框字符串

        QFile file_pass("D:/Qtproject/happyelim/happyelimres/password.txt");//使用前需检查路径
        if(file_pass.open(QIODevice::Append))
        {
            file_pass.write(passer.toUtf8());
            passer='\n';
            file_pass.write(passer.toUtf8());
            qDebug()<<"ok";
        }
        else qDebug()<<"no";
        file_pass.close();
    });

}

void regis::paintEvent(QPaintEvent *)  //重写paintEvent事件，画背景图
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/happyelimres/happyelim0002.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

regis::~regis()
{
    delete ui;
}

