#include "prologue.h"
#include "game.h"
#include "game_over.h"

#include <QObject>
#include <QDebug>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>

using namespace std;

game_over::game_over()
{

    frame_number = 1;

    //create a scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);

    //set view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    //add item to the scene
    setScene(scene);

    scene->setBackgroundBrush(QBrush(QImage(":/images/images/prologue1.png")));

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
}

void Prologue::change_screen()
{
    if (frame_number == 2)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/prologue_scene_1.png")));
    }
    else if (frame_number == 3)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/images/images/prologue_scene_2.png")));
    }
}
