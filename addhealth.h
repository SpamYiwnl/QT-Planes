#ifndef ADDHEALTH_H
#define ADDHEALTH_H

#include <QObject>
#include <QGraphicsPixmapItem>

class addHealth:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:

    addHealth(QGraphicsItem *parent = 0);

public slots:

    void move();
};

#endif // ADDHEALTH_H
