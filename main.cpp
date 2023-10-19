#include <iostream>
#include "BiboGrafik.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int druck = 0;

    // Positionierung von Spieler und Ziel festlegen
    int x = 1, y = 1; // Spieler
    srand(time(NULL));
    int x_ziel = rand() % 10 + 10, y_ziel = rand() % 10 + 10;

    // gehe zu Position vom Ziel
    gotoxy(x_ziel, y_ziel);
    cout << "#";

    // gehe zur Position vom Spieler
    gotoxy(x, y);
    cout << "*";

    // Rahmen
    int begrenzungx = 20;
    int begrenzungy = begrenzungx;
    int begrenzungsindex = 0;
    while (begrenzungsindex <= begrenzungx && begrenzungsindex <= begrenzungy) // Begrenzung
    {

        gotoxy(0, 0);
        cout << char(201);
        gotoxy(begrenzungsindex, 0);
        cout << char(205);
        gotoxy(0, begrenzungsindex);
        cout << char(186);
        gotoxy(begrenzungsindex, begrenzungx);
        cout << char(205);
        gotoxy(begrenzungy, begrenzungsindex);
        cout << char(186);
        gotoxy(begrenzungx, 0);
        cout << char(187);
        gotoxy(0, begrenzungy);
        cout << char(200);
        gotoxy(begrenzungx, begrenzungy);
        cout << char(188);

        begrenzungsindex++;
    }

    const int hindanzahl = 50;
    int hindindex = 0;
    int hindxa[hindanzahl];
    int hindya[hindanzahl];

    // Hinternisse
    while (hindindex < hindanzahl)
    {
        int hindx = rand() % 19 + 1;
        int hindy = rand() % 19 + 1;
        gotoxy(hindx, hindy);
        hindxa[hindindex] = hindx;
        hindya[hindindex] = hindy;

        if ((x_ziel == hindx && y_ziel == hindy) || (hindx == x && hindy == y))
        {
        }
        else
        {
            cout << "X";
            hindindex++;
        }
    }

    // in einer Schleife wiederhole die Eingabe (Tastendruck und
    // Spieler versetzen - solange wir nicht am ziel sind
    // Solange die y-Werte und die y-Werte nicht gleich sind
    while (x != x_ziel || y != y_ziel)
    {
        // Warte auf tastendruck
        int taste = getKey();

        // erst mal den alten Stern l�schen
        gotoxy(x, y);
        cout << " ";

        // Prüfe welche Taste gedr�ckt wurde
        if (taste == 587)
        {
            x--;
            druck++;
        }
        else if (taste == 589)
        {
            x++;
            druck++;
        }
        else if (taste == 584)
        {
            y--;
            druck++;
        }
        else if (taste == 592)
        {
            y++;
            druck++;
        }

        // Grenzen
        if (x < 1)
        {
            x++;
        }
        else if (x > begrenzungx - 1)
        {
            x--;
        }
        else if (y < 1)
        {
            y++;
        }
        else if (y > begrenzungy - 1)
        {
            y--;
        }

        // Hindernisse
        for (int i = 0; i < hindanzahl; i++)
        {
            if (x == hindxa[i] && (y == hindya[i]) && taste == 589)
            {
                x--;
            }
            else if (x == hindxa[i] && (y == hindya[i]) && taste == 587)
            {
                x++;
            }
            else if (x == hindxa[i] && (y == hindya[i]) && taste == 584)
            {
                y++;
            }
            else if (x == hindxa[i] && (y == hindya[i]) && taste == 592)
            {
                y--;
            }
        }

        gotoxy(x, y);
        cout << "*";
    }

    gotoxy(begrenzungx + 10, 5);
    cout << " Sie haben Anschlaege " << druck << " gebraucht.";

    gotoxy(begrenzungx + 10, 6);
    cout << "Druecken Sie eine beliebige Taste zum Beenden...";
    getch ();

    // Ausgaben von Codeblock bei Ende Programm bitte ganz unten in Konsole
    gotoxy(0, 20);
}
