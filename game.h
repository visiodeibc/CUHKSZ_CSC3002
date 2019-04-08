#ifndef GAME_H
#define GAME_H

#include "navigation.h"
#include "player.h"
#include "battle_scene.h"
#include "enemy.h"

#include<QObject>
#include<QWidget>

class Game : public QWidget
{
public:
    Game();

    Navigation * navigation_window;
    Player * player;
    battle_scene * battle;
    Enemy * enemy_1;
};

#endif // GAME_H
