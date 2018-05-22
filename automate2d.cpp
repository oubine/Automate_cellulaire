#include "automate2d.h"
#include "etat.h"
#include <math.h>
#include <algorithm>


void Automate2D::appliquerTransition(const Etat& dep, Etat& dest)
{
    if (this->getMotif().size() == 0) throw AutomateException("Motif non défini");
    if (dep.getTaille() != dest.getTaille()) dest = dep;
    auto iExamine = IndexTab2D(0,0,dep.getTaille(),dep.getTaille());
    for (unsigned int i = 0; i < dep.size(); i++)
    {//iExamine : index de la case de l'état de départ examinée
        for(unsigned int j = 0; j < this->getMotif().size(); j++)
        {//this->getMotif()[j] : index relatif des voisins par rapport à la case examinée
            /*iExamine = IndexTab2D(0,0,dep.getTaille(),dep.getTaille());
            iExamine += this->getMotif()[j];*/
            this->setVoisin(j,dep.getCellule((iExamine+this->getMotif()[j]).getIndex()));
        }
        unsigned int etat = baseToInt(std::vector<unsigned int>(this->getVoisinage(),this->getVoisinage()+this->nbVoisins()),dep.getValMax()+1);
        dest.setCellule(i, this->getRegleTransition()[this->getRegleTransition().size()-1-etat]);
        iExamine++;
    }
}

std::vector<unsigned int> fromRegleNaissMortToRegleTransition(std::vector<short int> regleNaissMort)
{
    /* RAPPEL : la règle regleNaissMort est sous la forme d'un vector de short int
     * qui prennent leur valeur dans l'intervalle [0,2] où 0 = mort, 1 = pas d'effet et 2 = naissance
     *  et où l'index du short int représente le nombre de voisins
     * exemple avec le règle du jeu de la vie classique : vector(0,0,1,2,0,0,0,0,0)
     *                                     nb de voisins en vie  0 1 2 3 4 5 6 7 8
     * On doit la transformer en une règle de transition qui à chaque
     * état du voisinage de la cellule examinée associe son nouvel état à l'issu de la transition.
     * Le voisinage de la cellule considérée est la liste de case suivante (cf. constructeur de VarianteJeuDeLaVie):
     * [(0,0),(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
     * Ainsi pour l'état du voisinage e1[0,0,0,0,0,0,1,1,1] la cellule considérée (e1[0] = 0) a 3 voisins
     * vivants et doit donc naître, la case n° 2^9-1-7 de la règle de transition va donc valoir 2
     * (le 7 est la traduction en base 10 du nombre binaire 000000111 et on doit
     * le soustraire de 2^9-1 car les états sont classés par ordre décroissant
     * conformément aux règles des automates élémentaires.*/
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
            resultat[nbEtats-1-i] = etatBinaire[0]; // rappelons que la première case du motif porte l'information de la case examinée
        }
        else if(regleNaissMort[nbVoisinsVivants] == 0) //la case examinée doit mourir
        {
            resultat[nbEtats-1-i] = 0;
        }
        else //la case examinée doit naître
        {
            resultat[nbEtats-1-i] = 1;
        }
    }
    return resultat;
}
