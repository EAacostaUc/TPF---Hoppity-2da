#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DeclaracionesHoppity.h"

/* calcula la diferencia entre las partidas ganadas del segundo jugador (b) y las partidas ganadas del primer jugador (a)
 * este retorna un valor negativo si el segundo jugador (el que esta en la segunda fila) tine mas partidas ganadas
 * , retorna un valor positivo si el primer jugador (el que esta en la primera fila) tiene mas partidas ganadas
 * y retorna un valor cero si es que los dos tienen mismas cantidad de partidas ganadas.
 * Esto usamos en la funcion "qsort" para ordenar de forma decreciente
 */
int compararJugadores(const void *a, const void *b) {
    return ((Jugador *)b)->partidas_ganadas - ((Jugador *)a)->partidas_ganadas;
}

void actualizarEstadisticas(const char *nombre, int *jugadas, int *ganadas, int *perdidas) {
    FILE *archivo = fopen("Estadisticas.txt", "r");
    FILE *temporal = fopen("Temp.txt", "w"); // en este archivo se iran copiando el contenido actualizado

    // se asume esta cantidad d jugadores
    Jugador jugadores[100];
    int numJugadores = 0;

    // Leer y almacenar los jugadores desde el archivo
    while (fscanf(archivo, "%s %d %d %d", jugadores[numJugadores].nombre, &jugadores[numJugadores].partidas_jugadas, &jugadores[numJugadores].partidas_ganadas, &jugadores[numJugadores].partidas_perdidas) == 4) {
        numJugadores++;
    }

    fclose(archivo);

    // Agregar o actualizar el jugador actual
    int encontrado = 0;
    for (int i = 0; i < numJugadores; i++) {
        if (strcmp(jugadores[i].nombre, nombre) == 0) { // si el nombre ingresado es igual al nombre que se ingresó anteriormente, aumentan los valores.
            jugadores[i].partidas_jugadas += *jugadas;
            jugadores[i].partidas_ganadas += *ganadas;
            jugadores[i].partidas_perdidas += *perdidas;
            encontrado = 1;
            break;
        }
    }
    // cuando este if sea "falso"
    if (encontrado != 1) { // si no hay coincidencia de nombres, se agrega nomas el nuevo (seria un nuevo jugador en este caso)
        strcpy(jugadores[numJugadores].nombre, nombre);
        jugadores[numJugadores].partidas_jugadas = *jugadas;
        jugadores[numJugadores].partidas_ganadas = *ganadas;
        jugadores[numJugadores].partidas_perdidas = *perdidas;
        numJugadores++;
    }

    // esta funcion se usa para ordenar la informacion de los jugadores, de manera decreciente del valor de partidas ganadas
    qsort(jugadores, numJugadores, sizeof(Jugador), compararJugadores);

    // Escribir los jugadores ordenados en el nuevo archivo "temporal", esto es lo que se ira cargando en el label
    for (int i = 0; i < numJugadores; i++) {

        fprintf(temporal, "%-10s\t\t\t\t\t\t%d\t\t\t\t\t\t\t%d\t\t\t\t\t\t\t%d\n", jugadores[i].nombre, jugadores[i].partidas_jugadas, jugadores[i].partidas_ganadas, jugadores[i].partidas_perdidas);

    }
// \t\t\t\t\t\t
    fclose(temporal);


    // DEspues de hacer la copia de Estadisticas.txt a Temp.txt, cambiamos el nombre de este nuevo por el nombre del archivo anterior y seguir usando ee nombre
    remove("Estadisticas.txt");
    rename("Temp.txt", "Estadisticas.txt");
}

