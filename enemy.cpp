#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QRandomGenerator>
#include "player.h"
#include "game.h"

extern Game* game;

Enemy::Enemy(qreal sceneHeight, qreal sceneWidth): QObject(), QGraphicsRectItem() {
    int height = qRound(sceneHeight) - 100;
    int width = qRound(sceneWidth) - 100;
    // qDebug() << height;
    int random_width = rand() % width;
    int random_height = rand() % height / 5;
    setPos(random_width, random_height);
    setRect(0,0, 100, 100);
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer ->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+10);
    // qDebug() << "Ship pos: " << pos().y();
    // qDebug() << "Rect Height: " << scene()->height();
    QList<QGraphicsItem *> collision = collidingItems();
    for (int i = 0; i < collision.size(); i++) {
        // auto* ptr = collision[i]; // ask sir
        QGraphicsItem* ptr = collision[i];
        if (typeid(*ptr) == typeid(Player)) {
            qDebug() << "You got hit";
        }
    }
    if(pos().y() > scene()->height()) {
        game->stats->decreaseHealth();
        scene()->removeItem(this);// scene member function
        delete this;
        // qDebug() << "Enemy deleted";
    }
}
