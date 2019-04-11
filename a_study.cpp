#include "a_study.h"
#include <QFont>
#include <QKeyEvent>

a_study::a_study()
{
    setPlainText("1.Study");
    setFont(QFont("times",18));
    setDefaultTextColor(Qt::yellow);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void a_study::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        emit up(1);
    }else if (event->key() == Qt::Key_Down){
        emit down(1);
    }else if (event->key() == Qt::Key_Y){
        emit yes(1);
    }
}
