#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent):QGraphicsTextItem(parent){


    Score = 0;
    setPlainText(QString("Score: ")+QString::number(Score));
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("times",16));

}

void score::increaseScore()
{
    //increasing and displaying the score
    Score++;
    setPlainText(QString("Score: ")+QString::number(Score));
}

int score::getScore(){

    return Score;
}

