#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "DeclaracionesHoppity.h"

//#define N 16

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
GtkWidget *ventana_estadisticas;
GtkWidget *eventbox_tablero;
GtkWidget *box1_tablero;
GtkWidget *box2_tablero;
GtkWidget *box3_tablero;
GtkWidget *fixed_tablero;
GtkWidget *grid_tablero;
GtkWidget *box4_tablero;
GtkWidget *fixed;
//botones
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
GtkWidget *boton_pasar_turno;
GtkWidget *boton_juego_nuevo;
GtkWidget *boton_estadisticas;
GtkWidget *cerrarEstadisticas;
GtkWidget *boton_cerrar_victoria;

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
GtkWidget *labelMovMaquina;
GtkWidget *label_error_datos;
GtkWidget *label_error_datos2;
GtkWidget *nombre1;
GtkWidget *jugadas1;
GtkWidget *ganadas1;
GtkWidget *perdidas1;


GtkWidget *labelnombre;
GtkWidget *labeljugadas;
GtkWidget *labelganadas;
GtkWidget *labelperdidas;



GtkWidget *label_info;

gchar stringJugador1[30];
gchar stringJugador2[30];

gchar stringJugador_aleatorio1[30];
gchar stringJugador_aleatorio2[30];

GtkWidget *boton_seleccionado;
GtkWidget *boton_vacio;

char tablero[N][N];
int peso[N][N];

GtkWidget *imagenes[16][16];
guint i,j;
guint x,y;

int x1 = 0, x2 = 0, z1 = 0, z2 = 0;
// de la maquina...
int fila_actualM=0, fila_nuevaM=0, colum_actualM=0, colum_nuevaM=0;
int Turno = 0, Color = 0, bandera = 0, turnoJugada = 1, bandera2 = 0, bandera3 = 0, bandera4 = 1, turno1 = 5, turno2 = 0, cont = 0, bandera5 = 0, bandera6 = 0
,var1 = 0, puerta = 0, puerta2 = 1, puerta3 = 1, FichaColor = 0, puerta4 = 0;
int reinicio = 0, aux2 = 0;
int bandNombre1 = 0, bandNombre2 = 0, ganoNegras = 0, ganoBlancas = 0;

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


/*Crea el archivo si es que no existe y va guardando la informacion de cada jugador despues de pasar por
la funcion de "revision_ganador" */
void guardarEstadisticas() {
    FILE *archivo = fopen("Estadisticas.txt", "a");

    Jugador jugador;
    jugador.partidas_jugadas = jugador.partidas_ganadas = jugador.partidas_perdidas = 0;

    if (bandera6 == 0) { // cuando se elige (opcion "ELEGIR")
    // si ganó negras, ganoNegras será igual a 1.  --- CASO NEGRAS
		if (ganoNegras != 0 && ((Turno == 1 && Color == 1) || (Turno == 2 && Color == 2))) { // GANADAS
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_jugador1)));
			jugador.partidas_jugadas++;
			jugador.partidas_ganadas++;

		} else if (ganoNegras == 0 && ((Turno == 1 && Color == 1) || (Turno == 2 && Color == 2))){ // PERDIDAS
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_jugador1)));
			jugador.partidas_jugadas++;
			jugador.partidas_perdidas++;
		}

		// si gano blancas sera 1 --- CASO BLANCAS
		if (ganoBlancas != 0 && ((Turno == 1 && Color == 2) || (Turno == 2 && Color == 1)))  { // GANADAS
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_jugador2)));
			jugador.partidas_jugadas++;
			jugador.partidas_ganadas++;

		} else if (ganoBlancas == 0 && ((Turno == 1 && Color == 2) || (Turno == 2 && Color == 1))) { // PERDIDAS
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_jugador2)));
			jugador.partidas_jugadas++;
			jugador.partidas_perdidas++;
		}

    } else { // totalmente aleatorio (opcion "ALEATORIO")
    	if (ganoNegras != 0 && ((Turno == 1 && Color == 1) || (Turno == 2 && Color == 2))) {
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador1)));
			jugador.partidas_jugadas++;
			jugador.partidas_ganadas++;

		} else if (ganoNegras == 0 && ((Turno == 1 && Color == 1) || (Turno == 2 && Color == 2))){
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador1)));
			jugador.partidas_jugadas++;
			jugador.partidas_perdidas++;
		}

    	if (ganoBlancas != 0 && ((Turno == 1 && Color == 2) || (Turno == 2 && Color == 1))) {
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador2)));
			jugador.partidas_jugadas++;
			jugador.partidas_ganadas++;

		} else if (ganoBlancas == 0 && ((Turno == 1 && Color == 2) || (Turno == 2 && Color == 1))){
			sprintf(jugador.nombre, "%s", gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador2)));
			jugador.partidas_jugadas++;
			jugador.partidas_perdidas++;
		}
    }
    actualizarEstadisticas(jugador.nombre, &jugador.partidas_jugadas, &jugador.partidas_ganadas, &jugador.partidas_perdidas);
    //fprintf(archivo, "%s\t\t\t\t\t\t%d\t\t\t\t\t\t\t%d\t\t\t\t\t\t\t%d\n", jugador.nombre, jugador.partidas_jugadas, jugador.partidas_ganadas, jugador.partidas_perdidas);
    fclose(archivo);
}
/* acá se lee el archivo y se guarda el contenido en un vector "vectorContenido" y este se carga en un label
para poder mostrar en ventana la informacion */
void verEstadisticas() {
	 // Abrir el archivo en modo lectura ("r")
	    FILE *archivo = fopen("Estadisticas.txt", "r");

	    // Crear un vector dinámico para almacenar el contenido del archivo
	    char *vectorContenido = NULL;
	    size_t tamanoVector = 0;

	    // Leer el contenido del archivo y almacenarlo en el vector
	    int caracter;
	    while ((caracter = fgetc(archivo)) != EOF) {
	        // Ampliar el tamaño del vector y agregar el carácter
	        vectorContenido = realloc(vectorContenido, tamanoVector + 1);
	        vectorContenido[tamanoVector++] = caracter;
	    }

	    // Asegurar que el vector tenga un carácter nulo al final
	    vectorContenido = realloc(vectorContenido, tamanoVector + 1);
	    vectorContenido[tamanoVector] = '\0';

	    // Imprimir el contenido del vector (que es el contenido del archivo)
	    //printf("\nContenido del archivo:\n%s\n", vectorContenido);

	    gtk_label_set_text(GTK_LABEL(label_info), vectorContenido);

	    // Liberar la memoria del vector
	   	 free(vectorContenido);

	    // Cerrar el archivo
	    fclose(archivo);
}


