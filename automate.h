#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <vector>
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
 * est constitué de la couronne des 8 cellules adjacentes plus la cellule elle-même.
 * Le motif associé serait donc le tableau suivant :
 * [(-1,-1),(-1,0),(-1,1),(0,-1),(0,0),(0,1),(1,-1),(1,0),(1,1)]
 * Autre exemple, les 256 automates élémentaires à une dimension aurait pour motif associé :
 * [-1,0,1]
 * L'ordre des index importe pour les règles (si motif [1,0,-1], les automates 1D seraient inversés par ex)
 * Pour les automates à 2 dimensions, les motifs sont des vector de vector à 2 cases.
 * Par soucis de généralité, les motifs des automates1D sont aussi des vector de vector à 1 case.*/

/* Les règles de transition sont des généralisations des règles des automates élémentaires.
 * Ce sont des vector représentant les images des états de départs ordonnés dans l'ordre décroissant.
 * Par exemple, pour un automate à 3 états et ayant 2 cellules dans son motif, une règle possible serait:
 * vector( 0, 2, 1, 1, 0, 0, 0, 1, 0)
 *        22,21,20,12,11,10,02,01,00
 */


/*Pour créer un nouvel automate, faire hériter une classe d'Automate1D ou 2D
et définir le motif et la règle de transition dans le constructeur de cette sous-classe
en utilisant - la méthode setMotif et le constructeur Automate(regle)
          ou - le constructeur Automate(regle,motif)*/

class Automate //classe abstraite
{
protected:
    std::vector<unsigned int> regleTransition;
    std::vector<std::vector<int>> motif; //si automate1D la deuxième couche de vector ne contient qu'un seul élément
    unsigned int *valVoisinage;
    //constructeurs / destructeurs
    virtual ~Automate(){delete[] valVoisinage;}
    Automate();
    Automate(std::vector<unsigned int> regle) : regleTransition(regle),valVoisinage(nullptr){}
    Automate(std::vector<unsigned int> regle,std::vector<std::vector<int>> motif) : regleTransition(regle), motif(motif), valVoisinage(new unsigned int[motif.size()]){}
    Automate(const Automate& a);
    Automate& operator=(const Automate& a);
    friend class AutomateManager;
public:
    virtual void appliquerTransition(const Etat& dep, Etat& dest) = 0;
    //getter / setter
    void setMotif(std::vector<std::vector<int>> m){motif = m; if(valVoisinage != nullptr) delete[]valVoisinage; valVoisinage = new unsigned int[m.size()];}
    std::vector<std::vector<int>> getMotif() const {return motif;}
    void setVoisin(int i, unsigned int val) {valVoisinage[i] = val;}
    unsigned int getVoisin(int i) const {return valVoisinage[i];}
    unsigned int* getVoisinage() {return valVoisinage;}
    unsigned int nbVoisins() {return motif.size();}
    std::vector<unsigned int> getRegleTransition() const {return regleTransition;}
};


std::vector<unsigned int> intToBase(unsigned int val, unsigned int base);
unsigned int baseToInt(const std::vector<unsigned int>& nb, unsigned int base);



#endif // AUTOMATE_H
