#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include<QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Helpwindow; }  //游戏帮助界面
QT_END_NAMESPACE

class Helpwindow : public QWidget
{
    Q_OBJECT

public:
    Helpwindow(QWidget *parent = nullptr);
    ~Helpwindow();
    void paintEvent(QPaintEvent *); //重写paintEvent事件

private:
    Ui::Helpwindow *ui;
};
#endif // HELPWINDOW_H