/*
Esto lo que revisa es si el ganador es "negras" o "blancas"
*/
void revision_ganador () {

	if (bandera5 == 1) { // negras

		if (bandera6 == 0) {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp1 = g_strdup_printf("%s", stringJugador1);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp1);
			g_free(temp1);
			ganoNegras++;      //bien
			ganoBlancas = 0;
			guardarEstadisticas();

		} else {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp3 = g_strdup_printf("%s", stringJugador_aleatorio1);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp3);
			g_free(temp3);
			ganoNegras++;      //bien
			ganoBlancas = 0;
			guardarEstadisticas();

		}
		gtk_widget_show_all (ventana7);
	}
	else if (bandera5 == 2) { // blancas

		if (bandera6 == 0) {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp2 = g_strdup_printf("%s", stringJugador2);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp2);
			g_free(temp2);
			ganoBlancas++;
			ganoNegras = 0;
			guardarEstadisticas();

		} else {
			// imprime el nombre del ganador en la ventana de "victoria"
			gchar *temp4 = g_strdup_printf("%s", stringJugador_aleatorio2);
			gtk_label_set_text(GTK_LABEL(nombre_ganador), temp4);
			g_free(temp4);
			ganoBlancas++;
			ganoNegras = 0;
			guardarEstadisticas();

		}

		gtk_widget_show_all (ventana7);

	}
	gtk_window_set_title (GTK_WINDOW (ventana7),"HOPPITY");
}

// Acá se imprime de forma alternada los nombres de cada jugador.
void imprimirTurnoActualTablero () {

	if (turno1 == 0) {
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador1);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio1);
		}
	} else if (turno1 == 1) {
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador2);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio2);
		}
	} else if (turno2 == 2){
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador1);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio1);
		}
	} else if (turno2 == 3) {
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador2);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio2);
		}
	}
}


