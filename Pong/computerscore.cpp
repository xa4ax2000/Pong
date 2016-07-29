#include "computerscore.h"
#include <QFont>

computerscore::computerscore()
{
    computerScore = 0;
    setPlainText(QString("Computer Score: ")+QString::number(computerScore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Comics", 20));
    setPos(500, 0);
}

void computerscore::increaseScore()
{
    computerScore++;
    setPlainText(QString("Computer Score: ")+QString::number(computerScore));
}
