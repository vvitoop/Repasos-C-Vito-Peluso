#include <stdio.h>
#include <string.h>

int main() {
    char palabras[5][50];
    int i;
    char cadena_mas_larga[50];

    for (i = 0; i < 5; i++) {
        printf("Por favor, ingresa la palabra %d: ", i + 1);
        scanf("%s", palabras[i]);
    }

    strcpy(cadena_mas_larga, palabras[0]);

    for (i = 1; i < 5; i++) {
        if (strlen(palabras[i]) > strlen(cadena_mas_larga)) {
            strcpy(cadena_mas_larga, palabras[i]);
        }
    }

    printf("La cadena mas larga es: %s\n", cadena_mas_larga);

    return 0;
}
