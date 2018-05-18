#include "automate.h"
#include "math.h"




std::ostream& operator<<(std::ostream& f, const Automate& A) {
    f << "Automate ayant pour regle : " << A.getRegleTransition() << "\n";
    return f;
}


unsigned long int NumBitToNum(const std::string& num) {
    if (num.size() != 8) throw AutomateException("Numero d'automate indefini");
    int puissance = 1;
    long unsigned int numero = 0;
    for (int i = 7; i >= 0; i--) {
        if (num[i] == '1') numero += puissance;
        else if (num[i] != '0') throw AutomateException("Numero d'automate indefini");
        puissance *= 2;
    }
    return numero;
}

std::string NumToNumBit(unsigned long int num) {
    std::string numeroBit;
    if (num > 256) throw AutomateException("Numero d'automate indefini");
    unsigned long int p = 128;
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


void Automate1D::appliquerTransition(const Etat& dep, Etat& dest) const {
    if(dep.getDimension() != 1 || dest.getDimension()!=1) throw AutomateException("Applique une transition sur un état de dimension non appropriée.");
    if (dep.getTaille() != dest.getTaille()) dest = dep;
    for (unsigned int i = 0; i < dep.getTaille(); i++) {
        unsigned short int conf=0;
        if (i > 0) conf+=dep.getCellule(i - 1) * 4;
        conf+=dep.getCellule(i)*2;
        if (i < dep.getTaille()-1) conf+=dep.getCellule(i + 1);
        dest.setCellule(i, regleTransition[7-conf]-'0');
    }
}
