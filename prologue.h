#ifndef PROLOGUE_H
#define PROLOGUE_H

#include <QGraphicsScene>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"

class Prologue : public QGraphicsView
{
    Q_OBJECT

public:
    Prologue(string player = nullptr);

    QGraphicsScene * scene;

    int frame_number;
    string player_name;

private:
    inline void change_screen();

public slots:
    void skip_prologue();
};

#endif // PROLOGUE_H
