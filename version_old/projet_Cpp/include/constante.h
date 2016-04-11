#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include "expression.h"

using namespace std;

class Constante : public Expression
{
private:
    double _value = 0;
public:
    Constante();
    Constante(const double=0.0);
    ~Constante();
    double eval() const;
    Expression* clone() const;
    friend ostream& operator<<(ostream&, const Constante &);
};

#endif // CONSTANTE_H
