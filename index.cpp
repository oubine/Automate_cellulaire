#include "index.h"

void IndexTab1D::setIndex(int i)
{
    this->i = i;
    while (this->i < 0)
        this->i += tailleTab;
    this->i %= tailleTab;
}

IndexTab1D& IndexTab1D::operator+=(const std::vector<int>& v)
{
    if(v.size() != 1) throw IndexException("Somme d'un index1D avec un vecteur de dim != 1");
    return (*this) += v[0];
}

IndexTab1D& IndexTab1D::operator-=(const std::vector<int>& v)
{
    if(v.size() != 1) throw IndexException("Somme d'un index1D avec un vecteur de dim != 1");
    return (*this) -= v[0];
}


IndexTab2D& IndexTab2D::operator+=(const std::vector<int>& v)
{
    if(v.size() != 2) throw IndexException("Somme d'un index2D avec un vecteur de dim != 2.");
    this->i += v[0];
    this->j += v[1];
    return (*this);
}

IndexTab2D& IndexTab2D::operator-=(const std::vector<int>& v)
{
    if(v.size() != 2) throw IndexException("Somme d'un index2D avec un vecteur de dim != 2.");
    this->i -= v[0];
    this->j -= v[1];
    return *this;
}

std::ostream& operator<<(std::ostream& f, const IndexTab1D& i)
{
    f<<i.getIndex();
    return f;
}
std::ostream& operator<<(std::ostream& f, const IndexTab2D& index)
{
    // marche de manière inexplicable f<<index.getIndexI()<<","<<index.getJ()<<" -> "<<index.getIndex();
    f<<index.getI()<<","<<index.getJ()<<" -> "<<index.getIndex();
    return f;
}
