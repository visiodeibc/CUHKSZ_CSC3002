#include "game.h"
#include <QObject>

Game::Game(QObject *parent) : QObject(parent)
{
    player_navigation = new Player(0, "smart");
    player_battle = new Player(0, "smart");
    navigation_window = new Navigation(player_navigation);

    enemy_1 = new Enemy(0,"enemy_calculus");

    navigation_window->show();
    battle = new battle_scene(player_battle,enemy_1);

    connect(player_navigation,&Player::change_view,this,&Game::activate);

}

void Game::activate()
{
    navigation_window->hide();
    battle->show();
    battle->study_1->setFocus();

}


