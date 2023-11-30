//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include <math.h>
//#include "DeclaracionesHoppity.h"
//#define N 16
//
//Peso (peso);
//int *PosActual = eleccionFicha (tablero, peso);
//g_print ("\nPosActual: %d,%d\n", *(PosActual+0), *(PosActual+1));
//int *PosNuevo = eleccionCasillaMover (tablero, peso, PosActual);
//
//int *eleccionFicha (char tablero[N][N], int peso[N][N]) {
//	int *posicionActual=malloc(2*sizeof(int));
//	int aux=0;
//	int band = 0;
//	for (int i = 15; i; i--){
//		for (int j = 15; j; j--){
//			if (tablero[i][j] == 'B'){
//
//				if (band == 0){
//					aux = peso[i][j];
//					band = 1;
//
//				}
//				if (aux <= peso[i][j]){
//					aux = peso[i][j];
//					*(posicionActual +0)= i;
//					*(posicionActual +1) = j;
//				}
//
//
//			}
//		}
//
//	}
//	printf ("\n%d,%d\n", *(posicionActual +0), *(posicionActual +1));
//	return posicionActual;
//}
//
//
//
//int *eleccionCasillaMover (char tablero[N][N], int peso[N][N], int PosActual[2]) {
//	int *posicionNueva = malloc(2*sizeof(int));
//
//	int *simple[3];
//	int *saltos[3];
//
//	for (int h = 0; h < 3; h++){
//		if (tablero [*(PosActual +0) - 1][*(PosActual +1)] == '.'){
//			simple[0][0] = *(PosActual +0) - 1;
//			simple[0][1] = *(PosActual +1);
//		}
//
//		else if (tablero [*(PosActual +0) - 1][*(PosActual + 1) - 1] == '.'){
//			simple[1][0] = *(PosActual +0) - 1;
//			simple[1][1] = *(PosActual +1) - 1;
//		}
//
//		else if (tablero [*(PosActual +0)][*(PosActual +1) - 1] == '.') {
//			simple[2][0] = *(PosActual +0);
//			simple[2][2] = *(PosActual +1) - 1;
//		}
//	}
//
//
//
//
//
//
//
//
//
//	return posicionNueva;
//}

