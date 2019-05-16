#ifndef D_RUN_H
#define D_RUN_H

#include <QObject>
#include<QGraphicsTextItem>

class d_run:public QGraphicsTextItem
{
    Q_OBJECT
public:
    d_run();
    void keyPressEvent(QKeyEvent *event);
signals:
    void up(int a);
    void down(int a);
    void yes(int a);
};

#endif // D_RUN_H
