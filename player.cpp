#include "player.h"
#include<QGraphicsScene>
#include<QKeyEvent>


Player::Player(QGraphicsItem *parent, string player): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/WeChat Image_20190319002956.png"));
    // setting the appropriate image
    if (player == "smart"){             // when the player is smart
        setPixmap(QPixmap(":/images/images/smart"));
    }else if(player == "cool"){         // when the player is cool
        setPixmap(QPixmap(":/images/images/cool"));
    }else{                              // when the player is lazy
        setPixmap(QPixmap(":/images/images/lazy"));
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if(pos().x() >0)
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() <1000+ this->pixmap().width())
        setPos(x()+20,y());
    }
    else if (event->key() == Qt::Key_Up){
        if((pos().y() >0))
        setPos(x(),y()-20);
    }
    else if (event->key() == Qt::Key_Down){
        if(pos().y() <700)
        setPos(x(),y()+20);
    }
}
