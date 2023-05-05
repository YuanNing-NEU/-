#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include <QMainWindow>

namespace Ui {
class GameoverScene;
}

class GameoverScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameoverScene(QWidget *parent = nullptr);
    ~GameoverScene();


    void paintEvent(QPaintEvent *);  //重写paintEvent事件，画背景图

private:
    Ui::GameoverScene *ui;
};

#endif // GAMEOVERSCENE_H
