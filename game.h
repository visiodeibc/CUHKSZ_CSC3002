#ifndef GAME_H
#define GAME_H

#include "navigation.h"
#include "player.h"
#include "battle_scene.h"

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>

// To play the soundtrack
#include <QMediaPlayer>


class Game: public QObject
{
    Q_OBJECT

public:
    Game(QObject *parent = nullptr, string player = nullptr);

    Navigation * navigation_window;
    Player * player_navigation;
    string player_name;
    battle_scene * battle;

public slots:
    void set_player(string player);
    void activate_battle(); //activate the navigation -> battle scene
    void restart_game(); // restarts -> open the starting page
//    void battle_won(int battle_stage);
    void battle_won(int battle_stage);
    void battle_lost();
    void battle_ran();

private:
    // Setup for the soundtrack
    QMediaPlayer * music_dungeon;
    QMediaPlayer * music_battle;

};

#endif // GAME_H
