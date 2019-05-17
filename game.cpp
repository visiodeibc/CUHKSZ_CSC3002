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
#include <QMessageBox>
#include <QMediaPlayer>
#include <QProcess>

#include "game.h"
#include "player.h"
#include "battle_scene.h"
#include "startingpage.h"

Game::Game(QObject *parent, string player) : QObject(parent)
{

    set_player(player);
    player_navigation = new Player(nullptr, player_name);
    navigation_window = new Navigation(player_navigation);

    // Create game over window
    game_over_window = new Game_Over();

    navigation_window->show();
    battle = new battle_scene(player_name);

    //navigation to battle scene
    connect(player_navigation, SIGNAL(change_view()), this, SLOT(activate_battle()));

    //battle scene to navigtion/ending/run
    connect(battle,SIGNAL(battle_ran()),this,SLOT(battle_ran()));
    connect(battle,SIGNAL(battle_won(int)),this,SLOT(battle_won(int)));
    connect(battle,SIGNAL(battle_lost()),this,SLOT(battle_lost()));

    // background music for the dungeon (dungeon.mp3)
    music_dungeon  = new QMediaPlayer();
    music_dungeon->setMedia(QUrl("qrc:/soundtracks/soundtracks/dungeon.mp3"));
    music_dungeon->setVolume(75);
    music_dungeon->play();

    // background music for battle scene (battle.mp3)
    music_battle = new QMediaPlayer();
    music_battle->setMedia(QUrl("qrc:/soundtracks/soundtracks/battle.mp3"));
    music_battle->setVolume(75);

    // background music for closing (closing.mp3)
    music_closing = new QMediaPlayer();
    music_closing->setMedia(QUrl("qrc:/soundtracks/soundtracks/closing.mp3"));
    music_closing->setVolume(75);
}

// Changes the player to the selected
void Game::set_player(string player)
{
    this->player_name = player;
}

void Game::activate_battle()
{

    if ( (battle->battle_stage == 1 && player_navigation->pos().x() == 150.0) ||
         (battle->battle_stage == 2 && player_navigation->pos().x() == 450.0) ||
         (battle->battle_stage == 3 && player_navigation->pos().x() == 950.0) )
    {
        switch( QMessageBox::question(navigation_window,
                    tr("Dungeon and Studies"),
                    tr("Are you sure you want to enter?"),

                    QMessageBox::Yes |
                    QMessageBox::No ) )
        {
          case QMessageBox::Yes: // If user chooses to enter the battle
           music_dungeon->stop();
           navigation_window->hide();
           battle->show();
           music_battle->play();
           battle->study_1->setFocus();
           break;
          case QMessageBox::Cancel:
            break;
          default:
            break;
        }
    }
    else
    {
        QMessageBox::warning(navigation_window,
                tr("Dungeon and Studies"),
                tr("You have no permission to enter this room.") );
    }

}


void Game::restart_game()
{
    // Show the starting page

    music_dungeon->stop();
    music_battle->stop();

    StartingPage StartingPage;
    StartingPage.show();
}

void Game::battle_won(int battle_stage)
{

    if(battle_stage == 2)
    {
        battle->hide();
        music_battle->stop();

        navigation_window->show();
        music_dungeon->play();
    }
    else if(battle_stage == 3)
    {
        battle->hide();
        music_battle->stop();

        navigation_window->show();
        music_dungeon->play();
    }

    // If all the battle stages are won, hide all windows except game_over.
    if(battle_stage == 4)
    {
        battle->hide();
        music_battle->stop();

        navigation_window->hide();
        music_dungeon->stop();

        game_over_window->show();
        music_closing->play();
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

    connect(restart, &QPushButton::clicked, [](){
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    );

    // exit button: exit the game
    connect(quit, &QPushButton::clicked, [](){
        exit(1);
    }
    );

    //background music
    music_battle->stop();
    music_dungeon->play();
}

void Game::battle_ran()
{
    music_battle->stop();
    music_dungeon->play();
    battle->hide();
    navigation_window->show();
}
