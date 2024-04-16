#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include <QObject>

class TestPlayer : public QObject {
    Q_OBJECT

private slots:
    void testPlayerMovement();
    void testPlayerShooting();
};

#endif // TESTPLAYER_H
