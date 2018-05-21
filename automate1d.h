#ifndef AUTOMATE1D_H
#define AUTOMATE1D_H

#include "automate.h"
#include "etat.h"


class Automate1D : public Automate
{
    friend class AutomateManager;
public:
    Automate1D():Automate(){}
    Automate1D(std::vector<unsigned int> regle):Automate(regle){}
    Automate1D(std::vector<unsigned int> regle, std::vector<std::vector<int>> motif):Automate(regle,motif){}
    void appliquerTransition(const Etat& dep, Etat& dest);
};


unsigned short int NumBitToNum(const std::string& num);
std::string NumToNumBit(unsigned short int num);
std::vector<unsigned int> regleStrToVector(const std::string& regleBit);
std::string vectorToRegleStr(const std::vector<unsigned int> &regle);


class AutomateElementaire : public Automate1D
{
private :
    unsigned short int numeroRegleTransition;
public:
    //constructeurs
    AutomateElementaire(unsigned short int num) : Automate1D(regleStrToVector(NumToNumBit(num))),numeroRegleTransition(num){this->setMotifElementaire();}
    AutomateElementaire(const std::string& num) : Automate1D(regleStrToVector(num)), numeroRegleTransition(NumBitToNum(num)){this->setMotifElementaire();}
    //AutomateElementaire(const Automate1D& a) : Automate(a){this->setMotifElementaire();}
    //autres
    void setMotifElementaire()
    {
        std::vector<std::vector<int>> motif(3, std::vector<int>(1));
        motif[0][0] = -1;
        motif[1][0] = 0;
        motif[2][0] = 1;
        this->setMotif(motif);
    }
    virtual void appliquerTransition(const Etat& dep, Etat& dest){this->Automate1D::appliquerTransition(dep,dest);}
};




#endif // AUTOMATE1D_H
