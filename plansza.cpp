#include "plansza.h"
#include <QDir>
#include <QString>
#include <QTime>
static const double Pi = 3.14159265358979323846264338327950288419717;
Plansza::Plansza()
{

}
static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += 2*Pi;
    while (angle > 2*Pi)
        angle -= 2*Pi;
    return angle;
}
bool Plansza::wczytaj(string plik){
    ifstream p;
    bool test=false;
    p.open(plik.c_str());
    if(!p.is_open()) {
        p.close();
        p.clear();
        cout<<"Nie mozna otworzyc pliku"<<endl;
        return test;
    }
    string linia;
    string l[10];

    for(int i=0; i<10; i++){
        l[i]="";
    }

    int k;
    while(!p.eof()){
        getline(p,linia);
        int ls=linia.size();
        test=true;
        k=0;
        for(int i=0; i<ls; i++){
            while((linia[i]!=';')&&(i<ls)){
                l[k]+=linia[i];
                i++;
            }
            k++;
        }
        if(l[0]=="s"){
            double x,y;
            stringstream s;
            s << l[1];
            s >> x;
            s.clear();
            s << l[2];
            s >> y;
            QPointF polozenie(x,y);
            Skrzyzowanie *skrz=new Skrzyzowanie(polozenie);
            skrzyzowania.append(skrz);
            //cout<<"Dodano skrzyzowanie "<<x<<" "<<y<<endl;
        }
        else if(l[0]=="d"){
            double x1,y1,x2,y2;
            stringstream s;
            s << l[1];
            s >> x1;
            s.clear();
            s << l[2];
            s >> y1;
            s.clear();
            s << l[3];
            s >> x2;
            s.clear();
            s << l[4];
            s >> y2;
            QLineF linia(x1,y1,x2,y2);
            Droga *dr=new Droga(linia);
            drogi.append(dr);
        }
        else test=false;
        linia="";
        for(int i=0; i<10; i++){
            l[i]="";
        }
    }
    p.close();
    for(int i=0; i<skrzyzowania.length(); i++){
        for(int k=0; k<drogi.length(); k++){
            int nr=-1;
            if(drogi[k]->podajPolozenie().p1()==skrzyzowania[i]->podajPolozenie()){

                if (abs(drogi[k]->podajPolozenie().angle())<0.01){
                    nr=0;
                } else if (abs(drogi[k]->podajPolozenie().angle()-90)<0.01){
                    nr=1;
                } else if (abs(drogi[k]->podajPolozenie().angle()-180)<0.01){
                    nr=2;
                } else if (abs(drogi[k]->podajPolozenie().angle()-270)<0.01){
                    nr=3;
                }
                if(nr!=-1) {
                    skrzyzowania[i]->dodajDroge(nr);

                }
            }
            else if(drogi[k]->podajPolozenie().p2()==skrzyzowania[i]->podajPolozenie()){

                if (abs(drogi[k]->podajPolozenie().angle())<0.01){
                    nr=2;
                } else if (abs(drogi[k]->podajPolozenie().angle()-90)<0.01){
                    nr=3;
                } else if (abs(drogi[k]->podajPolozenie().angle()-180)<0.01){
                    nr=0;
                } else if (abs(drogi[k]->podajPolozenie().angle()-270)<0.01){
                    nr=1;
                }
                if(nr!=-1) {
                    skrzyzowania[i]->dodajDroge(nr);

                }
            }
        }
    }
    return test;
}

