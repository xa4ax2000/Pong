#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <QGraphicsTextItem>
#include <pongball.h>

class playerscore:public QGraphicsTextItem
{
friend class PongBall;
private:
    int playerScore;                            //create playerScore variable
public:
    playerscore();                              //constructor
    void increaseScore();                       //increase score function
};

#endif // PLAYERSCORE_H
