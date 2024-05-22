#include "enemy.h"
#include <time.h>
#include <QDebug>
#include <QTimer>

void Enemy::InitEnemy()
{
    Hp = ENEMY_INIT_HP;
    Mp = ENEMY_INIT_MP;
    speed = ENEMY_INIT_SPEED;	// 一次移动的像素
//    move_interval = 100;
    brith_interval = 3;

    // 设置攻击力
    Damage = 2;


    Image = new QImage(":/res/res\\image/enemy1.jpg");
    *Image = Image->scaled(ENEMY_WIDTH, ENEMY_HEIGHT);


    qDebug() << "InitEnemy";

    //随机左右生成位置
    srand(time(0));
    brith_direction = rand() % 2;
    if (brith_direction == LEFT) {
        pos.x = 0;
    }
    else {
        pos.x = 2048 - ENEMY_WIDTH - 1;	//窗口width设置为了2048
    }

    //出生高度是固定的（不会飞）
    pos.y = ENEMY_INTI_Y;

    m_box.setBox(pos.x, pos.y, ENEMY_WIDTH, ENEMY_HEIGHT);
}

void Enemy::move()
{
    //追着hero跑
    if (pos.x < hero->pos.x) {
        // 超出边界就不继续动
        if (pos.x + ENEMY_WIDTH + speed > 2048)
            return;

        pos.x += speed;
    }
    else {
        // 超出边界就不继续动
        if (pos.x - speed < 0)
            return;

        pos.x -= speed;
    }


    m_box.setBox(pos.x, pos.y, ENEMY_WIDTH, ENEMY_HEIGHT);

//    qDebug() << "move!!!";
}

void Enemy::attack()
{
    hero->Hp -= Damage;
}

void Enemy::set_hero(Hero *hero)
{
    this->hero = hero;

}
