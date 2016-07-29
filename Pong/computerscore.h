#ifndef COMPUTERSCORE_H
#define COMPUTERSCORE_H

#include <QGraphicsTextItem>
#include <pongball.h>

class computerscore:public QGraphicsTextItem
{
friend class PongBall;
private:
    int computerScore;                          //create playerScore variable
public:
    computerscore();                            //constructor
    void increaseScore();                       //increase score function
};

#endif // COMPUTERSCORE_H
