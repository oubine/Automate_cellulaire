#include "etat.h"
#include "automate.h"
#include <iostream>

std::ostream& operator<<(std::ostream& f, const Etat& e)
{
    for(unsigned int i = 0; i < (unsigned int) pow(e.getTaille(),e.getDimension()); i++)
        f<< e.getCellule(i)<<" ";
    f<<"\n";
    return f;
}

std::ostream& operator<<(std::ostream& f, const Etat1D& e)
{
    auto i = IndexTab1D(0,e.getTaille());
    for (unsigned int k = 0; k < e.getTaille(); k++)
    {
        for(int j = 0; j < 2; j++)
        {
            if (e.getCellule(i.getIndex())) f << char(178); else f << "_";
        }
        i++;
    }
    f << '\n';
    return f;
}

std::ostream& operator<<(std::ostream& f, const Etat2D& e)
{
    auto i = IndexTab2D(0,0,e.getTaille(),e.getTaille());
    for (unsigned int k = 0; k < e.getTaille(); k++)
    {
        for(int j = 0; j < 2; j++)
        {
            if (e.getCellule(i.getIndex())) f << char(178); else f << "_";
        }
        if(i.getJ() == 0) f << '\n';
        i++;
    }
    return f;
}


Etat& Etat::operator=(const Etat& e) {
    if (this != &e) {
        if(dimension != e.dimension)
        {
            throw EtatException("Erreur affectation d'états de dimensions différentes.");
        }
        if (taille != e.taille)
        {
            unsigned int* newvaleur = new unsigned int[(int)(pow(e.taille, e.dimension))];
            for (unsigned int i = 0; i < pow(e.taille, e.dimension); i++) newvaleur[i] = e.valeur[i];
            unsigned int* old = this->valeur;
            this->valeur = newvaleur;
            delete[] old;
        }else for (unsigned int i = 0; i < e.dimension; i++) valeur[i] = e.valeur[i];
    }
    return *this;
}

void Etat::setCellule(unsigned int i, unsigned int val) {
    if (i >= (unsigned int) pow(taille,dimension)) throw EtatException("Erreur Cellule");
    valeur[i] = val;
}

unsigned int Etat::getCellule(unsigned int i) const {
    if (i >= (unsigned int) pow(taille,dimension)) throw EtatException("Erreur Cellule");
    return valeur[i];
}


