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

    cout << "Entrer la valeur (A->B->C->D->E->...) :  ";
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
    Affectation* a = new Affectation(e1, e2);

    return a;
}

//CONDITIONNEL
Conditionnel* sConditionnel(Binaire* e1, Expression* e2, Expression* e3) {
    Conditionnel* c = new Conditionnel(e1, e2, e3);

    return c;
}
//--END CONDITIONNEL

//IFTHENELSE
IfThenElse* sIfThenElse(Binaire* e1, Expression* e2, Expression* e3) {
    IfThenElse* ite = new IfThenElse(e1, e2, e3);

    return ite;
}
//--END IFTHENELSE

//BLOC
Bloc* sBloc(string s, Expression* e) {
    Bloc* b = new Bloc(s, e);

    return b;
}
//--END BLOC

//POUR
Pour* sPour(Expression* e1, Expression* e2, Expression* e3, Expression* e4) {
    Pour* p = new Pour(e1, e2, e3, e4);

    return p;
}
//--END POUR
void printContent(string s, string other, double d) {
    cout << "******************************************************************\n";
    cout << "Votre contenu : " << s << other << d << "\n";
    cout << "******************************************************************\n";
}

void viewMenuCreation() {
    cout << "\t-----------------------OPTIONS-----------------------" << endl;
    cout << "\t 1 : constante" << endl;
    cout << "\t 2 : cosinus" << endl;
    cout << "\t 3 : binaire1" << endl;
    cout << "\t 4 : binaire2" << endl;
    cout << "\t 5 : variable" << endl;
    cout << "\t 6 : conditionnel" << endl;
    cout << "\t 7 : if then else" << endl;
    cout << "\t 8 : bloc" << endl;
    cout << "\t 9 : boucle avec une seule expression" << endl;
    cout << "\t-----------------------------------------------------" << endl;
    cout << "\t 0 : SEPARER des excercices et des resultats avec ***" << endl;
    cout << "\t 999 : SAUVEGARDER votre fichier et quitter" << endl;
    cout << "\t-----------------------------------------------------" << endl;
    cout << endl;
    cout << "Votre choix : ";
}

