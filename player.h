
#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsView>


class battle_scene;
class Navigation;
using namespace std;

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0, string character = nullptr);

    void keyPressEvent(QKeyEvent *event);
    void reset_health(int a);

    //attributes
    int health;
    int attack_1_dmg;
    int attack_2_dmg;
    int attack_3_dmg;

signals:
    void change_view();

};

#endif // PLAYER_H
