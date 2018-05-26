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
    Fenetre_AutoDim2* fendim2 = new Fenetre_AutoDim2(main);
    /*Etat2D e(100,1);
    for(unsigned int i = 0; i < 100; ++i) {
        for(unsigned int j=0; j<100; ++j){
            e.setCellule(IndexTab2D(i,j,100,100), rand()%2);}}
    VarianteJeuDeLaVie a({0,0,1,2,0,0,0,0,0});
    Etat2D e2(100,1);
    for(unsigned int i = 0; i < 100; i++)
    {
        a.appliquerTransition(e,e2);
        e = e2;
    }
*/
    std::cout << typeid(fendim1).name() << " , "<<typeid(fendim2).name()<<"\n";
    main->show();
    //AutoCell autoc;
    //autoc.show();
    return app.exec();
}
