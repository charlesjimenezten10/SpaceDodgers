#ifndef PLAYER_H
#define PLAYER_H
// #include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointer>
#include "bullet.h"
#include "enemy.h"

class Player: public QObject, public QGraphicsPixmapItem{ // inherits the QObject and QGraphicsPixmapItem
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
    QPointer<Bullet> bullet;
    qreal sceneWidth;
    qreal sceneHeight;
    QPointer<Enemy> enemy;
    int xBullet;
    int yBullet;
public slots:
    void spawn();
};

#endif // PLAYER_H
