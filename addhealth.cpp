#include "addhealth.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include <game.h>
#include <player.h>
#include <QList>
#include <typeinfo>
#include <enemy.h>

extern game*myGame;

addHealth::addHealth(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){

    //When a life object is created setting its position and image
    int randomNumber = rand()%900;
    setPos(randomNumber,0);
    setPixmap(QPixmap(":/images/life.png"));

    //after creating the life object calling its move() method using a timer to move it in the scene
    QTimer *newTimer = new QTimer();
    connect(newTimer,SIGNAL(timeout()),this,SLOT(move()));
    newTimer->start(50);
}


void addHealth::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();

    //Checking if life is colliding with any object
    for(int i = 0,n = colliding_items.size(); i<n; ++i){

        //If colliding with player
        if(typeid(*(colliding_items[i])) == typeid(player)){

            //Increasing health
            myGame->myHealth->increaseHealth();

            //Removing life to free up memory
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(),y()+7);

    //If life moves out of the scene deleting it to save memory
    if(pos().y() > 900){

        scene()->removeItem(this);
        delete this;
    }


}
