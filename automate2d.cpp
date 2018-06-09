#include "automate2d.h"
#include "etat.h"
#include <math.h>
#include <algorithm>
#include <chrono>

/**
* \brief Méthode qui définit le comportement de la méthode virtuelle appliquerTransition pour tous les automates à deux dimensions.
*
* On examine le voisinage de chaque cellule de l'état de départ et on affecte à la cellule de même index de l'état de destination
* l'image de l'état du voisinage par la règle locale de transition.
*
* @param[in] dep L'état avant la transition.

* @param[out] dest État dans lequel on va stocker l'état après la transition.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
void Automate2D::appliquerTransition(const Etat& dep, Etat& dest)
{
    auto start = std::chrono::high_resolution_clock::now();
    unsigned int etat;
    if (motif.size() == 0) throw AutomateException("Motif non défini");
    if (dep.getTaille() != dest.getTaille()) dest = dep;
    auto iExamine = IndexTab2D(0,0,dep.getTaille(),dep.getTaille());

    for (unsigned int i = 0; i < dep.size(); i++)
    {//iExamine : index de la case de l'état de départ examinée
        for(unsigned int j = 0; j < this->getMotif().size(); j++)
        {
            valVoisinage[j] = dep.getCellule(iExamine+motif[j]);
        }
        etat = baseToInt(std::vector<unsigned int>(valVoisinage,valVoisinage+nbVoisins()),dep.getValMax()+1);
        dest.setCellule(i, regleTransition[etat]);
        iExamine++;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time transition: " << elapsed.count() << " s\n";
}

/**
* \brief Fonction qui transforme une règle en fonction du nombre de voisins vivants en règle de transition
*
* La règle regleNaissMort est sous la forme d'un vector de short int
* qui prennent leur valeur dans l'intervalle [0,2] où 0 = mort, 1 = pas d'effet et 2 = naissance
*  et où l'index du short int représente le nombre de voisins
* exemple avec le règle du jeu de la vie classique : vector(0,0,1,2,0,0,0,0,0)
*                                     nb de voisins en vie  0 1 2 3 4 5 6 7 8
* On doit la transformer en une règle de transition qui à chaque
* état du voisinage de la cellule examinée associe son nouvel état à l'issu de la transition.
* Le voisinage de la cellule considérée est la liste de case suivante (cf. VarianteJeuDeLaVie::getMotifElementaire):
* [(0,0),(-1,1),(-1,0),(-1,-1),(0,1),(0,-1),(1,1),(1,0),(1,-1)]
* Ainsi pour l'état du voisinage e1[0,0,0,0,0,0,1,1,1] la cellule considérée (e1[0] = 0) a 3 voisins
* vivants et doit donc naître, la case n° 7-1 de la règle de transition va donc valoir 2
* (le 7 est la traduction en base 10 du nombre binaire 000000111)
*
* @param[in] regleNaissMort La règle en fonction du nombre de voisins vivants.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
std::vector<unsigned int> fromRegleNaissMortToRegleTransition(std::vector<short int> regleNaissMort)
{
    std::vector<unsigned int> etatBinaire;
    unsigned int nbEtats = pow(2,9);
    unsigned int nbVoisinsVivants = 0;
    std::vector<unsigned int> resultat (nbEtats, 0); //le resultat est évidemment la règle à construire
    for(unsigned int i = 0; i < nbEtats; i++)
    {
        etatBinaire = intToBase(i,2);
        while (etatBinaire.size() < 9) etatBinaire.insert(etatBinaire.begin(),0);
        nbVoisinsVivants = std::count(etatBinaire.begin()+1,etatBinaire.end(),1);
        if(regleNaissMort[nbVoisinsVivants] == 1)//la case examinée ne doit pas changer d'état
        {
            resultat[i] = etatBinaire[0]; // rappelons que la première case du motif porte l'information de la case examinée
        }
        else if(regleNaissMort[nbVoisinsVivants] == 0) //la case examinée doit mourir
        {
            resultat[i] = 0;
        }
        else //la case examinée doit naître
        {
            resultat[i] = 1;
        }
    }
    return resultat;
}

/**
* \brief Méthode statique qui renvoie le motif des variantes du jeu de la vie : [(0,0),(-1,1),(-1,0),(-1,-1),(0,1),(0,-1),(1,1),(1,0),(1,-1)]
*
* Les règles pour les variantes du jeu de la vie sont symétriques par rapport à la cellule centrale,
* la cellule du centre étant plus importante, on la place en première dans le motif,
* cela simplifiera la création de la règle de l'automate.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
std::vector<std::vector<int>> VarianteJeuDeLaVie::getMotifElementaire()
{
    std::vector<std::vector<int>> motif(9, std::vector<int>(2));
    //les règles pour les variantes du jeu de la vie sont symétriques par rapport à la cellule centrale
    //la cellule du centre étant plus importante, on la place en première dans le motif
    //cela simplifiera la création de la règle de l'automate
    motif[0][0] = 0; motif[0][1] = 0;
    motif[1][0] = -1; motif[1][1] = 1;
    motif[2][0] = -1; motif[2][1] = 0;
    motif[3][0] = -1; motif[3][1] = -1;
    motif[4][0] = 0; motif[4][1] = 1;
    motif[5][0] = 0; motif[5][1] = -1;
    motif[6][0] = 1; motif[6][1] = 1;
    motif[7][0] = 1; motif[7][1] = 0;
    motif[8][0] = 1; motif[8][1] = -1;
    return motif;
}

/**
* \brief Méthode statique qui renvoie le motif de la fourmi de Langton : [(0,0),(0,-1),(-1,0),(0,1),(1,0)]
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
std::vector<std::vector<int>> FourmiLangton::getMotif()
{
    std::vector<std::vector<int>> resultat(5, std::vector<int>(2));
    resultat[0][0] = 0; resultat[0][1] = 0;
    resultat[1][0] = 0; resultat[1][1] = -1;
    resultat[2][0] = -1; resultat[2][1] = 0;
    resultat[3][0] = 0; resultat[3][1] = 1;
    resultat[4][0] = 1; resultat[4][1] = 0;
    return resultat;
}


/**
* \brief Méthode statique qui renvoie la règle locale de transition pour la fourmi de langton.
*
*  Si la valeur de la cellule est paire, la case est non marquée. Si la valeur de la cellule est impaire, la case est marquée.
* {0,1} -> cellule vide;
* {2,3} -> fourmi orientée vers l'ouest;
* {4,5} -> fourmi orientée vers le nord;
* {6,7} -> fourmi orientée vers l'est;
* {8,9} -> fourmi orientée vers le sud;
* collision de deux fourmis -> destruction mutuelle
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
std::vector<unsigned int> FourmiLangton::getRegle()
{
    //numero pair -> case non marquée    impair -> marquée
    //0,1:vide 2,3:ouest 4,5:nord 6,7:est 8,9:sud
    //collision de deux fourmi -> destruction mutuelle
    unsigned int nbEtat = pow(10,5);
    auto resultat = std::vector<unsigned int>(nbEtat,0);
    std::vector<unsigned int> etatBinaire;
    int nbFourmiArriveSurLaCaseCentrale;
    for(unsigned int i = 0; i < nbEtat; i++)
    {
        nbFourmiArriveSurLaCaseCentrale = 0;
        etatBinaire = intToBase(i,10);
        while (etatBinaire.size() < 5) etatBinaire.insert(etatBinaire.begin(),0);
        //la case centrale contient une fourmi
        if(etatBinaire[0] > 1)
        { // elle la quitte
            etatBinaire[0] = (etatBinaire[0]+1)%2;
        }
        //une fourmi arrive sur la case centrale
        if(etatBinaire[1] == 4 || etatBinaire[1] == 9) //une fourmi arrive depuis l'ouest
        {
            resultat[i] = etatBinaire[0]%2+6;
            nbFourmiArriveSurLaCaseCentrale++;
        }
        if(etatBinaire[2] == 6 || etatBinaire[2] == 3) //une fourmi arrive depuis le nord
        {
            resultat[i] = etatBinaire[0]%2+8;
            nbFourmiArriveSurLaCaseCentrale++;
        }
        if(etatBinaire[3] == 8 || etatBinaire[3] == 5) //une fourmi arrive depuis l'est
        {
            resultat[i] = etatBinaire[0]%2+2;
            nbFourmiArriveSurLaCaseCentrale++;
        }
        if(etatBinaire[4] == 2 || etatBinaire[4] == 7) //une fourmi arrive depuis le sud
        {
            resultat[i] = etatBinaire[0]%2+4;
            nbFourmiArriveSurLaCaseCentrale++;
        }
        if(nbFourmiArriveSurLaCaseCentrale == 0) resultat[i] = etatBinaire[0];
        if(nbFourmiArriveSurLaCaseCentrale > 1)//plusieurs fourmis sont arrivées sur la même case centrale
            resultat[i] %= 2; // elles s'annihilent
    }
    return resultat;
}
