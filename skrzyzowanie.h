#ifndef SKRZYZOWANIE_H
#define SKRZYZOWANIE_H
#include <QLine>
#include <QtWidgets>
#include <time.h>

class Skrzyzowanie
{
public:
    Skrzyzowanie(QPointF polozenie);
    QPointF podajPolozenie();
    bool czyMoge(QPointF pozycja);
    bool czyJestDroga(int nr);
    void cykl();
    void dodajDroge(int nr);
private:

    QPointF polozenie;
    int nrcyklu;
    int czas;
    bool drogi[4];

};

#endif // SKRZYZOWANIE_H
