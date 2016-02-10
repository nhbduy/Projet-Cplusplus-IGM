#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

using namespace std;

class Expression
{
protected:
    double val;
public:
    Expression();
    virtual ~Expression();
    double getVal() const;
    virtual Expression* clone() const = 0;
    friend ostream& operator<<(ostream&, const Expression &);


};

#endif // EXPRESSION_H
