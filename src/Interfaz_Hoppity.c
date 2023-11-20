

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
//#include "Inteligencia_hoppity.h"

#define N 16

#define FICHA_NEGRO "IMG/bola-negra.png"

#define FICHA_BLANCO "IMG/bola-blanca.png"

#define CASILLA_VACIO "IMG/vacio.png"

#define FICHA_NEGRA_CLICK "IMG/bola-negra-click.png"

#define FICHA_BLANCA_CLICK "IMG/bola-blanca-click.png"

//hola
GtkWidget *ventana;
GtkWidget *ventana1;
GtkWidget *ventana2;
GtkWidget *ventana3;
GtkWidget *ventana4;
GtkWidget *ventana5;
GtkWidget *ventana6;
GtkWidget *ventana7;
GtkWidget *tablero_hoppity;
GtkWidget *eventbox_tablero;
GtkWidget *box1_tablero;
GtkWidget *box2_tablero;
GtkWidget *box3_tablero;
GtkWidget *fixed_tablero;
GtkWidget *grid_tablero;
GtkWidget *box4_tablero;
GtkWidget *fixed;

GtkWidget *boton[16][16];

GtkWidget *boton_bienvenida_salir;
GtkWidget *boton_bienvenida_jugar;
GtkWidget *boton_bienvenida_credito;
GtkWidget *boton_inicio_elegir;
GtkWidget *boton_listo;
GtkWidget *boton_inicio_atras;
GtkWidget *boton_elegir_atras;
GtkWidget *boton_cerrar_credito;
GtkWidget *boton_modo1;
GtkWidget *boton_modo_atras;
GtkWidget *boton_ayuda_tablero;
GtkWidget *boton_cerrar_tablero;
GtkWidget *boton_ayuda_cerrar;
GtkWidget *boton_atras_tablero;
GtkWidget *boton_inicio_aleatorio;
GtkWidget *boton_aleatorio_listo;
GtkWidget *boton_ventana6_listo;
GtkWidget *boton_humano;
GtkWidget *boton_computadora;
GtkWidget *boton_aleatorio1;
GtkWidget *boton_blanca;
GtkWidget *boton_negra;
GtkWidget *boton_aleatorio2;
GtkWidget *boton_credito;
GtkWidget *boton_inicia_compu;

// Del tablero nuevo (por imagenes)
GtkWidget *boton_tablero_atras;
GtkWidget *boton_tablero_ayuda;
GtkWidget *boton_tablero_cerrar;
GtkWidget *jugador_fichanegra;
GtkWidget *jugador_fichablanca;
GtkWidget *turno_jugador;



GtkWidget *entry_jugador1;
GtkWidget *entry_jugador2;
GtkWidget *entry_aleatorio_jugador1;
GtkWidget *entry_aleatorio_jugador2;
GtkWidget *nombre_jugador_negro;
GtkWidget *nombre_jugador_blanco;
GtkWidget *label_modo_juego;
GtkWidget *label_turno;
GtkWidget *label_color;
GtkWidget *label_turno_actual;
GtkWidget *nombre_ganador;
GtkWidget *label_movInvalido;

gchar stringJugador1[30];
gchar stringJugador2[30];

gchar stringJugador_aleatorio1[30];
gchar stringJugador_aleatorio2[30];

GtkWidget *boton_seleccionado;
GtkWidget *boton_vacio;


char tablero[N][N];
// de la maquina...
int fila_actual1=0, fila_actual2=0, fila_actual3=0, fila_actual4=0, fila_actual5=0, fila_actual6=0, fila_actual7=0, fila_actual8=0, fila_actual9=0, fila_actual10=0, fila_actual11=0, fila_actual12=0, fila_actual13=0, fila_actual14=0, fila_actual15=0, fila_actual16=0, fila_actual17=0, fila_actual18=0, fila_actual19=0;
int colum_actual1=0, colum_actual2=0, colum_actual3=0, colum_actual4=0, colum_actual5=0, colum_actual6=0, colum_actual7=0, colum_actual8=0, colum_actual9=0, colum_actual10=0, colum_actual11=0, colum_actual12=0, colum_actual13=0, colum_actual14=0, colum_actual15=0, colum_actual16=0, colum_actual17=0, colum_actual18=0, colum_actual19=0;
int fila_nueva1=0, fila_nueva2=0, fila_nueva3=0, fila_nueva4=0, fila_nueva5=0, fila_nueva6=0, fila_nueva7=0, fila_nueva8=0, fila_nueva9=0, fila_nueva10=0, fila_nueva11=0, fila_nueva12=0, fila_nueva13=0, fila_nueva14=0, fila_nueva15=0, fila_nueva16=0, fila_nueva17=0, fila_nueva18=0, fila_nueva19=0;
int colum_nueva1=0, colum_nueva2=0, colum_nueva3=0, colum_nueva4=0, colum_nueva5=0, colum_nueva6=0, colum_nueva7=0, colum_nueva8=0, colum_nueva9=0, colum_nueva10=0, colum_nueva11=0, colum_nueva12=0, colum_nueva13=0, colum_nueva14=0, colum_nueva15=0, colum_nueva16=0, colum_nueva17=0, colum_nueva18=0, colum_nueva19=0;

GtkWidget *imagenes[16][16];

guint i,j;
guint x,y;
int x1 = 0, x2 = 0, z1 = 0, z2 = 0;

int Turno = 0, Color = 0, bandera = 0, turnoJugada = 1, bandera2 = 0, bandera3 = 0, bandera4 = 1, turno1 = 0, turno2 = 2, cont = 0, bandera5 = 0, bandera6 = 0;
int turno=0;
int iniciar1=0, fichaBlanca=0, iniciar2=0, iniciar3=0, iniciar4=0, iniciar5=0, iniciar6=0, iniciar7=0, iniciar8=0, iniciar9=0, iniciar10=0, iniciar11=0
,iniciar12=0, iniciar13=0, iniciar14=0, iniciar15=0, iniciar16=0, iniciar17=0, iniciar18=0, iniciar19=0;

int b1=1, b2=1, b3=1, b4=1, b5=1, b6=1, b7=1, b8=1, b9=1, b10=1, b11=1, b12=1, b13=1, b14=1, b15=1, b16=1, b17=1, b18=1, b19=1; // contadores de pasos
int p = 0, q = 0, q1=0, q2=0, q3=0, q4=0, q5=0, q6=0, q7=0, q8=0, q9=0, q10=0, q11=0, q12=0, q13=0, q14=0, q15=0, q16=0,q17=0, q18=0;
int p1=0, p2=0, p3=0, p4=0, p5=0, p6=0, p7=0, p8=0, p9=0, p10=0, p11=0, p12=0, p13=0, p14=0, p15=0, p16=0, p17=0, p18=0, p19=0;

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
				tablero[i][j] = 'N'; // B                                          // 5

			}

			/*
			Condiciones para colocar 'B' en la parte inferior derecha de la matriz en forma triangular.
			*/

			else if ((i==15 && j>=11) || (i==14 && j>=11) || (i==13 && j>=12) || (i==12 && j>=13) || (i==11 && j>=14)) {
				tablero[i][j] = 'B';                                                                  // 10

			}
			else {
				tablero[i][j] = '.';
			}

		}
	}
}
/*
Esta funcion es para cargar las fichas (imagenes de las fichas), cada ficha en su respectivo lugar.
parametros:
-> tablero tipo char de 16x16
*/
void cargarimagenes (char tablero[N][N]) {
	int i, j;
	for (i = 0; i < 16; i++){

		for (j = 0; j < 16; j++){

			if(tablero[i][j] == 'B'){

				imagenes[i][j] = gtk_image_new_from_file(FICHA_BLANCO); // al tipo GtkWidget le asignamos las blancas, en las coordenadas ya asignada antes
				gtk_grid_attach(GTK_GRID(grid_tablero),imagenes[i][j],j,i,1,1);

			}

			else if(tablero[i][j] == 'N'){

				imagenes[i][j] = gtk_image_new_from_file(FICHA_NEGRO);
				gtk_grid_attach(GTK_GRID(grid_tablero),imagenes[i][j],j,i,1,1);

			}

			else{

				imagenes[i][j] = gtk_image_new_from_file(CASILLA_VACIO);
				gtk_grid_attach(GTK_GRID(grid_tablero),imagenes[i][j],j,i,1,1);

			}

		}

	}
}
/*
Aca se actualiza el tablero cada vez que se haga un movimiento, ya sea por parte del humano o maquina
*/
void actualizacionDeTablero () {
	int i, j;
	for (i = 0; i < 16; i++){

		for (j = 0; j < 16; j++){

			if(tablero[i][j] == '.'){

				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), CASILLA_VACIO);

			}
			else if(tablero[i][j] == 'B'){

				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_BLANCO);

			}
			else if(tablero[i][j] == 'N'){

				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_NEGRO);

			}

		}

	}
}
/*
Este se encarga de revisar si los pasos que ha dado la ficha, sea igual a la cantidad de pasos que puede dar durante todo su recorrido
, este soluciona el problema de que al llegar una ficha al campamento opuesto (lugar en donde ya se tiene que quedar) no se mueva
otra ficha al mismo tiempo, para evitar que se muevan 2 fichas a la vez (esto daria ventaja a la maquina)
*/
void solucionMov2fichas () {
	if (b1 == 12) {q=1;}
	if (b2 == 12) {q1=1;}
	if (b3 == 13) {q2=1;}
	if (b4 == 13) {q3=1;}
	if (b5 == 14) {q4=1;}
	if (b6 == 13) {q5=1;}
	if (b7 == 13) {q6=1;}
	if (b8 == 12) {q7=1;}
	if (b9 == 12) {q8=1;}
	if (b10 == 12) {q9=1;}
	if (b11 == 13) {q10=1;}
	if (b12 == 13) {q11=1;}
	if (b13 == 14) {q12=1;}
	if (b14 == 13) {q13=1;}
	if (b15 == 13) {q14=1;}
	if (b16 == 12) {q15=1;}
	if (b17 == 13) {q16=1;}
	if (b18 == 14) {q17=1;}
}

