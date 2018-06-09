/**
 * \file etat.h
 * \brief Fichier d'en-tête des classes d'état
 * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
 * \version 1.0
 * \date 16 Juin 2018
 *
 * Fichier d'en-tête déclarant l'architecture des états dans l'application.
 *
 */

#ifndef ETAT
#define ETAT


#include <string>
#include <iostream>
#include <math.h>
#include "index.h"

/**
* La classe EtatException permet de gérer les exceptions liées aux états.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
class EtatException {
public:
    EtatException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};


/**
* \brief La classe Etat représente une valuation de chaque cellule d'une région torique et carrée d'un réseau \f$ Z^d \f$.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
class Etat
{
private:
    /**
    * \brief L'attribut taille est le nombre de cellules dans un côté du tableau contenant les valuations.
    *
    * Pour avoir la taille totale du tableau, utiliser la méthode size().
    *
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    unsigned int taille;

    /**
    * \brief La dimension du réseau.
    *
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    const unsigned short int dimension;

    /**
    * \brief Le tableau contenant les valuations des chaque cellule de la région du réseau.
    *
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    unsigned int* valeur;

    /**
    * \brief La valeur max de l'alphabet dans lequel les cellules prennent leur valeur.
    *
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    unsigned int valMax; // les cellules de l'état prennent leur valeur dans l'intervalle [0,valMax]
public:

    //Etat(const unsigned short int dim):taille(0),dimension(dim),valeur(nullptr){}
    Etat(unsigned int taille, unsigned short int dim, unsigned int valMax):taille(taille),dimension(dim),valeur(new unsigned int [(int)(pow(taille,dim))]()),valMax(valMax){}
    virtual ~Etat() { delete[] valeur; }
    Etat(const Etat& e): taille(e.taille), dimension(e.dimension), valeur(new unsigned int[(int)(pow(e.taille,e.dimension))]),valMax(e.valMax)
    {
        for (unsigned int i = 0; i < e.size(); i++) valeur[i] = e.getCellule(i);
    }
    Etat& operator=(const Etat& e);
    unsigned int getTaille() const { return taille; }
    unsigned int getDimension() const { return dimension; }
    unsigned int getValMax() const {return valMax;}
    virtual void setCellule(unsigned int index, unsigned int val);
    void setCellule(const Index& i, unsigned int val) {this->setCellule(i.getIndex(),val);}
    virtual unsigned int getCellule(unsigned int index) const;
    unsigned int getCellule(const Index& i) const { return this->getCellule(i.getIndex());}
    unsigned int size() const {return (unsigned int) pow(taille,dimension);}
};


class Etat1D : public Etat
{
public:
    Etat1D(unsigned int taille, unsigned int valMax): Etat(taille,1,valMax){}
};

class Etat2D : public Etat
{
public:
    Etat2D(unsigned int taille, unsigned int valMax): Etat(taille,2,valMax){}
};

std::ostream& operator<<(std::ostream& f, const Etat& e);
std::ostream& operator<<(std::ostream& f, const Etat1D& e);
std::ostream& operator<<(std::ostream& f, const Etat2D& e);

#endif // ETAT

