#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>
#include <gameover.h>

class health: public QGraphicsTextItem{

public:
    health(QGraphicsItem *parent=0);

    void decreaseHealth();
    void increaseHealth();
    int getHealth();

private:
    int Health;
    gameOver *over;
};

#endif // HEALTH_H
