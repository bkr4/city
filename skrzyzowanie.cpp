#include "skrzyzowanie.h"

Skrzyzowanie::Skrzyzowanie(QPointF polozenie)
{
    Skrzyzowanie::polozenie = polozenie;
    czas=0;
    for(int i=0;i<4;i++){
        drogi[i]=false;
    }

}

QPointF Skrzyzowanie::podajPolozenie()
{
    return polozenie;
}
bool Skrzyzowanie::czyMoge(QPointF pozycja)
{
    QLineF odl;
    odl=QLineF(polozenie, pozycja);
    qreal kierunek=odl.angle();
    int nrkierunku=-1;
    if(kierunek>359.5||kierunek<0.5) nrkierunku=0;
    else if(kierunek>89.5&&kierunek<90.5) nrkierunku=1;
    else if(kierunek>179.5&&kierunek<180.5) nrkierunku=2;
    else if(kierunek>269.5&&kierunek<270.5) nrkierunku=3;
    if(nrkierunku==nrcyklu) return true;
    else return false;

}
void Skrzyzowanie::dodajDroge(int nr){
    drogi[nr]=true;
}

bool Skrzyzowanie::czyJestDroga(int nr){
    if(nr<=3) return drogi[nr];
    else return false;
}
void Skrzyzowanie::cykl()
{
    do{
        if(czyJestDroga(nrcyklu)) czas++;
        else czas+=20;
        if(czas<20) nrcyklu=0;
        else if(czas<40) nrcyklu=1;
        else if(czas<60) nrcyklu=2;
        else if(czas<80) nrcyklu=3;
        else {
            czas=0;
            nrcyklu=0;
        }
    }
    while(!czyJestDroga(nrcyklu));


}
