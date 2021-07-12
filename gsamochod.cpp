#include "gsamochod.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;

Gsamochod::Gsamochod(Pojazd *pojazd)
{
    obj=pojazd;
    angle=pojazd->podaj_kat();
    pos=pojazd->podaj_pozycje();
    speed=pojazd->podaj_predkosc();
    setPos(pos);
}
void Gsamochod::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPainterPath path;
    double s=0;
    double c=1;
    path.moveTo(-4*c+s, 2*c-4*s);
    path.lineTo(-4*c+8*s,8*c-4*s);
    path.lineTo(4*c+8*s,8*c+4*s);
    path.lineTo(4*c+s,2*c+4*s);
    path.closeSubpath();

    painter->setBrush(Qt::black);
    painter->drawPath(path);

}
QRectF Gsamochod::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
void Gsamochod::advance(int step)
{
    if (!step)
        return;
    if(obj==nullptr) {
        return;
    }
    angle=obj->podaj_kat();
    speed=obj->podaj_predkosc();
    pos=obj->podaj_pozycje();
    setRotation(angle/(Pi)*180);
    setPos(pos);
}
