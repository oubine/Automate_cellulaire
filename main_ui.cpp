#include "main_UI.h"
#include "automate.h"

void Ui_MainWindow::setupUi(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("Automates Cellulaires"));
    MainWindow->resize(850, 544);
    MainWindow->setMaximumSize(QSize(1000, 900));
    actionEnregistrer = new QAction(MainWindow);
    actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
    actionEnregistrer->setEnabled(false);
    actionImporter = new QAction(MainWindow);
    actionImporter->setObjectName(QString::fromUtf8("actionImporter"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    layout_main = new QVBoxLayout(centralwidget);
    layout_main->setObjectName(QString::fromUtf8("layout_main"));
    reglages_generaux = new QGroupBox(centralwidget);
    reglages_generaux->setObjectName(QString::fromUtf8("reglages_generaux"));
    reglages_generaux->setMaximumSize(QSize(1000, 150));
    layout_reglages_generaux = new QHBoxLayout(reglages_generaux);
    layout_reglages_generaux->setObjectName(QString::fromUtf8("layout_reglages_generaux"));
    type_automate = new QGroupBox(reglages_generaux);
    type_automate->setObjectName(QString::fromUtf8("type_automate"));
    type_automate->setMinimumSize(QSize(260, 90));
    type_automate->setMaximumSize(QSize(300, 100));
    layout_type_automate = new QVBoxLayout(type_automate);
    layout_type_automate->setObjectName(QString::fromUtf8("layout_type_automate"));
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
    select_type_automate->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    select_type_automate->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    layout_type_automate->addWidget(select_type_automate);


    layout_reglages_generaux->addWidget(type_automate);

    Affichage = new QGroupBox(reglages_generaux);
    Affichage->setObjectName(QString::fromUtf8("Affichage"));
    Affichage->setMaximumSize(QSize(1500, 100));
    layout_affichage = new QFormLayout(Affichage);
    layout_affichage->setObjectName(QString::fromUtf8("layout_affichage"));
    layout_affichage->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    aff_manuel = new QRadioButton(Affichage);
    aff_manuel->setObjectName(QString::fromUtf8("aff_manuel"));

    layout_affichage->setWidget(0, QFormLayout::LabelRole, aff_manuel);

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

    /***********************
     *
     * automate dimension 1
     *
     *
     ***********************/

    page_dim1 = new QWidget();
    page_dim1->setObjectName(QString::fromUtf8("page_dim1"));
    layout_page_dim1 = new QVBoxLayout(page_dim1);
    layout_page_dim1->setObjectName(QString::fromUtf8("layout_page_dim1"));

    //configuration dimension 1

    configuration_dim1 = new QGroupBox(page_dim1);
    configuration_dim1->setObjectName(QString::fromUtf8("configuration_dim1"));
    configuration_dim1->setMaximumSize(QSize(900, 400));

    regles_dim1 = new QHBoxLayout();
    regles_dim1->setObjectName(QString::fromUtf8("regles_dim1"));


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
    bouton_generateur->setText(QApplication::translate("MainWindow", "Générer", 0));
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
    Simulation->setMaximumSize(QSize(1500, 50));

    layout_page_dim1->addWidget(Simulation);

    stacked_settings->addWidget(page_dim1);
    Simulation->setEnabled(false);

    /************************
     *
     * automate dimension 2
     *
     *
     ************************/

    page_dim2 = new QWidget();
    page_dim2->setObjectName(QString::fromUtf8("page_dim2"));
    layout_page_dim2 = new QVBoxLayout(page_dim2);
    layout_page_dim2->setObjectName(QString::fromUtf8("layout_page_dim2"));
    configuration_dim2 = new QGroupBox(page_dim2);
    configuration_dim2->setObjectName(QString::fromUtf8("configuration_dim2"));
    configuration_dim2->setMaximumSize(QSize(900, 400));
    layout_config_dim2 = new QHBoxLayout(configuration_dim2);
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
        voisins[i]->setText(QApplication::translate("MainWindow", QString::number(i+1).toUtf8(), 0));

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
    select_generateur_dim2->addItem(tr("Symétrique"));


    layout_page_dim2->addWidget(configuration_dim2);

    layout_generateur_dim2 = new QVBoxLayout;
    generateur_dim2->setLayout(layout_generateur_dim2);
    layout_generateur_dim2->addLayout(layout_select_generateur_dim2);
    nb_cases_dim2 = new QSpinBox();
    nb_cases_dim2->setRange(2, 50);
    nb_cases_dim2->setValue(30);
    nb_cases_dim2->setMaximumWidth(100);
    nb_cases_l_dim2 = new QLabel("Nombre de cases");
    layout_cases_dim2 = new QHBoxLayout;
    layout_cases_dim2->addWidget(nb_cases_l_dim2);
    layout_cases_dim2->addWidget(nb_cases_dim2);
    layout_generateur_dim2->addLayout(layout_cases_dim2);
    nb_cases_dim2->setEnabled(false);

    nb_transitions_dim2 = new QSpinBox();
    nb_transitions_dim2->setRange(1, 50);
    nb_transitions_dim2->setValue(10);
    nb_transitions_dim2->setMaximumWidth(100);
    nb_transitions_l_dim2 = new QLabel("Nombre de transitions");
    layout_transitions_dim2 = new QHBoxLayout;
    layout_transitions_dim2->addWidget(nb_transitions_l_dim2);
    layout_transitions_dim2->addWidget(nb_transitions_dim2);
    layout_generateur_dim2->addLayout(layout_transitions_dim2);
    nb_transitions_dim2->setEnabled(false);

    bouton_generateur_dim2 = new QPushButton;
    bouton_generateur_dim2->setObjectName(QString::fromUtf8("bouton_generateur"));
    bouton_generateur_dim2->setMinimumSize(QSize(0, 50));
    bouton_generateur_dim2->setText(QApplication::translate("MainWindow", "Générer", 0));
    bouton_generateur_dim2->setMaximumSize(QSize(1500, 50));
    layout_generateur_dim2->addWidget(bouton_generateur_dim2);
    generateur_dim2->setLayout(layout_generateur_dim2);


    //bouton simulation dim2


    Simulation_dim2 = new QPushButton(page_dim2);
    Simulation_dim2->setObjectName(QString::fromUtf8("Simulation_dim2"));
    Simulation_dim2->setMinimumSize(QSize(0, 50));    Simulation_dim2->setMaximumSize(QSize(1500, 50));

    layout_page_dim2->addWidget(Simulation_dim2);

    stacked_settings->addWidget(page_dim2);

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

    retranslateUi(MainWindow);
    Temps->setCurrentIndex(1);
    aff_manuel->setChecked(true);
    stacked_settings->setCurrentIndex(0);

    //connexion des signaux et des slots

    connect(num, SIGNAL(valueChanged(int)), this, SLOT(synchronizeNumToNumBit(int)));//réciproquement, on connecte le décimal au binaire

    for(unsigned int i=0; i<8; ++i)
    {
        connect(vie[i], SIGNAL(toggled(bool)), mort[i], SLOT(setDisabled(bool)));
        connect(mort[i], SIGNAL(toggled(bool)), vie[i], SLOT(setDisabled(bool)));
    }

    connect(select_type_automate, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onDimensionItemClicked(QListWidgetItem*)));
    connect(aff_manuel, SIGNAL(toggled(bool)), this, SLOT(onAffichageButtonClicked(bool)));
    connect(bouton_generateur, SIGNAL(clicked()), this, SLOT(onGenerateurButtonClicked()));
    connect(Simulation, SIGNAL(clicked()), this, SLOT(onSimulationButtonClicked()));
    connect(actionEnregistrer, SIGNAL(triggered()), this, SLOT(onActionEnregistrer()));
    connect(actionImporter, SIGNAL(triggered()), this, SLOT(onActionImporter()));

    connect(select_generateur, SIGNAL(activated(QString)), this, SLOT(set_Gen_options(QString)));
    QMetaObject::connectSlotsByName(MainWindow);

} // setupUi


