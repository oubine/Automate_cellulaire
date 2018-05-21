#include <QApplication>
#include "main_UI.h"
#include "automate.h"
#include <iostream>
#include "motif.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *main = new QMainWindow;

    Fenetre_AutoDim1* fendim1 = new Fenetre_AutoDim1(main);
    Fenetre_AutoDim2* fendim2 = new Fenetre_AutoDim2(main);
    main->show();
    //AutoCell autoc;
    //autoc.show();
    return app.exec();
}
