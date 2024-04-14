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










// std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
// std::unique_ptr<Player> player(new Player());
// player->setRect(0, 0,100,100);
// player->setFlag(QGraphicsItem::ItemIsFocusable); // allows to focus on item as only one item at a scene can respond to q events
// player->setFocus();


// scene->addItem(player.get());
// std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));
// view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // disables horizontal scrollbar
// view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // disables vertical scrollbar
// view->show();
// view->setFixedSize(800, 800);
// scene->setSceneRect(0,0, 800, 800);
// player->setPos(view-> width() / 2, view -> height() - (player -> rect().height()) - 10);
// QGraphicsScene* scene = new QGraphicsScene();
// Player* player = new Player();
// QGraphicsView* view = new QGraphicsView(scene);
// view->setSceneRect(scene->sceneRect());
// Enemy * enemy = new Enemy();
// QTimer* timer = new QTimer();
// QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
// timer->start(5000);
