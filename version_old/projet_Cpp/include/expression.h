#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

using namespace std;

class Expression
{
protected:
    string _nom;
    static unsigned int _nbexpr;
public:
    Expression(const string&="expression");

    virtual ~Expression();

    double calculer()=0;

    string getNom() const;

    void print() const;

    static unsigned int getNbExpressions();
};

#endif // EXPRESSION_H