int creation() {
    string pathExe;
    cout << "Entrer le path de l'excercice que vous voulez créer (.txt) : ";
    cin >> pathExe;

    string pathRes;
    cout << "Entrer le path du resultat que vous voulez stocker (.txt) : ";
    cin >> pathRes;

    ofstream exe;
    exe.open(pathExe);
    ofstream res;
    res.open(pathRes);

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
                cout << "\n\t\tA (constante)\n" << endl;

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
                cout << "\n\t\tcos(A)\n" << endl;
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
                cout << "\n\t\t(C + (B * sin(A)))\n" << endl;
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
                cout << "\n\t\t((D + (C * sin(B))) > A) => true(1), false(0)\n" << endl;
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
                cout << "\n\t\tx = A\n\t(y <- (C + (B * x))) = ?\n" << endl;
                Variable *e1;
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
                cout << "\n\t\tx = A\n\t\t((x > D)) ? (x + C) : (x + B)\n\t\t=> EVAL ternaire = ?\n" << endl;
                Variable *e1;
                e1 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ////////////////////////////////////
                e = sConditionnel(sSuperieur(e1->clone(), sConstante()),
                                    sSomme(e1->clone(), sConstante()),
                                    sProduit(e1->clone(), sConstante()));

                s = e->afficher();
                exe << s << "\n=> EVAL ternaire" << question << "\n";

                d = e->eval();
                res << s << "\n=> EVAL ternaire" << result << d << "\n";

                printContent(s, "\n=> EVAL ternaire" + result, d);

                break;
            }
            case 7:
            {
                cout << "\n\t\tx = A\n\t\tif ((x > D)) {\n\t\t\t(x <- (x + C))\n\t\t} else {\n\t\t\t(x <- (x * B))\n\t\t}\n\t\t=> EVAL if then else = ?\n" << endl;
                Variable *e1;
                e1 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ////////////////////////////////////
                e = sIfThenElse(sSuperieur(e1->clone(), sConstante()),
                                    sAffectation(e1, sSomme(e1->clone(), sConstante())),
                                    sAffectation(e1, sProduit(e1->clone(), sConstante())));

                s = e->afficher();
                exe << s << "\n=> EVAL if then else" << question << "\n";

                d = e->eval();
                res << s << "\n=> EVAL if then else" << result << d << "\n";

                printContent(s, "\n=> EVAL if then else" + result, d);

                break;
            }
            case 8:
            {
                cout << "\n\t\tx = A\n\t\ty = B\n\t\t{\n\t\t\t(x <- (x + C))\n\t\t\tif ((x > F)) {\n\t\t\t(x <- (x + E))\n\t\t} else {\n\t\t\t(x <- (x * D))\n\t\t}\n\t\t\t(y <- (x + G))\n\t\t}\n\t\t=> EVAL bloc = ?\n" << endl;

                Variable *e1; //x
                e1 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ///////////////////////////////
                Variable *e2; //y
                e2 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ///////////////////////////////
                Bloc* b;
                b = sBloc("b1", sAffectation(e1, sSomme(e1->clone(), sConstante())));
                b->add(sIfThenElse(sSuperieur(e1->clone(), sConstante()),
                                    sAffectation(e1, sSomme(e1->clone(), sConstante())),
                                    sAffectation(e1, sProduit(e1->clone(), sConstante()))));



                b->add(sAffectation(e2, sSomme(e1->clone(), sConstante())));

                s = b->afficher();
                exe << s << "\n=> EVAL bloc" << question << "\n";

                d = b->eval();
                res << s << "\n=> EVAL bloc" << result << d << "\n";

                printContent(s, "\n=> EVAL bloc" + result, d);

                break;
            }
            case 9:
            {
                cout << "\n\t\tx = A\n\t\ti = B\n\t\tfor ((i <- E); (x > (i + D)); (i <- (i + C))) {\n\t\t\t(res <- (res * i))\n\t\t}\n\t\t=>EVAL pour = ?\n" << endl;

                Variable *e1; //x
                e1 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ///////////////////////////////
                Variable *e2; //i
                e2 = sVariable();

                s = e1->afficher();
                d = e1->eval();

                exe << s << result << d << "\n";
                res << s << result << d << "\n";
                ///////////////////////////////
                Variable *e3; //res
                e3 = new Variable("res", 1);
                ///////////////////////////////
                e = sPour(sAffectation(e2, sConstante()),
                            sSuperieur(e1->clone(), sSomme(e2->clone(), sConstante())),
                            sAffectation(e2, sSomme(e2->clone(), sConstante())),
                            sAffectation(e3, sProduit(e3->clone(), e2->clone())));

                s = e->afficher();
                exe << s << "\n=> EVAL pour" << question << "\n";

                d = e->eval();
                res << s << "\n=> EVAL pour" << result << d << "\n";

                printContent(s, "\n=> EVAL bloc" + result, d);

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

int evaluation() {
    int choice = -1;

    cout << "\t-----------------------OPTIONS-----------------------" << endl;
    cout << "\t 1 : comparer des resultats et des copies d'eleves" << endl;
    cout << "\t 2 : corriger des rcopies" << endl;
    cout << "\t 3 : ajouter des annotations" << endl;
    cout << "\t-----------------------------------------------------" << endl;
    cout << "\t 999 : SAUVEGARDER votre fichier et quitter" << endl;
    cout << "\t-----------------------------------------------------" << endl;
    cout << endl;
    cout << "Votre choix : ";

    do {
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "EN COURS......" << endl;
                return 0;
                break;
            case 2:
                cout << "EN COURS......" << endl;
                return 0;
                break;
            case 999:
                cout << "Sauvegarder des fichiers et quitter......" << endl;
                break;
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

    cin >> choice;
    switch(choice) {
        case 1:
            creation();
            break;
        case 2:
            evaluation();
            break;
        case 666:
            return 0;
            break;
        default:
            cout << "Le cas inconnu......" << endl;
            break;
    }

    return 0;
}


