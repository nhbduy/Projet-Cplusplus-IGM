/*!
 * \file variable.h
 * \brief La classe Variable
 * \author TH
 * \version 0.1
 */
#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <map>
#include "expression.h"
#include "constante.h"

/*! \class Variable
 * \brief La classe Variable
 *
 * Cette classe représente les variables.
 */
class Variable : public Expression
{
public:

  /*!
 * \fn Variable(const string&, double)
 * \brief Constructeur
 *
 * Constructeur de la classe Variable
 *
 * \param id : le nom
  * \param val : le valeur
 */
	Variable(const string&, double);
/*!
 * \fn Variable()
 * \brief Constructeur
 *
 * Constructeur de la classe Variable
 *
 */
	Variable();
  /*!
 * \fn Variable(const string&)
 * \brief Constructeur
 *
 * Constructeur de la classe Variable
 *
 * \param id : le nom
 */
	Variable(const string&);
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
	virtual ~Variable();
/*!
 * \brief Affiche l'expression
 * Methode qui permet d'afficher l'expression
 * \return  Le string d'expression
 */
	string afficher() const;
/*!
 * \brief clone l'expression
 * Methode qui permet de cloner l'expression
* \return  L'expression cloné
 */
	Expression* clone() const;
/*!
 * \brief Affecte la une valeur a une variable
 * Methode qui permet d'affecter une valeur a un variable
 */
	double set(double);
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream & operator << (ostream &, const Variable &);
/*!
 * \brief Efface la memoire
 * Methode qui permet d'effacer le contenu de la mémoire (toutes les variables)
 */
	static void effacerMemoire();
protected:
private:
	const string _id;
	static map<string, double> _variables;

};

#endif // VARIABLE_H
