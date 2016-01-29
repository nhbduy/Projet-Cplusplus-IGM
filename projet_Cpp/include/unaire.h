#ifndef UNAIRE_H
#define UNAIRE_H
#include "expression.h"

class Unaire : public Expression
{
    public:
        Unaire();
        Unaire(const string& name, Expression *);
        virtual ~Unaire();
        virtual string getString();
    protected:
        Expression *_op;
    private:
};

#endif // UNAIRE_H
