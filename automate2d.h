#ifndef AUTOMATE2D_H
#define AUTOMATE2D_H

#include "automate.h"
#include <vector>

class Automate2D : public Automate
{
    friend class AutomateManager;
public:
    Automate2D():Automate(){}
    Automate2D(std::vector<unsigned int> regle):Automate(regle){}
    Automate2D(std::vector<unsigned int> regle, std::vector<std::vector<int>> motif):Automate(regle,motif){}
    void appliquerTransition(const Etat& dep, Etat& dest) final;
};


std::vector<unsigned int> fromRegleNaissMortToRegleTransition(std::vector<short int> regleNaissMort);

class VarianteJeuDeLaVie : public Automate2D
{
    friend class AutomateManager;
public:
    /*le constructeur d'une variante du jeu de la vie accepte une règle sous la forme d'un vector de short int
     * qui prennent leur valeur dans l'intervalle [0,2] où 0 = mort, 1 = pas d'effet et 2 = naissance et où l'index
     * du short int représente le nombre de voisins
     * exemple avec le règle du jeu de la vie classique : vector(0,0,1,2,0,0,0,0,0)
     *                                     nb de voisins en vie  0 1 2 3 4 5 6 7 8
     */
    VarianteJeuDeLaVie(std::vector<short int> regleNaissMort):Automate2D(fromRegleNaissMortToRegleTransition(regleNaissMort)){setMotifElementaire();}
    void setMotifElementaire()
    {
        std::vector<std::vector<int>> motif(9, std::vector<int>(2));
        motif[0] = {0,0};
        //les règles pour les variantes du jeu de la vie sont symétriques par rapport à la cellule centrale
        //la cellule du centre étant plus importante, on la place en première dans le motif
        motif[1] = {-1,1};
        motif[2] = {-1,0};
        motif[3] = {-1,-1};
        motif[4] = {0,1};
        motif[5] = {0,-1};
        motif[6] = {1,1};
        motif[7] = {1,0};
        motif[8] = {1,-1};
        this->setMotif(motif);
    }
};

#endif // AUTOMATE2D_H
