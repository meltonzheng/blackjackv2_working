#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QPushButton>

class Player : public QWidget
{
    Q_OBJECT
public:
    Player(std::string pname);
    void givePixmap(QPixmap& pimage, int round);
    void giveIndex(int pindex);

public slots:
    void on();
    void drawF();
    void standF();
    void doFirstDraw(int x, int y);
//simple AI slot
    void play();

signals:
    void enable(bool b);
    void disable(bool b);
//simple AI signals

private:
    int w;
    int h;
    std::string name;
    bool specialRoundBoolean;

    std::vector<int> indices;
    std::vector<int> card_values;

    QLabel* playerLabel;
    QPushButton* rdraw;
    QPushButton* stand;
    QGraphicsScene* scene1;
    QGraphicsScene* scene2;
    QGraphicsScene* scene3;
    QGraphicsScene* scene4;
    QGraphicsScene* scene5;
    QGraphicsView* view1;
    QGraphicsView* view2;
    QGraphicsView* view3;
    QGraphicsView* view4;
    QGraphicsView* view5;
    QHBoxLayout* player_tray_layout;

};

#endif // PLAYER_H