/*
 Al apretar el boton "pasar turno" entra acá para que la maquina haga su jugada
*/
void aprieta_pasar_turno () {
	 //movimiento maquina
	if (var1 == 1) {
		turno1 = 1;
		imprimirTurnoActualTablero ();
		// entra en esta dos funciones, hace las revision para el movimiento.
		juegaMaquinaIA (tablero, &fila_actualM, &colum_actualM, &fila_nuevaM, &colum_nuevaM, &FichaColor, &reinicio, &aux2);
		solucionMov2fichas();

		// si son movimientos permitidos, se hacen los cambios...
		tablero[fila_nuevaM][colum_nuevaM] = 'B';
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
		tablero[fila_actualM][colum_actualM] = '.';

		actualizacionDeTablero();
		condicionQuienGana (tablero, &cont, &bandera5);
		revision_ganador(); //revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"
	}
	else if (var1 == 2) {
		turno2 = 2;
		imprimirTurnoActualTablero ();
		// entra en esta dos funciones, hace las revision para el movimiento.
		juegaMaquinaIA (tablero, &fila_actualM, &colum_actualM, &fila_nuevaM, &colum_nuevaM, &FichaColor, &reinicio, &aux2);
		solucionMov2fichas();

		tablero[fila_nuevaM][colum_nuevaM] = 'N';
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_NEGRO);
		tablero[fila_actualM][colum_actualM] = '.';

		actualizacionDeTablero();
		condicionQuienGana (tablero, &cont, &bandera5);
		revision_ganador(); //revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"

	}

	char mensaje[13];
	mensaje[0]= '(';
	mensaje[1]= fila_actualM + '0';
	mensaje[2] = ',';
	mensaje[3] = colum_nuevaM + '0';
	mensaje[4] = ')';
	mensaje[5] = ' ';
	mensaje[6]= 'a';
	mensaje[7] = ' ';
	mensaje[8]= '(';
	mensaje[9] = fila_nuevaM + '0';
	mensaje[10] = ',';
	mensaje[11] = colum_nuevaM + '0';
	mensaje[12] = ')';
	mensaje[13] = '\0';

	gchar *Mensaje = g_strdup_printf("%s", mensaje);

	gtk_label_set_text(GTK_LABEL(labelMovMaquina), Mensaje);
	g_free(Mensaje);

	var1 = 0; // ceramos de nuevo, para que el boton no funcione de seguido, solo debe funcionar despues de que termine el turno el humano
	puerta2 = 1; //habilitamos de vuelta para que el humano haga otro mov permitido
	puerta3 = 1; // habilitamos para volver a hacer mov adyacentes (esto se puso para que al hacer un salto no vuelva a hacer un mov adyacente)
}



