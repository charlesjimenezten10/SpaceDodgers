
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "game.h"
#include "stats.h"
#include <QImage>
#include <QDebug>
#include <QPushButton>
#include <QLabel>


Game::Game()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 800);
    createScene();
    timer = new QTimer();
}

void Game::start()
{
    setupPlayer();
    setupStats();
    setupEnemySpawn();
    // health = new Health();
    // scene->addItem(health);
}

void Game::createScene()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 800);
    setBackgroundBrush(QImage(":/images/background.png"));
    setScene(scene);
}
void Game::setupPlayer() {
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable); // allows to focus on item as only one item at a scene can respond to q events
    player->setFocus();
    player->setPos(width() / 2, height() - (player -> pixmap().height()) - 10);
    scene->addItem(player);
}

void Game::setupEnemySpawn() {
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn())); // timer or player needs to inherit QObject
    timer->start(2000);
}

void Game::setupStats() {
    stats = new Stats();
    scene->addItem(stats);
}


void Game::restart() {
    scene->clear();
    start();
}

void Game::displayRestartOrQuitDialog() {
    scene->clear();

    dialog = new QDialog();
    dialog->setWindowTitle("Game Over");

    QVBoxLayout* layout = new QVBoxLayout();

    // Add label
    QLabel* label = new QLabel("Game Over! Do you want to restart or quit?");
    layout->addWidget(label);

    // HOPE THIS WORKS TO RESTART OR QUIT !!!!
    QPushButton* restartButton = new QPushButton("Restart");
    QPushButton* quitButton = new QPushButton("Quit");
    layout->addWidget(restartButton);
    layout->addWidget(quitButton);

    // signal and slots cuz apparently that's the only way
    connect(restartButton, &QPushButton::clicked, this, &Game::restart);
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);

    dialog->setLayout(layout);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();

}

