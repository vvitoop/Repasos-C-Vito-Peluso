#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 100

int sonAnagramas(char cadena1[], char cadena2[]);
int esLetra(char c);

int main() {
    char cadena1[MAX_LONGITUD];
    char cadena2[MAX_LONGITUD];

    printf("Ingrese la primera cadena de caracteres: ");
    fgets(cadena1, MAX_LONGITUD, stdin);
    cadena1[strcspn(cadena1, "\n")] = '\0';

    printf("Ingrese la segunda cadena de caracteres: ");
    fgets(cadena2, MAX_LONGITUD, stdin);
    cadena2[strcspn(cadena2, "\n")] = '\0';

    if (sonAnagramas(cadena1, cadena2)) {
        printf("Las cadenas '%s' y '%s' son anagramas.\n", cadena1, cadena2);
    } else {
        printf("Las cadenas '%s' y '%s' no son anagramas.\n", cadena1, cadena2);
    }

    return 0;
}

int sonAnagramas(char cadena1[], char cadena2[]) {
    int longitud1 = strlen(cadena1);
    int longitud2 = strlen(cadena2);

    if (longitud1 != longitud2) {
        return 0;
    }

    int i;
    for (i = 0; cadena1[i]; i++) {
        cadena1[i] = tolower(cadena1[i]);
    }
    for (i = 0; cadena2[i]; i++) {
        cadena2[i] = tolower(cadena2[i]);
    }

    int frecuencias1[26] = {0};
    int frecuencias2[26] = {0};

    for (i = 0; i < longitud1; i++) {
        if (esLetra(cadena1[i])) {
            frecuencias1[cadena1[i] - 'a']++;
        }
    }

    for (i = 0; i < longitud2; i++) {
        if (esLetra(cadena2[i])) {
            frecuencias2[cadena2[i] - 'a']++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (frecuencias1[i] != frecuencias2[i]) {
            return 0;
        }
    }

    return 1;
}

int esLetra(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z');
}
