#include <stdio.h>
#include <string.h>
#define MAX 1001

void eingabe(char *input, int *length);
void bearbeitung(char *inputSatz, char *inputWort, char *inputErsatz);

int main()
{
    char inputSatz[MAX];
    char inputWort[MAX];
    char inputErsatz[MAX];
    int length;
    char jaein = '0';

    printf("Gib einen String ein:\n");
    eingabe(inputSatz, &length); // Aufruf der Funktion für die Eingabe
    
    do
    {
        do
        {
            printf("Welches Wort soll ersetz werden: ");
            eingabe(inputWort, &length);             // Aufruf der Eingabe für den String
        } while (strstr(inputSatz, inputWort) == 0); // Überprüfung ob das Wort überhaupt vorhanden ist

        printf("Durch welches Wort soll ersetz werden: ");
        eingabe(inputErsatz, &length); // Aufruf der Funktion für die Eingabe

        bearbeitung(inputSatz, inputWort, inputErsatz); // Aufruf der Funktion und weiter bearbeitung

        printf("Noch eine Ersetzung (j/n): "); // Abfrage ob nochmal ein Wort ersetzt werden soll
        while (scanf("%c", &jaein) != 1 || (jaein != 'j' && jaein != 'n'))
        {
            printf("Falsche Eingabe. Noch eine Ersetzung (j/n): ");
            while (getchar() != '\n'){};
        }
        while (getchar() != '\n'){};
    } while (jaein == 'j');

    return 0;
}

void eingabe(char *input, int *lenght)
{
    if (fgets(input, MAX, stdin) != 0) // Eingabefeld
    {
        *lenght = strlen(input);
        if (input[*lenght - 1] == '\n') // Löschen des Enterzeichens
            input[*lenght - 1] = '\0';
    }
}

void bearbeitung(char *inputSatz, char *inputWort, char *inputErsatz)
{
    char inputCopy[MAX];               // Ersatz String erstellt
    strcpy(inputCopy, inputSatz);      // Eingabestring in Ersatzstring copiert
    char *token;                       // Token Zeiger erstellen
    char *teiler = " ";                // Teiler mit charakter Leerzeichen erstellt
    strcpy(inputSatz, "\0");           // Eingabestring leeren
    token = strtok(inputCopy, teiler); // Zerteilen des Strings bei Leerzeichen
    while (token != 0)                 // Überprüfung auf 0 , wenn nicht 0 dann gibt es weitere Token
    {
        if ((strcmp(token, inputWort)) != 0)            //Auf Gleicheit überpüfen.
        {
            strncat(inputSatz, token, strlen(token));       //Ungleich -> Hängt Token vom String an
            strcat(inputSatz, " ");
        }
        else // Token ist ein Zeiger der auf den String inputSatz schaut
        {
            strncat(inputSatz, inputErsatz, strlen(inputErsatz));   //Gleichheit er hängt Ersatzwort an
            strcat(inputSatz, " ");
        }
        token = strtok(0, teiler);                  // Suche nach dem nächsten Token. Suche ab 0
    }
    printf("....Neuer String:\n%s\n", inputSatz);   //Ausgabe String
}
