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

#include "game.h"
#include "player.h"
#include "battle_scene.h"
#include "startingpage.h"

// To play the soundtrack
#include <QMediaPlayer>

Game::Game(QObject *parent, string player) : QObject(parent)
{
    set_player(player);
    player_navigation = new Player(nullptr, player_name);
    navigation_window = new Navigation(player_navigation);
    navigation_window->show();
    battle = new battle_scene(player_name);

    //navigation to battle scene
    connect(player_navigation, SIGNAL(change_view()), this, SLOT(activate_battle()));

    //battle scene to navigtion/ending/run
    connect(battle,SIGNAL(battle_ran()),this,SLOT(battle_ran()));
    connect(battle,SIGNAL(battle_won(int)),this,SLOT(battle_won(int)));
    connect(battle,SIGNAL(battle_lost()),this,SLOT(battle_lost()));

    // Play background music
    music_dungeon  = new QMediaPlayer();
    music_dungeon->setMedia(QUrl("qrc:/soundtracks/soundtracks/dungeon.mp3"));
    music_dungeon->play();
    music_battle = new QMediaPlayer();
    music_battle->setMedia(QUrl("qrc:/soundtracks/soundtracks/battle.mp3"));

}

// Changes the player to the selected
void Game::set_player(string player)
{
    this->player_name = player;
}

void Game::activate_battle()
{
    //background music
    music_dungeon->stop();
    music_battle->play();

    navigation_window->hide();
    battle->show();
    battle->study_1->setFocus();
}

void Game::restart_game()
{
    // Show the starting page

    StartingPage StartingPage;
    StartingPage.show();

    //background music
    music_dungeon->stop();
    music_battle->stop();
}

void Game::battle_won(int battle_stage)
{

    if(battle_stage == 2)
    {

    }
    else if(battle_stage == 3)
    {
    }

    battle->hide();
    navigation_window->show();

    //background music
    music_battle->stop();
    music_dungeon->play();
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

    //background music
    music_battle->stop();
    music_dungeon->play();
}
