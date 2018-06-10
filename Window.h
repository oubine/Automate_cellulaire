/**
 * \file Window.h
 * \brief Fichier d'en-tête des classes des fenêtres de simulation
 * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
 * \version 1.0
 * \date 16 Juin 2018
 *
 * Fichier d'en-tête déclarant les classes des fenêtres de simulation des automates implémentés dans l'application.
 *
 */

#ifndef Window_Simulation_Dim1_H
#define Window_Simulation_Dim1_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QGroupBox>
#include <QThread>
#include <iostream>
#include "automate2d.h"

/**
 * \class Window_Simulation
 * \brief Superclasse abstraite des fenêtres de simulation.
 *
 * Window_Simulation constitue le squelette des fenêtres de simulation. Les fenêtres correspondant aux classes implémentées hériteront de ce squelette.
 * Cette classe contient les boutons de l'affichage manuel (next et reset), ceux de l'affichage automatique (play, pause, reset), ainsi que tous les layout et une grille d'affichage.
 */

class Window_Simulation:public QWidget{

    Q_OBJECT
protected:

    /*!< Layout et widgets généraux. */

    QWidget *centralwidget;
    QVBoxLayout* couche;
    QHBoxLayout* layout_boutons;
    QVBoxLayout* layout_numero;
    QGroupBox* boutons;

    QTableWidget* etats;
    unsigned int dimension;
    QTableWidget* depart;
    unsigned int nb_transitions;


    //temps
    /*!< Boutons de gestion de la simulation */

    QPushButton* suivant;
    QPushButton* play;
    QPushButton* pause;
    QPushButton* raz;

    QLabel* transition;

    /*!< Variables de gestion de la simulation. */

    bool affichage_manuel;
    unsigned int temps_affichage;
    unsigned int taille;
    bool is_play_v;
    unsigned int transition_courante;


public:
    Window_Simulation(QWidget *parent,int dimension=20, int nb_transitions=20, bool aff=false, unsigned int temps=1, unsigned int taille=10, bool play=true):
        QWidget(parent),dimension(dimension), nb_transitions(nb_transitions), affichage_manuel(aff), temps_affichage(temps), taille(taille), is_play_v(play),transition_courante(0){}
    int getDimension() const {return dimension;}
    QTableWidget* getDepart() const {return depart;}
    void setEtatDepart(QTableWidget* dep){depart=dep;}
    void setDimension(unsigned int i){dimension=i;}
    void setNbTransitions(unsigned int i){dimension=i;}
    void setAffichage(bool b){affichage_manuel=b;}

signals:
    void is_play();
public slots:
    virtual void launchSimulationAuto()=0;
private slots :
    virtual void onSuivantButtonClicked()=0;
    virtual void onPlayButtonClicked()=0;
    virtual void onPauseButtonClicked()=0;
    virtual void onRazButtonClicked()=0;

};

/**
 * \class Window_Simulation_Dim1
 * \brief Classe de la fenêtre de simulation des automates à une dimension.
 *
 * Window_Simulation_Dim1 correspond à la classe de la fenêtre de simulation des automates à une dimension construite à partir du squelette de la classe abstraite Window_Simulation
 * Elle inclut en plus un numéro d'automate accompagné de ses getters et setters. Elle définit aussi les méthodes virtuelles pures de la classe abstraite.
 */

class Window_Simulation_Dim1 : public Window_Simulation{

    Q_OBJECT

    QLabel  *numero;
    int num_automate;

public:
    explicit Window_Simulation_Dim1(QWidget *parent);
    explicit Window_Simulation_Dim1(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, int num=0, bool aff=1, unsigned int tps_aff=500);
    QLabel* getNumLabel() const {return numero;}
    int getNumAutomate() const {return num_automate;}
    void setNumAutomate(int i){num_automate=i;}

signals:
    void is_play();
public slots:
    void launchSimulationAuto();
private slots :
    void onSuivantButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();
    void onRazButtonClicked();

};

/**
 * \class Window_Simulation_Dim2_GOL
 * \brief Classe de la fenêtre de simulation du Jeu de la Vie.
 *
 * Window_Simulation_Dim2_GOL correspond à la classe de la fenêtre de simulation du Jeu de la Vie construite à partir du squelette de la classe abstraite Window_Simulation.
 * Elle inclut en plus un vector correspondant à la règle définie par l'utilisateur, ainsi qu'un Etat2D correspondant à l'état de la transition en cours (pour des raisons d'optimisation). Elle définit aussi les méthodes virtuelles pures de la classe abstraite.
 */

class Window_Simulation_Dim2_GOL : public Window_Simulation{

    Q_OBJECT
    std::vector<short int> regle;

    Etat2D e;




public:
    explicit Window_Simulation_Dim2_GOL(QWidget* parent = nullptr);
    explicit Window_Simulation_Dim2_GOL(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, bool aff=1, unsigned int tps_aff=500, std::vector<short int> regle={0,0,1,2,0,0,0,0,0});

signals:
    void is_play();
public slots:
    void launchSimulationAuto();
private slots :
    void onSuivantButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();
    void onRazButtonClicked();

};

/**
 * \class Window_Simulation_Dim2_Langton
 * \brief Classe de la fenêtre de simulation de la Fourmi de Langton.
 *
 * Window_Simulation_Dim2_Langton correspond à la classe de la fenêtre de simulation de la Fourmi de Langton construite à partir du squelette de la classe abstraite Window_Simulation.
 * Elle inclue en plus un Etat2D correspondant à l'état de la transition en cours (pour des raisons d'optimisation). Elle définit aussi les méthodes virtuelles pures de la classe abstraite.
 */

class Window_Simulation_Dim2_Langton : public Window_Simulation{

    Q_OBJECT

    Etat2D e;



public:
    explicit Window_Simulation_Dim2_Langton(QWidget* parent = nullptr);
    explicit Window_Simulation_Dim2_Langton(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, bool aff=1, unsigned int tps_aff=500);

signals:
    void is_play();
public slots:
    void launchSimulationAuto();
private slots :
    void onSuivantButtonClicked();
    void onPlayButtonClicked();
    void onRazButtonClicked();
    void onPauseButtonClicked();
};

#endif // Window_Simulation_Dim1_H
