#include <stdio.h>
#include <stdarg.h>

void vielmax(int anzahl, ...);

int main()
{
    //Ausgabe der Überschrift
    printf("Testprogramm fuer Funktion vielmax()\n");
    printf("====================================\n\n");
    //Aufruf der Funktionen 
    vielmax(6, 12, 17, 3, 6, 24, 8);
    vielmax(4, 105, 77, 3, 54);
    return 0;
}

void vielmax(int anzahl, ...) // ... Ellipsen Aufruf mit variablen übergebenen Parametern (Keine defenierter Speicherbereich)
{   
    int maxZahl = 0; 
    va_list sPoint; //Pointer zeigt auf die unbenamten Parameter

    va_start(sPoint, anzahl); // Positionierung des Zeiger mittels int anzahl

    printf("Das Maximum der Zahlen: ");

    for (int i = 0; i < anzahl; i++)
    {
        int ausgabeZahl = va_arg(sPoint, int); // Parameter vom Zeiger wird übergeben. Mit dem nächsten Aufruf zeigt der Zeiger auf den nächsten Parameter
        printf("%d", ausgabeZahl);
        if (i < (anzahl - 1))
        {
            printf(", "); 
        }

        if (maxZahl < ausgabeZahl)
        {
            maxZahl = ausgabeZahl; //Übergabe vom MaxWert
        }
    }
    printf(" ist: %d\n", maxZahl); //Ausgabe vom MaxWert
    va_end(sPoint); //Zeiger/Stack wird bereinigt 
}
