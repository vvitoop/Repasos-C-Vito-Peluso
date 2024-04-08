#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 100

int contarVocales(char cadena[]);
int esVocal(char c);

int main() {
    char cadena[MAX_LONGITUD];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, MAX_LONGITUD, stdin);

    // Eliminar el salto de línea al final de la cadena
    cadena[strcspn(cadena, "\n")] = '\0';

    int cantidadVocales = contarVocales(cadena);
    printf("La cadena '%s' tiene %d vocales.\n", cadena, cantidadVocales);

    return 0;
}

int contarVocales(char cadena[]) {
    int cantidadVocales = 0;
    int longitud = strlen(cadena);
    int i; 

    for (i = 0; cadena[i]; i++) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] = cadena[i] + 32; 
        }
    }

    for (i = 0; i < longitud; i++) {
        if (esVocal(cadena[i])) {
            cantidadVocales++;
        }
    }

    return cantidadVocales;
}

int esVocal(char c) {
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
