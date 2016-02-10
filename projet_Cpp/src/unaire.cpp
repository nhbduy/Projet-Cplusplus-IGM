#include <iostream>
#include "unaire.h"

using namespace std;

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
