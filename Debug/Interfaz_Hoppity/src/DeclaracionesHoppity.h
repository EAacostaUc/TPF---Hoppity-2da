/*
 * DeclaracionesHoppity.h
 *
 *  Created on: 24 nov. 2023
 *      Author: erison
 */
#define N 16

#ifndef DECLARACIONESHOPPITY_H_
#define DECLARACIONESHOPPITY_H_
// para estadisticas
typedef struct {
    char nombre[50];
    int partidas_jugadas;
    int partidas_ganadas;
    int partidas_perdidas;
} Jugador;


void iniciartablero (char tablero[N][N]);
void solucionMov2fichas ();
void juegaMaquinaIA (char tablero[N][N], int *fila_actualM, int *colum_actualM, int *fila_nuevaM, int *colum_nuevaM, int *FichaColor, int *reinicio, int *aux2);
void condicionQuienGana (char tablero[N][N], int *cont, int *bandera5);
void revisarMovimientosPosibles (int *x1, int *x2, int *z1, int *z2, int *puerta, int *puerta2, int *puerta3, int *bandera, char tablero[N][N]);

int compararJugadores(const void *a, const void *b);
void actualizarEstadisticas(const char *nombre, int *jugadas, int *ganadas, int *perdidas);
//void Peso (int peso[N][N]);
//int *eleccionFicha (char tablero[N][N], int peso[N][N]);
//int *eleccionCasillaMover (char tablero[N][N], int peso[N][N], int PosActual[2]);


#endif /* DECLARACIONESHOPPITY_H_ */
