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
    Enemy(QGraphicsItem * parent = nullptr, string character = nullptr);

    //attributes
    int health;
    int attack_1;
    string enemy_type;

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

#endif // ENEMY_H
