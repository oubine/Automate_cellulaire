#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <iostream>
#include "etat.h"
#include "motif.h"

class AutomateException {
public:
    AutomateException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};


class Automate
//classe abstraite
{
protected:
    std::string regleTransition;
    Motif pattern;

    virtual ~Automate(){}
    Automate();
    Automate(std::string regle) : regleTransition(regle){} //nécessite l'ajout d'un motif ultérieur
    Automate(const Automate& a);
    Automate& operator=(const Automate& a);
    friend class AutomateManager;
public:
    const std::string& getRegleTransition() const { return regleTransition; }
    virtual void creerMotif() = 0;
    void setMotif(Motif m) {pattern = m;}
    virtual void appliquerTransition(const Etat& dep, Etat& dest) const = 0;
};

std::ostream& operator<<(std::ostream& f, const Automate& a);



unsigned short int NumBitToNum(const std::string& num);
std::string NumToNumBit(unsigned short int num);


class Automate1D : public Automate
{
    friend class AutomateManager;
public:
    unsigned short int numeroRegleTransition;
    Automate1D(unsigned short int num) : Automate(NumToNumBit(num)),numeroRegleTransition(num) {creerMotif();}
    Automate1D(const std::string& num) : Automate(num), numeroRegleTransition(NumBitToNum(num)){creerMotif();}
    Automate1D(const Automate1D& a) : Automate(a){}
    void creerMotif();
    void appliquerTransition(const Etat& dep, Etat& dest) const;
public:
     unsigned long int getNumero() const { return numeroRegleTransition; }
};








#endif // AUTOMATE_H
