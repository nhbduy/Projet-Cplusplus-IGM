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

Expression* sConstante();
Expression* sCosinus();
Expression* sBinaire();

int main()
{
    string pathFile;
    cout << "Entrer le path de l'excercice que vous voulez créer : ";
    cin >> pathFile;

    ofstream file(pathFile);

    Expression* e;

    int choice = -1;

    do {
        cout << " 0 : constante, [Ex] 5" << endl;
        cout << " 1 : cosinus, [Ex] cos(1.0472)" << endl;
        cout << " 2 : binaire, [Ex] s : (1 + (2 * sin(0.523599)))" << endl;
        cout << " 3 : variable1" << endl;
        cout << " 4 : variable2" << endl;
        cout << " 5 : conditionnel" << endl;
        cout << " 6 : if then else" << endl;
        cout << " 7 : bloc" << endl;
        cout << " 8 : boucle avec une seule expression" << endl;
        cout << " 9 : boucle avec bloc d'expressions" << endl;
        cout << " 10 : boucles imbriquées" << endl;
        cout << " 11 : tous les tests" << endl;
        cout << "333 : Separer des excercices avec ***" << endl;
        cout << "666 : Sauvegarder votre fichier" << endl;
        cout << endl;
        cout << "Votre choix : ";
        cin >> choice;


        switch(choice) {
            case 0:
            {
                e = sConstante();
                string s = e->afficher();
                file << s << "\n";
                break;
            }
            case 1:
            {
                e = sCosinus();
                string s = e->afficher();
                file << s << "\n";
                break;
            }
            case 2:
            {
                string name;
                cout << "Entrer le nom d'expression : ";
                cin >> name;

                e = sBinaire();
                string s = e->afficher();
                file << name << " : " << s << "\n";
                break;
            }
            case 333:
            {
                string s = "******************************************************************";
                file << s << "\n" << "\n";
                break;
            }
            default:
                cout << "Sauvegarder votre fichier......" << endl;
                file.close();
                break;
        }
    } while (choice != 666);
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

Expression* sBinaire() {

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


