#ifndef MOTIF_H
#define MOTIF_H

#include <ostream>
#include <vector>
#include "index.h"

class MotifException {
public:
    MotifException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};



/*class Motif1D :
{
    std::vector<int> voisinage;
public:
    Motif1D(std::vector<int> voisinage): voisinage(voisinage){}
    void ajouterVoisin(int voisin){voisinage.push_back(voisin);}
};

std::ostream& operator<<(std::ostream& f, const Motif& m);*/

#endif // MOTIF_H
