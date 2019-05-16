
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>


class battle_scene;
class Navigation;
using namespace std;

class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = nullptr, string character = nullptr);

    void keyPressEvent(QKeyEvent *event);
    void reset_health(int a);

    //attributes
    int health;
    int attack_1_dmg;
    int attack_2_dmg;
    int attack_3_dmg;
    string player_type;

private:
    QTimer * timer;
    int picCounter;
    int timerInterval;

public slots:
    void start_animation(); // Start timer to begin animation
    void animate(); // Animate the player item

signals:
    void change_view();
    void inaccessible();
};

#endif // PLAYER_H
