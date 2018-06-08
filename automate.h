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
* \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
*/
class AutomateException {
public:
    AutomateException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};

/* Les motifs sont les "patterns" qui constituent le voisinage utilisé par
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
 * Par soucis de généralité, les motifs des automates1D sont aussi des vector de vector à 1 case.*/

/* Les règles de transition sont des généralisations des règles des automates élémentaires.
 * Ce sont des vector représentant les images des états de départs ordonnés dans l'ordre croissant.
 * Par exemple, pour un automate à 3 états et ayant 2 cellules dans son motif, une règle possible serait:
 * vector( 0, 2, 1, 1, 0, 0, 0, 1, 0)
 *        00,01,02,10,11,12,20,21,22
 */


/*Pour créer un nouvel automate, faire hériter une classe d'Automate1D ou 2D
et définir le motif et la règle de transition dans le constructeur de cette sous-classe
en utilisant - la méthode setMotif et le constructeur Automate(regle)
          ou - le constructeur Automate(regle,motif)*/



/**
* \brief La classe Automate est abstraite, elle généralise les automates1D et 2D.
*
* Cette classe contient deux informations des 4-uplet que sont les automates cellulaires : la règle locale de transition et le voisinage des cellules.
* \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
*/
class Automate //classe abstraite
{
protected:
    /**
    * \brief L'attribut regleTransition contient la règle locale de transition de l'automate. Cette règle est représentée par un vector de valeurs comprises dans l'alphabet de l'automate.
    *
    * Les règles de transition sont des généralisations des règles des automates élémentaires.
    * Ce sont des vector représentant les images des états de départs ordonnés dans l'ordre croissant.
    * Par exemple, pour un automate à 3 états et ayant 2 cellules dans son motif, une règle possible serait:
    * vector( 0, 2, 1, 1, 0, 0, 0, 1, 0)
    *        00,01,02,10,11,12,20,21,22
    * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
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
    * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
    */
    std::vector<std::vector<int>> motif; //si automate1D la deuxième couche de vector ne contient qu'un seul élément
    /**
    * \brief L'attribut valVoisinage est un tableau alloué dynamiquement de taille le nombre de cellules dans le voisinage. Ce tableau n'est destinée à être utilisée que dans la méthode appliquerTransition.
    *
    * Ce tableau alloué dynamiquement permet d'optimiser la méthode appliquerTransition, l'allouer à la construction de l'automate évite de l'allouer à chaque appel de la méthode appliquerTransition.
    * \sa appliquerTransition()
    * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
    */
    unsigned int *valVoisinage;

public:
    //constructeurs / destructeurs
    virtual ~Automate(){delete[] valVoisinage;}
    Automate();
    Automate(std::vector<unsigned int> regle) : regleTransition(regle),valVoisinage(nullptr){}
    Automate(std::vector<unsigned int> regle,std::vector<std::vector<int>> motif) : regleTransition(regle), motif(motif), valVoisinage(new unsigned int[motif.size()]){}
    Automate(const Automate& a);
    Automate& operator=(const Automate& a);

    virtual void appliquerTransition(const Etat& dep, Etat& dest) = 0;
    //getter / setter
    void setMotif(std::vector<std::vector<int>> m){motif = m; if(valVoisinage != nullptr) delete[]valVoisinage; valVoisinage = new unsigned int[m.size()];}
    const std::vector<std::vector<int>>& getMotif() const {return motif;}
    void setVoisin(int i, unsigned int val) {valVoisinage[i] = val;}
    unsigned int getVoisin(int i) const {return valVoisinage[i];}
    unsigned int* getVoisinage() {return valVoisinage;}
    unsigned int nbVoisins() {return motif.size();}
    std::vector<unsigned int> getRegleTransition() const {return regleTransition;}

};


std::vector<unsigned int> intToBase(unsigned int val, unsigned int base);
unsigned int baseToInt(const std::vector<unsigned int>& nb, unsigned int base);




#endif // AUTOMATE_H
