#ifndef INDEX_H
#define INDEX_H
#include <ostream>

class IndexException {
public:
    IndexException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};

class Index
//classe abstraite permettant le polymorphisme des index
{
public:
    virtual int getIndex() const = 0;
    virtual void setIndex(int i)= 0;
};


class Index1D : public Index
//permet de stocker des index et ajoute des opérations usuelles (somme,différence)
{
private:
    int i;
public:
    //constructeurs
    Index1D():i(0){}
    Index1D(int i):i(i){}
    //getter/setter
    int getIndex() const {return i;}
    void setIndex(int i){this->i = i;}
    //surcharge opérateurs
    Index1D& operator=(const Index1D& i){this->setIndex(i.getIndex()); return *this;}
    Index1D& operator+=(const Index1D& i){this->setIndex(this->i+i.getIndex()); return *this;}
    Index1D& operator+=(const int& j){this->setIndex(this->getIndex()+j); return *this;}
    Index1D& operator-=(const Index1D& i){this->setIndex(this->i-i.getIndex()); return *this;}
    Index1D& operator-=(const int& i){this->setIndex(this->i-i); return *this;}
    Index1D& operator++(){this->setIndex(this->getIndex()+1); return *this;}//++i
    Index1D operator++(int){Index1D temp = *this; ++*this; return temp;}//i++
    Index1D& operator--(){this->setIndex(this->getIndex()-1); return *this;}//--i
    Index1D operator--(int){Index1D temp = *this; --*this; return temp;}//i--
    Index1D& operator%=(const int& d){this->setIndex(this->getIndex()%d); return *this;}
    //autre
};
inline Index1D& operator+(const Index1D& i, const Index1D& j){Index1D k = i; return k += j;}
inline Index1D& operator+(const Index1D& i, const int j){Index1D k = i; return k += j;}
inline Index1D& operator+(const int& i, const Index1D& j){Index1D k = j; return k+=i;}
inline Index1D& operator-(const Index1D& i, const Index1D& j){Index1D k = i; return k-=j;}
inline Index1D& operator-(const Index1D& i, const int& j){Index1D k = i; return k-=j;}
inline Index1D& operator-(const int& i, const Index1D& j){Index1D k = j;  return k-=i;}

class IndexTab1D : public Index1D
//permet d'accéder aux éléments d'un tableau1D en simplifiant les opérations sur les index (gère les index négatifs)
{
private:
    int tailleTab;
public:
    //constructeurs
    IndexTab1D(int i, int tailleTab):Index1D(i),tailleTab(tailleTab){}
    //getter/setter
    int getTailleTab() const {return tailleTab;}
    void setIndex(int i);
    void setTailleTab(unsigned int tailleTab) {this->tailleTab = tailleTab; this->setIndex(this->getIndex());}
    //surcharge opérateurs
    IndexTab1D& operator++(){this->setIndex(this->getIndex()+1); return *this;}//++i
    IndexTab1D operator++(int){IndexTab1D temp = *this; ++*this; return temp;}//i++
    IndexTab1D& operator--(){this->setIndex(this->getIndex()-1); return *this;}//--i
    IndexTab1D operator--(int){IndexTab1D temp = *this; --*this; return temp;}//i--
};

class Index2D : public Index
//permet de stocker des index2D et ajoute des opérations usuelles (somme,différence)
{
private:
    int i;
    int j;
public:
    //constructeurs
    Index2D(int i, int j):i(i),j(j){}
    //getter/setter
    int getIndex() const {return i*10000+j;}
    int getI() const {return i;}
    int getJ() const {return j;}
    virtual void setI(int i){this->i = i;}
    virtual void setJ(int j){this->j = j;}
    void setIndex(int i){throw IndexException("Appel de setIndex pour un Index2D"); i++;}
    //surcharge opérateurs
    Index2D& operator=(const Index2D& index){this->i = index.getI(); this->j = index.getJ(); return *this;}
    Index2D& operator+=(const Index2D& index){this->setI(this->i+index.getI());this->setJ(this->j+index.getJ()); return *this;}
    Index2D& operator-=(const Index2D& index){this->setI(this->i-index.getI());this->setJ(this->j-index.getJ()); return *this;}
};

inline Index2D& operator+(const Index2D& i, const Index2D& j){Index2D k = i; return k+=j;}
inline Index2D& operator-(const Index2D& i, const Index2D& j){Index2D k = i; return k-=j;}


class IndexTab2D : public Index2D
//permet d'accéder aux éléments d'un tableau2D en simplifiant les opérations sur les index
{
private:
    int maxI;
    int maxJ;
    int tailleTab;
public:
    //constructeurs
    IndexTab2D(int i, int j, int maxI, int maxJ):Index2D(i,j),maxI(maxI),maxJ(maxJ),tailleTab(maxI*maxJ){}
    //getter/setter
    int getIndex() const {return this->getI()*maxI+this->getJ();}
    int getTailleTab() const {return tailleTab;}
    int getMaxI() const {return maxI;}
    int getMaxJ() const {return maxJ;}
    void setI(int i){this->setI(i); while (this->getI() < 0) this->setI(this->getI()+maxI); this->setI(this->getI()%maxI);}
    void setJ(int j){this->setJ(j); while (this->getJ() < 0) this->setJ(this->getJ()+maxJ); this->setJ(this->getJ()%maxJ);}
    void setIndex(int i, int j){this->setI(i);this->setJ(j);}
    void setIndex(int i){this->setI(i/(int)maxJ);this->setJ(i%maxJ);}
    //surcharge opérateurs
    IndexTab2D& operator++(){this->setIndex(this->getIndex()+1); return *this;}//++i
    IndexTab2D operator++(int){IndexTab2D temp = *this; ++*this; return temp;}//i++
    IndexTab2D& operator--(){this->setIndex(this->getIndex()-1); return *this;}//--i
    IndexTab2D operator--(int){IndexTab2D temp = *this; --*this; return temp;}//i--
    };

std::ostream& operator<<(std::ostream& f, const Index& i);
std::ostream& operator<<(std::ostream& f, const Index2D& i);
std::ostream& operator<<(std::ostream& f, const IndexTab2D& i);

#endif // INDEX_H
