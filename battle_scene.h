#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "navigation.h"

#include "player.h"
#include "enemy.h"

#include "a_study.h"
#include "b_group.h"
#include "c_overnight.h"
#include "d_run.h"



class battle_scene : public QGraphicsView

{
public:

    battle_scene(Player *player=0,Enemy *enemy=0);

    Player * player;
    Enemy * enemy;
    QGraphicsScene * scene;

    a_study  * study_1;
    b_group * group_2;
    c_overnight * overnight_3;
    d_run * run_4;

    QGraphicsTextItem * player_health;
    QGraphicsTextItem * enemy_health;


public slots:
    void up(int a);
    void down(int a);
    void yes(int a);
};

#endif // BATTLE_SCENE_H