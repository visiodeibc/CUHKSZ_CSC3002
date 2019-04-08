#include "battle_dialog.h"
#include <QKeyEvent>
#include <QFont>


battle_dialog::battle_dialog(QGraphicsItem *parent, Player *player, Enemy *enemy)
{
    study = new QGraphicsTextItem();
    study->setPlainText("1. Study");
    study->setFont(QFont("times",18));
    study->setDefaultTextColor(Qt::yellow);

    group_study = new QGraphicsTextItem();
    group_study->setPlainText("2. Group Study");
    group_study->setFont(QFont("times",18));
    group_study->setDefaultTextColor(Qt::black);

    overnight_study = new QGraphicsTextItem();
    overnight_study->setPlainText("3. Overnight Study");
    overnight_study->setFont(QFont("times",18));
    overnight_study->setDefaultTextColor(Qt::black);

    run = new QGraphicsTextItem();
    run->setPlainText("4. Run");
    run->setFont(QFont("times",18));
    run->setDefaultTextColor(Qt::black);

    current_state = study;

    player_fighting = player;
    enemy_fighting = enemy;

    player_health = new QGraphicsTextItem();
    player_health->setFont(QString::number(player_fighting->health));
    player_health->setFont(QFont("times",25));
    player_health->setDefaultTextColor(Qt::green);

    enemy_health = new QGraphicsTextItem();
    enemy_health->setFont(QString::number(enemy_fighting->health));
    enemy_health->setFont(QFont("times",25));
    enemy_health->setDefaultTextColor(Qt::red);
}
