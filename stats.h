#ifndef STATS_H
#define STATS_H

#include <QGraphicsTextItem>
class Stats: public QGraphicsTextItem{
public:
    Stats();
    void increaseScore();
    void decreaseHealth();
    int getScore();
    int getHealth();
    int score;
    int health;
    void setScore();
    void setHealth(int x);
private:
};

#endif // STATS_H
