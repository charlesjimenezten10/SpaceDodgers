#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>


class Health: public QGraphicsPixmapItem{
public:
    Health();
    void decreaseHealth();
    int getHealth();
private:
    int health;
    void setHealth();
};

#endif // HEALTH_H
