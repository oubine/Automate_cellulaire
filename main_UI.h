/********************************************************************************
** Form generated from reading UI file 'Projet_LO21_2U14026.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PROJET_LO21_2U14026_H
#define PROJET_LO21_2U14026_H
#include "autocell.h"

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

class Ui_MainWindow : public QObject
{
    Q_OBJECT
    AutoCell *new_Window_dim1;
public:
    //général

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
    unsigned int taille=26;//taille des cases du tableau en pixels
    QWidget* page_etat_0;
    QWidget* page_etat_1;
    QLabel *etat_depart_l;
    QVBoxLayout* layout_page_etat_0;
    QVBoxLayout* layout_page_etat_1;
    QTableWidget *etat_depart_table;
    QLabel* aucun_etat_depart;

    QPushButton *Simulation;

    //automate de dimension 2
    QWidget *page_dim2;
    QVBoxLayout *layout_page_dim2;
    QGroupBox *configuration_dim2;
    QHBoxLayout *layout_config_dim2;

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

    QPushButton *Simulation_dim2;


    void setupUi(QMainWindow *MainWindow);
    void retranslateUi(QMainWindow *MainWindow);

    void Gen_aleatoire();
    void Gen_Un_Sur_Deux();

private slots :
    void onDimensionItemClicked(QListWidgetItem* item);
    void onAffichageButtonClicked(bool);
    void onGenerateurButtonClicked();
    void onSimulationButtonClicked();
    void synchronizeNumToNumBit(int i);
    void synchronizeNumBitToNum(const QString& s);
    void cellActivation(QTableWidgetItem* index);
    void onActionEnregistrer();
    void onActionImporter();
    void set_Gen_options(QString);
};


namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PROJET_LO21_2U14026_H