/*
Esta es la funcion principal, cada vez que se hace "click" encima de una ficha (la ficha que seleccionaste)
entra en esta funcion y se guardan las coordenas en donde esta esa ficha, y en base a eso se trabaja para realizar
los movimientos por parte del humano
*/
void eventBox(GtkWidget *event_box, GdkEventButton *event, gpointer data) {
	printf ("\n%d, %d y %d, %d\n", x1,x2,z1,z2);

	i = (GUINT_FROM_LE(event->y) / 33); // en "i" se guarda valor de fila actual, 33 pixels tiene la imagen de la ficha
	j = (GUINT_FROM_LE(event->x) / 33); // en "j" se guarda valor de columna actual, 33 pixels tiene la imagen de la ficha

		if (bandera == 0 && bandera2 == 0 && ((Turno == 1 && Color == 1) || (Turno == 1 && Color == 2) || (Turno == 2 && Color == 1) || (Turno == 2 && Color == 2) )) {
			// cuando humano juega con negras, aca la ficha seleccionada se pinta
			if (tablero[i][j] == 'N' && ( (Turno == 1 && Color == 1) || (Turno == 2 && Color == 2) ) ){
				printf ("\nTurno=%d y Color=%d", Turno,Color);
				printf ("\n%c\n", tablero[i][j]);
				turno1 = 0;
				imprimirTurnoActualTablero (); // con esto se alternan los turnos

				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_NEGRA_CLICK);

				x1 = i; // le asignamos antes de modificarse
				x2 = j; // le asignamos antes de modificarse

				if (puerta2 == 1) { // este se vuelve 1 si se ha presionado el boton "pasar turno" (no permite hacer dos o mas movimiento simples adyacentes)
					bandera++;
					printf ("\nBandera pasar turno = %d\n", bandera);
				}

			}// cuando humano juega con blancas, aca la ficha seleccionada se pinta
			else if (tablero[i][j] == 'B' && ( (Turno == 1 && Color == 2) || (Turno == 2 && Color == 1) ) ){
				turno2 = 3;
				imprimirTurnoActualTablero ();

				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),j,i)), FICHA_BLANCA_CLICK);

				x1 = i; // le asignamos antes de modificarse
				x2 = j; // le asignamos antes de modificarse

				if (puerta2 == 1) {
					bandera++;
				}
			}

		} // aca entra despues de seleccionar la ficha a mover, entra para ver donde quieres mover tu ficha
		else if (bandera == 1 && bandera2 == 0 && ((Turno == 1 && Color == 1) || (Turno == 1 && Color == 2) || (Turno == 2 && Color == 1) || (Turno == 2 && Color == 2))) {

			//JUEGA JUMANO CON NEGRAS
			if (Turno == 1 && Color == 1) {

				x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
				y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva

				revisarMovimientosPosibles (&x1, &x2, &z1, &z2, &puerta, &puerta2, &puerta3, &bandera, tablero);
				g_print ("\nfactaul: %d, cactual: %d y fnueva: %d, cnueva:%d, puerta: %d, puerta2: %d, puerta3: %d, %d", x1, x2, z1, z2, puerta, puerta2, puerta3, bandera);

				if (puerta == 1 && puerta2 == 1) { // esta variables se usan para que el humano haga de forma correcta mov simple y saltos multiples

					// puse adrento este cambio, peso no hace bien despues del primer salto multiple ya no permite selec fichas
					tablero[x1][x2] = '.'; // se coloca acá recien el "vacio", antes generaba problemas, con nuestra funcion "revisarMovimientosPosibles"
					var1 = 1; // se le asigna 1, para habilitar el boton "pasar turno"

					if (x1 == x && x2 == y) // esto cambie, porque cuando es "x1 + x2 == x + y", se cumple tambien cuando intenta hacer movimiento en la diagonal " / " (diagonal de abajo hacia arriba)
					{ // esto hace posible seleccionar y des-seleccionar las fichas
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

								actualizacionDeTablero();
								bandera--;
								condicionQuienGana (tablero, &cont, &bandera5);
								revision_ganador(); //revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"

								// con este "if" solucionamos para que haga bien, cuando es saltos multiples o solo un mov adyacente.
								if (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2)){
									puerta2 = 0; // ceramos, para que no haga mov adyacentes 2 o mas veces (para movimientos adyacentes)
								} else {
									puerta2 = 1; // le asignamos 1, si es hay posibilidad de hacer saltos multiples
								}


						}
						else {

								gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
								var1 = 0; // cuando humano haga mov invalido, no funcionará el boton "pasar turno"
						}
				}

			}

			// JUEGA HUMANO CON BLANCAS

			else if (Turno == 1 && Color == 2) {

				x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
				y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva

				revisarMovimientosPosibles (&x1, &x2, &z1, &z2, &puerta, &puerta2, &puerta3, &bandera, tablero);
				//g_print ("\nfactaul: %d, cactual: %d y fnueva: %d, cnueva:%d, puerta: %d, puerta2: %d", x1, x2, z1, z2, puerta, puerta2);

				if (puerta == 1 && puerta2 == 1) { // esta variables se usan para que el humano haga de forma correcta mov simple y saltos multiples

					tablero[x1][x2] = '.'; // se coloca acá recien el "vacio", antes generaba problemas, con nuestra funcion "revisarMovimientosPosibles"
					var1 = 2; // se le asigna 2, para habilitar el boton "pasar turno"

					if (x1 == x && x2 == y) {
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

						actualizacionDeTablero();
						bandera--;
						condicionQuienGana (tablero, &cont, &bandera5);
						revision_ganador(); //revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"

						// con este "if" solucionamos para que haga bien, cuando es saltos multiples o solo un mov adyacente.
						if (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2)){
							puerta2 = 0; // cerramos, para que no haga mov adyacentes 2 o mas veces (para movimientos adyacentes)
						} else {
							puerta2 = 1; // le asignamos 1, si es hay posibilidad de hacer saltos multiples
						}
					}
					else {

						gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
						var1 = 0;
					}

				}
			}

			// JUEGA MAQUINA CON NEGRAS

			else if (Turno == 2 && Color == 1) {

				x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
				y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva

				revisarMovimientosPosibles (&x1, &x2, &z1, &z2, &puerta, &puerta2, &puerta3, &bandera, tablero);

				if (puerta == 1 && puerta2 == 1) { // esta variables se usan para que el humano haga de forma correcta mov simple y saltos multiples

					tablero[x1][x2] = '.'; // se coloca acá recien el "vacio", antes generaba problemas, con nuestra funcion "revisarMovimientosPosibles"
					var1 = 2; // se le asigna 2, para habilitar el boton "pasar turno"

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

						actualizacionDeTablero();
						bandera--;
						condicionQuienGana (tablero, &cont, &bandera5);
						revision_ganador(); //revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"

						// con este "if" solucionamos para que haga bien, cuando es saltos multiples o solo un mov adyacente.
						if (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2)){
							puerta2 = 0; // cerramos, para que no haga mov adyacentes 2 o mas veces (para movimientos adyacentes)
						} else {
							puerta2 = 1; // le asignamos 1, si es hay posibilidad de hacer saltos multiples
						}
					}
					else {

						gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
						var1 = 0;
					}
				}
			}

			// JUEGA MAQUINA CON BLANCAS

			else if (Turno == 2 && Color == 2) {

				x = (GUINT_FROM_LE(event->y) / 33);  // en x se guarda fila nueva
				y = (GUINT_FROM_LE(event->x) / 33);   // en y se guarda columna nueva

				z1 = x; // a donde quiere mover  fila nueva
				z2 = y; // columna nueva

				revisarMovimientosPosibles (&x1, &x2, &z1, &z2, &puerta, &puerta2, &puerta3, &bandera, tablero);

				if (puerta == 1 && puerta2 == 1) { // esta variables se usan para que el humano haga de forma correcta mov simple y saltos multiples

					tablero[x1][x2] = '.'; // se coloca acá recien el "vacio", antes generaba problemas, con nuestra funcion "revisarMovimientosPosibles"
					var1 = 1; // se le asigna 2, para habilitar el boton "pasar turno"

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

							actualizacionDeTablero();
							bandera--;
							condicionQuienGana (tablero, &cont, &bandera5);
							revision_ganador(); //revisa esta funcion y si se cumple, muestra la ventana de "VICTORIA"

							// con este "if" solucionamos para que haga bien, cuando es saltos multiples o solo un mov adyacente.
							if (((pow((z1 - x1), 2) + pow((z2 - x2), 2)) <= 2)){
								puerta2 = 0; // cerramos, para que no haga mov adyacentes 2 o mas veces (para movimientos adyacentes)
							} else {
								puerta2 = 1; // le asignamos 1, si es hay posibilidad de hacer saltos multiples
							}

						}
						else {

								gtk_label_set_text(GTK_LABEL(label_movInvalido), "\nMovimiento invalido\n");
								var1 = 0;
						}
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

			juegaMaquinaIA (tablero, &fila_actualM, &colum_actualM, &fila_nuevaM, &colum_nuevaM, &FichaColor, &reinicio, &aux2);
			solucionMov2fichas();

			tablero[fila_nuevaM][colum_nuevaM] = 'N';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_NEGRO);
			tablero[fila_actualM][colum_actualM] = '.';

			actualizacionDeTablero();
			bandera3 = -1; // le asignamos -1 para que solamente se haga una vez la revision de las condiciones del "if"
			bandera2--; // para que juegue el humano

			turno2 = 3;
			imprimirTurnoActualTablero ();
		}
		else if (bandera3 == 1) {  // si bandera == 1, maquina jugara con blancas (el valor de bandera se cambia cuando se selecciona color de ficha)
			// movimiento maquina blancas

			juegaMaquinaIA (tablero, &fila_actualM, &colum_actualM, &fila_nuevaM, &colum_nuevaM, &FichaColor, &reinicio, &aux2);
			solucionMov2fichas();

			tablero[fila_nuevaM][colum_nuevaM] = 'B';
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(grid_tablero),y,x)), FICHA_BLANCO);
			tablero[fila_actualM][colum_actualM] = '.';

			actualizacionDeTablero();
			bandera3 = -1; // le asignamos -1 para que solamente se haga una vez la revision de las condiciones del "if"
			bandera2--;

			turno1 = 0;
			imprimirTurnoActualTablero ();
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
		g_free(opcion);

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
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador1);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio1);
		}
	} else if (Turno == 1 && Color == 2){
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador2);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio2);
		}
	} else if (Turno == 2 && Color == 1) {
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador1);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio1);
		}
	} else if (Turno == 2 && Color == 2) {
		if (puerta4 == 1){
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador2);
		} else {
			gtk_label_set_text(GTK_LABEL(turno_jugador), stringJugador_aleatorio2);
		}
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
	// esto para que eliga bien la maquina su ficha y haga bien los movimientos
	if (Turno == 1 && Color == 2){FichaColor = 1;} // empieza humano y luego maquina juega negras
	if (Turno == 1 && Color == 1){FichaColor = 2;} // empieza humano y luego maquina juega blancas
	if (Turno == 2 && Color == 1) {FichaColor = 1;} // empieza maquina y luego juega humano con negras
	if (Turno == 2 && Color == 2) {FichaColor = 2;} // empieza maquina y luego juega humano con blancas

	 gtk_widget_show_all (ventana6); //muestra la ventana de inicio
	 gtk_window_set_title (GTK_WINDOW (ventana6),"HOPPITY"); // Cambia titulo de la ventana.

}

