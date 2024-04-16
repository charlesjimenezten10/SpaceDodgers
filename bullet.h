#ifndef BULLET_H
#define BULLET_H
// #include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "stats.h"

class Bullet: public QObject, public QGraphicsPixmapItem { // inherit
    Q_OBJECT // Q OBJECT MACRO IS NEEDED
public:
    Bullet();
    // ~Bullet();
    Stats* stats;
public slots:
    void machineGun();
};


#endif // BULLET_H
