#include "game.h"

#include <iostream>

Game::Game(int nplayers)
    : QWidget(nullptr)
  , dealer(new QLabel)
  , num_of_players(nplayers)
{
//    QObject::connect(this,
//                         &Game::gameStarted,
//                         this,
//                         &Game::makeDeck);

//    std::cout << "works";
 //   scene->addItem(card);

    rect1 = QRectF(170,7, 73,100);
    rect2 = QRectF(257,7, 73,100);
    rect3 = QRectF(170,193,73,100);
    rect4 = QRectF(257,193,73,100);

    int w = 80;
    int h = 100;

    num_of_cards = 51;

    QHBoxLayout* player1_tray_layout = new QHBoxLayout();
    QHBoxLayout* player2_tray_layout = new QHBoxLayout();

//player 1 :

    QLabel* player1Label = new QLabel("Player 1");
    scene1 = new QGraphicsScene();
        scene1->setSceneRect(0,0,w,h);
    scene2 = new QGraphicsScene();
        scene2->setSceneRect(0,0,w,h);
    scene3 = new QGraphicsScene();
        scene3->setSceneRect(0,0,w,h);
    scene4 = new QGraphicsScene();
        scene4->setSceneRect(0,0,w,h);
    scene5 = new QGraphicsScene();
        scene5->setSceneRect(0,0,w,h);
    QGraphicsView* view1 = new QGraphicsView();
        view1->setScene(scene1);
        view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1->setFixedSize(QSize(w,h));
    QGraphicsView* view2 = new QGraphicsView();
        view2->setScene(scene2);
        view2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view2->setFixedSize(QSize(w,h));
    QGraphicsView* view3 = new QGraphicsView();
        view3->setScene(scene3);
        view3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view3->setFixedSize(QSize(w,h));
    QGraphicsView* view4 = new QGraphicsView();
        view4->setScene(scene4);
        view4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view4->setFixedSize(QSize(w,h));
    QGraphicsView* view5 = new QGraphicsView();
        view5->setScene(scene5);
        view5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view5->setFixedSize(QSize(w,h));
    player1_tray_layout->addWidget(player1Label);
    player1_tray_layout->addWidget(view1);
    player1_tray_layout->addWidget(view2);
    player1_tray_layout->addWidget(view3);
    player1_tray_layout->addWidget(view4);
    player1_tray_layout->addWidget(view5);
    rdraw1 = new QPushButton("Hit");
rdraw1->setVisible(false);
    stand1 = new QPushButton("Stand");
 stand1->setVisible(false);
     player1_tray_layout->addWidget(rdraw1);
     player1_tray_layout->addWidget(stand1);

//player 2 :

     QLabel* player2Label = new QLabel("Player 2");
    scene6 = new QGraphicsScene();
        scene6->setSceneRect(0,0,w,h);
    scene7 = new QGraphicsScene();
        scene7->setSceneRect(0,0,w,h);
    scene8 = new QGraphicsScene();
        scene8->setSceneRect(0,0,w,h);
    scene9 = new QGraphicsScene();
        scene9->setSceneRect(0,0,w,h);
    scene10 = new QGraphicsScene();
        scene10->setSceneRect(0,0,w,h);
    QGraphicsView* view6 = new QGraphicsView();
        view6->setScene(scene6);
        view6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view6->setFixedSize(QSize(w,h));
    QGraphicsView* view7 = new QGraphicsView();
        view7->setScene(scene7);
        view7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view7->setFixedSize(QSize(w,h));
    QGraphicsView* view8 = new QGraphicsView();
        view8->setScene(scene8);
        view8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view8->setFixedSize(QSize(w,h));
    QGraphicsView* view9 = new QGraphicsView();
        view9->setScene(scene9);
        view9->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view9->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view9->setFixedSize(QSize(w,h));
    QGraphicsView* view10 = new QGraphicsView();
        view10->setScene(scene10);
        view10->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view10->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view10->setFixedSize(QSize(w,h));
    player2_tray_layout->addWidget(player2Label);
    player2_tray_layout->addWidget(view6);
    player2_tray_layout->addWidget(view7);
    player2_tray_layout->addWidget(view8);
    player2_tray_layout->addWidget(view9);
    player2_tray_layout->addWidget(view10);
    rdraw2 = new QPushButton("Hit");
rdraw2->setVisible(false);
    stand2 = new QPushButton("Stand");
 stand2->setVisible(false);
    player2_tray_layout->addWidget(rdraw2);
    player2_tray_layout->addWidget(stand2);

//full layout :

    full_layout = new QVBoxLayout();

    full_layout->addLayout(player1_tray_layout);
    full_layout->addLayout(player2_tray_layout);

    draw = new QPushButton("First Draw");

    QHBoxLayout* buttons_layout = new QHBoxLayout();

    buttons_layout->addWidget(draw);

    lost = new QLabel("Player 2 Wins!");
lost->setVisible(false);

    won = new QLabel("Player 1 Wins!");
won->setVisible(false);

    tied = new QLabel("Both players tied!");
tied->setVisible(false);

    full_layout->addLayout(buttons_layout);

    full_layout->addWidget(lost);
    full_layout->addWidget(won);
    full_layout->addWidget(tied);

    setLayout(full_layout);

    QObject::connect(draw, &QPushButton::clicked,this, &Game::doFirstDraw);

    QObject::connect(this, &Game::firstDrawn, draw, &Game::setVisible);


    //player 1 controls:
    QObject::connect(this, &Game::opFirstDrawn, rdraw1, &Game::setVisible);
    QObject::connect(this, &Game::opFirstDrawn, stand1, &Game::setVisible);
    QObject::connect(rdraw1, &QPushButton::clicked,this, &Game::doRDraw1);
    QObject::connect(stand1, &QPushButton::clicked,this, &Game::doStand1);

    //player 2 controls:
    QObject::connect(this, &Game::player1Standing, rdraw2, &Game::setVisible);
    QObject::connect(this, &Game::player1Standing, stand2, &Game::setVisible);
    QObject::connect(rdraw2, &QPushButton::clicked,this, &Game::doRDraw2);
    QObject::connect(stand2, &QPushButton::clicked,this, &Game::doStand2);

    //final screen (busted results)
    QObject::connect(this, &Game::busted1, lost, &Game::setVisible);
    QObject::connect(this, &Game::busted2, won, &Game::setVisible);

    //final screen (value results)
    QObject::connect(this, &Game::player1Lost, lost, &Game::setVisible);
    QObject::connect(this, &Game::player1Won, won, &Game::setVisible);
    QObject::connect(this, &Game::tie, tied, &Game::setVisible);
}
void Game::makeDeck()
{

    //Create the images for each card:

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            card_image = full_image->copy(i*73,j*98,73,98);

            if(i >= 10)
            {
                card_images.push_back(card_image);
            }
            else
            {
                card_images.push_back(card_image);
            }
        }
    }

    //Create the values for each card (same index)

    for(int i = 0; i < 10; i ++)
    {
        for(int j = 0; j < 4; j++)
        {
            card_values.push_back(i+1);
        }
    }

    for(int k = 0; k < 12; k++)
    {
        card_values.push_back(10);
    }


}
void Game::setNumberOfPlayers(int nplayers)
{
    this->num_of_players = nplayers;
}
void Game::startGame()
{
    full_image = new QPixmap(":/cards.jpg");
    card_image = full_image->copy(0*73,0*97,73,97);
    makeDeck();

}
void Game::doFirstDraw()
{
    if( num_of_cards + 1 == card_images.size() && num_of_cards == 51)
    {
        //PLAYER 1 TRAY
        int index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene1->addPixmap(card_images.at(index));
        indices1.push_back(index);
        card_images.erase(card_images.begin() + index);
        index = rand() % num_of_cards + 1;
        num_of_cards--;
        scene2->addPixmap(card_images.at(index));
        if( index == indices1.at(0) || index > indices1.at(0) )
        {
            indices1.push_back(index + 1);
        }
        else
        {
            indices1.push_back(index);
        }
        card_images.erase(card_images.begin() + index);

        //PLAYER 2 TRAY
        index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene6->addPixmap(card_images.at(index));
        indices2.push_back(index);
        card_images.erase(card_images.begin() + index);
        index = rand() % num_of_cards + 1;
        num_of_cards--;
        scene7->addPixmap(card_images.at(index));
        if( index == indices2.at(0) || index > indices2.at(0) )
        {
            indices2.push_back(index + 1);
        }
        else
        {
            indices2.push_back(index);
        }
        card_images.erase(card_images.begin() + index);


        round = 2;

        emit firstDrawn(false);
        emit opFirstDrawn(true);

    }
    else
    {

    }
}

