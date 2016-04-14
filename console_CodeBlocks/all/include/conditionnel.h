/*!
 * \file conditionnel.h
 * \brief La classe Conditionnel
 * \author TH
 * \version 0.1
 */
#ifndef CONDITIONNEL_H
#define CONDITIONNEL_H

#include "expression.h"
#include "binaire.h"

/*! \class Conditionnel
 * \brief La classe Conditionnel
 *
 * Cette classe représente les opérateurs ternaire. Elles permettent d'obtenir une valeur si une condition est vraie, et une autre si la condition est fausse. Ils ont de forme :
(cond)?e1:e2
 */
class Conditionnel : public Expression
{
    public:
    /*!
 * \fn Conditionnel()
 * \brief Constructeur
 *
 * Constructeur de la classe Conditionnel
 *
 */
        Conditionnel();
    /*!
 * \fn Conditionnel(Binaire*, Expression*, Expression*)
 * \brief Constructeur
 *
 * Constructeur de la classe Conditionnel
 *
 * \param cond : la condition
 * \param exp1 : l'expression si la condition est vraie
 * \param exp2 : l'expression si la condition est fausse
 */
        Conditionnel(Binaire*, Expression*, Expression*);
    /*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
        virtual ~Conditionnel();
    /*!
 * \brief clone l'expression
 * Methode qui permet de cloner l'expression
* \return  L'expression cloné
 */
        Expression *clone() const;
    /*!
 * \brief Affiche l'expression
 * Methode qui permet d'afficher l'expression
 * \return  Le string d'expression
 */
        string afficher() const;
    /*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
        friend ostream & operator << (ostream & os, const Conditionnel &);
    /*!
 * \fn double eval() const
 * \brief Evalue l'expression
 * Methode qui permet d'evaluer l'expression
 * \return  Le valeur d'expression
 */
        double eval() const;
    /*!
* \fn Expression *deriver(const string &)
 * \brief Derive l'expression*
 * Methode qui permet deriver l'expression
 *\return  L'expression derivé
 */
        Expression *deriver(const string &);
    /*!
 * \brief Simplifie l'expression
 * Methode qui permet de simplifier l'expression
* \return  L'expression simplifié
 */
        Expression *simplifier();
    private:
        Binaire *_cond;
        Expression *_exp1, *_exp2;
};

#endif // CONDITIONNEL_H
