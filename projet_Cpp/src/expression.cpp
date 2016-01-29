#include "expression.h"

Expression::Expression()
{
    //ctor
}

Expression::Expression(const string& nom) : _nom(nom) {

}

Expression::~Expression()
{
    //dtor
}

string Expression::getNom() const
{
    return _nom;
}

Expression* Expression::clone() const
{

}



ostream& operator<<(ostream& os, const Expression & a)
{
    os << a.getNom();
    return os;
}

