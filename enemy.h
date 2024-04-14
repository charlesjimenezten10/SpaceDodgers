#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem { // inherit
    Q_OBJECT // Q OBJECT MACRO IS NEEDED
public:
    Enemy(qreal sceneHeight, qreal sceneWidth);
public slots:
    void move();
};

#endif // ENEMY_H
