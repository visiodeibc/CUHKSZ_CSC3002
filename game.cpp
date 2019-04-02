#include "game.h"

Game::Game()
{
    player = new Player();
    navigation_window = new Navigation(0,player);

}
