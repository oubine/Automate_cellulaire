#ifndef INTERVALLEABR_H
#define INTERVALLEABR_H

#include <ostream>
#include <vector>

class IntervalleABR
{
    unsigned int borneInf;
    unsigned int borneSup;
    int valeur;
    IntervalleABR* filsGauche;
    IntervalleABR* filsDroit;
public:
    //constructeurs/destructeurs
    IntervalleABR(unsigned int borneInf, unsigned int borneSup, int valeur):borneInf(borneInf),borneSup(borneSup),valeur(valeur),filsGauche(nullptr),filsDroit(nullptr){}
    IntervalleABR(unsigned int borneInf, unsigned int borneSup, int valeur, IntervalleABR* filsGauche, IntervalleABR* filsDroit):borneInf(borneInf),borneSup(borneSup),valeur(valeur),filsGauche(filsGauche),filsDroit(filsDroit){}
    virtual ~IntervalleABR();
    //getter/setter
    int getValeur() const {return valeur;}
    int getValeur(unsigned int index) const;
    IntervalleABR* getFilsGauche() const {return filsGauche;}
    IntervalleABR* getFilsDroit() const {return filsDroit;}
    void setFilsGauche(IntervalleABR* fils) {filsGauche = fils;}
    void setFilsDroit(IntervalleABR* fils) {filsDroit = fils;}
    unsigned int getBorneInf() const {return borneInf;}
    unsigned int getBorneSup() const {return borneSup;}
    //autre
    unsigned int hauteur();
    void afficher(std::ostream& f) const;
 };
IntervalleABR* ajouterIntervalle(IntervalleABR* racine, unsigned int borneInf, unsigned int borneSup, int valeur);
IntervalleABR* equilibrer(IntervalleABR* racine, IntervalleABR* noeud, IntervalleABR* pere = nullptr);
IntervalleABR* rotationD(IntervalleABR* racine, IntervalleABR* pivot, IntervalleABR* pere);
IntervalleABR* rotationG(IntervalleABR* racine, IntervalleABR* pivot, IntervalleABR* pere);
unsigned int nbElem(IntervalleABR* racine);
std::ostream& operator<<(std::ostream& f, const IntervalleABR& arbre);

template <typename T> const T& max (const T& a, const T& b) {return (a<b)?b:a;}
template <typename T> const T& abs (const T& a) {return a<0?-a:a;}

int hauteur2(IntervalleABR *arbre);


IntervalleABR* compresserRegleTransition(std::vector<unsigned int> regle);

#endif // INTERVALLEABR_H
