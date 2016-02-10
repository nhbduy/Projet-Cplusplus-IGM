#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include "expression.h"

using namespace std;

class Constante : public Expression
{
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
};

#endif // CONSTANTE_H
