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

QT_BEGIN_NAMESPACE

class Ui_MainWindow : public QObject
{
    Q_OBJECT
    AutoCell *new_Window_dim1;
public:
    QAction *actionEnregistrer;
    QAction *actionImporter;
    QWidget *centralwidget;
    QVBoxLayout *layout_main;
    QGroupBox *reglages_generaux;
    QHBoxLayout *layout_reglages_generaux;
    QGroupBox *type_automate;
    QVBoxLayout *layout_type_automate;
    QListWidget *select_type_automate;
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
    QStackedWidget *stacked_settings;
    QWidget *page_dim1;
    QVBoxLayout *layout_page_dim1;
    QGroupBox *configuration_dim1;
    QVBoxLayout *layout_etat_depart;
    QHBoxLayout *regles_dim1;
    QGroupBox *regles_transition;
    QHBoxLayout *regles_dim1_layout;
    QGroupBox *generateur;
    QLabel *etat_depart_l;
    QTableWidget *etat_depart_table;
    QPushButton *Simulation;
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
    QPushButton *Simulation_4;
    QMenuBar *menubar;
    QMenu *menuR_glages_de_l_automate_cellulaire;
    QStatusBar *statusbar;

    //correspond aux réglages qui étaient sur la seconde fenêtre au départ
        QSpinBox* num; // numéro
        QLineEdit* numeroBit[8]; // un QLineEdit par bit
        QLabel* numl;
        QLabel* numeroBitl[8];
        QVBoxLayout* numc;
        QVBoxLayout* bitc[8];
        QHBoxLayout* numeroc;
        QIntValidator* zeroOneValidator;
        // Question 2
        unsigned int dimension;
        QVBoxLayout* couche;

      //generateur
       QVBoxLayout* layout_generateur;
       QHBoxLayout* layout_cases;
       QSpinBox* nb_cases;
       QLabel* nb_cases_l;
       QHBoxLayout* layout_transitions;
       QSpinBox* nb_transitions;
       QLabel* nb_transitions_l;
       QPushButton* bouton_generateur;
       QStackedWidget* stacked_etat_depart;
       QWidget* page_etat_0;
       QWidget* page_etat_1;
       QVBoxLayout* layout_page_etat_1;


    void setupUi(QMainWindow *MainWindow);

    void retranslateUi(QMainWindow *MainWindow);


private slots :
    void onDimensionItemClicked(QListWidgetItem* item);
    void onAffichageButtonClicked(bool);
    void onGenerateurButtonClicked();
    void onSimulationButtonClicked();
    void synchronizeNumToNumBit(int i);
    void synchronizeNumBitToNum(const QString& s);
    void cellActivation(QTableWidgetItem* index);
    void onActionEnregistrer();
};


namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PROJET_LO21_2U14026_H
