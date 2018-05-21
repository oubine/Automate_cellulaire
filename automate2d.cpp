#include "automate2d.h"
#include "etat.h"
#include <math.h>
#include <algorithm>


void Automate2D::appliquerTransition(const Etat& dep, Etat& dest)
{
    std::cout<<"rest\n";
    if (this->getMotif().size() == 0) throw AutomateException("Motif non défini");
    std::cout<<"test\n";
    if (dep.getTaille() != dest.getTaille()) dest = dep;
    std::cout<<"test2\n";
    auto iExamine = IndexTab2D(0,0,dep.getTaille(),dep.getTaille());
    std::cout<<"test3\n";
    for (unsigned int i = 0; i < dep.size(); i++)
    {//iExamine : index de la case de l'état de départ examinée
        std::cout<<"test4 : "<<iExamine<<"\n";
        for(unsigned int j = 0; j < this->getMotif().size(); j++)
        {//this->getMotif()[j] : index relatif des voisins par rapport à la case examinée
            std::cout<<"test5 : "<<iExamine<<"("<<this->getMotif()[j][0]<<","<<this->getMotif()[j][1]<<")"<<" \n";
            std::cout<<"test6\n";
            std::cout<<"test6.5\n"<<(iExamine+this->getMotif()[j]);
            std::cout<<"test7 : "<<(iExamine+this->getMotif()[j]).getIndex()<<"\n";
            this->setVoisin(j,dep.getCellule((iExamine+this->getMotif()[j]).getIndex()));
        }
        unsigned int etat = baseToInt(std::vector<unsigned int>(this->getVoisinage(),this->getVoisinage()+this->nbVoisins()),dep.getValMax()+1);
        dest.setCellule(i, this->getRegleTransition()[this->getRegleTransition().size()-1-etat]);
        iExamine++;
    }
}

std::vector<unsigned int> fromRegleNaissMortToRegleTransition(std::vector<short int> regleNaissMort)
{
    std::vector<unsigned int> etatBinaire;
    unsigned int nbEtats = pow(2,9);
    unsigned int nbVoisinsVivants = 0;
    std::vector<unsigned int> resultat (nbEtats, 0);
    for(unsigned int i = 0; i < nbEtats; i++)
    {
        etatBinaire = intToBase(i,2);
        while (etatBinaire.size() < 9) etatBinaire.insert(etatBinaire.begin(),0);
        nbVoisinsVivants = std::count(etatBinaire.begin()+1,etatBinaire.end(),1);
        if(regleNaissMort[nbVoisinsVivants] == 1)//la case examinée ne doit pas changer d'état
        {
            resultat[nbEtats-1-i] = etatBinaire[0]; // rappelons que la première case du motif porte l'information de la case examinée
        }
        else if(regleNaissMort[nbVoisinsVivants] == 0)
        {
            resultat[nbEtats-1-i] = 0;
        }
        else
        {
            resultat[nbEtats-1-i] = 1;
        }
    }
    return resultat;
}
