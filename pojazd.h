#ifndef POJAZD_H
#define POJAZD_H
#include <QGraphicsItem>
#include <QtWidgets>
#include "droga.h"
#include "skrzyzowanie.h"


class Pojazd
{
public:

    virtual void define(QPointF pozycja, qreal angle)=0;
    virtual bool advance(Pojazd* pojazd, Droga* droga, Skrzyzowanie* skrzyzowanie)=0;
    virtual QPointF podaj_pozycje()=0;
    virtual qreal podaj_kat()=0;
    virtual qreal podaj_predkosc()=0;
    virtual string name()=0;

};

#endif // POJAZD_H
