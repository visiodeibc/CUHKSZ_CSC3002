#include "game.h"

Game::Game()
{
    player = new Player(0, "smart");
    navigation_window = new Navigation(player);
    enemy_1 = new Enemy(0,"enemy_calculus");


    navigation_window->show();
    battle = new battle_scene(player,enemy_1);
    player->setview(navigation_window,battle);
    setFocus();


}


