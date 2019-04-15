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
    Q_OBJECT
public:

    battle_scene(string player_name);
    void add_new_enemy(string enemy_name);

    Player * player;
    Enemy * enemy;
    QGraphicsScene * scene;
    a_study  * study_1;
    b_group * group_2;
    c_overnight * overnight_3;
    d_run * run_4;

    QGraphicsTextItem * player_health;
    QGraphicsTextItem * enemy_health;

    int battle_stage=1;

signals:
    void battle_won(int battle_stage);
    void battle_lost();
    void battle_ran();

public slots:

    void battle_finish();
    void up(int a);
    void down(int a);
    void yes(int a);
};

#endif // BATTLE_SCENE_H
