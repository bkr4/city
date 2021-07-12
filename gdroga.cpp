#include "gdroga.h"
#include <iostream>
#include <QtWidgets>
using namespace std;
Gdroga::Gdroga(QLineF linia)
{
    droga=linia;
    setPos(droga.p1());
}
void Gdroga::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QPainterPath path;
    double ux=droga.unitVector().dx()*10;
    double uy=droga.unitVector().dy()*10;
    double x=droga.dx();
    double y=droga.dy();
    path.moveTo(ux+uy,ux+uy);
    path.lineTo(ux+uy+x-2*ux,ux+uy+y-2*uy);
    path.lineTo(ux+uy+x-2*ux-2*uy,ux+uy+y-2*uy-2*ux);
    path.lineTo(ux-uy,uy-ux);
    path.closeSubpath();

    painter->setBrush(Qt::blue);
    painter->drawPath(path);

}
QRectF Gdroga::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
