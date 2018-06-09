/**
 * \file main_ui.cpp
 * \brief Fichier source définissant les classes de la fenêtre principale.
 * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
 * \version 1.0
 * \date 16 Juin 2018
 *
 * Fichier source définissant l'architecture des classes de l'IHM correspondant aux différents automates implémentés.
 *
 */

#include "main_UI.h"
#include "automate1d.h"
#include "Window.h"

/*!
 *  \brief Constructeur
 *
 *  Constructeur de la classe Fenetre_Principale
 *
 *  \param MainWindow : Fenêtre princicpale (type Qt)
 */

Fenetre_Principale::Fenetre_Principale(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("Automates Cellulaires"));
       MainWindow->resize(850, 700);
       MainWindow->setMaximumSize(QSize(1000, 1200));
       actionEnregistrer = new QAction(MainWindow);
       actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
       actionEnregistrer->setEnabled(false);
       actionImporter = new QAction(MainWindow);
       actionImporter->setObjectName(QString::fromUtf8("actionImporter"));

       centralwidget = new QWidget(MainWindow);
       centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
       layout_main = new QHBoxLayout(centralwidget);
       layout_main->setObjectName(QString::fromUtf8("layout_main"));
       layout_main->setAlignment(Qt::AlignTop);
       reglages_generaux = new QGroupBox(centralwidget);
       reglages_generaux->setObjectName(QString::fromUtf8("reglages_generaux"));
       //reglages_generaux->setMaximumSize(QSize(1000, 200));
       layout_reglages_generaux = new QVBoxLayout(reglages_generaux);
       layout_reglages_generaux->setObjectName(QString::fromUtf8("layout_reglages_generaux"));
       type_automate = new QGroupBox(reglages_generaux);
       type_automate->setObjectName(QString::fromUtf8("type_automate"));
       type_automate->setMinimumSize(QSize(260, 115));
       //type_automate->setMaximumSize(QSize(300, 200));
       layout_type_automate = new QHBoxLayout(type_automate);
       layout_type_automate->setObjectName(QString::fromUtf8("layout_type_automate"));
        select_type_automate = new QListWidget(type_automate);
        select_type_automate->setObjectName(QString::fromUtf8("select_type_automate"));
       QFont font;
       font.setFamily(QString::fromUtf8("Sans Serif"));
       font.setPointSize(14);
       font.setBold(false);
       font.setItalic(true);
       font.setWeight(50);
       select_type_automate->setFont(font);
       select_type_automate->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
       select_type_automate->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        layout_type_automate->addWidget(select_type_automate);

       layout_reglages_generaux->addWidget(type_automate);
       Affichage = new QGroupBox(reglages_generaux);
       Affichage->setObjectName(QString::fromUtf8("Affichage"));
       Affichage->setMaximumSize(QSize(1500, 200));
       Affichage->setMaximumHeight(120);
       layout_affichage = new QFormLayout(Affichage);
       layout_affichage->setObjectName(QString::fromUtf8("layout_affichage"));
       layout_affichage->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
       aff_manuel = new QRadioButton(Affichage);
       aff_manuel->setObjectName(QString::fromUtf8("aff_manuel"));

       layout_affichage->setWidget(0, QFormLayout::LabelRole, aff_manuel);
\
       aff_auto = new QRadioButton(Affichage);
       aff_auto->setObjectName(QString::fromUtf8("aff_auto"));
       aff_auto->setMinimumSize(QSize(0, 50));

       layout_affichage->setWidget(1, QFormLayout::LabelRole, aff_auto);

       Temps = new QStackedWidget(Affichage);
       Temps->setObjectName(QString::fromUtf8("Temps"));
       Temps->setMinimumSize(QSize(0, 50));
       Temps->setMaximumSize(QSize(250, 70));
       page_aff_auto = new QWidget();
       page_aff_auto->setObjectName(QString::fromUtf8("page_aff_auto"));
       layout_aff_auto = new QVBoxLayout(page_aff_auto);
       layout_aff_auto->setObjectName(QString::fromUtf8("layout_page_dim2_11"));
       temps_aff = new QHBoxLayout();
       temps_aff->setObjectName(QString::fromUtf8("temps_aff"));
       aff_temps_n = new QDoubleSpinBox(page_aff_auto);
       aff_temps_n->setObjectName(QString::fromUtf8("aff_temps_n"));
       aff_temps_n->setDecimals(3);
       aff_temps_n->setMaximum(60);
       aff_temps_n->setSingleStep(0.05);
       aff_temps_n->setValue(0.05);

       temps_aff->addWidget(aff_temps_n);

       unite_temps_aff = new QLabel(page_aff_auto);
       unite_temps_aff->setObjectName(QString::fromUtf8("unite_temps_aff"));

       temps_aff->addWidget(unite_temps_aff);


       layout_aff_auto->addLayout(temps_aff);

       Temps->addWidget(page_aff_auto);
       page_aff_man = new QWidget();
       page_aff_man->setObjectName(QString::fromUtf8("page_aff_man"));
       Temps->addWidget(page_aff_man);

       layout_affichage->setWidget(1, QFormLayout::FieldRole, Temps);


       layout_reglages_generaux->addWidget(Affichage);


       layout_main->addWidget(reglages_generaux);

       stacked_settings = new QStackedWidget(centralwidget);

       stacked_settings->setObjectName(QString::fromUtf8("stacked_settings"));
       stacked_settings->setEnabled(true);
       stacked_settings->setMinimumSize(QSize(750, 0));
       stacked_settings->setMaximumSize(QSize(900, 1500));
       stacked_settings->setContextMenuPolicy(Qt::DefaultContextMenu);
       stacked_settings->setAcceptDrops(false);
       stacked_settings->setAutoFillBackground(false);
       stacked_settings->setFrameShadow(QFrame::Raised);
       stacked_settings->setLineWidth(1);

       layout_main->addWidget(stacked_settings);


       MainWindow->setCentralWidget(centralwidget);
       reglages_generaux->raise();
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

       Temps->setCurrentIndex(0);
       aff_auto->setChecked(true);
       stacked_settings->setCurrentIndex(0);

       //connexion des signaux et des slots

       connect(select_type_automate, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onDimensionItemClicked(QListWidgetItem*)));
       connect(aff_manuel, SIGNAL(toggled(bool)), this, SLOT(onAffichageButtonClicked(bool)));
       connect(actionEnregistrer, SIGNAL(triggered()), this, SLOT(onActionEnregistrer()));
       connect(actionImporter, SIGNAL(triggered()), this, SLOT(onActionImporter()));
} // setupUi

/*!
 *  \brief Méthode Noms
 *
 *  Méthode Noms de la classe Fenetre_Principale permettant de nommer correctement tous les widget contenant du texte
 *
 *  \param MainWindow : Fenêtre princicpale (type Qt)
 */


void Fenetre_Principale::Noms(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("AutoCell LO21", "AutoCell LO21", 0));
    actionEnregistrer->setText(QApplication::translate("AutoCell LO21", "Enregistrer", 0));
    actionImporter->setText(QApplication::translate("AutoCell LO21", "Importer", 0));
    type_automate->setTitle(QApplication::translate("AutoCell LO21", "S\303\251lectionner le type d'automate : ", 0));

    const bool __sortingEnabled = select_type_automate->isSortingEnabled();
    select_type_automate->setSortingEnabled(false);
    select_type_automate->setSortingEnabled(__sortingEnabled);

    Affichage->setTitle(QApplication::translate("AutoCell LO21", "Affichage", 0));
    aff_manuel->setText(QApplication::translate("AutoCell LO21", "Manuel", 0));
    aff_auto->setText(QApplication::translate("AutoCell LO21", "Automatique", 0));
    unite_temps_aff->setText(QApplication::translate("AutoCell LO21", "sec", 0));

    menuR_glages_de_l_automate_cellulaire->setTitle(QApplication::translate("AutoCell LO21", "Fichiers de config", 0));
} // retranslateUi


/*!
 *  \brief Constructeur
 *
 *  Construcuteur de la classe Fenetre_AutoDim1
 *
 *  \param MainWindow : Fenêtre princicpale (type Qt)
 */
