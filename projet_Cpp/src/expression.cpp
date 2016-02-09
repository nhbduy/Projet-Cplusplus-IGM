#include <iostream>
#include "expression.h"

using namespace std;

Expression::Expression()
{
    //ctor
}

Expression::~Expression()
{
    //dtor
}

double Expression::getVal() const
{
    return val;
}

Expression* Expression::clone() const
{

}

ostream& operator<<(ostream& os, const Expression & a)
{
    os << a.getVal();
    return os;
}