// se encarga de que aparezcan los nombres en el tablero
void aprieta_listo_ventana6 (GtkWidget *event_box, GdkEventButton *event, gpointer data)
{
	strncpy (stringJugador_aleatorio1, gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador1)), 15); // guardamos en el puntero lo que se introduce por teclado
	strncpy (stringJugador_aleatorio2, gtk_entry_get_text(GTK_ENTRY(entry_aleatorio_jugador2)), 15);

	// en caso de no ingresar ningun nombre...
	if (strlen(stringJugador_aleatorio1) == 0) {
			//strcpy(stringJugador_aleatorio1, "Jugador Negro");
		bandNombre1 = 0;
	} else {bandNombre1 = 1;}

	if (strlen(stringJugador_aleatorio2) == 0){
		//strcpy(stringJugador_aleatorio2, "Jugador Blanco");
		bandNombre2 = 0;
	} else {bandNombre2 = 1;}

	gchar *temp3 = g_strdup_printf("%s", stringJugador_aleatorio1);
	gtk_label_set_text(GTK_LABEL(jugador_fichanegra), temp3);
	g_free(temp3);

	gchar *temp4 = g_strdup_printf("%s", stringJugador_aleatorio2);
	gtk_label_set_text(GTK_LABEL(jugador_fichablanca), temp4);
	g_free(temp4);

	bandera6 = 1; // para que entre en lo de revisionganador, y aparezca el nombre cuando aprieta aleatorio
	puerta4 = 2; // para agregar los nombres cuando aprieta totalmente aleatorio y no "elegir"

	if (bandNombre1 == 1 && bandNombre2 == 1) {
		 imprimirTurnoActual();
		 if (reinicio == 0){
			iniciartablero (tablero);
			cargarimagenes (tablero);
		}

		 gtk_widget_hide (ventana6);
		 gtk_widget_show_all (tablero_hoppity);
		 gtk_window_set_title (GTK_WINDOW (tablero_hoppity),"HOPPITY"); // Cambia titulo de la ventana.
	}
	else { // te muestra el texto si no se ingresaron datos...
		gchar *error = g_strdup_printf("Error: Debes ingresar los nombres");
		gtk_label_set_text(GTK_LABEL(label_error_datos2), error);
		g_free(error);
	}
}


