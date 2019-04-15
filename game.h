#ifndef GAME_H
#define GAME_H

#include "navigation.h"
#include "player.h"
#include "battle_scene.h"

#include<QObject>
#include<QWidget>

// new edits
#include <QWidget>

#include <QPushButton>

#include <QObject>

#include <QString>

#include <QGraphicsView>

#include <QGraphicsScene>


class Game: public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject *parent = nullptr);

    Navigation * navigation_window;
    Player * player_navigation;
    string player_name;
    battle_scene * battle;

public slots:
    void activate(); //activate the navigation -> battle scene
    void restart_game(); // restarts -> open the starting page
    void battle_won(int battle_stage);
    void battle_lost();
    void battle_ran();
};

#endif // GAME_H
