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

#ifndef WINDOW_DIM1_H
#define WINDOW_DIM1_H

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

class Window:public QWidget{

    Q_OBJECT
protected:
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
    QPushButton* suivant;
    QPushButton* play;
    QPushButton* pause;
    QPushButton* raz;

    QLabel* transition;
    bool affichage_manuel;
    unsigned int temps_affichage;
    unsigned int taille;
    bool is_play_v;
    unsigned int transition_courante;


public:
    Window(QWidget *parent,int dimension=20, int nb_transitions=20, bool aff=false, unsigned int temps=1, unsigned int taille=10, bool play=true):
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

class Window_Dim1 : public Window{

    Q_OBJECT

    QLabel  *numero;
    int num_automate;

public:
    explicit Window_Dim1(QWidget *parent);
    explicit Window_Dim1(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, int num=0, bool aff=1, unsigned int tps_aff=500);
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

class Window_Dim2_GOL : public Window{

    Q_OBJECT
    std::vector<short int> regle;

    Etat2D e;




public:
    explicit Window_Dim2_GOL(QWidget* parent = nullptr);
    explicit Window_Dim2_GOL(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, bool aff=1, unsigned int tps_aff=500, std::vector<short int> regle={0,0,1,2,0,0,0,0,0});

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

class Window_Dim2_Langton : public Window{

    Q_OBJECT

    std::vector<short int> regle;
    Etat2D e;



public:
    explicit Window_Dim2_Langton(QWidget* parent = nullptr);
    explicit Window_Dim2_Langton(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, bool aff=1, unsigned int tps_aff=500);

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

#endif // WINDOW_DIM1_H