Droga* Plansza::podaj_droge(QPointF pozycja, qreal kierunek){
    kierunek=normalizeAngle(kierunek);
    kierunek=kierunek*180/Pi;

    for (int i = 0; i < drogi.length(); i++) {
        QLineF linia = drogi[i]->podajPolozenie();
        QLineF linia1=QLineF(linia.p1(),pozycja);
        QLineF linia2=QLineF(linia.p2(),pozycja);
        if(abs(linia.length()-linia1.length()-linia2.length())<0.1 && (abs(kierunek-linia.angle())<0.01 || abs(normalizeAngle((kierunek-linia.angle()-180)*Pi/180))<0.01)){
            return drogi[i];
        }

    }
    cout<<"Nie znaleziono linii dla pojazdu: x: "<<pozycja.x()<<" y: "<<pozycja.y()<<kierunek<<endl;
    return nullptr;
}
Skrzyzowanie* Plansza::podaj_skrz(QPointF pozycja, qreal kierunek){
    int nr=-1;
    double odl=1000;
    for (int i = 0; i < skrzyzowania.length(); i++) {
        QPointF punkt = skrzyzowania[i]->podajPolozenie();
        QLineF linia=QLineF(punkt,pozycja);
        QLineF linia1=QLineF(punkt,QPointF(pozycja.x()+cos(kierunek),pozycja.y()+sin(kierunek)));

        if((abs(punkt.x()-pozycja.x())<0.01 || abs(punkt.y()-pozycja.y())<0.01) && linia1.length()<linia.length() && nr==-1){
            odl=linia.length();
            nr=i;
        }
        else if((abs(punkt.x()-pozycja.x())<0.01 || abs(punkt.y()-pozycja.y())<0.01) && linia1.length()<linia.length() && linia.length()<odl){
            odl=linia.length();
            nr=i;
        }
    }
    if(nr==-1){
        cout<<"Nie znaleziono skrzyzowania dla pojazdu: x: "<<pozycja.x()<<" y: "<<pozycja.y()<<" k: "<<kierunek<<endl;
        return nullptr;
    } else return skrzyzowania[nr];

}
Pojazd* Plansza::podaj_pojazd(QPointF pozycja, qreal kierunek){
    QLineF linia;

    int nr=-1;
    double odl=1000;
    for(int i=0; i<pojazdy.length();i++){
        QPointF punkt = pojazdy[i]->podaj_pozycje();
        double kat=pojazdy[i]->podaj_kat();
        QLineF linia1=QLineF(punkt,QPointF(pozycja.x()+cos(kierunek),pozycja.y()+sin(kierunek)));
        linia=QLineF(pozycja, punkt);
        if(abs(kat-kierunek)<0.01 && nr==-1 && linia.length()>0.01 && linia1.length()<linia.length()){
            odl=linia.length();
            nr=i;
        }
        else if(abs(kat-kierunek)<0.01 && linia.length()<=odl && linia.length()>0.01 && linia1.length()<linia.length()){
            odl=linia.length();
            nr=i;
        }
    }
    if(nr==-1){
        return nullptr;
    } else return pojazdy[nr];
}
int Plansza::uruchom(){
    const int pojazdow=20;

    string plik="plik.txt";
    if(wczytaj(plik)) cout<<"Pomyslnie wczytano plansze"<<endl;
    else {
        cout<<"Blad wczytywania planszy. Zamykam aplikacje"<<endl;
        return 0;
    }
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    bool b;
    for (int i=0; i<pojazdow; i++){
        qreal x,y,angle;
        do{
            b=false;
            int nrdrogi=qrand()%(drogi.length());
            QLineF linia=drogi[nrdrogi]->podajPolozenie();
            double ux=linia.unitVector().dx()*10;
            double uy=linia.unitVector().dy()*10;
            x=(double)qrand()/RAND_MAX*(linia.dx()-3.1*ux)+(linia.x1()+1.55*ux);
            y=(double)qrand()/RAND_MAX*(linia.dy()-3.1*uy)+(linia.y1()+1.55*uy);
            angle=linia.angle()*Pi/180;
            angle=normalizeAngle(angle);

            for(int k=0;k<pojazdy.length();k++){
                if(abs(pojazdy[k]->podaj_pozycje().x()-x)<10 && abs(pojazdy[k]->podaj_pozycje().x()-x)<10 && abs(pojazdy[k]->podaj_kat()-angle)<0.1){
                    b=true;
                    break;
                }
            }
        }while(b);

        b=false;
        QPointF punkt=QPointF(x,y);
        if(i==0 || i==1) pojazdy.append(new Karetka);
        else pojazdy.append(new Samochod);

        pojazdy[i]->define(punkt,angle);

    }
    cout<<"Dodano pojazdy."<<endl;
    return 0;


}
QList<Droga*> Plansza::podaj_drogi(){
    return drogi;
}
QList<Skrzyzowanie*> Plansza::podaj_skrzyzowania(){
    return skrzyzowania;
}
QList<Pojazd*> Plansza::podaj_pojazdy(){
    return pojazdy;
}

void Plansza::akt(){

    for(int i=0;i<pojazdy.length();i++){
        if(!pojazdy[i]->advance(podaj_pojazd(pojazdy[i]->podaj_pozycje(),pojazdy[i]->podaj_kat()),
                                podaj_droge(pojazdy[i]->podaj_pozycje(),pojazdy[i]->podaj_kat()),
                                podaj_skrz(pojazdy[i]->podaj_pozycje(),pojazdy[i]->podaj_kat()))) {
            pojazdy.removeAt(i);
            cout<<"Blad aktualizacji pojazdu. Usuwam pojazd."<<endl;
        }
    }
    for(int i=0;i<skrzyzowania.length();i++){
        skrzyzowania[i]->cykl();
    }
}
