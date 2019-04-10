#include "navigation.h"
#include<QKeyEvent>

Navigation::Navigation( Player * player)
{
    //create a scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);
    scene->setBackgroundBrush(QBrush(QImage(":/images/images/bg.png")));


    //create an item to put into the scene
    player->setPos(300,300);
    player->setFocus();

    //set view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    //add item to the scene
    scene->addItem(player);
    setScene(scene);

}

void Navigation::add_enemy_to_scene(Enemy *enemy, int x_pos, int y_pos)
{
    enemy->setPos(x_pos,y_pos);
    //scene->addItem(enemy);
}


