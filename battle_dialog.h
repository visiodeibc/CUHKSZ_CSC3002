#ifndef BATTLE_DIALOG_H
#define BATTLE_DIALOG_H

#include<QGraphicsTextItem>
#include<QGraphicsScene>
#include<QObject>
#include"player.h"
#include"enemy.h"

class battle_dialog: public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    battle_dialog(QGraphicsItem * parent =0,Player * player =0,Enemy * enemy=0);
   // void keyPressEvent(QKeyEvent *event);
    void playerAttack(int attack_type=0);
    void enemyAttack(int attack_type=0 );

    QGraphicsTextItem * study;
    QGraphicsTextItem * group_study;
    QGraphicsTextItem * overnight_study;
    QGraphicsTextItem * run;

    QGraphicsTextItem * current_state;

    Player * player_fighting;
    Enemy * enemy_fighting;

    QGraphicsTextItem * player_health;
    QGraphicsTextItem * enemy_health;


};

#endif // BATTLE_DIALOG_H
