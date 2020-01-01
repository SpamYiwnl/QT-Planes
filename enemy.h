#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>


class enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
   enemy(QGraphicsItem *parent =0);
   QTimer *myTimer;

public slots:

   void moveEnemy();

};


#endif // ENEMY_H
