/*!
 * \file binaire.h
 * \brief La classe Binaire
 * \author TH
 * \version 0.1
 */


#ifndef BINAIRE_H
#define BINAIRE_H

#include "expression.h"

/*! \class Binaire
 * \brief La classe Binaire
 *
 * Cette classe représente les opérateurs binaires
 */


class Binaire : public Expression
{
public:
/*!
 * \fn Binaire()
 * \brief Constructeur
 *
 * Constructeur de la classe Binaire
 *
 */
	Binaire();
/*!
 * \brief Destructeur
 * Destructeur de la classe Binaire
 */
	virtual ~Binaire();
/*!
 * \fn Binaire(Expression *, Expression *, const string& name = "binaire")
 * \brief Constructeur
 *
 * Constructeur de la classe Binaire
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
 */
	Binaire(Expression *, Expression *, const string& name = "binaire");
/*!
 * \brief Affiche l'expression
 * Methode qui permet d'afficher l'expression
 * \return  Le string d'expression
 */
	virtual string afficher();
protected:
	Expression *_gauche, *_droite;
private:
};

/*! \class Somme
 * \brief La classe Somme
 *
 * Cette classe représente l'addition
 */

class Somme : public Binaire
{
public:
/*!
 * \fn Somme()
 * \brief Constructeur
 *
 * Constructeur de la classe Somme
 *
 */
	Somme();
/*!
 * \brief Destructeur
 * Destructeur de la classe Somme
 */
	virtual ~Somme();
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
	Expression *clone() const;
/*!
 * \brief Affiche l'expression
 * Methode qui permet d'afficher l'expression
 * \return  Le string d'expression
 */
	string afficher() const;
/*!
 * \fn Somme(Expression *, Expression *, const string& name = "+");
 * \brief Constructeur
 *
 * Constructeur de la classe Somme
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
* \param nom : nom d'expression
 */
	Somme(Expression *, Expression *, const string& name = "+");
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const Somme &);

protected:
private:
};

/*! \class Difference
 * \brief La classe Difference
 *
 * Cette classe représente le soustraction
 */
class Difference : public Binaire
{
public:
/*!
 * \fn Difference()
 * \brief Constructeur
 *
 * Constructeur de la classe Difference
 *
 */
	Difference();
/*!
 * \brief Destructeur
 * Destructeur de la classe Difference
 */
	virtual ~Difference();
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
	Expression *clone() const;
/*!
 * \brief Affiche l'expression
 * Methode qui permet d'afficher l'expression
 * \return  Le string d'expression
 */
	string afficher() const;
/*!
 * \fn Difference(Expression *, Expression *, const string& name = "-");
 * \brief Constructeur
 *
 * Constructeur de la classe Difference
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
* \param nom : nom d'expression
 */
	Difference(Expression *, Expression *, const string& name = "-");
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const Difference &);

protected:
private:
};

/*! \class Produit
 * \brief La classe Produit
 *
 * Cette classe représente le multiplication
 */
class Produit : public Binaire
{
public:
/*!
 * \fn Produit()
 * \brief Constructeur
 *
 * Constructeur de la classe Produit
 *
 */
	Produit();
/*!
 * \brief Destructeur
 * Destructeur de la classe Produit
 */
	virtual ~Produit();
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
 * \fn Produit(Expression *, Expression *, const string& name = "-");
 * \brief Constructeur
 *
 * Constructeur de la classe Produit
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
* \param nom : nom d'expression
 */
	Produit(Expression *, Expression *, const string& name = "*");
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const Produit &);

protected:
private:
};

/*! \class Division
 * \brief La classe Division
 *
 * Cette classe représente le division
 */
class Division : public Binaire
{
public:
/*!
 * \fn Division()
 * \brief Constructeur
 *
 * Constructeur de la classe Division
 *
 */
	Division();
/*!
 * \brief Destructeur
 * Destructeur de la classe Division
 */
	virtual ~Division();
/*!
 * \fn double eval() const
 * \brief Evalue l'expression
 * Methode qui permet d'evaluer l'expression
 * \return  Le valeur d'expression
 */
	double eval() const;
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
 * \fn Division(Expression *, Expression *, const string& name = "/");
 * \brief Constructeur
 *
 * Constructeur de la classe Division
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
* \param nom : nom d'expression
 */
	Division(Expression *, Expression *, const string& name = "/");
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const Division &);

protected:
private:
};

/*! \class Superieur
 * \brief La classe Superieur
 *
 * Cette classe représente les opérateurs de comparaison strictement supérieur
 */
class Superieur : public Binaire
{
public:
/*!
 * \fn Superieur()
 * \brief Constructeur
 *
 * Constructeur de la classe Superieur
 *
 */
	Superieur();
/*!
 * \brief Destructeur
 * Destructeur de la classe Superieur
 */
	virtual ~Superieur();
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
 * \fn Superieur(Expression *, Expression *);
 * \brief Constructeur
 *
 * Constructeur de la classe Superieur
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
 */
	Superieur(Expression *, Expression *);
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const Superieur &);

protected:
private:
};

/*! \class Inferieur
 * \brief La classe Inferieur
 *
 * Cette classe représente les opérateurs de comparaison strictement inferieur
 */
class Inferieur : public Binaire
{
public:
/*!
 * \fn Inferieur()
 * \brief Constructeur
 *
 * Constructeur de la classe Inferieur
 *
 */
	Inferieur();
/*!
 * \brief Destructeur
 * Destructeur de la classe Inferieur
 */
	virtual ~Inferieur();
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
 * \fn Inferieur(Expression *, Expression *);
 * \brief Constructeur
 *
 * Constructeur de la classe Inferieur
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
 */
	Inferieur(Expression *, Expression *);
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const Inferieur &);

protected:
private:
};

/*! \class SuperieurEgal
 * \brief La classe SuperieurEgal
 *
 * Cette classe représente les opérateurs de comparaison supérieur ou égal
 */
class SuperieurEgal : public Binaire
{
public:
/*!
 * \fn SuperieurEgal()
 * \brief Constructeur
 *
 * Constructeur de la classe SuperieurEgal
 *
 */
	SuperieurEgal();
/*!
 * \brief Destructeur
 * Destructeur de la classe SuperieurEgal
 */
	virtual ~SuperieurEgal();
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
 * \fn SuperieurEgal(Expression *, Expression *);
 * \brief Constructeur
 *
 * Constructeur de la classe SuperieurEgal
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
 */
	SuperieurEgal(Expression *, Expression *);
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const SuperieurEgal &);

protected:
private:
};

/*! \class InferieurEgal
 * \brief La classe InferieurEgal
 *
 * Cette classe représente les opérateurs de comparaison inferieur ou egal
 */
class InferieurEgal : public Binaire
{
public:
/*!
 * \fn InferieurEgal()
 * \brief Constructeur
 *
 * Constructeur de la classe InferieurEgal
 *
 */
	InferieurEgal();
/*!
 * \brief Destructeur
 * Destructeur de la classe InferieurEgal
 */
	virtual ~InferieurEgal();
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
 * \fn InferieurEgal(Expression *, Expression *);
 * \brief Constructeur
 *
 * Constructeur de la classe InferieurEgal
 *
 * \param exp1 : opérande gauche
 * \param exp2 : opérande droite
 */
	InferieurEgal(Expression *, Expression *);
/*!
 * \brief operator<<
 * Methode qui permet d'afficher l'expression
 */
	friend ostream& operator<<(ostream&, const InferieurEgal &);

protected:
private:
};


#endif // BINAIRE_H
