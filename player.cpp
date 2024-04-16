#include "player.h"
#include <QKeyEvent>
#include <QDebug>
#include "bullet.h"
#include <QGraphicsScene>
#include "enemy.h"



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
        // qDebug() << "Position is: " << x();
        if (x() > 50){
            setPos(x() - 30, y());
            break;
        }
        setPos(x(), y());
        break;
    case Qt::Key_Right:
        // qDebug() << "Position is: " << x();
        if (x() < scene() -> width() - 100){
            setPos(x() + 30, y());
            break;
        }
        setPos(x(), y());
        break;
    case Qt::Key_Up:
        if(y() >= (scene()->height()) / 2){
            setPos(x(), y() - 20);
            break;
        }
        setPos(x(), y());
        break;
    case Qt::Key_Down:
    {
        if(y() <= (scene()->height()) - pixmap().height() - 1){

            setPos(x(), y() + 20);
            break;
        }
        setPos(x(), y());
        break;
    }
    case Qt::Key_Space:
    {
        // bullet = new Bullet();
        Bullet* bullet= new Bullet();
        // std::unique_ptr<Bullet> bullet (new Bullet());
        bullet->setPos(x()-3, y()-20);
        // bulletTwo->setPos(x()+90, y());
        // scene()->addItem(bullet.get());
        scene()->addItem(bullet);
        break;
    }

    }

}
void Player::spawn() {
    qreal sceneHeight = scene() -> height();
    qreal sceneWidth = scene() -> width();
    Enemy* enemyOne = new Enemy(sceneHeight, sceneWidth);
    scene() -> addItem(enemyOne);
}
