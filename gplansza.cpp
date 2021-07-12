#include "gplansza.h"
#include <typeinfo>
#include <math.h>
#include <QtWidgets>

Gplansza::Gplansza()
{
}
int Gplansza::uruchom(Plansza* plansza, int argc, char **argv){
    QList<Droga*> drogi=plansza->podaj_drogi();
    QList<Pojazd*> pojazdy=plansza->podaj_pojazdy();
    QList<Skrzyzowanie*> skrzyzowania=plansza->podaj_skrzyzowania();
    QApplication app(argc,argv);
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(Qt::green);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Warszawa o poranku"));
    view.resize(650, 650);
    view.show();

    for (int i = 0; i < drogi.size(); ++i) {
        Gdroga *gdroga = new Gdroga(drogi[i]->podajPolozenie());
        gdrogi.append(gdroga);
        scene.addItem(gdroga);
    }
    for (int i = 0; i < skrzyzowania.size(); ++i) {
        Gskrzyzowanie *gskrz = new Gskrzyzowanie(skrzyzowania[i]->podajPolozenie(), skrzyzowania[i]);
        gskrzyzowania.append(gskrz);
        scene.addItem(gskrz);
    }

    for (int i = 0; i < pojazdy.size(); ++i) {
        Gpojazd *pojazd;
        if(pojazdy[i]->name()=="samochod") pojazd = new Gsamochod(pojazdy[i]);
        else pojazd = new Gkaretka(pojazdy[i]);
        gpojazdy.append(pojazd);
        scene.addItem(pojazd);

    }

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    QObject::connect(&timer, SIGNAL(timeout()), plansza, SLOT(akt()));
    timer.start(1000 / 33);
    return app.exec();
}