// casi 800 lineas, "intento" de IA para mover blancas
void juegaMaquinaIABlancas (char tablero[N][N]) {
	// movimiento, primera ficha
	if (b1 <= 11) {
		if (iniciar1 == 0) {
			fila_actual1 = 11;
			colum_actual1 = 14;
		} else {
			fila_actual1 = fila_nueva1;
			colum_actual1 = colum_nueva1;
		}

		if (tablero[fila_actual1][colum_actual1] == 'B' && tablero[fila_actual1 - 1][colum_actual1 - 1] != 'N') {

			fila_nueva1 = fila_actual1 - 1;
			colum_nueva1 = colum_actual1 - 1;

			iniciar1 = 1;
			b1++;
			p = 0;

			tablero[fila_nueva1][colum_nueva1] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual1][colum_actual1] = '.';

		} else if (tablero[fila_actual1][colum_actual1] == 'B' && tablero[fila_actual1 - 1][colum_actual1 - 1] == 'N' && tablero[fila_actual1 - 2][colum_actual1 - 2] == '.') {

			fila_nueva1 = fila_actual1 - 2;
			colum_nueva1 = colum_actual1 - 2;

			iniciar1 = 1;
			b1++;
			b1++;
			p = 0;

			tablero[fila_nueva1][colum_nueva1] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual1][colum_actual1] = '.';

		}else {
			p = 1;  // banderas, para ir intercalando movimientos en caso de que encuentre dos fichas en la diagonal (no podra saltar)
		}

	}
	// movimiento, segunda ficha
	if ((b1 == 12 && b2 <= 11 && q == 1) || (p == 1 && p2 == 0)) { // (p == 1 && p2 == 0) esta parte se usa cuando hay dos fichas en frente
		if (iniciar2 == 0) {
			fila_actual2 = 11;
			colum_actual2 = 15;
		} else {
			fila_actual2 = fila_nueva2;
			colum_actual2 = colum_nueva2;
		}

		if (tablero[fila_actual2][colum_actual2] == 'B' && tablero[fila_actual2 - 1][colum_actual2 - 1] != 'N') {

			fila_nueva2 = fila_actual2 - 1;
			colum_nueva2 = colum_actual2 - 1;

			iniciar2 = 1;
			b2++;
			p = 0;

			tablero[fila_nueva2][colum_nueva2] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual2][colum_actual2] = '.';

		} else if (tablero[fila_actual2][colum_actual2] == 'B' && tablero[fila_actual2 - 1][colum_actual2 - 1] == 'N' && tablero[fila_actual2 - 2][colum_actual2 - 2] == '.') {

			fila_nueva2 = fila_actual2 - 2;
			colum_nueva2 = colum_actual2 - 2;

			iniciar2 = 1;
			b2++;
			b2++;
			p = 0;

			tablero[fila_nueva2][colum_nueva2] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual2][colum_actual2] = '.';
		}else {
			p = 1;
		}
		if (b2 > 11){p2 = 1;} // para que no vuelva a revisar esto (porque cuando llega al lugar en donde se tiene que quedar volvia a mover la ficha hanciendola desaparecer)
	}
	// movimiento, tercera ficha
	if ((b2 == 12 && b3 <= 12 && q1 == 1) || (p == 1 && p3 == 0)) {
		if (iniciar3 == 0) {
			fila_actual3 = 12;
			colum_actual3 = 14;
		} else {
			fila_actual3 = fila_nueva3;
			colum_actual3 = colum_nueva3;
		}

		if (tablero[fila_actual3][colum_actual3] == 'B' && tablero[fila_actual3 - 1][colum_actual3 - 1] != 'N') {

			fila_nueva3 = fila_actual3 - 1;
			colum_nueva3 = colum_actual3 - 1;

			iniciar3 = 1;
			b3++;
			p = 0;

			tablero[fila_nueva3][colum_nueva3] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual3][colum_actual3] = '.';

		} else if (tablero[fila_actual3][colum_actual3] == 'B' && tablero[fila_actual3 - 1][colum_actual3 - 1] == 'N' && tablero[fila_actual3 - 2][colum_actual3 - 2] == '.') {

			fila_nueva3 = fila_actual3 - 2;
			colum_nueva3 = colum_actual3 - 2;

			iniciar3 = 1;
			b3++;
			b3++;
			p = 0;

			tablero[fila_nueva3][colum_nueva3] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual3][colum_actual3] = '.';

		}else {
			p = 1;
		} if (b3 > 12){p3 = 1;}

	}
	// movimiento, cuarta ficha
	if ((b3 == 13 && b4 <= 12 && q2 == 1) || (p == 1 && p4 == 0)) {
		if (iniciar4 == 0) {
			fila_actual4 = 12;
			colum_actual4 = 13;
		}else {
			fila_actual4 = fila_nueva4;
			colum_actual4 = colum_nueva4;
		}

		if (tablero[fila_actual4][colum_actual4] == 'B' && tablero[fila_actual4 - 1][colum_actual4 - 1] != 'N') {

			fila_nueva4 = fila_actual4 - 1;
			colum_nueva4 = colum_actual4 - 1;

			iniciar4 = 1;
			b4++;
			p = 0;

			tablero[fila_nueva4][colum_nueva4] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual4][colum_actual4] = '.';

		} else if (tablero[fila_actual4][colum_actual4] == 'B' && tablero[fila_actual4 - 1][colum_actual4 - 1] == 'N' && tablero[fila_actual4 - 2][colum_actual4 - 2] == '.') {

			fila_nueva4 = fila_actual4 - 2;
			colum_nueva4 = colum_actual4 - 2;

			iniciar4 = 1;
			b4++;
			b4++;
			p = 0;

			tablero[fila_nueva4][colum_nueva4] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual4][colum_actual4] = '.';

		}else {
			p = 1;
		} if (b4 > 12){p4 = 1;}

	}
	// movimiento, quinta ficha
	if ((b4 == 13 && b5 <= 13 && q3 == 1) || (p == 1 && p5 == 0)) {
		if (iniciar5 == 0) {
			fila_actual5 = 13;
			colum_actual5 = 13;
		}else {
			fila_actual5 = fila_nueva5;
			colum_actual5 = colum_nueva5;
		}

		if (tablero[fila_actual5][colum_actual5] == 'B' && tablero[fila_actual5 - 1][colum_actual5 - 1] != 'N') {

			fila_nueva5 = fila_actual5 - 1;
			colum_nueva5 = colum_actual5 - 1;

			iniciar5 = 1;
			b5++;
			p = 0;

			tablero[fila_nueva5][colum_nueva5] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual5][colum_actual5] = '.';

		} else if (tablero[fila_actual5][colum_actual5] == 'B' && tablero[fila_actual5 - 1][colum_actual5 - 1] == 'N' && tablero[fila_actual5 - 2][colum_actual5 - 2] == '.') {

			fila_nueva5 = fila_actual5 - 2;
			colum_nueva5 = colum_actual5 - 2;

			iniciar5 = 1;
			b5++;
			b5++;
			p = 0;

			tablero[fila_nueva5][colum_nueva5] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual5][colum_actual5] = '.';

		}else{
			p = 1;
		} if (b5 > 13){p5 = 1;}

	}
	// movimiento, sexta ficha
	if ((b5 == 14 && b6 <= 12 && q4 == 1) || (p == 1 && p6 == 0)) {
		if (iniciar6 == 0) {
			fila_actual6 = 13;
			colum_actual6 = 12;
		}else {
			fila_actual6 = fila_nueva6;
			colum_actual6 = colum_nueva6;
		}

		if (tablero[fila_actual6][colum_actual6] == 'B' && tablero[fila_actual6 - 1][colum_actual6 - 1] != 'N') {

			fila_nueva6 = fila_actual6 - 1;
			colum_nueva6 = colum_actual6 - 1;

			iniciar6 = 1;
			b6++;
			p = 0;

			tablero[fila_nueva6][colum_nueva6] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual6][colum_actual6] = '.';

		} else if (tablero[fila_actual6][colum_actual6] == 'B' && tablero[fila_actual6 - 1][colum_actual6 - 1] == 'N' && tablero[fila_actual6 - 2][colum_actual6 - 2] == '.') {

			fila_nueva6 = fila_actual6 - 2;
			colum_nueva6 = colum_actual6 - 2;

			iniciar6 = 1;
			b6++;
			b6++;
			p = 0;

			tablero[fila_nueva6][colum_nueva6] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual6][colum_actual6] = '.';

		}else {
			p = 1;
		} if (b6 > 12){p6 = 1;}

	}
	// movimiento, septima ficha
	if ((b6 == 13 && b7 <= 12 && q5 == 1) || (p == 1 && p7 == 0)) {
		if (iniciar7 == 0) {
			fila_actual7 = 14;
			colum_actual7 = 12;
		}else {
			fila_actual7 = fila_nueva7;
			colum_actual7 = colum_nueva7;
		}

		if (tablero[fila_actual7][colum_actual7] == 'B' && tablero[fila_actual7 - 1][colum_actual7 - 1] != 'N') {

			fila_nueva7 = fila_actual7 - 1;
			colum_nueva7 = colum_actual7 - 1;

			iniciar7 = 1;
			b7++;
			p = 0;

			tablero[fila_nueva7][colum_nueva7] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual7][colum_actual7] = '.';

		} else if (tablero[fila_actual7][colum_actual7] == 'B' && tablero[fila_actual7 - 1][colum_actual7 - 1] == 'N' && tablero[fila_actual7 - 2][colum_actual7 - 2] == '.') {

			fila_nueva7 = fila_actual7 - 2;
			colum_nueva7 = colum_actual7 - 2;

			iniciar7 = 1;
			b7++;
			b7++;
			p = 0;

			tablero[fila_nueva7][colum_nueva7] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual7][colum_actual7] = '.';

		}else {
			p = 1;
		} if (b7 > 12){p7 = 1;}

	}
	// movimiento, octava ficha
	if ((b7 == 13 && b8 <= 11 && q6 == 1) || (p == 1 && p8 == 0)) {
		if (iniciar8 == 0) {
			fila_actual8 = 14;
			colum_actual8 = 11;
		}else {
			fila_actual8 = fila_nueva8;
			colum_actual8 = colum_nueva8;
		}

		if (tablero[fila_actual8][colum_actual8] == 'B' && tablero[fila_actual8 - 1][colum_actual8 - 1] != 'N') {

			fila_nueva8 = fila_actual8 - 1;
			colum_nueva8 = colum_actual8 - 1;

			iniciar8 = 1;
			b8++;
			p = 0;

			tablero[fila_nueva8][colum_nueva8] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual8][colum_actual8] = '.';

		} else if (tablero[fila_actual8][colum_actual8] == 'B' && tablero[fila_actual8 - 1][colum_actual8 - 1] == 'N' && tablero[fila_actual8 - 2][colum_actual8 - 2] == '.') {

			fila_nueva8 = fila_actual8 - 2;
			colum_nueva8 = colum_actual8 - 2;

			iniciar8 = 1;
			b8++;
			b8++;
			p = 0;
			tablero[fila_nueva8][colum_nueva8] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual8][colum_actual8] = '.';

		} else {
			p = 1;
		} if (b8 > 11){p8 = 1;}

	}
	// movimiento, novena ficha
	if ((b8 == 12 && b9 <= 11 && q7 == 1) || (p == 1 && p9 == 0)) {
		if (iniciar9 == 0) {
			fila_actual9 = 15;
			colum_actual9 = 11;
		}else {
			fila_actual9 = fila_nueva9;
			colum_actual9 = colum_nueva9;
		}

		if (tablero[fila_actual9][colum_actual9] == 'B' && tablero[fila_actual9 - 1][colum_actual9 - 1] != 'N') {

			fila_nueva9 = fila_actual9 - 1;
			colum_nueva9 = colum_actual9 - 1;

			iniciar9 = 1;
			b9++;
			p = 0;

			tablero[fila_nueva9][colum_nueva9] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual9][colum_actual9] = '.';

		} else if (tablero[fila_actual9][colum_actual9] == 'B' && tablero[fila_actual9 - 1][colum_actual9 - 1] == 'N' && tablero[fila_actual9 - 2][colum_actual9 - 2] == '.') {

			fila_nueva9 = fila_actual9 - 2;
			colum_nueva9 = colum_actual9 - 2;

			iniciar9 = 1;
			b9++;
			b9++;
			p = 0;

			tablero[fila_nueva9][colum_nueva9] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual9][colum_actual9] = '.';

		} else {
			p = 1;
		} if (b9 > 11){p9 = 1;}

	}
	// movimiento, decima ficha
	if ((b9 == 12 && b10 <= 11 && q8 == 1) || (p == 1 && p10 == 0)) {
		if (iniciar10 == 0) {
			fila_actual10 = 12;
			colum_actual10 = 15;
		}else {
			fila_actual10 = fila_nueva10;
			colum_actual10 = colum_nueva10;
		}

		if (tablero[fila_actual10][colum_actual10] == 'B' && tablero[fila_actual10 - 1][colum_actual10 - 1] != 'N') {

			fila_nueva10 = fila_actual10 - 1;
			colum_nueva10 = colum_actual10- 1;

			iniciar10 = 1;
			b10++;
			p = 0;

			tablero[fila_nueva10][colum_nueva10] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual10][colum_actual10] = '.';

		} else if (tablero[fila_actual10][colum_actual10] == 'B' && tablero[fila_actual10 - 1][colum_actual10 - 1] == 'N' && tablero[fila_actual10 - 2][colum_actual10 - 2] == '.') {

			fila_nueva10 = fila_actual10 - 2;
			colum_nueva10 = colum_actual10 - 2;

			iniciar10 = 1;
			b10++;
			b10++;
			p = 0;

			tablero[fila_nueva10][colum_nueva10] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual10][colum_actual10] = '.';

		} else {
			p = 1;
		} if (b10 > 11){p10 = 1;}

	}
	// movimiento, ficha 11
	if ((b10 == 12 && b11 <= 12 && q9 == 1) || (p == 1 && p11 == 0)) {
		if (iniciar11 == 0) {
			fila_actual11 = 13;
			colum_actual11 = 15;
		}else {
			fila_actual11 = fila_nueva11;
			colum_actual11 = colum_nueva11;
		}

		if (tablero[fila_actual11][colum_actual11] == 'B' && tablero[fila_actual11 - 1][colum_actual11 - 1] != 'N') {

			fila_nueva11 = fila_actual11 - 1;
			colum_nueva11 = colum_actual11 - 1;

			iniciar11 = 1;
			b11++;
			p = 0;

			tablero[fila_nueva11][colum_nueva11] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual11][colum_actual11] = '.';

		} else if (tablero[fila_actual11][colum_actual11] == 'B' && tablero[fila_actual11 - 1][colum_actual11 - 1] == 'N' && tablero[fila_actual11 - 2][colum_actual11 - 2] == '.') {

			fila_nueva11 = fila_actual11 - 2;
			colum_nueva11 = colum_actual11 - 2;

			iniciar11 = 1;
			b11++;
			b11++;
			p = 0;

			tablero[fila_nueva11][colum_nueva11] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actual11][colum_actual11] = '.';

		} else {
			p = 1;
		} if (b11 > 12){p11 = 1;}

	}
	// movimiento, ficha 12
		if ((b11 == 13 && b12 <= 12 && q10 == 1) || (p == 1 && p12 == 0)) {
			if (iniciar12 == 0) {
				fila_actual12 = 13;
				colum_actual12 = 14;
			}else {
				fila_actual12 = fila_nueva12;
				colum_actual12 = colum_nueva12;
			}

			if (tablero[fila_actual12][colum_actual12] == 'B' && tablero[fila_actual12 - 1][colum_actual12 - 1] != 'N') {

				fila_nueva12 = fila_actual12 - 1;
				colum_nueva12 = colum_actual12 - 1;

				iniciar12 = 1;
				b12++;
				p = 0;

				tablero[fila_nueva12][colum_nueva12] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual12][colum_actual12] = '.';

			} else if (tablero[fila_actual12][colum_actual12] == 'B' && tablero[fila_actual12 - 1][colum_actual12 - 1] == 'N' && tablero[fila_actual12 - 2][colum_actual12 - 2] == '.') {

				fila_nueva12 = fila_actual12 - 2;
				colum_nueva12 = colum_actual12 - 2;

				iniciar12 = 1;
				b12++;
				b12++;
				p = 0;

				tablero[fila_nueva12][colum_nueva12] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual12][colum_actual12] = '.';

			} else {
				p = 1;
			} if (b12 > 12){p12 = 1;}

		}
		// movimiento, ficha 13
		if ((b12 == 13 && b13 <= 13 && q11 == 1) || (p == 1 && p13 == 0)) {
			if (iniciar13 == 0) {
				fila_actual13 = 14;
				colum_actual13 = 14;
			}else {
				fila_actual13 = fila_nueva13;
				colum_actual13 = colum_nueva13;
			}

			if (tablero[fila_actual13][colum_actual13] == 'B' && tablero[fila_actual13 - 1][colum_actual13 - 1] != 'N') {

				fila_nueva13 = fila_actual13 - 1;
				colum_nueva13 = colum_actual13 - 1;

				iniciar13 = 1;
				b13++;
				p = 0;

				tablero[fila_nueva13][colum_nueva13] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual13][colum_actual13] = '.';

			} else if (tablero[fila_actual13][colum_actual13] == 'B' && tablero[fila_actual13 - 1][colum_actual13 - 1] == 'N' && tablero[fila_actual13 - 2][colum_actual13 - 2] == '.') {

				fila_nueva13 = fila_actual13 - 2;
				colum_nueva13 = colum_actual13 - 2;

				iniciar13 = 1;
				b13++;
				b13++;
				p = 0;

				tablero[fila_nueva13][colum_nueva13] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual13][colum_actual13] = '.';

			} else {
				p = 1;
			} if (b13 > 13){p13 = 1;}
		}
		// movimiento, ficha 14
		if ((b13 == 14 && b14 <= 12 && q12 == 1) || (p == 1 && p14 == 0)) {
			if (iniciar14 == 0) {
				fila_actual14 = 14;
				colum_actual14 = 13;
			}else {
				fila_actual14 = fila_nueva14;
				colum_actual14 = colum_nueva14;
			}

			if (tablero[fila_actual14][colum_actual14] == 'B' && tablero[fila_actual14 - 1][colum_actual14 - 1] != 'N') {

				fila_nueva14 = fila_actual14 - 1;
				colum_nueva14 = colum_actual14 - 1;

				iniciar14 = 1;
				b14++;
				p = 0;

				tablero[fila_nueva14][colum_nueva14] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual14][colum_actual14] = '.';

			} else if (tablero[fila_actual14][colum_actual14] == 'B' && tablero[fila_actual14 - 1][colum_actual14 - 1] == 'N' && tablero[fila_actual14 - 2][colum_actual14 - 2] == '.') {

				fila_nueva14 = fila_actual14 - 2;
				colum_nueva14 = colum_actual14 - 2;

				iniciar14 = 1;
				b14++;
				b14++;
				p = 0;

				tablero[fila_nueva14][colum_nueva14] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual14][colum_actual14] = '.';

			} else {
				p = 1;
			} if (b14 > 12){p14 = 1;}
		}
		// movimiento, ficha 15
		if ((b14 == 13 && b15 <= 12 && q13 == 1) || (p == 1 && p15 == 0)) {
			if (iniciar15 == 0) {
				fila_actual15 = 15;
				colum_actual15 = 13;
			}else {
				fila_actual15 = fila_nueva15;
				colum_actual15 = colum_nueva15;
			}

			if (tablero[fila_actual15][colum_actual15] == 'B' && tablero[fila_actual15 - 1][colum_actual15 - 1] != 'N') {

				fila_nueva15 = fila_actual15 - 1;
				colum_nueva15 = colum_actual15 - 1;

				iniciar15 = 1;
				b15++;
				p = 0;

				tablero[fila_nueva15][colum_nueva15] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual15][colum_actual15] = '.';

			} else if (tablero[fila_actual15][colum_actual15] == 'B' && tablero[fila_actual15 - 1][colum_actual15 - 1] == 'N' && tablero[fila_actual15 - 2][colum_actual15 - 2] == '.') {

				fila_nueva15 = fila_actual15 - 2;
				colum_nueva15 = colum_actual15 - 2;

				iniciar15 = 1;
				b15++;
				b15++;
				p = 0;

				tablero[fila_nueva15][colum_nueva15] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual15][colum_actual15] = '.';

			} else {
				p = 1;
			} if (b15 > 12){p15 = 1;}
		}
		// movimiento, ficha 16
		if ((b15 == 13 && b16 <= 11 && q14 == 1) || (p == 1 && p16 == 0)) {
			if (iniciar16 == 0) {
				fila_actual16 = 15;
				colum_actual16 = 12;
			}else {
				fila_actual16 = fila_nueva16;
				colum_actual16 = colum_nueva16;
			}

			if (tablero[fila_actual16][colum_actual16] == 'B' && tablero[fila_actual16 - 1][colum_actual16 - 1] != 'N') {

				fila_nueva16 = fila_actual16 - 1;
				colum_nueva16 = colum_actual16 - 1;

				iniciar16 = 1;
				b16++;
				p = 0;

				tablero[fila_nueva16][colum_nueva16] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual16][colum_actual16] = '.';

			} else if (tablero[fila_actual16][colum_actual16] == 'B' && tablero[fila_actual16 - 1][colum_actual16 - 1] == 'N' && tablero[fila_actual16 - 2][colum_actual16 - 2] == '.') {

				fila_nueva16 = fila_actual16 - 2;
				colum_nueva16 = colum_actual16 - 2;

				iniciar16 = 1;
				b16++;
				b16++;
				p = 0;

				tablero[fila_nueva16][colum_nueva16] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual16][colum_actual16] = '.';

			} else {
				p = 1;
			} if (b16 > 11){p16 = 1;}
		}
		// movimiento, ficha 17
		if ((b16 == 12 && b17 <= 12 && q15 == 1) || (p == 1 && p17 == 0)) {
			if (iniciar17 == 0) {
				fila_actual17 = 14;
				colum_actual17 = 15;
			}else {
				fila_actual17 = fila_nueva17;
				colum_actual17 = colum_nueva17;
			}

			if (tablero[fila_actual17][colum_actual17] == 'B' && tablero[fila_actual17 - 1][colum_actual17 - 1] != 'N') {

				fila_nueva17 = fila_actual17 - 1;
				colum_nueva17 = colum_actual17 - 1;

				iniciar17 = 1;
				b17++;
				p = 0;

				tablero[fila_nueva17][colum_nueva17] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual17][colum_actual17] = '.';

			} else if (tablero[fila_actual17][colum_actual17] == 'B' && tablero[fila_actual17 - 1][colum_actual17 - 1] == 'N' && tablero[fila_actual17 - 2][colum_actual17 - 2] == '.') {

				fila_nueva17 = fila_actual17 - 2;
				colum_nueva17 = colum_actual17 - 2;

				iniciar17 = 1;
				b17++;
				b17++;
				p = 0;

				tablero[fila_nueva17][colum_nueva17] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual17][colum_actual17] = '.';

			} else {
				p = 1;
			} if (b17 > 12){p17 = 1;}
		}
		// movimiento, ficha 18
		if ((b17 == 13 && b18 <= 13 && q16 == 1) || (p == 1 && p18 == 0)) {
			if (iniciar18 == 0) {
				fila_actual18 = 15;
				colum_actual18 = 15;
			}else {
				fila_actual18 = fila_nueva18;
				colum_actual18 = colum_nueva18;
			}

			if (tablero[fila_actual18][colum_actual18] == 'B' && tablero[fila_actual18 - 1][colum_actual18 - 1] != 'N') {

				fila_nueva18 = fila_actual18 - 1;
				colum_nueva18 = colum_actual18 - 1;

				iniciar18 = 1;
				b18++;
				p = 0;

				tablero[fila_nueva18][colum_nueva18] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual18][colum_actual18] = '.';

			} else if (tablero[fila_actual18][colum_actual18] == 'B' && tablero[fila_actual18 - 1][colum_actual18 - 1] == 'N' && tablero[fila_actual18 - 2][colum_actual18 - 2] == '.') {

				fila_nueva18 = fila_actual18 - 2;
				colum_nueva18 = colum_actual18 - 2;

				iniciar18 = 1;
				b18++;
				b18++;
				p = 0;

				tablero[fila_nueva18][colum_nueva18] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual18][colum_actual18] = '.';

			} else {
				p = 1;
			} if (b18 > 13){p18 = 1;}
		}
		// movimiento, ficha 19
		if ((b18 == 14 && b19 <= 12 && q17 == 1) || (p == 1 && p19 == 0)) {
			if (iniciar19 == 0) {
				fila_actual19 = 15;
				colum_actual19 = 14;
			}else {
				fila_actual19 = fila_nueva19;
				colum_actual19 = colum_nueva19;
			}

			if (tablero[fila_actual19][colum_actual19] == 'B' && tablero[fila_actual19 - 1][colum_actual19 - 1] != 'N') {

				fila_nueva19 = fila_actual19 - 1;
				colum_nueva19 = colum_actual19 - 1;

				iniciar19 = 1;
				b19++;
				p = 0;

				tablero[fila_nueva19][colum_nueva19] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual19][colum_actual19] = '.';

			} else if (tablero[fila_actual19][colum_actual19] == 'B' && tablero[fila_actual19 - 1][colum_actual19 - 1] == 'N' && tablero[fila_actual19 - 2][colum_actual19 - 2] == '.') {

				fila_nueva19 = fila_actual19 - 2;
				colum_nueva19 = colum_actual19 - 2;

				iniciar19 = 1;
				b19++;
				b19++;
				p = 0;

				tablero[fila_nueva19][colum_nueva19] = 'B';
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
				tablero[fila_actual19][colum_actual19] = '.';

			} else {
				p = 1;
			} if (b19 > 12){p19 = 1;}
		}
}