Fenetre_AutoDim1::Fenetre_AutoDim1(QMainWindow *MainWindow):Fenetre_Principale(MainWindow),  taille(25), enregistrer_autodim1(false)
{
    /***********************
     *
     * automate dimension 1
     *
     *
     ***********************/
    select_type_automate->insertItem(select_type_automate->count(), "Automates 1 dimension");

    page_dim1 = new QWidget();
    page_dim1->setObjectName(QString::fromUtf8("page_dim1"));
    layout_page_dim1 = new QVBoxLayout(page_dim1);
    layout_page_dim1->setObjectName(QString::fromUtf8("layout_page_dim1"));
    layout_page_dim1->setAlignment(Qt::AlignTop);

    //configuration dimension 1

    configuration_dim1 = new QGroupBox(page_dim1);
    configuration_dim1->setObjectName(QString::fromUtf8("configuration_dim1"));
    configuration_dim1->setMaximumSize(QSize(900, 400));

    regles_dim1 = new QHBoxLayout();
    regles_dim1->setObjectName(QString::fromUtf8("regles_dim1"));
    regles_dim1->setAlignment(Qt::AlignTop);


    //règles de transition dimension 1

    regles_transition = new QGroupBox(configuration_dim1);
    regles_transition->setObjectName(QString::fromUtf8("regles_transition"));

    regles_transition->setMaximumSize(QSize(400, 200));

    num = new QSpinBox();//spinbox -> sélection du numéro de l'automate en décimal
    num->setRange(0, 255);//255 automates possibles
    num->setValue(0);//valeur par défaut
    num->setMaximumWidth(100);
    numl = new QLabel("Numéro");//Label du numéro de l'automate
    numc = new QVBoxLayout;//Box pour la spinBox et le label
    numc->addWidget(numl);//on ajoute le label (en premier=en haut)
    numc->addWidget(num);//on ajoute la spinbx (en seconde=en bas)
    numeroc = new QHBoxLayout;//Box pour l'interface du numéro en binaire+décimal
    numeroc->addLayout(numc);//ajout de la box pour le numéro en décimal
    zeroOneValidator = new QIntValidator(this);//sélection de chaque règle : 0 ou 1
    zeroOneValidator->setRange(0, 1);//ça ne peut être que 0 ou 1
    numeroBitl[0] = new QLabel("111");//tableau des labels des états
    numeroBitl[1] = new QLabel("110");
    numeroBitl[2] = new QLabel("101");
    numeroBitl[3] = new QLabel("100");
    numeroBitl[4] = new QLabel("011");
    numeroBitl[5] = new QLabel("010");
    numeroBitl[6] = new QLabel("001");
    numeroBitl[7] = new QLabel("000");

    for(unsigned int counter = 0; counter < 8; ++counter) {
        //pour chaque état du tableau, création de l'interface
        numeroBit[counter] = new QLineEdit();//on créé la case pour éditer les états
        numeroBit[counter]->setFixedWidth(20); //pixels
        numeroBit[counter]->setMaxLength(1); //caractères
        numeroBit[counter]->setText("0");//valeur par défaut
        numeroBit[counter]->setValidator(zeroOneValidator);//0 ou 1
        bitc[counter] = new QVBoxLayout;//On créé une box pour mettre le label et le champ de sélection
        bitc[counter]->addWidget(numeroBitl[counter]);//on ajoute le label
        bitc[counter]->addWidget(numeroBit[counter]);//on ajoute le champ
        numeroc->addLayout(bitc[counter]);//on ajoute le tout à la grande boîte pour l'écriture décimale + binaire
        connect(numeroBit[counter], SIGNAL(textChanged(QString)), this, SLOT(synchronizeNumBitToNum(QString)));//on connecte le binaire au décimal pour que la MàJ se fasse automatiquement
    }
    regles_transition->setLayout(numeroc);
    couche = new QVBoxLayout;//Nouvelle box pour l'affichage des étapes de l'automate




    //generateur dimension 1


    regles_dim1->addWidget(regles_transition);
    layout_generateur = new QVBoxLayout;
    generateur = new QGroupBox(configuration_dim1);
    generateur->setObjectName(QString::fromUtf8("generateur"));
    generateur->setMaximumSize(QSize(400, 200));
    regles_dim1->addWidget(generateur);

    select_generateur = new QComboBox(generateur);
    select_generateur->setMaximumSize(QSize(120, 20));
    select_generateur_l=new QLabel("Génération");
    layout_select_generateur = new QHBoxLayout;
    layout_select_generateur->addWidget(select_generateur_l);
    layout_select_generateur->addWidget(select_generateur);
    layout_generateur->addLayout(layout_select_generateur);

    select_generateur->addItem(tr("Aléatoire"));
    select_generateur->addItem(tr("Manuelle"));
    select_generateur->addItem(tr("1 sur 2"));


    nb_cases = new QSpinBox();
    nb_cases->setRange(2, MAX_CASES);
    nb_cases->setValue(30);
    nb_cases->setMaximumWidth(100);
    nb_cases_l = new QLabel("Nombre de cases");
    layout_cases = new QHBoxLayout;
    layout_cases->addWidget(nb_cases_l);
    layout_cases->addWidget(nb_cases);
    layout_generateur->addLayout(layout_cases);
    //nb_cases->setEnabled(false);

    nb_transitions = new QSpinBox();
    nb_transitions->setRange(1, MAX_TRANSITIONS);
    nb_transitions->setValue(10);
    nb_transitions->setMaximumWidth(100);
    nb_transitions_l = new QLabel("Nombre de transitions");
    layout_transitions = new QHBoxLayout;
    layout_transitions->addWidget(nb_transitions_l);
    layout_transitions->addWidget(nb_transitions);
    layout_generateur->addLayout(layout_transitions);
    nb_transitions->setEnabled(true);

    bouton_generateur = new QPushButton;
    bouton_generateur->setObjectName(QString::fromUtf8("bouton_generateur"));
    bouton_generateur->setMinimumSize(QSize(0, 50));
    bouton_generateur->setText(QApplication::translate("AutoCell LO21", "Générer", 0));
    bouton_generateur->setMaximumSize(QSize(1500, 50));
    layout_generateur->addWidget(bouton_generateur);
    generateur->setLayout(layout_generateur);



    //etat de départ dimension 1

    layout_page_etat_0 = new QVBoxLayout;
    aucun_etat_depart = new QLabel("Générez/Importez un état de départ");
    layout_page_etat_0->addWidget(aucun_etat_depart);
    layout_page_etat_0->setAlignment(Qt::AlignHCenter);

    layout_etat_depart = new QVBoxLayout(configuration_dim1);
    layout_etat_depart->setObjectName(QString::fromUtf8("layout_etat_depart"));
    layout_etat_depart->setAlignment(Qt::AlignTop);
    etat_depart_l = new QLabel(configuration_dim1);
    etat_depart_l->setObjectName(QString::fromUtf8("etat_depart_l"));
    etat_depart_l->setMinimumSize(QSize(100, 20));
    etat_depart_l->setMaximumSize(QSize(1500, 20));

    layout_etat_depart->addWidget(etat_depart_l);

    stacked_etat_depart = new QStackedWidget;
    stacked_etat_depart->setObjectName(QString::fromUtf8("stacked_etat_depart"));
    stacked_etat_depart->setEnabled(true);
    page_etat_0 = new QWidget();
    page_etat_0->setObjectName(QString::fromUtf8("page_etat_0"));
    page_etat_0->setLayout(layout_page_etat_0);
    page_etat_1 = new QWidget();
    page_etat_1->setObjectName(QString::fromUtf8("page_etat_1"));
    layout_page_etat_1 = new QVBoxLayout;
    layout_page_etat_1->setAlignment(Qt::AlignTop);
    page_etat_1->setLayout(layout_page_etat_1);
    layout_page_etat_1->addWidget(etat_depart_l);
    stacked_etat_depart->addWidget(page_etat_0);
    stacked_etat_depart->addWidget(page_etat_1);
    stacked_etat_depart->raise();
    layout_page_dim1->addWidget(configuration_dim1);
    layout_etat_depart->addLayout(regles_dim1);
    layout_etat_depart->addWidget(stacked_etat_depart);

    //bouton simulation dimension 1
    Simulation = new QPushButton(page_dim1);
    Simulation->setObjectName(QString::fromUtf8("Simulation"));
    Simulation->setMinimumSize(QSize(0, 50));
    //Simulation->setMaximumSize(QSize(1500, 50));

    layout_page_dim1->addWidget(Simulation);

    stacked_settings->addWidget(page_dim1);
    Simulation->setEnabled(false);

    Noms_dim1(MainWindow);

    //connexions
    connect(num, SIGNAL(valueChanged(int)), this, SLOT(synchronizeNumToNumBit(int)));//réciproquement, on connecte le décimal au binaire

    connect(bouton_generateur, SIGNAL(clicked()), this, SLOT(onGenerateurButtonClicked_dim1()));
    connect(Simulation, SIGNAL(clicked()), this, SLOT(onSimulationButtonClicked_dim1()));

    QMetaObject::connectSlotsByName(MainWindow);
}

/*!
 *  \brief Méthode Noms_dim1
 *
 *  Méthode Noms de la classe Fenetre_AutoDim1 permettant de nommer correctement tous les widget contenant du texte des automates à une dimension
 *
 *  \param MainWindow : Fenêtre princicpale (type Qt)
 */

void Fenetre_AutoDim1::Noms_dim1(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("AutoCell LO21", "AutoCell LO21", 0));
    actionEnregistrer->setText(QApplication::translate("AutoCell LO21", "Enregistrer", 0));
    actionImporter->setText(QApplication::translate("AutoCell LO21", "Importer", 0));
    type_automate->setTitle(QApplication::translate("AutoCell LO21", "S\303\251lectionner le type d'automate : ", 0));

    const bool __sortingEnabled = select_type_automate->isSortingEnabled();
    select_type_automate->setSortingEnabled(false);
    //QListWidgetItem *___qlistwidgetitem = select_type_automate->item(0);
    //___qlistwidgetitem->setText(QApplication::translate("AutoCell LO21", "Automates 1 dimension", 0));
    select_type_automate->setSortingEnabled(__sortingEnabled);

    Affichage->setTitle(QApplication::translate("AutoCell LO21", "Affichage", 0));
    aff_manuel->setText(QApplication::translate("AutoCell LO21", "Manuel", 0));
    aff_auto->setText(QApplication::translate("AutoCell LO21", "Automatique", 0));
    unite_temps_aff->setText(QApplication::translate("AutoCell LO21", "sec", 0));
    configuration_dim1->setTitle(QApplication::translate("AutoCell LO21", "Configuration", 0));
    regles_transition->setTitle(QApplication::translate("AutoCell LO21", "R\303\250gles de transition", 0));
    generateur->setTitle(QApplication::translate("AutoCell LO21", "G\303\251n\303\251rateur", 0));
    etat_depart_l->setText(QApplication::translate("AutoCell LO21", "\303\211tat de d\303\251part", 0));
    Simulation->setText(QApplication::translate("AutoCell LO21", "Lancer !", 0));

    menuR_glages_de_l_automate_cellulaire->setTitle(QApplication::translate("AutoCell LO21", "Fichiers de config", 0));
} // retranslateUi

/*!
 *  \brief Slot virtual de gestion du type d'automate
 *
 *  Slot permettant de gérer la liste de types d'automates. On la redéfinit dans chaque nouvelle classe afin de gérer le nouvel automate.
 *
 *  \param item : item qui a été cliqué dans le widget
 */

void Fenetre_AutoDim1::onDimensionItemClicked(QListWidgetItem* item)
{
    if (select_type_automate->item(0) == item) {
            stacked_settings->setCurrentIndex(0);
            actionEnregistrer->setEnabled(enregistrer_autodim1);

        }
}

/*!
 *  \brief Slot de gestion du type d'affichage
 *
 *  Slot permettant de gérer le type d'affichage (manuel ou automatique) de la classe Fenetre_Principale.
 *
 *  \param checked : booléen du radio bouton de l'affichage manuel
 */
void Fenetre_Principale::onAffichageButtonClicked(bool checked)
{
    if(checked)//dans le cas de l'affichage manuel
    {
        Temps->setCurrentIndex(1);
    }
    else//dans le cas de l'affichage automatique sélectionné
    {
        Temps->setCurrentIndex(0);
    }
}

/*!
 *  \brief Slot de gestion du générateur des automates à une dimension
 *
 *  Slot permettant de gérer la génération de l'état de départ d'une dimension ainsi que ses générateurs.
 *
 */

