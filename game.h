#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h" // Assuming you have a Player class
#include "stats.h"

class Game: public QGraphicsView {
public:
    Game();
    void start();
    QGraphicsScene* scene;
    Player* player;
    Stats* stats;
};

#endif // GAME_H
