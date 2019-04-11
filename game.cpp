#include "game.h"
#include <QObject>

Game::Game(QObject *parent) : QObject(parent)
{
    player_navigation = new Player(0, "smart");
    navigation_window = new Navigation(player_navigation);
    player_name = "smart";
    navigation_window->show();
    battle = new battle_scene(player_name);

    //navigation to battle scene
    connect(player_navigation,&Player::change_view,this,&Game::activate);

    //battle scene to navigtion/ending/run
    connect(battle,&battle_scene::battle_won,this,&Game::battle_won);
    connect(battle,&battle_scene::battle_lost,this,&Game::battle_lost);
    connect(battle,&battle_scene::battle_ran,this,&Game::battle_ran);

}

void Game::activate()
{
    navigation_window->hide();
    battle->show();
    battle->study_1->setFocus();

}

void Game::battle_won(int battle_stage)
{
    if(battle_stage == 2){

    }else if(battle_stage == 3){

    }
}

void Game::battle_lost()
{

}

void Game::battle_ran()
{
    navigation_window->show();
    battle->hide();
    navigation_window->player->setFocus();
}


