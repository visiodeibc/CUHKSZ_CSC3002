#ifndef C_OVERNIGHT_H
#define C_OVERNIGHT_H

#include <QObject>
#include<QGraphicsTextItem>

class c_overnight:public QGraphicsTextItem
{
    Q_OBJECT
public:
    c_overnight();
    void keyPressEvent(QKeyEvent *event);
signals:
    void up(int a);
    void down(int a);
    void yes(int a);
};

#endif // C_OVERNIGHT_H
