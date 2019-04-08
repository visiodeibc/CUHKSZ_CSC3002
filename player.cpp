#include "player.h"
#include<QGraphicsScene>
#include<QKeyEvent>


Player::Player(QGraphicsItem *parent, string player): QGraphicsPixmapItem(parent){
    // setting the appropriate image
    if (player == "smart"){             // when the player is smart
        setPixmap(QPixmap(":/images/images/main_smart.png"));
    }else if(player == "cool"){         // when the player is cool
        setPixmap(QPixmap(":/images/images/cool.png"));
    }else{                              // when the player is lazy
        setPixmap(QPixmap(":/images/images/lazy.png"));
    }

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if(pos().x() >0)
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() <1000)
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
    else if (event->key()== Qt::Key_A){
        //scene()->removeItem(this);
        current_navigation_view->hide();
        current_battle_view->show();

    }
}

void Player::setview(QGraphicsView *navigation_view,QGraphicsView * battle_view)
{
    current_navigation_view = navigation_view;
    current_battle_view = battle_view;
}
