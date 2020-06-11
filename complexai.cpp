#include "complexai.h"
double sigmoid(double value)
{
   return 1 / (1 + pow(2.71828, -1 * value));
}
double sigmoidD(double value)
{
   return pow(2.71828, -1 * value) / pow((1 + pow(2.71828, -1 * value)),2);
}
ComplexAI::ComplexAI()
{
    w = 80;
    h = 100;
    specialRoundBoolean = false;

    full_image = new QPixmap(":/cards.jpg");

    reset();

    QString filename="C:/Users/Melton/Documents/blackjackv2/data.txt";

    QFile file( filename );

    file.open(QIODevice::ReadOnly);

    if(!file.isOpen())
            {
                QMessageBox::information(0,"error",file.errorString());
            }

    QString test;
        QTextStream in(&file);
        //4 neural network layers:
        //Level 1: 54 nodes -> 54 biases, 54 weights
    std::vector<QString> lines;
        while(!in.atEnd()) {
            QString line = in.readLine();
            lines.push_back(line);
        }
    QString level1Weights = lines.at(1); // represents Level 1 weights
    QStringList weightsList = level1Weights.split(' ');
    level1Weights = weightsList.at(1);
    weightsList = level1Weights.split(',');
    for(auto x : weightsList)
    {
        weights1.push_back(x.toDouble());
    }
    weights1.pop_back();
    QString level1Biases = lines.at(2); // represents Level 1 biases
    QStringList biasesList = level1Biases.split(' ');
    level1Biases = biasesList.at(1);
    biasesList = level1Biases.split(',');
    for(auto x : biasesList)
    {
        biases1.push_back(x.toDouble());
    }
    biases1.pop_back();
    QString level2Weights = lines.at(4); // represents Level 1 weights
    weightsList = level2Weights.split(' ');
    level2Weights = weightsList.at(1);
    weightsList = level2Weights.split(',');
    for(auto x : weightsList)
    {
        weights2.push_back(x.toDouble());
    }
    weights2.pop_back();
    QString level2Biases = lines.at(5); // represents Level 1 biases
    biasesList = level2Biases.split(' ');
    level2Biases = biasesList.at(1);
    biasesList = level2Biases.split(',');
    for(auto x : biasesList)
    {
        biases2.push_back(x.toDouble());
    }
    biases2.pop_back();
    QString level3Weights = lines.at(7); // represents Level 1 weights
    weightsList = level3Weights.split(' ');
    level3Weights = weightsList.at(1);
    weightsList = level3Weights.split(',');
    for(auto x : weightsList)
    {
        weights3.push_back(x.toDouble());
    }
    weights3.pop_back();
    QString level3Biases = lines.at(8); // represents Level 1 biases
    biasesList = level3Biases.split(' ');
    level3Biases = biasesList.at(1);
    biasesList = level3Biases.split(',');
    for(auto x : biasesList)
    {
        biases3.push_back(x.toDouble());
    }
    biases3.pop_back();

    nodes1.resize(54);
    nodes2.resize(30);
    nodes3.resize(15);




//



    file.close();

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
    playerLabel = new QLabel(QString::fromStdString("Learning AI"));
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
     QObject::connect(this, &ComplexAI::enable,rdraw,&QPushButton::setVisible);
     QObject::connect(this, &ComplexAI::enable,stand,&QPushButton::setVisible);
     QObject::connect(this, &ComplexAI::enableBetting,bet,&QPushButton::setEnabled);
     QObject::connect(this, &ComplexAI::enableBetting,betMoney,&QPushButton::setEnabled);
     QObject::connect(bet, &QPushButton::clicked,this,&ComplexAI::continueGame);

     QObject::connect(rdraw, &QPushButton::clicked,this,&ComplexAI::emitDRAW);
     QObject::connect(stand, &QPushButton::clicked,this,&ComplexAI::standF);
     QObject::connect(this, &ComplexAI::removal,rdraw,&QPushButton::setVisible);
     QObject::connect(this, &ComplexAI::removal,stand,&QPushButton::setVisible);


//AI connections
    // QObject::connect(this, &ComplexAI::hit,rdraw,&QPushButton::click);
    // QObject::connect(this, &ComplexAI::standSig,stand,&QPushButton::click);
}

