/**
 * \file automate.h
 * \brief Fichier d'en-tête de la superclasse d'automate
 * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
 * \version 1.0
 * \date 16 Juin 2018
 *
 * Fichier d'en-tête déclarant la superclasse abstraite des de l'architecture des automates.
 *
 */

#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <vector>
#include <iostream>
#include "intervalleabr.h"
#include "etat.h"
#include "motif.h"


/**
* La classe AutomateException permet de gérer les exceptions liées aux automates.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
class AutomateException {
public:
    AutomateException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};


/*Pour créer un nouvel automate, faire hériter une classe d'Automate1D ou 2D
et définir le motif et la règle de transition dans le constructeur de cette sous-classe
en utilisant - la méthode setMotif et le constructeur Automate(regle)
          ou - le constructeur Automate(regle,motif)*/



/**
* \brief La classe Automate est abstraite, elle généralise les Automate1D et Automate2D.
*
* Cette classe contient trois informations des 4-uplet que sont les automates cellulaires : la règle locale de transition, l'alphabet et le voisinage des cellules.
* Les attributs sont protected et non private afin que les classes filles puissent accéder plus rapidement aux attributs (les getter étaient lents).
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
class Automate //classe abstraite
{
protected:
    /**
    * \brief L'attribut regleTransition contient la règle locale de transition de l'automate. Cette règle est représentée par un vector de valeurs comprises dans l'alphabet de l'automate.
    *
    * Les règles de transition sont des généralisations des règles des automates élémentaires.
    * Ce sont des vector représentant les images des états de départs ordonnés dans l'ordre croissant.
    * Par exemple, pour un automate à 4 états et ayant 2 cellules dans son motif, une règle possible serait:
    * vector( 0, 2, 1, 1, 3, 3, 0, 1, 0) correspondant respectivement aux états
    *        00,01,02,10,11,12,20,21,22 du voisinage
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    std::vector<unsigned int> regleTransition;





    /**
    * \brief L'attribut motif contient le motif du voisinage de l'automate. Ce motif est représenté par un vector de vector d'index relatifs.
    *
    * Les motifs sont les "patterns" qui constituent le voisinage utilisé par
     * les automates pour appliquer les règles qui leurs sont associées.
     * Les motifs sont constitués d'une liste d'index relatifs par rapport à
     * la cellule considérée par l'automate.
     * Par exemple, dans le cas du jeu de la vie de Conway, le voisinage d'une cellule
     * est constitué de la couronne des 8 cellules adjacentes plus la cellule elle-même.
     * Le motif associé serait donc le tableau suivant :
     * [(-1,-1),(-1,0),(-1,1),(0,-1),(0,0),(0,1),(1,-1),(1,0),(1,1)]
     * Autre exemple, les 256 automates élémentaires à une dimension aurait pour motif associé :
     * [-1,0,1]
     * L'ordre des index importe pour les règles (si motif [1,0,-1], les automates 1D seraient inversés par ex)
     * Pour les automates à 2 dimensions, les motifs sont des vector de vector à 2 cases.
     * Par soucis de généralité, les motifs des automates1D sont aussi des vector de vector à 1 case.
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    std::vector<std::vector<int>> motif; //si automate1D la deuxième couche de vector ne contient qu'un seul élément




    /**
    * \brief L'attribut valVoisinage est un tableau alloué dynamiquement de taille le nombre de cellules dans le voisinage. Ce tableau n'est destinée à être utilisée que dans la méthode appliquerTransition.
    *
    * Ce tableau alloué dynamiquement permet d'optimiser la méthode appliquerTransition, l'allouer à la construction de l'automate évite de l'allouer à chaque appel de la méthode appliquerTransition.
    * \sa appliquerTransition()
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    unsigned int *valVoisinage;


    /**
    * \brief La valeur max de l'alphabet de l'automate.
    *
    * L'alphabet de l'automate est l'intervalle discrète [0,valMax].
    *
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    unsigned int valMax;

public:
    //constructeurs / destructeurs
    /**
    * \brief Destructeur.
    * Libère la mémoire de valVoisinage.
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    virtual ~Automate(){delete[] valVoisinage;}





    /**
    * \brief Constructeur.
    * @param[in] regle Règle locale de transition sous la forme d'un vector de valeurs.
    * Soit \f$ Q \f$ l'alphabet de l'automate, la \f$ n^{eme} \f$ case de regle contient l'image de
    * l'état du voisinage décrit par le nombre \f$ n \f$ écrit en base \f$ | Q | \f$
    * (la \f$ k^{eme} \f$ decimale de \f$ n \f$ écrit en base \f$ | Q | \f$ représente la \f$ k^{eme} \f$ cellule du voisinage)
    *
    * @param[in] motif Motif du voisinage sous la forme d'un vector d'index (un index 1D est un vector<int> à une case, un index2D un vector<int> à deux cases représentant abscisse et ordonnée).
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    Automate(std::vector<unsigned int> regle,std::vector<std::vector<int>> motif) : regleTransition(regle), motif(motif), valVoisinage(new unsigned int[motif.size()]){}


    Automate(const Automate& a);
    Automate& operator=(const Automate& a);


    /**
    * \brief Méthode centrale de l'automate censée appliquer la règle locale de transition à un état du réseau.
    *
    * Cette méthode est virtuelle pure afin qu'Automate1D et Automate2D la redéfinisse en fonction des traitements spécifiques à la dimension de l'automate.
    *
    * @param[in] dep L'état de départ avant la transition. On use du polymorphisme.

    * @param[out] dest L'état de destination après la transition. On use du polymorphisme.
    *
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    virtual void appliquerTransition(const Etat& dep, Etat& dest) = 0;





    //getter / setter
    void setMotif(std::vector<std::vector<int>> m){motif = m; if(valVoisinage != nullptr) delete[]valVoisinage; valVoisinage = new unsigned int[m.size()];}
    const std::vector<std::vector<int>>& getMotif() const {return motif;}
    void setVoisin(int i, unsigned int val) {valVoisinage[i] = val;}
    unsigned int getVoisin(int i) const {return valVoisinage[i];}
    unsigned int* getVoisinage() {return valVoisinage;}
    unsigned int nbVoisins() {return motif.size();}
    std::vector<unsigned int> getRegleTransition() const {return regleTransition;}
    unsigned int getValMax() const {return valMax;}

};

/**
* \brief Fonction qui transforme un entier en base 10 en un entier en base \f$ n \f$.
*
* Le nombre \f$ k \f$ en base \f$ n \f$ est representé par un vector d'unsigned int que l'on nomme \f$ v \f$.
* \f$ k = \sum_{i=0}^{v.size()-1} v[i]*n^{v.size()-1-i} \f$
*
* @param[in] val Le nombre en base 10.

* @param[in] base La base d'arrivée.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
std::vector<unsigned int> intToBase(unsigned int val, const unsigned int& base);
/**
* \brief Fonction qui transforme un entier en base \f$ n \f$ en un entier en base 10.
*
* Le nombre \f$ k \f$ en base \f$ n \f$ est representé par un vector d'unsigned int que l'on nomme \f$ v \f$.
* \f$ k = \sum_{i=0}^{v.size()-1} v[i]*n^{v.size()-1-i} \f$
*
* @param[in] nb Le nombre en base \f$ n\f$.

* @param[in] base La base d'origine.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
unsigned int baseToInt(const std::vector<unsigned int>& nb, const unsigned int& base);




#endif // AUTOMATE_H
