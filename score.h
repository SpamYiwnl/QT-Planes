#ifndef HEALTHANDSCORE_H
#define HEALTHANDSCORE_H

#include <QGraphicsTextItem>

class score: public QGraphicsTextItem{

public:
    score(QGraphicsItem *parent=0);

    void increaseScore();
    int getScore();

private:
    int Score;

};

#endif // HEALTHANDSCORE_H
