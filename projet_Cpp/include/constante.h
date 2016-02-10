#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include "expression.h"

using namespace std;

class Constante : public Expression
{
<<<<<<< HEAD
public:
    Constante();
    Constante(double);
    virtual ~Constante();
    double getVal() const;
    Expression* clone() const;
    friend ostream& operator<<(ostream&, const Constante &);

protected:
private:
//        double val = 0;
=======
    public:
        Constante();
        Constante(const double=0.0);
        ~Constante();
        double eval() const;
        Expression* clone() const;
        friend ostream& operator<<(ostream&, const Constante &);

    protected:
    private:
        double _value = 0;
>>>>>>> refs/remotes/origin/testConstante()
};

#endif // CONSTANTE_H
