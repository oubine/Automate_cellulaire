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

class Window_Dim1 : public QWidget{
Q_OBJECT
    QWidget *centralwidget;
    QVBoxLayout* couche;
    QHBoxLayout* layout_boutons;
    QVBoxLayout* layout_numero;
    QGroupBox* boutons;

    QTableWidget* etats;
    unsigned int dimension;
    QLabel  *numero;
    QTableWidget* depart;
    int num_automate;
    unsigned int nb_transitions;


    //temps
    QPushButton* suivant;
    QPushButton* play;
    QPushButton* pause;
    QLabel* transition;
    bool affichage_manuel;
    unsigned int temps_affichage;
    unsigned int taille;
    bool is_play_v;
    unsigned int transition_courante;


public:
    explicit Window_Dim1(QWidget* parent = nullptr);
    explicit Window_Dim1(QWidget* parent = nullptr, unsigned int taille=1, unsigned int transitions=1, int num=0, bool aff=1, unsigned int tps_aff=500);
    int getDimension() const {return dimension;}
    QLabel* getNumLabel() const {return numero;}
    QTableWidget* getDepart() const {return depart;}
    int getNumAutomate() const {return num_automate;}
    void setNumAutomate(int i){num_automate=i;}
    void setEtatDepart(QTableWidget* dep){depart=dep;}
    void setDimension(unsigned int i){dimension=i;}
    void setNbTransitions(unsigned int i){dimension=i;}
    void setAffichage(bool b){affichage_manuel=b;}

signals:
    void is_play();
public slots:
    void launchSimulationAuto();
private slots :
    void onSuivantButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();
};

class Window_Dim2 : public QWidget{
Q_OBJECT
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
    QLabel* transition;
    bool affichage_manuel;
    unsigned int temps_affichage;
    unsigned int taille;
    std::vector<short int> regle;

    bool is_play_v;
    unsigned int transition_courante;



public:
    explicit Window_Dim2(QWidget* parent = nullptr);
    explicit Window_Dim2(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, bool aff=1, unsigned int tps_aff=500, std::vector<short int> regle={0,0,1,2,0,0,0,0,0});
    int getDimension() const {return dimension;}
    QTableWidget* getDepart() const {return depart;}
    void setEtatDepart(QTableWidget* dep){depart=dep;}
    void setDimension(unsigned int i){dimension=i;}
    void setNbTransitions(unsigned int i){dimension=i;}
    void setAffichage(bool b){affichage_manuel=b;}

signals:
    void is_play();
public slots:
    void launchSimulationAuto();
private slots :
    void onSuivantButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();
};

class Window_Dim2_Langton : public QWidget{
Q_OBJECT
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
    QLabel* transition;
    bool affichage_manuel;
    unsigned int temps_affichage;

    std::vector<short int> regle;
    unsigned int taille;
    Etat2D e;
    bool is_play_v;


    unsigned int transition_courante;




public:
    explicit Window_Dim2_Langton(QWidget* parent = nullptr);
    explicit Window_Dim2_Langton(QWidget* parent = nullptr, unsigned int taille=10, unsigned int transitions=1, bool aff=1, unsigned int tps_aff=500);
    int getDimension() const {return dimension;}
    QTableWidget* getDepart() const {return depart;}
    void setEtatDepart(QTableWidget* dep){depart=dep;}
    void setDimension(unsigned int i){dimension=i;}
    void setNbTransitions(unsigned int i){dimension=i;}
    void setAffichage(bool b){affichage_manuel=b;}

signals:
    void is_play();
public slots:
    void launchSimulationAuto();
private slots :
    void onSuivantButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();
};

#endif // WINDOW_DIM1_H