void Fenetre_AutoDim1::onGenerateurButtonClicked_dim1()
{
    if(page_dim1->findChild<QTableWidget*>("etat_depart_table"))//on teste si le tableau existe déjà
    {
        layout_page_etat_1->removeWidget(etat_depart_table);
        delete etat_depart_table;
    }
    dimension=nb_cases->value();
    //stacked_etat_depart->setFixedSize(dimension*taille + 50, taille+50);
    etat_depart_table = new QTableWidget(1, dimension); //
    etat_depart_table->setFixedHeight(taille+40); // largeur = nombre_cellules*taille_cellule, hauteur = taille_cellule
    etat_depart_table->setMaximumWidth(taille*dimension+2);
    etat_depart_table->horizontalHeader()->setVisible(true); // masque le header (numéro des cases) horizontal
    etat_depart_table->verticalHeader()->setVisible(false); // masque le header vertical
    etat_depart_table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // désactive la scroll barre vertical
    etat_depart_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre horizontal
    // création des items du QTableWidget, initialisés à "" avec un fond blanc
    //on initialise toutes les cases avec un symbole représentant une case à l'état 0, ici, c'est "", une chaîne vide.

    for(unsigned int counter = 0; counter < dimension; ++counter) {
        etat_depart_table->setColumnWidth(counter, taille);
        etat_depart_table->setItem(0, counter, new QTableWidgetItem(""));
        etat_depart_table->item(0, counter)->setBackgroundColor("white");
        etat_depart_table->item(0, counter)->setTextColor("white");
        }
    etat_depart_table->setParent(page_dim1);
    layout_page_etat_1->addWidget(etat_depart_table);
    etat_depart_table->setObjectName(QString::fromUtf8("etat_depart_table"));
    connect(etat_depart_table, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation_dim1(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
    if(select_generateur->currentText()==tr("Aléatoire"))
    {
        Gen_aleatoire();
    }
    else if(select_generateur->currentText()==tr("Manuelle"))
    {
        stacked_etat_depart->setCurrentIndex(1);
        Simulation->setEnabled(true);
        enregistrer_autodim1=true;
        actionEnregistrer->setEnabled(enregistrer_autodim1);
    }
    else if(select_generateur->currentText()==tr("1 sur 2"))
    {
        Gen_Un_Sur_Deux();
    }
}


/*!
 *  \brief Slot de gestion du bouton de simulation
 *
 *  Slot permettant de gérer le bouton de simulation (Lancer !) afin de créer la fenêtre correspondant au bon automate en appelant le constructeur avec les bons paramètres.
 *
 */
void Fenetre_AutoDim1::onSimulationButtonClicked_dim1()
{
        new_Window_dim1 = new Window_Dim1(nullptr, dimension, nb_transitions->value(), num->value(),aff_manuel->isChecked(), aff_temps_n->value()*1000);
        new_Window_dim1->setEtatDepart(etat_depart_table);
        new_Window_dim1->show();
        if(!aff_manuel->isChecked())
        {
            new_Window_dim1->launchSimulationAuto();
        }
}

/*!
 *  \brief Slot de gestion des cliques sur l'état de départ des automates à une dimension
 *
 *  Slot permettant de gérer l'activation des cellules de l'état de départ.
 *
 *  \param index : index de la cellule cliquée
 */

void Fenetre_AutoDim1::cellActivation_dim1(QTableWidgetItem *index) {//méthode pour changer l'état
    if (etat_depart_table->item(0, index->column())->backgroundColor() == "white") {//si la cellule était morte, on la fait vivre (elle passe du blanc au noir)
        etat_depart_table->item(0, index->column())->setBackgroundColor("black");
    } else {//au contraire, on passe du noir au blanc si la cellule était vivante
        etat_depart_table->item(0, index->column())->setBackgroundColor("white");
    }
}

/*!
 *  \brief Méthode de synchronization du numéro de l'automate à une dimension (décimal vers binaire)
 *
 *  Méthode permettant de mettre à jour le numéro binaire de l'automate lorsque le numéro décimal est changé
 *
 *  \param i : numéro décimal de l'automate
 */

void Fenetre_AutoDim1::synchronizeNumToNumBit(int i) {//synchronisation de numéro de l'automate en décimal vers binaire
    std::string numBit = NumToNumBit(i);//string correspondant au numéro en binaire
    for(unsigned int counter = 0; counter < 8; ++counter) {
        numeroBit[counter]->setText(QString(numBit[counter]));//on convertit le std::string en string de Qt grâce à la méthode disponible dans Qt
    }
}


/*!
 *  \brief Méthode de synchronization du numéro de l'automate à une dimension (binaire vers décimal)
 *
 *  Méthode permettant de mettre à jour le numéro décimal de l'automate lorsque le numéro binaire est changé
 *
 *  \param i : numéro binaire de l'automate (sous forme de QString)
 */
void Fenetre_AutoDim1::synchronizeNumBitToNum(const QString& s) {//synchronisation de numéro de l'automate en binaire vers décimal
    if (s == "") {//on vérifie si la chaîne est vide
        return;
    }
    std::string numBit = "";//string correspondant au numéro en binaire
    for(unsigned int counter = 0; counter < 8; ++counter) {
        numBit += numeroBit[counter]->text().toStdString();//on convertit le string Qt en std::string
    }
    num->setValue(NumBitToNum(numBit));//on utilise la méthode fournie dans l'autre TD
}

/*!
 *  \brief Slot de gestion de l'enregistrement des automates à une dimension
 *
 *  Slot permettant d'enregistrer les automates à une dimension dans un fichier XML du répertoire HOME de l'utilisateur.
 *
 */

void Fenetre_AutoDim1::onActionEnregistrer_dim1()
{
        QString path =QDir::homePath().append(QDir::toNativeSeparators(QString::fromUtf8("/Configs_dim_1/")));
        QDir dir;
        fichier = new QFileDialog;
        //fichier->setDefaultSuffix(QString::fromUtf8("txt"));
        if(!dir.exists(path))
        {
            dir.mkpath(path);
        }

        QString nom_fichier = fichier->getSaveFileName(centralwidget,
                                 QString::fromUtf8("Enregistrement de configuration"),
                                 path);

        if((nom_fichier.split(".").count()==1))
        {
            nom_fichier.append(".xml");
        }

        QFile file(nom_fichier);
        if ((file.open(QIODevice::ReadWrite)))
        {
            QDomDocument dom(nom_fichier.split("/").last());

            QTextStream stream(&file);

            //QDomElement base = dom.documentElement();
            QDomElement root = dom.createElement("root");
            dom.appendChild(root);

            QDomElement regles = dom.createElement("Regles");
            regles.setAttribute("numero", num->value());
            root.appendChild(regles);//On associe write_elem à domElem.

            QDomElement generator = dom.createElement("Generateur");
            generator.setAttribute("nb_cases", nb_cases->value());
            generator.setAttribute("nb_transitions", nb_transitions->value());
            generator.setAttribute("generation", select_generateur->currentIndex());
            root.appendChild(generator);

            QDomElement etat_dep = dom.createElement("Etat_depart");
            root.appendChild(etat_dep);

            QDomElement etats_dep[nb_cases->value()];
            for(int i=0; i<nb_cases->value(); i++)
            {
                etats_dep[i] = dom.createElement("Etat"+QString::number(i));
                etats_dep[i].setAttribute("active", etat_depart_table->item(0,i)->backgroundColor()=="black");
                etat_dep.appendChild(etats_dep[i]);
            }

            QString write_doc = dom.toString();
            stream << write_doc;

            file.close();
        }
}


/*!
 *  \brief Slot de gestion de l'import des automates à une dimension
 *
 *  Slot permettant d'importer les automates à une dimension à partir d'un fichier XML du répertoire HOME de l'utilisateur.
 *
 */
void Fenetre_AutoDim1::onActionImporter_dim1()
{
    QDir dir;
    QString path =QDir::homePath().append(QDir::toNativeSeparators(QString::fromUtf8("/Configs_dim_1/")));
    if(!dir.exists(path))
    {
        QMessageBox::information(NULL, "Information", "Aucune configuration n'a été préalablement enregistrée \n Aucune configuration à importer.");
    }
    else
    {
        fichier = new QFileDialog;
        QString nom_fichier = fichier->getOpenFileName(centralwidget,
                                 QString::fromUtf8("Enregistrement de configuration"),
                                 path);

        QDomDocument dom;
        QFile file(nom_fichier);

        if ((file.open(QIODevice::ReadOnly)) && (dom.setContent(&file)))
        {
            QDomElement docElem = dom.documentElement();
            QDomNode n = docElem.firstChild();
            QDomElement e = n.toElement();

            //QMessageBox::information(NULL, "Information", e.tagName());
            num->setValue(e.attribute("numero").toInt());

            n=n.nextSibling();
            e=n.toElement();
            nb_cases->setValue(e.attribute("nb_cases").toInt());
            //QMessageBox::information(NULL, "Information", e.tagName());

            nb_transitions->setValue(e.attribute("nb_transitions").toInt());
            //QMessageBox::information(NULL, "Transitions", e.tagName());

            select_generateur->setCurrentIndex(e.attribute("generation").toInt());

            n=n.nextSibling();
            e=n.toElement();

            n=e.firstChild();
            e=n.toElement();

            //QMessageBox::information(NULL, "Etat", e.tagName());

            if(page_dim1->findChild<QTableWidget*>("etat_depart_table"))//on teste si le tableau existe déjà
            {
                layout_page_etat_1->removeWidget(etat_depart_table);
                delete etat_depart_table;
            }

            dimension=nb_cases->value();

            etat_depart_table = new QTableWidget(1, dimension); //
            etat_depart_table->setFixedHeight(taille+40); // largeur = nombre_cellules*taille_cellule, hauteur = taille_cellule
            etat_depart_table->horizontalHeader()->setVisible(true); // masque le header (numéro des cases) horizontal
            etat_depart_table->verticalHeader()->setVisible(false); // masque le header vertical
            etat_depart_table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // désactive la scroll barre vertical
            etat_depart_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // désactive la scroll barre horizontal

            for(unsigned int counter = 0; counter < dimension; ++counter) {
                etat_depart_table->setColumnWidth(counter, taille);
                if(e.attribute("active").toUInt())
                {
                    etat_depart_table->setItem(0, counter, new QTableWidgetItem(""));
                    etat_depart_table->item(0, counter)->setBackgroundColor("black");
                }
                else
                {
                    etat_depart_table->setItem(0, counter, new QTableWidgetItem(""));
                    etat_depart_table->item(0, counter)->setBackgroundColor("white");
                }
                n=n.nextSibling();
                e=n.toElement();
            }

            etat_depart_table->setParent(page_dim1);
            layout_page_etat_1->addWidget(etat_depart_table);
            etat_depart_table->setObjectName(QString::fromUtf8("etat_depart_table"));
            connect(etat_depart_table, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation_dim1(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
            stacked_etat_depart->setCurrentIndex(1);
            Simulation->setEnabled(true);
            enregistrer_autodim1=true;
            actionEnregistrer->setEnabled(enregistrer_autodim1);

            file.close();
        }
    }
}

/*!
 *  \brief Slot virtual de gestion de l'enregistrement des automates
 *
 *  Slot permettant de gérer les actions d'enregistrement selon le type d'automate implémenté.
 *
 */
void Fenetre_AutoDim1::onActionEnregistrer()
{
    if(stacked_settings->currentIndex()==0)
    {
        emit onActionEnregistrer_dim1();
    }
}

/*!
 *  \brief Slot virtual de gestion de l'import des automates
 *
 *  Slot permettant de gérer les actions d'import selon le type d'automate implémenté.
 *
 */

void Fenetre_AutoDim1::onActionImporter()
{
    if(stacked_settings->currentIndex()==0)
    {
        emit onActionImporter_dim1();
    }
}

/*!
 *  \brief Méthode de génération aléatoire d'un état de départ à une dimension.
 *
 *  Méthode permettant de définir le comportement du générateur aléatoire pour les automates à une dimension : les cases sont générées aléatoirement vivantes ou mortes, avec une chance sur deux d'être vivante ou morte.
 *
 */

void Fenetre_AutoDim1::Gen_aleatoire()
{
    srand(time(NULL));
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        if(rand()%2)
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem());
            etat_depart_table->item(0, counter)->setBackgroundColor("white");
        }
        else
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem());
            etat_depart_table->item(0, counter)->setBackgroundColor("black");
        }
    }
    stacked_etat_depart->setCurrentIndex(1);
    Simulation->setEnabled(true);
    enregistrer_autodim1=true;
    actionEnregistrer->setEnabled(enregistrer_autodim1);
}

/*!
 *  \brief Méthode de génération d'une cellule sur deux d'un état de départ à une dimension.
 *
 *  Méthode permettant de définir le comportement du générateur d'une cellule sur deux pour les automates à une dimension.
 */


void Fenetre_AutoDim1::Gen_Un_Sur_Deux()
{
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        if(counter%2)
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem(""));
            etat_depart_table->item(0, counter)->setBackgroundColor("white");
            etat_depart_table->item(0, counter)->setTextColor("white");
        }
        else
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem());
            etat_depart_table->item(0, counter)->setBackgroundColor("black");
            etat_depart_table->item(0, counter)->setTextColor("black");
        }
    }
    stacked_etat_depart->setCurrentIndex(1);
    Simulation->setEnabled(true);
    enregistrer_autodim1=true;
    actionEnregistrer->setEnabled(enregistrer_autodim1);
}