void aleatorioMaquina (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1) {

    *fila_actual1 = rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
    *colum_actual1 = rand() % 16;
    *colum_nueva1 = rand() % 16;
    *fila_nueva1 = rand() % 16;

}


void juegaMaquinaB (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[N][N]) {

	while ((tablero [*fila_actual1][*colum_actual1] != 'B') || (tablero [*fila_nueva1][*colum_nueva1] != '.')
	 || (pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2)) > 2)
    {
        *fila_actual1 = rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
        *colum_actual1 = rand() % 16;
        *colum_nueva1 = rand() % 16;
        *fila_nueva1 = rand() % 16;

    }
}


void juegaMaquinaN (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[N][N]) {

    while ((tablero [*fila_actual1][*colum_actual1] != 'N') || (tablero [*fila_nueva1][*colum_nueva1] != '.')
    || (pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2)) > 2)   // en el calculo le puse que sea > 8 para que haga tambien los saltos
    {
        *fila_actual1 = rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
        *colum_actual1 = rand() % 16;
        *colum_nueva1 = rand() % 16;
        *fila_nueva1 = rand() % 16;

    }
}
/*
Esto lo que revisa es si el ganador es "negras" o "blancas"
*/
void revision_ganador () {

	if (cont == 19 && bandera5 == 1) { // negras

		if (bandera6 == 0) {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp1 = g_strdup_printf("%s", stringJugador1);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp1);

		} else {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp3 = g_strdup_printf("%s", stringJugador_aleatorio1);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp3);

		}

		gtk_widget_show_all (ventana7);
	}
	else if (cont == 19 && bandera5 == 2) { // blancas

		if (bandera6 == 0) {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp2 = g_strdup_printf("%s", stringJugador2);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp2);

		} else {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp4 = g_strdup_printf("%s", stringJugador_aleatorio2);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp4);

		}

		gtk_widget_show_all (ventana7);

	}
	gtk_window_set_title (GTK_WINDOW (ventana7),"HOPPITY");
}
/*
Esto se revisa constantemente, con cada movimiento que se haga.
revisa si las fichas ocupan ya completamente el campamento opuesto
*/
void condicionQuienGana (char tablero[N][N]) {

	    for (int i = 0; i < 16; i++) {         //Recorremos la matriz
	        for (int j = 0; j < 16; j++) {
	                                            // Revisión del campo de las fichas negras.
	            if (i<=4 && j == 0 && tablero[i][j] == 'B')
	                cont++;
	            if (i<=4 && j == 1 && tablero[i][j] == 'B')
	                cont++;
	            if (i<=3 && j == 2 && tablero[i][j] == 'B')
	                cont++;
	            if (i<=2 && j == 3 && tablero[i][j] == 'B')
	                cont++;
	            if (i<=1 && j == 4 && tablero[i][j] == 'B')
	                cont++;
	        }
	    }
	    if (cont == 19){
	        bandera5 = 2; // se le asigna 2 en caso de sea blancas
	        revision_ganador(); // revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"
	    }
	    else {
	        cont = 0;
	    }

	    for (int i = 0; i < 16; i++) {         //Recorremos la matriz
	        for (int j = 0; j < 16; j++) {
	                                            // Revisión del campo de las fichas blancas.
	             if (i==15 && j>=11 && tablero[i][j] == 'N')
	                cont++;
	             if (i==14 && j>=11 && tablero[i][j] == 'N')
	                cont++;
	             if (i==13 && j>=12 && tablero[i][j] == 'N')
	                cont++;
	             if (i==12 && j>=13 && tablero[i][j] == 'N')
	                cont++;
	             if (i==11 && j>=14 && tablero[i][j] == 'N')
	                cont++;
	        }
	    }
	    if (cont == 19){
	        bandera5 = 1; // se le asigna 1 en caso de sea negras
	        revision_ganador(); // revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"
	    }
	    else {
	        cont = 0;
	    }

}

