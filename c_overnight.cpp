#include "c_overnight.h"
#include <QFont>
#include <QKeyEvent>

c_overnight::c_overnight()
{
    setPlainText("3.Overnight Study");
    setFont(QFont("times",18));
    setDefaultTextColor(Qt::black);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void c_overnight::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        emit up(3);
    }else if (event->key() == Qt::Key_Down){
        emit down(3);
    }else if (event->key() == Qt::Key_Y){
        emit yes(3);
    }
}
