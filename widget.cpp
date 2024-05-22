#include "widget.h"
#include "ui_widget.h"
#include <synchapi.h>	//包括了Sleep，是qt自带的库

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    ui->Label_Hero_Hp
}

Widget::~Widget()
{
    delete ui;
}


void Widget::InitGame() {

    //set the widget title
    setWindowTitle("横板打怪小游戏——test by Arw");

    // set the background
    QPixmap bkground(":/res/res\\image/bk.jpg");
    bkground = bkground.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, bkground);
    setPalette(pal);

    // 设置目标击杀数
    kill_goal = 10;

    //init the hero
    hero = new Hero;
    hero->InitHero();

    //init the enemy
    enemy = new Enemy;
    enemy->set_hero(hero);
    enemy->InitEnemy();

    // 初始化计时器开始计时
    m_interval = 100;
    timer = new QTimer(this);
    timer->setInterval(m_interval);
    timer->setSingleShot(false);	// 重复触发timeout
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start();

    // 设置显示初始Hp
    QString cur_hp = "Hero_Hp: " + QString::number(hero->Hp);
    ui->Label_Hero_Hp->setText(cur_hp);

    // 设置显示击杀数
    QString cur_kill_count = "击杀数：" + QString::number(hero->kill_count);
    ui->Label_Kill_Count->setText(cur_kill_count);

    // 设置显示目标击杀数
    QString goal = "目标击杀：" + QString::number(kill_goal);
    ui->Label_Kill_Goal->setText(goal);

    // 设置显示初始Mp
    QString cur_mp = "Hero_Mp: " + QString::number(hero->Mp);
    ui->Label_Hero_Mp->setText(cur_mp);

}

void Widget::PlayGame()
{

}

void Widget::LoseGame()
{
    QMessageBox endBox;
    endBox.setText("您已死亡，游戏失败！");
    endBox.exec();

    exit(0);

}

void Widget::WinGame()
{
    QMessageBox endBox;
    endBox.setText("达成目标，游戏胜利！");
    endBox.exec();

    exit(0);
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    hero->move(event->key());

    qDebug() << "yes";

    if (event->key() == Qt::Key_K) {
        hero->attack();

        hero->attack_pos.setPosition(hero->pos.x + HERO_WIDTH, hero->pos.y + HERO_HEIGHT / 4);
        hero->attack_box.setBox(hero->attack_pos.x, hero->attack_pos.y, HERO_ATTACK_WIDTH, HERO_ATTACK_HEIGHT);

        if (hero->isAttack && enemy->m_box.isTouch(hero->attack_box)) {
            enemy->Hp -= hero->Damage;
        }

//        qDebug() << hero->isAttack;
    }
    else if (event->key() == Qt::Key_J) {
        hero->attack();

        hero->attack_pos.setPosition(hero->pos.x - HERO_ATTACK_WIDTH, hero->pos.y + HERO_HEIGHT / 4);
        hero->attack_box.setBox(hero->attack_pos.x, hero->attack_pos.y, HERO_ATTACK_WIDTH, HERO_ATTACK_HEIGHT);

         if (hero->isAttack && enemy->m_box.isTouch(hero->attack_box)) {
            enemy->Hp -= hero->Damage;
        }
    }


    update();
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawImage(QPoint(enemy->pos.x, enemy->pos.y), *(enemy->Image));
    painter.drawImage(QPoint(hero->pos.x, hero->pos.y), *(hero->Image));	//后画hero让hero比enemy图层更高一些不会被覆盖

    if (hero->isAttack) {
        painter.drawImage(QPoint(hero->attack_pos.x, hero->attack_pos.y), *(hero->attackImage));
        hero->isAttack = false;
    }

}

void Widget::onTimeout()
{
    static int cnt = 0;
    cnt++;

    // 每隔一秒，Mp加一
    if (cnt % 10 == 1) {
        if (hero->Mp < 100)
            hero->Mp++;
    }

    QString cur_mp = "Hero_Mp: " + QString::number(hero->Mp);
    ui->Label_Hero_Mp->setText(cur_mp);

    enemy->move();

    if (enemy->m_box.isTouch(hero->m_box)) {
        enemy->attack();

        QString cur_hp = "Hero_Hp: " + QString::number(hero->Hp);
        ui->Label_Hero_Hp->setText(cur_hp);
    }


    update();

    if (enemy->Hp <= 0) {
        if (enemy != nullptr)
            delete enemy;

        hero->kill_count++;
        QString cur_kill_count = "击杀数：" + QString::number(hero->kill_count);
        ui->Label_Kill_Count->setText(cur_kill_count);

        enemy = new Enemy;
        enemy->set_hero(hero);
        enemy->InitEnemy();

        if (hero->kill_count == kill_goal) {
            WinGame();
        }
    }

    if (hero->Hp <= 0) {
        LoseGame();
    }


}

void Widget::on_Button_Help_clicked()
{
    help_widget* help = new help_widget;
    help->show();
}
