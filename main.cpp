#include <QApplication>
#include "main_UI.h"
#include "automate.h"

//On a mis des attributs de AutoCell en public pour pouvoir y accéder depuis Ui_MainWindow -> pas top
//Le num de AutoCell ne semble pas être le bon... -> problème de config ?
//Les transitions ne sont pas les bonnes -> ne correspondent qu'à deux automates différents

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *main = new QMainWindow;
    Ui_MainWindow* main_window = new Ui_MainWindow;
    main_window->setupUi(main);
    main->show();
    //AutoCell autoc;
    //autoc.show();
    return app.exec();
}
