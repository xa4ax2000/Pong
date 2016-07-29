#include "paddle1class.h"
#include <QDebug>
#include <QKeyEvent>

paddle1class::paddle1class()
{
setRect(0,0,10,100);                                          //When object is created, it creates object at (0,0) with dimensions 10x100
}

void paddle1class::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){                           //If 'up' key is pushed, paddle moves up until it hits ceiling
        if(y()>0)
            setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){                   //If 'down' key is pushed, paddle moves down until it hits floor
        if(y()<(600-this->rect().height()))
            setPos(x(),y()+10);
    }
}


