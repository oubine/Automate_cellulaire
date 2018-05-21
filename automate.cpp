#include "automate.h"



std::vector<unsigned int> intToBase(unsigned int val, unsigned int base)
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

unsigned int baseToInt(const std::vector<unsigned int>& nb, unsigned int base)
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
