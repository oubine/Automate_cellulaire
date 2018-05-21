#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <iostream>
#include "etat.h"
#include "motif.h"

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
 * est constitué de la couronne des 8 cellules adjacentes. Le motif associé serait
 * donc le tableau suivant : [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
 * Autre exemple, les 256 automates élémentaires à une dimension aurait pour motif associé :
 * [-1,0,1]
 * L'ordre des index importe (si motif [1,0,-1], les automates 1D seraient inversés par ex)*/

/* Les règles de transition sont des généralisations des règles des automates élémentaires.
 * Ce sont des vector représentant les images des états de départs ordonnés dans l'ordre décroissant.
 * Par exemple, pour un automate à 3 états et ayant 2 cellules dans son motif, une règle possible serait:
 * vector( 0, 2, 1, 1, 0, 0, 0, 1, 0)
 *        22,21,20,12,11,10,02,01,00
 * Pour les automates à 2 dimensions, les règles sont des vector de vector à 2 cases.*/


class Automate
//classe abstraite
{
protected:
    std::vector<int> regleTransition;
    std::vector<std::vector<int>> motif; //si automate1D la deuxième couche de vector ne contient qu'un seul élément

    virtual ~Automate(){}
    Automate();
    Automate(std::vector<int> regle) : regleTransition(regle){}
    Automate(const Automate& a);
    Automate& operator=(const Automate& a);
    friend class AutomateManager;
public:
    virtual void appliquerTransition(const Etat& dep, Etat& dest) const = 0;
};


unsigned short int NumBitToNum(const std::string& num);
std::string NumToNumBit(unsigned short int num);


class Automate1D : public Automate
{
    friend class AutomateManager;
public:
    Automate1D():Automate(){}
    Automate1D(std::vector<int> regle):Automate(regle){}
    void appliquerTransition(const Etat& dep, Etat& dest) const;
};



class AutomateElementaire : public Automate1D
{
private :
    unsigned short int numeroRegleTransition;
public:
    Automate1D(unsigned short int num) : Automate(NumToNumBit(num)),numeroRegleTransition(num) {creerMotif();}
    Automate1D(const std::string& num) : Automate(num), numeroRegleTransition(NumBitToNum(num)){creerMotif();}
    Automate1D(const Automate1D& a) : Automate(a){}

};








#endif // AUTOMATE_H