void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0));
    actionImporter->setText(QApplication::translate("MainWindow", "Importer", 0));
    type_automate->setTitle(QApplication::translate("MainWindow", "S\303\251lectionner le type d'automate : ", 0));

    const bool __sortingEnabled = select_type_automate->isSortingEnabled();
    select_type_automate->setSortingEnabled(false);
    QListWidgetItem *___qlistwidgetitem = select_type_automate->item(0);
    ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Automates 1 dimension", 0));
    QListWidgetItem *___qlistwidgetitem1 = select_type_automate->item(1);
    ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Jeu de la vie", 0));
    select_type_automate->setSortingEnabled(__sortingEnabled);

    Affichage->setTitle(QApplication::translate("MainWindow", "Affichage", 0));
    aff_manuel->setText(QApplication::translate("MainWindow", "Manuel", 0));
    aff_auto->setText(QApplication::translate("MainWindow", "Automatique", 0));
    unite_temps_aff->setText(QApplication::translate("MainWindow", "sec", 0));
    configuration_dim1->setTitle(QApplication::translate("MainWindow", "Configuration", 0));
    regles_transition->setTitle(QApplication::translate("MainWindow", "R\303\250gles de transition", 0));
    generateur->setTitle(QApplication::translate("MainWindow", "G\303\251n\303\251rateur", 0));
    etat_depart_l->setText(QApplication::translate("MainWindow", "\303\211tat de d\303\251part", 0));
    Simulation->setText(QApplication::translate("MainWindow", "Lancer !", 0));
    configuration_dim2->setTitle(QApplication::translate("MainWindow", "Configuration", 0));
    regles_transition_dim2->setTitle(QApplication::translate("MainWindow", "R\303\250gles de transition", 0));

    regles_creation_l->setText(QApplication::translate("MainWindow", "R\303\250gle de cr\303\251ation", 0));
    voisins_n_l->setText(QApplication::translate("MainWindow", "Nombre de voisins : ", 0));
    regles_mort_l->setText(QApplication::translate("MainWindow", "R\303\250gle de mort", 0));
    generateur_dim2->setTitle(QApplication::translate("MainWindow", "G\303\251n\303\251rateur", 0));
    Simulation_dim2->setText(QApplication::translate("MainWindow", "Lancer !", 0));
    menuR_glages_de_l_automate_cellulaire->setTitle(QApplication::translate("MainWindow", "Enregistrement", 0));
} // retranslateUi


