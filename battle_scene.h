#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "battle_dialog.h"
#include "navigation.h"


class battle_scene : public QGraphicsView

{
public:

    battle_scene(Player *player=0,Enemy *enemy=0);

    Player * player;
    Enemy * enemy;
    battle_dialog  * current_battle_dialog;
    QGraphicsScene * scene;
};

#endif // BATTLE_SCENE_H
