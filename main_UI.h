/********************************************************************************
** Form generated from reading UI file 'Projet_LO21_2U14026.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PROJET_LO21_2U14026_H
#define PROJET_LO21_2U14026_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnregistrer;
    QAction *actionImporter;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *regleages_generaux;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *type_automate;
    QVBoxLayout *verticalLayout_12;
    QListWidget *select_type_automate;
    QGroupBox *Affichage;
    QFormLayout *formLayout;
    QRadioButton *aff_manuel;
    QRadioButton *aff_auto;
    QStackedWidget *Temps;
    QWidget *page_aff_auto;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *temps_aff;
    QDoubleSpinBox *aff_temps_n;
    QLabel *unite_temps_aff;
    QWidget *page_aff_man;
    QStackedWidget *stacked_settings;
    QWidget *page_dim1;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *etat_depart;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *regles_dim1;
    QGroupBox *regles_transition;
    QGroupBox *generateur;
    QLabel *etat_depart_l;
    QTableWidget *etat_depart_table;
    QPushButton *Simulation;
    QWidget *page_dim2;
    QVBoxLayout *verticalLayout;
    QGroupBox *etat_depart_4;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *regles_dim2;
    QGroupBox *regles_transition_dim2;
    QGridLayout *gridLayout;
    QLabel *voisin3;
    QLabel *voisin2;
    QLabel *voisin1;
    QLabel *voisin5;
    QLabel *voisin7;
    QLabel *voisin6;
    QLabel *regles_creation_l;
    QLabel *voisins_n_l;
    QLabel *voisin4;
    QLabel *voisin8;
    QLabel *regles_mort_l;
    QCheckBox *vie1;
    QCheckBox *vie2;
    QCheckBox *vie3;
    QCheckBox *vie4;
    QCheckBox *vie5;
    QCheckBox *vie6;
    QCheckBox *vie7;
    QCheckBox *vie8;
    QCheckBox *mort1;
    QCheckBox *mort2;
    QCheckBox *mort3;
    QCheckBox *mort4;
    QCheckBox *mort5;
    QCheckBox *mort6;
    QCheckBox *mort7;
    QCheckBox *mort8;
    QGroupBox *generateur_dim2;
    QPushButton *Simulation_4;
    QMenuBar *menubar;
    QMenu *menuR_glages_de_l_automate_cellulaire;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 544);
        MainWindow->setMaximumSize(QSize(1000, 900));
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        actionImporter = new QAction(MainWindow);
        actionImporter->setObjectName(QString::fromUtf8("actionImporter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        regleages_generaux = new QGroupBox(centralwidget);
        regleages_generaux->setObjectName(QString::fromUtf8("regleages_generaux"));
        regleages_generaux->setMaximumSize(QSize(1000, 150));
        horizontalLayout_2 = new QHBoxLayout(regleages_generaux);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        type_automate = new QGroupBox(regleages_generaux);
        type_automate->setObjectName(QString::fromUtf8("type_automate"));
        type_automate->setMinimumSize(QSize(260, 90));
        type_automate->setMaximumSize(QSize(300, 100));
        verticalLayout_12 = new QVBoxLayout(type_automate);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        select_type_automate = new QListWidget(type_automate);
        new QListWidgetItem(select_type_automate);
        new QListWidgetItem(select_type_automate);
        select_type_automate->setObjectName(QString::fromUtf8("select_type_automate"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        select_type_automate->setFont(font);
        select_type_automate->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        select_type_automate->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_12->addWidget(select_type_automate);


        horizontalLayout_2->addWidget(type_automate);

        Affichage = new QGroupBox(regleages_generaux);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));
        Affichage->setMaximumSize(QSize(16777215, 100));
        formLayout = new QFormLayout(Affichage);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        aff_manuel = new QRadioButton(Affichage);
        aff_manuel->setObjectName(QString::fromUtf8("aff_manuel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, aff_manuel);

        aff_auto = new QRadioButton(Affichage);
        aff_auto->setObjectName(QString::fromUtf8("aff_auto"));
        aff_auto->setMinimumSize(QSize(0, 60));

        formLayout->setWidget(1, QFormLayout::LabelRole, aff_auto);

        Temps = new QStackedWidget(Affichage);
        Temps->setObjectName(QString::fromUtf8("Temps"));
        Temps->setEnabled(false);
        Temps->setMaximumSize(QSize(250, 60));
        page_aff_auto = new QWidget();
        page_aff_auto->setObjectName(QString::fromUtf8("page_aff_auto"));
        verticalLayout_11 = new QVBoxLayout(page_aff_auto);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        temps_aff = new QHBoxLayout();
        temps_aff->setObjectName(QString::fromUtf8("temps_aff"));
        aff_temps_n = new QDoubleSpinBox(page_aff_auto);
        aff_temps_n->setObjectName(QString::fromUtf8("aff_temps_n"));
        aff_temps_n->setDecimals(3);
        aff_temps_n->setMaximum(60);
        aff_temps_n->setSingleStep(0.1);

        temps_aff->addWidget(aff_temps_n);

        unite_temps_aff = new QLabel(page_aff_auto);
        unite_temps_aff->setObjectName(QString::fromUtf8("unite_temps_aff"));

        temps_aff->addWidget(unite_temps_aff);


        verticalLayout_11->addLayout(temps_aff);

        Temps->addWidget(page_aff_auto);
        page_aff_man = new QWidget();
        page_aff_man->setObjectName(QString::fromUtf8("page_aff_man"));
        Temps->addWidget(page_aff_man);

        formLayout->setWidget(1, QFormLayout::FieldRole, Temps);


        horizontalLayout_2->addWidget(Affichage);


        verticalLayout_3->addWidget(regleages_generaux);

        stacked_settings = new QStackedWidget(centralwidget);
        stacked_settings->setObjectName(QString::fromUtf8("stacked_settings"));
        stacked_settings->setEnabled(true);
        stacked_settings->setMinimumSize(QSize(750, 0));
        stacked_settings->setMaximumSize(QSize(900, 16777215));
        stacked_settings->setContextMenuPolicy(Qt::DefaultContextMenu);
        stacked_settings->setAcceptDrops(false);
        stacked_settings->setAutoFillBackground(false);
        stacked_settings->setFrameShadow(QFrame::Raised);
        stacked_settings->setLineWidth(1);
        page_dim1 = new QWidget();
        page_dim1->setObjectName(QString::fromUtf8("page_dim1"));
        verticalLayout_2 = new QVBoxLayout(page_dim1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        etat_depart = new QGroupBox(page_dim1);
        etat_depart->setObjectName(QString::fromUtf8("etat_depart"));
        etat_depart->setMaximumSize(QSize(900, 400));
        verticalLayout_13 = new QVBoxLayout(etat_depart);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        regles_dim1 = new QHBoxLayout();
        regles_dim1->setObjectName(QString::fromUtf8("regles_dim1"));
        regles_transition = new QGroupBox(etat_depart);
        regles_transition->setObjectName(QString::fromUtf8("regles_transition"));
        regles_transition->setMaximumSize(QSize(16777215, 300));

        regles_dim1->addWidget(regles_transition);

        generateur = new QGroupBox(etat_depart);
        generateur->setObjectName(QString::fromUtf8("generateur"));
        generateur->setMaximumSize(QSize(16777215, 300));

        regles_dim1->addWidget(generateur);


        verticalLayout_13->addLayout(regles_dim1);

        etat_depart_l = new QLabel(etat_depart);
        etat_depart_l->setObjectName(QString::fromUtf8("etat_depart_l"));
        etat_depart_l->setMinimumSize(QSize(100, 20));
        etat_depart_l->setMaximumSize(QSize(16777215, 20));

        verticalLayout_13->addWidget(etat_depart_l);

        etat_depart_table = new QTableWidget(etat_depart);
        if (etat_depart_table->columnCount() < 30)
            etat_depart_table->setColumnCount(30);
        if (etat_depart_table->rowCount() < 1)
            etat_depart_table->setRowCount(1);
        etat_depart_table->setObjectName(QString::fromUtf8("etat_depart_table"));
        etat_depart_table->setMinimumSize(QSize(750, 0));
        etat_depart_table->setMaximumSize(QSize(750, 25));
        etat_depart_table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        etat_depart_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        etat_depart_table->setRowCount(1);
        etat_depart_table->setColumnCount(30);
        etat_depart_table->horizontalHeader()->setVisible(false);
        etat_depart_table->horizontalHeader()->setDefaultSectionSize(25);
        etat_depart_table->verticalHeader()->setVisible(false);
        etat_depart_table->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_13->addWidget(etat_depart_table);


        verticalLayout_2->addWidget(etat_depart);

        Simulation = new QPushButton(page_dim1);
        Simulation->setObjectName(QString::fromUtf8("Simulation"));
        Simulation->setMinimumSize(QSize(0, 50));
        Simulation->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(Simulation);

        stacked_settings->addWidget(page_dim1);
        page_dim2 = new QWidget();
        page_dim2->setObjectName(QString::fromUtf8("page_dim2"));
        verticalLayout = new QVBoxLayout(page_dim2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        etat_depart_4 = new QGroupBox(page_dim2);
        etat_depart_4->setObjectName(QString::fromUtf8("etat_depart_4"));
        etat_depart_4->setMaximumSize(QSize(900, 400));
        horizontalLayout = new QHBoxLayout(etat_depart_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        regles_dim2 = new QHBoxLayout();
        regles_dim2->setObjectName(QString::fromUtf8("regles_dim2"));
        regles_transition_dim2 = new QGroupBox(etat_depart_4);
        regles_transition_dim2->setObjectName(QString::fromUtf8("regles_transition_dim2"));
        regles_transition_dim2->setMaximumSize(QSize(16777215, 300));
        gridLayout = new QGridLayout(regles_transition_dim2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        voisin3 = new QLabel(regles_transition_dim2);
        voisin3->setObjectName(QString::fromUtf8("voisin3"));

        gridLayout->addWidget(voisin3, 0, 3, 1, 1);

        voisin2 = new QLabel(regles_transition_dim2);
        voisin2->setObjectName(QString::fromUtf8("voisin2"));

        gridLayout->addWidget(voisin2, 0, 2, 1, 1);

        voisin1 = new QLabel(regles_transition_dim2);
        voisin1->setObjectName(QString::fromUtf8("voisin1"));

        gridLayout->addWidget(voisin1, 0, 1, 1, 1);

        voisin5 = new QLabel(regles_transition_dim2);
        voisin5->setObjectName(QString::fromUtf8("voisin5"));

        gridLayout->addWidget(voisin5, 0, 5, 1, 1);

        voisin7 = new QLabel(regles_transition_dim2);
        voisin7->setObjectName(QString::fromUtf8("voisin7"));

        gridLayout->addWidget(voisin7, 0, 7, 1, 1);

        voisin6 = new QLabel(regles_transition_dim2);
        voisin6->setObjectName(QString::fromUtf8("voisin6"));

        gridLayout->addWidget(voisin6, 0, 6, 1, 1);

        regles_creation_l = new QLabel(regles_transition_dim2);
        regles_creation_l->setObjectName(QString::fromUtf8("regles_creation_l"));

        gridLayout->addWidget(regles_creation_l, 1, 0, 1, 1);

        voisins_n_l = new QLabel(regles_transition_dim2);
        voisins_n_l->setObjectName(QString::fromUtf8("voisins_n_l"));
        voisins_n_l->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(voisins_n_l, 0, 0, 1, 1);

        voisin4 = new QLabel(regles_transition_dim2);
        voisin4->setObjectName(QString::fromUtf8("voisin4"));

        gridLayout->addWidget(voisin4, 0, 4, 1, 1);

        voisin8 = new QLabel(regles_transition_dim2);
        voisin8->setObjectName(QString::fromUtf8("voisin8"));

        gridLayout->addWidget(voisin8, 0, 8, 1, 1);

        regles_mort_l = new QLabel(regles_transition_dim2);
        regles_mort_l->setObjectName(QString::fromUtf8("regles_mort_l"));

        gridLayout->addWidget(regles_mort_l, 2, 0, 1, 1);

        vie1 = new QCheckBox(regles_transition_dim2);
        vie1->setObjectName(QString::fromUtf8("vie1"));

        gridLayout->addWidget(vie1, 1, 1, 1, 1);

        vie2 = new QCheckBox(regles_transition_dim2);
        vie2->setObjectName(QString::fromUtf8("vie2"));

        gridLayout->addWidget(vie2, 1, 2, 1, 1);

        vie3 = new QCheckBox(regles_transition_dim2);
        vie3->setObjectName(QString::fromUtf8("vie3"));

        gridLayout->addWidget(vie3, 1, 3, 1, 1);

        vie4 = new QCheckBox(regles_transition_dim2);
        vie4->setObjectName(QString::fromUtf8("vie4"));

        gridLayout->addWidget(vie4, 1, 4, 1, 1);

        vie5 = new QCheckBox(regles_transition_dim2);
        vie5->setObjectName(QString::fromUtf8("vie5"));

        gridLayout->addWidget(vie5, 1, 5, 1, 1);

        vie6 = new QCheckBox(regles_transition_dim2);
        vie6->setObjectName(QString::fromUtf8("vie6"));

        gridLayout->addWidget(vie6, 1, 6, 1, 1);

        vie7 = new QCheckBox(regles_transition_dim2);
        vie7->setObjectName(QString::fromUtf8("vie7"));

        gridLayout->addWidget(vie7, 1, 7, 1, 1);

        vie8 = new QCheckBox(regles_transition_dim2);
        vie8->setObjectName(QString::fromUtf8("vie8"));

        gridLayout->addWidget(vie8, 1, 8, 1, 1);

        mort1 = new QCheckBox(regles_transition_dim2);
        mort1->setObjectName(QString::fromUtf8("mort1"));

        gridLayout->addWidget(mort1, 2, 1, 1, 1);

        mort2 = new QCheckBox(regles_transition_dim2);
        mort2->setObjectName(QString::fromUtf8("mort2"));

        gridLayout->addWidget(mort2, 2, 2, 1, 1);

        mort3 = new QCheckBox(regles_transition_dim2);
        mort3->setObjectName(QString::fromUtf8("mort3"));

        gridLayout->addWidget(mort3, 2, 3, 1, 1);

        mort4 = new QCheckBox(regles_transition_dim2);
        mort4->setObjectName(QString::fromUtf8("mort4"));

        gridLayout->addWidget(mort4, 2, 4, 1, 1);

        mort5 = new QCheckBox(regles_transition_dim2);
        mort5->setObjectName(QString::fromUtf8("mort5"));

        gridLayout->addWidget(mort5, 2, 5, 1, 1);

        mort6 = new QCheckBox(regles_transition_dim2);
        mort6->setObjectName(QString::fromUtf8("mort6"));

        gridLayout->addWidget(mort6, 2, 6, 1, 1);

        mort7 = new QCheckBox(regles_transition_dim2);
        mort7->setObjectName(QString::fromUtf8("mort7"));

        gridLayout->addWidget(mort7, 2, 7, 1, 1);

        mort8 = new QCheckBox(regles_transition_dim2);
        mort8->setObjectName(QString::fromUtf8("mort8"));

        gridLayout->addWidget(mort8, 2, 8, 1, 1);

        voisins_n_l->raise();
        regles_creation_l->raise();
        regles_mort_l->raise();
        voisin1->raise();
        voisin2->raise();
        voisin3->raise();
        voisin4->raise();
        voisin5->raise();
        voisin6->raise();
        voisin7->raise();
        voisin8->raise();
        vie1->raise();
        vie2->raise();
        vie3->raise();
        vie4->raise();
        vie5->raise();
        vie6->raise();
        vie7->raise();
        vie8->raise();
        mort1->raise();
        mort2->raise();
        mort3->raise();
        mort4->raise();
        mort5->raise();
        mort6->raise();
        mort7->raise();
        mort8->raise();

        regles_dim2->addWidget(regles_transition_dim2);

        generateur_dim2 = new QGroupBox(etat_depart_4);
        generateur_dim2->setObjectName(QString::fromUtf8("generateur_dim2"));
        generateur_dim2->setMaximumSize(QSize(16777215, 300));

        regles_dim2->addWidget(generateur_dim2);


        horizontalLayout->addLayout(regles_dim2);


        verticalLayout->addWidget(etat_depart_4);

        Simulation_4 = new QPushButton(page_dim2);
        Simulation_4->setObjectName(QString::fromUtf8("Simulation_4"));
        Simulation_4->setMinimumSize(QSize(0, 50));
        Simulation_4->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(Simulation_4);

        stacked_settings->addWidget(page_dim2);

        verticalLayout_3->addWidget(stacked_settings);

        MainWindow->setCentralWidget(centralwidget);
        regleages_generaux->raise();
        stacked_settings->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 23));
        menuR_glages_de_l_automate_cellulaire = new QMenu(menubar);
        menuR_glages_de_l_automate_cellulaire->setObjectName(QString::fromUtf8("menuR_glages_de_l_automate_cellulaire"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuR_glages_de_l_automate_cellulaire->menuAction());
        menuR_glages_de_l_automate_cellulaire->addAction(actionEnregistrer);
        menuR_glages_de_l_automate_cellulaire->addAction(actionImporter);

        retranslateUi(MainWindow);
        QObject::connect(select_type_automate, SIGNAL(itemClicked(QListWidgetItem*)), stacked_settings, SLOT(setFocus(0)));

        Temps->setCurrentIndex(0);
        stacked_settings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        actionImporter->setText(QApplication::translate("MainWindow", "Importer", 0, QApplication::UnicodeUTF8));
        type_automate->setTitle(QApplication::translate("MainWindow", "S\303\251lectionner le type d'automate : ", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = select_type_automate->isSortingEnabled();
        select_type_automate->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = select_type_automate->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Automate 1 dimension", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = select_type_automate->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Automate 2 dimensions", 0, QApplication::UnicodeUTF8));
        select_type_automate->setSortingEnabled(__sortingEnabled);

        Affichage->setTitle(QApplication::translate("MainWindow", "Affichage", 0, QApplication::UnicodeUTF8));
        aff_manuel->setText(QApplication::translate("MainWindow", "Manuel", 0, QApplication::UnicodeUTF8));
        aff_auto->setText(QApplication::translate("MainWindow", "Automatique", 0, QApplication::UnicodeUTF8));
        unite_temps_aff->setText(QApplication::translate("MainWindow", "sec", 0, QApplication::UnicodeUTF8));
        etat_depart->setTitle(QApplication::translate("MainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        regles_transition->setTitle(QApplication::translate("MainWindow", "R\303\250gles de transition", 0, QApplication::UnicodeUTF8));
        generateur->setTitle(QApplication::translate("MainWindow", "G\303\251n\303\251rateur", 0, QApplication::UnicodeUTF8));
        etat_depart_l->setText(QApplication::translate("MainWindow", "\303\211tat de d\303\251part", 0, QApplication::UnicodeUTF8));
        Simulation->setText(QApplication::translate("MainWindow", "Lancer !", 0, QApplication::UnicodeUTF8));
        etat_depart_4->setTitle(QApplication::translate("MainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        regles_transition_dim2->setTitle(QApplication::translate("MainWindow", "R\303\250gles de transition", 0, QApplication::UnicodeUTF8));
        voisin3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        voisin2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        voisin1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        voisin5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        voisin7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        voisin6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        regles_creation_l->setText(QApplication::translate("MainWindow", "R\303\250gle de cr\303\251ation", 0, QApplication::UnicodeUTF8));
        voisins_n_l->setText(QApplication::translate("MainWindow", "Nombre de voisins : ", 0, QApplication::UnicodeUTF8));
        voisin4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        voisin8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        regles_mort_l->setText(QApplication::translate("MainWindow", "R\303\250gle de mort", 0, QApplication::UnicodeUTF8));
        vie1->setText(QString());
        vie2->setText(QString());
        vie3->setText(QString());
        vie4->setText(QString());
        vie5->setText(QString());
        vie6->setText(QString());
        vie7->setText(QString());
        vie8->setText(QString());
        mort1->setText(QString());
        mort2->setText(QString());
        mort3->setText(QString());
        mort4->setText(QString());
        mort5->setText(QString());
        mort6->setText(QString());
        mort7->setText(QString());
        mort8->setText(QString());
        generateur_dim2->setTitle(QApplication::translate("MainWindow", "G\303\251n\303\251rateur", 0, QApplication::UnicodeUTF8));
        Simulation_4->setText(QApplication::translate("MainWindow", "Lancer !", 0, QApplication::UnicodeUTF8));
        menuR_glages_de_l_automate_cellulaire->setTitle(QApplication::translate("MainWindow", "Enregistrement", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PROJET_LO21_2U14026_H
