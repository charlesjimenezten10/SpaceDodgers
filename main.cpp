#include <QApplication>
#include "game.h"
#include <QTest>
#include "gameTest.h"

Game* game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->start();

    // GameTest gameTest;
    // QTest::qExec(&gameTest, argc,argv);
    return a.exec();
}