/*
void imprimirTurnoActualTablero () {

	if (turno1 == 0) {
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega humano: Negras");

	} else if (turno1 == 1) {
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega computadora: Blancas");

	} else if (turno2 == 2){
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega humano: Blancas");

	} else if (turno2 == 3) {
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega computadora: Negras");

	}
}*/


/*
Esta es la funcion principal, cada vez que se hace "click" encima de una ficha (la ficha que seleccionaste)
entra en esta funcion y se guardan las coordenas en donde esta esa ficha, y en base a eso se trabaja para realizar
los movimientos por parte del humano
*/
void eventBox(GtkWidget *event_box, GdkEventButton *event, gpointer data)
{
	i = (GUINT_FROM_LE(event->y) / 33); // en "i" se guarda valor de fila actual, 33 pixels tiene la imagen de la ficha
	j = (GUINT_FROM_LE(event->x) / 33); // en "j" se guarda valor de columna actual, 33 pixels tiene la imagen de la ficha


		if (bandera == 0 && bandera2 == 0 && ((Turno == 1 && Color == 1) || (Turno == 1 && Color == 2) || (Turno == 2 && Color == 1) || (Turno == 2 && Color == 2) )) {
			// cuando humano juega con negras, aca la ficha seleccionada se pinta
			if (tablero[i][j] == 'N' && ( (Turno == 1 && Color == 1) || (Turno == 2 && Color == 2) ) ){
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_NEGRA_CLICK);
				g_print ("coord negras: %d,%d\n", i,j);

				x1 = i; // le asignamos antes de modificarse
				x2 = j; // le asignamos antes de modificarse

				tablero[i][j] = '.'; // le asignamos "vacio" a la posicion de la ficha a mover
				bandera++;
				//bandera2 = 0;
			}// cuando humano juega con blancas, aca la ficha seleccionada se pinta
			else if (tablero[i][j] == 'B' && ( (Turno == 1 && Color == 2) || (Turno == 2 && Color == 1) ) ){
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_BLANCA_CLICK);
				g_print ("\ncoord blancas: %d,%d\n", i,j);

				x1 = i; // le asignamos antes de modificarse
				x2 = j; // le asignamos antes de modificarse

				tablero[i][j] = '.';
				bandera++;
				//bandera2 = 0;
			}

		} // aca entra despues de seleccionar la ficha a mover, entra para ver donde quieres mover tu ficha
		else if (bandera == 1 && bandera2 == 0 && ((Turno == 1 && Color == 1) || (Turno == 1 && Color == 2) || (Turno == 2 && Color == 1) || (Turno == 2 && Color == 2))) {

			x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
			y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

			//con esto se soluciono lo de elegir una ficha y mover a la ubicacion donde esta la ficha elegida  x1 + x2 != x+y bien
			if (Turno == 1 && Color == 1) {
				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva

				//imprimirTurnoActualTablero ();

				if (x1 == x && x2 == y) // esto cambie, porque cuando es "x1 + x2 == x + y", se cumple tambien cuando intenta hacer movimiento en la diagonal " / " (diagonal de abajo hacia arriba)
				{
					//gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
					tablero[x1][x2] = 'N';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_NEGRO);
					actualizacionDeTablero();
					bandera--;
				}
					// movimientos adyacentes
					if (( (i >= 0 && i <= 15) && (j >= 0 && j <= 15) && (x >= 0 && x <= 15) && (y >= 0 && y <= 15)
					&& ((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2) && tablero[x][y] != 'N' && tablero[i][j] != 'B' && bandera == 1)
							// condicion para hacer salto simple tablero [x][y] != 'N' || tablero [x][y] != 'B' con este agregado, se soluciono lo de comer ficha contraria y cuando hace salto y selecciona su propia ficha
					|| ( (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 8)) && (tablero [x][y] != 'N' && tablero [x][y] != 'B') && ( ((tablero [x1+1][x2+1] == 'N' || tablero [x1+1][x2+1] == 'B') && x1 < z1 && x2 < z2  && x1+2==z1 && x2+2==z2)
					||  ((tablero [x1+1][x2-1] == 'N' || tablero [x1+1][x2-1] == 'B') && x1 < z1 && x2 > z2 && x1+2==z1 && x2-2==z2)
					||  ((tablero [x1+1][x2] == 'N' || tablero [x1+1][x2] == 'B') 	&& x1 < z1 && x2 == z2 && x1+2==z1 && x2==z2)
					||  ((tablero [x1-1][x2+1] == 'N' || tablero [x1-1][x2+1] == 'B') && x1 > z1 && x2 < z2 && x1-2==z1 && x2+2==z2)
					||  ((tablero [x1-1][x2-1] == 'N' || tablero [x1-1][x2-1] == 'B') && x1 > z1 && x2 > z2 && x1-2==z1 && x2-2==z2)
					||  ((tablero [x1-1][x2] == 'N' || tablero [x1-1][x2] == 'B') 	&& x1 > z1 && x2 == z2 && x1-2==z1 && x2==z2)
					||  ((tablero [x1][x2+1] == 'N' || tablero [x1][x2+1] == 'B') 	&& x1 == z1 && x2 < z2 && x1==z1 && x2+2==z2)
					||  ((tablero [x1][x2-1] == 'N' || tablero [x1][x2-1] == 'B') 	&& x1 == z1 && x2 > z2 && x1==z1 && x2-2==z2) ) ) ) {  // si se le quita tablero[z1][z2] != 'N' avanza solo adelante y (pow((x - x1), 2) + pow((y - x2), 2) IA?


							gtk_label_set_text(GTK_LABEL(label_movInvalido), "\n\n");

							tablero[x][y] = 'N';
							gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_NEGRO);

							// movimiento maquina
							//aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
							//juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
							solucionMov2fichas();
							juegaMaquinaIABlancas (tablero);

//							tablero[fila_nueva1][colum_nueva1] = 'B';
//
//							gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
//
//							tablero[fila_actual1][colum_actual1] = '.';

							actualizacionDeTablero();
							bandera--;
							condicionQuienGana (tablero);

					}
					else {

							gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");

					}


			}

			// juega humano con blancas

			else if (Turno == 1 && Color == 2) {

				x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
				y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva

				if (x1 == x && x2 == y)
				{
					//gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
					tablero[x1][x2] = 'B';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_BLANCO);
					actualizacionDeTablero();
					bandera--;
				}

				if (((i >= 0 && i <= 15) && (j >= 0 && j <= 15) && (x >= 0 && x <= 15) && (y >= 0 && y <= 15)
				&& ((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2) && tablero[x][y] != 'N' && tablero[i][j] != 'B' && bandera == 1)
						// condicion para hacer saltos
				|| ( (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 8)) && (tablero [x][y] != 'N' && tablero [x][y] != 'B') && ( ((tablero [x1+1][x2+1] == 'N' || tablero [x1+1][x2+1] == 'B') && x1 < z1 && x2 < z2  && x1+2==z1 && x2+2==z2)
				||  ((tablero [x1+1][x2-1] == 'N' || tablero [x1+1][x2-1] == 'B') && x1 < z1 && x2 > z2 && x1+2==z1 && x2-2==z2)
				||  ((tablero [x1+1][x2] == 'N' || tablero [x1+1][x2] == 'B') 	&& x1 < z1 && x2 == z2 && x1+2==z1 && x2==z2)
				||  ((tablero [x1-1][x2+1] == 'N' || tablero [x1-1][x2+1] == 'B') && x1 > z1 && x2 < z2 && x1-2==z1 && x2+2==z2)
				||  ((tablero [x1-1][x2-1] == 'N' || tablero [x1-1][x2-1] == 'B') && x1 > z1 && x2 > z2 && x1-2==z1 && x2-2==z2)
				||  ((tablero [x1-1][x2] == 'N' || tablero [x1-1][x2] == 'B') 	&& x1 > z1 && x2 == z2 && x1-2==z1 && x2==z2)
				||  ((tablero [x1][x2+1] == 'N' || tablero [x1][x2+1] == 'B') 	&& x1 == z1 && x2 < z2 && x1==z1 && x2+2==z2)
				||  ((tablero [x1][x2-1] == 'N' || tablero [x1][x2-1] == 'B') 	&& x1 == z1 && x2 > z2 && x1==z1 && x2-2==z2) ) ) ) {  // si se le quita tablero[z1][z2] != 'N' avanza solo adelante y (pow((x - x1), 2) + pow((y - x2), 2) IA?

					gtk_label_set_text(GTK_LABEL(label_movInvalido), "\n\n");

					tablero[x][y] = 'B';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);

					// movimiento maquina
					aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
					juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);


					tablero[fila_nueva1][colum_nueva1] = 'N';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_NEGRO);

					tablero[fila_actual1][colum_actual1] = '.';
					actualizacionDeTablero();
					bandera--;
					condicionQuienGana (tablero);


				}
				else {

					gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");

				}


			}//

			// JUega maquina con negras

			else if (Turno == 2 && Color == 1) {

				x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
				y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva


				if (x1 == x && x2 == y)
				{
					//gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
					tablero[x1][x2] = 'B';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_BLANCO);
					actualizacionDeTablero();
					bandera--;
				}

					// movimientos adyacentes
				if (((i >= 0 && i <= 15) && (j >= 0 && j <= 15) && (x >= 0 && x <= 15) && (y >= 0 && y <= 15)
				&& ((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2) && tablero[x][y] != 'N' && tablero[i][j] != 'B' && bandera == 1)
						// condicion para hacer saltos
				|| ( (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 8)) && (tablero [x][y] != 'N' && tablero [x][y] != 'B') && ( ((tablero [x1+1][x2+1] == 'N' || tablero [x1+1][x2+1] == 'B') && x1 < z1 && x2 < z2  && x1+2==z1 && x2+2==z2)
				||  ((tablero [x1+1][x2-1] == 'N' || tablero [x1+1][x2-1] == 'B') && x1 < z1 && x2 > z2 && x1+2==z1 && x2-2==z2)
				||  ((tablero [x1+1][x2] == 'N' || tablero [x1+1][x2] == 'B') 	&& x1 < z1 && x2 == z2 && x1+2==z1 && x2==z2)
				||  ((tablero [x1-1][x2+1] == 'N' || tablero [x1-1][x2+1] == 'B') && x1 > z1 && x2 < z2 && x1-2==z1 && x2+2==z2)
				||  ((tablero [x1-1][x2-1] == 'N' || tablero [x1-1][x2-1] == 'B') && x1 > z1 && x2 > z2 && x1-2==z1 && x2-2==z2)
				||  ((tablero [x1-1][x2] == 'N' || tablero [x1-1][x2] == 'B') 	&& x1 > z1 && x2 == z2 && x1-2==z1 && x2==z2)
				||  ((tablero [x1][x2+1] == 'N' || tablero [x1][x2+1] == 'B') 	&& x1 == z1 && x2 < z2 && x1==z1 && x2+2==z2)
				||  ((tablero [x1][x2-1] == 'N' || tablero [x1][x2-1] == 'B') 	&& x1 == z1 && x2 > z2 && x1==z1 && x2-2==z2) ) ) ) {  // si se le quita tablero[z1][z2] != 'N' avanza solo adelante y (pow((x - x1), 2) + pow((y - x2), 2) IA?

					gtk_label_set_text(GTK_LABEL(label_movInvalido), "\n\n");

					tablero[x][y] = 'B';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
					//actualizacionDeTablero();

					// movimiento maquina
					aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
					juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);


					tablero[fila_nueva1][colum_nueva1] = 'N';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_NEGRO);

					tablero[fila_actual1][colum_actual1] = '.';
					actualizacionDeTablero();
					bandera--;
					condicionQuienGana (tablero);
				}
				else {

					gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");

				}

			}

			// JUega maquina con blancas

			else if (Turno == 2 && Color == 2) {

				x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
				y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva


				if (x1 == x && x2 == y) // esto cambie, porque cuando es "x1 + x2 == x + y", se cumple tambien cuando intenta hacer movimiento en la diagonal " / " (diagonal de abajo hacia arriba)
				{
					//gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
					tablero[x1][x2] = 'N';
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_NEGRO);
					actualizacionDeTablero();
					bandera--;
				}
					// movimientos adyacentes
					if (( (i >= 0 && i <= 15) && (j >= 0 && j <= 15) && (x >= 0 && x <= 15) && (y >= 0 && y <= 15)
					&& ((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2) && tablero[x][y] != 'N' && tablero[i][j] != 'B' && bandera == 1)
							// condicion para hacer salto simple tablero [x][y] != 'N' || tablero [x][y] != 'B' con este agregado, se soluciono lo de comer ficha contraria y cuando hace salto y selecciona su propia ficha
					|| ( (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 8)) && (tablero [x][y] != 'N' && tablero [x][y] != 'B') && ( ((tablero [x1+1][x2+1] == 'N' || tablero [x1+1][x2+1] == 'B') && x1 < z1 && x2 < z2  && x1+2==z1 && x2+2==z2)
					||  ((tablero [x1+1][x2-1] == 'N' || tablero [x1+1][x2-1] == 'B') && x1 < z1 && x2 > z2 && x1+2==z1 && x2-2==z2)
					||  ((tablero [x1+1][x2] == 'N' || tablero [x1+1][x2] == 'B') 	&& x1 < z1 && x2 == z2 && x1+2==z1 && x2==z2)
					||  ((tablero [x1-1][x2+1] == 'N' || tablero [x1-1][x2+1] == 'B') && x1 > z1 && x2 < z2 && x1-2==z1 && x2+2==z2)
					||  ((tablero [x1-1][x2-1] == 'N' || tablero [x1-1][x2-1] == 'B') && x1 > z1 && x2 > z2 && x1-2==z1 && x2-2==z2)
					||  ((tablero [x1-1][x2] == 'N' || tablero [x1-1][x2] == 'B') 	&& x1 > z1 && x2 == z2 && x1-2==z1 && x2==z2)
					||  ((tablero [x1][x2+1] == 'N' || tablero [x1][x2+1] == 'B') 	&& x1 == z1 && x2 < z2 && x1==z1 && x2+2==z2)
					||  ((tablero [x1][x2-1] == 'N' || tablero [x1][x2-1] == 'B') 	&& x1 == z1 && x2 > z2 && x1==z1 && x2-2==z2) ) ) ) {  // si se le quita tablero[z1][z2] != 'N' avanza solo adelante y (pow((x - x1), 2) + pow((y - x2), 2) IA?


							gtk_label_set_text(GTK_LABEL(label_movInvalido), "\n\n");

							tablero[x][y] = 'N';
							gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_NEGRO);
							//actualizacionDeTablero();

							// movimiento maquina
							aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
							juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);


							tablero[fila_nueva1][colum_nueva1] = 'B';
							gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);

							tablero[fila_actual1][colum_actual1] = '.';
							actualizacionDeTablero();
							bandera--;
							condicionQuienGana (tablero);

					}
					else {

							gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");

					}


			}

		}


}

