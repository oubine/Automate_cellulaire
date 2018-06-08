#include "automate.h"


Automate::Automate(const Automate& a)
{
    delete[] this->valVoisinage;
    this->valVoisinage = new unsigned int[a.getMotif().size()];
}

Automate& Automate::operator=(const Automate& a)
{
    if (&a == this) return *this;
    delete[] this->valVoisinage;
    this->valVoisinage = new unsigned int[a.getMotif().size()];
    return *this;
}

std::vector<unsigned int> intToBase(unsigned int val, const unsigned int &base)
{
    if(val == 0) return std::vector<unsigned int> {0};
    std::vector<unsigned int> resultat;
    while (val != 0)
    {
        resultat.insert(resultat.begin(),val%base);
        val /= (unsigned int) base;
    }
    return resultat;
}

unsigned int baseToInt(const std::vector<unsigned int>& nb, const unsigned int& base)
{
    if (nb.size() == 1 && nb[0] == 0) return 0;
    unsigned int resultat = 0;
    for(auto it = nb.begin(); it != nb.end(); it++)
    {
        resultat += *it;
        resultat *= base;
    }
    return resultat/base;
}