void Ui_MainWindow::onDimensionItemClicked(QListWidgetItem* item)
{
    if (select_type_automate->item(0) == item) {
            stacked_settings->setCurrentIndex(0);
            if(page_dim1->findChild<QTableWidget*>("etat_depart_table"))
            {
                actionEnregistrer->setEnabled(true);
            }
        }
    else if(select_type_automate->item(1) == item)
    {
        stacked_settings->setCurrentIndex(1);
        actionEnregistrer->setEnabled(false);
    }
}

void Ui_MainWindow::onAffichageButtonClicked(bool checked)
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

void Ui_MainWindow::onGenerateurButtonClicked()
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
    connect(etat_depart_table, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
    if(select_generateur->currentText()==tr("Aléatoire"))
    {
        Gen_aleatoire();
    }
    else if(select_generateur->currentText()==tr("Manuelle"))
    {
        stacked_etat_depart->setCurrentIndex(1);
        Simulation->setEnabled(true);
        actionEnregistrer->setEnabled(true);
    }
    else if(select_generateur->currentText()==tr("1 sur 2"))
    {
        Gen_Un_Sur_Deux();
    }
}

void Ui_MainWindow::onSimulationButtonClicked()
{
    new_Window_dim1 = new AutoCell(nullptr, dimension, nb_transitions->value(), num->value(),aff_manuel->isChecked(), aff_temps_n->value()*1000);
    new_Window_dim1->setEtatDepart(etat_depart_table);
    new_Window_dim1->show();
    if(!aff_manuel->isChecked())
    {
        new_Window_dim1->launchSimulationAuto();
    }
}

void Ui_MainWindow::cellActivation(QTableWidgetItem *index) {//méthode pour changer l'état
    if (etat_depart_table->item(0, index->column())->text() == "") {//si la cellule était morte, on la fait vivre (elle passe du blanc au noir)
        etat_depart_table->item(0, index->column())->setText("_");

        etat_depart_table->item(0, index->column())->setBackgroundColor("black");

        etat_depart_table->item(0, index->column())->setTextColor("black");
    } else {//au contraire, on passe du noir au blanc si la cellule était vivante
        etat_depart_table->item(0, index->column())->setText("");

        etat_depart_table->item(0, index->column())->setBackgroundColor("white");

        etat_depart_table->item(0, index->column())->setTextColor("white");
    }
}

void Ui_MainWindow::synchronizeNumToNumBit(int i) {//synchronisation de numéro de l'automate en décimal vers binaire
    std::string numBit = NumToNumBit(i);//string correspondant au numéro en binaire
    for(unsigned int counter = 0; counter < 8; ++counter) {
        numeroBit[counter]->setText(QString(numBit[counter]));//on convertit le std::string en string de Qt grâce à la méthode disponible dans Qt
    }
}

