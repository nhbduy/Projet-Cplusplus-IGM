/*!
 * \file boucle.h
 * \brief La classe Pour
 * \author TH
 * \version 0.1
 */

#ifndef BOUCLE_H
#define BOUCLE_H
#include "expression.h"

/*! \class Pour
 * \brief La classe Pour
 *
 * Cette classe représente les structures itératives. Elles permettent de réaliser des boucles.
 */
class Pour : public Expression
{
public:
/*!
 * \fn Pour()
 * \brief Constructeur
 *
 * Constructeur de la classe Pour
 *
 */
	Pour();
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Pour();
/*!
 * \fn Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc)
 * \brief Constructeur
 *
 * Constructeur de la classe Pour
 * \param init : l'initialisation
 * \param cond : le condition
 * \param incr : l'incrementaion
 * \param calcul : le calcul
 */
	Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc);
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
	friend ostream & operator << (ostream & os, const Pour &);
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
protected:
private:
	Expression *_init, *_cond, *_incr, *_calcul;
};

#endif // BOUCLE_H
