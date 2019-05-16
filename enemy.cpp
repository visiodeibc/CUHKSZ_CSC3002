#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QPainter>
using namespace std;

Enemy::Enemy(QGraphicsItem * parent, string character): QGraphicsPixmapItem(parent)
{
    // setting the appropriate image
    if (character == "enemy_calculus")
    {
        enemy_type = "enemy_calculus";
        setPixmap(QPixmap(":/images/images/enemy_calculus.png"));

        damage_amount = 20;
    }
    else if(character == "enemy_python")
    {
        enemy_type = "enemy_python";
        setPixmap(QPixmap(":/images/images/enemy_python.png"));

        damage_amount = 30;
    }
    else // when enemy is cpp
    {
        enemy_type = "enemy_cpp";
        setPixmap(QPixmap(":/images/images/enemy_cpp.png"));

        damage_amount = 100;
    }
    health = 100;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Enemy::start_animation()
{
    timer = new QTimer;
    picCounter = 0;
    timerInterval = 500;
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(timerInterval);
}

void Enemy::animate()
{
    timer->setInterval(timerInterval);

    if (this->enemy_type == "enemy_calculus")
    {
        QPixmap p0(":/images/images/enemy_calculus1.png");
        QPixmap p1(":/images/images/enemy_calculus.png");

        if (picCounter == 0)
        {
            setPixmap(p0);
        }
        else if (picCounter == 1)
        {
            setPixmap(p1);
            timer->stop();
        }
    }
    else if (this->enemy_type == "enemy_python")
    {
        QPixmap p0(":/images/images/enemy_python1.png");
        QPixmap p1(":/images/images/enemy_python.png");

        if (picCounter == 0)
        {
            setPixmap(p0);
        }
        else if (picCounter == 1)
        {
            setPixmap(p1);
            timer->stop();
        }
    }
    else if (this->enemy_type == "enemy_cpp")
    {
        QPixmap p0(":/images/images/enemy_cpp.png");
        QPixmap p1(":/images/images/enemy_cpp.png");

        if (picCounter == 0)
        {
            setPixmap(p0);
        }
        else if (picCounter == 1)
        {
            setPixmap(p1);
            timer->stop();
        }
    }

    picCounter++;
}
