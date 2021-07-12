#include <QtWidgets>
#include <math.h>
#include <QCoreApplication>
#include "plansza.h"
#include "gplansza.h"

int main(int argc, char **argv)
{

    Plansza* plansza=new Plansza;
    plansza->uruchom();
    Gplansza* gplansza=new Gplansza;
    gplansza->uruchom(plansza, argc, argv);
}
