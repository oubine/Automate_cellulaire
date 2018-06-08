#include <QApplication>
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
    Fenetre_AutoDim2_GOL* fendim2 = new Fenetre_AutoDim2_GOL(main);
    Fenetre_AutoDim2_Langton* fendim3 = new Fenetre_AutoDim2_Langton(main);


    std::cout << typeid(fendim1).name() << " , "<<typeid(fendim2).name() << " , "<<typeid(fendim3).name()<<"\n";
    main->show();
    //AutoCell autoc;
    //autoc.show();
    return app.exec();
}
