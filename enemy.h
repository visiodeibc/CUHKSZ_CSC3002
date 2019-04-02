#ifndef ENEMY_H
#define ENEMY_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<string>
using namespace std;

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0, string character=0 , int enemy_type = 0);

    //attributes
    int health;
    int attack_1;
};

#endif // ENEMY_H
