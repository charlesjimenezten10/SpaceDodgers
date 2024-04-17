#include "player.h"
#include <QKeyEvent>
#include <QDebug>
#include "bullet.h"
#include <QGraphicsScene>
#include "enemy.h"
#include <QPointer>


QPointer<Bullet> bullet;

Player::Player(): QGraphicsPixmapItem(){
    QPixmap shipPixmap(":/images/enemy_two.png");
    QPixmap playerShip = shipPixmap.scaled(QSize(150,150));
    setPixmap(playerShip);
    setTransformOriginPoint(50,50); // rotate from the center of the image
    setRotation(180);

}

void Player::keyPressEvent(QKeyEvent* event)
{/*
    qDebug() << scene() -> height();
    qDebug() << "Y position is: " <<  y();
    qDebug() << "Height is: " << rect().height();*/
    switch(event->key()) {
    case Qt::Key_Left:
        if (x() > 50){
            setPos(x() - 30, y());
            // qDebug() << x();
        }
        break;
    case Qt::Key_Right:
        if (x() < scene() -> width() - 100){
            setPos(x() + 30, y());
        }
        break;
    case Qt::Key_Up:
        if(y() >= (scene()->height()) / 2){
            setPos(x(), y() - 20);
        }
        // setPos(x(), y());
        // break;
        break;
    case Qt::Key_Down:
        if(y() <= (scene()->height()) - pixmap().height() - 1){
            setPos(x(), y() + 20);
        }
        // setPos(x(), y());
        break;
    case Qt::Key_Space:
        bullet = new Bullet;
        // FOR THE UNIT TEST PLS DONT JUDGE
        xBullet = x()-3;
        yBullet = y()-20;
        bullet->setPos(xBullet, yBullet);
        scene()->addItem(bullet);
        break;
    }

}
void Player::spawn() {
    sceneHeight = scene() -> height();
    sceneWidth = scene() -> width();
    enemy = new Enemy(sceneHeight, sceneWidth);
    if(enemy) {
        scene() -> addItem(enemy);
    }
}
