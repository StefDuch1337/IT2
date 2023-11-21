#include <stdio.h>

void eingabe(int *n, int *k); 
int binomKoeffizient( int n, int k);

int main()
{
    //Deklaieren der Variablen
    int n = 0;  
    int k = 0;
    int erg = 0;

    eingabe(&n, &k); // Aufruf der Funktion für Eingabe
    erg = binomKoeffizient(n, k);   // Aufruf zur Berechnung des Binomialkoeefizient 

    printf(" /\t%u \\\n",n);
    printf("|\t    |\t = %u\n",erg);
    printf(" \\\t%u /\n",k);

    return 0;
}

void eingabe( int *n, int *k)
{
    printf("Wie viele Positionen: ");
    while (scanf("%d", &*n) != 1 || *n < 0) //Überprüfung der Eingabe + Eingabe
    {
        printf("Falsche Eingabe. Bitte geben Sie diese Zahl erneut ein: ");
        while(getchar() != '\n'){};
    }

    printf("Wie viele Elemente (muss <= %u sein): ", *n); //Überprüfung der Eingabe + Eingabe
    while (scanf("%d", &*k) != 1 || *k < 0 || *k >= *n)
    {
        printf("Falsche Eingabe. Bitte geben Sie eine Zahl <= %d ein: ", *n);
        while(getchar() != '\n'){};
    }
}

 int binomKoeffizient( int n, int k)
{
    int erg;
    if( k == n || k == 0){ //Ist dies erreicht wird 1 zurückgegeben
        return 1;
    }
    else{
    erg = binomKoeffizient(n-1,k) + binomKoeffizient(n-1, k-1); //Aufruf der ersten Rekursion dann aufruf der zweiten Rekursion bis If erreicht, dann Rückgabe. 
    }

    return erg;
}