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
#include <QPointer>

class Game: public QGraphicsView {
public:
    Game();
    ~Game();
    bool hitByEnemy;
    QPointer<QTimer> timer;
    QPointer<QGraphicsScene> scene;
    QPointer<Player> player;
    QPointer<Stats>stats;
    QPointer<Health> health;
    QPointer<Enemy> enemy;
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
