#include "etat.h"
#include "math.h"
#include "automate.h"
#include <iostream>

Etat::Etat(unsigned int n, unsigned short int dim) : taille(n), dimension(dim), valeur(new int [int(pow(n,dim))])
{
    for (unsigned int i = 0; i < pow(n,dim); i++) valeur[i] = 0;
}

Etat::Etat(const Etat& e): taille(e.taille), dimension(e.dimension), valeur(new int[int(pow(e.taille,e.dimension))])
{
    for (unsigned int i = 0; i < pow(taille,dimension); i++) this->valeur[i] = e.valeur[i];
}

std::ostream& operator<<(std::ostream& f, const Etat& e)
{
    for (unsigned int i = 0; i < e.getDimension(); i++)
    {
        for (unsigned int j = 0; j < e.getTaille(); j++)
            if (e.getCellule((i*e.getTaille())+j)) f << char(178); else f << " ";
        f << '\n';
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
            int* newvaleur = new int[int(pow(e.taille, e.dimension))];
            for (unsigned int i = 0; i < pow(e.taille, e.dimension); i++) newvaleur[i] = e.valeur[i];
            int* old = this->valeur;
            this->valeur = newvaleur;
            delete[] old;
        }else for (unsigned int i = 0; i < e.dimension; i++) valeur[i] = e.valeur[i];
    }
    return *this;
}

void Etat1D::setCellule(unsigned int i, int val) {
    if (i >= taille) throw EtatException("Erreur Cellule");
    valeur[i] = val;
}

int Etat1D::getCellule(unsigned int i) const {
    if (i >= taille) throw EtatException("Erreur Cellule");
    return valeur[i];
}

