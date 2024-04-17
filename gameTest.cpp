#include "gameTest.h"
#include <QTest>
#include <QDebug>
#include <QGraphicsScene>
#include "game.h"
#include "player.h"
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>


// To start before anything else equivalent to @BeforeAll in Java
void GameTest::initTestCase() {
    game = new Game();
}

// init() runs before each test equivalent to @BeforeEach in Java
void GameTest::init() {
    game->start();
}
void GameTest::testKeyPressLeft() {
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    QCOMPARE(game->player->x(), 370);
}

void GameTest::testKeyPressRight() {
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    QCOMPARE(game->player->x(), 430);
}

void GameTest::testKeyPressUp() {
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    game->player->keyPressEvent(&event);
    QCOMPARE(game->player->y(), 600);
}

void GameTest::testKeyPressDown() {
    // as the player starts at the bottom, by default it shouldn't be able to go down
    QKeyEvent eventUp(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    QKeyEvent eventDown(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
    game->player->keyPressEvent(&eventUp);
    game->player->keyPressEvent(&eventUp);
    game->player->keyPressEvent(&eventDown);
    QCOMPARE(game->player->y(), 620);
}

void GameTest::testSpaceBar() {
    // Game game;
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    QVERIFY2(game->player->bullet, "Bullet was not created");
}

void GameTest::testEnemySpawn() {
    // Game game;
    QTRY_VERIFY2_WITH_TIMEOUT(game->player->enemy, "Enemy was not created", 2000);
}

void GameTest::testBulletIsDeletedScene() {
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
    game->disconnect(game->timer, SIGNAL(timeout()), game->player, SLOT(spawn()));
    game->player->xBullet = 10;
    game->player->yBullet = 1;
    game->player->keyPressEvent(&event);
    QVERIFY2(game->player->bullet->y() < 0, "Test");
    // QTRY_VERIFY2_WITH_TIMEOUT(game->player->bullet == nullptr, "Bullet was not created", 1000);
}

void GameTest::testEnemyBulletDeleted() {
    // QKeyEvent event(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
    // // game->player->enemySpawn = true;
    // QTimer* timer = new QTimer;
    // QTimer::singleShot(2000, game->player, game->player->keyPressEvent(&event));
}



