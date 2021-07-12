#ifndef GSAMOCHOD_H
#define GSAMOCHOD_H

#include <QGraphicsItem>
#include "samochod.h"
#include "gpojazd.h"

class Gsamochod: public Gpojazd
{
private:
    Pojazd* obj;
    QPointF pos;
    QColor color;
    qreal angle;
    qreal speed;

public:
    Gsamochod(Pojazd* pojazd);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual void advance(int step) override;
};

#endif // GSAMOCHOD_H
