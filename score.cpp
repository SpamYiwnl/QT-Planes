#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent):QGraphicsTextItem(parent){

    //When a score object is created in the game setting its value and image
    //This will take its default postion of left top corner of the screen pos(x()->0,y()->0)
    Score = 0;
    setPlainText(QString("Score: ")+QString::number(Score));
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("times",16));

}

void score::increaseScore()
{
    //Increasing the score and setting the result on the scene
    Score++;
    setPlainText(QString("Score: ")+QString::number(Score));
}

int score::getScore(){

    return Score;
}

