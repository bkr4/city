#ifndef GPLANSZA_H
#define GPLANSZA_H

#include "gdroga.h"
#include "gpojazd.h"
#include "gsamochod.h"
#include "gkaretka.h"
#include "gskrzyzowanie.h"
#include "plansza.h"
//#include "skrzyzowanie.h"
//#include "pojazd.h"
#include <QList>


class Gplansza
{
public:
    Gplansza();
    void uaktualnij();
    int uruchom(Plansza* plansza, int argc, char **argv);
private:
    QList<Gdroga*> gdrogi;
    QList<Gskrzyzowanie*> gskrzyzowania;
    QList<Gpojazd*> gpojazdy;


};

#endif // GPLANSZA_H