/*
 Esta funcion se usa cuando en el juego empieza la maquina
 al apretar el boton para que la maquina empieze a jugar entra aca y actualiza una vez ya con el movimiento que hizo la maquina
 entra solamente una vez, despues ya se hace una jugada normal
 */
void aprieta_juega_compu (GtkWidget *event_box, GdkEventButton *event, gpointer data) {

	if (bandera4 == 1) {
		if (bandera3 == 0) {
			// movimiento maquina negras
			aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
			juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);

			tablero[fila_nueva1][colum_nueva1] = 'N';
			tablero[fila_actual1][colum_actual1] = '.';

			actualizacionDeTablero();
			bandera3 = -1; // le asignamos -1 para que solamente se haga una vez la revision de las condiciones del "if"
			bandera2--;
		}
		else if (bandera3 == 1) {  // si bandera == 1, maquina jugara con blancas (el valor de bandera se cambia cuando se selecciona color de ficha)
			// movimiento maquina blancas
			aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
			juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);

			tablero[fila_nueva1][colum_nueva1] = 'B';
			tablero[fila_actual1][colum_actual1] = '.';

			actualizacionDeTablero();
			bandera3 = -1; // le asignamos -1 para que solamente se haga una vez la revision de las condiciones del "if"
			bandera2--;
		}
	}
}


