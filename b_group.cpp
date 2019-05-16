#include "b_group.h"
#include <QFont>
#include <QKeyEvent>
#include <QApplication>

b_group::b_group()
{
    QFont newFont("Courier", 20, QFont::Bold, false);
    QApplication::setFont(newFont);

    setPlainText("2.Group Study");
    setDefaultTextColor(Qt::white);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void b_group::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        emit up(2);
    }else if (event->key() == Qt::Key_Down){
        emit down(2);
    }else if (event->key() == Qt::Key_Y){
        emit yes(2);
    }
}
