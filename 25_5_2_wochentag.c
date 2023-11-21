#include <stdio.h>
#include <string.h>
#define MAX 11

int pruefDate(int tag, int monat, int jahr, int *schaltjahr) // Aufruf der Funktion , ob das Datum passt.
{
    if (monat > 12 || monat < 1 || jahr < 1 || tag < 1) // Erste Abfrage auf Monat und Jahr
        return 0;

    if (monat > 2)              //Überprüfung auf Schaltjahr
        *schaltjahr = 0;
    else if (jahr % 400 == 0)
        *schaltjahr = 1;
    else if (jahr % 100 == 0)
        *schaltjahr = 0;
    else if (jahr % 4 == 0)
        *schaltjahr = 1;
    else
        *schaltjahr = 0;

    int monat_tage[12] = {31, 28 + *schaltjahr, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Anlegen des Arrays um die Tage der einzelnen Monate zu ermitteln

    return tag <= monat_tage[monat - 1]; // Überprüfung auf Richtige Tages eingabe
}

int main()
{
    int jh_koeff[4] = {4, 2, 0, 5};
    int monat_koeff[12] = {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0};
    char *arrayWochentag[7];
    int tag, monat, jh, ja, jahr, schaltjahr, wochentag;

    arrayWochentag[0] = "Sonntag";
    arrayWochentag[1] = "Montag";
    arrayWochentag[2] = "Dienstag";
    arrayWochentag[3] = "Mittwoch";
    arrayWochentag[4] = "Donnerstag";
    arrayWochentag[5] = "Freitag";
    arrayWochentag[6] = "Samstag";

    printf("Gib Datum ein(tt.mm.jjjj): ");
    while (scanf("%d.%d.%d", &tag, &monat, &jahr) != 3 || pruefDate(tag, monat, jahr, &schaltjahr)!= 1) // Eingabe und direkte überprüfung
    {
        printf("Falsche Eingabe. Bitte erneut eingeben: ");
        while (getchar() != '\n');
    }

    jh = jahr / 100;                                                                              // Aufteilen auf linke Zahl
    ja = jahr % 100;                                                                              // Aufteilen auf Rechte Zahl
    wochentag = (tag + monat_koeff[monat - 1] - schaltjahr + jh_koeff[jh % 4] + ja + ja / 4) % 7; // Berechnung aus Pseudocode
    printf("Das Datum %0d.%0d.%d ist ein %s", tag, monat, jahr, arrayWochentag[wochentag]);       // Ausgabe

    return 0;
}

/*
1 Januar = 31
2 Februar = 28 oder Schalt 29
3 März = 31
4 April = 30
5 Mai 31
6 Juni 30
7 Juli 31
8 August 31
9 September 30
10 Oktober 31
11 November 30
12 Dezember 31

int pruefSchaltjahr(int monat, int jahr) // Aufruf laut Pseudocode zum ermitteln eob Schaltjahr
{
    int schaltjahr = 0;
    if (monat > 2)
        schaltjahr = 0;
    else if (jahr % 400 == 0)
        schaltjahr = 1;
    else if (jahr % 100 == 0)
        schaltjahr = 0;
    else if (jahr % 4 == 0)
        schaltjahr = 1;
    else
        schaltjahr = 0;

    return schaltjahr; // Rückgabe ob Schaltjahr oder nicht
}


*/