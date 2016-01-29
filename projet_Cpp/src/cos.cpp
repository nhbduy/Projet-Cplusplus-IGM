#include "cos.h"


Cos::Cos()
{
    //ctor
}

Cos::Cos(double x)
{
    val = x;
}

Cos::Cos(Constante c)
{
    val = c.getVal();
}

Cos::~Cos()
{
    //dtor
}

double Cos::eval()
{
    return cos(val);
}

ostream& operator<<(ostream& os, const Cos & a)
{
    os << "abc";
    return os;
}
