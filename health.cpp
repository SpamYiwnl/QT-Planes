#include "health.h"
#include <QFont>
#include <game.h>
#include <gameover.h>
#include <stdlib.h>

extern game *myGame;

health::health(QGraphicsItem *parent):QGraphicsTextItem(parent){

    //setting position, value and image to health object
    Health = 3;
    setPlainText(QString("Health: ")+QString::number(Health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));


}

void health::decreaseHealth()
{
    //showing and decreasing value of health
        Health--;
        setPlainText(QString("Health: ")+QString::number(Health));

    //displaying the game over ui and stopping the game if the players health is gone
        if(Health==0){
        myGame->closeAll();
        myGame->hide();
        over = new gameOver();
        over->show();
        }
}

void health::increaseHealth()
{
    //showing and increasing value of health
        Health++;
        setPlainText(QString("Health: ")+QString::number(Health));
}


int health::getHealth()
{
    return Health;
}
