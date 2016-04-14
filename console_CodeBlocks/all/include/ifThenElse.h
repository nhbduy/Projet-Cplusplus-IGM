/*!
 * \file ifThenElse.h
 * \brief La classe IfThenElse
 * \author TH
 * \version 0.1
 */
 #ifndef IFTHENELSE_H
#define IFTHENELSE_H

#include "expression.h"
#include "binaire.h"

/*! \class IfThenElse
 * \brief La classe IfThenElse
 *
 * Cette classe représente les structures de contrôle conditionnelles. Ils permettent d’exécuter une série d'instructions dans le cas où une condition est vraie, et d'exécuter une autre série d'instructions dans le cas contraire.
 */
class IfThenElse : public Expression
{
public:
/*!
 * \fn IfThenElse()
 * \brief Constructeur
 *
 * Constructeur de la classe IfThenElse
 *
 */
	IfThenElse();
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~IfThenElse();
   /*!
 * \fn IfThenElse(Binaire*, Expression*, Expression*)
 * \brief Constructeur
 *
 * Constructeur de la classe IfThenElse
 *
 * \param cond : le condition
 * \param exp1 : l'expression si la condition est vraie
 * \param exp2 : l'expression si la condition est fausse
 */
	IfThenElse(Binaire*, Expression*, Expression*);
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
	friend ostream & operator << (ostream & os, const IfThenElse &);
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
protected:
};

#endif // IFTHENELSE_H