void aprieta_jugar_ventana(GtkWidget *event_box, GdkEventButton *event, gpointer data)

{
	 gtk_widget_hide (ventana);

	 gtk_widget_show_all (ventana4);
	 gtk_window_set_title (GTK_WINDOW (ventana4),"HOPPITY");
}


void aprieta_creditos_ventana3(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana1);

		 gtk_widget_show_all (ventana3);
		 gtk_window_set_title (GTK_WINDOW (ventana3),"HOPPITY");
}



void aprieta_cerrar_ventana3(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana3);

		 //gtk_widget_show_all (ventana);
}

void aprieta_atras_ventana4(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana4);

		 gtk_widget_show_all (ventana);
}

void aprieta_HumvsCom_ventana4(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana4);

	char modo[30] = {"Humano vs. Computadora"};

		gchar *opcion = g_strdup_printf("%s", modo);
		gtk_label_set_text(GTK_LABEL(label_modo_juego), opcion);

		 gtk_widget_show_all (ventana1);
		 gtk_window_set_title (GTK_WINDOW (ventana1),"HOPPITY");
}


void aprieta_atras_ventana1(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana1);

		 gtk_widget_show_all (ventana4);
}

void aprieta_elegir_ventana1(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana1);

		 gtk_widget_show_all (ventana2);
		 gtk_window_set_title (GTK_WINDOW (ventana2),"HOPPITY");

}


