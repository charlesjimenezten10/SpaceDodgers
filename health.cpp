#include "health.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Health::Health()
{
    setHealth();
    QPixmap lifePixmap(":/images/life.png");
    QPixmap lives = lifePixmap.scaled(QSize(50,50));
    setPixmap(lives);
    qDebug() << "Your health is" << getHealth();
}

void Health::decreaseHealth()
{
    health--;
}

int Health::getHealth()
{
    return health;
}

void Health::setHealth()
{
    health = 5;
}
