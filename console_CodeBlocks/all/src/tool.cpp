#include <iostream>
#include <fstream>

#include "../include/expression.h"
#include "../include/constante.h"
#include "../include/binaire.h"    // contient les sous-classes de Binaire : Somme, Produit, Superieur ....
#include "../include/unaire.h"     // contient les sous-classes de Unaire : COs, Sin ....
#include "../include/variable.h"
#include "../include/affectation.h"
#include "../include/conditionnel.h"
#include "../include/ifThenElse.h"
#include "../include/boucle.h"
#include "../include/bloc.h"

using namespace std;

//CONSTANTE
Constante* sConstante() {
    double temp;

    cout << "Entrer la valeur (droit->gauche:A,B,C,D...) :  ";
    cin >> temp;

    Constante* e = new Constante(temp);

    return e;
}

//UNAIRE
Sin* sSin(Expression* e) {
    Sin* s = new Sin(e->clone());

    return s;
}

Cos* sCos(Expression* e) {
    Cos* c = new Cos(e->clone());

    return c;
}

Exponentielle* sExponentielle(Expression* e1, Expression *e2) {
    Exponentielle* e = new Exponentielle(e1->clone(), e2->clone());

    return e;
}
//--END UNAIRE

//BINAIRE
Somme* sSomme(Expression* e1, Expression* e2) {
    Somme* s = new Somme(e1->clone(), e2->clone());

    return s;
}

Difference* sDifference(Expression* e1, Expression* e2) {
    Difference* d = new Difference(e1->clone(), e2->clone());

    return d;
}

Produit* sProduit(Expression* e1, Expression* e2) {
    Produit* p = new Produit(e1->clone(), e2->clone());

    return p;
}

Division* sDivision(Expression* e1, Expression* e2) {
    Division* d = new Division(e1->clone(), e2->clone());

    return d;
}

Superieur* sSuperieur(Expression* e1, Expression* e2) {
    Superieur* s = new Superieur(e1->clone(), e2->clone());

    return s;
}

Inferieur* sInferieur(Expression* e1, Expression* e2) {
    Inferieur* i = new Inferieur(e1->clone(), e2->clone());

    return i;
}

SuperieurEgal* sSuperieurEgal(Expression* e1, Expression* e2) {
    SuperieurEgal* se = new SuperieurEgal(e1->clone(), e2->clone());

    return se;
}

InferieurEgal* sInferieurEgal(Expression* e1, Expression* e2) {
    InferieurEgal* ie = new InferieurEgal(e1->clone(), e2->clone());

    return ie;
}
//--END BINAIRE

//VARIABLE
Variable* sVariable() {
    string s;
    double d;

    cout << "Entrer nom de variable :  ";
    cin >> s;
    cout << "Entrer valeur de variable :  ";
    cin >> d;
    Variable* v = new Variable(s, d);

    return v;
}

Variable* sVariableAChercher() {
    string s;

    cout << "Entrer nom de variable à chercher (valeur d'initiale = 0) :  ";
    cin >> s;
    Variable* v = new Variable(s);

    return v;
}
//--END VARIABLE

//AFFECTATION
//--END
Affectation* sAffectation(Variable* e1, Expression* e2) {
    Affectation* a = new Affectation(e1, e2->clone());

    return a;
}

//CONDITIONNEL
Conditionnel* sConditionnel(Binaire* e1, Expression* e2, Expression* e3) {
    Conditionnel* c = new Conditionnel(e1, e2->clone(), e3->clone());

    return c;
}
//--END CONDITIONNEL

//IFTHENELSE
IfThenElse* sIfThenElse(Binaire* e1, Expression* e2, Expression* e3) {
    IfThenElse* ite = new IfThenElse(e1, e2->clone(), e3->clone());

    return ite;
}
//--END IFTHENELSE

//
//--END

void printContent(string s, string other, double d) {
    cout << "******************************************************************\n";
    cout << "Votre contenu : " << s << other << d << "\n";
    cout << "******************************************************************\n";
}

void viewMenuCreation() {
    cout << "\t-----------------------OPTIONS-----------------------" << endl;
    cout << "\t 1 : constante \n\t\tA (constante)" << endl;
    cout << "\t 2 : cosinus   \n\t\tcos(A)" << endl;
    cout << "\t 3 : binaire1  \n\t\t(C + (B * sin(A)))" << endl;
    cout << "\t 4 : binaire2  \n\t\t((D + (C * sin(B))) > A) => true(1), false(0)" << endl;
    cout << "\t 5 : variable \n\t\tx = A\n\t(y <- (C + (B * x))) = ?" << endl;
    cout << "\t 6 : conditionnel \n\t\tx = A\n\t\t((x > D)) ? (x + C) : (x + B)\n\t\t=> EVAL ternaire = ?" << endl;
    cout << "\t 7 : if then else \n\t\tx = A\n\t\tif ((x > D)) {\n\t\t\t(x <- (x + C))\n\t\t} else {\n\t\t\t(x <- (x * B))\n\t\t}\n\t\t=> EVAL if then else = ?" << endl;
    cout << "\t 8 : bloc  " << endl;
    cout << "\t 9 : boucle avec une seule expression " << endl;
    cout << "\t 10 : boucle avec bloc d'expressions " << endl;
    cout << "\t 11 : boucles imbriquées " << endl;
    cout << "\t 12 : tous les tests" << endl;
    cout << "\t-----------------------------------------------------" << endl;
    cout << "\t 0 : SEPARER des excercices et des resultats avec ***" << endl;
    cout << "\t 999 : SAUVEGARDER votre fichier et quitter" << endl;
    cout << "\t-----------------------------------------------------" << endl;
    cout << endl;
    cout << "Votre choix : ";
}

