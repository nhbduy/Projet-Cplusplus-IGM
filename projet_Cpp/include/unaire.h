#ifndef UNAIRE_H
#define UNAIRE_H

#include <iostream>

using namespace std;

class Unaire : public Expression
{
protected:
    Expression *exp;
public:
    Unaire();
    virtual ~Unaire();

    virtual double getVal();

};

class Cos : public Unaire
{
protected:
     double val;
public:
     Cos();
     Cos(double);
     Cos(Constante);
     virtual ~Cos();
     double eval();
     friend ostream& operator<<(ostream&, const Cos &);
};



#endif // UNAIRE_H
