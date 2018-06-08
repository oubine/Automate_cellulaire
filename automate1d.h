/**
 * \file automate1d.h
 * \brief Fichier d'en-tête des classes d'automate 1 dimension
 * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
 * \version 1.0
 * \date 16 Juin 2018
 *
 * Fichier d'en-tête déclarant l'architecture des automates à une dimension dans l'application.
 *
 */
#ifndef AUTOMATE1D_H
#define AUTOMATE1D_H

#include "automate.h"
#include "etat.h"


/**
* \brief Classe qui définit le comportement de tous les automates à une dimension.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
class Automate1D : public Automate
{
public:
    Automate1D(std::vector<unsigned int> regleTransition, std::vector<std::vector<int>> motif):Automate(regleTransition,motif){}
    void appliquerTransition(const Etat& dep, Etat& dest) final;
};


unsigned short int NumBitToNum(const std::string& num);
std::string NumToNumBit(unsigned short int num);
std::vector<unsigned int> regleStrToVector(const std::string& regleBit);
std::string vectorToRegleStr(const std::vector<unsigned int> &regle);

/**
* \brief La classe des automates élémentaires à une dimension.
*
* \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
*/
class AutomateElementaire : public Automate1D
{
private :
    unsigned short int numeroRegleTransition;
public:
    //constructeurs
    AutomateElementaire(unsigned short int num);
    AutomateElementaire(const std::string& num);
    //AutomateElementaire(const Automate1D& a) : Automate(a){this->setMotifElementaire();}
    //autres
    /**
    * \brief Méthode statique qui renvoie le motif commun à tous les automates élémentaires : [-1,0,1].
    *
    * \author Oubine Perrin, Guillaume Sabbagh, Adrien Thuau
    */
    static std::vector<std::vector<int>> getMotifElementaire()
    {
        std::vector<std::vector<int>> motif(3, std::vector<int>(1));
        motif[0][0] = -1;
        motif[1][0] = 0;
        motif[2][0] = 1;
        return motif;
    }
 };




#endif // AUTOMATE1D_H
