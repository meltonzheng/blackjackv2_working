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

    lost = new QLabel("Player 1 Busted! AI wins!");
lost->setVisible(false);

    won = new QLabel("AI Busted! Player 1 Wins!");
won->setVisible(false);

    full_layout->addWidget(lost);
    full_layout->addWidget(won);

    setLayout(full_layout);

//connections:
    QObject::connect(firstDraw, &QPushButton::clicked, this, &GameSimpleAI::firstDrawCoords);
    QObject::connect(this, &GameSimpleAI::indices1ARE, ai, &Player::doFirstDraw);
    QObject::connect(this, &GameSimpleAI::indices2ARE, player1, &Player::doFirstDraw);
    QObject::connect(player1, &Player::bust,lost,&QPushButton::setVisible);
    QObject::connect(ai, &Player::bust,won,&QPushButton::setVisible);


    //present draw and stand buttons and remove first draw button
    QObject::connect(firstDraw, &QPushButton::clicked, player1, &Player::on);
    QObject::connect(firstDraw, &QPushButton::clicked, ai, &Player::on);
    QObject::connect(player1, &Player::disable, firstDraw, &GameSimpleAI::setVisible);

    //activate draw and stand buttons
    QObject::connect(player1, &Player::drawPLZ, this, &GameSimpleAI::drawCoords1);
    QObject::connect(this, &GameSimpleAI::indexS1, player1, &Player::drawF);
    QObject::connect(ai, &Player::drawPLZ, this, &GameSimpleAI::drawCoords2);
    QObject::connect(this, &GameSimpleAI::indexS2, ai, &Player::drawF);
    QObject::connect(ai, &Player::sumIS, this, &GameSimpleAI::acceptValues1);
    QObject::connect(player1, &Player::sumIS, this, &GameSimpleAI::acceptValues2);


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
         index1 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
         indices.push_back(index1);
         index2 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        while(index2 == index1)
        {
            index2 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;

        }
        indices.push_back(index2);
        index3 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        while(index3 == index1 || index3 == index2)
        {
            index3 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;

        }
        indices.push_back(index3);
        index4 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        while(index4 == index1 || index4 == index2 || index4 == index3)
        {
            index4 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        }
        indices.push_back(index4);
        emit indices1ARE(index1, index2);
        emit indices2ARE(index3, index4);

    }
}

void GameSimpleAI::drawCoords1()
{
    index5 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    while( std::find(indices.begin(), indices.end(), index5) != indices.end() )
    {
        index5 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    }
    indices.push_back(index5);
    emit indexS1(index5);
}

void GameSimpleAI::drawCoords2()
{
    index6 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    while( std::find(indices.begin(), indices.end(), index6) != indices.end() )
    {
        index6 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    }
    indices.push_back(index6);
    emit indexS2(index6);
}

void GameSimpleAI::acceptValues1(int val)
{
    val1 = val;
}
void GameSimpleAI::acceptValues2(int val)
{
    val2 = val;
}
