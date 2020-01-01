#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <player.h>
#include <score.h>
#include <health.h>
#include <addhealth.h>
#include <QMediaPlayer>
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <enemy.h>

class game:public QGraphicsView{

public:

    game(QWidget *parent=0);

    QGraphicsScene *myScene;
    player *myPlayer;
    score *myScore;
    health *myHealth;
    QMediaPlayer *bgMusic;
    QTimer *myTimer;
    game *gameO;

public slots:

    void closeAll();

};

#endif // GAME_H
