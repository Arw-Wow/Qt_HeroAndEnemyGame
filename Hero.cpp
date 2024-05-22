#include "Hero.h"
#include <QDebug>

void Hero::InitHero()
{
    pos.x = HERO_INIT_X;
    pos.y = HERO_INTI_Y;
    Hp = HERO_INIT_HP;
    Mp = HERO_INIT_MP;
    speed = HERO_INIT_SPEED;

    attack_pos.x = pos.x + HERO_WIDTH;
    attack_pos.y = pos.y + HERO_HEIGHT / 4;

    Damage = 10;

    kill_count = 0;

    isAttack = false;


    m_box.setBox(pos.x, pos.y, HERO_WIDTH, HERO_HEIGHT);
    attack_box.setBox(attack_pos.x, attack_pos.y, HERO_ATTACK_WIDTH, HERO_ATTACK_HEIGHT);


    // 加载hero的图片（还未渲染）
    Image = new QImage(":/res/res\\image/hero.jpg");
    *Image = Image->scaled(HERO_WIDTH, HERO_HEIGHT);


    // 加载attack的图片
    attackImage = new QImage(":/res/res\\image/hero_attck.jpg");
    *attackImage = attackImage->scaled(HERO_ATTACK_WIDTH, HERO_ATTACK_HEIGHT);

}

void Hero::move(int eventKey)
{
    //超出边界就不能继续动

    switch (eventKey) {
    case Qt::Key_A:
        if (pos.x - speed < 0)
            return;
        pos.x -= speed;
        break;

    case Qt::Key_D:
        if (pos.x + HERO_WIDTH + speed > 2048)
            return;
        pos.x += speed;
        break;

    case Qt::Key_W:
        if (pos.y - speed < 0)
            return;
        pos.y -= speed;
        break;

    case Qt::Key_S:
        if (pos.y + HERO_HEIGHT + speed > 768)
            return;
        pos.y += speed;
        break;
    }

    qDebug() << "move!";

    m_box.setBox(pos.x, pos.y, HERO_WIDTH, HERO_HEIGHT);
    attack_box.setBox(attack_pos.x, attack_pos.y, HERO_ATTACK_WIDTH, HERO_ATTACK_HEIGHT);

}

void Hero::attack()
{
    if (Mp < 5)
        return;

    qDebug() << "hero_attack!";


    Mp -= 5;
    isAttack = true;
}

//void Hero::attack()
//{
//    if (Mp < 5)
//        return;

//    Mp -= 5;
//    isAttack = true;
//}