void ComplexAI::givePixmap(QPixmap& pimage, int round)
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


void ComplexAI::doFirstDraw(int x, int y)
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

void ComplexAI::drawF(int x)
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

void ComplexAI::standF()
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

void ComplexAI::on()
{
    emit enableBetting(true);
    emit disable(false);
}

void ComplexAI::emitDRAW()
{
    emit drawPLZ();
}

void ComplexAI::setup()
{
    bet->setEnabled(false);

    //here I want the AI to create a bet which maximizes profit
    //initialize first layer

    nodes1.at(indices.at(0)) = 1;
    nodes1.at(indices.at(1)) = 1;
    //calculate next layer(2) size of 30

    for(unsigned int i = 0; i < nodes2.size(); i++)
    {
        int total = 0;
        for(unsigned int j = 0; j < nodes1.size(); j++)
        {
            total += nodes1.at(j) * weights1.at(j);
        }
        nodes2.at(i) = sigmoid(total + biases2.at(i));
    }
    //calculate next layer(3) size of 15

    for(unsigned int i = 0; i < nodes3.size(); i++)
    {
        int total = 0;
        for(unsigned int j = 0; j < nodes2.size(); j++)
        {
            total += nodes2.at(j) * weights2.at(j);
        }
        nodes3.at(i) = sigmoid(total+ biases3.at(i));
    }
    //calculate the multiplier

    double totalVal = 0;
    for(unsigned int i = 0; i < nodes3.size(); i++)
    {
        totalVal += sigmoid(nodes3.at(i)*weights3.at(i) );
    }
    multiplier = sigmoid(totalVal);

    theBet = multiplier*money;
    money -= theBet;
    std::string moneyString = "Money: $" + std::to_string(money);
    moneyLabel->setText(QString::fromStdString(moneyString));
    betMoney->setRange(1,money);
    betMoney->setDisabled(true);

}


