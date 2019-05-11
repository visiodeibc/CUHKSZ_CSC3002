#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QGraphicsScene>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"

class game_over : public QGraphicsView
{
    Q_OBJECT

public:
    game_over();

    QGraphicsScene * scene;

    int frame_number;
    string player_name;

private:
    inline void change_screen();

//public slots:
//    void skip_prologue();
};

#endif // GAME_OVER_H
