#ifndef MOTIF_H
#define MOTIF_H

#include <ostream>
#include "index.h"

class MotifException {
public:
    MotifException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};


class Motif //classe abstraite
/* Les motifs sont les "patterns" qui constituent le voisinage utilisé par
 * les automates pour appliquer les règles qui leurs sont associées.
 * Les motifs sont constitués d'une liste d'Index relatifs par rapport à
 * la cellule considérée par l'automate.
 * Par exemple, dans le cas du jeu de la vie de Conway, le voisinage d'une cellule
 * est constitué de la couronne des 8 cellules adjacentes. Le motif associé serait
 * donc le tableau suivant : [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
 * chaque couple étant en réalité un objet Index2D.
 * Autre exemple, les 256 automates élémentaires à une dimension aurait pour motif associé :
 * [Index1D(-1),Index1D(0),Index1D(1)]
 * L'ordre des index importe (si motif [1,0,-1], les automates 1D seraient inversés par ex)*/
{
protected:
    Index** voisinage; //tableau d'index 1D ou 2D (on use du polymorphisme)
    unsigned int nbVoisins;
    unsigned int nbMaxVoisins;
public:
    void ajouterVoisin(Index* i);
    Motif() : voisinage(nullptr),nbVoisins(0),nbMaxVoisins(0){}
    Motif(Index** voisinage, int nbVoisins): voisinage(voisinage), nbVoisins(nbVoisins), nbMaxVoisins(nbVoisins){}
    virtual ~Motif() {delete[] voisinage;}
    unsigned int getNbVoisins() const {return nbVoisins;}

    class ConstIterator {
        friend class Motif;
        const Motif* m;
        unsigned int i;
        ConstIterator(const Motif* m) :m(m), i(0) {}
    public:
        ConstIterator():m(nullptr),i(0) {}
        bool isDone() const {
            return i == m->getNbVoisins();
        }
        void next() {
            if (isDone())
                throw MotifException("error, next on an iterator which is done");
            i++;
        }
        const Index& current() const {
            if (isDone())
                throw MotifException("error, indirection on an iterator which is done");
            return *(m->voisinage[i]);
        }
    };
    ConstIterator begin() const{
        return ConstIterator(this);
    }
    ConstIterator getConstIterator() const {
        return ConstIterator(this);
    }
};

std::ostream& operator<<(std::ostream& f, const Motif& m);

/*class Motif1D : public Motif
{
public:
    void ajouterVoisin(Index* i);
};*/

#endif // MOTIF_H
