#ifndef PADDLE1CLASS_H
#define PADDLE1CLASS_H

#include <QGraphicsRectItem>

class paddle1class: public QGraphicsRectItem
{
public:
    paddle1class();
    void keyPressEvent(QKeyEvent *event);                       //when a key is pressed it will call this function
    void boundaries();                                          //maintain the boundaries of the paddle
};

#endif // PADDLE1CLASS_H