//al apretar boton humano aparece que se selecciono esa opcion e imprime abajo como la opcion elegida
void aprieta_turno_humano (GtkWidget *event_box, GdkEventButton *event, gpointer data){
	char turno[30] = {"Humano"};
	Turno = 1;
	bandera4 = 0; // en caso de que apriete turno humano, entonces al apretar el boton para que la maquina mueva no va a funcionar...

		gchar *temp1 = g_strdup_printf("%s", turno);
		gtk_label_set_text(GTK_LABEL(label_turno), temp1);
		g_free(temp1);

}


//al apretar boton computadora aparece que se selecciono esa opcion e imprime abajo como la opcion elegida
void aprieta_turno_computadora (){
	char turno[30] = {"Computadora"};
	Turno = 2;
	bandera4 = 1; // para entrar en la funcion de "aprieta_juega_compu_"
	bandera2 = 1; // para que no entre de una a funcion evenBox y obligue a apretar el boton para que empieze maquina

		gchar *temp1 = g_strdup_printf("%s", turno);
		gtk_label_set_text(GTK_LABEL(label_turno), temp1);
		g_free(temp1);
}


//al apretar boton blanco aparece que se selecciono esa opcion e imprime abajo abajo como la opcion elegida
void aprieta_color_blanco (){
	char color[30] = {"Blanca"};
	Color = 2;
	bandera3 = 1;  // esto en caso de que juegue maquina con blancas
	if (Turno == 1){FichaColor = 1;} // si humano elige blancas, maquina revisará solamente fichas negras en la funcion
	if (Turno == 2) {FichaColor = 2;} // si turno es de cumputadora y selecciono ficha blanca
		gchar *temp1 = g_strdup_printf("%s", color);
		gtk_label_set_text(GTK_LABEL(label_color), temp1);
		g_free(temp1);

}

//al apretar boton negro aparece que se selecciono esa opcion e imprime abajo abajo como la opcion elegida
void aprieta_color_negro (){
	char color[30] = {"Negra"};
	Color = 1;
	if (Turno == 1){FichaColor = 2;} // si humano elige negras, maquina revisará solamente fichas blancas rn la funcion
	if (Turno == 2) {FichaColor = 1;} // si turno es de cumputadora y selecciono ficha negra
		gchar *temp1 = g_strdup_printf("%s", color);
		gtk_label_set_text(GTK_LABEL(label_color), temp1);
		g_free(temp1);

}


void aprieta_turno_aleatorio_ventana2(){
	srand (time(NULL));
	Turno = (rand () % 2) + 1;
	 if (Turno == 1){

		 bandera4 = 0; // en caso de que apriete turno humano, entonces al apretar el boton para que la maquina mueva no va a funcionar...

		 char turno[30] = {"Humano"};
		 gchar *temp1 = g_strdup_printf("%s", turno);
		 gtk_label_set_text(GTK_LABEL(label_turno), temp1);
		 g_free(temp1);

	  } else {

		  bandera2 = 1; // para que no entre de una a funcion evenBox y obligue a apretar el boton para que empieze maquina

		  char turno[30] = {"Computadora"};
		  gchar *temp1 = g_strdup_printf("%s", turno);
		  gtk_label_set_text(GTK_LABEL(label_turno), temp1);
		  g_free(temp1);

	 }
}



void aprieta_color_aleatorio_ventana2(){
	srand (time(NULL));
	Color = (rand () % 2) + 1;
	 if (Color == 1){
		 if (Turno == 1){FichaColor = 2;}
		 if (Turno == 2) {FichaColor = 1;} // si turno es de cumputadora y selecciono ficha negra

		char color[30] = {"Negra"};
		gchar *temp1 = g_strdup_printf("%s", color);
		gtk_label_set_text(GTK_LABEL(label_color), temp1);
		g_free(temp1);

	  } else {

		  bandera3 = 1;  // esto en caso de que juegue maquina con blancas
		  if (Turno == 1){FichaColor = 1;}
		  if (Turno == 2) {FichaColor = 2;} // si turno es de cumputadora y selecciono ficha blanca

		  char color[30] = {"Blanca"};
		  gchar *temp1 = g_strdup_printf("%s", color);
		  gtk_label_set_text(GTK_LABEL(label_color), temp1);
		  g_free(temp1);
	 }
}



