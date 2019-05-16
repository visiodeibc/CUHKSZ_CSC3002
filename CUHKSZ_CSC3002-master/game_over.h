#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include "player.h"
#include "enemy.h"


class Game_Over : public QGraphicsView
{
    Q_OBJECT
public:
    Game_Over();

    QGraphicsScene * scene;

private:
    inline void change_screen();

public slots:
    void restart();
    void exit();

};

#endif // GAME_OVER_H
