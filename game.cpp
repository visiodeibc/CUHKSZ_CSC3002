#include "game.h"
#include "player.h"
#include "battle_scene.h"
#include <QObject>

#include <QLabel>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include <QDesktopWidget>
#include "startingpage.h"

Game::Game(QObject *parent) : QObject(parent)
{
    player_navigation = new Player(nullptr, "smart");
    navigation_window = new Navigation(player_navigation);
    player_name = "smart";
    navigation_window->show();
    battle = new battle_scene(player_name);

    //navigation to battle scene
    connect(player_navigation, SIGNAL(change_view()), this, SLOT(activate()));

    //battle scene to navigtion/ending/run
//   connect(battle, SIGNAL(battle_scene::battle_won()), this, SLOT(battle_won()));
//   connect(battle, SIGNAL(battle_scene::battle_lost()), this, SLOT(battle_lost()));
    connect(battle,SIGNAL(battle_ran()),this,SLOT(battle_ran()));

}

void Game::activate()
{
    navigation_window->hide();
    battle->show();
    battle->study_1->setFocus();

}

void Game::restart_game()
{
    // Show the starting page

    StartingPage StartingPage;
    StartingPage.show();
}

void Game::battle_won(int battle_stage)
{
    if(battle_stage == 2){

    }else if(battle_stage == 3){

    }
}

void Game::battle_lost()
{

    QWidget* game_over_menu = new QWidget;
    QLabel* you_lose = new QLabel("<h1> You lost the game! </h1>");

    you_lose->setAlignment(Qt::AlignCenter);

    QPushButton* restart = new QPushButton("Restart");
    QPushButton* quit = new QPushButton("Quit the game");


    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(you_lose);
    layout->addWidget(restart);
    layout->addWidget(quit);

    game_over_menu->setLayout(layout);
    game_over_menu->show();

    connect(restart, SIGNAL(clicked()), battle, SLOT(close()));
    connect(restart, SIGNAL(clicked()), game_over_menu, SLOT(close()));
    connect(restart, SIGNAL(clicked()), this, SLOT(activate()));

    connect(quit, SIGNAL(clicked()), battle, SLOT(close()));
    connect(quit, SIGNAL(clicked()), game_over_menu, SLOT(close()));
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
}

void Game::battle_ran()
{

    battle->hide();
    navigation_window->show();
}
