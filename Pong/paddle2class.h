#ifndef PADDLE2CLASS_H
#define PADDLE2CLASS_H

#include <QGraphicsRectItem>
#include <QObject>
#include <pongball.h>

class Paddle2Class : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    friend class PongBall;
private:
    PongBall* pointerToBall;                          //store pointer to the Ball
    int difference;
    int speedDifficulty;
    int acceleration;
public:
    Paddle2Class();                                   //constructor
    void getBallPointer(PongBall* ball);
public slots:
    void paddle2ai();
};

#endif // PADDLE2CLASS_H
