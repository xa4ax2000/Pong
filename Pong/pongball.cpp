#include "pongball.h"
#include <QTimer>
#include <QDebug>
#include <paddle1class.h>
#include <playerscore.h>


PongBall::PongBall(paddle1class* paddle1, Paddle2Class* paddle2)
{
    setRect(0,0,12,12);                                                             //When object is created, it creats object at (0,0) with dimensions (12x12)
    pointerToPaddle1 = paddle1;                                                      //store paddle1 pointer into private variable pointer: pointerToPaddle1
    pointerToPaddle2 = paddle2;
    QTimer *timer = new QTimer();                                                   //timer object is created (our signal)
    timer->start(50);                                                               //Set timer at 50 ms
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));                          //connect timer object to move function in this ball object
}

void PongBall::getPointerToScore(playerscore *playerScore, computerscore* computerScore)
{
    pScore = playerScore;
    cScore = computerScore;
}

void PongBall::move()
{
    if (x() <= 0){                                                                  //if ball goes out of bounds (x<0 || x>800)
        setPos(400,300);
        caseNum = 0;
        cScore->increaseScore();
    }
    else if (x() >= 800){
        setPos(400,300);
        caseNum = 0;
        pScore->increaseScore();
    }


    if (y() <= 0 || y() >= 600-this->rect().height())                               //if ball is outside of y() boundaries, then change bool of vertical direction
        vDirection = (vDirection+1)%2;


    //divides the paddle1 into 5 equal components: 2,1,0,1,2 --> each case has a different speed effect
    if (x() >= 0 && x() <=800)
        if(x() <= pointerToPaddle1->x()+pointerToPaddle1->rect().width()){
            if (y() >= pointerToPaddle1->y() && y() <= pointerToPaddle1->y()+pointerToPaddle1->rect().height()/5)
                caseNum = 2;
            else if (y() >= pointerToPaddle1->y()+pointerToPaddle1->rect().height()/5 && y() <= pointerToPaddle1->y()+2*(pointerToPaddle1->rect().height()/5))
                caseNum = 1;
            else if (y() >= pointerToPaddle1->y()+2*(pointerToPaddle1->rect().height()/5) && y() <= pointerToPaddle1->y()+3*(pointerToPaddle1->rect().height()/5))
                caseNum = 0;
            else if (y() >= pointerToPaddle1->y()+3*(pointerToPaddle1->rect().height()/5) && y() <= pointerToPaddle1->y()+4*(pointerToPaddle1->rect().height()/5))
                caseNum = 1;
            else if (y() >= pointerToPaddle1->y()+4*(pointerToPaddle1->rect().height()/5) && y() <= pointerToPaddle1->y()+pointerToPaddle1->rect().height())
                caseNum = 2;
        }
    //computer paddle2 effect on ball
    if (x() >= 0 && x() <=800)
        if(x() >= pointerToPaddle2->x()){
            if (y() >= pointerToPaddle2->y() && y() <= pointerToPaddle2->y()+pointerToPaddle2->rect().height()/5)
                caseNum = 2;
            else if (y() >= pointerToPaddle2->y()+pointerToPaddle2->rect().height()/5 && y() <= pointerToPaddle2->y()+2*(pointerToPaddle2->rect().height()/5))
                caseNum = 1;
            else if (y() >= pointerToPaddle2->y()+2*(pointerToPaddle2->rect().height()/5) && y() <= pointerToPaddle2->y()+3*(pointerToPaddle2->rect().height()/5))
                caseNum = 0;
            else if (y() >= pointerToPaddle2->y()+3*(pointerToPaddle2->rect().height()/5) && y() <= pointerToPaddle2->y()+4*(pointerToPaddle2->rect().height()/5))
                caseNum = 1;
            else if (y() >= pointerToPaddle2->y()+4*(pointerToPaddle2->rect().height()/5) && y() <= pointerToPaddle2->y()+pointerToPaddle2->rect().height())
                caseNum = 2;
        }

    if (x() >= 0 && x() <= 800)                                                     //if ball object is within x() boundaries
        if (x() <= pointerToPaddle1->x() + pointerToPaddle1->rect().width() &&      //if x() of ball lies behind or on the paddleX+width AND
            y() >= pointerToPaddle1->y() &&                                         //if y() of ball lies at or below the paddleY AND
            y() <= pointerToPaddle1->y() + pointerToPaddle1->rect().height())       //if y() of ball lies at or above the paddleY+height THEN
            hDirection = (hDirection+1)%2;                                          //change bool of horizontal direction

    if (x() >= 0 && x() <=800)                                                      //if ball object is within x() boundaries
        if(x() >= pointerToPaddle2->x() - pointerToPaddle2->rect().width() &&       //if x() of ball lies behind or on the paddleX+width AND
           y() >= pointerToPaddle2->y() &&                                          //if y() of ball lies at or below the paddleY AND
           y() <= pointerToPaddle2->y() + pointerToPaddle2->rect().height())        //if y() of ball lies at or above the paddleY+height THEN
            hDirection = (hDirection+1)%2;                                          //change bool of horizontal direction

    if (y() > 0 || y() < 600){                                                      //controls ball movement with speed variable depending on bool cases
        if (hDirection == false && vDirection == true){
            if (caseNum == 2)
                setPos(x()-speed, y()-3*speed);
            else if (caseNum == 1)
                setPos(x()-speed, y()-1.5*speed);
            else
                setPos(x()-speed, y()-speed);
        }
        else if (hDirection == false && vDirection == false){
            if (caseNum == 2)
                setPos(x()-speed, y()+3*speed);
            else if (caseNum == 1)
                setPos(x()-speed, y()+1.5*speed);
            else
                setPos(x()-speed, y()+speed);
        }
        else if (hDirection == true && vDirection == true){
            if (caseNum == 2)
                setPos(x()+speed, y()-3*speed);
            else if (caseNum == 1)
                setPos(x()+speed, y()-1.5*speed);
            else
                setPos(x()+speed, y()-speed);
        }
        else if (hDirection == true && vDirection == false){
            if (caseNum == 2)
                setPos(x()+speed, y()+3*speed);
            else if (caseNum == 1)
                setPos(x()+speed, y()+1.5*speed);
            else
                setPos(x()+speed, y()+speed);
        }
    }

}

