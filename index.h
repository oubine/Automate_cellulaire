#ifndef INDEX_H
#define INDEX_H
#include <vector>
#include <iostream>

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
    virtual unsigned int getIndex() const = 0;
    virtual void setIndex(int iAbsolu)= 0;
};


class IndexTab1D : public Index
//permet d'accéder aux éléments d'un tableau1D en simplifiant les opérations sur les index (gère les index négatifs)
{
private:
    int i;
    unsigned int tailleTab;
public:
    //constructeurs
    IndexTab1D(const IndexTab1D& index):i(index.getIndex()),tailleTab(index.getTailleTab()){}
    IndexTab1D(int i, unsigned int tailleTab):i(i),tailleTab(tailleTab){}
    //getter/setter
    unsigned int getTailleTab() const {return tailleTab;}
    unsigned int getIndex() const {return (unsigned int) i;}
    void setIndex(int i);
    void setTailleTab(unsigned int tailleTab) {this->tailleTab = tailleTab; this->setIndex(this->getIndex());}
    //surcharge opérateurs
    IndexTab1D& operator=(const IndexTab1D& i){this->setIndex(i.getIndex()); return *this;}
    IndexTab1D& operator+=(const IndexTab1D& i){this->setIndex(this->i+i.getIndex()); return *this;}
    IndexTab1D& operator+=(const int& j){this->setIndex(this->getIndex()+j); return *this;}
    IndexTab1D& operator+=(const std::vector<int>& v);
    IndexTab1D& operator-=(const IndexTab1D& i){this->setIndex(this->i-i.getIndex()); return *this;}
    IndexTab1D& operator-=(const int& i){this->setIndex(this->i-i); return *this;}
    IndexTab1D& operator-=(const std::vector<int>& v);
    IndexTab1D& operator++(){this->setIndex(this->getIndex()+1); return *this;}//++i
    IndexTab1D operator++(int){IndexTab1D temp = *this; ++*this; return temp;}//i++
    IndexTab1D& operator--(){this->setIndex(this->getIndex()-1); return *this;}//--i
    IndexTab1D operator--(int){IndexTab1D temp = *this; --*this; return temp;}//i--
    IndexTab1D operator+(const IndexTab1D& j){IndexTab1D k = *this; return k += j;}
    IndexTab1D operator+(const std::vector<int>& j){IndexTab1D k = *this; return k += j;}
    IndexTab1D operator+(const int& j){IndexTab1D k = *this; return k += j;}
    IndexTab1D operator-(const IndexTab1D& j){IndexTab1D k = *this; return k-=j;}
    IndexTab1D operator-(const std::vector<int>& j){IndexTab1D k = *this; return k -= j;}
    IndexTab1D operator-(const int& j){IndexTab1D k = *this; return k-=j;}
};


std::ostream& operator<<(std::ostream& f, const IndexTab1D& i);

class IndexTab2D : public Index
//permet d'accéder aux éléments d'un tableau2D en simplifiant les opérations sur les index
{
private:
    IndexTab1D i;
    IndexTab1D j;
    unsigned int tailleTab;
public:
    //constructeurs
    IndexTab2D(const IndexTab2D& index):i(index.getIndexI()), j(index.getIndexJ()),tailleTab(index.getTailleTab()) {}
    IndexTab2D(int i_, int j_, unsigned int tailleTabI, unsigned int tailleTabJ):i(i_,tailleTabI),j(j_,tailleTabJ),tailleTab(tailleTabI*tailleTabJ){}
    //getter/setter
    IndexTab1D getIndexI() const {return i;}
    IndexTab1D getIndexJ() const {return j;}
    unsigned int getI() const {return i.getIndex();}
    unsigned int getJ() const {return j.getIndex();}
    unsigned int getIndex() const {return (unsigned int) (this->getI()*this->getMaxJ()+this->getJ());}
    unsigned int getTailleTab() const {return tailleTab;}
    unsigned int getMaxI() const {return i.getTailleTab();}
    unsigned int getMaxJ() const {return j.getTailleTab();}
    void setI(int i){this->i.setIndex(i);}
    void setJ(int j){this->j.setIndex(j);}
    void setIndex(int i, int j){this->setI(i);this->setJ(j);}
    void setIndex(int indexAbsolu){this->setI(indexAbsolu/j.getTailleTab());this->setJ(indexAbsolu%j.getTailleTab());}
    //surcharge opérateurs
    IndexTab2D& operator=(const IndexTab2D& index){if (this != &index) {i = index.getIndexI();j = index.getIndexJ();tailleTab = index.getTailleTab(); return *this;}}
    IndexTab2D& operator++(){this->setIndex(this->getIndex()+1); return *this;}//++i
    IndexTab2D operator++(int){IndexTab2D temp = *this; ++*this; return temp;}//i++
    IndexTab2D& operator--(){this->setIndex(this->getIndex()-1); return *this;}//--i
    IndexTab2D operator--(int){IndexTab2D temp = *this; --*this; return temp;}//i--
    IndexTab2D& operator+=(const IndexTab2D& index){i += index.getI(); j += index.getJ(); return *this;}
    IndexTab2D& operator+=(const int& k){this->setIndex(this->getIndex()+k);return *this;}
    IndexTab2D& operator+=(const std::vector<int>& v);
    IndexTab2D& operator-=(const IndexTab2D& index){i -= index.getI(); j -= index.getJ(); return *this;}
    IndexTab2D& operator-=(const int& k){this->setIndex(this->getIndex()-k); return *this;}
    IndexTab2D& operator-=(const std::vector<int>& v);
    IndexTab2D operator+(const IndexTab2D& j){IndexTab2D k = *this; return k += j;}
    IndexTab2D operator+(const int j){IndexTab2D k = *this; return k += j;}
    IndexTab2D operator-(const IndexTab2D& j){IndexTab2D k = *this; return k-=j;}
    IndexTab2D operator-(const int& j){IndexTab2D k = *this; return k-=j;}
    IndexTab2D operator+(const std::vector<int>& v){IndexTab2D a = *this; return a+=v;}
    IndexTab2D operator-(const std::vector<int>& v){IndexTab2D a = *this; return a -= v;}
};



std::ostream& operator<<(std::ostream& f, const IndexTab2D& i);


#endif // INDEX_H
