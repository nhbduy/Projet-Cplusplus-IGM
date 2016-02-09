#include <iostream>
#include "expression.h"
#include "constante.h"

using namespace std;

Constante::Constante()
{
    //ctor
}

Constante::Constante(double n) : Expression()
{
    val = n;
}

Constante::~Constante()
{
    //dtor
}

double Constante::getVal() const
{
    return val;
}

Expression* Constante::clone() const
{
    return new Constante(*this);
}

ostream& operator<<(ostream& os, const Constante & a)
{
    os << "cde";
    return os;
}
