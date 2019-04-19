#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>


Player::Player(QGraphicsItem *parent, string player): QGraphicsPixmapItem(parent){
    // setting the appropriate image
    if (player == "smart")
    {
        setPixmap(QPixmap(":/images/images/main_smart.png"));
    }
    else if(player == "cool")
    {
        setPixmap(QPixmap(":/images/images/main_cool.png"));
    }
    else if(player == "lazy")
    {
        setPixmap(QPixmap(":/images/images/main_lazy.png"));
    }
    health = 100;
    setFlag(QGraphicsItem::ItemIsFocusable);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if((pos().x() >0) && (pos().y() == 500.0))
        {
            setPos(x()-50,y());
        }
        qDebug() << "myObject knows you pressed left!";
        qDebug() << "x:" << pos().x();
        qDebug() << "y:" << pos().y();
    }
    else if (event->key() == Qt::Key_Right){
        if((pos().x() < 1000) && (pos().y() == 500.0))
        setPos(x()+50,y());

        qDebug() << "myObject knows you pressed right!";
        qDebug() << "x:" << pos().x();
        qDebug() << "y:" << pos().y();
    }

    if (pos().x() == 150.0 || pos().x() == 450.0 || pos().x() == 950.0)
    {
        if (event->key() == Qt::Key_Up)
        {
            if((pos().y() >250))
            setPos(x(),y()-50);

            qDebug() << "myObject knows you pressed up!";
            qDebug() << "x:" << pos().x();
            qDebug() << "y:" << pos().y();
        }
        else if (event->key() == Qt::Key_Down)
        {
            if(pos().y() <500)
            setPos(x(),y()+50);

            qDebug() << "myObject knows you pressed down!";
            qDebug() << "x:" << pos().x();
            qDebug() << "y:" << pos().y();
        }

        if(pos().y() == 250.0)
        {
            if (event->key()== Qt::Key_A){
                emit change_view();
            }
        }
    }
}

void Player::reset_health(int a)
{
    health = a;
}


