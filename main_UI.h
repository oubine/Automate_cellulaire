#ifndef PROJET_LO21
#define PROJET_LO21
#include "Window.h"
#define MAX_CASES 500
#define MAX_TRANSITIONS 300

#define MAX_CASES_DIM2 200
#define MAX_TRANSITIONS_DIM2 100000

#include <QWidget>
#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QRadioButton>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileDialog>
#include <QtXml>
#include <QMessageBox>
#include <QComboBox>
#include <cstdlib>

QT_BEGIN_NAMESPACE

//On a fait cette implémentation car l'héritage virtual ne fonctionne pas avec Q_Object.
//Pour ajouter un nouvel automate :
// - faire la classe correpondant à la nouvelle fenêtre de l'automate
// - redéfinir les méthodes !!! en prenant en compte les automates déjà implantés (différencier les pages avec des if)
// - ajouter des générateurs si besoin et les gérer avec set_Gen_options
// - définir le comportement de Enregistrer et Importer !!! en prenant en compte les automates déjà implantés (différencier les pages avec des if)


class Fenetre_Principale : public QObject
{
    Q_OBJECT
    //général
protected:
    QStatusBar *statusbar;
    QWidget *centralwidget;
    QVBoxLayout *layout_main;

    QGroupBox *reglages_generaux;
    QHBoxLayout *layout_reglages_generaux;

    QGroupBox *type_automate;
    QVBoxLayout *layout_type_automate;
    QListWidget *select_type_automate;
    QStackedWidget *stacked_settings;

    //enregistrement
    QAction *actionEnregistrer;
    QAction *actionImporter;
    QMenuBar *menubar;
    QMenu *menuR_glages_de_l_automate_cellulaire;
    QFileDialog* fichier;

    //réglage de l'affichage
    QGroupBox *Affichage;
    QFormLayout *layout_affichage;
    QRadioButton *aff_manuel;
    QRadioButton *aff_auto;
    QStackedWidget *Temps;
    QWidget *page_aff_auto;
    QVBoxLayout *layout_aff_auto;
    QHBoxLayout *temps_aff;
    QDoubleSpinBox *aff_temps_n;
    QLabel *unite_temps_aff;
    QWidget *page_aff_man;

public:
    Fenetre_Principale(QMainWindow *MainWindow);
    virtual void Noms(QMainWindow *MainWindow);

    void Gen_aleatoire();//on a choisi un remplissage aléatoire mais pas une taille aléatoire
    void Gen_Un_Sur_Deux();

private slots :
    virtual void onDimensionItemClicked(QListWidgetItem* item)=0;
    virtual void onAffichageButtonClicked(bool);
    virtual void onActionEnregistrer()=0;
    virtual void onActionImporter()=0;
};

class Fenetre_AutoDim1 : public Fenetre_Principale
{
    Q_OBJECT
protected:

    //automate de dimension 1
    QVBoxLayout* couche;

    QWidget *page_dim1;
    QVBoxLayout *layout_page_dim1;
    QGroupBox *configuration_dim1;
    QVBoxLayout *layout_etat_depart;

    QHBoxLayout *regles_dim1;
    QGroupBox *regles_transition;
    QHBoxLayout *regles_dim1_layout;
    QSpinBox* num;
    QLineEdit* numeroBit[8];
    QLabel* numl;
    QLabel* numeroBitl[8];
    QVBoxLayout* numc;
    QVBoxLayout* bitc[8];
    QHBoxLayout* numeroc;
    QIntValidator* zeroOneValidator;
    unsigned int dimension;

    QGroupBox *generateur;
    QComboBox* select_generateur;
    QLabel* select_generateur_l;
    QHBoxLayout* layout_select_generateur;
    QVBoxLayout* layout_generateur;
    QHBoxLayout* layout_cases;
    QSpinBox* nb_cases;
    QLabel* nb_cases_l;
    QHBoxLayout* layout_transitions;
    QSpinBox* nb_transitions;
    QLabel* nb_transitions_l;
    QPushButton* bouton_generateur;

    QStackedWidget* stacked_etat_depart;
    unsigned int taille=25;//taille des cases du tableau en pixels
    QWidget* page_etat_0;
    QWidget* page_etat_1;
    QLabel *etat_depart_l;
    QVBoxLayout* layout_page_etat_0;
    QVBoxLayout* layout_page_etat_1;
    QTableWidget *etat_depart_table;
    QLabel* aucun_etat_depart;

    QPushButton *Simulation;

    //enregistrement
    bool enregistrer_autodim1=0;

    Window_Dim1 *new_Window_dim1;
public :
    Fenetre_AutoDim1(QMainWindow *MainWindow);
    void Gen_aleatoire();//on a choisi un remplissage aléatoire mais pas une taille aléatoire
    void Gen_Un_Sur_Deux();
    void Noms(QMainWindow *MainWindow);


private slots :
    void onDimensionItemClicked(QListWidgetItem*);
    virtual void onGenerateurButtonClicked();
    virtual void onSimulationButtonClicked();
    void synchronizeNumToNumBit(int i);
    void synchronizeNumBitToNum(const QString& s);
    void cellActivation_dim1(QTableWidgetItem* index);
    void onActionEnregistrer();
    void onActionImporter();
};

