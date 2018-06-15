#include "automate1d.h"
#include <math.h>


/**
* \brief Méthode qui définit le comportement de la méthode virtuelle appliquerTransition pour tous les automates à une dimension.
*
* On examine le voisinage de chaque cellule de l'état de départ et on affecte à la cellule de même index de l'état de destination
* l'image de l'état du voisinage par la règle locale de transition.
*
* @param[in] dep L'état avant la transition.

* @param[out] dest État dans lequel on va stocker l'état après la transition.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
void Automate1D::appliquerTransition(const Etat& dep, Etat& dest) {
    if (motif.size() == 0) throw AutomateException("Motif non défini");
    if (valMax != dep.getValMax()) throw AutomateException("appel de appliquerTransition sur un état ayant un alphabet différent de celui accepté par l'automate.");
    if (dep.getTaille() != dest.size()) dest = dep;
    auto iExamine = IndexTab1D(0,dep.getTaille());
    /** iExamine est l'index de la cellule examinée à un instant t **/
    for (unsigned int i = 0; i < dep.getTaille(); i++)
    {
        for(unsigned int j = 0; j < this->getMotif().size(); j++)
        {
            /** on récupère le voisinage de la cellule examinée en fonction du motif de voisinage de l'automate **/
            this->setVoisin(j,dep.getCellule(iExamine+motif[j]));
        }
        /** on traduit l'état du voisinage en nombre en base 10 qui représente l'index de la règle contenant l'état suivant de la cellule considérée **/
        unsigned int etat = baseToInt(std::vector<unsigned int>(valVoisinage,valVoisinage+this->nbVoisins()),dep.getValMax()+1);
        /** on assigne à l'état de destination le nouvel état de la cellule examinée **/
        dest.setCellule(i, regleTransition[etat]);
        /** on passe à la cellule suivante **/
        iExamine++;
    }
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


/**
* \brief Constructeur.
*
* Ce constructeur fait le lien entre numéro de l'automate élémentaire et sa règle locale de transition telle qu'on la représente dans notre classe Automate.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
AutomateElementaire::AutomateElementaire(unsigned short int num) : Automate1D(regleStrToVector(NumToNumBit(num)),AutomateElementaire::getMotifElementaire(),1),numeroRegleTransition(num)
{
    std::vector<unsigned int> temp = this->regleTransition;
    for(unsigned int i = 0; i < temp.size(); ++i)
    {
        temp[i] = regleTransition[temp.size()-1-i];
    }
    regleTransition = temp;
}
AutomateElementaire::AutomateElementaire(const std::string& num) : Automate1D(regleStrToVector(NumToNumBit(NumBitToNum(num))),AutomateElementaire::getMotifElementaire(),1), numeroRegleTransition(NumBitToNum(num))
{
    std::vector<unsigned int> temp = this->regleTransition;
    for(unsigned int i = 0; i < temp.size(); ++i)
    {
        temp[i] = regleTransition[temp.size()-1-i];
    }
    regleTransition = temp;
}
