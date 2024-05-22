#ifndef HERO_H
#define HERO_H

#include <QWidget>
#include "Position.h"
#include "touchbox.h"
//#include "enemy.h"


constexpr int HERO_INIT_X = 1024;
constexpr int HERO_INTI_Y = 480;
constexpr int HERO_INIT_HP = 100;
constexpr int HERO_INIT_MP = 100;
constexpr int HERO_WIDTH = 150;
constexpr int HERO_HEIGHT = 200;
constexpr int HERO_INIT_SPEED = 15;
constexpr int HERO_ATTACK_WIDTH = 200;
constexpr int HERO_ATTACK_HEIGHT = 120;


class Hero
{
public:
    Hero() = default;

    void InitHero();
    void move(int eventKey);

    void attack();
//    void attackRight();



public:

    Position pos;
    Position attack_pos;
    int Hp;
    int Mp;
    int Damage;
    int speed;	// 一次移动的像素
    QImage* Image;
    bool isAttack;

    TouchBox m_box;
    TouchBox attack_box;

    QImage* attackImage;

    int kill_count;


};

#endif // HERO_H