void Ui_MainWindow::synchronizeNumBitToNum(const QString& s) {//synchronisation de numéro de l'automate en binaire vers décimal
    if (s == "") {//on vérifie si la chaîne est vide
        return;
    }
    std::string numBit = "";//string correspondant au numéro en binaire
    for(unsigned int counter = 0; counter < 8; ++counter) {
        numBit += numeroBit[counter]->text().toStdString();//on convertit le string Qt en std::string
    }
    num->setValue(NumBitToNum(numBit));//on utilise la méthode fournie dans l'autre TD
}

void Ui_MainWindow::onActionEnregistrer()
{
    if(stacked_settings->currentIndex()==0)//dans le cas des automates de dimension 1
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
                etats_dep[i].setAttribute("active", etat_depart_table->item(0,i)->text()=="_");
                etat_dep.appendChild(etats_dep[i]);
            }

            QString write_doc = dom.toString();
            stream << write_doc;

            file.close();
        }
    }
}

void Ui_MainWindow::onActionImporter()
{
    if(stacked_settings->currentIndex()==0)//dans le cas des automates de dimension 1
    {
        fichier = new QFileDialog;
        QString path =QDir::homePath().append(QDir::toNativeSeparators(QString::fromUtf8("/Configs_dim_1/")));
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
            if(select_generateur->currentText()==tr("Aléatoire"))
            {
                nb_cases->setEnabled(false);
            }
            else
            {
                nb_cases->setEnabled(true);
            }

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
                    etat_depart_table->setItem(0, counter, new QTableWidgetItem("_"));
                    etat_depart_table->item(0, counter)->setBackgroundColor("black");
                    etat_depart_table->item(0, counter)->setTextColor("black");
                }
                else
                {
                    etat_depart_table->setItem(0, counter, new QTableWidgetItem(""));
                    etat_depart_table->item(0, counter)->setBackgroundColor("white");
                    etat_depart_table->item(0, counter)->setTextColor("white");
                }
                n=n.nextSibling();
                e=n.toElement();
            }

            etat_depart_table->setParent(page_dim1);
            layout_page_etat_1->addWidget(etat_depart_table);
            etat_depart_table->setObjectName(QString::fromUtf8("etat_depart_table"));
            connect(etat_depart_table, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(cellActivation(QTableWidgetItem*)));//on connecte un click avec l'activation d'une cellule sur l'état de départ
            stacked_etat_depart->setCurrentIndex(1);
            Simulation->setEnabled(true);
            actionEnregistrer->setEnabled(true);

            file.close();
        }
    }

}

void Ui_MainWindow::set_Gen_options(QString index)
{
    if(index=="Manuelle")
    {

        nb_cases->setEnabled(true);

    }
    else if(index=="Aléatoire")
    {
        srand (time(NULL));
        //nb_cases->setEnabled(false);
        //nb_cases->setValue(rand()%(MAX_CASES-1)+1);

    }
    else if(index=="1 sur 2")
    {
        nb_cases->setEnabled(true);
    }
}

void Ui_MainWindow::Gen_aleatoire()
{
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        etat_depart_table->setColumnWidth(counter, taille);
        if(rand()%2)
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem(""));
            etat_depart_table->item(0, counter)->setBackgroundColor("white");
            etat_depart_table->item(0, counter)->setTextColor("white");
        }
        else
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem("_"));
            etat_depart_table->item(0, counter)->setBackgroundColor("black");
            etat_depart_table->item(0, counter)->setTextColor("black");
        }
    }
    stacked_etat_depart->setCurrentIndex(1);
    Simulation->setEnabled(true);
    actionEnregistrer->setEnabled(true);
}

void Ui_MainWindow::Gen_Un_Sur_Deux()
{
    for(unsigned int counter = 0; counter < dimension; ++counter) {
        etat_depart_table->setColumnWidth(counter, taille);
        if(counter%2)
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem(""));
            etat_depart_table->item(0, counter)->setBackgroundColor("white");
            etat_depart_table->item(0, counter)->setTextColor("white");
        }
        else
        {
            etat_depart_table->setItem(0, counter, new QTableWidgetItem("_"));
            etat_depart_table->item(0, counter)->setBackgroundColor("black");
            etat_depart_table->item(0, counter)->setTextColor("black");
        }
    }
    stacked_etat_depart->setCurrentIndex(1);
    Simulation->setEnabled(true);
    actionEnregistrer->setEnabled(true);
}
