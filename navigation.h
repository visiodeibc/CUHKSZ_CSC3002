#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"


class Navigation : QGraphicsView
{
public:
    Navigation(QWidget * parent=0, Player * player = 0);
    QGraphicsScene * scene;
    Player * player;
};

#endif // NAVIGATION_H
