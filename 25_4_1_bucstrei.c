#include <stdio.h>
#include <string.h>
#define MAX 1001
#define MAX_ZEICHEN 3

void input(char *eingabe, char *teiler, int *length);

int main()
{
    // Initiallisieren der Variablen
    int length = 0;
    char teiler[MAX_ZEICHEN]; //Teiler auf 3 zeichen , enter und 0
    char eingabe[MAX];
    char *token;

    input(eingabe, teiler, &length);           // Eingabe der Zeichenkette und des Charakters
    char *result = strchr(eingabe, teiler[0]); // Feststellen ob das Zeichen verfügbar wäre
    if (result != 0)
    {
        printf(".........die neue Zeichenkette ist dann:\n");   //Ausgabe
        token = strtok(eingabe, teiler); //Zerteilen des Strings bei teiler, zeichen
        while (token != 0)
        {
            printf("%s", token);
            token = strtok(0, teiler); //Bei Token 0 anfangen. 
        }
    }
    else
    {
        printf("Es gibt dieses Zeichen nicht in der Zeichenkette.");
    }
    return 0;
}

void input(char *eingabe, char *teiler, int *length)
{
    printf("Bitte geben Sie eine Zeichenkette (max.1000 Zeichen ein): ");
    if (fgets(eingabe, MAX, stdin) != 0)
    {
        *length = strlen(eingabe);
        if (eingabe[*length - 1] == '\n')
        {
            eingabe[*length - 1] = '\0'; // oder eingabe[strcspn(eingabe, "\n")] = '\0' Sucht das \n und ersetzt es durch \0
        }
    }
    // while (getchar() != '\n'); //Wenn man mehr als 1000 eingibt dann passiert was? // while ((c = getchar()) != '\n' && c != EOF);
    printf("Geben Sie das zu loeschende Zeichen ein: "); // Eingabe des Charakters
    if (fgets(teiler, MAX_ZEICHEN, stdin) != 0)
    {
        *length = strlen(teiler);
        if (teiler[*length - 1] == '\n')
        {
            teiler[*length - 1] = '\0'; // oder eingabe[strcspn(eingabe, "\n")] = '\0' Sucht das \n und ersetzt es durch \0
        }
    }
}