void aprieta_atras_ventana2(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana2);

		 gtk_widget_show_all (ventana1);
}



// cuando arpieta listo despues de hacer las elecciones...
// al apretar listo, aparecerá el tablero, ya con las configuraciones
void aprieta_listo_ventana2(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	//gtk_widget_hide (ventana2);

	strncpy (stringJugador1, gtk_entry_get_text(GTK_ENTRY(entry_jugador1)), 15); // guardamos en el puntero lo que se introduce por teclado
	strncpy (stringJugador2, gtk_entry_get_text(GTK_ENTRY(entry_jugador2)), 15); // guardamos en el puntero lo que se introduce por teclado

	// en caso de no ingresar ningun nombre...
	if (strlen(stringJugador1) == 0){
		bandNombre1 = 0;
	} else {bandNombre1 = 1;}

	if (strlen(stringJugador2) == 0){
		bandNombre2 = 0;
	} else {bandNombre2 = 1;}

	gchar *temp1 = g_strdup_printf("%s", stringJugador1);
	gtk_label_set_text(GTK_LABEL(jugador_fichanegra), temp1);
	g_free(temp1);

	gchar *temp2 = g_strdup_printf("%s", stringJugador2);
	gtk_label_set_text(GTK_LABEL(jugador_fichablanca), temp2);
	g_free(temp2);
	puerta4 = 1; // para agregar los nombres cuando selecciona turno y ficha

	// aca se revisa si se hizo eleccion de fichas, turno y si agregaron nombre, sino te tira el mensaje de error
	if (bandNombre1 == 1 && bandNombre2 == 1 && Color != 0 && Turno != 0) {
		// para cargar las imagenes en el tablero
		imprimirTurnoActual();
		if (reinicio == 0){
			iniciartablero (tablero);
			cargarimagenes (tablero);
		}


		gtk_widget_hide (ventana2);
		gtk_widget_show_all (tablero_hoppity);
		gtk_window_set_title (GTK_WINDOW (tablero_hoppity),"HOPPITY");
	}
	else { // te muestra el texto si no se ingresaron datos...
		gchar *error = g_strdup_printf("Recuerda elegir turno, color de ficha e ingresar nombres");
		gtk_label_set_text(GTK_LABEL(label_error_datos), error);
		g_free(error);
	}
}


void aprieta_atras_tablero_hoppity(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (tablero_hoppity);

		 gtk_widget_show_all (ventana2);
		 gtk_window_set_title (GTK_WINDOW (ventana2),"HOPPITY");
}

void aprieta_ayuda_tablero_hoppity(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	//gtk_widget_hide (tablero_hoppity);

	gtk_window_set_title (GTK_WINDOW (ventana5),"HOPPITY");
	gtk_widget_show_all (ventana5);

}


void aprieta_cerrar_ventana5(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	gtk_widget_hide (ventana5);

		gtk_widget_show_all (tablero_hoppity);
}

/*
Se reinicia el juego al apretar el boton "JUEGO NUEVO"
entra acá y cera de vuelta las variables...
*/
void aprieta_juego_nuevo () {
	gtk_widget_hide (tablero_hoppity);

	// ceramos las variables tdo de vuelta
	x1 = 0, x2 = 0, z1 = 0, z2 = 0;
	fila_actualM=0, fila_nuevaM=0, colum_actualM=0, colum_nuevaM=0;
	Turno = 0, Color = 0, bandera = 0, turnoJugada = 1, bandera2 = 0, bandera3 = 0, bandera4 = 1, turno1 = 5, turno2 = 0, cont = 0, bandera5 = 0, bandera6 = 0
	,var1 = 0, puerta = 0, puerta2 = 1, puerta3 = 1, FichaColor = 0, puerta4 = 0;
	bandNombre1 = 0, bandNombre2 = 0;
	// esto para que no aparezcan las elecciones anteriores solamente...
	char color[30] = {" "};
	gchar *t1 = g_strdup_printf("%s", color);
	gtk_label_set_text(GTK_LABEL(label_color), t1);
	g_free(t1);

    char turno[30] = {" "};
    gchar *t2 = g_strdup_printf("%s", turno);
    gtk_label_set_text(GTK_LABEL(label_turno), t2);
    g_free(t2);

	iniciartablero (tablero); // se inicializa de vuelta tablero
	actualizacionDeTablero(); // actualizamos
	reinicio = 1, aux2 = 1; // variables que se encargar de cerar tdas las variables que se usan en INTELIGENCIA.c

	 gtk_widget_show_all (ventana4);
	 gtk_window_set_title (GTK_WINDOW (ventana4),"HOPPITY");
}

void aprieta_boton_estadisticas () {
	//verEstadisticas();
	// Llama a la función verEstadisticas pasando las etiquetas individualmente
	verEstadisticas(labelnombre, labeljugadas, labelganadas, labelperdidas);

	 gtk_widget_show_all (ventana_estadisticas);
	 gtk_window_set_title (GTK_WINDOW (ventana_estadisticas),"HOPPITY");
}

