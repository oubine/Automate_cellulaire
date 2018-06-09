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

/**
* \brief Classe qui définit le comportement de tous les automates à deux dimensions.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
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
    /** \brief Ce constructeur fait le lien entre une règle en fonction du nombre de cellules adjacentes vivantes à une règle locale de transition globale comme définie dans Automate.
     *
     * Le constructeur d'une variante du jeu de la vie accepte une règle sous la forme d'un vector de short int
     * qui prennent leur valeur dans l'intervalle [0,2] où 0 = mort, 1 = pas d'effet et 2 = naissance et où l'index
     * du short int représente le nombre de voisins en vie
     * exemple avec le règle du jeu de la vie classique : vector(0,0,1,2,0,0,0,0,0)
     *                                     nb de voisins en vie  0 1 2 3 4 5 6 7 8
     */
    VarianteJeuDeLaVie(std::vector<short int> regleNaissMort):Automate2D(fromRegleNaissMortToRegleTransition(regleNaissMort),VarianteJeuDeLaVie::getMotifElementaire()){}
    static std::vector<std::vector<int>> getMotifElementaire();
};

class FourmiLangton : public Automate2D
{
public:
    FourmiLangton():Automate2D(FourmiLangton::getRegle(),FourmiLangton::getMotif()){}
    static std::vector<std::vector<int>> getMotif();
    static std::vector<unsigned int> getRegle();
};

#endif // AUTOMATE2D_H
