#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , stack(new QStackedWidget())
    , start(new QPushButton("Start Game!"))
    , game(new Game())
{
    game_with_simple_ai = new GameSimpleAI();
    game_with_complex_ai = new GameComplexAI();
    start2 = new QPushButton("Start AI Game!");
    start3 = new QPushButton("Start LEARNING AI Game");
    QWidget* menuScreen = new QWidget();
    QVBoxLayout* menuLayout = new QVBoxLayout();
    QLabel* menuTitle = new QLabel("BlackJack Game!");
    menuLayout->addWidget(menuTitle,0,Qt::AlignHCenter);
    menuLayout->addWidget(start);
    menuLayout->addWidget(start2);
    menuLayout->addWidget(start3);

    menuScreen->setLayout(menuLayout);

    stack->addWidget(menuScreen);
    stack->addWidget(game);
    stack->addWidget(game_with_simple_ai);
    stack->addWidget(game_with_complex_ai);

    setCentralWidget(stack);

    stack->setCurrentIndex(0);


    QObject::connect(start,
                     &QPushButton::clicked,
                     this,
                     &MainWindow::startPressed);

    QObject::connect(start2,
                     &QPushButton::clicked,
                     this,
                     &MainWindow::startPressed2);

    QObject::connect(start3,
                     &QPushButton::clicked,
                     this,
                     &MainWindow::startPressed3);
}

void MainWindow::startPressed()
{
    stack->setCurrentIndex(1);
    game->startGame();
}

void MainWindow::startPressed2()
{
    stack->setCurrentIndex(2);
    game_with_simple_ai->startGame();
}

void MainWindow::startPressed3()
{
    stack->setCurrentIndex(3);
    game_with_complex_ai->startGame();
}

MainWindow::~MainWindow()
{

}
