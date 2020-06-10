#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTime>
#include <QCoreApplication>
#include <QSpinBox>

#include <iostream>

class Player : public QWidget
{
    Q_OBJECT
public:
    Player(std::string pname);
    void givePixmap(QPixmap& pimage, int round);
    void giveIndex(int pindex);
    void clearStuff();

public slots:
    void on();
    void drawF(int x);
    void standF();
    void doFirstDraw(int x, int y);
    void emitDRAW();
    void continueGame();
    void increase();
    void equalize();
//simple AI slot
    void play();
    void setup();


signals:
    void enable(bool b);
    void disable(bool b);
    void drawPLZ();
    void removal(bool b);
    void sumIS(int asdf);
    void bust(bool b);
    void done(bool b);
    void enableBetting(bool b);
//simple AI signals
    void hit();
    void standSig();

private:
    int w;
    int h;
    int round;
    std::string name;
    bool specialRoundBoolean;
    int money;
    int theBet;
    bool waitforbets;

    std::vector<int> indices;
    std::vector<int> card_values;

    QSpinBox* betMoney;
    QLabel* moneyLabel;
    QPixmap* full_image;
    QLabel* playerLabel;
    QPushButton* rdraw;
    QPushButton* stand;
    QPushButton* bet;
    QGraphicsScene* scene1;
    QGraphicsScene* scene2;
    QGraphicsScene* scene3;
    QGraphicsScene* scene4;
    QGraphicsScene* scene5;
    QGraphicsView* view1;
    QGraphicsView* view2;
    QGraphicsView* view3;
    QGraphicsView* view4;
    QGraphicsView* view5;
    QHBoxLayout* player_tray_layout;
};

#endif // PLAYER_H
