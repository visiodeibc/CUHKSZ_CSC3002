#ifndef A_STUDY_H
#define A_STUDY_H

#include <QObject>
#include<QGraphicsTextItem>

class a_study:  public QGraphicsTextItem
{
    Q_OBJECT
public:
    a_study();
    void keyPressEvent(QKeyEvent *event);
signals:
    void up(int a);
    void down(int a);
    void yes(int a);
};

#endif // A_STUDY_H
