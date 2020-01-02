#include "enemy.h"
#include <QList>
#include <typeinfo>
#include <game.h>
#include <stdlib.h>
#include <player.h>


extern game *myGame;

enemy::enemy(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){

    //setting position and image
    int random_number = rand()%600;
    setPos(random_number,0);
    setPixmap(QPixmap(":/images/enemy.png"));

    //using a timer to work with the moveEnemy() function and to move it in the scene
    myTimer = new QTimer();
    connect(myTimer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    myTimer->start(50);
}

void enemy::moveEnemy()
{

    QList <QGraphicsItem *> colliding_items = collidingItems();

    //checking if an enemy collides with any object
    for(int i = 0,n = colliding_items.size(); i<n; ++i){

        //colliding with player
        if(typeid(*(colliding_items[i])) == typeid(player)){

            //decreasing health

            myGame->myHealth->decreaseHealth();

            //removing enemy after being hit to free up and save memory
            scene()->removeItem(this);
            delete this;
            return;
        }
    }




    setPos(x(),y()+7);

    //deleting the enemy after they go out of the scene to free up and save memory
    if(pos().y() > 900){

        //Reduce health
        myGame->myHealth->decreaseHealth();

        scene()->removeItem(this);
        delete this;
    }
}