// arreglar para que imprima bien los turnos actuales

void imprimirTurnoActual () {
	if (Turno == 1 && Color == 1) {
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega humano: Negras");

	} else if (Turno == 1 && Color == 2){
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega humano: Blancas");

	} else if (Turno == 2 && Color == 1) {
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega computadora: Negras");

	} else if (Turno == 2 && Color == 2) {
		gtk_label_set_text(GTK_LABEL(turno_jugador), "Juega computadora: Blancas");

	}
}




void aprieta_aleatorio (GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana1);

	//int turno, color;
	srand (time(NULL));
	Turno = (rand () % 2) + 1;
	if (Turno == 1 ) {
		bandera4 = 0; // en caso de que apriete turno humano, entonces al apretar el boton para que la maquina mueva no va a funcionar...
	} else {
		bandera2 = 1; // para que no entre de una a funcion evenBox y obligue a apretar el boton para que empieze maquina
	}

	Color = (rand () % 2) + 1;
	if (Color == 2) {
		bandera3 = 1;  // esto en caso de que juegue maquina con blancas
	}

	 gtk_widget_show_all (ventana6); //muestra la ventana de inicio
	 gtk_window_set_title (GTK_WINDOW (ventana6),"HOPPITY"); // Cambia titulo de la ventana.

}

// se encarga de que aparezcan los nombres en el tablero
void aprieta_listo_ventana6 (GtkWidget *event_box, GdkEventButton *event, gpointer data)
{
	gtk_widget_hide (ventana6);

	strncpy (stringJugador_aleatorio1, gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador1)), 15); // guardamos en el puntero lo que se introduce por teclado
	strncpy (stringJugador_aleatorio2, gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador2)), 15);

	// en caso de no ingresar ningun nombre...
	if (strlen(stringJugador_aleatorio1) == 0)
			strcpy(stringJugador_aleatorio1, "Jugador Negro");

	if (strlen(stringJugador_aleatorio2) == 0)
		strcpy(stringJugador_aleatorio2, "Jugador Blanco");

	// faltaria un if, de acuerdo a lo que se eliga (conexion con el codigo)

	gchar *temp3 = g_strdup_printf("%s", stringJugador_aleatorio1);
	gtk_label_set_text(GTK_LABEL(jugador_fichanegra), temp3);

	gchar *temp4 = g_strdup_printf("%s", stringJugador_aleatorio2);
	gtk_label_set_text(GTK_LABEL(jugador_fichablanca), temp4);

	bandera6 = 1; // para que entre en lo de revisionganador, y aparezca el nombre cuando aprieta aleatorio

	 imprimirTurnoActual();
	 iniciartablero (tablero);
	 cargarimagenes (tablero);

	 gtk_widget_show_all (tablero_hoppity);
	 gtk_window_set_title (GTK_WINDOW (tablero_hoppity),"HOPPITY"); // Cambia titulo de la ventana.

}


//al apretar boton humano aparece que se selecciono esa opcion e imprime abajo como la opcion elegida
void aprieta_turno_humano (GtkWidget *event_box, GdkEventButton *event, gpointer data){
	char turno[30] = {"Humano"};
	Turno = 1;
	bandera4 = 0; // en caso de que apriete turno humano, entonces al apretar el boton para que la maquina mueva no va a funcionar...

		gchar *temp1 = g_strdup_printf("%s", turno);
		gtk_label_set_text(GTK_LABEL(label_turno), temp1);

}


//al apretar boton computadora aparece que se selecciono esa opcion e imprime abajo como la opcion elegida
void aprieta_turno_computadora (){
	char turno[30] = {"Computadora"};
	Turno = 2;
	bandera2 = 1; // para que no entre de una a funcion evenBox y obligue a apretar el boton para que empieze maquina
		gchar *temp1 = g_strdup_printf("%s", turno);
		gtk_label_set_text(GTK_LABEL(label_turno), temp1);

}


//al apretar boton blanco aparece que se selecciono esa opcion e imprime abajo abajo como la opcion elegida
void aprieta_color_blanco (){
	char color[30] = {"Blanca"};
	Color = 2;
	bandera3 = 1;  // esto en caso de que juegue maquina con blancas
		gchar *temp1 = g_strdup_printf("%s", color);
		gtk_label_set_text(GTK_LABEL(label_color), temp1);

}

//al apretar boton negro aparece que se selecciono esa opcion e imprime abajo abajo como la opcion elegida
void aprieta_color_negro (){
	char color[30] = {"Negra"};
	Color = 1;

		gchar *temp1 = g_strdup_printf("%s", color);
		gtk_label_set_text(GTK_LABEL(label_color), temp1);

}


void aprieta_turno_aleatorio_ventana2(){
	srand (time(NULL));
	Turno = (rand () % 2) + 1;
	 if (Turno == 1){

		 bandera4 = 0; // en caso de que apriete turno humano, entonces al apretar el boton para que la maquina mueva no va a funcionar...

		 char turno[30] = {"Humano"};
		 gchar *temp1 = g_strdup_printf("%s", turno);
		 gtk_label_set_text(GTK_LABEL(label_turno), temp1);

	  } else {

		  bandera2 = 1; // para que no entre de una a funcion evenBox y obligue a apretar el boton para que empieze maquina

		  char turno[30] = {"Computadora"};
		  gchar *temp1 = g_strdup_printf("%s", turno);
		  gtk_label_set_text(GTK_LABEL(label_turno), temp1);

	 }
}



void aprieta_color_aleatorio_ventana2(){
	srand (time(NULL));
	Color = (rand () % 2) + 1;
	 if (Color == 1){

		char color[30] = {"Negra"};
		gchar *temp1 = g_strdup_printf("%s", color);
		gtk_label_set_text(GTK_LABEL(label_color), temp1);

	  } else {

		  bandera3 = 1;  // esto en caso de que juegue maquina con blancas

		  char color[30] = {"Blanca"};
		  gchar *temp1 = g_strdup_printf("%s", color);
		  gtk_label_set_text(GTK_LABEL(label_color), temp1);
	 }
}



void aprieta_atras_ventana2(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana2);

		 gtk_widget_show_all (ventana1);
}



// cuando arpieta listo despues de hacer las elecciones...
// al apretar listo, aparecerá el tablero, ya con las configuraciones
void aprieta_listo_ventana2(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana2);

	strncpy (stringJugador1, gtk_entry_get_text(GTK_ENTRY(entry_jugador1)), 15); // guardamos en el puntero lo que se introduce por teclado
	strncpy (stringJugador2, gtk_entry_get_text(GTK_ENTRY(entry_jugador2)), 15); // guardamos en el puntero lo que se introduce por teclado

	// en caso de no ingresar ningun nombre...
	if (strlen(stringJugador1) == 0)
		strcpy(stringJugador1, "Jugador Negro");

	if (strlen(stringJugador2) == 0)
		strcpy(stringJugador2, "Jugador Blanco");

	gchar *temp1 = g_strdup_printf("%s", stringJugador1);
	gtk_label_set_text(GTK_LABEL(jugador_fichanegra), temp1);

	gchar *temp2 = g_strdup_printf("%s", stringJugador2);
	gtk_label_set_text(GTK_LABEL(jugador_fichablanca), temp2);

	// para cargar las imagenes en el tablero
	imprimirTurnoActual();
	iniciartablero (tablero);
	cargarimagenes (tablero);

	 gtk_widget_show_all (tablero_hoppity);
	 gtk_window_set_title (GTK_WINDOW (tablero_hoppity),"HOPPITY");
}


void aprieta_atras_tablero_hoppity(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (tablero_hoppity);

		 gtk_widget_show_all (ventana2);
		 gtk_window_set_title (GTK_WINDOW (ventana2),"HOPPITY");
}

void aprieta_ayuda_tablero_hoppity(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (tablero_hoppity);

	gtk_window_set_title (GTK_WINDOW (ventana5),"HOPPITY");
	gtk_widget_show_all (ventana5);

}


