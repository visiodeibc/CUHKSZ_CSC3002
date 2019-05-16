#include "c_overnight.h"
#include <QFont>
#include <QApplication>
#include <QKeyEvent>

c_overnight::c_overnight()
{
    QFont newFont("Courier", 20, QFont::Bold, false);
    QApplication::setFont(newFont);

    setPlainText("3.Overnight Study");

    setDefaultTextColor(Qt::white);
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
