#include "gamesimpleai.h"

#include <iostream>

GameSimpleAI::GameSimpleAI()
    : QWidget(nullptr)
{
    int w = 80;
    int h = 100;

    num_of_cards = 51;

//player 1 :
    ai = new Player("The Simple AI");

//player 2 :
    player1 = new Player("Player 1");

//full layout :
    full_layout = new QVBoxLayout();
    full_layout->addWidget(ai);
    full_layout->addWidget(player1);

    firstDraw = new QPushButton("First Draw");

    full_layout->addWidget(firstDraw);

    setLayout(full_layout);

//connections:
    QObject::connect(firstDraw, &QPushButton::clicked, this, &GameSimpleAI::firstDrawCoords);
    QObject::connect(this, &GameSimpleAI::indices1ARE, ai, &Player::doFirstDraw);
    QObject::connect(this, &GameSimpleAI::indices2ARE, player1, &Player::doFirstDraw);

    //turn on draw and stand buttons
    QObject::connect(firstDraw, &QPushButton::clicked, player1, &Player::on);
    QObject::connect(firstDraw, &QPushButton::clicked, ai, &Player::on);
    QObject::connect(player1, &Player::disable, firstDraw, &GameSimpleAI::setVisible);

    //Let AI make moves
    QObject::connect(firstDraw, &QPushButton::clicked, ai, &Player::play);


}
void GameSimpleAI::makeDeck()
{

}
void GameSimpleAI::setNumberOfPlayers(int nplayers)
{
    this->num_of_players = nplayers;
}
void GameSimpleAI::startGame()
{

}

void GameSimpleAI::firstDrawCoords()
{
    if( num_of_cards == 51)
    {
        int index1 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        int index2 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        while(index2 == index1)
        {
            index2 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        }
        int index3 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        while(index3 == index1 || index3 == index2)
        {
            index3 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        }
        int index4 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        while(index4 == index1 || index4 == index2 || index4 == index3)
        {
            index4 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        }


        emit indices1ARE(index1, index2);
        emit indices2ARE(index3, index4);
    }
}
