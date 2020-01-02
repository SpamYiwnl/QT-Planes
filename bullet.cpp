#include "bullet.h"
#include <QList>
#include <QTimer>
#include <game.h>
#include <typeinfo>
#include <enemy.h>
#include <addhealth.h>

extern game *myGame;

bullet::bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){

    //setting an image for the bullet object
    setPixmap(QPixmap(":/images/bullet.png"));

    //using a timer to work with the moveBullet() funtion and to move the bullet in the scene
    QTimer *myTimer = new QTimer();
    connect(myTimer,SIGNAL(timeout()),this,SLOT(moveBullet()));
    myTimer->start(50);
}

void bullet::moveBullet()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();

    //CChecking if bullet collides with any object
    for(int i = 0,n = colliding_items.size(); i<n; ++i){

        //colliding with enemy
        if(typeid(*(colliding_items[i])) == typeid(enemy)){

            //Increasing score
            myGame->myScore->increaseScore();

            //Remove those colliding objects from the scene so they will be deleted and it will save memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }//colliding with life
        else if(typeid(*(colliding_items[i])) == typeid(addHealth)){

            //Increasing health
            myGame->myHealth->increaseHealth();

            //deleting objects which collides with the bullet to free up and save memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }


    setPos(x(),y()-10);

    //deleting the bullets after they go out of the scene to free up and save memory
    if(pos().y()< 0){

        scene()->removeItem(this);
        delete this;
    }
}
