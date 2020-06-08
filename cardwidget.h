#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>

class cardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit cardWidget(QWidget* parent = nullptr);

protected:


private:
    QPointF* point;
    QRectF* source;
    QPixmap* img;
    QLabel* imageLabel;
    QVBoxLayout* layout;

};

#endif // CARDWIDGET_H
