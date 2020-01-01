#include "bullet.h"
#include <QList>
#include <QTimer>
#include <game.h>
#include <typeinfo>
#include <enemy.h>
#include <addhealth.h>

extern game *myGame;

bullet::bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){

    //when a bullet object is created setting its image
    setPixmap(QPixmap(":/images/bullet.png"));

    //after creating the bullet object calling its moveBullet() funtion using a timer to move the bullet in the scene
    QTimer *myTimer = new QTimer();
    connect(myTimer,SIGNAL(timeout()),this,SLOT(moveBullet()));
    myTimer->start(50);
}

void bullet::moveBullet()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();

    //Checking if the bullet is colliding with any object
    for(int i = 0,n = colliding_items.size(); i<n; ++i){

        //If colliding with enemy
        if(typeid(*(colliding_items[i])) == typeid(enemy)){

            //Increasing score
            myGame->myScore->increaseScore();

            //Remove those colliding objects from the scene so they will be deleted and it will save memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }//If colliding with life
        else if(typeid(*(colliding_items[i])) == typeid(addHealth)){

            //Increasing health
            myGame->myHealth->increaseHealth();

            //Remove those colliding objects from the scene so they will be deleted and it will save memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }


    setPos(x(),y()-10);

    //If the bullet moves out of the scene deleting it to save memory
    if(pos().y()< 0){

        scene()->removeItem(this);
        delete this;
    }
}
