#include "player.h"

Player::Player(std::string pname) : name(pname)
{
    w = 80;
    h = 100;
    specialRoundBoolean = false;

    full_image = new QPixmap(":/cards.jpg");

    moneyLabel = new QLabel();
    money = 1000;
    waitforbets=false;
    bet = new QPushButton();
    bet->setText("Bet: ");
    bet->setEnabled(false);

    betMoney = new QSpinBox();
    betMoney->setRange(1,money);
    betMoney->setEnabled(false);

    QHBoxLayout* beyLayout = new QHBoxLayout;
    QVBoxLayout* bey2Layout = new QVBoxLayout;
    bey2Layout->addWidget(moneyLabel);
    bey2Layout->addLayout(beyLayout);
    beyLayout->addWidget(bet);
    betMoney->resize(5,5);
    beyLayout->addWidget(betMoney);

    std::string moneyString = "Money: $" + std::to_string(money);

    moneyLabel->setText(QString::fromStdString(moneyString));

    //Create the values for each card (same index)

    for(int l = 0; l < 4; l++)
    {
        card_values.push_back(11);
    }

    for(int i = 1; i < 10; i ++)
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

    //Create layout
    playerLabel = new QLabel(QString::fromStdString(name));
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
    view1 = new QGraphicsView();
        view1->setScene(scene1);
        view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1->setFixedSize(QSize(w,h));
    view2 = new QGraphicsView();
        view2->setScene(scene2);
        view2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view2->setFixedSize(QSize(w,h));
    view3 = new QGraphicsView();
        view3->setScene(scene3);
        view3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view3->setFixedSize(QSize(w,h));
    view4 = new QGraphicsView();
        view4->setScene(scene4);
        view4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view4->setFixedSize(QSize(w,h));
    view5 = new QGraphicsView();
        view5->setScene(scene5);
        view5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view5->setFixedSize(QSize(w,h));
    player_tray_layout = new QHBoxLayout;
    player_tray_layout->addWidget(playerLabel);
    player_tray_layout->addLayout(bey2Layout);
    player_tray_layout->addWidget(view1);
    player_tray_layout->addWidget(view2);
    player_tray_layout->addWidget(view3);
    player_tray_layout->addWidget(view4);
    player_tray_layout->addWidget(view5);
    rdraw = new QPushButton("Hit");
rdraw->setVisible(false);
    stand = new QPushButton("Stand");
 stand->setVisible(false);
     player_tray_layout->addWidget(rdraw);
     player_tray_layout->addWidget(stand);
     setLayout(player_tray_layout);

//Create connections
     QObject::connect(this, &Player::enable,rdraw,&QPushButton::setVisible);
     QObject::connect(this, &Player::enable,stand,&QPushButton::setVisible);
     QObject::connect(this, &Player::enableBetting,bet,&QPushButton::setEnabled);
     QObject::connect(this, &Player::enableBetting,betMoney,&QPushButton::setEnabled);
     QObject::connect(bet, &QPushButton::clicked,this,&Player::continueGame);

     QObject::connect(rdraw, &QPushButton::clicked,this,&Player::emitDRAW);
     QObject::connect(stand, &QPushButton::clicked,this,&Player::standF);
     QObject::connect(this, &Player::removal,rdraw,&QPushButton::setVisible);
     QObject::connect(this, &Player::removal,stand,&QPushButton::setVisible);


//AI connections
    // QObject::connect(this, &Player::hit,rdraw,&QPushButton::click);
    // QObject::connect(this, &Player::standSig,stand,&QPushButton::click);
}

void Player::givePixmap(QPixmap& pimage, int round)
{
    if(round == 1 && specialRoundBoolean)
    {
        //round 1 is first draw of two cards, so this draws the second since the boolean is false first
        scene2->addPixmap(pimage);
    }
    else if (round == 1 && !specialRoundBoolean)
    {
        //this should run first, so that the second call is true
        scene1->addPixmap(pimage);
        specialRoundBoolean = true;
    }
    else if (round == 2)
    {
        scene3->addPixmap(pimage);
        specialRoundBoolean = true;
    }
    else if (round == 3)
    {
        scene4->addPixmap(pimage);
        specialRoundBoolean = true;
    }
    else if (round == 4)
    {
        scene5->addPixmap(pimage);
        specialRoundBoolean = true;
    }
}


