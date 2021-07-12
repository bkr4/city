#ifndef GPOJAZD_H
#define GPOJAZD_H

#include <QGraphicsItem>
#include "pojazd.h"

class Gpojazd : public QGraphicsItem
{
private:
    Pojazd* obj;
    QPointF pos;
    QColor color;
    qreal angle;
    qreal speed;
public:

    virtual QRectF boundingRect() const override=0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override=0;
protected:
    virtual void advance(int step) override=0;
};

#endif // GPOJAZD_H