/*!
 *  \brief Constructeur
 *
 *  Constructeur de la classe Fenetre_AutoDim2_GOL
 *
 *  \param MainWindow : Fenêtre princicpale (type Qt)
 */
Fenetre_AutoDim2_GOL::Fenetre_AutoDim2_GOL(QMainWindow *MainWindow):Fenetre_AutoDim1(MainWindow), taille_dim2(25),enregistrer_autodim2(false)
{
    /************************
     *
     * automate dimension 2
     *
     *
     ************************/

    select_type_automate->insertItem(select_type_automate->count(), "Jeu de la vie");

    page_dim2 = new QWidget();
    page_dim2->setObjectName(QString::fromUtf8("page_dim2"));
    stacked_settings->addWidget(page_dim2);

    layout_page_dim2 = new QVBoxLayout(page_dim2);
    layout_page_dim2->setObjectName(QString::fromUtf8("layout_page_dim2"));
    configuration_dim2 = new QGroupBox(page_dim2);
    configuration_dim2->setObjectName(QString::fromUtf8("configuration_dim2"));
    //configuration_dim2->setMaximumSize(QSize(900, 400));
    layout_config_dim2 = new QVBoxLayout(configuration_dim2);
    layout_config_dim2->setObjectName(QString::fromUtf8("layout_config_dim2"));
    regles_dim2 = new QHBoxLayout();
    regles_dim2->setObjectName(QString::fromUtf8("regles_dim2"));

    //règles de transition dim 2

    regles_transition_dim2 = new QGroupBox(configuration_dim2);
    regles_transition_dim2->setObjectName(QString::fromUtf8("regles_transition_dim2"));
    regles_transition_dim2->setMaximumSize(QSize(1500, 300));
    gridLayout = new QGridLayout(regles_transition_dim2);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    regles_creation_l = new QLabel(regles_transition_dim2);
    regles_creation_l->setObjectName(QString::fromUtf8("regles_creation_l"));

    gridLayout->addWidget(regles_creation_l, 1, 0, 1, 1);

    voisins_n_l = new QLabel(regles_transition_dim2);
    voisins_n_l->setObjectName(QString::fromUtf8("voisins_n_l"));
    voisins_n_l->setMaximumSize(QSize(1500, 15));

    gridLayout->addWidget(voisins_n_l, 0, 0, 1, 1);

    regles_mort_l = new QLabel(regles_transition_dim2);
    regles_mort_l->setObjectName(QString::fromUtf8("regles_mort_l"));

    gridLayout->addWidget(regles_mort_l, 2, 0, 1, 1);

    for(unsigned int i=0; i<8; i++)
    {
        voisins[i]=new QLabel(regles_transition_dim2);
        gridLayout->addWidget(voisins[i],0,i+1,1,1);
        voisins[i]->setObjectName(QString::fromUtf8("voisin").append(QString::number(i+1)));
        voisins[i]->raise();
        voisins[i]->setText(QApplication::translate("AutoCell LO21", QString::number(i+1).toUtf8(), 0));

        vie[i]=new QCheckBox(regles_transition_dim2);
        vie[i]->setObjectName(QString::fromUtf8("vie").append(QString::number(i+1)));
        gridLayout->addWidget(vie[i],1,i+1,1,1);
        vie[i]->raise();
        vie[i]->setText(QString());

        mort[i]=new QCheckBox(regles_transition_dim2);
        mort[i]->setObjectName(QString::fromUtf8("mort").append(QString::number(i+1)));
        gridLayout->addWidget(mort[i],2,i+1,1,1);
        mort[i]->raise();
        mort[i]->setText(QString());

    }


    voisins_n_l->raise();
    regles_creation_l->raise();
    regles_mort_l->raise();

    regles_dim2->addWidget(regles_transition_dim2);


    //générateur dim 2

    generateur_dim2 = new QGroupBox(configuration_dim2);
    generateur_dim2->setObjectName(QString::fromUtf8("generateur_dim2"));
    generateur_dim2->setMaximumSize(QSize(1500, 300));

    regles_dim2->addWidget(generateur_dim2);


    layout_config_dim2->addLayout(regles_dim2);

    select_generateur_dim2 = new QComboBox(generateur_dim2);
    select_generateur_dim2->setMaximumSize(QSize(120, 20));
    select_generateur_dim2_l=new QLabel("Génération");
    layout_select_generateur_dim2 = new QHBoxLayout;
    layout_select_generateur_dim2->addWidget(select_generateur_dim2_l);
    layout_select_generateur_dim2->addWidget(select_generateur_dim2);

    select_generateur_dim2->addItem(tr("Aléatoire"));
    select_generateur_dim2->addItem(tr("Manuelle"));
    select_generateur_dim2->addItem(tr("1 sur 2"));
    select_generateur_dim2->addItem(tr("Glider"));


    layout_page_dim2->addWidget(configuration_dim2);

    layout_generateur_dim2 = new QVBoxLayout;
    generateur_dim2->setLayout(layout_generateur_dim2);
    layout_generateur_dim2->addLayout(layout_select_generateur_dim2);
    nb_cases_dim2 = new QSpinBox();
    nb_cases_dim2->setRange(2, MAX_CASES_DIM2);
    nb_cases_dim2->setValue(50);
    nb_cases_dim2->setMaximumWidth(100);
    nb_cases_l_dim2 = new QLabel("Nombre de cases");
    layout_cases_dim2 = new QHBoxLayout;
    layout_cases_dim2->addWidget(nb_cases_l_dim2);
    layout_cases_dim2->addWidget(nb_cases_dim2);
    layout_generateur_dim2->addLayout(layout_cases_dim2);
    nb_cases_dim2->setEnabled(true);

    nb_transitions_dim2 = new QSpinBox();
    nb_transitions_dim2->setRange(1, MAX_TRANSITIONS_DIM2);
    nb_transitions_dim2->setValue(20);
    nb_transitions_dim2->setMaximumWidth(100);
    nb_transitions_l_dim2 = new QLabel("Nombre de transitions");
    layout_transitions_dim2 = new QHBoxLayout;
    layout_transitions_dim2->addWidget(nb_transitions_l_dim2);
    layout_transitions_dim2->addWidget(nb_transitions_dim2);
    layout_generateur_dim2->addLayout(layout_transitions_dim2);
    nb_transitions_dim2->setEnabled(true);

    bouton_generateur_dim2 = new QPushButton;
    bouton_generateur_dim2->setObjectName(QString::fromUtf8("bouton_generateur"));
    bouton_generateur_dim2->setMinimumSize(QSize(0, 50));
    bouton_generateur_dim2->setText(QApplication::translate("AutoCell LO21", "Générer", 0));
    bouton_generateur_dim2->setMaximumSize(QSize(1500, 50));
    layout_generateur_dim2->addWidget(bouton_generateur_dim2);
    generateur_dim2->setLayout(layout_generateur_dim2);

    //etat de départ dimension 2

    layout_page_etat_0_dim2 = new QVBoxLayout;
    aucun_etat_depart_dim2 = new QLabel("Générez/Importez un état de départ");
    layout_page_etat_0_dim2->addWidget(aucun_etat_depart_dim2);
    layout_page_etat_0_dim2->setAlignment(Qt::AlignHCenter);

    layout_etat_depart_dim2 = new QVBoxLayout;
    layout_etat_depart_dim2->setObjectName(QString::fromUtf8("layout_etat_depart_dim2"));

    etat_depart_l_dim2 = new QLabel(configuration_dim2);
    etat_depart_l_dim2->setObjectName(QString::fromUtf8("etat_depart_l_dim2"));
    etat_depart_l_dim2->setMinimumSize(QSize(100, 20));
    etat_depart_l_dim2->setMaximumSize(QSize(1500, 20));

    layout_etat_depart_dim2->addWidget(etat_depart_l_dim2);

    stacked_etat_depart_dim2 = new QStackedWidget;
    stacked_etat_depart_dim2->setObjectName(QString::fromUtf8("stacked_etat_depart_dim2"));
    stacked_etat_depart_dim2->setEnabled(true);
    page_etat_0_dim2 = new QWidget();
    page_etat_0_dim2->setObjectName(QString::fromUtf8("page_etat_0_dim2"));
    page_etat_0_dim2->setLayout(layout_page_etat_0_dim2);
    page_etat_1_dim2 = new QWidget();
    page_etat_1_dim2->setObjectName(QString::fromUtf8("page_etat_1_dim2"));
    layout_page_etat_1_dim2 = new QVBoxLayout;
    page_etat_1_dim2->setLayout(layout_page_etat_1_dim2);
    layout_page_etat_1_dim2->addWidget(etat_depart_l_dim2);
    stacked_etat_depart_dim2->addWidget(page_etat_0_dim2);
    stacked_etat_depart_dim2->addWidget(page_etat_1_dim2);
    stacked_etat_depart_dim2->raise();
    layout_page_dim2->addWidget(configuration_dim2);
    layout_config_dim2->addWidget(stacked_etat_depart_dim2);

    //bouton simulation dim2


    Simulation_dim2 = new QPushButton(page_dim2);
    Simulation_dim2->setObjectName(QString::fromUtf8("Simulation_dim2"));
    Simulation_dim2->setMinimumSize(QSize(0, 50));    Simulation_dim2->setMaximumSize(QSize(1500, 50));

    layout_page_dim2->addWidget(Simulation_dim2);
    stacked_settings->setCurrentIndex(0);

    Noms_dim2(MainWindow);

    //connexions

    connect(bouton_generateur_dim2, SIGNAL(clicked()), this, SLOT(onGenerateurButtonClicked_dim2()));
    connect(Simulation_dim2, SIGNAL(clicked()), this, SLOT(onSimulationButtonClicked_dim2()));
    for(unsigned int i=0; i<8; ++i)
    {
        connect(vie[i], SIGNAL(toggled(bool)), mort[i], SLOT(setDisabled(bool)));
        connect(mort[i], SIGNAL(toggled(bool)), vie[i], SLOT(setDisabled(bool)));
    }
    mort[0]->setChecked(true);
    mort[1]->setChecked(true);
    vie[3]->setChecked(true);
    mort[4]->setChecked(true);
    mort[5]->setChecked(true);
    mort[6]->setChecked(true);
    mort[7]->setChecked(true);
    Simulation_dim2->setEnabled(false);
    QMetaObject::connectSlotsByName(MainWindow);

}


