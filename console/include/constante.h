#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "expression.h"

class Constante : public Expression
{
public:
	Constante();
	Constante(const double = 0.0);
	virtual ~Constante();
	virtual double eval() const;
	Expression *deriver(const string &);
	Expression *simplifier();
	string afficher() const;
	Expression* clone() const;
	friend ostream& operator<<(ostream&, const Constante &);
	string string_from_double(double val) { ostringstream os; os << val; return os.str(); }

protected:
private:
	double _valeur = 0.0;
};

#endif // CONSTANTE_H
