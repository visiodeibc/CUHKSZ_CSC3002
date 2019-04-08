#include "battle_scene.h"

battle_scene::battle_scene(Player *player, Enemy *enemy)
{

    //create a scene
    scene =  new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);
    scene->setBackgroundBrush(QBrush(QImage(":/images/images/bg.png")));



    //create an item to put into the scene
    //player->setPos(0,this->height()/2 - (player->pixmap().height()/2));    //reset it to the lsft top position
    enemy->setPos(0,0);                                                     //reset the enemy position to right top

    //create battle dialog part
    current_battle_dialog = new battle_dialog(0,player,enemy);
    current_battle_dialog->setFlag(QGraphicsItem::ItemIsFocusable);
    //current_battle_dialog->setFocus();

    current_battle_dialog->study->setPos(1000,600);
    current_battle_dialog->group_study->setPos(1000,630);
    current_battle_dialog->overnight_study->setPos(1000,690);
    current_battle_dialog->run->setPos(1000,720);

    current_battle_dialog->player_health->setPos(0,20);
    current_battle_dialog->enemy_health->setPos(0,20);

    //add item to the scene
    //scene->addItem(player);
    scene->addItem(enemy);
    scene->addItem(current_battle_dialog->study);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    setScene(scene);

}
