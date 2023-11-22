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