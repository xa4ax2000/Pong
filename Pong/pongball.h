#ifndef PONGBALL_H
#define PONGBALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <paddle1class.h>
#include <paddle2class.h>
#include <playerscore.h>
#include <computerscore.h>


class PongBall : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    friend class Paddle2Class; friend class playerscore; friend class computerscore;
private:
    int caseNum;
    playerscore* pScore;
    computerscore* cScore;
    bool hDirection = false;                                         //horizontal direction of ball: (-) towards player, (+) away from player
    bool vDirection = true;                                          //vertical direction of ball: (-) down, (+) up
    int speed = 10;                                                  //the distance traveled per signal (time)
    paddle1class* pointerToPaddle1;                                  //class pointer to paddle1class object
    Paddle2Class* pointerToPaddle2;                                  //class pointer to paddle1class object
public:
    PongBall(paddle1class* paddle1, Paddle2Class* paddle2);          //Constructor
    void getPointerToScore(playerscore* playerScore, computerscore* computerScore);
public slots:
    void move();                                                     //move function for signal/slot
};

#endif // PONGBALL_H
