#include "a_study.h"
#include <QFont>
#include <QKeyEvent>
#include <QApplication>

a_study::a_study()
{
    QFont newFont("Courier", 20, QFont::Bold, false);
    QApplication::setFont(newFont);

    setPlainText("1.Study");
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
