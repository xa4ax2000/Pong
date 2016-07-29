#include "playerscore.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>

playerscore::playerscore()
{
    playerScore = 0;                                                            //initialize score to 0
    setPlainText(QString("Player Score: ") + QString::number(playerScore));     //set the score
    setDefaultTextColor(Qt::blue);                                              //set font color
    setFont(QFont("Comics", 20));                                               //set font and size
    setPos(100, 0);                                                             //set position
}

void playerscore::increaseScore()
{
        playerScore++;
        setPlainText(QString("Player Score: ") + QString::number(playerScore)); //update the score
}

