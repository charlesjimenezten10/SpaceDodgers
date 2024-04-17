#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include <QGraphicsTextItem>

class Enemy: public QObject, public QGraphicsPixmapItem { // inherit
    Q_OBJECT // Q OBJECT MACRO IS NEEDED
public:
    Enemy(qreal sceneHeight, qreal sceneWidth);
    // ~Enemy();
public slots:
    void move();
private:
    void signalSlotMove();
    void enemyPosition(qreal sceneWidth, qreal sceneHeight);
    void createEnemy();
};

#endif // ENEMY_H
