#include "../include/expression.h"
#include "../include/constante.h"
//#include <fonction.h>
#include <math.h>

Constante::Constante()
{
    //ctor
}

Constante::Constante(const double val) : Expression(string_from_double(val)), _valeur(val)
{

}

Constante::~Constante()
{
    //dtor
}

double Constante::eval() const
{
    return _valeur;
}

Expression* Constante::deriver(const string &var)
{
	return 0;
}

Expression *Constante::simplifier()
{
    return this;
}

string Constante::afficher() const
{
    std::ostringstream os;
    os << _valeur;
    return os.str();
}

Expression* Constante::clone() const
{
    return new Constante(*this);
}

ostream& operator<<(ostream& os, const Constante & constante)
{
    os << constante.afficher();
    return os;
}