void ComplexAI::play()
{
    rdraw->setEnabled(false);
    stand->setEnabled(false);

//    delay();

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

void ComplexAI::continueGame()
{
    bet->setEnabled(false);
    theBet = betMoney->value();
    money -= theBet;
    std::string moneyString = "Money: $" + std::to_string(money);
    betMoney->setRange(1,money);
    moneyLabel->setText(QString::fromStdString(moneyString));

    emit enable(true);
}

void ComplexAI::increase()
{
    money += theBet*2;
    std::string moneyString = "Money: $" + std::to_string(money);
    betMoney->setRange(1,money);
    moneyLabel->setText(QString::fromStdString(moneyString));

    //learn that this was good, multiplier shouldve been 1
    learn(1.00 - multiplier);
}

void ComplexAI::equalize()
{
    money += theBet;
    std::string moneyString = "Money: $" + std::to_string(money);
    betMoney->setRange(1,money);
    moneyLabel->setText(QString::fromStdString(moneyString));

    learn(0.50 - multiplier);
}

void ComplexAI::learnLost()
{
    //learn that this was not ok, multiplier shouldve 0
    double cost = (0.0 - multiplier);

    learn(cost);
}

void ComplexAI::updateData()
{
    QString filename="C:/Users/Melton/Documents/blackjackv2/data.txt";

        QFile file( filename );

        file.open(QIODevice::WriteOnly);

        QTextStream out(&file);

        out << "Level 1: " << "\n";
            out << "Weights: ";
            for(unsigned int i = 0; i < weights1.size(); i++)
            {
                out << QString::fromStdString(std::to_string(weights1.at(i))) + ",";
            }
            out << "\n";
            out << "Biases: ";
            for(unsigned int j = 0; j < biases1.size(); j++)
            {
                out << QString::fromStdString(std::to_string(biases1.at(j))) + ",";
            }
            out << "\n";

            //Level 2: 30 nodes

            out << "Level 2: " << "\n";
            out << "Weights: ";
            for(unsigned int i = 0; i < weights2.size(); i++)
            {
                out << QString::fromStdString(std::to_string(weights2.at(i))) + ",";
            }
            out << "\n";
            out << "Biases: ";
            for(unsigned int j = 0; j < biases2.size(); j++)
            {
                out << QString::fromStdString(std::to_string(biases2.at(j))) + ",";
            }
            out << "\n";

            //Level 3: 15 nodes

            out << "Level 3: " << "\n";
            out << "Weights: ";
            for(unsigned int i = 0; i < weights3.size(); i++)
            {
                out << QString::fromStdString(std::to_string(weights3.at(i))) + ",";
            }
            out << "\n";
            out << "Biases: ";
            for(unsigned int j = 0; j < weights3.size(); j++)
            {
                out << QString::fromStdString(std::to_string(weights3.at(j))) + ",";
            }
            out << "\n";
            file.close();
}
void ComplexAI::clearStuff()
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
void ComplexAI::obtainInfo(int e, int f)
{
    nodes1.resize(54);
    nodes1.at(e) = 1;
    nodes1.at(f) = 1;
}
void ComplexAI::reset()
{
    QString filename="C:/Users/Melton/Documents/blackjackv2/data.txt";

        QFile file( filename );

        file.open(QIODevice::WriteOnly);

        QTextStream out(&file);

        int layer1 = 54;
        int layer2 = 30;
        int layer3 = 15;
        int x = 1;

        out << "Level 1: " << "\n";
            out << "Weights: ";
            for(unsigned int i = 0; i < layer1; i++)
            {
                out << QString::fromStdString(std::to_string(x)) + ",";
            }
            out << "\n";
            out << "Biases: ";
            for(unsigned int j = 0; j < layer1; j++)
            {
                out << QString::fromStdString(std::to_string(x)) + ",";
            }
            out << "\n";

            //Level 2: 30 nodes

            out << "Level 2: " << "\n";
            out << "Weights: ";
            for(unsigned int i = 0; i < layer2; i++)
            {
                out << QString::fromStdString(std::to_string(x)) + ",";
            }
            out << "\n";
            out << "Biases: ";
            for(unsigned int j = 0; j < layer2; j++)
            {
                out << QString::fromStdString(std::to_string(x)) + ",";
            }
            out << "\n";

            //Level 3: 15 nodes

            out << "Level 3: " << "\n";
            out << "Weights: ";
            for(unsigned int i = 0; i < layer3; i++)
            {
                out << QString::fromStdString(std::to_string(x)) + ",";
            }
            out << "\n";
            out << "Biases: ";
            for(unsigned int j = 0; j < layer3; j++)
            {
                out << QString::fromStdString(std::to_string(x)) + ",";
            }
            out << "\n";
            file.close();
}

void ComplexAI::learn(double cost)
{
    //correct weights for layer 3
    std::vector<double> NEWweights3(weights3.size());
    for(unsigned int i = 0; i < weights3.size(); i++)
    {
        double a = nodes3.at(i);
        double w = weights3.at(i);
        double b = biases3.at(i);
        NEWweights3.at(i) = w * (a * sigmoidD(w * a + b) * 2 * cost);
    }
    weights3 = NEWweights3;
    //correct baises for layer 3
    std::vector<double> NEWbiases3(biases3.size());
    for(unsigned int i = 0; i < biases3.size(); i++)
    {
        double a = nodes3.at(i);
        double w = weights3.at(i);
        double b = biases3.at(i);
        NEWbiases3.at(i) = b * (sigmoidD(w * a + b) * 2 * cost);
    }
    biases3 = NEWbiases3;
    //correct nodes for layer 3
    std::vector<double> NEWnodes3(nodes3.size());

    std::vector<double> costPerNode(nodes3.size());

    for(unsigned int i = 0; i < nodes3.size(); i++)
    {
        double a = nodes3.at(i);
        double w = weights3.at(i);
        double b = biases3.at(i);
        costPerNode.at(i) = (w * sigmoidD(w * a + b) * 2 * cost);
        NEWnodes3.at(i) = a * (w * sigmoidD(w * a + b) * 2 * cost);
    }
    nodes3 = NEWnodes3;

    //correct weights in layer 2
    std::vector<double> NEWweights2(weights2.size());
    for(unsigned int i = 0; i < weights3.size(); i++)
    {
        for(unsigned int j = 0; j < weights2.size(); j++)
        {
            double a = nodes2.at(j);
            double w = weights2.at(j);
            double b = biases2.at(j);
            NEWweights2.at(j) += w * (a * sigmoidD(w * a + b) * costPerNode.at(i) );
        }
    }
    for(unsigned int k = 0; k < weights2.size(); k++)
    {
        NEWweights2.at(k) /= weights3.size();
    }
    weights2 = NEWweights2;

    //correct biases in layer 2
    std::vector<double> NEWbiases2(biases2.size());
    for(unsigned int i = 0; i < biases3.size(); i++)
    {
        for(unsigned int j = 0; j < biases2.size(); j++)
        {
            double a = nodes2.at(j);
            double w = weights2.at(j);
            double b = biases2.at(j);
            NEWbiases2.at(j) += b * (a * sigmoidD(w * a + b) * costPerNode.at(i) );
        }
    }
    for(unsigned int k = 0; k < biases2.size(); k++)
    {
        NEWbiases2.at(k) /= biases3.size();
    }
    biases2 = NEWbiases2;

    //correct nodes for layer 2
    std::vector<double> NEWnodes2(nodes2.size());

    std::vector<double> costPerNode2(nodes2.size());

    for(unsigned int i = 0; i < nodes3.size(); i++)
    {
        for(unsigned int j = 0; j < nodes2.size(); j++)
        {
            double a = nodes2.at(j);
            double w = weights2.at(j);
            double b = biases2.at(j);
            costPerNode2.at(j) += (w * sigmoidD(w * a + b) * costPerNode.at(i));
            NEWnodes2.at(j) += a * (w * sigmoidD(w * a + b) * costPerNode.at(i));
        }

    }
    for(unsigned int k = 0; k < nodes2.size(); k++)
    {
        NEWnodes2.at(k) /= nodes3.size();
        costPerNode2.at(k) /= nodes3.size();
    }
    nodes2 = NEWnodes2;

    //correct weights in layer 1
    std::vector<double> NEWweights1(weights1.size());
    for(unsigned int i = 0; i < weights2.size(); i++)
    {
        for(unsigned int j = 0; j < weights1.size(); j++)
        {
            double a = nodes1.at(j);
            double w = weights1.at(j);
            double b = biases1.at(j);
            NEWweights1.at(j) += w * (a * sigmoidD(w * a + b) * costPerNode2.at(i) );
        }
    }
    for(unsigned int k = 0; k < weights1.size(); k++)
    {
        NEWweights1.at(k) /= weights2.size();
    }
    weights1 = NEWweights1;

    //correct biases in layer 1
    std::vector<double> NEWbiases1(biases1.size());
    for(unsigned int i = 0; i < biases2.size(); i++)
    {
        for(unsigned int j = 0; j < biases1.size(); j++)
        {
            double a = nodes1.at(j);
            double w = weights1.at(j);
            double b = biases1.at(j);
            NEWbiases1.at(j) += b * (a * sigmoidD(w * a + b) * costPerNode2.at(i) );
        }
    }
    for(unsigned int k = 0; k < biases1.size(); k++)
    {
        NEWbiases1.at(k) /= biases2.size();
    }
    biases1 = NEWbiases1;


    updateData();
}

