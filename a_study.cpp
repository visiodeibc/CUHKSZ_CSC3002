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
        //if(current_state == (dialog_list.){
        emit up(1);
          //this->setDefaultTextColor(Qt::black);
          //  qDebug() <<"im here";
    }else if (event->key() == Qt::Key_Down){
        //if(current_state == (dialog_list.){
          //this->setDefaultTextColor(Qt::yellow);
        emit down(1);
          //  qDebug() <<"im here";
    }else if (event->key() == Qt::Key_Y){
        emit yes(1);
    }
}
