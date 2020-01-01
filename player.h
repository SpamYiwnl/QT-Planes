#ifndef RECTMOVEMENT_H
#define RECTMOVEMENT_H

#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>


class player: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    player(QGraphicsItem *parent=0);

    void keyPressEvent(QKeyEvent *myEvent);
public slots:

    void spawn();
    void spawnLife();
private:
    QMediaPlayer *bulletSound = new QMediaPlayer();

};

#endif // RECTMOVEMENT_H
