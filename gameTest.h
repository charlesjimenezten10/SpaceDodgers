#ifndef GAMETEST_H
#define GAMETEST_H
#include <QObject>
#include <QTest>
#include "game.h"

class GameTest: public QObject
{
    Q_OBJECT
public:
    Game* game;
private slots:
    void testBulletIsDeletedScene();
    void initTestCase();
    void init();
    void testKeyPressLeft();
    void testKeyPressRight();
    void testKeyPressUp();
    void testKeyPressDown();
    void testSpaceBar();
    void testEnemySpawn();
    void testEnemyBulletDeleted();
};
#endif // GAMETEST_H