/*!
*  \brief Méthode Noms_dim2
*
*  Méthode Noms de la classe Fenetre_AutoDim2_GOL permettant de nommer correctement tous les widget contenant du texte du Jeu de la Vie
*
*  \param MainWindow : Fenêtre princicpale (type Qt)
*/
void Fenetre_AutoDim2_GOL::Noms_dim2(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("AutoCell LO21", "AutoCell LO21", 0));
    actionEnregistrer->setText(QApplication::translate("AutoCell LO21", "Enregistrer", 0));
    actionImporter->setText(QApplication::translate("AutoCell LO21", "Importer", 0));
    type_automate->setTitle(QApplication::translate("AutoCell LO21", "S\303\251lectionner le type d'automate : ", 0));

    const bool __sortingEnabled = select_type_automate->isSortingEnabled();
    select_type_automate->setSortingEnabled(false);
    //QListWidgetItem *___qlistwidgetitem1 = select_type_automate->item(select_type_automate->count());
    //___qlistwidgetitem1->setText(QApplication::translate("AutoCell LO21", "Jeu de la vie", 0));
    select_type_automate->setSortingEnabled(__sortingEnabled);

    Affichage->setTitle(QApplication::translate("AutoCell LO21", "Affichage", 0));
    aff_manuel->setText(QApplication::translate("AutoCell LO21", "Manuel", 0));
    aff_auto->setText(QApplication::translate("AutoCell LO21", "Automatique", 0));
    unite_temps_aff->setText(QApplication::translate("AutoCell LO21", "sec", 0));
    configuration_dim2->setTitle(QApplication::translate("AutoCell LO21", "Configuration", 0));
    regles_transition_dim2->setTitle(QApplication::translate("AutoCell LO21", "R\303\250gles de transition", 0));

    regles_creation_l->setText(QApplication::translate("AutoCell LO21", "R\303\250gle de cr\303\251ation", 0));
    voisins_n_l->setText(QApplication::translate("AutoCell LO21", "Nombre de voisins : ", 0));
    regles_mort_l->setText(QApplication::translate("AutoCell LO21", "R\303\250gle de mort", 0));
    generateur_dim2->setTitle(QApplication::translate("AutoCell LO21", "G\303\251n\303\251rateur", 0));
    Simulation_dim2->setText(QApplication::translate("AutoCell LO21", "Lancer !", 0));
    menuR_glages_de_l_automate_cellulaire->setTitle(QApplication::translate("AutoCell LO21", "Fichiers de config", 0));
} // retranslateUi

void Fenetre_AutoDim2_GOL::onDimensionItemClicked(QListWidgetItem* item)
{
    if (select_type_automate->item(0) == item) {
            stacked_settings->setCurrentIndex(0);
            actionEnregistrer->setEnabled(enregistrer_autodim1);

        }
    else if(select_type_automate->item(1) == item)
    {
        stacked_settings->setCurrentIndex(1);
        actionEnregistrer->setEnabled(enregistrer_autodim2);
    }
}


/*!
*  \brief Slot de gestion du bouton de simulation du Jeu de la Vie
*
*  Slot permettant de gérer le bouton de simulation (Lancer !) afin de créer la fenêtre correspondant au Jeu de la Vie en appelant le constructeur avec les bons paramètres.
*
*/

void Fenetre_AutoDim2_GOL::onSimulationButtonClicked_dim2()
{
        int tab_regle[8];
        for(unsigned int i=0; i<8;++i)
        {
            tab_regle[i]=1+vie[i]->isChecked();
            tab_regle[i]-=mort[i]->isChecked();
        }
        new_Window_dim2 = new Window_Dim2_GOL(nullptr, dimension_dim2, nb_transitions_dim2->value(),aff_manuel->isChecked(), aff_temps_n->value()*1000,
                                          std::vector<short int>(tab_regle, tab_regle + sizeof(tab_regle) / sizeof tab_regle[0]));
        new_Window_dim2->setEtatDepart(etat_depart_table_dim2);
        //new_Window_dim2->setAttribute(Qt::WA_DeleteOnClose);
        new_Window_dim2->show();
        if(!aff_manuel->isChecked())
        {
            new_Window_dim2->launchSimulationAuto();
        }
}

/*!
 *  \brief Slot de gestion du générateur du Jeu de la Vie
 *
 *  Slot permettant de gérer la génération de l'état de départ du Jeu de la Vie ainsi que ses générateurs.
 *
 */

