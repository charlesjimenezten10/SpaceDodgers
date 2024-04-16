#include "playerTest.h"
#include <QTest>
#include <QDebug>
#include <QGraphicsScene>
#include "game.h"
#include "player.h"
#include <QGraphicsView>
#include <QKeyEvent>

// MovementTest::MovementTest() {
//     // Game game;
//     // toUpper();

// }

// void MovementTest::toUpper()
// {
//     QString str = "Hello";
//     QCOMPARE(str.toUpper(), QString("HELLO"));
// }

// To start before anything else equivalent to @BeforeAll in Java
void PlayerTest::initTestCase() {
    game = new Game();
}

// init() runs before each test equivalent to @BeforeEach in Java
void PlayerTest::init() {
    game->start();
}
void PlayerTest::testKeyPressLeft() {
    // Game game;
    // game->start();
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    game->player->keyPressEvent(&event);
    QCOMPARE(game->player->x(), 340);
}

void PlayerTest::testKeyPressRight() {
    // Game game;
    // game->start();
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    game->player->keyPressEvent(&event);
    QCOMPARE(game->player->x(), 460);
}

void PlayerTest::testKeyPressUp() {
    // Game game;
    // game->start();
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    game->player->keyPressEvent(&event);
    QCOMPARE(game->player->y(), 600);
}

void PlayerTest::testKeyPressDown() {
    // Game game;
    // game->start();
    // as the player starts at the bottom, by default it shouldn't be able to go down
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    game->player->keyPressEvent(&event);
    game->player->keyPressEvent(&event);
    QCOMPARE(game->player->y(), 640); //reason why is by default, 0,0 is the top left corner
}

void PlayerTest::testSpaceBar() {
    // Game game;
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
    game->player->keyPress(&event)
}

