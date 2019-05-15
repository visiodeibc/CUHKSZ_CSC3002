#include "prologue.h"
#include "game.h"

#include <QObject>
#include <QDebug>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>

using namespace std;

Game * game;

Prologue::Prologue(string player)
{

    frame_number = 1;
    player_name = player;

    //create a scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);

    //set view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    //add item to the scene
    setScene(scene);

    scene->setBackgroundBrush(QBrush(QImage(":/images/images/p1.png")));

    // Implement the Next button
    QPushButton * next_button = new QPushButton("Next");
    next_button->move(300,500);
    next_button->setFixedHeight(40);
    next_button->setFixedWidth(200);
    next_button->setStyleSheet("width: 200px");
    scene->addWidget(next_button);

    // Implement the skip button
    QPushButton * skip_button = new QPushButton("Skip");
    skip_button->move(700,500);
    skip_button->setFixedHeight(40);
    skip_button->setFixedWidth(200);
    skip_button->setStyleSheet("width: 200px");
    scene->addWidget(skip_button);

    // Skip button: goes straight to the navigation scene
    connect(skip_button, &QPushButton::clicked, [this](){
        skip_prologue();
    }
    );

    // Next button: gets next prologue scene
    connect(next_button, &QPushButton::clicked, [this](){
        if (frame_number > 0 && frame_number < 8)
        {
            change_screen();
            frame_number++;
        }
        else
        {
            skip_prologue(); // If prologue scene ends, go to navigation scene.
        }
    }
    );
}

void Prologue::change_screen()
{
    if (frame_number == 2)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/p2.png")));
    }
    else if (frame_number == 3)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/p3.png")));
    }
    else if (frame_number == 4)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/p4.png")));
    }
    else if (frame_number == 5)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/p5.png")));
    }
    else if (frame_number == 6)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/p6.png")));
    }
    else if (frame_number == 7)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/p7.png")));
    }
}

void Prologue::skip_prologue()
{
    this->hide();
    game = new Game(nullptr, player_name);
}
