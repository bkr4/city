#ifndef KONIEC_H
#define KONIEC_H
#include "droga.h"

class Koniec
{
    int id;
    int cz; //częstotliwość generacji
    Droga* dr; //wskaźnik na dołączoną drogę
    int m; //metoda dołączenia do drogi
    void generuj();
    void kasuj();
public:
    Koniec(int idn, int cze, Droga* droga, int dr);
    void cykl();
};

#endif // KONIEC_H
