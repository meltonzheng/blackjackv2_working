#include "GameComplexAI.h"

#include <iostream>

GameComplexAI::GameComplexAI()
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
    QObject::connect(firstDraw, &QPushButton::clicked, this, &GameComplexAI::firstDrawCoords);
    QObject::connect(this, &GameComplexAI::indices1ARE, ai, &Player::doFirstDraw);
    QObject::connect(this, &GameComplexAI::indices2ARE, player1, &Player::doFirstDraw);


    //present draw and stand buttons and remove first draw button
    QObject::connect(firstDraw, &QPushButton::clicked, player1, &Player::on);
    QObject::connect(firstDraw, &QPushButton::clicked, ai, &Player::on);
    QObject::connect(player1, &Player::disable, firstDraw, &GameComplexAI::setVisible);

    //activate draw and stand buttons
    QObject::connect(player1, &Player::drawPLZ, this, &GameComplexAI::drawCoords1);
    QObject::connect(this, &GameComplexAI::indexS1, player1, &Player::drawF);
    QObject::connect(ai, &Player::drawPLZ, this, &GameComplexAI::drawCoords2);
    QObject::connect(this, &GameComplexAI::indexS2, ai, &Player::drawF);
    QObject::connect(ai, &Player::sumIS, this, &GameComplexAI::acceptValues1);
    QObject::connect(player1, &Player::sumIS, this, &GameComplexAI::acceptValues2);

    //end screen
    QObject::connect(this, &GameComplexAI::calculate, this, &GameComplexAI::finish);
    QObject::connect(this, &GameComplexAI::AIWon, lost, &GameComplexAI::setVisible);
    QObject::connect(this, &GameComplexAI::AIWon, won, &GameComplexAI::setHidden);
    QObject::connect(this, &GameComplexAI::playerWon, won, &GameComplexAI::setVisible);
    QObject::connect(this, &GameComplexAI::playerWon, lost, &GameComplexAI::setHidden);
    QObject::connect(this, &GameComplexAI::AIWon, play_again, &GameComplexAI::setVisible);
    QObject::connect(this, &GameComplexAI::playerWon, play_again, &GameComplexAI::setVisible);
    QObject::connect(player1, &Player::bust,lost,&QPushButton::setVisible);
    QObject::connect(player1, &Player::bust,won,&QPushButton::setHidden);
    QObject::connect(ai, &Player::bust,won,&QPushButton::setVisible);
    QObject::connect(ai, &Player::bust,lost,&QPushButton::setHidden);
    QObject::connect(player1, &Player::bust,play_again, &GameComplexAI::setVisible);
    QObject::connect(ai, &Player::bust,play_again, &GameComplexAI::setVisible);


    //play again?
    QObject::connect(play_again,&QPushButton::clicked,play_again,&QPushButton::setVisible);
    QObject::connect(play_again, &QPushButton::clicked, this, &GameComplexAI::reset);
    QObject::connect(play_again,&QPushButton::clicked,lost,&QPushButton::setVisible);
    QObject::connect(play_again,&QPushButton::clicked,won,&QPushButton::setVisible);

    //Let AI make moves
    QObject::connect(firstDraw, &QPushButton::clicked, ai, &Player::play);
    QObject::connect(ai, &Player::drawPLZ, ai, &Player::play);



}
void GameComplexAI::makeDeck()
{

}
void GameComplexAI::setNumberOfPlayers(int nplayers)
{
    this->num_of_players = nplayers;
}
void GameComplexAI::startGame()
{

}

void GameComplexAI::firstDrawCoords()
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

void GameComplexAI::drawCoords1()
{
    index5 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    while( std::find(indices.begin(), indices.end(), index5) != indices.end() )
    {
        index5 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    }
    indices.push_back(index5);
    emit indexS1(index5);
}

void GameComplexAI::drawCoords2()
{
    index6 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    while( std::find(indices.begin(), indices.end(), index6) != indices.end() )
    {
        index6 = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
    }
    indices.push_back(index6);
    emit indexS2(index6);
}

void GameComplexAI::acceptValues1(int val)
{
    val1 = val;
    if(val2 != 0)
    {
        emit calculate();
    }
}
void GameComplexAI::acceptValues2(int val)
{
    val2 = val;
    if(val1 != 0)
    {
        emit calculate();
    }
}

void GameComplexAI::finish()
{
    if(val1 > val2)
    {
        lost->setText("AI Won!");
        emit AIWon(true);
    }
    else
    {
        won->setText("Player Won!");
        emit playerWon(true);
    }
}

void GameComplexAI::reset()
{
    //use full deck
    num_of_cards = 51;

    //clear out the pixmaps, indices
    ai->clearStuff();
    player1->clearStuff();

    //restore the first button
    firstDraw->setVisible(true);

}

