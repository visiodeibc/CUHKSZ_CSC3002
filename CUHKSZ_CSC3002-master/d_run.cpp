#include "d_run.h"
#include <QFont>
#include <QKeyEvent>

d_run::d_run()
{
    setPlainText("4.Run");
    setFont(QFont("Minecraft",15));
    setDefaultTextColor(Qt::white);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void d_run::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        emit up(4);
    }else if (event->key() == Qt::Key_Down){
        emit down(4);
    }else if (event->key() == Qt::Key_Y){
        emit yes(4);
    }
}
