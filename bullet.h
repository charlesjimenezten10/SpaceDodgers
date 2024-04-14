#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem { // inherit
    Q_OBJECT // Q OBJECT MACRO IS NEEDED
public:
    Bullet();
public slots:
    void machineGun();
    void rocketLauncher();
};


#endif // BULLET_H
