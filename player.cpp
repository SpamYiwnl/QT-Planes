#include "player.h"
#include <bullet.h>
#include <enemy.h>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <addhealth.h>
#include <QDebug>

player::player(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    //when the player is created in the scene setting  its image and keeping a private QMediaPlayer to output the sounds of the bullet
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    setPixmap(QPixmap(":/images/player.png"));
}

void player::keyPressEvent(QKeyEvent *myEvent) //Checking what key was pressed by the user
{
    //If the left key was clicked check if its possible for the user to move left and if possible move the user left
    if(myEvent->key() == Qt::Key_Left){
        if(pos().x()>0){
             setPos(x()-10,y());
             qDebug("test");
        }
    }
    //If the right key was clicked check if its possible for the user to move right and if possible move the user right
    else if(myEvent->key() == Qt::Key_Right){
        if(pos().x()+ 258 < 1200){
            setPos(x()+10,y());
        }
    }
    //If the spacebar was clicked creating a bullet object and add it to the scene
    else if(myEvent->key() == Qt::Key_Space){

        //Creating a bullet
        bullet *myBullet = new bullet();
        myBullet->setPos(x(),y());
        scene()->addItem(myBullet);

        //Playing bullet sounds
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }else if (bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }

    }
}

void player::spawn()
{
    //add enemies to the scene
    enemy *myEnemy = new enemy();
    scene()->addItem(myEnemy);

}

void player::spawnLife()
{
    //add life to the scene
    addHealth *newLife = new addHealth();
    scene()->addItem(newLife);

}