void Fenetre_AutoDim2_GOL::onGenerateurButtonClicked_dim2()
{
        if(page_dim2->findChild<QTableWidget*>("etat_depart_table_dim2"))//on teste si le tableau existe déjà
        {
            layout_page_etat_1_dim2->removeWidget(etat_depart_table_dim2);
            delete etat_depart_table_dim2;
        }
        dimension_dim2=nb_cases_dim2->value();
        etat_depart_table_dim2 = new QTableWidget(dimension_dim2, dimension_dim2); //
        etat_depart_table_dim2->horizontalHeader()->setVisible(true); // masque le header (numéro des cases) horizontal
        etat_depart_table_dim2->verticalHeader()->setVisible(true); // masque le header vertical
        etat_depart_table_dim2->setMaximumHeight(std::min((int)500, (int)((int)dimension_dim2*(int)taille_dim2)));
        etat_depart_table_dim2->setMaximumWidth(taille_dim2*dimension_dim2+2);
        etat_depart_table_dim2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre vertical
        etat_depart_table_dim2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre horizontal
        // création des items du QTableWidget, initialisés à "" avec un fond blanc
        //on initialise toutes les cases avec un symbole représentant une case à l'état 0, ici, c'est "", une chaîne vide.

        for(unsigned int counter = 0; counter < dimension_dim2; ++counter) {
            etat_depart_table_dim2->setRowHeight(counter, taille_dim2);
            for(unsigned int counter2=0; counter2<dimension_dim2; ++counter2){
                etat_depart_table_dim2->setColumnWidth(counter2, taille_dim2);
                etat_depart_table_dim2->setItem(counter, counter2, new QTableWidgetItem(""));
                etat_depart_table_dim2->item(counter, counter2)->setBackgroundColor("white");//vide donc couleur = blanc
                etat_depart_table_dim2->item(counter, counter2)->setTextColor("white");//idem, on ne veut pas voir le texte à l'intérieur (même pas besoin car c'est une chaîne vide)
            }
        }

        etat_depart_table_dim2->setParent(page_dim2);
        layout_page_etat_1_dim2->addWidget(etat_depart_table_dim2);
        etat_depart_table_dim2->setObjectName(QString::fromUtf8("etat_depart_table_dim2"));
        connect(etat_depart_table_dim2, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation_dim2(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
        if(select_generateur_dim2->currentText()==tr("Aléatoire"))
        {
            Gen_aleatoire_dim2();
        }
        else if(select_generateur_dim2->currentText()==tr("Manuelle"))
        {
            stacked_etat_depart_dim2->setCurrentIndex(1);
            Simulation_dim2->setEnabled(true);
            stacked_etat_depart_dim2->setCurrentIndex(1);
            //enregistrer_auto_dim2=true;
            //actionEnregistrer_dim2->setEnabled(enregistrer_autodim2);
        }
        else if(select_generateur_dim2->currentText()==tr("1 sur 2"))
        {
            Gen_Un_Sur_Deux_dim2();
        }
        else if(select_generateur_dim2->currentText() == tr("Glider"))
        {
            Gen_Glider();
        }
}

/*!
*  \brief Slot de gestion des cliques sur l'état de départ du Jeu de la Vie.
*
*  Slot permettant de gérer l'activation des cellules de l'état de départ.
*
*  \param index : index de la cellule cliquée
*/

void Fenetre_AutoDim2_GOL::cellActivation_dim2(QTableWidgetItem *index) {
    if (etat_depart_table_dim2->item(index->row(), index->column())->backgroundColor() == "white") {//si la cellule était morte, on la fait vivre (elle passe du blanc au noir)

        etat_depart_table_dim2->item(index->row(), index->column())->setBackgroundColor("black");

    } else {//au contraire, on passe du noir au blanc si la cellule était vivante

        etat_depart_table_dim2->item(index->row(), index->column())->setBackgroundColor("white");

    }
}

/*!
*  \brief Méthode de génération aléatoire d'un état de départ du Jeu de la Vie.
*
*  Méthode permettant de générer aléatoirement des cellules en vie pour l'état de départ du Jeu de la Vie (une cellule a une chance sur 6 d'être vivante)
*
*/
void Fenetre_AutoDim2_GOL::Gen_aleatoire_dim2()
{
    srand(time(NULL));

    for(unsigned int counter = 0; counter < dimension_dim2; ++counter) {
        for(unsigned int counter2=0; counter2<dimension_dim2; ++counter2){
            if(rand()%6)
            {
                etat_depart_table_dim2->item(counter, counter2)->setBackgroundColor("white");
            }
            else
            {
                etat_depart_table_dim2->item(counter, counter2)->setBackgroundColor("black");
            }
        }
    }
    stacked_etat_depart_dim2->setCurrentIndex(1);
    Simulation_dim2->setEnabled(true);
    enregistrer_autodim2=true;
    actionEnregistrer->setEnabled(enregistrer_autodim2);
}

/*!
 *  \brief Méthode de génération d'une cellule sur deux d'un état de départ du Jeu de la Vie.
 *
 *  Méthode permettant de définir le comportement du générateur d'une cellule sur deux pour le Jeu de la Vie.
 */
void Fenetre_AutoDim2_GOL::Gen_Un_Sur_Deux_dim2()
{
    for(unsigned int counter = 0; counter < dimension_dim2; ++counter) {
        for(unsigned int counter2=0; counter2<dimension_dim2; ++counter2){
            if((counter+counter2)%2)
            {
                etat_depart_table_dim2->setItem(counter, counter2, new QTableWidgetItem(""));
                etat_depart_table_dim2->item(counter, counter2)->setBackgroundColor("white");
                etat_depart_table_dim2->item(counter, counter2)->setTextColor("white");
            }
            else
            {
                etat_depart_table_dim2->setItem(counter, counter2, new QTableWidgetItem());
                etat_depart_table_dim2->item(counter, counter2)->setBackgroundColor("black");
                etat_depart_table_dim2->item(counter, counter2)->setTextColor("black");
            }
        }
    }
    stacked_etat_depart_dim2->setCurrentIndex(1);
    Simulation_dim2->setEnabled(true);
    enregistrer_autodim2=true;
    actionEnregistrer->setEnabled(enregistrer_autodim2);
}

/*!
 *  \brief Méthode de génération d'un glider pour le Jeu de la Vie.
 *
 *  Méthode permettant de définir le comportement du générateur d'un glider (pattern suivant une route rectiligne) pour le Jeu de la Vie.
 */

void Fenetre_AutoDim2_GOL::Gen_Glider()
{
    for(unsigned int i = 0; i < dimension_dim2; ++i) {
        for(unsigned int j=0; j<dimension_dim2; ++j){
            if((i==0&&j==2)||(i==1&&j==2)||(i==2&&j==2)||(i==2&&j==1)||(i==1&&j==0))
            {
                etat_depart_table_dim2->setItem(i, j, new QTableWidgetItem(""));
                etat_depart_table_dim2->item(i, j)->setBackgroundColor("black");
                etat_depart_table_dim2->item(i, j)->setTextColor("black");
            }
            else
            {
                etat_depart_table_dim2->setItem(i, j, new QTableWidgetItem());
                etat_depart_table_dim2->item(i, j)->setBackgroundColor("white");
                etat_depart_table_dim2->item(i, j)->setTextColor("white");
            }
        }
    }
    stacked_etat_depart_dim2->setCurrentIndex(1);
    Simulation_dim2->setEnabled(true);
    enregistrer_autodim2=true;
    actionEnregistrer->setEnabled(enregistrer_autodim2);
}

/*!
 *  \brief Slot de gestion de l'enregistrement des automates du Jeu de la Vie
 *
 *  Slot permettant d'enregistrer les automates du Jeu de la Vie dans un fichier XML du répertoire HOME de l'utilisateur.
 *
 */

void Fenetre_AutoDim2_GOL::onActionEnregistrer_dim2()
{
        QString path =QDir::homePath().append(QDir::toNativeSeparators(QString::fromUtf8("/Configs_dim_2/")));
        QDir dir;
        fichier = new QFileDialog;
        //fichier->setDefaultSuffix(QString::fromUtf8("txt"));
        if(!dir.exists(path))
        {
            dir.mkpath(path);
        }

        QString nom_fichier = fichier->getSaveFileName(centralwidget,
                                 QString::fromUtf8("Enregistrement de configuration"),
                                 path);

        if((nom_fichier.split(".").count()==1))
        {
            nom_fichier.append(".xml");
        }

        QFile file(nom_fichier);
        if ((file.open(QIODevice::ReadWrite)))
        {
            QDomDocument dom(nom_fichier.split("/").last());

            QTextStream stream(&file);

            //QDomElement base = dom.documentElement();
            QDomElement root = dom.createElement("root");
            dom.appendChild(root);

            QDomElement regles_root = dom.createElement("Regles");
            QDomElement regles[8];
            for(unsigned int i=0; i<8; ++i)
            {
                regles[i] = dom.createElement("Voisin"+QString::number(i+1));
                regles[i].setAttribute("vie", vie[i]->isChecked());
                regles[i].setAttribute("mort", mort[i]->isChecked());
                regles_root.appendChild(regles[i]);
            }
            root.appendChild(regles_root);

            QDomElement generator = dom.createElement("Generateur");
            generator.setAttribute("nb_cases", nb_cases_dim2->value());
            generator.setAttribute("nb_transitions", nb_transitions_dim2->value());
            generator.setAttribute("generation", select_generateur_dim2->currentIndex());
            root.appendChild(generator);

            QDomElement etat_dep = dom.createElement("Etat_depart");
            root.appendChild(etat_dep);

            QDomElement etats_dep[dimension_dim2][dimension_dim2];
            for(unsigned int i=0; i<dimension_dim2; ++i)
            {
                for(unsigned int j=0; j<dimension_dim2; ++j)
                {
                    etats_dep[i][j] = dom.createElement("Case"+QString::number(i)+tr("-")+QString::number(j));
                    etats_dep[i][j].setAttribute("ligne", i);
                    etats_dep[i][j].setAttribute("colonne", j);
                    etats_dep[i][j].setAttribute("active", etat_depart_table_dim2->item(i,j)->backgroundColor()=="black");
                    etat_dep.appendChild(etats_dep[i][j]);
                }
            }

            QString write_doc = dom.toString();
            stream << write_doc;

            file.close();
        }
}

/*!
 *  \brief Slot de gestion de l'import des automates du Jeu de la Vie
 *
 *  Slot permettant d'importer des automates du Jeu de la Vie à partir d'un fichier XML du répertoire HOME de l'utilisateur.
 *
 */

void Fenetre_AutoDim2_GOL::onActionImporter_dim2()
{
    QDir dir;
    QString path =QDir::homePath().append(QDir::toNativeSeparators(QString::fromUtf8("/Configs_dim_2/")));
    if(!dir.exists(path))
    {
        QMessageBox::information(NULL, "Information", "Aucune configuration n'a été préalablement enregistrée \nAucune configuration à importer.");
    }
    else
    {
        fichier = new QFileDialog;
        QString nom_fichier = fichier->getOpenFileName(centralwidget,
                                 QString::fromUtf8("Import de configuration"),
                                 path);

        QDomDocument dom;
        QFile file(nom_fichier);

        if ((file.open(QIODevice::ReadOnly)) && (dom.setContent(&file)))
        {
            QDomElement docElem = dom.documentElement();
            QDomNode n = docElem.firstChild();
            QDomElement e = n.firstChild().toElement();

            for(unsigned int i=0; i<8; ++i)
            {
                vie[i]->setChecked(e.attribute("vie").toUInt());
                mort[i]->setChecked(e.attribute("mort").toUInt());
                e=e.nextSiblingElement();
            }

            n=n.nextSibling();
            e=n.toElement();

            //QMessageBox::information(NULL, "Generateur", e.tagName());

            nb_cases_dim2->setValue(e.attribute("nb_cases").toInt());

            nb_transitions_dim2->setValue(e.attribute("nb_transitions").toInt());
            //QMessageBox::information(NULL, "Transitions", e.tagName());

            select_generateur_dim2->setCurrentIndex(e.attribute("generation").toInt());

            n=e.nextSibling();
            n=n.firstChild();
            e=n.toElement();

            //QMessageBox::information(NULL, "Etat_depart", e.tagName());

            if(page_dim2->findChild<QTableWidget*>("etat_depart_table_dim2"))//on teste si le tableau existe déjà
            {
                layout_page_etat_1_dim2->removeWidget(etat_depart_table_dim2);
                delete etat_depart_table_dim2;
            }

            dimension_dim2=nb_cases_dim2->value();
            etat_depart_table_dim2 = new QTableWidget(dimension_dim2, dimension_dim2); //
            etat_depart_table_dim2->horizontalHeader()->setVisible(true); // masque le header (numéro des cases) horizontal
            etat_depart_table_dim2->verticalHeader()->setVisible(true); // masque le header vertical
            etat_depart_table_dim2->setMaximumHeight(std::min((int)300, (int)((int)dimension_dim2*(int)taille_dim2)));
            etat_depart_table_dim2->setMaximumWidth(taille_dim2*dimension_dim2+2);

            etat_depart_table_dim2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre vertical
            etat_depart_table_dim2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre horizontal


            for(unsigned int counter = 0; counter < dimension_dim2; ++counter) {
                etat_depart_table_dim2->setRowHeight(counter, taille_dim2);
                for(unsigned int counter2=0; counter2<dimension_dim2; ++counter2){
                    if(e.attribute("active").toUInt())
                    {
                        etat_depart_table_dim2->setColumnWidth(counter2, taille_dim2);
                        etat_depart_table_dim2->setItem(counter, counter2, new QTableWidgetItem());
                        etat_depart_table_dim2->item(counter, counter2)->setBackgroundColor("black");
                        etat_depart_table_dim2->item(counter, counter2)->setTextColor("black");
                    }
                    else
                    {
                        etat_depart_table_dim2->setColumnWidth(counter2, taille_dim2);
                        etat_depart_table_dim2->setItem(counter, counter2, new QTableWidgetItem(""));
                        etat_depart_table_dim2->item(counter, counter2)->setBackgroundColor("white");
                        etat_depart_table_dim2->item(counter, counter2)->setTextColor("white");
                    }
                    n=n.nextSibling();
                    e=n.toElement();
                }
            }


            etat_depart_table_dim2->setParent(page_dim2);
            layout_page_etat_1_dim2->addWidget(etat_depart_table_dim2);
            etat_depart_table_dim2->setObjectName(QString::fromUtf8("etat_depart_table_dim2"));
            connect(etat_depart_table_dim2, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation_dim2(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
            stacked_etat_depart_dim2->setCurrentIndex(1);
            Simulation_dim2->setEnabled(true);
            enregistrer_autodim2=true;
            actionEnregistrer->setEnabled(enregistrer_autodim2);

            file.close();
        }
    }
}

void Fenetre_AutoDim2_GOL::onActionEnregistrer()
{
    if(stacked_settings->currentIndex()==0)
    {
        emit onActionEnregistrer_dim1();
    }
    else if(stacked_settings->currentIndex()==1)
    {
        emit onActionEnregistrer_dim2();
    }
}

void Fenetre_AutoDim2_GOL::onActionImporter()
{
    if(stacked_settings->currentIndex()==0)
    {
        emit onActionImporter_dim1();
    }
    else if(stacked_settings->currentIndex()==1)
    {
        emit onActionImporter_dim2();
    }
}

/*!
 *  \brief Constructeur
 *
 *  Constructeur de la classe Fenetre_AutoDim2_Langton
 *
 *  \param MainWindow : Fenêtre princicpale (type Qt)
 */

Fenetre_AutoDim2_Langton::Fenetre_AutoDim2_Langton(QMainWindow *MainWindow):Fenetre_AutoDim2_GOL(MainWindow), taille_langton(25), enregistrer_autolangton(false)
{
    /************************
     *
     * automate fourmi de langton
     *
     *
     ************************/

    select_type_automate->insertItem(select_type_automate->count(), "Fourmi de Langton");

    page_langton = new QWidget();
    page_langton->setObjectName(QString::fromUtf8("page_langton"));
    stacked_settings->addWidget(page_langton);

    layout_page_langton = new QVBoxLayout(page_langton);
    layout_page_langton->setObjectName(QString::fromUtf8("layout_page_langton"));
    configuration_langton = new QGroupBox(page_langton);
    configuration_langton->setObjectName(QString::fromUtf8("configuration_langton"));
    //configuration_langton->setMaximumSize(QSize(900, 400));
    layout_config_langton = new QVBoxLayout(configuration_langton);
    layout_config_langton->setObjectName(QString::fromUtf8("layout_config_langton"));
    regles_langton = new QHBoxLayout();
    regles_langton->setObjectName(QString::fromUtf8("regles_langton"));


    //générateur langton

    generateur_langton = new QGroupBox(configuration_langton);
    generateur_langton->setObjectName(QString::fromUtf8("generateur_langton"));
    generateur_langton->setMaximumSize(QSize(1500, 300));

    regles_langton->addWidget(generateur_langton);


    layout_config_langton->addLayout(regles_langton);

    select_generateur_langton = new QComboBox(generateur_langton);
    select_generateur_langton->setMaximumSize(QSize(120, 20));
    select_generateur_langton_l=new QLabel("Génération");
    layout_select_generateur_langton = new QHBoxLayout;
    layout_select_generateur_langton->addWidget(select_generateur_langton_l);
    layout_select_generateur_langton->addWidget(select_generateur_langton);

    select_generateur_langton->addItem(tr("Aléatoire"));
    select_generateur_langton->addItem(tr("Manuelle"));


    layout_page_langton->addWidget(configuration_langton);

    layout_generateur_langton = new QVBoxLayout;
    generateur_langton->setLayout(layout_generateur_langton);
    layout_generateur_langton->addLayout(layout_select_generateur_langton);
    nb_cases_langton = new QSpinBox();
    nb_cases_langton->setRange(2, MAX_CASES_DIM2);
    nb_cases_langton->setValue(50);
    nb_cases_langton->setMaximumWidth(100);
    nb_cases_l_langton = new QLabel("Nombre de cases");
    layout_cases_langton = new QHBoxLayout;
    layout_cases_langton->addWidget(nb_cases_l_langton);
    layout_cases_langton->addWidget(nb_cases_langton);
    layout_generateur_langton->addLayout(layout_cases_langton);
    nb_cases_langton->setEnabled(true);

    nb_transitions_langton = new QSpinBox();
    nb_transitions_langton->setRange(1, MAX_TRANSITIONS_DIM2);
    nb_transitions_langton->setValue(20);
    nb_transitions_langton->setMaximumWidth(100);
    nb_transitions_l_langton = new QLabel("Nombre de transitions");
    layout_transitions_langton = new QHBoxLayout;
    layout_transitions_langton->addWidget(nb_transitions_l_langton);
    layout_transitions_langton->addWidget(nb_transitions_langton);
    layout_generateur_langton->addLayout(layout_transitions_langton);
    nb_transitions_langton->setEnabled(true);

    bouton_generateur_langton = new QPushButton;
    bouton_generateur_langton->setObjectName(QString::fromUtf8("bouton_generateur"));
    bouton_generateur_langton->setMinimumSize(QSize(0, 50));
    bouton_generateur_langton->setText(QApplication::translate("AutoCell LO21", "Générer", 0));
    bouton_generateur_langton->setMaximumSize(QSize(1500, 50));
    layout_generateur_langton->addWidget(bouton_generateur_langton);
    generateur_langton->setLayout(layout_generateur_langton);

    //etat de départ dimension 2

    layout_page_etat_0_langton = new QVBoxLayout;
    aucun_etat_depart_langton = new QLabel("Générez/Importez un état de départ");
    layout_page_etat_0_langton->addWidget(aucun_etat_depart_langton);
    layout_page_etat_0_langton->setAlignment(Qt::AlignHCenter);

    layout_etat_depart_langton = new QVBoxLayout;
    layout_etat_depart_langton->setObjectName(QString::fromUtf8("layout_etat_depart_langton"));

    etat_depart_l_langton = new QLabel(configuration_langton);
    etat_depart_l_langton->setObjectName(QString::fromUtf8("etat_depart_l_langton"));
    etat_depart_l_langton->setMinimumSize(QSize(100, 20));
    etat_depart_l_langton->setMaximumSize(QSize(1500, 20));

    layout_etat_depart_langton->addWidget(etat_depart_l_langton);

    stacked_etat_depart_langton = new QStackedWidget;
    stacked_etat_depart_langton->setObjectName(QString::fromUtf8("stacked_etat_depart_langton"));
    stacked_etat_depart_langton->setEnabled(true);
    page_etat_0_langton = new QWidget();
    page_etat_0_langton->setObjectName(QString::fromUtf8("page_etat_0_langton"));
    page_etat_0_langton->setLayout(layout_page_etat_0_langton);
    page_etat_1_langton = new QWidget();
    page_etat_1_langton->setObjectName(QString::fromUtf8("page_etat_1_langton"));
    layout_page_etat_1_langton = new QVBoxLayout;
    page_etat_1_langton->setLayout(layout_page_etat_1_langton);
    layout_page_etat_1_langton->addWidget(etat_depart_l_langton);
    stacked_etat_depart_langton->addWidget(page_etat_0_langton);
    stacked_etat_depart_langton->addWidget(page_etat_1_langton);
    stacked_etat_depart_langton->raise();
    layout_page_langton->addWidget(configuration_langton);
    layout_config_langton->addWidget(stacked_etat_depart_langton);

    //bouton simulation langton


    Simulation_langton = new QPushButton(page_langton);
    Simulation_langton->setObjectName(QString::fromUtf8("Simulation_langton"));
    Simulation_langton->setMinimumSize(QSize(0, 50));    Simulation_langton->setMaximumSize(QSize(1500, 50));

    layout_page_langton->addWidget(Simulation_langton);
    stacked_settings->setCurrentIndex(0);

    Noms_Langton(MainWindow);

    //connexions

    connect(bouton_generateur_langton, SIGNAL(clicked()), this, SLOT(onGenerateurButtonClicked_Langton()));
    connect(Simulation_langton, SIGNAL(clicked()), this, SLOT(onSimulationButtonClicked_Langton()));
    for(unsigned int i=0; i<8; ++i)
    {
        connect(vie[i], SIGNAL(toggled(bool)), mort[i], SLOT(setDisabled(bool)));
        connect(mort[i], SIGNAL(toggled(bool)), vie[i], SLOT(setDisabled(bool)));
    }
    mort[0]->setChecked(true);
    mort[1]->setChecked(true);
    vie[3]->setChecked(true);
    mort[4]->setChecked(true);
    mort[5]->setChecked(true);
    mort[6]->setChecked(true);
    mort[7]->setChecked(true);
    Simulation_langton->setEnabled(false);
    QMetaObject::connectSlotsByName(MainWindow);

}


/*!
*  \brief Méthode Noms_Langton
*
*  Méthode Noms de la classe Fenetre_AutoDim2_Langton permettant de nommer correctement tous les widget contenant du texte des automates de la Fourmi de Langton
*
*  \param MainWindow : Fenêtre princicpale (type Qt)
*/

void Fenetre_AutoDim2_Langton::Noms_Langton(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("AutoCell LO21", "AutoCell LO21", 0));
    actionEnregistrer->setText(QApplication::translate("AutoCell LO21", "Enregistrer", 0));
    actionImporter->setText(QApplication::translate("AutoCell LO21", "Importer", 0));
    type_automate->setTitle(QApplication::translate("AutoCell LO21", "S\303\251lectionner le type d'automate : ", 0));

    const bool __sortingEnabled = select_type_automate->isSortingEnabled();
    select_type_automate->setSortingEnabled(false);
    //QListWidgetItem *___qlistwidgetitem1 = select_type_automate->item(select_type_automate->count());
    //___qlistwidgetitem1->setText(QApplication::translate("AutoCell LO21", "Jeu de la vie", 0));
    select_type_automate->setSortingEnabled(__sortingEnabled);

    Affichage->setTitle(QApplication::translate("AutoCell LO21", "Affichage", 0));
    aff_manuel->setText(QApplication::translate("AutoCell LO21", "Manuel", 0));
    aff_auto->setText(QApplication::translate("AutoCell LO21", "Automatique", 0));
    unite_temps_aff->setText(QApplication::translate("AutoCell LO21", "sec", 0));
    configuration_langton->setTitle(QApplication::translate("AutoCell LO21", "Configuration", 0));

    regles_creation_l->setText(QApplication::translate("AutoCell LO21", "R\303\250gle de cr\303\251ation", 0));
    voisins_n_l->setText(QApplication::translate("AutoCell LO21", "Nombre de voisins : ", 0));
    regles_mort_l->setText(QApplication::translate("AutoCell LO21", "R\303\250gle de mort", 0));
    generateur_langton->setTitle(QApplication::translate("AutoCell LO21", "G\303\251n\303\251rateur", 0));
    Simulation_langton->setText(QApplication::translate("AutoCell LO21", "Lancer !", 0));
    menuR_glages_de_l_automate_cellulaire->setTitle(QApplication::translate("AutoCell LO21", "Fichiers de config", 0));
} // retranslateUi

void Fenetre_AutoDim2_Langton::onDimensionItemClicked(QListWidgetItem* item)
{
    if (select_type_automate->item(0) == item) {
            stacked_settings->setCurrentIndex(0);
            actionEnregistrer->setEnabled(enregistrer_autodim1);

        }
    else if(select_type_automate->item(1) == item)
    {
        stacked_settings->setCurrentIndex(1);
        actionEnregistrer->setEnabled(enregistrer_autodim2);
    }
    else if(select_type_automate->item(2) == item)
    {
        stacked_settings->setCurrentIndex(2);
        actionEnregistrer->setEnabled(enregistrer_autolangton);
    }

}

/*!
*  \brief Slot de gestion du bouton de simulation
*
*  Slot permettant de gérer le bouton de simulation (Lancer !) afin de créer la fenêtre correspondant à la Fourmi de Langton en appelant le constructeur avec les bons paramètres.
*
*/

void Fenetre_AutoDim2_Langton::onSimulationButtonClicked_Langton()
{
        new_Window_langton = new Window_Dim2_Langton(nullptr, dimension_langton, nb_transitions_langton->value(),aff_manuel->isChecked(), aff_temps_n->value()*1000);
        new_Window_langton->setEtatDepart(etat_depart_table_langton);
        new_Window_langton->show();
        if(!aff_manuel->isChecked())
        {
            new_Window_langton->launchSimulationAuto();
        }
}

/*!
 *  \brief Slot de gestion du générateur de la Fourmi de Langton
 *
 *  Slot permettant de gérer la génération de l'état de départ de la Fourmi de Langton ainsi que ses générateurs.
 *
 */

void Fenetre_AutoDim2_Langton::onGenerateurButtonClicked_Langton()
{
        if(page_langton->findChild<QTableWidget*>("etat_depart_table_langton"))//on teste si le tableau existe déjà
        {
            layout_page_etat_1_langton->removeWidget(etat_depart_table_langton);
            delete etat_depart_table_langton;
        }
        dimension_langton=nb_cases_langton->value();
        etat_depart_table_langton = new QTableWidget(dimension_langton, dimension_langton); //
        etat_depart_table_langton->horizontalHeader()->setVisible(true); // masque le header (numéro des cases) horizontal
        etat_depart_table_langton->verticalHeader()->setVisible(true); // masque le header vertical
        //etat_depart_table_langton->setMaximumHeight(std::min((int)300, (int)((int)dimension_langton*(int)taille_langton)));
        etat_depart_table_langton->setMaximumWidth(taille_langton*dimension_langton+2);
        etat_depart_table_langton->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre vertical
        etat_depart_table_langton->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre horizontal
        // création des items du QTableWidget, initialisés à "" avec un fond blanc
        //on initialise toutes les cases avec un symbole représentant une case à l'état 0, ici, c'est "", une chaîne vide.

        for(unsigned int counter = 0; counter < dimension_langton; ++counter) {
            etat_depart_table_langton->setRowHeight(counter, taille_langton);
            for(unsigned int counter2=0; counter2<dimension_langton; ++counter2){
                etat_depart_table_langton->setColumnWidth(counter2, taille_langton);
                etat_depart_table_langton->setItem(counter, counter2, new QTableWidgetItem(""));
                etat_depart_table_langton->item(counter, counter2)->setFlags(etat_depart_table_langton->item(counter, counter2)->flags() ^ Qt::ItemIsEditable);
            }
        }

        etat_depart_table_langton->setParent(page_langton);
        layout_page_etat_1_langton->addWidget(etat_depart_table_langton);
        etat_depart_table_langton->setObjectName(QString::fromUtf8("etat_depart_table_langton"));
        connect(etat_depart_table_langton, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation_Langton(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
        if(select_generateur_langton->currentText()==tr("Aléatoire"))
        {
            Gen_aleatoire_langton();
        }
        else if(select_generateur_langton->currentText()==tr("Manuelle"))
        {
            stacked_etat_depart_langton->setCurrentIndex(1);
            Simulation_langton->setEnabled(true);
            stacked_etat_depart_langton->setCurrentIndex(1);
        }
}

/*!
*  \brief Slot de gestion des cliques sur l'état de départ des automates de la Fourmi de Langton
*
*  Slot permettant de gérer l'activation des cellules de l'état de départ.
*
*  \param index : index de la cellule cliquée
*/

void Fenetre_AutoDim2_Langton::cellActivation_Langton(QTableWidgetItem *index) {//méthode pour changer l'état
    if (etat_depart_table_langton->item(index->row(), index->column())->text() == "") {
        QPixmap pixmap(":/arrow-right.png");
        QIcon ButtonIcon(pixmap);
        etat_depart_table_langton->item(index->row(), index->column())->setIcon(ButtonIcon);
        etat_depart_table_langton->item(index->row(), index->column())->setText("right");

    } else if(etat_depart_table_langton->item(index->row(), index->column())->text() == "right") {

        QPixmap pixmap(":/arrow-down.png");
        QIcon ButtonIcon(pixmap);
        etat_depart_table_langton->item(index->row(), index->column())->setIcon(ButtonIcon);
        etat_depart_table_langton->item(index->row(), index->column())->setText("down");
    }
    else if(etat_depart_table_langton->item(index->row(), index->column())->text() == "down") {

            QPixmap pixmap(":/arrow-left.png");
            QIcon ButtonIcon(pixmap);
            etat_depart_table_langton->item(index->row(), index->column())->setIcon(ButtonIcon);
            etat_depart_table_langton->item(index->row(), index->column())->setText("left");
        }
    else if(etat_depart_table_langton->item(index->row(), index->column())->text() == "left") {

            QPixmap pixmap(":/arrow-up.png");
            QIcon ButtonIcon(pixmap);
            etat_depart_table_langton->item(index->row(), index->column())->setIcon(ButtonIcon);
            etat_depart_table_langton->item(index->row(), index->column())->setText("up");
        }
    else
    {
        QPixmap pixmap("");
        QIcon ButtonIcon(pixmap);
        etat_depart_table_langton->item(index->row(), index->column())->setIcon(ButtonIcon);
        etat_depart_table_langton->item(index->row(), index->column())->setText("");
    }

}

/*!
 *  \brief Slot de gestion de l'enregistrement des automates de la Fourmi de Langton
 *
 *  Slot permettant d'enregistrer les automates de la Fourmi de Langton dans un fichier XML du répertoire HOME de l'utilisateur.
 *
 */

void Fenetre_AutoDim2_Langton::onActionEnregistrer_Langton()
{
    QString path =QDir::homePath().append(QDir::toNativeSeparators(QString::fromUtf8("/Configs_langton/")));
    QDir dir;
    fichier = new QFileDialog;
    //fichier->setDefaultSuffix(QString::fromUtf8("txt"));
    if(!dir.exists(path))
    {
        dir.mkpath(path);
    }

    QString nom_fichier = fichier->getSaveFileName(centralwidget,
                             QString::fromUtf8("Enregistrement de configuration"),
                             path);

    if((nom_fichier.split(".").count()==1))
    {
        nom_fichier.append(".xml");
    }

    QFile file(nom_fichier);
    if ((file.open(QIODevice::ReadWrite)))
    {
        QDomDocument dom(nom_fichier.split("/").last());

        QTextStream stream(&file);

        //QDomElement base = dom.documentElement();
        QDomElement root = dom.createElement("root");
        dom.appendChild(root);

        QDomElement generator = dom.createElement("Generateur");
        generator.setAttribute("nb_cases", nb_cases_langton->value());
        generator.setAttribute("nb_transitions", nb_transitions_langton->value());
        generator.setAttribute("generation", select_generateur_langton->currentIndex());
        root.appendChild(generator);

        QDomElement etat_dep = dom.createElement("Etat_depart");
        root.appendChild(etat_dep);

        QDomElement etats_dep[dimension_langton][dimension_langton];
        for(unsigned int i=0; i<dimension_langton; ++i)
        {
            for(unsigned int j=0; j<dimension_langton; ++j)
            {
                etats_dep[i][j] = dom.createElement("Case"+QString::number(i)+tr("-")+QString::number(j));
                etats_dep[i][j].setAttribute("ligne", i);
                etats_dep[i][j].setAttribute("colonne", j);
                etats_dep[i][j].setAttribute("active", etat_depart_table_langton->item(i,j)->text());
                etat_dep.appendChild(etats_dep[i][j]);
            }
        }

        QString write_doc = dom.toString();
        stream << write_doc;

        file.close();
    }
}

/*!
 *  \brief Slot de gestion de l'import des automates de la Fourmi de Langton
 *
 *  Slot permettant d'importer les automates de la Fourmi de Langton à partir d'un fichier XML du répertoire HOME de l'utilisateur.
 *
 */

void Fenetre_AutoDim2_Langton::onActionImporter_Langton()
{
    QDir dir;
    QString path =QDir::homePath().append(QDir::toNativeSeparators(QString::fromUtf8("/Configs_langton/")));

    if(!dir.exists(path))
    {
        QMessageBox::information(NULL, "Information", "Aucune configuration n'a été préalablement enregistrée \nAucune configuration à importer.");
    }
    else
    {
        fichier = new QFileDialog;
        QString nom_fichier = fichier->getOpenFileName(centralwidget,
                                 QString::fromUtf8("Import de configuration"),
                                 path);
        QDomDocument dom;
        QFile file(nom_fichier);

        if ((file.open(QIODevice::ReadOnly)) && (dom.setContent(&file)))
        {
            QDomElement docElem = dom.documentElement();
            QDomNode n = docElem.firstChild();
            QDomElement e = n.toElement();

            //QMessageBox::information(NULL, "Generateur", e.tagName());

            nb_cases_langton->setValue(e.attribute("nb_cases").toInt());

            nb_transitions_langton->setValue(e.attribute("nb_transitions").toInt());
            //QMessageBox::information(NULL, "Transitions", e.tagName());

            select_generateur_langton->setCurrentIndex(e.attribute("generation").toInt());

            n=e.nextSibling();
            n=n.firstChild();
            e=n.toElement();

            //QMessageBox::information(NULL, "Etat_depart", e.tagName());

            if(page_langton->findChild<QTableWidget*>("etat_depart_table_langton"))//on teste si le tableau existe déjà
            {
                layout_page_etat_1_langton->removeWidget(etat_depart_table_langton);
                delete etat_depart_table_langton;
            }

            dimension_langton=nb_cases_langton->value();
            etat_depart_table_langton = new QTableWidget(dimension_langton, dimension_langton); //
            etat_depart_table_langton->horizontalHeader()->setVisible(true); // masque le header (numéro des cases) horizontal
            etat_depart_table_langton->verticalHeader()->setVisible(true); // masque le header vertical
            etat_depart_table_langton->setMinimumHeight(std::min((int)300, (int)((int)dimension_langton*(int)taille_langton)));
            etat_depart_table_langton->setMaximumWidth(taille_langton*dimension_langton+2);
            etat_depart_table_langton->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre vertical
            etat_depart_table_langton->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); // désactive la scroll barre horizontal


            for(unsigned int counter = 0; counter < dimension_langton; ++counter) {
                etat_depart_table_langton->setRowHeight(counter, taille_langton);
                for(unsigned int counter2=0; counter2<dimension_langton; ++counter2){
                    if(e.attribute("active")=="")
                    {
                        etat_depart_table_langton->setColumnWidth(counter2, taille_langton);
                        etat_depart_table_langton->setItem(counter, counter2, new QTableWidgetItem(""));
                        QPixmap pixmap("");
                        QIcon ButtonIcon(pixmap);
                        etat_depart_table_langton->item(counter, counter2)->setIcon(ButtonIcon);
                    }
                    else if(e.attribute("active")=="right")
                    {
                        etat_depart_table_langton->setColumnWidth(counter2, taille_langton);
                        etat_depart_table_langton->setItem(counter, counter2, new QTableWidgetItem("right"));
                        QPixmap pixmap(":/arrow-right.png");
                        QIcon ButtonIcon(pixmap);
                        etat_depart_table_langton->item(counter, counter2)->setIcon(ButtonIcon);
                    }
                    else if(e.attribute("active")=="down")
                    {
                        etat_depart_table_langton->setColumnWidth(counter2, taille_langton);
                        etat_depart_table_langton->setItem(counter, counter2, new QTableWidgetItem("down"));
                        QPixmap pixmap(":/arrow-down.png");
                        QIcon ButtonIcon(pixmap);
                        etat_depart_table_langton->item(counter, counter2)->setIcon(ButtonIcon);
                    }
                    else if(e.attribute("active")=="left")
                    {
                        etat_depart_table_langton->setColumnWidth(counter2, taille_langton);
                        etat_depart_table_langton->setItem(counter, counter2, new QTableWidgetItem("left"));
                        QPixmap pixmap(":/arrow-left.png");
                        QIcon ButtonIcon(pixmap);
                        etat_depart_table_langton->item(counter, counter2)->setIcon(ButtonIcon);
                    }
                    else if(e.attribute("active")=="up"){
                        etat_depart_table_langton->setColumnWidth(counter2, taille_langton);
                        etat_depart_table_langton->setItem(counter, counter2, new QTableWidgetItem("up"));
                        QPixmap pixmap(":/arrow-up.png");
                        QIcon ButtonIcon(pixmap);
                        etat_depart_table_langton->item(counter, counter2)->setIcon(ButtonIcon);
                    }
                    etat_depart_table_langton->item(counter, counter2)->setFlags(etat_depart_table_langton->item(counter, counter2)->flags() ^ Qt::ItemIsEditable);
                    n=n.nextSibling();
                    e=n.toElement();
                }
            }


            etat_depart_table_langton->setParent(page_langton);
            layout_page_etat_1_langton->addWidget(etat_depart_table_langton);
            etat_depart_table_langton->setObjectName(QString::fromUtf8("etat_depart_table_langton"));
            connect(etat_depart_table_langton, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation_Langton(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
            stacked_etat_depart_langton->setCurrentIndex(1);
            Simulation_langton->setEnabled(true);
            enregistrer_autolangton=true;
            actionEnregistrer->setEnabled(enregistrer_autolangton);

            file.close();
        }
    }

}

void Fenetre_AutoDim2_Langton::onActionEnregistrer()
{
    if(stacked_settings->currentIndex()==0)
    {
        emit onActionEnregistrer_dim1();
    }
    else if(stacked_settings->currentIndex()==1)
    {
        emit onActionEnregistrer_dim2();
    }
    else if(stacked_settings->currentIndex()==2)
    {
        emit onActionEnregistrer_Langton();
    }

}

void Fenetre_AutoDim2_Langton::onActionImporter()
{
    if(stacked_settings->currentIndex()==0)
    {
        emit onActionImporter_dim1();
    }
    else if(stacked_settings->currentIndex()==1)
    {
        emit onActionImporter_dim2();
    }
    else if(stacked_settings->currentIndex()==2)
    {
        emit onActionImporter_Langton();
    }
}


/*!
*  \brief Méthode de génération aléatoire d'un état de départ de la Fourmi de Langton.
*
*  Méthode permettant de définir le comportement du générateur aléatoire pour les automates de la Fourmi de Langton :
* on place une fourmi sur une cellule choisie pseudo-aléatoirement.
* Sa direction est aussi choisie pseudo-aléatoirement
*
*/

void Fenetre_AutoDim2_Langton::Gen_aleatoire_langton()
{
    srand(time(NULL));
    unsigned int fourmi = rand()%(dimension_langton*dimension_langton);
    int direction = rand()%4;
    QString directions[4]={tr("right"), tr("down"), tr("left"), tr("top")};
    QString logo[4]={tr(":/arrow-right.png"), tr(":/arrow-down.png"), tr(":/arrow-left.png"), tr(":/arrow-top.png")};
    for(unsigned int counter = 0; counter < dimension_langton; ++counter) {
        for(unsigned int counter2=0; counter2<dimension_langton; ++counter2){
            if(counter*dimension_langton+counter2==fourmi)
            {
                QPixmap pixmap(logo[direction]);
                QIcon ButtonIcon(pixmap);
                etat_depart_table_langton->item(counter, counter2)->setIcon(ButtonIcon);
                etat_depart_table_langton->item(counter, counter2)->setText(directions[direction]);
            }
        }
    }
    stacked_etat_depart_langton->setCurrentIndex(1);
    Simulation_langton->setEnabled(true);
    enregistrer_autolangton=true;
    actionEnregistrer->setEnabled(enregistrer_autolangton);
}

