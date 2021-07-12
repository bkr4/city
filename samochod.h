#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include "pojazd.h"
//#include "plansza.h"


class Samochod: public Pojazd
{
private:
    QPointF pos;
    QColor color;
    qreal angle;
    qreal speed;

public:
    Samochod();
    void define(QPointF pozycja, qreal angle);
    bool advance(Pojazd* pojazd, Droga* droga, Skrzyzowanie* skrzyzowanie);
    QPointF podaj_pozycje();
    qreal podaj_kat();
    qreal podaj_predkosc();
    string name();
};

#endif // SAMOCHOD_H
