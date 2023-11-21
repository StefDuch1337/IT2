#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000

void beschreiben(int array[], int max, int *laenge);
int pruefen(int array[], int *laenge);

int main()
{
    int array[MAX];
    int erg = 0;
    int laenge = 0;

    // Array mit 0 & 1 beschreiben
    beschreiben(array, MAX, &laenge);

    for (int i = 0; i < laenge; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
    // Aufrufen der Funktion
    erg = pruefen(array, &laenge);
    printf("%d\n", erg);
    return 0;
}

void beschreiben(int array[], int max, int *laenge)
{
    srand(time(0));
    // Eingabe + Ueberpruefung
    printf("Laenge der 0/1-Folge (max. 1000): ");
    while (scanf("%d", &*laenge) != 1 || *laenge > 1000 || *laenge < 1)
    {
        printf("Falsche Eingabe. Bitte erneut eingeben: ");
        while (getchar() != '\n'){}
    }
    // Beschreiben des Arrays
    for (int i = 0; i < *laenge; i++)
    {
        array[i] = rand() % 2;
    }
}

int pruefen(int array[], int *laenge)
{
    int laengeHilf = 0;
    int arrayHilf[(*laenge / 2)+1]; // Bei ungerade wird die Kommzahl abgeschnitten (gewollt)

    for (int i = 0; i < (*laenge - 1); i += 2) // Schleife zum überprüfung der nebenstehenden Zahlen
    {
        if (array[i] == array[i + 1])
            arrayHilf[laengeHilf] = 0;
        else
            arrayHilf[laengeHilf] = 1;

        laengeHilf++; // erhöhen der Var zum beschreiben des Arrays
    }

    if (*laenge % 2 == 1) // Überprüfung auf ungerade damit das letzte Bit ohne partner rübergezogen wird
    {
        arrayHilf[laengeHilf] = array[*laenge - 1];
        laengeHilf++;
    }
    if (laengeHilf > 1)
    {
        for (int j = 0; j < (laengeHilf); j++)
        {
            printf("%d", arrayHilf[j]); // Ausgabe der neuen Zahlen
            array[j] = arrayHilf[j];    // Überschreiben auf den "richtigen Array"
        }
        printf("\n");
    }
    *laenge = laengeHilf; // Neue länge des Arrays übergeben

    if (*laenge == 1)
        return array[0];
    else
        return pruefen(array, laenge); // Rekursion starten
}
// 1 Bsp
// 5-1 = 4
// 0 1 2 3 <4
// start bei i = 0 -> 0 & 1
//	i = 2 -> 2 & 3

// 2 Bsp
// 4 - 1 = 3
//<3
// start bei i = 0 -> 0 & 1
//	i = 2 -> 2 & 3
//	i = 4 ende