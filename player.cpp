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
    //setting an image to the player and playing the sound of the bullet/ shooting sound
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    setPixmap(QPixmap(":/images/player.png"));
}

void player::keyPressEvent(QKeyEvent *myEvent) //checking which key is pressed by the player
{
    //checking if there is space to move and moving left if the left key is pressed
    if(myEvent->key() == Qt::Key_Left){
        if(pos().x()>0){
             setPos(x()-10,y());
             qDebug("test");
        }
    }
    //checking if there is space to move and moving right if the right key is pressed
    else if(myEvent->key() == Qt::Key_Right){
        if(pos().x()+ 256< 1200){
            setPos(x()+10,y());
        }
    }
    //creating and adding a bullet object if the spacebar is pressed
    else if(myEvent->key() == Qt::Key_Space){

        //Creating a bullet
        bullet *myBullet = new bullet();
        myBullet->setPos(x(),y());
        scene()->addItem(myBullet);

        //playing shooting sound
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }else if (bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }

    }
}

void player::spawn()
{
    //adding enemies
    enemy *myEnemy = new enemy();
    scene()->addItem(myEnemy);

}

void player::spawnLife()
{
    //adding life
    addHealth *newLife = new addHealth();
    scene()->addItem(newLife);

}

