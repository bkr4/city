#include "droga.h"

Droga::Droga(QLineF linia)
{
    droga=linia;
}
QLineF Droga::podajPolozenie(){
    return droga;
}
