#ifndef PLAYER_H
#define PLAYER_H
// #include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>


class Player: public QObject, public QGraphicsPixmapItem{ // inherits the QObject and QGraphicsPixmapItem
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // PLAYER_H
