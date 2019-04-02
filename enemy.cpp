#include "enemy.h"

Enemy::Enemy(QGraphicsItem * parent, string character , int enemy_type): QGraphicsPixmapItem(parent)
{
    // setting the appropriate image
    if (character == "enemy_calculus"){
        setPixmap(QPixmap(":/images/images/enemy_calculus"));
    }else if(character == "enemy_python"){
        setPixmap(QPixmap(":/images/images/enemy_python"));
    }else{  // when enemy is cpp
        setPixmap(QPixmap(":/images/images/cpp"));
    }

    // setting the attributes
    if (enemy_type == 1){     // level 1 enemy

    }else if(enemy_type == 2){// level 2 enemy

    }else{                    // level 3 enemy

    }
}