void Game::doRDraw1()
{
    if( round == 2)
    {
        int index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene3->addPixmap(card_images.at(index));
        card_images.erase(card_images.begin() + index);
        if( index > indices1.at(1) && index > indices1.at(0) )
        {
            indices1.push_back(index + 2);
        }
        else if ( index < indices1.at(1) && index < indices1.at(0) )
        {
            indices1.push_back(index);
        }
        else
        {
            indices1.push_back(index+1);
        }
        if(card_values.at(indices1.at(0)) + card_values.at(indices1.at(1)) + card_values.at(indices1.at(2))  > 21)
        {
            this->bust1();
        }
        round++;
    }
    else if ( round == 3 )
    {
        int index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene4->addPixmap(card_images.at(index));
        card_images.erase(card_images.begin() + index);
        int numsBigger = 0;
        for(auto x : indices1)
        {
            if( x > index)
            {
                numsBigger++;
            }
        }
        indices1.push_back(index+numsBigger);
        if(card_values.at(indices1.at(0)) + card_values.at(indices1.at(1)) + card_values.at(indices1.at(2)) + card_values.at(indices1.at(3)) > 21)
        {
            this->bust1();
        }
        round++;
    }
    else if (round == 4)
    {
        int index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene5->addPixmap(card_images.at(index));
        card_images.erase(card_images.begin() + index);
        int numsBigger = 0;
        for(auto x : indices1)
        {
            if( x > index)
            {
                numsBigger++;
            }
        }
        indices1.push_back(index+numsBigger);
        if(card_values.at(indices1.at(0)) + card_values.at(indices1.at(1)) + card_values.at(indices1.at(2)) + card_values.at(indices1.at(3))+ card_values.at(indices1.at(4)) > 21)
        {
            this->bust1();
        }
        round = 1;
    }
}

