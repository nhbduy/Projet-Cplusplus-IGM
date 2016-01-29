#include "unaire.h"

Unaire::Unaire()
{
    //ctor
}

Unaire::Unaire(const string& name, Expression *op):Expression(name),_op(op)
{
}

Unaire::~Unaire()
{
    //dtor
}

string Unaire::getString()
{
return Expression::_nom+"("+ _op->getString() +")";
}
