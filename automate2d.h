/**
 * \file automate2d.h
 * \brief Fichier d'en-tête des classes d'automate 2 dimensions
 * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
 * \version 1.0
 * \date 16 Juin 2018
 *
 * Fichier d'en-tête déclarant l'architecture des automates à deux dimensions dans l'application.
 *
 */

#ifndef AUTOMATE2D_H
#define AUTOMATE2D_H

#include "automate.h"
#include <vector>

class Automate2D : public Automate
{
public:
    Automate2D(std::vector<unsigned int> regleTransition, std::vector<std::vector<int>> motif):Automate(regleTransition,motif){}
    void appliquerTransition(const Etat& dep, Etat& dest) final;
};


std::vector<unsigned int> fromRegleNaissMortToRegleTransition(std::vector<short int> regleNaissMort);

class VarianteJeuDeLaVie : public Automate2D
{
public:
    /* Le motif du voisinage de cet automate est le suivant :
     * [(0,0),(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
     * Le constructeur d'une variante du jeu de la vie accepte une règle sous la forme d'un vector de short int
     * qui prennent leur valeur dans l'intervalle [0,2] où 0 = mort, 1 = pas d'effet et 2 = naissance et où l'index
     * du short int représente le nombre de voisins
     * exemple avec le règle du jeu de la vie classique : vector(0,0,1,2,0,0,0,0,0)
     *                                     nb de voisins en vie  0 1 2 3 4 5 6 7 8
     */
    VarianteJeuDeLaVie(std::vector<short int> regleNaissMort):Automate2D(fromRegleNaissMortToRegleTransition(regleNaissMort),VarianteJeuDeLaVie::getMotifElementaire()){}
    static std::vector<std::vector<int>> getMotifElementaire()
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
};

class FourmiLangton : public Automate2D
{
public:
    FourmiLangton():Automate2D(FourmiLangton::getRegle(),FourmiLangton::getMotif()){}
    static std::vector<std::vector<int>> getMotif();
    static std::vector<unsigned int> getRegle();
};

#endif // AUTOMATE2D_H
