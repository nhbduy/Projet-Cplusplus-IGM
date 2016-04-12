/*!
 * \file unaire.h
 * \brief La classe Unaire
 * \author TH
 * \version 0.1
 */
#ifndef UNAIRE_H
#define UNAIRE_H

#include "expression.h"
#include "binaire.h"


/*! \class Unaire
 * \brief La classe Unaire
 *
 * Cette classe représente les opérateurs unaires. Ces operateur agissent sur un seul opérande qui peut-être une constante, une variable, ou une expression.
 */
class Unaire : public Expression
{
public:
/*!
 * \fn Unaire()
 * \brief Constructeur
 *
 * Constructeur de la classe Unaire
 *
 */
	Unaire();
   /*!
 * \fn Unaire(Expression *, const string& name = "unaire")
 * \brief Constructeur
 *
 * Constructeur de la classe Unaire
 *
 * \param exp : l'expression
  * \param nom : le nom
 */
	Unaire(Expression *, const string& name = "unaire");
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Unaire();
/*!
 * \brief Affiche l'expression
 * Methode qui permet d'afficher l'expression
 * \return  Le string d'expression
 */
	virtual string afficher();
protected:
	Expression *_op;
private:
};

/*! \class Sin
 * \brief La classe Sin
 *
 * Cette classe représente le Sin.
 */
class Sin : public Unaire
{
public:
/*!
 * \fn Sin()
 * \brief Constructeur
 *
 * Constructeur de la classe Sin
 *
 */
	Sin();
   /*!
 * \fn Sin(Expression *, const string& name = "sin")
 * \brief Constructeur
 *
 * Constructeur de la classe Sin
 *
 * \param exp : l'expression
  * \param nom : le nom
 */
	Sin(Expression *, const string& name = "sin");
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Sin();
/*!
 * \brief clone l'expression
 * Methode qui permet de cloner l'expression
* \return  L'expression cloné
 */
	Expression* clone() const;
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
	double val;
private:
};

/*! \class Cos
 * \brief La classe Cos
 *
 * Cette classe représente le Cos.
 */
class Cos : public Unaire
{
public:
/*!
 * \fn Cos()
 * \brief Constructeur
 *
 * Constructeur de la classe Cos
 *
 */
	Cos();
   /*!
 * \fn Cos(Expression *, const string& name = "cos")
 * \brief Constructeur
 *
 * Constructeur de la classe Cos
 *
 * \param exp : l'expression
  * \param nom : le nom
 */
	Cos(Expression *, const string& name = "cos");
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Cos();
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
 * \brief clone l'expression
 * Methode qui permet de cloner l'expression
* \return  L'expression cloné
 */
	Expression* clone() const;
protected:
	double val;
private:
};

/*! \class Exponentielle
 * \brief La classe Exponentielle
 *
 * Cette classe représente l'Exponentielle.
 */
class Exponentielle : public Unaire
{
public:
/*!
 * \fn Exponentielle()
 * \brief Constructeur
 *
 * Constructeur de la classe Exponentielle
 *
 */
	Exponentielle();
   /*!
 * \fn Exponentielle(Expression *, Expression *, const string& name = "ex")
 * \brief Constructeur
 *
 * Constructeur de la classe Exponentielle
 *
 * \param exp1 : l'expression
 * \param exp2 : le puissance
  * \param nom : le nom
 */
	Exponentielle(Expression *, Expression *, const string& name = "ex");
/*!
 * \brief Destructeur
 * Destructeur de la classe Affectation
 */
	virtual ~Exponentielle();
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
	friend ostream& operator<<(ostream&, const Exponentielle &);

protected:
	Expression* _exp;
	Expression* _pow;
private:
};

#endif // UNAIRE_H
