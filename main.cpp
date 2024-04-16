#include <QApplication>
// #include <QGraphicsScene>
// #include "player.h" // replaced from <QGraphicsItem> -> myRect is derived from it
// #include <QGraphicsView>
// #include <QTimer>
// #include <QObject>
// #include <memory>
#include "game.h"


Game* game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->start();

    return a.exec();
}