void aprieta_cerrar_ventana5(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana5);

		gtk_widget_show_all (tablero_hoppity);
}




 int main (int argc, char *argv[]) {
		//Inicializaciones

	    GtkBuilder *builder;

	    gtk_init (&argc, &argv);

	    builder = gtk_builder_new();
	    gtk_builder_add_from_file(builder, "pruebaInterfaz.glade", NULL);


	    // tablero
	    tablero_hoppity = GTK_WIDGET(gtk_builder_get_object(builder, "tablero_hoppity"));
	    eventbox_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "eventbox_tablero"));
	    box1_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "box1_tablero"));
	    box2_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "box2_tablero"));
	    box3_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "box3_tablero"));
	    fixed_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_tablero"));
	    grid_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "grid_tablero"));
	    box4_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "box4_tablero"));

	    // ventanas
	    ventana = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_bienvenida"));
	    ventana1 = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_inicio"));
	    ventana2 = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_elegir"));
	    ventana3 = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_creditos"));
	    ventana4 = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_modo"));
	    ventana5 = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_ayuda"));
	    ventana6 = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_nombre_aleatorio"));
	    ventana7 = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_victoria"));
	    fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));


	    gtk_window_set_title (GTK_WINDOW (ventana),"HOPPITY"); // Cambia titulo de la ventana.



	    //botones
	    boton_bienvenida_salir = GTK_WIDGET(gtk_builder_get_object(builder, "boton_bienvenida_salir"));
	    boton_bienvenida_jugar = GTK_WIDGET(gtk_builder_get_object(builder, "boton_bienvenida_jugar"));


	    boton_inicio_elegir = GTK_WIDGET(gtk_builder_get_object(builder, "boton_inicio_elegir"));
	    boton_listo = GTK_WIDGET(gtk_builder_get_object(builder, "boton_listo"));
	    boton_inicio_atras = GTK_WIDGET(gtk_builder_get_object(builder, "boton_inicio_atras")); // "atras" de la segunda ventana
	    boton_elegir_atras = GTK_WIDGET(gtk_builder_get_object(builder, "boton_elegir_atras"));// "atras" de la tercera ventana
	    boton_bienvenida_credito = GTK_WIDGET(gtk_builder_get_object(builder, "boton_bienvenida_credito"));
	    boton_cerrar_credito = GTK_WIDGET(gtk_builder_get_object(builder, "boton_cerrar_credito"));
	    boton_modo1 = GTK_WIDGET(gtk_builder_get_object(builder, "boton_modo1"));
	    boton_modo_atras = GTK_WIDGET(gtk_builder_get_object(builder, "boton_modo_atras"));
	    boton_ayuda_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "boton_ayuda_tablero"));
	    boton_ayuda_cerrar = GTK_WIDGET(gtk_builder_get_object(builder, "boton_ayuda_cerrar"));
	    boton_cerrar_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "boton_cerrar_tablero"));
	    boton_atras_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "boton_atras_tablero"));
	    boton_inicio_aleatorio = GTK_WIDGET(gtk_builder_get_object(builder, "boton_inicio_aleatorio"));
	    boton_aleatorio_listo = GTK_WIDGET(gtk_builder_get_object(builder, "boton_aleatorio_listo"));
	    boton_ventana6_listo = GTK_WIDGET(gtk_builder_get_object(builder, "boton_ventana6_listo"));
	    boton_humano = GTK_WIDGET(gtk_builder_get_object(builder, "boton_humano"));
	    boton_computadora = GTK_WIDGET(gtk_builder_get_object(builder, "boton_computadora"));
	    boton_aleatorio1 = GTK_WIDGET(gtk_builder_get_object(builder, "boton_aleatorio1"));
	    boton_blanca = GTK_WIDGET(gtk_builder_get_object(builder, "boton_blanca"));
	    boton_negra = GTK_WIDGET(gtk_builder_get_object(builder, "boton_negra"));
	    boton_aleatorio2 = GTK_WIDGET(gtk_builder_get_object(builder, "boton_aleatorio2"));
	    boton_credito = GTK_WIDGET(gtk_builder_get_object(builder, "boton_credito"));

	    boton_inicia_compu = GTK_WIDGET(gtk_builder_get_object(builder, "boton_inicia_compu"));

	    nombre_jugador_negro = GTK_WIDGET(gtk_builder_get_object(builder, "nombre_jugador_negro"));
	    nombre_jugador_blanco = GTK_WIDGET(gtk_builder_get_object(builder, "nombre_jugador_blanco"));

	    entry_jugador1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_jugador1"));
	    entry_jugador2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_jugador2"));

	    entry_aleatorio_jugador1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_aleatorio_jugador1"));
	    entry_aleatorio_jugador2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_aleatorio_jugador2"));

	    // para que aparezca en el menu de elegir, la parte de abajo
	    label_modo_juego = GTK_WIDGET(gtk_builder_get_object(builder, "label_modo_juego"));
	    label_turno = GTK_WIDGET(gtk_builder_get_object(builder, "label_turno"));
	    label_color = GTK_WIDGET(gtk_builder_get_object(builder, "label_color"));
	    label_turno_actual = GTK_WIDGET(gtk_builder_get_object(builder, "label_turno_actual"));
	    label_movInvalido = GTK_WIDGET(gtk_builder_get_object(builder, "label_movInvalido"));

		nombre_ganador = GTK_WIDGET(gtk_builder_get_object(builder, "nombre_ganador"));


		// tablero nuevo (por imagenes)
		boton_tablero_atras = GTK_WIDGET(gtk_builder_get_object(builder, "boton_tablero_atras"));
		boton_tablero_ayuda = GTK_WIDGET(gtk_builder_get_object(builder, "boton_tablero_ayuda"));
		boton_tablero_cerrar = GTK_WIDGET(gtk_builder_get_object(builder, "boton_tablero_cerrar"));
		jugador_fichanegra = GTK_WIDGET(gtk_builder_get_object(builder, "jugador_fichanegra"));
		jugador_fichablanca = GTK_WIDGET(gtk_builder_get_object(builder, "jugador_fichablanca"));
		turno_jugador = GTK_WIDGET(gtk_builder_get_object(builder, "turno_jugador"));

	    g_signal_connect (ventana, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	    g_signal_connect (boton_bienvenida_salir, "clicked", G_CALLBACK(gtk_window_close), ventana);
	    g_signal_connect(boton_bienvenida_jugar, "button-press-event", G_CALLBACK(aprieta_jugar_ventana), NULL);
	    g_signal_connect(boton_bienvenida_credito,"button-press-event", G_CALLBACK(aprieta_creditos_ventana3), NULL);
	    g_signal_connect(boton_cerrar_credito,"button-press-event", G_CALLBACK(aprieta_cerrar_ventana3), NULL);
	    g_signal_connect(boton_credito,"button-press-event", G_CALLBACK(aprieta_creditos_ventana3), NULL);

	    // ventana4
	    g_signal_connect(boton_modo_atras,"button-press-event", G_CALLBACK(aprieta_atras_ventana4), NULL);
	    g_signal_connect(boton_modo1,"button-press-event", G_CALLBACK(aprieta_HumvsCom_ventana4), NULL);

	    // ventana1
	    g_signal_connect(boton_inicio_atras,"button-press-event", G_CALLBACK(aprieta_atras_ventana1), NULL);
	    g_signal_connect(boton_inicio_elegir,"button-press-event", G_CALLBACK(aprieta_elegir_ventana1), NULL);
	    g_signal_connect(boton_inicio_aleatorio, "button-press-event", G_CALLBACK(aprieta_aleatorio), NULL);

	    // ventana2
	    g_signal_connect(boton_elegir_atras,"button-press-event", G_CALLBACK(aprieta_atras_ventana2), NULL);
	    g_signal_connect(boton_listo,"button-press-event", G_CALLBACK(aprieta_listo_ventana2), NULL);
	    //aprieta los botones para elegir turno y color
		g_signal_connect(boton_humano, "button-press-event", G_CALLBACK(aprieta_turno_humano), NULL);
		g_signal_connect(boton_computadora, "button-press-event", G_CALLBACK(aprieta_turno_computadora), NULL);
		g_signal_connect(boton_blanca, "button-press-event", G_CALLBACK(aprieta_color_blanco), NULL);
		g_signal_connect(boton_negra, "button-press-event", G_CALLBACK(aprieta_color_negro), NULL);

		g_signal_connect(boton_aleatorio1, "button-press-event", G_CALLBACK(aprieta_turno_aleatorio_ventana2), NULL);
		g_signal_connect(boton_aleatorio2, "button-press-event", G_CALLBACK(aprieta_color_aleatorio_ventana2), NULL);

	    //tablero (por imagenes)
	    g_signal_connect(boton_tablero_atras,"button-press-event", G_CALLBACK(aprieta_atras_tablero_hoppity), NULL);
	    g_signal_connect(boton_tablero_ayuda,"button-press-event", G_CALLBACK(aprieta_ayuda_tablero_hoppity), NULL);
	    g_signal_connect(boton_tablero_cerrar,"button-press-event", G_CALLBACK(gtk_window_close), NULL);

	    //ventana5
	    g_signal_connect(boton_ayuda_cerrar,"button-press-event", G_CALLBACK(aprieta_cerrar_ventana5), NULL);

	    //ventana6
	    g_signal_connect(boton_ventana6_listo , "button-press-event", G_CALLBACK(aprieta_listo_ventana6), NULL);
	    // tablero
	    g_signal_connect(boton_inicia_compu,"button-press-event", G_CALLBACK(aprieta_juega_compu), NULL);


	    g_signal_connect(eventbox_tablero , "button-press-event", G_CALLBACK(eventBox), NULL);


	    //GtkWidget *fondotablero = gtk_image_new_from_file("tableroHoppity.png");
	    //gtk_fixed_put(GTK_FIXED(fixed_tablero), fondotablero, 0, 0);

	    /* make sure that everything, window and label, are visible */
	    gtk_widget_show_all (ventana);

	    /* start the main loop, and let it rest there until the application is closed */
	    gtk_main ();

	    return 0;
 }
