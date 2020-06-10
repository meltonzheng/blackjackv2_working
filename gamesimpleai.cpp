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

    QPushButton* play_again = new QPushButton("Play Again");
    full_layout->addWidget(play_again);
    play_again->setVisible(false);

    setLayout(full_layout);

//connections:
    QObject::connect(firstDraw, &QPushButton::clicked, this, &GameSimpleAI::firstDrawCoords);
    QObject::connect(this, &GameSimpleAI::indices1ARE, ai, &Player::doFirstDraw);
    QObject::connect(this, &GameSimpleAI::indices2ARE, player1, &Player::doFirstDraw);


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
    QObject::connect(ai, &Player::done, this, &GameSimpleAI::standBy1);
    QObject::connect(player1, &Player::done, this, &GameSimpleAI::standBy2);

    //end screen
    QObject::connect(this, &GameSimpleAI::calculate, this, &GameSimpleAI::finish);
    QObject::connect(this, &GameSimpleAI::AIWon, lost, &GameSimpleAI::setVisible);
        //if AI won, increase his money
    QObject::connect(this, &GameSimpleAI::AIWon, ai, &Player::increase);

    QObject::connect(this, &GameSimpleAI::AIWon, won, &GameSimpleAI::setHidden);
    QObject::connect(this, &GameSimpleAI::playerWon, won, &GameSimpleAI::setVisible);
       //if player won, increase his money
    QObject::connect(this, &GameSimpleAI::playerWon, player1, &Player::increase);

    QObject::connect(this, &GameSimpleAI::playerWon, lost, &GameSimpleAI::setHidden);
    QObject::connect(this, &GameSimpleAI::AIWon, play_again, &GameSimpleAI::setVisible);
    QObject::connect(this, &GameSimpleAI::playerWon, play_again, &GameSimpleAI::setVisible);
    QObject::connect(player1, &Player::bust,lost,&QPushButton::setVisible);
    //if player busted, increase ai money
    QObject::connect(player1, &Player::bust, ai, &Player::increase);

    QObject::connect(player1, &Player::bust,won,&QPushButton::setHidden);
    QObject::connect(ai, &Player::bust,won,&QPushButton::setVisible);
    //if ai busted, increase player money
    QObject::connect(ai, &Player::bust, player1, &Player::increase);

    QObject::connect(ai, &Player::bust,lost,&QPushButton::setHidden);
    QObject::connect(player1, &Player::bust,play_again, &GameSimpleAI::setVisible);
    QObject::connect(ai, &Player::bust,play_again, &GameSimpleAI::setVisible);

    //if tied
    QObject::connect(this, &GameSimpleAI::tied, won, &GameSimpleAI::setVisible);
    QObject::connect(this, &GameSimpleAI::tied, lost, &GameSimpleAI::setHidden);
    QObject::connect(this, &GameSimpleAI::tied, ai, &Player::equalize);
    QObject::connect(this, &GameSimpleAI::tied, player1, &Player::equalize);

    //play again?
    QObject::connect(play_again,&QPushButton::clicked,play_again,&QPushButton::setVisible);
    QObject::connect(play_again, &QPushButton::clicked, this, &GameSimpleAI::reset);
    QObject::connect(play_again,&QPushButton::clicked,lost,&QPushButton::setVisible);
    QObject::connect(play_again,&QPushButton::clicked,won,&QPushButton::setVisible);

    //Let AI make moves
    QObject::connect(firstDraw, &QPushButton::clicked, ai, &Player::setup);
    QObject::connect(player1, &Player::enable, ai, &Player::play);
    QObject::connect(ai, &Player::drawPLZ, ai, &Player::play);



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

void GameSimpleAI::finish()
{
    if(val1 > val2)
    {
        lost->setText("AI Won!");
        emit AIWon(true);
    }
    else if (val1 < val2)
    {
        won->setText("Player Won!");
        emit playerWon(true);
    }
    else
    {
        won->setText("Players Tied!");
        emit tied(true);
    }
}

void GameSimpleAI::reset()
{
    //use full deck
    num_of_cards = 51;

    //clear out the pixmaps, indices
    ai->clearStuff();
    player1->clearStuff();

    //restore the first button
    firstDraw->setVisible(true);
    b1 = false;
    b2 = false;

    lost->setText("Player 1 Busted! AI wins!");
    won->setText("AI Busted! Player 1 Wins!");

}
void GameSimpleAI::standBy1(bool b)
{
    b1 = b;
    if(b1 && b2)
    {
        emit calculate();
    }
}
void GameSimpleAI::standBy2(bool b)
{
    b2 = b;
    if(b1 && b2)
    {
        emit calculate();
    }
}

