#include <QApplication>
#include "game.h"
#include <QTest>
#include "playerTest.h"

Game* game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    // game = new Game();
    // game->show();
    // game->start();

    PlayerTest playerTest;
    QTest::qExec(&playerTest, argc,argv);
    return a.exec();
}
