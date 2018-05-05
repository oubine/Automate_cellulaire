#include "autocell.h"
#include "automate_dim1.h"
#include "main_UI.h"

AutoCell::AutoCell(QWidget *parent) : QWidget(parent) {
    // Question 3
    unsigned int taille = 27; //pixels de l'état de départ
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

AutoCell::AutoCell(QWidget *parent, unsigned int dim, unsigned int transitions) : QWidget(parent), dimension(dim), nb_transitions(transitions) {
    // Question 3
    unsigned int taille = 20; //pixels de l'état de départ
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
    etats = new QTableWidget(nb_transitions, dimension, this);//création du tableau
    etats->setFixedSize(dimension*taille, nb_transitions*taille);//dimensions du tableau
    etats->horizontalHeader()->setVisible(false);//on enlève la numérotation horizontale des cases
    etats->verticalHeader()->setVisible(false);//on enlève la numérotation verticale des cases
    etats->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//on enlève la scroll barre verticale
    etats->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//on enlève la scroll barre horizontale
    etats->setEditTriggers(QAbstractItemView::NoEditTriggers); // désactive la modification des états par l'utilisateur
    // set the default size, here i've set it to 20px by 20x
    etats->horizontalHeader()->setDefaultSectionSize(20);
    etats->verticalHeader()->setDefaultSectionSize(20);
    // set the resize mode to fixed, so the user cannot change the height/width
    //etats->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    //etats->verticalHeader()->setResizeMode(QHeaderView::Fixed);
    // on va créer les items, on utilise 2 boucles car on parcourt un tableau 2 dimensions
    for(unsigned int ligne = 0; ligne < nb_transitions; ++ligne) {
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

//Ici, on entre dans la partie logique pour faire fonctionner l'automate

void AutoCell::launchSimulation() {//méthode pour lancer la simulation
    // création de l'état
    Etat e(dimension);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        if(depart->item(0, counter)->text() != "") {
                e.setCellule(counter, true);
        }
    }
    // on récupère l'automate correspondant au numéro de l'interface graphique, en utilisant l'AutomateManager
    // à noter, il n'est pas nécessaire d'instancier un objet AutomateManager, comme il s'agit d'un singleton,
    // on peut considérer que l'objet existe déjà dans le système
    const Automate& a = AutomateManager::getAutomateManager().getAutomate(num_automate);
    // on construit l'objet simulateur correspondant
    Simulateur sim(a, e, dimension);
    // on applique les transitions au simulateur en affichant le résultat dans l'interface graphique
    for(unsigned int step = 0; step < nb_transitions; ++step) {
        // on applique la transition
        sim.next();
        // on récupère le dernier état
        const Etat& etat = sim.dernier();
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
