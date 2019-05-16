#include "d_run.h"
#include <QFont>
#include <QKeyEvent>
#include <QApplication>

d_run::d_run()
{
    QFont newFont("Courier", 20, QFont::Bold, false);
    QApplication::setFont(newFont);

    setPlainText("4.Run");
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
