#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QGraphicsItem>
#include "enemy.h"
#include "game.h"
#include "stats.h"

extern Game* game;

Bullet::Bullet(): QObject(), QGraphicsPixmapItem()
{
    // this draws the bullets (thin bullets cuz u dont want it big lol)
    createBullet();
    signalAndSlotBulletMovement();
}

void Bullet::weaponBullet() {
    // check if bullet touches an enemy (IF U SEE THIS, IT TOOK ME AN HOUR TO FIND OUT THAT THERE WAS A METHOD ALREADY BUILT IN)
    QList<QGraphicsItem *> collisions = collidingItems();
    // qDebug() << collision;
    // qDebug() << "Bullet" << x();
    setPos(x(), y()-10);
    for(QGraphicsItem* collision: collisions) {
        if (typeid(*collision) == typeid(Enemy)) {
            game->stats->increaseScore();
            // qDebug("You hit an enemy");
            scene() -> removeItem(collision);
            scene() -> removeItem(this);
            delete collision;
            delete this;
            return;
        }
    }
    // for (int i = 0; i < collision.size(); i++) {
    //     // auto* ptr = collision[i]; // ask sir
    //     QGraphicsItem* ptr = collision[i];
    // }
    // for when it goes out of the scene
    if(pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);// scene member function
        delete this;
        // qDebug("Bullet deleted");
    }
}

void Bullet::createBullet() {
    QPixmap bulletPixmap(":/images/laser.png");
    QPixmap bullet = bulletPixmap.scaled(QSize(50,50));
    setPixmap(bullet);
}

void Bullet::signalAndSlotBulletMovement() {
    QTimer* timerMachineGun = new QTimer(this);
    connect(timerMachineGun, SIGNAL(timeout()), this, SLOT(weaponBullet()));
    timerMachineGun->start(20);
}
// Bullet::~Bullet() {
//     delete this;
// }
