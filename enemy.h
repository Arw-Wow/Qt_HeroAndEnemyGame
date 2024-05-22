#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include "Position.h"

#include "Hero.h"
#include "touchbox.h"

//constexpr int ENEMY_INIT_X = 1024;
constexpr int ENEMY_INTI_Y = 480;
constexpr int ENEMY_INIT_HP = 30;
constexpr int ENEMY_INIT_MP = 20;
constexpr int ENEMY_WIDTH = 150;
constexpr int ENEMY_HEIGHT = 200;
constexpr int ENEMY_INIT_SPEED = 10;	// 稍慢于 hero
constexpr int LEFT = 0;
constexpr int RIGHT = 1;

class Enemy
{


public:
    Enemy() = default;

    void InitEnemy();
    void attack();
    void move();
    void set_hero(Hero* hero);


private:

    Hero* hero;	// 保存hero的指针


public:

    Position pos;
    int brith_direction;	// 0为left，1为right
    int Hp;
    int Mp;
    int Damage;	// 攻击力
    int speed;	// 一次移动的像素
//    double move_interval;	// 移动间隔时间
//    QTimer* move_timer;	// 移动的计时器
    QImage* Image;
    int brith_interval;	//以秒为单位

    TouchBox m_box;


};

#endif // ENEMY_H
