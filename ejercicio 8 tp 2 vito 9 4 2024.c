/*8. Realizar un programa en el cual el usuario primero ingrese una oración
la cual puede estar en mayúscula o minúscula o de manera alternada
y luego pueda seleccionar que realice las siguientes acciones
a) Mostrar la oración toda en mayúscula
b) Mostrar la oración todo en minúsculas
c) Mostrar la oración alternando una mayúscula y una minúscula
D) Mostrar la oración comenzando todas las palabras con mayúscula*/


#include <stdio.h>
#include <string.h>

void transformar_oracion(char oracion[], char opcion) {
    int i;
    switch (opcion) {
        case 'a':
            for (i = 0; oracion[i]; i++) {
                if (oracion[i] >= 'a' && oracion[i] <= 'z') {
                    oracion[i] -= 32;
                }
            }
            break;
        case 'b':
            for (i = 0; oracion[i]; i++) {
                if (oracion[i] >= 'A' && oracion[i] <= 'Z') {
                    oracion[i] += 32;
                }
            }
            break;
        case 'c':
            for (i = 0; oracion[i]; i++) {
                if (oracion[i] >= 'a' && oracion[i] <= 'z') {
                    oracion[i] = (i % 2 == 0) ? oracion[i] - 32 : oracion[i];
                } else if (oracion[i] >= 'A' && oracion[i] <= 'Z') {
                    oracion[i] = (i % 2 != 0) ? oracion[i] + 32 : oracion[i];
                }
            }
            break;
        case 'd':
            oracion[0] = (oracion[0] >= 'a' && oracion[0] <= 'z') ? oracion[0] - 32 : oracion[0];
            for (i = 1; oracion[i]; i++) {
                if (oracion[i] >= 'a' && oracion[i] <= 'z') {
                    if (!(oracion[i - 1] >= 'a' && oracion[i - 1] <= 'z') && !(oracion[i - 1] >= 'A' && oracion[i - 1] <= 'Z')) {
                        oracion[i] -= 32;
                    }
                } else if (oracion[i] >= 'A' && oracion[i] <= 'Z') {
                    if ((oracion[i - 1] >= 'a' && oracion[i - 1] <= 'z') || (oracion[i - 1] >= 'A' && oracion[i - 1] <= 'Z')) {
                        oracion[i] += 32;
                    }
                }
            }
            break;
        default:
            printf("Opcion invalida\n");
    }
}

int main() {
    char oracion[1000];
    char opcion;

    printf("Ingrese una oracion: ");
    fgets(oracion, sizeof(oracion), stdin);
    oracion[strcspn(oracion, "\n")] = '\0'; 

    printf("Seleccione una opcion:\n");
    printf("a) Mostrar la oracion toda en mayuscula\n");
    printf("b) Mostrar la oracion toda en minuscula\n");
    printf("c) Mostrar la oracion alternando una mayuscula y una minuscula\n");
    printf("d) Mostrar la oracion comenzando todas las palabras con mayuscula\n");
    printf("Opcion: ");
    scanf(" %c", &opcion);

    transformar_oracion(oracion, opcion);
    printf("La oracion transformada es: %s\n", oracion);

    return 0;
}
