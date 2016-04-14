/*!
 * \file constante.h
 * \brief La classe Constante
 * \author TH
 * \version 0.1
 */
 #ifndef CONSTANTE_H
#define CONSTANTE_H
#include "expression.h"
/*! \class Constante
 * \brief La classe Constante
 *
 * Cette classe permet de représenter un expression constante qui est un valeur numérique de type double.
 */
class Constante : public Expression
{
public:
/*!
 * \fn Constante()
 * \brief Constructeur
 *
 * Constructeur de la classe Constante

 *
 */
	Constante();
    /*!
 * \fn Constante(const double = 0.0)
 * \brief Constructeur
 *
 * Constructeur de la classe Constante
 *
 * \param val : le valeur
 */
	Constante(const double = 0.0);
/*!
 * \brief Destructeur
 * Destructeur de la classe Constante
 */
	virtual ~Constante();
/*!
 * \fn double eval() const
 * \brief Evalue l'expression
 * Methode qui permet d'evaluer l'expression
 * \return  Le valeur d'expression
 */
	virtual double eval() const;
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
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const Constante &);
	string string_from_double(double val) { ostringstream os; os << val; return os.str(); }

protected:
private:
	double _valeur = 0.0;
};

#endif // CONSTANTE_H
