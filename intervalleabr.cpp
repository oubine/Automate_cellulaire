#include "intervalleabr.h"
IntervalleABR* compresserRegleTransition(std::vector<unsigned int> regle)
{
    IntervalleABR* resultat = nullptr;
    unsigned int val_precedente = regle[0];
    unsigned int borne_inf = 0;
    unsigned int nb_cases_moins_un = regle.size()-1;
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
    // on doit maintenant équilibrer l'arbre
    return equilibrer(racine,racine);
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


IntervalleABR* equilibrer(IntervalleABR* racine, IntervalleABR* noeud, IntervalleABR* pere)
{
    //renvoie la nouvelle racine
    if (noeud == nullptr) return racine;
    int hSAG = hauteur2(noeud->getFilsGauche());
    int hSAD = hauteur2(noeud->getFilsDroit());
    int delta = hSAD - hSAG;
    IntervalleABR* temp = racine;
    if(abs(delta) > 1)//while(abs(delta) > 1)
    {
        if(hSAG > hSAD)
        {
            racine = rotationD(racine,noeud,pere);
        }
        else
        {
            racine = rotationG(racine,noeud,pere);
        }
        if(temp != racine)
        return racine;
        /*hSAG = hauteur2(noeud->getFilsGauche());
        hSAD = hauteur2(noeud->getFilsDroit());
        delta = hSAD - hSAG;*/
    }

    racine = equilibrer(racine,noeud->getFilsGauche(),noeud);
    if(temp != racine)
    return racine;
    racine = equilibrer(racine,noeud->getFilsDroit(),noeud);
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

IntervalleABR* rotationD(IntervalleABR* racine, IntervalleABR* pivot, IntervalleABR* pere)
{
    if (pivot->getFilsGauche() != nullptr)
    {
        IntervalleABR* y = pivot->getFilsGauche();
        IntervalleABR* C = y->getFilsDroit();
        if(racine == pivot) racine = y;
        else if(pivot == pere->getFilsGauche()) pere->setFilsGauche(y);
        else pere->setFilsDroit(y);
        y->setFilsDroit(pivot);
        pivot->setFilsGauche(C);
    }
    return racine;
}


IntervalleABR* rotationG(IntervalleABR* racine, IntervalleABR* pivot, IntervalleABR* pere)
{
    if (pivot->getFilsDroit() != nullptr)
    {
        IntervalleABR* y = pivot->getFilsDroit();
        IntervalleABR* C = y->getFilsGauche();
        if(racine == pivot) racine = y;
        else if(pivot == pere->getFilsDroit()) pere->setFilsDroit(y);
        else pere->setFilsGauche(y);
        y->setFilsGauche(pivot);
        pivot->setFilsDroit(C);
    }
    return racine;
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