void Player::doFirstDraw(int x, int y)
{
    round = 1;

    indices.push_back(x);
    indices.push_back(y);

    int mapx_to_y = x % 4;
    int mapx_to_x = (x - mapx_to_y)/4;

    QPixmap card_image = full_image->copy(mapx_to_x*73,mapx_to_y*97,73,97);

    this->givePixmap(card_image,round);

    int mapy_to_y = y % 4;
    int mapy_to_x = (y - mapy_to_y)/4;

    card_image = full_image->copy(mapy_to_x*73,mapy_to_y*97,73,97);

    this->givePixmap(card_image,round);

}

void Player::drawF(int x)
{
    round++;
    indices.push_back(x);
    int mapx_to_y = x % 4;
    int mapx_to_x = (x - mapx_to_y)/4;
    QPixmap card_image = full_image->copy(mapx_to_x*73,mapx_to_y*97,73,97);
    this->givePixmap(card_image,round);

    int total = 0;
    for(auto x : indices)
    {
        total+=card_values.at(x);
    }
    //check for aces
    for(auto x : indices)
    {
        if(x < 4 && total > 21)
        {
            total-=10;
        }
    }
    if( total > 21)
    {
        emit bust(true);
    }
}

void Player::standF()
{
    int total = 0;
    for(auto x : indices)
    {
        total+=card_values.at(x);
    }
    for(auto x : indices)
    {
        if(x < 4 && total > 21)
        {
            total-=10;
        }
    }
    emit sumIS(total);
    emit done(true);
    emit removal(false);
}

void Player::on()
{
    emit enableBetting(true);
    emit disable(false);
}

void Player::emitDRAW()
{


    emit drawPLZ();


}

void delay()
{
    QTime dieTime = QTime::currentTime().addSecs(2);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
void Player::setup()
{
    bet->setEnabled(false);
    theBet = 5;
    money -= theBet;
    std::string moneyString = "Money: $" + std::to_string(money);
    moneyLabel->setText(QString::fromStdString(moneyString));
    betMoney->setRange(1,money);
    betMoney->setDisabled(true);

}


void Player::play()
{
    rdraw->setEnabled(false);
    stand->setEnabled(false);

    delay();

    if(indices.size() > 1)
    {
        int total = 0;
        for(auto x : indices)
        {
            total += card_values.at(x);
        }
        for(auto x : indices)
        {
            if(x < 4 && total > 21)
            {
                total-=10;
            }
        }
        if(total <= 16)
        {
            emit drawPLZ();
        }
        else
        {
            int total = 0;
            for(auto x : indices)
            {
                total+=card_values.at(x);
            }
            for(auto x : indices)
            {
                if(x < 4 && total > 21)
                {
                    total-=10;
                }
            }
            emit sumIS(total);
            emit done(true);
            emit removal(false);
        }
    }
}

void Player::continueGame()
{
    bet->setEnabled(false);
    theBet = betMoney->value();
    money -= theBet;
    std::string moneyString = "Money: $" + std::to_string(money);
    betMoney->setRange(1,money);
    moneyLabel->setText(QString::fromStdString(moneyString));

    emit enable(true);
}

void Player::increase()
{
    money += theBet*2;
    std::string moneyString = "Money: $" + std::to_string(money);
    betMoney->setRange(1,money);
    moneyLabel->setText(QString::fromStdString(moneyString));
}

void Player::clearStuff()
{
     specialRoundBoolean = false;

     indices.clear();
    scene1->clear();
    scene2->clear();
     scene3->clear();
      scene4->clear();
       scene5->clear();

       round = 1;

       rdraw->setVisible(false);
        stand->setVisible(false);

}


