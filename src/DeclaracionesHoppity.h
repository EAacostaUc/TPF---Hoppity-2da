/*
 * DeclaracionesHoppity.h
 *
 *  Created on: 24 nov. 2023
 *      Author: erison
 */
#define N 16
//int cont = 0, bandera5 = 0;

#ifndef DECLARACIONESHOPPITY_H_
#define DECLARACIONESHOPPITY_H_

void iniciartablero (char tablero[N][N]);
//void aleatorioMaquina (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1);
//void juegaMaquinaB (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[N][N]);

void solucionMov2fichas ();
void juegaMaquinaIA (char tablero[N][N], int *fila_actualM, int *colum_actualM, int *fila_nuevaM, int *colum_nuevaM, int *FichaColor);

//void juegaMaquinaN (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[N][N]);
void condicionQuienGana (char tablero[N][N], int *cont, int *bandera5);
void revisarMovimientosPosibles (int *x1, int *x2, int *z1, int *z2, int *puerta, int *puerta2, int *puerta3, int *bandera, char tablero[N][N]);
//void Peso (int peso[N][N]);
//int *eleccionFicha (char tablero[N][N], int peso[N][N]);
//int *eleccionCasillaMover (char tablero[N][N], int peso[N][N], int PosActual[2]);


// int *z1, int *z2,
#endif /* DECLARACIONESHOPPITY_H_ */
