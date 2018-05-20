#include <QApplication>
#include "main_UI.h"
#include "automate.h"
#include <iostream>
#include "motif.h"

int main(int argc, char *argv[])
{
    /*
    Motif m;
    Index2D* i = new Index2D(3,4);
    Index2D* j = new Index2D(-3,4);
    Index2D* k = new Index2D(0,2);
    m.ajouterVoisin(i);
    m.ajouterVoisin(j);
    m.ajouterVoisin(k);
    std::cout << m;
    */
    QApplication app(argc, argv);
    QMainWindow *main = new QMainWindow;
    Fenetre_AutoDim1* fendim1 = new Fenetre_AutoDim1(main);
    Fenetre_AutoDim2* fendim2 = new Fenetre_AutoDim2(main);
    main->show();
    //AutoCell autoc;
    //autoc.show();
    return app.exec();
}
