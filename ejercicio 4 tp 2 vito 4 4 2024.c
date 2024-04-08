#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 100

int main() {
    char cadena[MAX_LONGITUD];
    char caracterBuscar, caracterReemplazar;

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, MAX_LONGITUD, stdin);

    printf("Ingrese el caracter a buscar: ");
    scanf(" %c", &caracterBuscar);

    printf("Ingrese el caracter de reemplazo: ");
    scanf(" %c", &caracterReemplazar);

    printf("Cadena original: %s", cadena);

    int i;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == caracterBuscar) {
            cadena[i] = caracterReemplazar;
        }
    }

    printf("Cadena modificada: %s", cadena);

    return 0;
}
