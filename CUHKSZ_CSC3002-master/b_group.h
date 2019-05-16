#ifndef B_GROUP_H
#define B_GROUP_H

#include <QObject>
#include<QGraphicsTextItem>

class b_group:public QGraphicsTextItem
{
    Q_OBJECT
public:
    b_group();
    void keyPressEvent(QKeyEvent *event);
signals:
    void up(int a);
    void down(int a);
    void yes(int a);
};

#endif // B_GROUP_H
