#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h" // Assuming you have a Player class
#include "stats.h"
#include "health.h"
#include "enemy.h"
#include <QTimer>
#include <QDialog>
#include <QColor>

class Game: public QGraphicsView {
public:
    Game();
    QTimer* timer;
    QGraphicsScene* scene;
    Player* player;
    Stats* stats;
    Health* health;
    Enemy* enemy;
    QDialog* dialog;
    void start();
    void createScene();
    void setupPlayer();
    void setupEnemySpawn();
    void setupStats();
    void restart();
    void displayRestartOrQuitDialog();
    void startScreen();
};

#endif // GAME_H
