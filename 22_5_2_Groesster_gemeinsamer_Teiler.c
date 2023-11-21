#include <stdio.h>
#define MAX 10

int eingabe(int arrayZahl[], int max); // 
int ggtBerechnung(int n, int m);

int main()
{

    int arrayZahl[MAX];
    int ggt = 0;

    int anzahlZahlen = eingabe(arrayZahl, MAX); // Eingabe der Zahlen

    for (int i = 0; i < anzahlZahlen; i++)
    {
        ggt = ggtBerechnung(ggt, arrayZahl[i]); //Öffnen der Berechnungsfunktion -> Gibt immer den neuen gemeinsamen Teiler ein
    }

    printf("%d", ggt); // Ausgabe

    return 0;
}

int eingabe(int arrayZahl[], int max)
{

    printf("Gib nicht-ngeative ganze Zahlen ein (Ende = 0 / Max 100)\n");
    for (int i = 0; i < max; i++)
    {
        printf("%d. Zahl: ", i + 1); 
        while (scanf("%d", &arrayZahl[i]) != 1 || arrayZahl[i] < 0) //Eingabe und Überrpüfung
        {
            printf("Falsche Eingabe: Bitte gebe eine Zahl ein: "); //Löschen des Enters bei Falscheingabe
            while (getchar() != '\n')
            {
            };
        }
        if (arrayZahl[i] == 0) //Rückgabe bei 0 Eingabe
            return i;
    }

    return 0;
}

int ggtBerechnung(int n, int m)
{
    if (m == 0)     //Rückgabe bei M == 0
    {
        return n;
    }
    else
    {
        return ggtBerechnung(m, n % m); //Geht immer einer Stack runter und wird dann am Ende wieder hoch gegeben
    }
}

//53
//87
//23
//9
