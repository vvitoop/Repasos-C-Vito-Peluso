/*1. Pedir al usuario que ingrese su nombre y luego imprimirlo en pantalla.*/

#include <stdio.h>

int main (){
	
	char nombre[50];
	
	printf("Ingrese su nombre:");
	
	scanf("%s", nombre);
	
	printf("Hola %s bienvenido al programa.\n", nombre);
	
	return 0;
	
	
}
