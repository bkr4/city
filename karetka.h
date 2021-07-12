#ifndef KARETKA_H
#define KARETKA_H
#include "pojazd.h"
//#include "plansza.h"


class Karetka: public Pojazd
{
private:
    QPointF pos;
    QColor color;
    qreal angle;
    qreal speed;

public:
    Karetka();
    void define(QPointF pozycja, qreal angle);
    bool advance(Pojazd* pojazd, Droga* droga, Skrzyzowanie* skrzyzowanie);
    QPointF podaj_pozycje();
    qreal podaj_kat();
    qreal podaj_predkosc();
    string name();

};

#endif // KARETKA_H
