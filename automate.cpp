#include "automate.h"
#include "math.h"




void Automate1D::appliquerTransition(const Etat& dep, Etat& dest) {
    if (this->getMotif().size() == 0) throw AutomateException("Motif non défini");
    if (dep.getTaille() != dest.getTaille()) dest = dep;
    std::cout<<dep<<"\n";
    auto iExamine = IndexTab1D(0,dep.getTaille());
    for (unsigned int i = 0; i < dep.getTaille(); i++)
    {//iExamine : index de la case de l'état de départ examinée
        for(unsigned int j = 0; j < this->getMotif().size(); j++)
        {//this->getMotif()[j] : index relatif des voisins par rapport à la case examinée
            this->setVoisin(j,dep.getCellule((iExamine+this->getMotif()[j]).getIndex()));
        }
        unsigned int etat = baseToInt(std::vector<unsigned int>(this->getVoisinage(),this->getVoisinage()+this->nbVoisins()),dep.getValMax()+1);
        dest.setCellule(i, this->getRegleTransition()[this->getRegleTransition().size()-1-etat]);
        iExamine++;
    }
    std::cout<<dest<<"\n\n";
}




unsigned short int NumBitToNum(const std::string& num) {
    if (num.size() != 8) throw AutomateException("Numero d'automate indefini");
    int puissance = 1;
    short unsigned int numero = 0;
    for (int i = 7; i >= 0; i--) {
        if (num[i] == '1') numero += puissance;
        else if (num[i] != '0') throw AutomateException("Numero d'automate indefini");
        puissance *= 2;
    }
    return numero;
}

std::string NumToNumBit(unsigned short int num) {
    std::string numeroBit;
    if (num > 256) throw AutomateException("Numero d'automate indefini");
    unsigned short int p = 128;
    int i = 7;
    while (i >= 0) {
        if (num >= p) {
            numeroBit.push_back('1');
            num -= p;
        }
        else { numeroBit.push_back('0'); }
        i--;
        p = p / 2;
    }
    return numeroBit;
}

std::vector<unsigned int> regleStrToVector(const std::string& regleBit)
{
    std::vector<unsigned int> result;
    for(auto it = regleBit.begin(); it != regleBit.end(); it++)
    {
        result.push_back((int) *it - '0');
    }
    return result;
}

std::string vectorToRegleStr(const std::vector<unsigned int> &regle)
{
    std::string result;
    for(auto it = regle.begin(); it != regle.end(); it++)
    {
        result += (char) *it + '0';
    }
    return result;
}


std::vector<unsigned int> intToBase(unsigned int val, unsigned int base)
{
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
    unsigned int resultat = 0;
    for(auto it = nb.begin(); it != nb.end(); it++)
    {
        resultat += *it;
        resultat *= base;
    }
    return resultat/base;
}


