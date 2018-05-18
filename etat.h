#ifndef ETAT
#define ETAT


#include <string>
#include <iostream>

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
    unsigned int taille;
    const unsigned short int dimension;
    int* valeur;
public:
    //Etat(const unsigned short int dim):taille(0),dimension(dim),valeur(nullptr){}
    Etat(unsigned int taille, unsigned short int dim);
    virtual ~Etat() { delete[] valeur; }
    Etat(const Etat& e);
    Etat& operator=(const Etat& e);
    unsigned int getTaille() const { return taille; }
    unsigned int getDimension() const { return dimension; }
    virtual void setCellule(unsigned int index, int val) = 0;
    virtual bool getCellule(unsigned int index) const = 0;
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
    bool getCellule(unsigned int i) const;
};

#endif // ETAT

