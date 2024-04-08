#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 100

int esPalindromo(char cadena[]);
int esLetra(char c);

int main() {
    char cadena[MAX_LONGITUD];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, MAX_LONGITUD, stdin);

    cadena[strcspn(cadena, "\n")] = '\0';

    if (esPalindromo(cadena)) {
        printf("La cadena '%s' es un palindromo.\n", cadena);
    } else {
        printf("La cadena '%s' no es un palindromo.\n", cadena);
    }

    return 0;
}

int esPalindromo(char cadena[]) {
    int longitud = strlen(cadena);
    int i, j;

    for (i = 0; cadena[i]; i++) {
        if (esLetra(cadena[i])) {
            cadena[i] = tolower(cadena[i]);
        }
    }

    for (i = 0, j = longitud - 1; i < j; i++, j--) {
        while (!esLetra(cadena[i]) && i < j) {
            i++;
        }
        while (!esLetra(cadena[j]) && i < j) {
            j--;
        }

        if (cadena[i] != cadena[j]) {
            return 0; 
        }
    }

    return 1; 
}

int esLetra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
