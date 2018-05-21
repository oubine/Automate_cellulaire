#include "autocell.h"
#include "automate.h"
#include "automatemanager.h"
#include "simulateur.h"
#include "main_UI.h"
#include <iostream>

AutoCell::AutoCell(QWidget *parent) : QWidget(parent),taille(10) {
    // Question 3
    //numero = new QLabel(QString::number(num_automate),this);
    depart = new QTableWidget(1, dimension);
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        depart->setColumnWidth(counter, taille);
        depart->setItem(0, counter, new QTableWidgetItem(""));
        depart->item(0, counter)->setBackgroundColor("white");//vide donc couleur = blanc
        depart->item(0, counter)->setTextColor("white");//idem, on ne veut pas voir le texte à l'intérieur (même pas besoin car c'est une chaîne vide)
    }

    couche = new QVBoxLayout;//Nouvelle box pour l'affichage des étapes de l'automate
    //couche->addWidget(numero);
    etats = new QTableWidget(dimension, dimension, this);//création du tableau
    etats->setFixedSize(dimension*taille, dimension*taille);//dimensions du tableau
    etats->horizontalHeader()->setVisible(false);//on enlève la numérotation horizontale des cases
    etats->verticalHeader()->setVisible(false);//on enlève la numérotation verticale des cases
    etats->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//on enlève la scroll barre verticale
    etats->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//on enlève la scroll barre horizontale
    etats->setEditTriggers(QAbstractItemView::NoEditTriggers); // désactive la modification des états par l'utilisateur
    // on va créer les items, on utilise 2 boucles car on parcourt un tableau 2 dimensions
    for(unsigned int ligne = 0; ligne < dimension; ++ligne) {
        // fixe les dimensions des lignes et des colonnes
        etats->setColumnWidth(ligne, taille);
        etats->setRowHeight(ligne, taille);
        for(unsigned int colonne = 0; colonne < dimension; ++colonne) {//on initialise toutes les cellules à l'état mort
            etats->setItem(ligne, colonne, new QTableWidgetItem(""));//symbole choisi pour représenter une cellule morte
            etats->item(ligne, colonne)->setBackgroundColor("white");//la cellule est morte, donc blanche
            etats->item(ligne, colonne)->setTextColor("white");//idem pour le texte, comme pour les cellules de départ
        }
    }
    //couche->addWidget(numero);
    couche->addWidget(etats);//on ajoute le tableau à l interface
    setLayout(couche);//on définit l'environnement global
}