int creation() {
    string pathExe;
    cout << "Entrer le path de l'excercice que vous voulez créer : ";
    cin >> pathExe;

    string pathRes;
    cout << "Entrer le path du resultat que vous voulez stocker : ";
    cin >> pathRes;

    ofstream exe(pathExe);
    ofstream res(pathRes);

    Expression* e;

    string s;
    double d;

    string question = " = ?";
    string result = " = ";

    int choice = -1;

    do {
        viewMenuCreation();
        cin >> choice;


        switch(choice) {
            case 1:
            {
                e = sConstante();

                s = e->afficher();
                exe << s << "\n";

                d = e->eval();
                res << d << "\n";

                printContent("", "", d);

                break;
            }
            case 2:
            {
                e = sCos(sConstante());

                s = e->afficher();
                exe << s << question << "\n";

                d = e->eval();
                res << s << result << d << "\n";

                printContent(s, result, d);

                break;
            }
            case 3:
            {
                e = sSomme(sConstante(), sProduit(sConstante(), sSin(sConstante())));

                s = e->afficher();
                exe << s << question << "\n";

                d = e->eval();
                res << s << result << d << "\n";

                printContent(s, result, d);

                break;
            }
            case 4:
            {
                e = sSuperieur(sSomme(sConstante(), sProduit(sConstante(), sSin(sConstante()))), sConstante());

                s = e->afficher();
                exe << s << question << "\n";

                d = e->eval();
                res << s << result << d << "\n";

                printContent(s, result, d);

                break;
            }
            case 5:
            {
                Expression *e1;
                e1 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";

                printContent(s, result, d);
                ////////////////////////////////////
                e = sAffectation(sVariableAChercher(), sSomme(sConstante(), sProduit(sConstante(), e1->clone())));

                s = e->afficher();
                exe << s << question << "\n";

                d = e->eval();
                res << s << result << d << "\n";

                printContent(s, result, d);

                break;
            }
            case 6:
            {
                Expression *e1;
                e1 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ////////////////////////////////////
                e = sConditionnel(sSuperieur(e1, sConstante()),
                                    sSomme(e1, sConstante()),
                                    sProduit(e1, sConstante()));

                s = e->afficher();
                exe << s << "\n=> EVAL ternaire" << question << "\n";

                d = e->eval();
                res << s << "\n=> EVAL ternaire" << result << d << "\n";

                printContent(s, "\n=> EVAL ternaire" + result, d);

                break;
            }
            case 7:
            {
                Expression *e1;
                e1 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ////////////////////////////////////
                e = sIfThenElse(sSuperieur(e1, sConstante()),
                                    sAffectation(sVariableAChercher(), sSomme(e1, sConstante())),
                                    sAffectation(sVariableAChercher(), sProduit(e1, sConstante())));

                s = e->afficher();
                exe << s << "\n=> EVAL if then else" << question << "\n";

                d = e->eval();
                res << s << "\n=> EVAL if then else" << result << d << "\n";

                printContent(s, "\n=> EVAL if then else" + result, d);

                break;
            }
            case 0:
            {
                s = "******************************************************************\n\n";
                exe << s;
                res << s;
                break;
            }
            case 999:
            {
                cout << "Sauvegarder des fichiers et quitter......" << endl;
                exe.close();
                res.close();
                break;
            }
            default:
                cout << "Le cas inconnu......" << endl;
                break;
        }
    } while (choice != 999);

    return 0;
}


int main()
{
    int choice = -1;

    cout << "\t----------BIENVENUE A L'OUTIL : CREATION-EVALUATION DES EXPRESSIONS----------" << endl;
    cout << "\t 1 : creation" << endl;
    cout << "\t 2 : evaluation" << endl;
    cout << "\t 666 : quitter" << endl;
    cout << "\t-----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Votre choix : ";

    //do {
        cin >> choice;
        switch(choice) {
            case 1:
                creation();
                break;
            case 2:
                break;
            case 666:
                return 0;
                break;
            default:
                cout << "Le cas inconnu......" << endl;
                break;
        }
    //} while (choice != 666);

    return 0;
}


