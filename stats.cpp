#include "stats.h"
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
Stats::Stats(): QGraphicsTextItem() {
    setScore();
    setDefaultTextColor(Qt::white);
    setHealth();
    setPlainText("Score " + QString::number(score) + "\n" + "Health " + QString::number(health));
    setFont(QFont("Times", 15, QFont::Bold));
}

void Stats::increaseScore()
{
    score+=1000;
    setPlainText("Score " + QString::number(score) + "\n" + "Health " + QString::number(health));
}

void Stats::decreaseHealth()
{
    health--;
    setPlainText("Score " + QString::number(score) + "\n" + "Health " + QString::number(health));

}

int Stats::getScore()
{
    return score;
}

int Stats::getHealth()
{
    return health;
}

void Stats::setScore()
{
    score = 0;
}

void Stats::setHealth()
{
    health = 5;
}



