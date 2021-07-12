#ifndef GDROGA_H
#define GDROGA_H
//#include "droga.h"
#include <QGraphicsItem>


class Gdroga : public QGraphicsItem
{
public:
    Gdroga(QLineF linia);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

private:
    QLineF droga;
    QRectF boundingRect() const override;
};

#endif // GDROGA_H
