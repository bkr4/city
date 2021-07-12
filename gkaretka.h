#ifndef GKARETKA_H
#define GKARETKA_H
#include "karetka.h"
#include "gpojazd.h"

#include <QGraphicsItem>
#include "samochod.h"
#include "gpojazd.h"

class Gkaretka: public Gpojazd
{
private:
    Pojazd* obj;
    QPointF pos;
    QColor color;
    qreal angle;
    qreal speed;
    int licznik;

public:
    Gkaretka(Pojazd* pojazd);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual void advance(int step) override;
};

#endif // GKARETKA_H
