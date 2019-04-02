#ifndef GAME_H
#define GAME_H

#include "navigation.h"
#include "player.h"

class Game
{
public:
    Game();
    Navigation * navigation_window;
    Player * player;
};

#endif // GAME_H
