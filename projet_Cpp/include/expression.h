#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

using namespace std;

class Expression
{
protected:
    double val;
//    string _nom;
public:
    Expression();
    Expression(const string&);
    virtual ~Expression();
    string getString() const;
    Expression* clone() const;
    virtual double eval() const;
    friend ostream& operator<<(ostream&, const Expression &);
};



#endif // EXPRESSION_H
