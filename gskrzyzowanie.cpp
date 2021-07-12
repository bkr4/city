#include "gskrzyzowanie.h"

Gskrzyzowanie::Gskrzyzowanie(QPointF polozenie, Skrzyzowanie* skrz)
{
    Gskrzyzowanie::polozenie=polozenie;
    Gskrzyzowanie::skrz=skrz;
    setPos(polozenie);
}
void Gskrzyzowanie::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    QPainterPath path;
    path.moveTo(-10,-10);
    path.lineTo(-10,10);
    path.lineTo(10,10);
    path.lineTo(10,-10);
    path.closeSubpath();
    painter->setBrush(Qt::red);
    painter->drawPath(path);
}
QRectF Gskrzyzowanie::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
