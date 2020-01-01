#include "health.h"
#include <QFont>
#include <game.h>
#include <gameover.h>
#include <stdlib.h>

extern game *myGame;

health::health(QGraphicsItem *parent):QGraphicsTextItem(parent){

    //When a health object is created in the game setting its value,position and image
    Health = 3;
    setPlainText(QString("Health: ")+QString::number(Health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));


}

void health::decreaseHealth()
{
    //Decreasing the health and setting the result in the scene
        Health--;
        setPlainText(QString("Health: ")+QString::number(Health));

    //If player has run out of life,Stopping the game and displaying the game over ui
        if(Health==0){
        myGame->closeAll();
        myGame->hide();
        over = new gameOver();
        over->show();
        }
}

void health::increaseHealth()
{
    //Increasing the health and setting the result in the scene
        Health++;
        setPlainText(QString("Health: ")+QString::number(Health));
}


int health::getHealth()
{
    return Health;
}
