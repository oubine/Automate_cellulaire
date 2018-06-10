#include <QApplication>
#include <QWidget>
#include "main_UI.h"
#include "automate.h"
#include "automate2d.h"
#include <iostream>
#include <typeinfo>
#include "motif.h"
#include "etat.h"
#include "index.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *main = new QMainWindow;
    Fenetre_AutoDim1* fendim1 = new Fenetre_AutoDim1(main);
    Fenetre_AutoDim2_GOL* fenGOT = new Fenetre_AutoDim2_GOL(main);
    Fenetre_AutoDim2_Langton* fen_Langton = new Fenetre_AutoDim2_Langton(main);
    QObject::connect(qApp, SIGNAL(aboutToQuit()), fen_Langton, SLOT(writeSettings()));
    fen_Langton->readSettings();
    std::cout << typeid(fendim1).name() << " , "<<typeid(fenGOT).name()<<"\n"<<typeid(fen_Langton).name()<<std::endl;
    main->show();
    //AutoCell autoc;
    //autoc.show();
    return app.exec();
}