AutoCell::AutoCell(QWidget *parent, unsigned int dim, unsigned int transitions, int num, bool aff, unsigned int tps_aff) :
    QWidget(parent), dimension(dim), num_automate(num), nb_transitions(transitions), affichage_manuel(aff), temps_affichage(tps_aff),taille(20) {
    // Question 3
    couche = new QVBoxLayout;//Nouvelle box pour l'affichage des étapes de l'automate
    layout_boutons=new QHBoxLayout;
    numero = new QLabel(QString::fromUtf8("Numéro : ").append(QString::number(num_automate)),this);
    layout_numero=new QVBoxLayout;
    layout_numero->setAlignment(Qt::AlignLeft);
    layout_numero->addWidget(numero);
    transition=new QLabel(QString::fromUtf8("Transition courante : ").append(QString::number(transition_courante)).append(QString::fromUtf8(" sur ")).append(QString::number(nb_transitions)),this);
    layout_numero->addWidget(transition);
    layout_boutons->addLayout(layout_numero);
    if(affichage_manuel)
    {
        suivant = new QPushButton;
        suivant->setObjectName(QString::fromUtf8("suivant"));
        suivant->setMinimumSize(QSize(0, 15));
        suivant->setMaximumSize(QSize(50, 15));
        suivant->setText(QApplication::translate("AutoCell LO21", "Next", 0));
        layout_boutons->addWidget(suivant);
        connect(suivant, SIGNAL(clicked()), this, SLOT(onSuivantButtonClicked()));
    }
    else
    {
        play = new QPushButton;
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(0, 20));
        play->setMaximumSize(QSize(20, 20));
        play->setFlat(true);
        QPixmap pixmap("play.png");
        QIcon ButtonIcon(pixmap);
        play->setIcon(ButtonIcon);
        play->setIconSize(pixmap.rect().size());
        layout_boutons->addWidget(play);

        pause = new QPushButton;
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setMinimumSize(QSize(0, 20));
        pause->setMaximumSize(QSize(20, 20));
        pause->setFlat(true);
        QPixmap pixmap2("pause.png");
        QIcon ButtonIcon2(pixmap2);
        pause->setIcon(ButtonIcon2);
        pause->setIconSize(pixmap2.rect().size());
        layout_boutons->addWidget(pause);

        connect(pause, SIGNAL(clicked()), this, SLOT(onPauseButtonClicked()));
        connect(play, SIGNAL(clicked()), this, SLOT(onPlayButtonClicked()));
    }



    //layout_boutons->setAlignment(Qt::AlignRight);
    depart = new QTableWidget(1, dimension);
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        depart->setColumnWidth(counter, taille);
        depart->setItem(0, counter, new QTableWidgetItem(""));
        depart->item(0, counter)->setBackgroundColor("white");//vide donc couleur = blanc
        depart->item(0, counter)->setTextColor("white");//idem, on ne veut pas voir le texte à l'intérieur (même pas besoin car c'est une chaîne vide)
    }
    couche->addLayout(layout_boutons);
    etats = new QTableWidget(nb_transitions, dimension, this);//création du tableau
    etats->setFixedSize(dimension*taille, nb_transitions*taille);//dimensions du tableau
    etats->horizontalHeader()->setVisible(false);//on enlève la numérotation horizontale des cases
    etats->verticalHeader()->setVisible(false);//on enlève la numérotation verticale des cases
    etats->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//on enlève la scroll barre verticale
    etats->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//on enlève la scroll barre horizontale
    etats->setEditTriggers(QAbstractItemView::NoEditTriggers); // désactive la modification des états par l'utilisateur
    // set the default size, here i've set it to 20px by 20x
    etats->horizontalHeader()->setDefaultSectionSize(taille);
    etats->verticalHeader()->setDefaultSectionSize(taille);
    // set the resize mode to fixed, so the user cannot change the height/width
    //etats->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    //etats->verticalHeader()->setResizeMode(QHeaderView::Fixed);
    // on va créer les items, on utilise 2 boucles car on parcourt un tableau 2 dimensions
    for(unsigned int ligne = 0; ligne < nb_transitions; ++ligne) {
        // fixe les dimensions des lignes et des colonnes
        for(unsigned int colonne = 0; colonne < dimension; ++colonne) {//on initialise toutes les cellules à l'état mort
            etats->setItem(ligne, colonne, new QTableWidgetItem(""));//symbole choisi pour représenter une cellule morte
            etats->item(ligne, colonne)->setBackgroundColor("white");//la cellule est morte, donc blanche
            etats->item(ligne, colonne)->setTextColor("white");//idem pour le texte, comme pour les cellules de départ
        }
    }
    couche->addWidget(etats);//on ajoute le tableau à l interface
    setLayout(couche);//on définit l'environnement global
}

//Ici, on entre dans la partie logique pour faire fonctionner l'automate

void AutoCell::launchSimulation() {//méthode pour lancer la simulation
    // création de l'état
    Etat1D e(dimension,1);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        if(depart->item(0, counter)->text() != "") {
                e.setCellule(counter, true);
        }
    }
    // on récupère l'automate correspondant au numéro de l'interface graphique, en utilisant l'AutomateManager
    // à noter, il n'est pas nécessaire d'instancier un objet AutomateManager, comme il s'agit d'un singleton,
    // on peut considérer que l'objet existe déjà dans le système
    Automate1D& a = AutomateManager::getAutomateManager().getAutomate(num_automate);
    // on construit l'objet simulateur correspondant
    Simulateur sim(a, e, dimension);
    // on applique les transitions au simulateur en affichant le résultat dans l'interface graphique
    for(unsigned int step = 0; step < nb_transitions; ++step) {
        // on applique la transition
        sim.next();
        // on récupère le dernier état
        const Etat1D& etat = sim.dernier();
        // on l'affiche
        for(unsigned int colonne = 0; colonne < dimension; ++colonne) {
            if (etat.getCellule(colonne) == true) {
                etats->item(step, colonne)->setText("_");
                etats->item(step, colonne)->setBackgroundColor("black");
                etats->item(step, colonne)->setTextColor("black");
            } else {
                etats->item(step, colonne)->setText("");
                etats->item(step, colonne)->setBackgroundColor("white");
                etats->item(step, colonne)->setTextColor("white");
            }
        }
    }
}

