#ifndef ETAT
#define ETAT


#include <string>
#include <iostream>
#include "index.h"

class EtatException {
public:
    EtatException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};

class Etat
//classe abstraite
{
protected:
    unsigned int taille;//ce qu'on appelait avant dimension : c'est la taille du tableau représentant un état de l'automate
    const unsigned short int dimension;
    int* valeur;
public:
    class ConstIteratorEtat {};
    //Etat(const unsigned short int dim):taille(0),dimension(dim),valeur(nullptr){}
    Etat(unsigned int taille, unsigned short int dim);
    virtual ~Etat() { delete[] valeur; }
    Etat(const Etat& e);
    Etat& operator=(const Etat& e);
    unsigned int getTaille() const { return taille; }
    unsigned int getDimension() const { return dimension; }
    virtual void setCellule(unsigned int index, int val) = 0;
    virtual int getCellule(unsigned int index) const = 0;
    virtual ConstIteratorEtat& begin() const = 0;
    virtual ConstIteratorEtat& getConstIterator() const = 0;
};

std::ostream& operator<<(std::ostream& f, const Etat& e);

class Etat1D : public Etat
{
public:
    //Etat1D():Etat(1){}
    Etat1D(const Etat1D& e): Etat(e){}
    //Etat1D(const Etat& e): Etat(e){if(dimension != 1) throw EtatException("Erreur copie états de dimensions différentes.");}
    Etat1D(unsigned int taille): Etat(taille,1){}
    void setCellule(unsigned int i, int val);
    void setCellule(IndexTab1D i, int val){this->setCellule(i.getIndex(),val);}
    int getCellule(unsigned int i) const;
    int getCellule(IndexTab1D i) const {return this->getCellule(i.getIndex());}

    class ConstIterator : public ConstIteratorEtat {
        friend class Etat1D;
        const Etat1D* e;
        IndexTab1D i;
        ConstIterator(const Etat1D* etat) :e(etat), i(IndexTab1D(0,etat->getTaille())) {}
    public:
        bool isDone() const {
            return (unsigned int) i.getIndex() == e->getTaille();
        }
        void next() {
            if (isDone())
                throw EtatException("error, next on an iterator which is done");
            i++;
        }
        IndexTab1D current() const {
            if (isDone())
                throw EtatException("error, indirection on an iterator which is done");
            return i;
        }

    };
    ConstIteratorEtat& begin() const{
        return ConstIterator(this);
    }
    ConstIteratorEtat& getConstIterator() const {
        return ConstIterator(this);
    }
};

#endif // ETAT

