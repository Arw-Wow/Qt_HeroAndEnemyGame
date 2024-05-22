#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>
#include <time.h>
#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QMessageBox>

#include "Position.h"
#include "Hero.h"
#include "enemy.h"

#include "help_widget.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE






class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;


//自己添加的

public:

    void InitGame();
    void PlayGame();

    void LoseGame();
    void WinGame();

//    Enemy* InitEnemy();


private:

//    void renderImage();
    Hero* hero;
    Enemy* enemy;

    int kill_goal;

    QTimer* timer;

    int m_interval;



protected:

    void keyPressEvent(QKeyEvent *event) override; //键盘按下事件
//    void keyReleaseEvent(QKeyEvent *event) override; //键盘松开事件

    void paintEvent(QPaintEvent *e) override;


public slots:

    void onTimeout();

private slots:
    void on_Button_Help_clicked();
};
#endif // WIDGET_H
