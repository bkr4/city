#include "samochod.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;

Samochod::Samochod()
{
    pos=QPointF(0,0);
    speed=1;
    color=QColor(qrand() % 256, qrand() % 256, qrand() % 256);
    angle=0;
}
string Samochod::name()
{
    return "samochod";
}
void Samochod::define(QPointF pozycja, qreal angle)
{
    pos=pozycja;
    speed=1;
    color=QColor(qrand() % 256, qrand() % 256, qrand() % 256);
    Samochod::angle=angle;
}

QPointF Samochod::podaj_pozycje()
{
    return pos;
}
qreal Samochod::podaj_kat()
{
    return angle;
}
qreal Samochod::podaj_predkosc()
{
    return speed;
}

bool Samochod::advance(Pojazd *pojazd, Droga *droga, Skrzyzowanie *skrzyzowanie)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    double doskrzyz;
    if(skrzyzowanie==nullptr) return false;
    if(droga==nullptr) return false;
    else doskrzyz=QLineF(pos, skrzyzowanie->podajPolozenie()).length();
    double dopoj;
    if(pojazd==nullptr) dopoj=-1;
    else dopoj=QLineF(pos, pojazd->podaj_pozycje()).length();
    if(dopoj<0 || dopoj>doskrzyz){    //pusto przed skrzyzowaniem
        if(doskrzyz>=(15+speed)){
            pos.setX(pos.x()+cos(angle)*speed);
            pos.setY(pos.y()+sin(angle)*speed);
        }
        else {
            if(skrzyzowanie->czyMoge(pos)){     //skret
                int k;
                bool test=true;
                while(test){
                    k=qrand()%4;
                    if(skrzyzowanie->czyJestDroga(k)){
                        test=false;
                    }

                }
                switch(k){
                case(0):
                    pos.setX(skrzyzowanie->podajPolozenie().x()+15);
                    pos.setY(skrzyzowanie->podajPolozenie().y());
                    angle=0;
                    break;

                case(1):
                    pos.setX(skrzyzowanie->podajPolozenie().x());
                    pos.setY(skrzyzowanie->podajPolozenie().y()-15);
                    angle=Pi*3/2;
                    break;

                case(2):
                    pos.setX(skrzyzowanie->podajPolozenie().x()-15);
                    pos.setY(skrzyzowanie->podajPolozenie().y());
                    angle=Pi;
                    break;

                case(3):
                    pos.setX(skrzyzowanie->podajPolozenie().x());
                    pos.setY(skrzyzowanie->podajPolozenie().y()+15);
                    angle=Pi/2;
                    break;
                }
            }
        }
    }
    else if(dopoj>10+speed){    //jazda za samochodem
        pos.setX(pos.x()+cos(angle)*speed);
        pos.setY(pos.y()+sin(angle)*speed);
    }
    return true;
}
