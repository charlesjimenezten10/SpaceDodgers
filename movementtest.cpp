#include "movementtest.h"
#include <QTest>
// #include "player.h"
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsScene>

MovementTest::MovementTest() {
    // QGraphicsView view;
    toUpper();
}

void MovementTest::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}
