#ifndef DROGA_H
#define DROGA_H

#include <iostream>
#include <QLine>
#include <QtWidgets>

using namespace std;

class Droga
{
public:
    Droga(QLineF linia);
    QLineF podajPolozenie();
private:
    QLineF droga;
};

#endif // DROGA_H
