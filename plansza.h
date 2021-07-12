#ifndef PLANSZA_H
#define PLANSZA_H

#include <QObject>
#include <math.h>
#include "droga.h"
#include "samochod.h"
#include "skrzyzowanie.h"
#include "karetka.h"
#include <fstream>
#include <sstream>
#include <QList>

class Plansza: public QObject
{
    Q_OBJECT
public:
    Plansza();
    Droga* podaj_droge(QPointF pozycja, qreal kierunek);
    Skrzyzowanie* podaj_skrz(QPointF pozycja, qreal kierunek);
    Pojazd* podaj_pojazd(QPointF pozycja, qreal kierunek);
    int uruchom();
    QList<Droga*> podaj_drogi();
    QList<Skrzyzowanie*> podaj_skrzyzowania();
    QList<Pojazd*> podaj_pojazdy();
public slots:
    void akt();
private:

    bool wczytaj(string plik);
    QList<Droga*> drogi;
    QList<Skrzyzowanie*> skrzyzowania;
    QList<Pojazd*> pojazdy;


};

#endif // PLANSZA_H
