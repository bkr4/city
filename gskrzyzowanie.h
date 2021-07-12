#ifndef GSKRZYZOWANIE_H
#define GSKRZYZOWANIE_H
#include <QGraphicsItem>
#include "skrzyzowanie.h"

class Gskrzyzowanie : public QGraphicsItem
{
public:
    Gskrzyzowanie(QPointF polozenie, Skrzyzowanie* skrz);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
    void swiatla(int metoda);
private:
    QPointF polozenie;
    QRectF boundingRect() const override;
    Skrzyzowanie* skrz;
};

#endif // GSKRZYZOWANIE_H
