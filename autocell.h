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

class AutoCell : public QWidget{
Q_OBJECT
    QWidget *centralwidget;
    QVBoxLayout* couche;
    QHBoxLayout* layout_boutons;
    QVBoxLayout* layout_numero;
    QGroupBox* boutons;
    // Question 3
    QTableWidget* etats;
    unsigned int dimension;
    QLabel  *numero;
    QTableWidget* depart;
    int num_automate;
    unsigned int nb_transitions;
    unsigned int transition_courante=0;

    //temps
    QPushButton* suivant;
    QPushButton* play;
    QPushButton* pause;
    QLabel* transition;
    bool affichage_manuel;
    unsigned int temps_affichage;
    bool is_play_v=1;
public:
    explicit AutoCell(QWidget* parent = nullptr);
    explicit AutoCell(QWidget* parent = nullptr, unsigned int dim=1, unsigned int transitions=1, int num=0, bool aff=1, unsigned int tps_aff=500);
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
    void launchSimulation();
    void launchSimulationAuto();
private slots :
    void onSuivantButtonClicked();
    void onPlayButtonClicked();
    void onPauseButtonClicked();
};

#endif // WINDOW_DIM1_H
