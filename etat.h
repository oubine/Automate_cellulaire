#ifndef ETAT
#define ETAT


#include <string>
#include <iostream>
#include <math.h>
#include "index.h"

class EtatException {
public:
    EtatException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};

class Etat
{
protected:
    unsigned int taille;//ce qu'on appelait avant dimension : c'est la taille du tableau représentant un état de l'automate
    const unsigned short int dimension;
    unsigned int* valeur;
    unsigned int valMax; // les cellules de l'état prennent leur valeur dans l'intervalle [0,valMax]
public:

    //Etat(const unsigned short int dim):taille(0),dimension(dim),valeur(nullptr){}
    Etat(unsigned int taille, unsigned short int dim, unsigned int valMax):taille(taille),dimension(dim),valeur(new unsigned int [(int)(pow(taille,dim))]()),valMax(valMax){}
    virtual ~Etat() { delete[] valeur; }
    Etat(const Etat& e): taille(e.taille), dimension(e.dimension), valeur(new unsigned int[(int)(pow(e.taille,e.dimension))]),valMax(e.valMax)
    {
        for (unsigned int i = 0; i < (unsigned int) pow(e.getTaille(),e.getDimension()); i++) valeur[i] = e.getCellule(i);
    }
    Etat& operator=(const Etat& e);
    unsigned int getTaille() const { return taille; }
    unsigned int getDimension() const { return dimension; }
    unsigned int getValMax() const {return valMax;}
    virtual void setCellule(unsigned int index, unsigned int val);
    void setCellule(const Index& i, unsigned int val) {this->setCellule(i.getIndex(),val);}
    virtual unsigned int getCellule(unsigned int index) const;
    unsigned int getCellule(const Index& i) { return this->getCellule(i.getIndex());}
};


class Etat1D : public Etat
{
public:
    Etat1D(unsigned int taille, unsigned int valMax): Etat(taille,1,valMax){}
    /*void setCellule(unsigned int i, unsigned int val);
    void setCellule(IndexTab1D &i, unsigned int val){this->setCellule(i.getIndex(),val);}
    unsigned int getCellule(unsigned int i) const;
    unsigned int getCellule(IndexTab1D &i) const {return this->getCellule(i.getIndex());}
*/
};

class Etat2D : public Etat
{
public:
    Etat2D(unsigned int taille, unsigned int valMax): Etat(taille,2,valMax){}
    /*void setCellule(unsigned int index, unsigned int val);
    void setCellule(IndexTab2D i, unsigned int val){this->setCellule(i.getIndex(),val);}
    unsigned int getCellule(unsigned int i) const;
    unsigned int getCellule(Index1D i) const {return this->getCellule(i.getIndex());}
*/
};

std::ostream& operator<<(std::ostream& f, const Etat& e);
std::ostream& operator<<(std::ostream& f, const Etat1D& e);
std::ostream& operator<<(std::ostream& f, const Etat2D& e);

#endif // ETAT

