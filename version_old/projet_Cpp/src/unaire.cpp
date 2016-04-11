#include <iostream>
#include "unaire.h"

using namespace std;

Unaire::Unaire()
{
    //ctor
}

Unaire::Unaire( Expression *op, const string& name):Expression(name),_op(op)
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

Cos::Cos()
{
    //ctor
}

Cos::Cos(Expression *exp, const string&name):Unaire(exp,name)
{

}

Cos::~Cos()
{
    //dtor
}

double Cos::eval() const
{
 return cos(_op->eval());
}
