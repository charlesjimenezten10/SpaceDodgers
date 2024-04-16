#ifndef PLAYERTEST_H
#define PLAYERTEST_H
#include <QObject>
#include <QTest>
#include "game.h"

class PlayerTest: public QObject
{
    Q_OBJECT
// public:
//     // MovementTest();
    Game* game;
//     // QGraphicsScene scene;
//     // QGraphicsView view;

private slots:
    void initTestCase();
    void init();
    void testKeyPressLeft();
    void testKeyPressRight();
    void testKeyPressUp();
    void testKeyPressDown();
    void testSpaceBar();
};
#endif // PLAYERTEST_H