void aprieta_boton_cerrarEstadisticas () {
	gtk_widget_hide (ventana_estadisticas);
	gtk_widget_show_all (tablero_hoppity);
}

void aprieta_boton_cerrarVictoria () {
	gtk_widget_hide (ventana7);
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
	    ventana_estadisticas = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_estadisticas"));


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
	    boton_pasar_turno = GTK_WIDGET(gtk_builder_get_object(builder, "boton_pasar_turno"));
	    boton_estadisticas = GTK_WIDGET(gtk_builder_get_object(builder, "boton_estadisticas"));
	    boton_cerrar_victoria = GTK_WIDGET(gtk_builder_get_object(builder, "boton_cerrar_victoria"));

	    boton_inicia_compu = GTK_WIDGET(gtk_builder_get_object(builder, "boton_inicia_compu"));
	    boton_juego_nuevo = GTK_WIDGET(gtk_builder_get_object(builder, "boton_juego_nuevo"));

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
	    labelMovMaquina = GTK_WIDGET(gtk_builder_get_object(builder, "labelMovMaquina"));
	    label_error_datos = GTK_WIDGET(gtk_builder_get_object(builder, "label_error_datos"));
	    label_error_datos2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_error_datos2"));
	    nombre1 = GTK_WIDGET(gtk_builder_get_object(builder, "nombre1"));
	    jugadas1 = GTK_WIDGET(gtk_builder_get_object(builder, "jugadas1"));
	    ganadas1 = GTK_WIDGET(gtk_builder_get_object(builder, "ganadas1"));
	    perdidas1 = GTK_WIDGET(gtk_builder_get_object(builder, "perdidas1"));


	    labelnombre = GTK_WIDGET(gtk_builder_get_object(builder, "labelnombre"));
	    labeljugadas = GTK_WIDGET(gtk_builder_get_object(builder, "labeljugadas"));
	    labelganadas = GTK_WIDGET(gtk_builder_get_object(builder, "labelganadas"));
	    labelperdidas = GTK_WIDGET(gtk_builder_get_object(builder, "labelperdidas"));


		nombre_ganador = GTK_WIDGET(gtk_builder_get_object(builder, "nombre_ganador"));
		label_info = GTK_WIDGET(gtk_builder_get_object(builder, "label_info"));


		// tablero nuevo (por imagenes)
		boton_tablero_atras = GTK_WIDGET(gtk_builder_get_object(builder, "boton_tablero_atras"));
		boton_tablero_ayuda = GTK_WIDGET(gtk_builder_get_object(builder, "boton_tablero_ayuda"));
		boton_tablero_cerrar = GTK_WIDGET(gtk_builder_get_object(builder, "boton_tablero_cerrar"));
		jugador_fichanegra = GTK_WIDGET(gtk_builder_get_object(builder, "jugador_fichanegra"));
		jugador_fichablanca = GTK_WIDGET(gtk_builder_get_object(builder, "jugador_fichablanca"));
		turno_jugador = GTK_WIDGET(gtk_builder_get_object(builder, "turno_jugador"));
		 cerrarEstadisticas = GTK_WIDGET(gtk_builder_get_object(builder, "cerrarEstadisticas"));

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
	    g_signal_connect(boton_tablero_cerrar,"button-press-event", G_CALLBACK(gtk_main_quit), NULL);

	    //ventana5
	    g_signal_connect(boton_ayuda_cerrar,"button-press-event", G_CALLBACK(aprieta_cerrar_ventana5), NULL);

	    //ventana6
	    g_signal_connect(boton_ventana6_listo , "button-press-event", G_CALLBACK(aprieta_listo_ventana6), NULL);
	    // tablero
	    g_signal_connect(boton_inicia_compu,"button-press-event", G_CALLBACK(aprieta_juega_compu), NULL);
	    g_signal_connect(boton_pasar_turno,"button-press-event", G_CALLBACK(aprieta_pasar_turno), NULL);
	    g_signal_connect(boton_juego_nuevo,"button-press-event", G_CALLBACK(aprieta_juego_nuevo), NULL);
	    g_signal_connect(boton_estadisticas,"button-press-event", G_CALLBACK(aprieta_boton_estadisticas), NULL);
		g_signal_connect(cerrarEstadisticas,"button-press-event", G_CALLBACK(aprieta_boton_cerrarEstadisticas), NULL);
		g_signal_connect(boton_cerrar_victoria,"button-press-event", G_CALLBACK(aprieta_boton_cerrarVictoria), NULL);
	    g_signal_connect(eventbox_tablero , "button-press-event", G_CALLBACK(eventBox), NULL);

	    /* make sure that everything, window and label, are visible */
	    gtk_widget_show_all (ventana);

	    /* start the main loop, and let it rest there until the application is closed */
	    gtk_main ();

	    return 0;
 }
