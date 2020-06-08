#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QPushButton>
#include <vector>

#include "cardwidget.h"
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QObject>
#include <QGraphicsView>
#include <QPainter>

#include <QRandomGenerator>



//set default players to 2 (including dealer)

const constexpr int PLAYERS = 2;
const constexpr int WIDTH = 500;
const constexpr int HEIGHT = 300;

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(int = PLAYERS);

public slots:
    void setNumberOfPlayers(int players);
    void startGame();
    void doFirstDraw();
    void doRDraw1();
    void doRDraw2();
    void doStand1();
    void doStand2();


signals:
    void gameStarted();
    void cardDrawn();
    void firstDrawn(bool b);
    void opFirstDrawn(bool b);
    void busted1(bool b);
    void busted2(bool b);
    void player1Standing(bool b);
    void player1Won(bool b);
    void player1Lost(bool b);
    void tie(bool b);

private:
    int num_of_cards;
    int round;

    std::vector<QPixmap> card_images;
    std::vector<int> card_values;
    std::vector<int> indices1;
    std::vector<int> indices2;

    void bust1();
    void bust2();

    QLabel* lost;
    QLabel* won;
    QLabel* tied;

    QRectF rect1;
    QRectF rect2;
    QRectF rect3;
    QRectF rect4;

    QPixmap* full_image;
    QPixmap card_image;

    void makeDeck();

    QPushButton* draw;
    QPushButton* stand1;
    QPushButton* rdraw1;
    QPushButton* stand2;
    QPushButton* rdraw2;

    QLabel* dealer;

    QTimer timer;
    int num_of_players;

    QHBoxLayout* player1_tray_layout;
    QHBoxLayout* player2_tray_layout;
    QVBoxLayout* full_layout;

    QGraphicsScene* scene1;
    QGraphicsScene* scene2;
    QGraphicsScene* scene3;
    QGraphicsScene* scene4;
    QGraphicsScene* scene5;
    QGraphicsScene* scene6;
        QGraphicsScene* scene7;
        QGraphicsScene* scene8;
        QGraphicsScene* scene9;
        QGraphicsScene* scene10;

    QGraphicsView* view1;
    QGraphicsView* view2;
    QGraphicsView* view3;
    QGraphicsView* view4;
    QGraphicsView* view5;
    QGraphicsView* view6;
       QGraphicsView* view7;
       QGraphicsView* view8;
       QGraphicsView* view9;
       QGraphicsView* view10;
};


#endif // GAME_H
