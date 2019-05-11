#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>

#include <QTimer>
#include <QPainter>
using namespace std;

Player::Player(QGraphicsItem *parent, string player): QGraphicsPixmapItem(parent){
    // setting the appropriate image
    if (player == "smart")
    {
        player_type = "smart";
        setPixmap(QPixmap(":/images/images/main_smart.png"));
    }
    else if(player == "cool")
    {
        player_type = "cool";
        setPixmap(QPixmap(":/images/images/main_cool.png"));

    }
    else if(player == "lazy")
    {
        player_type = "lazy";
        setPixmap(QPixmap(":/images/images/main_lazy.png"));
    }
    health = 100;
    setFlag(QGraphicsItem::ItemIsFocusable);

//    connect(this, SIGNAL(start_animation()), this, SLOT(init_animation()));

//    timer = new QTimer;
//    picCounter = 0;
//    timerInterval = 1000;
//    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
//    timer->start(timerInterval);
}

void Player::start_animation()
{
    timer = new QTimer;
    picCounter = 0;
    timerInterval = 500;
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(timerInterval);
}

void Player::animate()
{
    timer->setInterval(timerInterval);

    if (player_type == "smart")
    {
        QPixmap p0(":/images/images/main_smart1.png");
        QPixmap p1(":/images/images/main_smart.png");
    }

    QPixmap p0(":/images/images/main_cool1.png");
    QPixmap p1(":/images/images/main_cool.png");
    QPixmap p2(":/images/images/main_cool.png");

    if (picCounter == 0)
    {
        setPixmap(p0);
    }
    else if (picCounter == 1)
    {
        setPixmap(p1);
        timer->stop();
    }
    picCounter++;
//    if (picCounter == 3)
//        picCounter = 0;
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
            if (event->key()== Qt::Key_A)
            {
                emit change_view();
            }
        }
    }
}

void Player::reset_health(int a)
{
    health = a;
}


