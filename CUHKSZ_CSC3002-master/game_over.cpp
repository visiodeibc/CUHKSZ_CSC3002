#include "game_over.h"
#include "game.h"
#include "startingpage.h"

#include <QPushButton>
#include <QtGui>

#include <QHBoxLayout>
#include <QApplication>
#include <QLabel>
#include <QObject>

#include <QProcess>

Game_Over::Game_Over()
{
    //create a scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);

    //set view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    //add item to the scene
    setScene(scene);
    scene->setSceneRect(0,0,1200,800);
    scene->setBackgroundBrush(QBrush(QImage(":/images/images/closing.png")));

    // Implement the restart button
    QPushButton * restart_button = new QPushButton("Restart");
    restart_button->move(500,550);
    restart_button->setFixedHeight(40);
    restart_button->setFixedWidth(200);
    restart_button->setStyleSheet("width: 200px");
    scene->addWidget(restart_button);

    // Implement the exit buttony
    QPushButton * exit_button = new QPushButton("Exit");
    exit_button->move(500,650);
    exit_button->setFixedHeight(40);
    exit_button->setFixedWidth(200);
    exit_button->setStyleSheet("width: 200px");
    scene->addWidget(exit_button);

    // restart button: restart the game
    connect(restart_button, &QPushButton::clicked, [this](){
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    );

    // exit button: exit the game
    connect(exit_button, &QPushButton::clicked, [this](){
        exit();
    }
    );

}

void Game_Over::restart()
{
    this->hide();
    StartingPage StartingPage;
    StartingPage.show();
}
void Game_Over::exit()
{
    close();
    qApp->quit();
}
