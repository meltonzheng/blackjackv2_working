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

signals:
    void gameStarted();
    void indices1ARE(int a, int b);
    void indices2ARE(int c, int d);

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
    int index7;
    int index8;
    int index9;
    int index10;

    Player* player1;
    Player* ai;

    std::vector<QPixmap> card_images;
    std::vector<int> card_values;

    QPixmap* full_image;
    QPixmap card_image;
    QPushButton* firstDraw;

    void makeDeck();

    QVBoxLayout* full_layout;

};


#endif // GAMESIMPLEAI_H
