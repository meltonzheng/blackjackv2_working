#ifndef GAMESIMPLEAI_H
#define GAMESIMPLEAI_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QPushButton>
#include <vector>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QObject>
#include <QGraphicsView>
#include <QPainter>
#include <QRandomGenerator>
#include <algorithm>


#include "player.h"

class GameSimpleAI : public QWidget
{
    Q_OBJECT
public:
    explicit GameSimpleAI();

public slots:
    void setNumberOfPlayers(int players);
    void startGame();
    void firstDrawCoords();
    void drawCoords1();
    void drawCoords2();
    void acceptValues1(int val);
    void acceptValues2(int val);
    void finish();
    void reset();
    void standBy1(bool b);
    void standBy2(bool b);

signals:
    void gameStarted();
    void indices1ARE(int a, int b);
    void indices2ARE(int c, int d);
    void indexS1(int x);
    void indexS2(int x);
    void calculate();
    void playerWon(bool b);
    void AIWon(bool b);
    void tied(bool b);



private:
    int num_of_players;
    int num_of_cards;
    int round;
    int index1;
    int index2;
    int index3;
    int index4;
    int index5;
    int index6;
    int val1=0;
    int val2=0;
    bool b1 = false;
    bool b2 = false;

    Player* player1;
    Player* ai;

    std::vector<int> indices;
    std::vector<QPixmap> card_images;
    std::vector<int> card_values;

    QPixmap* full_image;
    QPixmap card_image;
    QPushButton* firstDraw;
    QLabel* won;
    QLabel* lost;

    void makeDeck();

    QVBoxLayout* full_layout;

};


#endif // GAMESIMPLEAI_H
