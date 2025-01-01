#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> // Pour gerer les entrees utilisateur comme 'o/n'
#include <Windows.h>
using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    //console mise sur le mode utf-8
    //system("chcp 65001"); // Change la console en UTF-8
    // Initialisation du generateur de nombres aleatoires
    srand(static_cast<unsigned int>(time(0)));

    char rejouer;
    do {
        // Nettoyage de la console au debut d'une partie
#ifdef _WIN32
        system("cls"); // Commande pour Windows
#endif
        setColor(10);
        cout << "Bienvenue dans le jeu du 'Devine le nombre' !" << endl;

        // Definir les bornes
        int borneMin = 1, borneMax = 100;
        int nombreSecret = rand() % (borneMax - borneMin + 1) + borneMin; // Genère un nombre entre borneMin et borneMax
        int proposition, essais = 0;
        int points = 0;

        cout << "J'ai choisi un nombre entre " << borneMin << " et " << borneMax << ". A toi de deviner !" << endl;

        do {
            cout << "Entre un nombre : ";
            cin >> proposition;
            essais++;
            if (proposition < nombreSecret) {
                setColor(4);
                cout << "Trop petit !" << endl;
            }
            else if (proposition > nombreSecret) {
                setColor(4);
                cout << "Trop grand !" << endl;
            }
            else {
                //compter les points
                if (essais == 1) {
                    points = essais * 1000;
                }
                else if (essais > 1 and points < 3) {
                    points = essais * 500;
                }
                else if (essais > 3 and essais < 6) {
                    points = essais * 250;
                }
                else {
                    points = essais * 100;
                }
                setColor(10);
                cout << "Bravo ! Tu as trouve le nombre en " << essais << " essais !" << endl;
                cout << "Cela te fait " << points << " points !!" << endl;
            }
        } while (proposition != nombreSecret);

        // Pause après la victoire
#ifdef _WIN32
        system("pause"); // Pause sous Windows
#endif


        // Demander si le joueur veut rejouer
        cout << "Veux-tu rejouer ? (o/n) : ";
        cin >> rejouer;

    } while (rejouer == 'o' || rejouer == 'O' || rejouer == 'y' || rejouer == 'Y');

    cout << "Merci d'avoir joue ! A bientot !" << endl;

    return 0;
}
