#include <stdio.h>
#include <string.h>
#define MAXI 13
#define MAXZAHL 11

int main()
{
    char *arrayZahl[MAXZAHL];
    char *input[MAXI];
    int summe = 0;
    //Anlegen vom Zeiger aufs Array, zum Speichenr der Strings
    arrayZahl[0] = "eins";
    arrayZahl[1] = "zwei";
    arrayZahl[2] = "drei";
    arrayZahl[3] = "vier";
    arrayZahl[4] = "fuenf";
    arrayZahl[5] = "sechs";
    arrayZahl[6] = "sieben";
    arrayZahl[7] = "acht";
    arrayZahl[8] = "neun";
    arrayZahl[9] = "zehn";
    arrayZahl[10] = "elf";
    //Eingabe hat nicht funktiioniert
    input[0] = "Endreim";
    input[1] = "Kurzweil";
    input[2] = "Nachtfalter";
    input[3] = "Wohnviertel";
    input[4] = "Neunauge";
    input[5] = "Weinstein";
    input[6] = "Erdreich";
    input[7] = "Achtung";
    input[8] = "Segelflieger";
    input[9] = "Pfalzwein";
    input[10] = "Radreifen";
    input[11] = "Gehhelfer";
    input[12] = "Leinsamen";

    for (int i = 0; i < 13; i++)
    {
        for (int k = 0; k < 11; k++)
        {
            if (strncasecmp(input[i], arrayZahl[k],strlen(arrayZahl[k])) == 0) //Erste überprüfung ob der String am Anfang vom String steht. Auf Großschreibung.
            {
                summe += (k + 1);
                printf("%15s: ...\t%5s ... \t%+5d\n", input[i], arrayZahl[k], k + 1); // Ausgabe
                break;
            }
            else
            {
                char *ergebnis = strstr(input[i], arrayZahl[k]); //Überprüfung ob der string im String vorkommt. keine Großschreibungsüberrpüfung.
                if (ergebnis != 0)
                {
                    summe += (k + 1);
                    printf("%15s: ...\t%5s ... \t%+5d\n", input[i], arrayZahl[k], k + 1); //Ausgabe
                    break;
                }
            }
        }
    }
    printf("--------------------------------------------------\n"); //Ausgabe aufs Ergebnis
    printf("\t\t%+29d", summe);

    return 0;
}

/*  Funktioniert nicht Frage. 
    do
    {
        int lenght
        char jaein;
        int anzahlStrings = 0;
        printf("Bitte gebe ein Zahlenwort ein: ");
        if (fgets(input[anzahlStrings], MAX, stdin) != 0) // Eingabefeld
        {
            lenght = strlen(input[anzahlStrings]);
            if (input[anzahlStrings][lenght - 1] == '\n') // Löschen des Enterzeichens
                input[anzahlStrings][lenght - 1] = '\0';
        }
        anzahlStrings += 1;

        printf("Moechtest du noch ein Zahlenwort eingeben [j/n:] ");
        while (scanf("%c", &jaein) != 1 || (jaein != 'j' && jaein != 'n'))
        {
            printf("Falsche Eingabe. Noch ein Zahlenwort(j/n): ");
            while (getchar() != '\n'){};
        }
        while (getchar() != '\n'){};
    } while (jaein == 'j');

*/