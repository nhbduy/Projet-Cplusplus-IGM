/*!
 * \file expression.h
 * \brief La classe Expression
 * \author TH
 * \version 0.1
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

/*! \class Expression
 * \brief La classe Expression
 *
 * Cette classe représente l'expression
 */
class Expression
{
public:
/*!
 * \fn Expression()
 * \brief Constructeur
 *
 * Constructeur de la classe Expression
 *
 */
	Expression();
   /*!
 * \fn Expression(const string&)
 * \brief Constructeur
 *
 * Constructeur de la classe Expression
 *
 * \param nom : le nom d'expression
 */
	Expression(const string&);
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Expression();
/*!
 * \brief Affiche l'expression
 * Methode qui permet d'afficher l'expression
 * \return  Le string d'expression
 */
	virtual string afficher() const;
/*!
 * \brief clone l'expression
 * Methode qui permet de cloner l'expression
* \return  L'expression cloné
 */
	virtual Expression *clone() const = 0;
/*!
* \fn Expression *deriver(const string &)
 * \brief Derive l'expression*
 * Methode qui permet deriver l'expression
 *\return  L'expression derivé
 */
	virtual Expression *deriver(const string&) = 0;
/*!
 * \brief Simplifie l'expression
 * Methode qui permet de simplifier l'expression
* \return  L'expression simplifié
 */
	virtual Expression *simplifier() = 0;
/*!
 * \fn double eval() const
 * \brief Evalue l'expression
 * Methode qui permet d'evaluer l'expression
 * \return  Le valeur d'expression
 */
	virtual double eval() const = 0;
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
 	friend ostream& operator<<(ostream&, const Expression &);
	static void toutLiberer();
protected:
	/*double val;*/
	string _nom;
private:

};



#endif // EXPRESSION_H
