#include "paddle2class.h"
#include <QTimer>
#include <pongball.h>
#include <QDebug>
#include <math.h>


Paddle2Class::Paddle2Class()
{
    setRect(0,0,10,100);                                                      //create dimensions of paddle2
    QTimer *timer = new QTimer();                                             //timer object, set 30ms
    timer->start(30);
    connect(timer, SIGNAL(timeout()),this, SLOT(paddle2ai()));                //Everytime 30ms passes, paddle2ai will update
}

void Paddle2Class::getBallPointer(PongBall *ball)
{
    pointerToBall = ball;                                                     //stores in private variable the pointer to ball object
}



void Paddle2Class::paddle2ai()
{
    difference = (y()+rect().height()/2) -                                    //calculate difference in y between ball and paddle2
                 (pointerToBall->y()+pointerToBall->rect().height()/2);
    speedDifficulty = 9;                                                     //speed of paddle2 as it moves
    acceleration = difference/50;                                             //the acceleration factor
    acceleration = abs(acceleration);                                         //get absolute value of acceleration to maintain positive

    if (y() <= 0)                                                             //to keep the paddle in the window boundaries
        setPos(x(), y()+1);
    else if (y() >= 600-rect().height())
        setPos(x(), y()-1);

    if (difference > 0)                                                       //computer ai of moving to "catch" the ball
        setPos(x(), y()-acceleration*speedDifficulty);
    else if (difference < 0)
        setPos(x(), y()+acceleration*speedDifficulty);
    else
        setPos(x(), y());

}



