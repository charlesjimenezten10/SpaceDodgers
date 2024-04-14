#include "player.h"
#include <QKeyEvent>
#include <QDebug>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "enemy.h"

void Player::keyPressEvent(QKeyEvent *event)
{/*
    qDebug() << scene() -> height();
    qDebug() << "Y position is: " <<  y();
    qDebug() << "Height is: " << rect().height();*/
    switch(event->key()) {
    case Qt::Key_Left:
        // qDebug() << "Position is: " << x();
        if (x() > 0){
            setPos(x() - 10, y());
            break;
        }
        setPos(x(), y());
        break;
    case Qt::Key_Right:
        // qDebug() << "Position is: " << x();
        if (x() < scene() -> width() - rect().width()){
            setPos(x() + 10, y());
            break;
        }
        setPos(x(), y());
        break;
    case Qt::Key_Up:
        if(y() >= (scene()->height()) / 2){
            setPos(x(), y() - 10);
            break;
        }
        setPos(x(), y());
        break;
    case Qt::Key_Down:
    {
        if(y() <= (scene()->height()) - rect().height() - 1){

            setPos(x(), y() + 10);
            break;
        }
        setPos(x(), y());
        break;
    }
    case Qt::Key_Space:
    {
        Bullet* machineGun = new Bullet();
        machineGun->setPos(x() + 45, y());
        scene()->addItem(machineGun);
        break;
    }
    case Qt::Key_R:
    {
        Bullet* rocketLauncher = new Bullet();
        rocketLauncher->setPos(x() + 10, y());
        scene()->addItem(rocketLauncher);
        break;
    }

    }

}
void Player::spawn() {
    qreal sceneHeight = scene() -> height();
    qreal sceneWidth = scene() -> width();
    Enemy* enemy = new Enemy(sceneHeight, sceneWidth);
    scene() -> addItem(enemy);
}
