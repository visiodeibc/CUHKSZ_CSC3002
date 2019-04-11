#ifndef NAVIGATION_H
#define NAVIGATION_H


#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "enemy.h"


class Navigation : public QGraphicsView
{
public:
    Navigation(Player * player = 0);

    void add_enemy_to_scene(Enemy *enemy, int x_pos, int y_pos);

    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
};

#endif // NAVIGATION_H
