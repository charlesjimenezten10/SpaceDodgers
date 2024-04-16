#ifndef MOVEMENTTEST_H
#define MOVEMENTTEST_H
#include <QObject>
#include <QDebug>
#include <QTest>
#include <QGraphicsScene>
#include <QGraphicsView>

class MovementTest: public QObject
{
    Q_OBJECT
public:
    MovementTest();
    QGraphicsScene scene;
    QGraphicsView view;
private slots:
    // void testKeyPress();
    void toUpper();
};

QTEST_MAIN(MovementTest)
#include "movementtest.moc"
#endif // MOVEMENTTEST_H
