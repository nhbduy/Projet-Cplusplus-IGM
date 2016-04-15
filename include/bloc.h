/*!
 * \file bloc.h
 * \brief La classe Bloc
 * \author TH
 * \version 0.1
 */

#ifndef BLOC_H
#define BLOC_H
#include <list>
#include "expression.h"
#include "binaire.h"

/*! \class Bloc
 * \brief La classe Bloc
 *
 * Cette classe représente une séquence d’instructions (expression) sur le même modèle
 */
class Bloc : public Expression
{
public:
/*!
 * \fn Bloc()
 * \brief Constructeur
 *
 * Constructeur de la classe Bloc
 *
 */
	Bloc();
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Bloc();
/*!
 * \fn Bloc(const string &, Expression*)
 * \brief Constructeur
 *
 * Constructeur de la classe Bloc
 *
 * \param nom : nom du bloc
 * \param expression : l'expression
 */
	Bloc(const string &, Expression*);
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
	friend ostream & operator << (ostream & os, const Bloc &);
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
	void add(Expression*);
private:
	list<Expression*> _exp;
	const string _nom;
protected:
};

#endif // BLOC_H
