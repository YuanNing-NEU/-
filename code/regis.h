#ifndef REGIS_H
#define REGIS_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class regis; }
QT_END_NAMESPACE

class regis : public QMainWindow  //注册界面类
{
    Q_OBJECT

public:
    regis(QWidget *parent = nullptr);
    ~regis();

    void paintEvent(QPaintEvent *);  //重写paintEvent事件，画背景图

private:
    Ui::regis *ui;
};
#endif // REGIS_H
