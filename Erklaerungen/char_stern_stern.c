#include <stdio.h>

int main() {
    // Ein Array von Zeichenketten
    char* strings[] = {"Apple", "Banana", "Orange"};

    // Ein Zeiger auf den Anfang des Zeiger-Arrays
    char** pointerArray = strings;

    // Dereferenzierung des Zeigers auf den Anfang des Zeiger-Arrays
    char* firstString = *pointerArray;

    // Dereferenzierung eines Zeigers auf eine Zeichenkette (char*)
    char firstCharacter = *firstString;

    // Ausgabe der Ergebnisse
    printf("Pointer Array: %p\n", (void*)pointerArray);         // Adresse des Zeiger-Arrays
    printf("First String: %s\n", firstString);                   // Inhalt der ersten Zeichenkette
    printf("First Character of First String: %c\n", firstCharacter); // Erstes Zeichen der ersten Zeichenkette

    return 0;
}

// Zeiger auf den Anfang des Zeiger-Arrays (char** pointerArray):

// pointerArray ist ein Zeiger, der auf den Anfang des Zeiger-Arrays strings zeigt.
// Dereferenzierung des Zeigers auf den Anfang des Zeiger-Arrays (char* firstString = *pointerArray):

// firstString wird auf den Anfang der ersten Zeichenkette im Array ("Apple") gesetzt.
// Hier verwenden wir *pointerArray, um den Wert zu erhalten, auf den pointerArray zeigt, was der Anfang der ersten Zeichenkette ist.
// Dereferenzierung eines Zeigers auf eine Zeichenkette (char firstCharacter = *firstString):

// firstCharacter wird auf das erste Zeichen der ersten Zeichenkette ('A') gesetzt.
// Hier verwenden wir *firstString, um den Wert zu erhalten, auf den firstString zeigt, was das erste Zeichen der Zeichenkette ist.


//1. Ein Array von Zeichenketten:
char* strings[] = {"Apple", "Banana", "Orange"};
//2. Ein Zeiger auf den Anfang des Zeiger-Arrays:
char** pointerArray = strings;
//pointerArray ist ein Zeiger auf einen Zeiger auf Zeichen (char**).
//Es wird auf den Anfang des Zeiger-Arrays strings gesetzt.
//3. Dereferenzierung des Zeigers auf den Anfang des Zeiger-Arrays:
char* firstString = *pointerArray;
//firstString ist ein Zeiger auf Zeichen (char*).
//Es wird auf das dereferenziert, worauf pointerArray zeigt, also auf die Adresse der ersten Zeichenkette "Apple".
//4. Dereferenzierung eines Zeigers auf eine Zeichenkette (char):*
char firstCharacter = *firstString;
//firstCharacter ist ein einzelnes Zeichen (char).
//Es wird auf das dereferenziert, worauf firstString zeigt, also auf das erste Zeichen der Zeichenkette "Apple".

// Zusammengefasst:

// strings ist ein Array von Zeigern auf Zeichenketten.
// pointerArray ist ein Zeiger auf den Anfang dieses Zeiger-Arrays.
// firstString ist ein Zeiger auf den Anfang der ersten Zeichenkette im Array.
// firstCharacter ist das erste Zeichen dieser ersten Zeichenkette.
// In diesem Beispiel sind die Datentypen wichtig, um sicherzustellen, dass die Dereferenzierungen korrekt erfolgen und die richtigen Werte erhalten werden.








