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

void viewMenu();

Expression* sConstante();
Expression* sCosinus();
Expression* sBinaire1();
Expression* sBinaire2();

int main()
{
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
        viewMenu();
        cin >> choice;


        switch(choice) {
            case 0:
            {
                e = sConstante();

                s = e->afficher();
                exe << s << "\n";

                d = e->eval();
                res << d << "\n";

                break;
            }
            case 1:
            {
                e = sCosinus();

                s = e->afficher();
                exe << s << question << "\n";

                d = e->eval();
                res << s << result << d << "\n";

                break;
            }
            case 2:
            {
                string name;
                cout << "Entrer le nom d'expression : ";
                cin >> name;

                e = sBinaire1();

                s = e->afficher();
                exe << name << " : " << s << question << "\n";

                d = e->eval();
                res << name << " : " << s << result << d << "\n";

                break;
            }
            case 3:
//            {
//                e = sBinaire2();
//
//                s = e->afficher();
//                exe << s << question << "\n";
//
//                d = e->eval();
//                res << s << result << d << "\n";

                break;
//            }

            case 000:
            {
                s = "******************************************************************\n\n";
                exe << s;
                res << s;
                break;
            }
            default:
                cout << "Sauvegarder vos fichiers......" << endl;
                exe.close();
                res.close();
                break;
        }
    } while (choice != 999);
}

void viewMenu() {
    cout << " 0 : constante, [Ex] 5" << endl;
    cout << " 1 : cosinus, [Ex] cos(1.0472)" << endl;
    cout << " 2 : binaire1, [Ex] (1 + (2 * sin(0.523599)))" << endl;
    cout << " 3 : binaire2, [Ex] ((1 + (2 * sin(0.523599))) > 1.8) => true(1), false(0)" << endl;
    cout << " 4 : variable1" << endl;
    cout << " 5 : variable2" << endl;
    cout << " 6 : conditionnel" << endl;
    cout << " 7 : if then else" << endl;
    cout << " 8 : bloc" << endl;
    cout << " 9 : boucle avec une seule expression" << endl;
    cout << " 10 : boucle avec bloc d'expressions" << endl;
    cout << " 11 : boucles imbriquées" << endl;
    cout << " 12 : tous les tests" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << " 000 : SEPARER des excercices et des resultats avec ***" << endl;
    cout << " 999 : SAUVEGARDER votre fichier" << endl;
     cout << "----------------------------------------------------" << endl;
    cout << endl;
    cout << "Votre choix : ";
}

Expression* sConstante() {
    double temp;

    cout << "Entrer le valeur de constante :  ";
    cin >> temp;

    Expression* e = new Constante(temp);

    return e;
}

Expression* sCosinus() {
    double temp;

    cout << "Entrer le valeur de cos :  ";
    cin >> temp;

    Cos* c = new Cos(new Constante(temp));

    return c;
}

Expression* sBinaire1() {

    double a, b, c;

    cout << "Entrer le valeur de a :  ";
    cin >> a;
    cout << "Entrer le valeur de b :  ";
    cin >> b;
    cout << "Entrer le valeur de c :  ";
    cin >> c;

    Somme* s = new Somme(new Constante(a), new Produit(new Constante(b), new Sin(new Constante(c))));

    return s;
}


