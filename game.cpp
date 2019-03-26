#include "Game.h"
#include<QMediaPlayer>
#include<QBrush>

Game::Game(QWidget *parent)
{

    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,800);
    setBackgroundBrush(QBrush(QImage(":/images/images/WeChat Image_20190319002937.png")));


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    //create an item to put into the scene
    player = new Player();
    player->setPos(0,scene->height()/2 - (player->pixmap().height()/2));

    //add item to the scene
    scene ->addItem(player);

    // make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    //QGraphicsView *view = new QGraphicsView(scene);



    show();
    ;



}
