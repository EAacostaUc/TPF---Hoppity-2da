#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "DeclaracionesHoppity.h"
#define N 16

/*
 Inicializamos el tablero, en donde tiene que ir colocados las fichas negras se le asigna "N", fichas blancas "B"
 y casillas vacias "."
 parametors:
 -> tablero tipo char de 16x16
*/
void iniciartablero (char tablero[N][N]) {

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {

			/*
			Condiciones para colocar 'N' en la parte superior izquierda de la matriz en forma triangular.
			*/

			if ((i<=4 && j == 0 && i>=0) || (i<=4 && j == 1 && i>=0) || (i<=3 && j == 2 && i>=0)
										|| (i<=2 && j == 3 && i>=0) || (i<=1 && j == 4 && i>=0)) {
				tablero[i][j] = 'N'; // B        ..                                  // 5
			}

			/*
			Condiciones para colocar 'B' en la parte inferior derecha de la matriz en forma triangular.
			*/

			else if ((i==15 && j>=11) || (i==14 && j>=11) || (i==13 && j>=12) || (i==12 && j>=13) || (i==11 && j>=14)) {
				tablero[i][j] = 'B';   // N                                                           // 10

			}
			else {
				tablero[i][j] = '.';
			}

		}
	}
}

/*
Por el momento la maquina entra aca para seleccionar las filas y columnas
solamente aleatorio
*/
/*void aleatorioMaquina (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1) {

    *fila_actual1 = rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
    *colum_actual1 = rand() % 16;
    *colum_nueva1 = rand() % 16;
    *fila_nueva1 = rand() % 16;

}*/

/*
 Aca se revisa si las filas y columnas elegidas son correctas, sino vuelve a seleccionar
*/
/*void juegaMaquinaB (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[N][N]) {

	while ((tablero [*fila_actual1][*colum_actual1] != 'B') || (tablero [*fila_nueva1][*colum_nueva1] != '.')
	 || (pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2)) > 2)
    {
        *fila_actual1 = rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
        *colum_actual1 = rand() % 16;
        *colum_nueva1 = rand() % 16;
        *fila_nueva1 = rand() % 16;

    }
}
*/

/*void juegaMaquinaN (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[N][N]) {

    while ((tablero [*fila_actual1][*colum_actual1] != 'N') || (tablero [*fila_nueva1][*colum_nueva1] != '.')
    || (pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2)) > 2)   // en el calculo le puse que sea > 8 para que haga tambien los saltos
    {
        *fila_actual1 = rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
        *colum_actual1 = rand() % 16;
        *colum_nueva1 = rand() % 16;
        *fila_nueva1 = rand() % 16;

    }
}
*/

/*
Esto se revisa constantemente, con cada movimiento que se haga.
revisa si las fichas ocupan ya completamente el campamento opuesto
*/
void condicionQuienGana (char tablero[N][N], int *cont, int *bandera5) {

		// revision blancas
	    for (int i = 0; i < 16; i++) {         //Recorremos la matriz
	        for (int j = 0; j < 16; j++) {
	                                            // Revisión del campo de las fichas negras.
	            if (i<=4 && j == 0 && tablero[i][j] == 'B')
	                (*cont)++;
	            if (i<=4 && j == 1 && tablero[i][j] == 'B')
	                (*cont)++;
	            if (i<=3 && j == 2 && tablero[i][j] == 'B')
	                (*cont)++;
	            if (i<=2 && j == 3 && tablero[i][j] == 'B')
	                (*cont)++;
	            if (i<=1 && j == 4 && tablero[i][j] == 'B')
	                (*cont)++;
	        }
	    }
	    if (*cont == 19){
	        *bandera5 = 2; // se le asigna 2 en caso de sea blancas
	    }
	    else {
	        *cont = 0;
	    }

	    // revision negras
	    for (int i = 0; i < 16; i++) {         //Recorremos la matriz
	        for (int j = 0; j < 16; j++) {
	                                            // Revisión del campo de las fichas blancas.
	             if (i==15 && j>=11 && tablero[i][j] == 'N')
	            	 (*cont)++;
	             if (i==14 && j>=11 && tablero[i][j] == 'N')
	            	 (*cont)++;
	             if (i==13 && j>=12 && tablero[i][j] == 'N')
	            	 (*cont)++;
	             if (i==12 && j>=13 && tablero[i][j] == 'N')
	            	 (*cont)++;
	             if (i==11 && j>=14 && tablero[i][j] == 'N')
	            	 (*cont)++;
	        }
	    }
	    if (*cont == 19){
	        *bandera5 = 1; // se le asigna 1 en caso de sea negras
	    }
	    else {
	        *cont = 0;
	    }

}

