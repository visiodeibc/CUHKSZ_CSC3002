#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
using namespace std;

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0, string character = 0);
    void keyPressEvent(QKeyEvent *event);

    //attributes
    int health;
    int attack_1_dmg;
    int attack_2_dmg;
    int attack_3_dmg;

private:

};

#endif // PLAYER_H
