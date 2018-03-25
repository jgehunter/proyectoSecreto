/* 
*	FICHERO: main.c
*	AUTORES: Jorge Hunter	Iñaki Echevarría	José Miguel Hervás
*
*	El programa permite al usuario elegir el numero de elementos de una tabla,
*	la ordenacion previa de la tabla y el algoritmo que se quiere utilizar para
*	ordenarla y devuelve al usuario el valor en microsegundos del tiempo que
*	tarda el algoritmo elegido en ordenar la tabla elegida.
*
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TABLA 1000000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "main.h"
#include "algoritmos.h"
#include "measureTime.h"


int main()
{
	long tamTabla;				// Tamaño de la tabla.
	long ordTabla;				// Tipo de ordenación de la tabla.
	long tipAlg;				// Tipo de algoritmo de ordenación.
	long long micros;			// Tiempor que tarda en microsegundos.
	struct lista *tabla;		// Tabla a ordenar.
	char input[256];			// Lectura del input del usuario.
	char *tmp;					

	// Se pide al usuario que introduzca el tamaño de la tabla, que debe ser
	// un entero mayor que 0 y menor MAX_TABLA.
	do {
		printf("Selecciona el numero de elementos de la tabla: ");
		fgets(input, sizeof(input), stdin);
		tamTabla = strtol(input, &tmp, 10);
		memset(input, 0, sizeof(input));
	} while ((tamTabla <= 0) || (tamTabla > MAX_TABLA));

	// Se pide al usuario que introduzca como quiere que esté preordenada la
	// tabla: ordenada de menor a mayor, ordenada de mayor a menor o de forma
	// aleatoria.
	do {
		printf("Selecciona la ordenacion de la tabla: \n 1.Ordenada");
		printf(" \n 2.Inversa \n 3.Aleatoria \n");
		fgets(input, sizeof(input), stdin);
		ordTabla = strtol(input, &tmp, 10);
		memset(input, 0, sizeof(input));
	} while ((ordTabla != 1) && (ordTabla != 2) && (ordTabla != 3));

	// Se pide al usuario que introduzca el algoritmo que quiere utilizar
	// para ordenar la tabla.
	do {
		printf("Selecciona el algoritmo: \n 1.Burbuja \n 2.Insercion \n");
		printf("3.Seleccion \n 4.Shell \n 5.Monticulo \n 6.Quicksort \n");
		fgets(input, sizeof(input), stdin);
		tipAlg = strtol(input, &tmp, 10);
		memset(input, 0, sizeof(input));
	} while ((tipAlg != 1) && (tipAlg != 2) && (tipAlg != 3) &&
			(tipAlg != 4) && (tipAlg != 5) && (tipAlg != 6));
    
    printf("Seleccionado: elementos = %d, tabla = %d, algoritmo = %d \n",
	tamTabla, ordTabla, tipAlg);

	tabla = malloc(tamTabla * sizeof(struct lista)); 
	crearTabla(tabla, ordTabla, tamTabla);
	startTimer();
	ordenarTabla(tabla, tamTabla, tipAlg);
	micros = getTime();
	printf("Ha tardado %lld microsegundos\n", micros);
	free(tabla);
	
	return 0;
}

