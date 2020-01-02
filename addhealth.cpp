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

    //Creating a life object,position and image
    int randomNumber = rand()%900;
    setPos(randomNumber,0);
    setPixmap(QPixmap(":/images/life.png"));

    //using a timer with move() method
    QTimer *newTimer = new QTimer();
    connect(newTimer,SIGNAL(timeout()),this,SLOT(move()));
    newTimer->start(50);
}


void addHealth::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();

    //Checking if life collides with any object
    for(int i = 0,n = colliding_items.size(); i<n; ++i){

        //colliding with player
        if(typeid(*(colliding_items[i])) == typeid(player)){

            //Increasing health
            myGame->myHealth->increaseHealth();

            //freeing up memory after colliding
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(),y()+7);

    //freeing up memory when it moves out of the scene
    if(pos().y() > 900){

        scene()->removeItem(this);
        delete this;
    }


}
