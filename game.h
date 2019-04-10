#ifndef GAME_H
#define GAME_H

#include "navigation.h"
#include "player.h"
#include "battle_scene.h"
#include "enemy.h"

#include<QObject>
#include<QWidget>

class Game: public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject *parent = nullptr);

    Navigation * navigation_window;
    Player * player_navigation;
    Player * player_battle;
    battle_scene * battle;
    Enemy * enemy_1;
    int stage_number;

public slots:
    void activate();
};

#endif // GAME_H