class Fenetre_AutoDim2 : protected Fenetre_AutoDim1
{
    Q_OBJECT
protected:
    //automate de dimension 2
    QWidget *page_dim2;
    QVBoxLayout *layout_page_dim2;
    QGroupBox *configuration_dim2;
    QVBoxLayout *layout_config_dim2;
    QVBoxLayout *layout_etat_depart_dim2;


    QHBoxLayout *regles_dim2;
    QGroupBox *regles_transition_dim2;
    QGridLayout *gridLayout;
    QLabel* voisins[8];
    QLabel *regles_creation_l;
    QLabel *voisins_n_l;
    QLabel *regles_mort_l;
    QCheckBox *vie[8];
    QCheckBox *mort[8];

    QGroupBox *generateur_dim2;
    QComboBox* select_generateur_dim2;
    QLabel* select_generateur_dim2_l;
    QHBoxLayout* layout_select_generateur_dim2;
    QVBoxLayout* layout_generateur_dim2;
    QHBoxLayout* layout_cases_dim2;
    QSpinBox* nb_cases_dim2;
    QLabel* nb_cases_l_dim2;
    QHBoxLayout* layout_transitions_dim2;
    QSpinBox* nb_transitions_dim2;
    QLabel* nb_transitions_l_dim2;
    QPushButton* bouton_generateur_dim2;
    unsigned int dimension_dim2;

    QStackedWidget* stacked_etat_depart_dim2;
    unsigned int taille_dim2=25;//taille des cases du tableau en pixels
    QWidget* page_etat_0_dim2;
    QWidget* page_etat_1_dim2;
    QLabel *etat_depart_l_dim2;
    QVBoxLayout* layout_page_etat_0_dim2;
    QVBoxLayout* layout_page_etat_1_dim2;
    QTableWidget *etat_depart_table_dim2;
    QLabel* aucun_etat_depart_dim2;

    QPushButton *Simulation_dim2;
    //enregistrement
    bool enregistrer_autodim2=0;

    Window_Dim2* new_Window_dim2;

public:
    void Noms(QMainWindow *MainWindow);
    Fenetre_AutoDim2(QMainWindow *MainWindow);
    void Gen_aleatoire_dim2();//on a choisi un remplissage aléatoire mais pas une taille aléatoire
    void Gen_Un_Sur_Deux_dim2();
private slots :
    void onDimensionItemClicked(QListWidgetItem*) override;
    void onGenerateurButtonClicked() override;
    void onSimulationButtonClicked() override;
    void cellActivation_dim2(QTableWidgetItem* index);
    void onActionEnregistrer() override;
    void onActionImporter() override;
};

class Fenetre_AutoDim2_Langton : protected Fenetre_AutoDim2
{
    Q_OBJECT

protected:
    //automate fourmi de Langton
    QWidget *page_langton;
    QVBoxLayout *layout_page_langton;
    QGroupBox *configuration_langton;
    QVBoxLayout *layout_config_langton;
    QVBoxLayout *layout_etat_depart_langton;


    QHBoxLayout *regles_langton;

    QGroupBox *generateur_langton;
    QComboBox* select_generateur_langton;
    QLabel* select_generateur_langton_l;
    QHBoxLayout* layout_select_generateur_langton;
    QVBoxLayout* layout_generateur_langton;
    QHBoxLayout* layout_cases_langton;
    QSpinBox* nb_cases_langton;
    QLabel* nb_cases_l_langton;
    QHBoxLayout* layout_transitions_langton;
    QSpinBox* nb_transitions_langton;
    QLabel* nb_transitions_l_langton;
    QPushButton* bouton_generateur_langton;
    unsigned int dimension_langton;

    QStackedWidget* stacked_etat_depart_langton;
    unsigned int taille_langton=25;//taille des cases du tableau en pixels
    QWidget* page_etat_0_langton;
    QWidget* page_etat_1_langton;
    QLabel *etat_depart_l_langton;
    QVBoxLayout* layout_page_etat_0_langton;
    QVBoxLayout* layout_page_etat_1_langton;
    QTableWidget *etat_depart_table_langton;
    QLabel* aucun_etat_depart_langton;

    QPushButton *Simulation_langton;
    //enregistrement
    bool enregistrer_autolangton=0;

    Window_Dim2_Langton* new_Window_langton;

public:
    void Noms(QMainWindow *MainWindow);
    Fenetre_AutoDim2_Langton(QMainWindow *MainWindow);
    void Gen_aleatoire_langton();//on a choisi un remplissage aléatoire mais pas une taille aléatoire
private slots :
    void onDimensionItemClicked(QListWidgetItem*) override;
    void onGenerateurButtonClicked() override;
    void onSimulationButtonClicked() override;
    void cellActivation_Langton(QTableWidgetItem* index);
    void onActionEnregistrer() override;
    void onActionImporter() override;
};

namespace Ui {
    //class MainWindow: public Fenetre_Principale {};
}
QT_END_NAMESPACE

#endif
