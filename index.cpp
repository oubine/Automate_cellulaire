#include "index.h"

void IndexTab1D::setIndex(int i)
{
    this->Index1D::setIndex(i);
    while (this->getIndex() < 0)
        this->Index1D::setIndex(this->getIndex()+tailleTab);
        //équivaut à (*this)+=tailleTab mais on ne peut pas l'utiliser car
        //la surcharge du += utilise la fonction setIndex => boucle infinie
    this->Index1D::setIndex(this->getIndex()%tailleTab); //de même avec %=
}

std::ostream& operator<<(std::ostream& f, const Index& i)
{
    f<<i.getIndex();
    return f;
}
std::ostream& operator<<(std::ostream& f, const Index2D& i)
{
    f<<i.getI()<<","<<i.getJ();
    return f;
}
std::ostream& operator<<(std::ostream& f, const IndexTab2D& i)
{
    f<<i.getI()<<","<<i.getJ()<<"->"<<i.getIndex();
    return f;
}
