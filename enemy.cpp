#include "enemy.h"
#include <QList>
#include <typeinfo>
#include <game.h>
#include <stdlib.h>
#include <player.h>


extern game *myGame;

enemy::enemy(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){

    //When an enemy object is created setting its position and image
    int random_number = rand()%600;
    setPos(random_number,0);
    setPixmap(QPixmap(":/images/enemy.png"));

    //after creating enemy object calling its moveEnemy() function using a timer to move it in the scene
    myTimer = new QTimer();
    connect(myTimer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    myTimer->start(50);
}

void enemy::moveEnemy()
{

    QList <QGraphicsItem *> colliding_items = collidingItems();

    //Checking if an enemy is colliding with any object
    for(int i = 0,n = colliding_items.size(); i<n; ++i){

        //Ifcolliding with player
        if(typeid(*(colliding_items[i])) == typeid(player)){

            //Decreasing health

            myGame->myHealth->decreaseHealth();

            //Removing enemy to free up memory
            scene()->removeItem(this);
            delete this;
            return;
        }
    }




    setPos(x(),y()+7);

    //If enemy moves out of the scene deleting it to save memory
    if(pos().y() > 900){

        //Reduce health
        myGame->myHealth->decreaseHealth();

        scene()->removeItem(this);
        delete this;
    }
}





