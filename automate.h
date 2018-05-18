#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <iostream>
#include "etat.h"

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
    unsigned long int numeroRegleTransition;
    std::string regleTransition;

    virtual ~Automate(){}
    Automate();
    Automate(unsigned long int num, std::string regle) : numeroRegleTransition(num), regleTransition(regle){}
    Automate(const Automate& a);
    Automate& operator=(const Automate& a);
    friend class AutomateManager;
public:
    unsigned long int getNumero() const { return numeroRegleTransition; }
    const std::string& getRegleTransition() const { return regleTransition; }
    virtual void appliquerTransition(const Etat& dep, Etat& dest) const = 0;
};

std::ostream& operator<<(std::ostream& f, const Automate& a);


unsigned long int NumBitToNum(const std::string& num);
std::string NumToNumBit(unsigned long int num);


class Automate1D : public Automate
{
    friend class AutomateManager;
protected:
    Automate1D(unsigned long int num) : Automate(num, NumToNumBit(num)){}
    Automate1D(const std::string& num) : Automate(NumBitToNum(num), num){}
    Automate1D(const Automate1D& a) : Automate(a){}
    void appliquerTransition(const Etat& dep, Etat& dest) const;
};







#endif // AUTOMATE_H
