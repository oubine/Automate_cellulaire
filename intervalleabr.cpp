#include "intervalleabr.h"
#include <iostream>
#include "automate.h"
IntervalleABR* compresserRegleTransition(std::vector<unsigned int>& regle)
{
    IntervalleABR* resultat = nullptr;
    unsigned int val_precedente = regle[0];
    unsigned int borne_inf = 0;
    unsigned int nb_cases_moins_un = regle.size()-1;
    std::cout << "debut construction arbre\n";
    for(unsigned int i = 1; i < regle.size(); i++)
    {
        if(regle[i] != val_precedente)
        {
            if(resultat == nullptr)
            {
                resultat = new IntervalleABR(nb_cases_moins_un-(i-1),nb_cases_moins_un,val_precedente);
            }
            else
            {
                resultat = ajouterIntervalle(resultat, nb_cases_moins_un-(i-1),nb_cases_moins_un-borne_inf, val_precedente);
            }
            borne_inf = i;
            val_precedente = regle[i];
        }
    }
    resultat = ajouterIntervalle(resultat,0, nb_cases_moins_un-borne_inf, val_precedente);
    std::cout << "debut de l'equilibrage de l'arbre\n";
    resultat = equilibrer(resultat);
    std::cout <<nbElem(resultat)<<" elems : bytes ->"<< sizeof(resultat[0])*nbElem(resultat)<<" hauteur : "<<hauteur2(resultat) << "\n";
    return resultat;
}


IntervalleABR::~IntervalleABR()
{
    delete filsGauche;
    delete filsDroit;
}

int hauteur2(IntervalleABR* arbre)
{
    if (arbre == nullptr) return -1;
    return 1+max(hauteur2(arbre->getFilsGauche()),hauteur2(arbre->getFilsDroit()));
}

unsigned int IntervalleABR::hauteur()
{
    return static_cast<unsigned int>(hauteur2(this));
}

IntervalleABR* ajouterIntervalle(IntervalleABR* racine, unsigned int borneInf, unsigned int borneSup, int valeur)
{
    // appelez à la suite de cette fonction equilibrer(racine,racine) pour équilibrer l'arbre
    if (racine == nullptr) return new IntervalleABR(borneInf,borneSup,valeur);
    if(borneInf > borneSup) return racine;
    IntervalleABR* nouveau = new IntervalleABR(borneInf,borneSup,valeur);
    IntervalleABR* curseur = racine;
    while(1)
    {
        if ( (borneInf < curseur->getBorneInf() && borneSup >= curseur->getBorneInf()) || (borneInf >= curseur->getBorneInf() && borneInf <= curseur->getBorneSup()))
            return racine; //intersection
        if(borneInf < curseur->getBorneInf())
        {
            if(curseur->getFilsGauche() != nullptr)
            curseur = curseur->getFilsGauche();
            else
            {
                curseur->setFilsGauche(nouveau);

                break;
            }
        }
        else
        {
            if(curseur->getFilsDroit() != nullptr)
            curseur = curseur->getFilsDroit();
            else
            {
                curseur->setFilsDroit(nouveau);
                break;
            }
        }
    }
    // nouvelle intervalle ajoutée
    return racine;
}
int IntervalleABR::getValeur(unsigned int index) const
{
    const IntervalleABR* curseur = this;
    while (curseur != nullptr)
    {
        if(index < curseur->getBorneInf())
            curseur = curseur->getFilsGauche();
        else if(index > curseur->getBorneSup())
            curseur = curseur->getFilsDroit();
        else
            return curseur->getValeur();
    }
    return -1;
}


IntervalleABR* equilibrer(IntervalleABR* racine, IntervalleABR* pere)
{
    //renvoie la nouvelle racine
    if (racine == nullptr) return pere;
    racine = equilibrer(racine->getFilsDroit(),racine);
    // SAD équilibré
    racine = equilibrer(racine->getFilsGauche(),racine);
    // SAG équilibré
    int hSAG = hauteur2(racine->getFilsGauche());
    int hSAD = hauteur2(racine->getFilsDroit());
    int delta = hSAD - hSAG;
    if(abs(delta) > 1)
    {
        if(hSAG > hSAD)
        {
            racine = rotationD(racine,pere);
            racine = equilibrer(racine,pere);
        }
        else
        {
            racine = rotationG(racine,pere);
            racine = equilibrer(racine,pere);
        }
    }
    if(pere != nullptr)
    return pere;
    return racine;
}

void IntervalleABR::afficher(std::ostream& f) const
{
    f << "[" << borneInf << "," << borneSup << "]" << " -> "<<valeur<<"\n";
    if (filsGauche != nullptr)
    {
        f << "fils gauche de "<<"[" << borneInf << "," << borneSup << "] : ";
        filsGauche->afficher(f);
    }
    if (filsDroit != nullptr)
    {
        f << "fils droit de "<<"[" << borneInf << "," << borneSup << "] : ";
        filsDroit->afficher(f);
    }
}

IntervalleABR* rotationD(IntervalleABR* pivot, IntervalleABR* pere)
{
    if (pivot->getFilsGauche() != nullptr)
    {
        IntervalleABR* Q = pivot;
        IntervalleABR* P = pivot->getFilsGauche();
        IntervalleABR* B = P->getFilsDroit();
        if(pere != nullptr)
        {
            if(Q == pere->getFilsGauche()) pere->setFilsGauche(P);
            else pere->setFilsDroit(P);
         }
        P->setFilsDroit(Q);
        Q->setFilsGauche(B);
        return P;
    }
    return pivot;
}


IntervalleABR* rotationG(IntervalleABR* pivot, IntervalleABR* pere)
{
    if (pivot->getFilsDroit() != nullptr)
    {
        IntervalleABR* P = pivot;
        IntervalleABR* Q = pivot->getFilsDroit();
        IntervalleABR* B = Q->getFilsGauche();
        if(pere != nullptr)
        {
            if(P == pere->getFilsGauche()) pere->setFilsGauche(Q);
            else pere->setFilsDroit(Q);
         }
        Q->setFilsGauche(P);
        P->setFilsDroit(B);
        return Q;
    }
    return pivot;
}

std::ostream& operator<<(std::ostream& f, const IntervalleABR& arbre)
{
    arbre.afficher(f);
    return f;
}

unsigned int nbElem(IntervalleABR* racine)
{
    if(racine == nullptr) return 0;
    return 1+nbElem(racine->getFilsDroit())+nbElem(racine->getFilsGauche());
}
