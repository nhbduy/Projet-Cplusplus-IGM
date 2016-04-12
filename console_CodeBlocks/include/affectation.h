/*!
 * \file affectation.h
 * \brief La classe Affectation
 * \version 0.1
 */


#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "binaire.h"
#include "variable.h"

/*! \class Affectation
 * \brief La classe Affectation
 *
 * La classe permet d’affecter une valeur à une variable. Par exemple : x = 1, y = 2
 */

class Affectation : public Binaire
{
public:

/*!
 * \fn Affectation()
 * \brief Constructeur
 *
 * Constructeur de la classe Affectation
 *
 */
	Affectation();
/*!
 * \fn Affectation(Variable*, Expression*)
 * \brief Constructeur
 *
 * Constructeur de la classe Affectation
 *
 * \param variable : le variable
 * \param valeur : le valeur
 */
	Affectation(Variable*, Expression*);
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
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Affectation();
/*!
 * \brief clone l'expression
 * Methode qui permet de cloner l'expression
* \return  L'expression cloné
 */
	Expression* clone() const;
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
	friend ostream & operator << (ostream & os, const Affectation & affectation);
protected:
private:
    /*!
 * \brief Expression
 *
 * Methode qui permet d'afficher l'expression
 */
	Expression *_expression;
	Variable *_variable;
};

#endif // AFFECTATION_H
