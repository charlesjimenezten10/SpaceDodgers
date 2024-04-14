#include <QApplication>
#include <QGraphicsScene>
#include "player.h" // replaced from <QGraphicsItem> -> myRect is derived from it
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
// #include <memory>
#include "game.h"
#include "stats.h"



Game::Game()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 800);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 800);
    setScene(scene);
}

void Game::start()
{
    player = new Player();
    player->setRect(0, 0,100,100);
    player->setFlag(QGraphicsItem::ItemIsFocusable); // allows to focus on item as only one item at a scene can respond to q events
    player->setFocus();
    player->setPos(width() / 2, height() - (player -> rect().height()) - 10);
    scene->addItem(player);
    stats = new Stats();
    scene->addItem(stats);
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn())); // timer or player needs to inherit QObject
    timer->start(2000);
}












// QTimer* timer = new QTimer();
// int initialInterval = 2000; // Initial interval: 2000 milliseconds
// timer->start(initialInterval);

// // Create a QTimer to periodically adjust the timer interval
// QTimer intervalAdjustmentTimer;
// int decreaseDelay = 5000; // Decrease the interval after 5 seconds
// intervalAdjustmentTimer.singleShot(decreaseDelay, [=]() {
//     timer->setInterval(1000); // Decrease to 1000 milliseconds after 5 seconds
// });
// QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
