#ifndef WINDOW_DIM1_H
#define WINDOW_DIM1_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>

class AutoCell : public QWidget{
Q_OBJECT
    QVBoxLayout* couche;
    // Question 3
    QTableWidget* etats;
    unsigned int dimension;
    QLabel  *numero;
    QTableWidget* depart;
    int num_automate;
    unsigned int nb_transitions;
public:
    explicit AutoCell(QWidget* parent = nullptr);
    explicit AutoCell(QWidget* parent = nullptr, unsigned int dim=1, unsigned int transitions=1);
    int getDimension() const {return dimension;}
    QLabel* getNumLabel() const {return numero;}
    QTableWidget* getDepart() const {return depart;}
    int getNumAutomate() const {return num_automate;}
    void setNumAutomate(int i){num_automate=i;}
    void setEtatDepart(QTableWidget* dep){depart=dep;}
    void setDimension(unsigned int i){dimension=i;}
    void setNbTransitions(unsigned int i){dimension=i;}
public slots:
    void launchSimulation();
};

#endif // WINDOW_DIM1_H
