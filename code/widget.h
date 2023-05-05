#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget  //排行榜类
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent*);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
