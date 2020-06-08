#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , stack(new QStackedWidget())
    , start(new QPushButton("Start Game!"))
    , game(new Game())
{

    QWidget* menuScreen = new QWidget();
    QVBoxLayout* menuLayout = new QVBoxLayout();
    QLabel* menuTitle = new QLabel("BlackJack Game!");
    menuLayout->addWidget(menuTitle,0,Qt::AlignHCenter);
    menuLayout->addWidget(start);

    menuScreen->setLayout(menuLayout);

    stack->addWidget(menuScreen);
    stack->addWidget(game);

    setCentralWidget(stack);

    stack->setCurrentIndex(0);


    QObject::connect(start,
                     &QPushButton::clicked,
                     this,
                     &MainWindow::startPressed);
}

void MainWindow::startPressed()
{
    stack->setCurrentIndex(1);
    game->startGame();
}

MainWindow::~MainWindow()
{

}
