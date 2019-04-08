
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
    Player(QGraphicsItem * parent=0, string character = 0);

    void keyPressEvent(QKeyEvent *event);
    void setview(QGraphicsView *navigation_view,QGraphicsView *battle_view);

    //attributes
    int health;
    int attack_1_dmg;
    int attack_2_dmg;
    int attack_3_dmg;

    QGraphicsView *current_navigation_view;
    QGraphicsView *current_battle_view;

private:

};

#endif // PLAYER_H
