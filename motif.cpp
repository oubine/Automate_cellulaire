#include "motif.h"
#include <iostream>

void Motif::ajouterVoisin(Index* i)
{
    if(nbVoisins == nbMaxVoisins)
    {
        Index **newTab = new Index*[nbMaxVoisins + 5];
        for(unsigned int i = 0; i < nbVoisins; i++) newTab[i] = voisinage[i];
        delete[] voisinage;
        nbMaxVoisins += 5;
        voisinage = newTab;
    }
    voisinage[nbVoisins] = i;
    nbVoisins++;
}

std::ostream& operator<<(std::ostream& f, const Motif& m)
{
    for(auto it = m.begin(); !it.isDone(); it.next())
    {
        f<<it.current()<<"\n";
    }
    return f;
}