void Game::doRDraw2()
{
    if( round == 2)
    {
        int index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene8->addPixmap(card_images.at(index));
        card_images.erase(card_images.begin() + index);
        if( index > indices2.at(1) && index > indices2.at(0) )
        {
            indices2.push_back(index + 2);
        }
        else if ( index < indices2.at(1) && index < indices2.at(0) )
        {
            indices2.push_back(index);
        }
        else
        {
            indices2.push_back(index+1);
        }
        if(card_values.at(indices2.at(0)) + card_values.at(indices2.at(1)) + card_values.at(indices2.at(2))  > 21)
        {
            this->bust2();
        }
        round++;
    }
    else if ( round == 3 )
    {
        int index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene9->addPixmap(card_images.at(index));
        card_images.erase(card_images.begin() + index);
        int numsBigger = 0;
        for(auto x : indices2)
        {
            if( x > index)
            {
                numsBigger++;
            }
        }
        indices2.push_back(index+numsBigger);
        if(card_values.at(indices2.at(0)) + card_values.at(indices2.at(1)) + card_values.at(indices2.at(2)) + card_values.at(indices2.at(3)) > 21)
        {
            this->bust2();
        }
        round++;
    }
    else if (round == 4)
    {
        int index = QRandomGenerator::global()->bounded(0,num_of_cards) + 1;
        num_of_cards--;
        scene10->addPixmap(card_images.at(index));
        card_images.erase(card_images.begin() + index);
        int numsBigger = 0;
        for(auto x : indices2)
        {
            if( x > index)
            {
                numsBigger++;
            }
        }
        indices2.push_back(index+numsBigger);
        if(card_values.at(indices2.at(0)) + card_values.at(indices2.at(1)) + card_values.at(indices2.at(2)) + card_values.at(indices2.at(3))+ card_values.at(indices2.at(4)) > 21)
        {
            this->bust2();
        }
        round = 1;
    }
}

void Game::bust1()
{
    int sum = 0;
    round = 0;
    for(auto x : indices1)
    {
        sum += card_values.at(x);
    }

    if( sum > 21)
    {
        lost->setText("You busted! Player 2 Wins!");
        emit busted1(true);
    }

}

void Game::bust2()
{

    int sum = 0;
    round = 0;
    for(auto x : indices2)
    {
        sum += card_values.at(x);
    }

    if( sum > 21)
    {
        won->setText("You busted! Player 1 Wins!");
        emit busted2(true);
    }

}

void Game::doStand1()
{
    int sum = 0;
    for(auto x : indices1)
    {
        sum += card_values.at(x);
    }

    if( sum <= 21)
    {
        round = 2;
        emit player1Standing(true);
    }
}

void Game::doStand2()
{
    int sum1 = 0;
    int sum2 = 0;
    round = 0;
    for(auto x : indices1)
    {
        sum1 += card_values.at(x);
    }
    for(auto x : indices2)
    {
        sum2 += card_values.at(x);
    }
    if( sum1 > sum2)
    {
        emit player1Won(true);
    }
    else if ( sum1 < sum2)
    {
        emit player1Lost(true);
    }
    else
    {
        emit tie(true);
    }
}