void AutoCell::onSuivantButtonClicked()
{
    // création de l'état
    Etat1D e(dimension,1);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        if(depart->item(0, counter)->text() != "") {
                e.setCellule(counter, 1);
        }
        else e.setCellule(counter, 0);
    }
    // on récupère l'automate correspondant au numéro de l'interface graphique, en utilisant l'AutomateManager
    // à noter, il n'est pas nécessaire d'instancier un objet AutomateManager, comme il s'agit d'un singleton,
    // on peut considérer que l'objet existe déjà dans le système
    Automate1D& a = AutomateManager::getAutomateManager().getAutomate(num_automate);
    // on construit l'objet simulateur correspondant
    Simulateur sim(a, e, dimension);
    if(transition_courante<nb_transitions)
    {
        transition_courante++;

        // on applique les transitions au simulateur en affichant le résultat dans l'interface graphique
        for(unsigned int step = 0; step < transition_courante; ++step) {
            // on applique la transition
            sim.next();
            // on récupère le dernier état
            const Etat1D& etat = sim.dernier();
            // on l'affiche
            for(unsigned int colonne = 0; colonne < dimension; ++colonne) {
                if (etat.getCellule(colonne) == true) {
                    etats->item(step, colonne)->setText("_");
                    etats->item(step, colonne)->setBackgroundColor("black");
                    etats->item(step, colonne)->setTextColor("black");
                } else {
                    etats->item(step, colonne)->setText("");
                    etats->item(step, colonne)->setBackgroundColor("white");
                    etats->item(step, colonne)->setTextColor("white");
                }
            }
        }
        transition->setText(QApplication::translate("AutoCell LO21", QString::fromUtf8("Transition courante : ").append(QString::number(transition_courante)).append(QString::fromUtf8(" sur ")).append(QString::number(nb_transitions)).toStdString().c_str(), 0));
    }
    }

void AutoCell::launchSimulationAuto() {//méthode pour lancer la simulation
    //on doit appuyer sur play pour lancer l'éxécution
    //QEventLoop loop;
    //connect(this,SIGNAL(is_play()), &loop, SLOT(quit()));
    //loop.exec();

    // création de l'état
    Etat1D e(dimension,1);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        if(depart->item(0, counter)->text() != "") {
                e.setCellule(counter, true);
        }
    }
    // on récupère l'automate correspondant au numéro de l'interface graphique, en utilisant l'AutomateManager
    // à noter, il n'est pas nécessaire d'instancier un objet AutomateManager, comme il s'agit d'un singleton,
    // on peut considérer que l'objet existe déjà dans le système
    Automate1D& a = AutomateManager::getAutomateManager().getAutomate(num_automate);
    // on construit l'objet simulateur correspondant
    Simulateur sim(a, e, dimension);
    // on applique les transitions au simulateur en affichant le résultat dans l'interface graphique
    QEventLoop loop2;
    connect(this,SIGNAL(is_play()), &loop2, SLOT(quit()));

    for(unsigned int step = 0; step < nb_transitions; ++step) {
        if(!is_play_v)
        {
            loop2.exec();//si on est sur pause, on attend de réappuyer sur play pour continuer l'exécution
        }
        transition_courante++;
        transition->setText(QApplication::translate("AutoCell LO21", QString::fromUtf8("Transition courante : ").append(QString::number(transition_courante)).append(QString::fromUtf8(" sur ")).append(QString::number(nb_transitions)).toStdString().c_str(), 0));
        // on récupère le dernier état
        sim.next();
        const Etat1D& etat = sim.dernier();
        // on l'affiche
        for(unsigned int colonne = 0; colonne < dimension; ++colonne) {
            if (etat.getCellule(colonne) == true) {
                etats->item(step, colonne)->setText("_");
                etats->item(step, colonne)->setBackgroundColor("black");
                etats->item(step, colonne)->setTextColor("black");
            } else {
                etats->item(step, colonne)->setText("");
                etats->item(step, colonne)->setBackgroundColor("white");
                etats->item(step, colonne)->setTextColor("white");
            }
            QCoreApplication::processEvents();
        }
        for(unsigned int counter=0; counter<temps_affichage/4; counter++)//ça c'est de la bidouille pour actualiser pause/play plus souvent
        {
            QThread::msleep(4);
            QCoreApplication::processEvents();
        }
    }
}

void AutoCell::onPlayButtonClicked()
{
    is_play_v=true;
    emit is_play();
}

void AutoCell::onPauseButtonClicked()
{
    is_play_v=false;
}
