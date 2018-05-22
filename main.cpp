#include <QApplication>
#include "main_UI.h"
#include "automate.h"
#include "automate2d.h"
#include <iostream>
#include "motif.h"
#include "etat.h"
#include "index.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *main = new QMainWindow;

    Etat2D e(20,1);
    e.setCellule(IndexTab2D(0,2,20,20),1);
    e.setCellule(IndexTab2D(1,2,20,20),1);
    e.setCellule(IndexTab2D(2,2,20,20),1);
    e.setCellule(IndexTab2D(2,1,20,20),1);
    e.setCellule(IndexTab2D(1,0,20,20),1);
    VarianteJeuDeLaVie a({0,0,1,2,0,0,0,0,0});
    std::cout<<e<<"\n";
    Etat2D e2(20,1);
    for(int i = 0; i < 50; i ++)
    {
        a.appliquerTransition(e,e2);
        e = e2;
        std::cout<<e<<"\n";
    }


    Fenetre_AutoDim1* fendim1 = new Fenetre_AutoDim1(main);
    Fenetre_AutoDim2* fendim2 = new Fenetre_AutoDim2(main);
    main->show();
    //AutoCell autoc;
    //autoc.show();
    return app.exec();
}
