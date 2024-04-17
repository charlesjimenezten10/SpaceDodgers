#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QRandomGenerator>
#include "player.h"
#include "game.h"
#include "stats.h"

extern Game* game;

Enemy::Enemy(qreal sceneHeight, qreal sceneWidth): QObject(), QGraphicsPixmapItem() {
    enemyPosition(sceneWidth, sceneHeight);
    createEnemy();
    signalSlotMove();
}

void Enemy::enemyPosition(qreal sceneWidth, qreal sceneHeight){
    int height = qRound(sceneHeight) - 100;
    int width = qRound(sceneWidth) - 100;
    // qDebug() << "Height: " height << "\nWidth: " << width ;
    int random_width = rand() % width;
    int random_height = rand() % height / 5;
    setPos(random_width, random_height);
}

void Enemy::move()
{
    setPos(x(), y()+15);
    // qDebug() << "Ship pos: " << pos().y();
    // qDebug() << "Rect Height: " << scene()->height();
    int healthNum = game->stats->getHealth();
    QList<QGraphicsItem *> collisions = collidingItems();

    for(QGraphicsItem* collision: collisions) {
        if (typeid(*collision) == typeid(Player)) {
            // qDebug("You got hit");
            game->hitByEnemy = true;
            game->displayRestartOrQuitDialog();
            return;
        }
    }
    if(pos().y() > scene()->height()) {
        game->stats->decreaseHealth();
        scene()->removeItem(this);// scene member function
        delete this;
        // qDebug("Enemy deleted");
    }
    if (healthNum == 0) {
        game->displayRestartOrQuitDialog();
    }
}

void Enemy::signalSlotMove(){
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer ->start(50);
}

void Enemy::createEnemy() {
    qDebug() << "enemy created";
    QString enemies[2] = {":/images/spaceship.png", ":/images/enemy.png"}; // images of the two enemies to be later on used to randomly select one (code below)
    // qDebug() << enemies[1];
    int getArrayLength = sizeof(enemies) / sizeof(enemies[0]);
    int randomEnemyIndex = rand() % getArrayLength;
    QString randomEnemy = enemies[randomEnemyIndex];
    QPixmap enemyPixmap(randomEnemy);
    QPixmap enemy = enemyPixmap.scaled(QSize(100,100));
    // qDebug() << "Enemy spawned" << enemy;
    setTransformOriginPoint(50,50); // rotate from the center of the image
    setRotation(180);
    setPixmap(enemy);
    // return enemy;
}


