#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPixmap>
#include <QTimer>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "game.h"
#include "gamesimpleai.h"
#include "gamecomplexai.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startPressed();
    void startPressed2();
    void startPressed3();


private:

    //holds the screens
    QStackedWidget* stack;

    //start button
    QPushButton* start;
    QPushButton* start2;
    QPushButton* start3;

    //second screen with a game on it
    Game* game;

    //third screen
    GameSimpleAI* game_with_simple_ai;

    //fourth screen
    GameComplexAI* game_with_complex_ai;

    QTimer timer;
};
#endif // MAINWINDOW_H
