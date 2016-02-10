#ifndef UNAIRE_H
#define UNAIRE_H
<<<<<<< HEAD

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



=======
#include "expression.h"

class Unaire : public Expression
{
    public:
        Unaire();
        Unaire(Expression *, const string& name);
        virtual ~Unaire();
        virtual string getString();
    protected:
        Expression *_op;
    private:
};

>>>>>>> refs/remotes/origin/testConstante()
#endif // UNAIRE_H
