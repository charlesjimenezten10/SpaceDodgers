#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QGraphicsItem>
#include "enemy.h"
#include "game.h">

extern Game* game;

Bullet::Bullet(): QObject(), QGraphicsRectItem()
{
    // this draws the bullets (thin bullets cuz u dont want it big lol)
    setRect(0,0, 10, 50);
    QTimer* timerMachineGun = new QTimer(this);
    connect(timerMachineGun, SIGNAL(timeout()), this, SLOT(machineGun()));
    timerMachineGun->start(50);

    // QTimer * timerRocketLauncher = new QTimer(this);

    // connect(timerRocketLauncher, SIGNAL(timeout()), this, SLOT(rocketLauncher()));
    // timerRocketLauncher->start(1000);
    // qDebug() << "Rocket launcher timer started.";
}

void Bullet::machineGun() {
    // check if bullet touches an enemy
    QList<QGraphicsItem *> collision = collidingItems();
    // qDebug() << collision;

    setPos(x(), y()-10);
    for (int i = 0; i < collision.size(); i++) {
        // auto* ptr = collision[i]; // ask sir
        QGraphicsItem* ptr = collision[i];
        if (typeid(*ptr) == typeid(Enemy)) {
            game->stats->increaseScore();
            qDebug() << "ENEMY HIT";
            scene() -> removeItem(collision[i]);
            scene() -> removeItem(this);
            delete collision[i];
            delete this;
            return;
        }
    }
    if(pos().y() + rect().height() < 0) {
        scene()->removeItem(this);// scene member function
        delete this;
        qDebug() << "Bullet deleted";
    }
}

void Bullet::rocketLauncher() {
    setPos(x(), y()-10);
    // qDebug() << "Rocket launcher bullet moved.";
}