/*
Despues de seleccionar la ficha a mover (el humano) se revisa la ficha seleccionada acá
revisa si solamente quiere hacer movimiento adyacente o si quieres hacer saltos multiples si es posible.
la primera parte del "if" seria para movimientos adyacentes y el otro "else if" para saltos multiples.

*/
void revisarMovimientosPosibles (int *x1, int *x2, int *z1, int *z2, int *puerta, int *puerta2, int *puerta3,int *bandera, char tablero[N][N]) {

	if ((tablero[*x1][*x2] == 'N' || tablero[*x1][*x2] == 'B') && tablero[*z1][*z2] == '.' && ((pow((*z1 - *x1), 2) + pow((*z2 - *x2), 2)) <= 2) ){
		if (*puerta3 == 1) {
			*puerta = 1;   // aca solamente para movimiento adyacente...
		} else {
			*puerta = 0;
			*bandera = 0; // se le asigna cero, para resolver el caso de que cuando ya realiza tod0 el salto multiple, no recuerde la ficha y mueva de nuevo (el error de no poder seleccionar otra, se queda con el anterior hasta mover)
		}
	}
	else if ((tablero[*x1][*x2] == 'N' || tablero[*x1][*x2] == 'B') && ((tablero[*x1-1][*x2] == 'N' || tablero[*x1-1][*x2] == 'B') || (tablero[*x1+1][*x2] == 'N' || tablero[*x1+1][*x2] == 'B') || (tablero[*x1][*x2-1] == 'N' || tablero[*x1][*x2-1] == 'B') || (tablero[*x1][*x2+1] == 'N' || tablero[*x1][*x2+1] == 'B') || (tablero[*x1-1][*x2-1] == 'N' || tablero[*x1-1][*x2-1] == 'B')
			|| (tablero[*x1-1][*x2+1] == 'N' || tablero[*x1-1][*x2+1] == 'B') || (tablero[*x1+1][*x2-1] == 'N' || tablero[*x1+1][*x2-1] == 'B') || (tablero[*x1+1][*x2+1] == 'N' || tablero[*x1+1][*x2+1] == 'B'))  && tablero[*z1][*z2] == '.' && ((pow((*z1 - *x1), 2) + pow((*z2 - *x2), 2)) > 2) ) {

		*puerta = 1;
		*puerta3 = 0;

	}
	else if (*x1 == *z1 && *x2 == *z2) { // este le agregamos para poder seleccionar y des-seleccionar sin problema las fichas
		*puerta = 1;
	}

}

// funcion peso

/*void Peso (int peso[N][N]){
   // peso[N][N];
    int k=0;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (i>j)//triangular inferior
        		peso[i][j]=78;
	            	else
						peso[i][j]=100;
			            }
			        }

		for (int i = 0; i < 16; i++) {
				k=0;
					for (int j = 0; j < 16; j++) {
						if (i>j)//triangular inferior
							            		k++;
							            	else if (i<j)//triangular superior
							            		peso[i][j]=peso[i][j]-(i+j)+(--k)-2;
							            	else
							            		peso[i][j] = peso[i][j]-(i+j)+20;
			            }
			        }
			        int z=15, h=-1;
		for (int i = 15; i ; i--) {
						k=0; z--; h++;
							for (int j = z; j+1 ; j--) {

								peso[i][j] = peso[i][j] - k+h;
								k=k+2;
					            }
					        }

}*/







