// variables para guardar las coordenadas y variables que se usan como banderas para hacer los movimientos correctamente
int iniciar1=0, fichaBlanca=0, iniciar2=0, iniciar3=0, iniciar4=0, iniciar5=0, iniciar6=0, iniciar7=0, iniciar8=0, iniciar9=0, iniciar10=0, iniciar11=0
,iniciar12=0, iniciar13=0, iniciar14=0, iniciar15=0, iniciar16=0, iniciar17=0, iniciar18=0, iniciar19=0;

int b1=1, b2=1, b3=1, b4=1, b5=1, b6=1, b7=1, b8=1, b9=1, b10=1, b11=1, b12=1, b13=1, b14=1, b15=1, b16=1, b17=1, b18=1, b19=1; // contadores de pasos
int p = 0, q = 0, q1=0, q2=0, q3=0, q4=0, q5=0, q6=0, q7=0, q8=0, q9=0, q10=0, q11=0, q12=0, q13=0, q14=0, q15=0, q16=0,q17=0, q18=0;
int p1=0, p2=0, p3=0, p4=0, p5=0, p6=0, p7=0, p8=0, p9=0, p10=0, p11=0, p12=0, p13=0, p14=0, p15=0, p16=0, p17=0, p18=0, p19=0;

int fila_actual1=0, fila_actual2=0, fila_actual3=0, fila_actual4=0, fila_actual5=0, fila_actual6=0, fila_actual7=0, fila_actual8=0, fila_actual9=0, fila_actual10=0, fila_actual11=0, fila_actual12=0, fila_actual13=0, fila_actual14=0, fila_actual15=0, fila_actual16=0, fila_actual17=0, fila_actual18=0, fila_actual19=0;
int colum_actual1=0, colum_actual2=0, colum_actual3=0, colum_actual4=0, colum_actual5=0, colum_actual6=0, colum_actual7=0, colum_actual8=0, colum_actual9=0, colum_actual10=0, colum_actual11=0, colum_actual12=0, colum_actual13=0, colum_actual14=0, colum_actual15=0, colum_actual16=0, colum_actual17=0, colum_actual18=0, colum_actual19=0;
int fila_nueva1=0, fila_nueva2=0, fila_nueva3=0, fila_nueva4=0, fila_nueva5=0, fila_nueva6=0, fila_nueva7=0, fila_nueva8=0, fila_nueva9=0, fila_nueva10=0, fila_nueva11=0, fila_nueva12=0, fila_nueva13=0, fila_nueva14=0, fila_nueva15=0, fila_nueva16=0, fila_nueva17=0, fila_nueva18=0, fila_nueva19=0;
int colum_nueva1=0, colum_nueva2=0, colum_nueva3=0, colum_nueva4=0, colum_nueva5=0, colum_nueva6=0, colum_nueva7=0, colum_nueva8=0, colum_nueva9=0, colum_nueva10=0, colum_nueva11=0, colum_nueva12=0, colum_nueva13=0, colum_nueva14=0, colum_nueva15=0, colum_nueva16=0, colum_nueva17=0, colum_nueva18=0, colum_nueva19=0;

int aux1 = 0;

#define N 16

/*
Este se encarga de revisar si los pasos que ha dado la ficha, sea igual a la cantidad de pasos que puede dar durante tdo su recorrido
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
void juegaMaquinaIA (char tablero[N][N], int *fila_actualM, int *colum_actualM, int *fila_nuevaM, int *colum_nuevaM, int *FichaColor) {
	// movimiento, primera ficha
	if (b1 <= 11) {
		if (iniciar1 == 0) {
			if (*FichaColor == 2){ // blancas
				fila_actual1 = 11;
				colum_actual1 = 14;

				*fila_actualM = 11; // se le asigna a una variable puntero a int, para que recuerde y asi usar para el movimiento
				*colum_actualM = 14;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1){ // negras
				fila_actual1 = 15 - 11;
				colum_actual1 = 15 - 14;

				*fila_actualM = 15 - 11; // se le asigna a una variable puntero a int, para que recuerde y asi usar para el movimiento
				*colum_actualM = 15 - 14;
				aux1 = 1; // negras
			}
		} else {
			fila_actual1 = fila_nueva1;
			colum_actual1 = colum_nueva1;

			*fila_actualM = fila_nueva1;
			*colum_actualM = colum_nueva1;
		}


		if ((aux1 == 0 && tablero[fila_actual1][colum_actual1] == 'B' && tablero[fila_actual1 - 1][colum_actual1 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual1][colum_actual1] == 'N' && tablero[fila_actual1 + 1][colum_actual1 + 1] != 'B') ) {
			if (*FichaColor == 2) { // blancas

					fila_nueva1 = fila_actual1 - 1;
					colum_nueva1 = colum_actual1 - 1;

					*fila_nuevaM = fila_actual1 - 1;
					*colum_nuevaM = colum_actual1 - 1;

			} else if (*FichaColor == 1){ // negras

				fila_nueva1 = fila_actual1 + 1;
				colum_nueva1 = colum_actual1 + 1;

				*fila_nuevaM = fila_actual1 + 1;
				*colum_nuevaM = colum_actual1 + 1;

			}

			iniciar1 = 1;
			b1++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual1][colum_actual1] == 'B' && tablero[fila_actual1 - 1][colum_actual1 - 1] == 'N' && tablero[fila_actual1 - 2][colum_actual1 - 2] == '.')
		|| (aux1 == 1 && tablero[fila_actual1][colum_actual1] == 'N' && tablero[fila_actual1 + 1][colum_actual1 + 1] == 'B' && tablero[fila_actual1 + 2][colum_actual1 + 2] == '.')) {
			if (*FichaColor == 2) {

				fila_nueva1 = fila_actual1 - 2;
				colum_nueva1 = colum_actual1 - 2;

				*fila_nuevaM = fila_actual1 - 2;
				*colum_nuevaM = colum_actual1 - 2;

			} else if (*FichaColor == 1) {

				fila_nueva1 = fila_actual1 + 2;
				colum_nueva1 = colum_actual1 + 2;

				*fila_nuevaM = fila_actual1 + 2;
				*colum_nuevaM = colum_actual1 + 2;

			}

			iniciar1 = 1;
			b1++;
			b1++;
			p = 0;

		}else {
			p = 1;  // banderas, para ir intercalando movimientos en caso de que encuentre dos fichas en la diagonal (no podra saltar)
		}

	}
	// movimiento, segunda ficha
	if ((b1 == 12 && b2 <= 11 && q == 1) || (p == 1 && p2 == 0)) { // (p == 1 && p2 == 0) esta parte se usa cuando hay dos fichas en frente
		if (iniciar2 == 0) {
			if (*FichaColor == 2) {
				fila_actual2 = 11;
				colum_actual2 = 15;

				*fila_actualM = 11; // se le asigna a una variable puntero a int, para que recuerde y asi usar para el movimiento
				*colum_actualM = 15;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual2 = 15 - 11;
				colum_actual2 = 15 - 15;

				*fila_actualM = 15 - 11; // se le asigna a una variable puntero a int, para que recuerde y asi usar para el movimiento
				*colum_actualM = 15 - 15;
				aux1 = 1;
			}
		} else {
			fila_actual2 = fila_nueva2;
			colum_actual2 = colum_nueva2;

			*fila_actualM = fila_nueva2;
			*colum_actualM = colum_nueva2;
		}

		if ((aux1 == 0 && tablero[fila_actual2][colum_actual2] == 'B' && tablero[fila_actual2 - 1][colum_actual2 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual2][colum_actual2] == 'N' && tablero[fila_actual2 + 1][colum_actual2 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva2 = fila_actual2 - 1;
				colum_nueva2 = colum_actual2 - 1;

				*fila_nuevaM = fila_actual2 - 1;
				*colum_nuevaM = colum_actual2 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva2 = fila_actual2 + 1;
				colum_nueva2 = colum_actual2 + 1;

				*fila_nuevaM = fila_actual2 + 1;
				*colum_nuevaM = colum_actual2 + 1;
			}

			iniciar2 = 1;
			b2++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual2][colum_actual2] == 'B' && tablero[fila_actual2 - 1][colum_actual2 - 1] == 'N' && tablero[fila_actual2 - 2][colum_actual2 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual2][colum_actual2] == 'N' && tablero[fila_actual2 + 1][colum_actual2 + 1] == 'B' && tablero[fila_actual2 + 2][colum_actual2 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva2 = fila_actual2 - 2;
				colum_nueva2 = colum_actual2 - 2;

				*fila_nuevaM = fila_actual2 - 2;
				*colum_nuevaM = colum_actual2 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva2 = fila_actual2 + 2;
				colum_nueva2 = colum_actual2 + 2;

				*fila_nuevaM = fila_actual2 + 2;
				*colum_nuevaM = colum_actual2 + 2;
			}

			iniciar2 = 1;
			b2++;
			b2++;
			p = 0;

		}else {
			p = 1;
		}
		if (b2 > 11){p2 = 1;} // para que no vuelva a revisar esto (porque cuando llega al lugar en donde se tiene que quedar volvia a mover la ficha hanciendola desaparecer)
	}
	// movimiento, tercera ficha
	if ((b2 == 12 && b3 <= 12 && q1 == 1) || (p == 1 && p3 == 0)) {
		if (iniciar3 == 0) {
			if (*FichaColor == 2) {
				fila_actual3 = 12;
				colum_actual3 = 14;

				*fila_actualM = 12;
				*colum_actualM = 14;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual3 = 15 - 12;
				colum_actual3 = 15 - 14;

				*fila_actualM = 15 - 12;
				*colum_actualM = 15 - 14;
				aux1 = 1;
			}
		} else {
			fila_actual3 = fila_nueva3;
			colum_actual3 = colum_nueva3;

			*fila_actualM = fila_nueva3;
			*colum_actualM = colum_nueva3;
		}

		if ((aux1 == 0 && tablero[fila_actual3][colum_actual3] == 'B' && tablero[fila_actual3 - 1][colum_actual3 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual3][colum_actual3] == 'N' && tablero[fila_actual3 + 1][colum_actual3 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva3 = fila_actual3 - 1;
				colum_nueva3 = colum_actual3 - 1;

				*fila_nuevaM = fila_actual3 - 1;
				*colum_nuevaM = colum_actual3 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva3 = fila_actual3 + 1;
				colum_nueva3 = colum_actual3 + 1;

				*fila_nuevaM = fila_actual3 + 1;
				*colum_nuevaM = colum_actual3 + 1;
			}

			iniciar3 = 1;
			b3++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual3][colum_actual3] == 'B' && tablero[fila_actual3 - 1][colum_actual3 - 1] == 'N' && tablero[fila_actual3 - 2][colum_actual3 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual3][colum_actual3] == 'N' && tablero[fila_actual3 + 1][colum_actual3 + 1] == 'B' && tablero[fila_actual3 + 2][colum_actual3 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva3 = fila_actual3 - 2;
				colum_nueva3 = colum_actual3 - 2;

				*fila_nuevaM = fila_actual3 - 2;
				*colum_nuevaM = colum_actual3 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva3 = fila_actual3 + 2;
				colum_nueva3 = colum_actual3 + 2;

				*fila_nuevaM = fila_actual3 + 2;
				*colum_nuevaM = colum_actual3 + 2;
			}

			iniciar3 = 1;
			b3++;
			b3++;
			p = 0;

		}else {
			p = 1;
		} if (b3 > 12){p3 = 1;}

	}
	// movimiento, cuarta ficha
	if ((b3 == 13 && b4 <= 12 && q2 == 1) || (p == 1 && p4 == 0)) {
		if (iniciar4 == 0) {
			if (*FichaColor == 2) {
				fila_actual4 = 12;
				colum_actual4 = 13;

				*fila_actualM = 12;
				*colum_actualM = 13;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual4 = 15 - 12;
				colum_actual4 = 15 - 13;

				*fila_actualM = 15 - 12;
				*colum_actualM = 15 - 13;
				aux1 = 1; // blancas
			}
		}else {
			fila_actual4 = fila_nueva4;
			colum_actual4 = colum_nueva4;

			*fila_actualM = fila_nueva4;
			*colum_actualM = colum_nueva4;
		}

		if ((aux1 == 0 && tablero[fila_actual4][colum_actual4] == 'B' && tablero[fila_actual4 - 1][colum_actual4 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual4][colum_actual4] == 'N' && tablero[fila_actual4 + 1][colum_actual4 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva4 = fila_actual4 - 1;
				colum_nueva4 = colum_actual4 - 1;

				*fila_nuevaM = fila_actual4 - 1;
				*colum_nuevaM = colum_actual4 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva4 = fila_actual4 + 1;
				colum_nueva4 = colum_actual4 + 1;

				*fila_nuevaM = fila_actual4 + 1;
				*colum_nuevaM = colum_actual4 + 1;
			}

			iniciar4 = 1;
			b4++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual4][colum_actual4] == 'B' && tablero[fila_actual4 - 1][colum_actual4 - 1] == 'N' && tablero[fila_actual4 - 2][colum_actual4 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual4][colum_actual4] == 'N' && tablero[fila_actual4 + 1][colum_actual4 + 1] == 'B' && tablero[fila_actual4 + 2][colum_actual4 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva4 = fila_actual4 - 2;
				colum_nueva4 = colum_actual4 - 2;

				*fila_nuevaM = fila_actual4 - 2;
				*colum_nuevaM = colum_actual4 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva4 = fila_actual4 + 2;
				colum_nueva4 = colum_actual4 + 2;

				*fila_nuevaM = fila_actual4 + 2;
				*colum_nuevaM = colum_actual4 + 2;
			}

			iniciar4 = 1;
			b4++;
			b4++;
			p = 0;

		}else {
			p = 1;
		} if (b4 > 12){p4 = 1;}

	}
	// movimiento, quinta ficha
	if ((b4 == 13 && b5 <= 13 && q3 == 1) || (p == 1 && p5 == 0)) {
		if (iniciar5 == 0) {
			if (*FichaColor == 2) {
				fila_actual5 = 13;
				colum_actual5 = 13;

				*fila_actualM = 13;
				*colum_actualM = 13;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual5 = 15 - 13;
				colum_actual5 = 15 - 13;

				*fila_actualM = 15 - 13;
				*colum_actualM = 15 - 13;
				aux1 = 1;
			}
		}else {
			fila_actual5 = fila_nueva5;
			colum_actual5 = colum_nueva5;

			*fila_actualM = fila_nueva5;
			*colum_actualM = colum_nueva5;
		}

		if ((aux1 == 0 && tablero[fila_actual5][colum_actual5] == 'B' && tablero[fila_actual5 - 1][colum_actual5 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual5][colum_actual5] == 'N' && tablero[fila_actual5 + 1][colum_actual5 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva5 = fila_actual5 - 1;
				colum_nueva5 = colum_actual5 - 1;

				*fila_nuevaM = fila_actual5 - 1;
				*colum_nuevaM = colum_actual5 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva5 = fila_actual5 + 1;
				colum_nueva5 = colum_actual5 + 1;

				*fila_nuevaM = fila_actual5 + 1;
				*colum_nuevaM = colum_actual5 + 1;
			}

			iniciar5 = 1;
			b5++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual5][colum_actual5] == 'B' && tablero[fila_actual5 - 1][colum_actual5 - 1] == 'N' && tablero[fila_actual5 - 2][colum_actual5 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual5][colum_actual5] == 'N' && tablero[fila_actual5 + 1][colum_actual5 + 1] == 'B' && tablero[fila_actual5 + 2][colum_actual5 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva5 = fila_actual5 - 2;
				colum_nueva5 = colum_actual5 - 2;

				*fila_nuevaM = fila_actual5 - 2;
				*colum_nuevaM = colum_actual5 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva5 = fila_actual5 + 2;
				colum_nueva5 = colum_actual5 + 2;

				*fila_nuevaM = fila_actual5 + 2;
				*colum_nuevaM = colum_actual5 + 2;
			}

			iniciar5 = 1;
			b5++;
			b5++;
			p = 0;

		}else{
			p = 1;
		} if (b5 > 13){p5 = 1;}

	}
	// movimiento, sexta ficha
	if ((b5 == 14 && b6 <= 12 && q4 == 1) || (p == 1 && p6 == 0)) {
		if (iniciar6 == 0) {
			if (*FichaColor == 2) {
				fila_actual6 = 13;
				colum_actual6 = 12;

				*fila_actualM = 13;
				*colum_actualM = 12;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual6 = 15 - 13;
				colum_actual6 = 15 - 12;

				*fila_actualM = 15 - 13;
				*colum_actualM = 15 - 12;
				aux1 = 1;
			}
		}else {
			fila_actual6 = fila_nueva6;
			colum_actual6 = colum_nueva6;

			*fila_actualM = fila_nueva6;
			*colum_actualM = colum_nueva6;
		}

		if ((aux1 == 0 && tablero[fila_actual6][colum_actual6] == 'B' && tablero[fila_actual6 - 1][colum_actual6 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual6][colum_actual6] == 'N' && tablero[fila_actual6 + 1][colum_actual6 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva6 = fila_actual6 - 1;
				colum_nueva6 = colum_actual6 - 1;

				*fila_nuevaM = fila_actual6 - 1;
				*colum_nuevaM = colum_actual6 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva6 = fila_actual6 + 1;
				colum_nueva6 = colum_actual6 + 1;

				*fila_nuevaM = fila_actual6 + 1;
				*colum_nuevaM = colum_actual6 + 1;
			}

			iniciar6 = 1;
			b6++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual6][colum_actual6] == 'B' && tablero[fila_actual6 - 1][colum_actual6 - 1] == 'N' && tablero[fila_actual6 - 2][colum_actual6 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual6][colum_actual6] == 'N' && tablero[fila_actual6 + 1][colum_actual6 + 1] == 'B' && tablero[fila_actual6 + 2][colum_actual6 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva6 = fila_actual6 - 2;
				colum_nueva6 = colum_actual6 - 2;

				*fila_nuevaM = fila_actual6 - 2;
				*colum_nuevaM = colum_actual6 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva6 = fila_actual6 + 2;
				colum_nueva6 = colum_actual6 + 2;

				*fila_nuevaM = fila_actual6 + 2;
				*colum_nuevaM = colum_actual6 + 2;
			}

			iniciar6 = 1;
			b6++;
			b6++;
			p = 0;

		}else {
			p = 1;
		} if (b6 > 12){p6 = 1;}

	}
	// movimiento, septima ficha
	if ((b6 == 13 && b7 <= 12 && q5 == 1) || (p == 1 && p7 == 0)) {
		if (iniciar7 == 0) {
			if (*FichaColor == 2) {
				fila_actual7 = 14;
				colum_actual7 = 12;

				*fila_actualM = 14;
				*colum_actualM = 12;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual7 = 15 - 14;
				colum_actual7 = 15 - 12;

				*fila_actualM = 15 - 14;
				*colum_actualM = 15 - 12;
				aux1 = 1;
			}
		}else {
			fila_actual7 = fila_nueva7;
			colum_actual7 = colum_nueva7;

			*fila_actualM = fila_nueva7;
			*colum_actualM = colum_nueva7;
		}

		if ((aux1 == 0 && tablero[fila_actual7][colum_actual7] == 'B' && tablero[fila_actual7 - 1][colum_actual7 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual7][colum_actual7] == 'N' && tablero[fila_actual7 + 1][colum_actual7 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva7 = fila_actual7 - 1;
				colum_nueva7 = colum_actual7 - 1;

				*fila_nuevaM = fila_actual7 - 1;
				*colum_nuevaM = colum_actual7 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva7 = fila_actual7 + 1;
				colum_nueva7 = colum_actual7 + 1;

				*fila_nuevaM = fila_actual7 + 1;
				*colum_nuevaM = colum_actual7 + 1;
			}

			iniciar7 = 1;
			b7++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual7][colum_actual7] == 'B' && tablero[fila_actual7 - 1][colum_actual7 - 1] == 'N' && tablero[fila_actual7 - 2][colum_actual7 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual7][colum_actual7] == 'N' && tablero[fila_actual7 + 1][colum_actual7 + 1] == 'B' && tablero[fila_actual7 + 2][colum_actual7 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva7 = fila_actual7 - 2;
				colum_nueva7 = colum_actual7 - 2;

				*fila_nuevaM = fila_actual7 - 2;
				*colum_nuevaM = colum_actual7 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva7 = fila_actual7 + 2;
				colum_nueva7 = colum_actual7 + 2;

				*fila_nuevaM = fila_actual7 + 2;
				*colum_nuevaM = colum_actual7 + 2;
			}

			iniciar7 = 1;
			b7++;
			b7++;
			p = 0;

		}else {
			p = 1;
		} if (b7 > 12){p7 = 1;}

	}
	// movimiento, octava ficha
	if ((b7 == 13 && b8 <= 11 && q6 == 1) || (p == 1 && p8 == 0)) {
		if (iniciar8 == 0) {
			if (*FichaColor == 2) {
				fila_actual8 = 14;
				colum_actual8 = 11;

				*fila_actualM = 14;
				*colum_actualM = 11;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual8 = 15 - 14;
				colum_actual8 = 15 - 11;

				*fila_actualM = 15 - 14;
				*colum_actualM = 15 - 11;
				aux1 = 1;
			}
		}else {
			fila_actual8 = fila_nueva8;
			colum_actual8 = colum_nueva8;

			*fila_actualM = fila_nueva8;
			*colum_actualM = colum_nueva8;
		}

		if ((aux1 == 0 && tablero[fila_actual8][colum_actual8] == 'B' && tablero[fila_actual8 - 1][colum_actual8 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual8][colum_actual8] == 'N' && tablero[fila_actual8 + 1][colum_actual8 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva8 = fila_actual8 - 1;
				colum_nueva8 = colum_actual8 - 1;

				*fila_nuevaM = fila_actual8 - 1;
				*colum_nuevaM = colum_actual8 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva8 = fila_actual8 + 1;
				colum_nueva8 = colum_actual8 + 1;

				*fila_nuevaM = fila_actual8 + 1;
				*colum_nuevaM = colum_actual8 + 1;
			}

			iniciar8 = 1;
			b8++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual8][colum_actual8] == 'B' && tablero[fila_actual8 - 1][colum_actual8 - 1] == 'N' && tablero[fila_actual8 - 2][colum_actual8 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual8][colum_actual8] == 'N' && tablero[fila_actual8 + 1][colum_actual8 + 1] == 'B' && tablero[fila_actual8 + 2][colum_actual8 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva8 = fila_actual8 - 2;
				colum_nueva8 = colum_actual8 - 2;

				*fila_nuevaM = fila_actual8 - 2;
				*colum_nuevaM = colum_actual8 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva8 = fila_actual8 + 2;
				colum_nueva8 = colum_actual8 + 2;

				*fila_nuevaM = fila_actual8 + 2;
				*colum_nuevaM = colum_actual8 + 2;
			}

			iniciar8 = 1;
			b8++;
			b8++;
			p = 0;

		} else {
			p = 1;
		} if (b8 > 11){p8 = 1;}

	}
	// movimiento, novena ficha
	if ((b8 == 12 && b9 <= 11 && q7 == 1) || (p == 1 && p9 == 0)) {
		if (iniciar9 == 0) {
			if (*FichaColor == 2) {
				fila_actual9 = 15;
				colum_actual9 = 11;

				*fila_actualM = 15;
				*colum_actualM = 11;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual9 = 15 - 15;
				colum_actual9 = 15 - 11;

				*fila_actualM = 15 - 15;
				*colum_actualM = 15 - 11;
				aux1 = 1;
			}
		}else {
			fila_actual9 = fila_nueva9;
			colum_actual9 = colum_nueva9;

			*fila_actualM = fila_nueva9;
			*colum_actualM = colum_nueva9;
		}

		if ((aux1 == 0 && tablero[fila_actual9][colum_actual9] == 'B' && tablero[fila_actual9 - 1][colum_actual9 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual9][colum_actual9] == 'N' && tablero[fila_actual9 + 1][colum_actual9 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva9 = fila_actual9 - 1;
				colum_nueva9 = colum_actual9 - 1;

				*fila_nuevaM = fila_actual9 - 1;
				*colum_nuevaM = colum_actual9 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva9 = fila_actual9 + 1;
				colum_nueva9 = colum_actual9 + 1;

				*fila_nuevaM = fila_actual9 + 1;
				*colum_nuevaM = colum_actual9 + 1;
			}

			iniciar9 = 1;
			b9++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual9][colum_actual9] == 'B' && tablero[fila_actual9 - 1][colum_actual9 - 1] == 'N' && tablero[fila_actual9 - 2][colum_actual9 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual9][colum_actual9] == 'N' && tablero[fila_actual9 + 1][colum_actual9 + 1] == 'B' && tablero[fila_actual9 + 2][colum_actual9 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva9 = fila_actual9 - 2;
				colum_nueva9 = colum_actual9 - 2;

				*fila_nuevaM = fila_actual9 - 2;
				*colum_nuevaM = colum_actual9 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva9 = fila_actual9 + 2;
				colum_nueva9 = colum_actual9 + 2;

				*fila_nuevaM = fila_actual9 + 2;
				*colum_nuevaM = colum_actual9 + 2;
			}

			iniciar9 = 1;
			b9++;
			b9++;
			p = 0;

		} else {
			p = 1;
		} if (b9 > 11){p9 = 1;}

	}
	// movimiento, decima ficha
	if ((b9 == 12 && b10 <= 11 && q8 == 1) || (p == 1 && p10 == 0)) {
		if (iniciar10 == 0) {
			if (*FichaColor == 2) {
				fila_actual10 = 12;
				colum_actual10 = 15;

				*fila_actualM = 12;
				*colum_actualM = 15;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual10 = 15 - 12;
				colum_actual10 = 15 - 15;

				*fila_actualM = 15 - 12;
				*colum_actualM = 15 - 15;
				aux1 = 1;
			}
		}else {
			fila_actual10 = fila_nueva10;
			colum_actual10 = colum_nueva10;

			*fila_actualM = fila_nueva10;
			*colum_actualM = colum_nueva10;
		}

		if ((aux1 == 0 && tablero[fila_actual10][colum_actual10] == 'B' && tablero[fila_actual10 - 1][colum_actual10 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual10][colum_actual10] == 'N' && tablero[fila_actual10 + 1][colum_actual10 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva10 = fila_actual10 - 1;
				colum_nueva10 = colum_actual10 - 1;

				*fila_nuevaM = fila_actual10 - 1;
				*colum_nuevaM = colum_actual10 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva10 = fila_actual10 + 1;
				colum_nueva10 = colum_actual10 + 1;

				*fila_nuevaM = fila_actual10 + 1;
				*colum_nuevaM = colum_actual10 + 1;
			}

			iniciar10 = 1;
			b10++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual10][colum_actual10] == 'B' && tablero[fila_actual10 - 1][colum_actual10 - 1] == 'N' && tablero[fila_actual10 - 2][colum_actual10 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual10][colum_actual10] == 'N' && tablero[fila_actual10 + 1][colum_actual10 + 1] == 'B' && tablero[fila_actual10 + 2][colum_actual10 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva10 = fila_actual10 - 2;
				colum_nueva10 = colum_actual10 - 2;

				*fila_nuevaM = fila_actual10 - 2;
				*colum_nuevaM = colum_actual10 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva10 = fila_actual10 + 2;
				colum_nueva10 = colum_actual10 + 2;

				*fila_nuevaM = fila_actual10 + 2;
				*colum_nuevaM = colum_actual10 + 2;
			}

			iniciar10 = 1;
			b10++;
			b10++;
			p = 0;

		} else {
			p = 1;
		} if (b10 > 11){p10 = 1;}

	}
	// movimiento, ficha 11
	if ((b10 == 12 && b11 <= 12 && q9 == 1) || (p == 1 && p11 == 0)) {
		if (iniciar11 == 0) {
			if (*FichaColor == 2) {
				fila_actual11 = 13;
				colum_actual11 = 15;

				*fila_actualM = 13;
				*colum_actualM = 15;
				aux1 = 0; // blancas
			} else if (*FichaColor == 1) {
				fila_actual11 = 15 - 13;
				colum_actual11 = 15 - 15;

				*fila_actualM = 15 - 13;
				*colum_actualM = 15 - 15;
				aux1 = 1;
			}
		}else {
			fila_actual11 = fila_nueva11;
			colum_actual11 = colum_nueva11;

			*fila_actualM = fila_nueva11;
			*colum_actualM = colum_nueva11;
		}

		if ((aux1 == 0 && tablero[fila_actual11][colum_actual11] == 'B' && tablero[fila_actual11 - 1][colum_actual11 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual11][colum_actual11] == 'N' && tablero[fila_actual11 + 1][colum_actual11 + 1] != 'B')) {
			if (*FichaColor == 2) {
				fila_nueva11 = fila_actual11 - 1;
				colum_nueva11 = colum_actual11 - 1;

				*fila_nuevaM = fila_actual11 - 1;
				*colum_nuevaM = colum_actual11 - 1;
			} else if (*FichaColor == 1) {
				fila_nueva11 = fila_actual11 + 1;
				colum_nueva11 = colum_actual11 + 1;

				*fila_nuevaM = fila_actual11 + 1;
				*colum_nuevaM = colum_actual11 + 1;
			}

			iniciar11 = 1;
			b11++;
			p = 0;

		} else if ((aux1 == 0 && tablero[fila_actual11][colum_actual11] == 'B' && tablero[fila_actual11 - 1][colum_actual11 - 1] == 'N' && tablero[fila_actual11 - 2][colum_actual11 - 2] == '.')
				|| (aux1 == 1 && tablero[fila_actual11][colum_actual11] == 'N' && tablero[fila_actual11 + 1][colum_actual11 + 1] == 'B' && tablero[fila_actual11 + 2][colum_actual11 + 2] == '.')) {
			if (*FichaColor == 2) {
				fila_nueva11 = fila_actual11 - 2;
				colum_nueva11 = colum_actual11 - 2;

				*fila_nuevaM = fila_actual11 - 2;
				*colum_nuevaM = colum_actual11 - 2;
			} else if (*FichaColor == 1) {
				fila_nueva11 = fila_actual11 + 2;
				colum_nueva11 = colum_actual11 + 2;

				*fila_nuevaM = fila_actual11 + 2;
				*colum_nuevaM = colum_actual11 + 2;
			}

			iniciar11 = 1;
			b11++;
			b11++;
			p = 0;

		} else {
			p = 1;
		} if (b11 > 12){p11 = 1;}

	}
	// movimiento, ficha 12
		if ((b11 == 13 && b12 <= 12 && q10 == 1) || (p == 1 && p12 == 0)) {
			if (iniciar12 == 0) {
				if (*FichaColor == 2) {
					fila_actual12 = 13;
					colum_actual12 = 14;

					*fila_actualM = 13;
					*colum_actualM = 14;
					aux1 = 0; // blancas
				} else if (*FichaColor == 1) {
					fila_actual12 = 15 - 13;
					colum_actual12 = 15 - 14;

					*fila_actualM = 15 - 13;
					*colum_actualM = 15 - 14;
					aux1 = 1;
				}
			}else {
				fila_actual12 = fila_nueva12;
				colum_actual12 = colum_nueva12;

				*fila_actualM = fila_nueva12;
				*colum_actualM = colum_nueva12;
			}

			if ((aux1 == 0 && tablero[fila_actual12][colum_actual12] == 'B' && tablero[fila_actual12 - 1][colum_actual12 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual12][colum_actual12] == 'N' && tablero[fila_actual12 + 1][colum_actual12 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva12 = fila_actual12 - 1;
					colum_nueva12 = colum_actual12 - 1;

					*fila_nuevaM = fila_actual12 - 1;
					*colum_nuevaM = colum_actual12 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva12 = fila_actual12 + 1;
					colum_nueva12 = colum_actual12 + 1;

					*fila_nuevaM = fila_actual12 + 1;
					*colum_nuevaM = colum_actual12 + 1;
				}

				iniciar12 = 1;
				b12++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual12][colum_actual12] == 'B' && tablero[fila_actual12 - 1][colum_actual12 - 1] == 'N' && tablero[fila_actual12 - 2][colum_actual12 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual12][colum_actual12] == 'N' && tablero[fila_actual12 + 1][colum_actual12 + 1] == 'B' && tablero[fila_actual12 + 2][colum_actual12 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva12 = fila_actual12 - 2;
					colum_nueva12 = colum_actual12 - 2;

					*fila_nuevaM = fila_actual12 - 2;
					*colum_nuevaM = colum_actual12 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva12 = fila_actual12 + 2;
					colum_nueva12 = colum_actual12 + 2;

					*fila_nuevaM = fila_actual12 + 2;
					*colum_nuevaM = colum_actual12 + 2;
				}

				iniciar12 = 1;
				b12++;
				b12++;
				p = 0;

			} else {
				p = 1;
			} if (b12 > 12){p12 = 1;}

		}
		// movimiento, ficha 13
		if ((b12 == 13 && b13 <= 13 && q11 == 1) || (p == 1 && p13 == 0)) {
			if (iniciar13 == 0) {
				if (*FichaColor == 2) {
					fila_actual13 = 14;
					colum_actual13 = 14;

					*fila_actualM = 14;
					*colum_actualM = 14;
					aux1 = 0; // blancas
				} else if (*FichaColor == 1) {
					fila_actual13 = 15 - 14;
					colum_actual13 = 15 - 14;

					*fila_actualM = 15 - 14;
					*colum_actualM = 15 - 14;
					aux1 = 1;
				}
			}else {
				fila_actual13 = fila_nueva13;
				colum_actual13 = colum_nueva13;

				*fila_actualM = fila_nueva13;
				*colum_actualM = colum_nueva13;
			}

			if ((aux1 == 0 && tablero[fila_actual13][colum_actual13] == 'B' && tablero[fila_actual13 - 1][colum_actual13 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual13][colum_actual13] == 'N' && tablero[fila_actual13 + 1][colum_actual13 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva13 = fila_actual13 - 1;
					colum_nueva13 = colum_actual13 - 1;

					*fila_nuevaM = fila_actual13 - 1;
					*colum_nuevaM = colum_actual13 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva13 = fila_actual13 + 1;
					colum_nueva13 = colum_actual13 + 1;

					*fila_nuevaM = fila_actual13 + 1;
					*colum_nuevaM = colum_actual13 + 1;
				}

				iniciar13 = 1;
				b13++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual13][colum_actual13] == 'B' && tablero[fila_actual13 - 1][colum_actual13 - 1] == 'N' && tablero[fila_actual13 - 2][colum_actual13 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual13][colum_actual13] == 'N' && tablero[fila_actual13 + 1][colum_actual13 + 1] == 'B' && tablero[fila_actual13 + 2][colum_actual13 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva13 = fila_actual13 - 2;
					colum_nueva13 = colum_actual13 - 2;

					*fila_nuevaM = fila_actual13 - 2;
					*colum_nuevaM = colum_actual13 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva13 = fila_actual13 + 2;
					colum_nueva13 = colum_actual13 + 2;

					*fila_nuevaM = fila_actual13 + 2;
					*colum_nuevaM = colum_actual13 + 2;
				}

				iniciar13 = 1;
				b13++;
				b13++;
				p = 0;

			} else {
				p = 1;
			} if (b13 > 13){p13 = 1;}
		}
		// movimiento, ficha 14
		if ((b13 == 14 && b14 <= 12 && q12 == 1) || (p == 1 && p14 == 0)) {
			if (iniciar14 == 0) {
				if (*FichaColor == 2) {
					fila_actual14 = 14;
					colum_actual14 = 13;

					*fila_actualM = 14;
					*colum_actualM = 13;
					aux1 = 0;
				}else if (*FichaColor == 1) {
					fila_actual14 = 15 - 14;
					colum_actual14 = 15 - 13;

					*fila_actualM = 15 - 14;
					*colum_actualM = 15 - 13;
					aux1 = 1;
				}
			}else {
				fila_actual14 = fila_nueva14;
				colum_actual14 = colum_nueva14;

				*fila_actualM = fila_nueva14;
				*colum_actualM = colum_nueva14;
			}

			if ((aux1 == 0 && tablero[fila_actual14][colum_actual14] == 'B' && tablero[fila_actual14 - 1][colum_actual14 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual14][colum_actual14] == 'N' && tablero[fila_actual14 + 1][colum_actual14 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva14 = fila_actual14 - 1;
					colum_nueva14 = colum_actual14 - 1;

					*fila_nuevaM = fila_actual14 - 1;
					*colum_nuevaM = colum_actual14 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva14 = fila_actual14 + 1;
					colum_nueva14 = colum_actual14 + 1;

					*fila_nuevaM = fila_actual14 + 1;
					*colum_nuevaM = colum_actual14 + 1;
				}

				iniciar14 = 1;
				b14++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual14][colum_actual14] == 'B' && tablero[fila_actual14 - 1][colum_actual14 - 1] == 'N' && tablero[fila_actual14 - 2][colum_actual14 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual14][colum_actual14] == 'N' && tablero[fila_actual14 + 1][colum_actual14 + 1] == 'B' && tablero[fila_actual14 + 2][colum_actual14 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva14 = fila_actual14 - 2;
					colum_nueva14 = colum_actual14 - 2;

					*fila_nuevaM = fila_actual14 - 2;
					*colum_nuevaM = colum_actual14 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva14 = fila_actual14 + 2;
					colum_nueva14 = colum_actual14 + 2;

					*fila_nuevaM = fila_actual14 + 2;
					*colum_nuevaM = colum_actual14 + 2;
				}

				iniciar14 = 1;
				b14++;
				b14++;
				p = 0;

			} else {
				p = 1;
			} if (b14 > 12){p14 = 1;}
		}
		// movimiento, ficha 15
		if ((b14 == 13 && b15 <= 12 && q13 == 1) || (p == 1 && p15 == 0)) {
			if (iniciar15 == 0) {
				if (*FichaColor == 2) {
					fila_actual15 = 15;
					colum_actual15 = 13;

					*fila_actualM = 15;
					*colum_actualM = 13;
					aux1 = 0;
				} else if (*FichaColor == 1) {
					fila_actual15 = 15 - 15;
					colum_actual15 = 15 - 13;

					*fila_actualM = 15 - 15;
					*colum_actualM = 15 - 13;
					aux1 = 1;
				}
			}else {
				fila_actual15 = fila_nueva15;
				colum_actual15 = colum_nueva15;

				*fila_actualM = fila_nueva15;
				*colum_actualM = colum_nueva15;
			}

			if ((aux1 == 0 && tablero[fila_actual15][colum_actual15] == 'B' && tablero[fila_actual15 - 1][colum_actual15 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual15][colum_actual15] == 'N' && tablero[fila_actual15 + 1][colum_actual15 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva15 = fila_actual15 - 1;
					colum_nueva15 = colum_actual15 - 1;

					*fila_nuevaM = fila_actual15 - 1;
					*colum_nuevaM = colum_actual15 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva15 = fila_actual15 + 1;
					colum_nueva15 = colum_actual15 + 1;

					*fila_nuevaM = fila_actual15 + 1;
					*colum_nuevaM = colum_actual15 + 1;
				}

				iniciar15 = 1;
				b15++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual15][colum_actual15] == 'B' && tablero[fila_actual15 - 1][colum_actual15 - 1] == 'N' && tablero[fila_actual15 - 2][colum_actual15 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual15][colum_actual15] == 'N' && tablero[fila_actual15 + 1][colum_actual15 + 1] == 'B' && tablero[fila_actual15 + 2][colum_actual15 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva15 = fila_actual15 - 2;
					colum_nueva15 = colum_actual15 - 2;

					*fila_nuevaM = fila_actual15 - 2;
					*colum_nuevaM = colum_actual15 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva15 = fila_actual15 + 2;
					colum_nueva15 = colum_actual15 + 2;

					*fila_nuevaM = fila_actual15 + 2;
					*colum_nuevaM = colum_actual15 + 2;
				}

				iniciar15 = 1;
				b15++;
				b15++;
				p = 0;

			} else {
				p = 1;
			} if (b15 > 12){p15 = 1;}
		}
		// movimiento, ficha 16
		if ((b15 == 13 && b16 <= 11 && q14 == 1) || (p == 1 && p16 == 0)) {
			if (iniciar16 == 0) {
				if (*FichaColor == 2) {
					fila_actual16 = 15;
					colum_actual16 = 12;

					*fila_actualM = 15;
					*colum_actualM = 12;
					aux1 = 0;
				} else if (*FichaColor == 1) {
					fila_actual16 = 15 - 15;
					colum_actual16 = 15 - 12;

					*fila_actualM = 15 - 15;
					*colum_actualM = 15 - 12;
					aux1 = 1;
				}

			}else {
				fila_actual16 = fila_nueva16;
				colum_actual16 = colum_nueva16;

				*fila_actualM = fila_nueva16;
				*colum_actualM = colum_nueva16;
			}

			if ((aux1 == 0 && tablero[fila_actual16][colum_actual16] == 'B' && tablero[fila_actual16 - 1][colum_actual16 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual16][colum_actual16] == 'N' && tablero[fila_actual16 + 1][colum_actual16 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva16 = fila_actual16 - 1;
					colum_nueva16 = colum_actual16 - 1;

					*fila_nuevaM = fila_actual16 - 1;
					*colum_nuevaM = colum_actual16 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva16 = fila_actual16 + 1;
					colum_nueva16 = colum_actual16 + 1;

					*fila_nuevaM = fila_actual16 + 1;
					*colum_nuevaM = colum_actual16 + 1;
				}

				iniciar16 = 1;
				b16++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual16][colum_actual16] == 'B' && tablero[fila_actual16 - 1][colum_actual16 - 1] == 'N' && tablero[fila_actual16 - 2][colum_actual16 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual16][colum_actual16] == 'N' && tablero[fila_actual16 + 1][colum_actual16 + 1] == 'B' && tablero[fila_actual16 + 2][colum_actual16 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva16 = fila_actual16 - 2;
					colum_nueva16 = colum_actual16 - 2;

					*fila_nuevaM = fila_actual16 - 2;
					*colum_nuevaM = colum_actual16 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva16 = fila_actual16 + 2;
					colum_nueva16 = colum_actual16 + 2;

					*fila_nuevaM = fila_actual16 + 2;
					*colum_nuevaM = colum_actual16 + 2;
				}

				iniciar16 = 1;
				b16++;
				b16++;
				p = 0;

			} else {
				p = 1;
			} if (b16 > 11){p16 = 1;}
		}
		// movimiento, ficha 17
		if ((b16 == 12 && b17 <= 12 && q15 == 1) || (p == 1 && p17 == 0)) {
			if (iniciar17 == 0) {
				if (*FichaColor == 2) {
					fila_actual17 = 14;
					colum_actual17 = 15;

					*fila_actualM = 14;
					*colum_actualM = 15;
					aux1 = 0;
				} else if (*FichaColor == 1) {
					fila_actual17 = 15 - 14;
					colum_actual17 = 15 - 15;

					*fila_actualM = 15 - 14;
					*colum_actualM = 15 - 15;
					aux1 = 1;
				}
			}else {
				fila_actual17 = fila_nueva17;
				colum_actual17 = colum_nueva17;

				*fila_actualM = fila_nueva17;
				*colum_actualM = colum_nueva17;
			}

			if ((aux1 == 0 && tablero[fila_actual17][colum_actual17] == 'B' && tablero[fila_actual17 - 1][colum_actual17 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual17][colum_actual17] == 'N' && tablero[fila_actual17 + 1][colum_actual17 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva17 = fila_actual17 - 1;
					colum_nueva17 = colum_actual17 - 1;

					*fila_nuevaM = fila_actual17 - 1;
					*colum_nuevaM = colum_actual17 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva17 = fila_actual17 + 1;
					colum_nueva17 = colum_actual17 + 1;

					*fila_nuevaM = fila_actual17 + 1;
					*colum_nuevaM = colum_actual17 + 1;
				}

				iniciar17 = 1;
				b17++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual17][colum_actual17] == 'B' && tablero[fila_actual17 - 1][colum_actual17 - 1] == 'N' && tablero[fila_actual17 - 2][colum_actual17 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual17][colum_actual17] == 'N' && tablero[fila_actual17 + 1][colum_actual17 + 1] == 'B' && tablero[fila_actual17 + 2][colum_actual17 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva17 = fila_actual17 - 2;
					colum_nueva17 = colum_actual17 - 2;

					*fila_nuevaM = fila_actual17 - 2;
					*colum_nuevaM = colum_actual17 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva17 = fila_actual17 + 2;
					colum_nueva17 = colum_actual17 + 2;

					*fila_nuevaM = fila_actual17 + 2;
					*colum_nuevaM = colum_actual17 + 2;
				}

				iniciar17 = 1;
				b17++;
				b17++;
				p = 0;

			} else {
				p = 1;
			} if (b17 > 12){p17 = 1;}
		}
		// movimiento, ficha 18
		if ((b17 == 13 && b18 <= 13 && q16 == 1) || (p == 1 && p18 == 0)) {
			if (iniciar18 == 0) {
				if (*FichaColor == 2) {
					fila_actual18 = 15;
					colum_actual18 = 15;

					*fila_actualM = 15;
					*colum_actualM = 15;
					aux1 = 0;
				} else if (*FichaColor == 1) {
					fila_actual18 = 15 - 15;
					colum_actual18 = 15 - 15;

					*fila_actualM = 15 - 15;
					*colum_actualM = 15 - 15;
					aux1 = 1;
				}
			}else {
				fila_actual18 = fila_nueva18;
				colum_actual18 = colum_nueva18;

				*fila_actualM = fila_nueva18;
				*colum_actualM = colum_nueva18;
			}

			if ((aux1 == 0 && tablero[fila_actual18][colum_actual18] == 'B' && tablero[fila_actual18 - 1][colum_actual18 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual18][colum_actual18] == 'N' && tablero[fila_actual18 + 1][colum_actual18 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva18 = fila_actual18 - 1;
					colum_nueva18 = colum_actual18 - 1;

					*fila_nuevaM = fila_actual18 - 1;
					*colum_nuevaM = colum_actual18 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva18 = fila_actual18 + 1;
					colum_nueva18 = colum_actual18 + 1;

					*fila_nuevaM = fila_actual18 + 1;
					*colum_nuevaM = colum_actual18 + 1;
				}

				iniciar18 = 1;
				b18++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual18][colum_actual18] == 'B' && tablero[fila_actual18 - 1][colum_actual18 - 1] == 'N' && tablero[fila_actual18 - 2][colum_actual18 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual18][colum_actual18] == 'N' && tablero[fila_actual18 + 1][colum_actual18 + 1] == 'B' && tablero[fila_actual18 + 2][colum_actual18 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva18 = fila_actual18 - 2;
					colum_nueva18 = colum_actual18 - 2;

					*fila_nuevaM = fila_actual18 - 2;
					*colum_nuevaM = colum_actual18 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva18 = fila_actual18 + 2;
					colum_nueva18 = colum_actual18 + 2;

					*fila_nuevaM = fila_actual18 + 2;
					*colum_nuevaM = colum_actual18 + 2;
				}

				iniciar18 = 1;
				b18++;
				b18++;
				p = 0;

		} else {
				p = 1;
			} if (b18 > 13){p18 = 1;}
		}
		// movimiento, ficha 19
		if ((b18 == 14 && b19 <= 12 && q17 == 1) || (p == 1 && p19 == 0)) {
			if (iniciar19 == 0) {
				if (*FichaColor == 2) {
					fila_actual19 = 15;
					colum_actual19 = 14;

					*fila_actualM = 15;
					*colum_actualM = 14;
					aux1 = 0;
				} else if (*FichaColor == 1) {
					fila_actual19 = 15 - 15;
					colum_actual19 = 15 - 14;

					*fila_actualM = 15 - 15;
					*colum_actualM = 15 - 14;
					aux1 = 1;
				}
			}else {
				fila_actual19 = fila_nueva19;
				colum_actual19 = colum_nueva19;

				*fila_actualM = fila_nueva19;
				*colum_actualM = colum_nueva19;
			}

			if ((aux1 == 0 && tablero[fila_actual19][colum_actual19] == 'B' && tablero[fila_actual19 - 1][colum_actual19 - 1] != 'N') || (aux1 == 1 && tablero[fila_actual19][colum_actual19] == 'N' && tablero[fila_actual19 + 1][colum_actual19 + 1] != 'B')) {
				if (*FichaColor == 2) {
					fila_nueva19 = fila_actual19 - 1;
					colum_nueva19 = colum_actual19 - 1;

					*fila_nuevaM = fila_actual19 - 1;
					*colum_nuevaM = colum_actual19 - 1;
				} else if (*FichaColor == 1) {
					fila_nueva19 = fila_actual19 + 1;
					colum_nueva19 = colum_actual19 + 1;

					*fila_nuevaM = fila_actual19 + 1;
					*colum_nuevaM = colum_actual19 + 1;
				}

				iniciar19 = 1;
				b19++;
				p = 0;

			} else if ((aux1 == 0 && tablero[fila_actual19][colum_actual19] == 'B' && tablero[fila_actual19 - 1][colum_actual19 - 1] == 'N' && tablero[fila_actual19 - 2][colum_actual19 - 2] == '.')
					|| (aux1 == 1 && tablero[fila_actual19][colum_actual19] == 'N' && tablero[fila_actual19 + 1][colum_actual19 + 1] == 'B' && tablero[fila_actual19 + 2][colum_actual19 + 2] == '.')) {
				if (*FichaColor == 2) {
					fila_nueva19 = fila_actual19 - 2;
					colum_nueva19 = colum_actual19 - 2;

					*fila_nuevaM = fila_actual19 - 2;
					*colum_nuevaM = colum_actual19 - 2;
				} else if (*FichaColor == 1) {
					fila_nueva19 = fila_actual19 + 2;
					colum_nueva19 = colum_actual19 + 2;

					*fila_nuevaM = fila_actual19 + 2;
					*colum_nuevaM = colum_actual19 + 2;
				}

				iniciar19 = 1;
				b19++;
				b19++;
				p = 0;

			} else {
				p = 1;
			} if (b19 > 12){p19 = 1;}
		}
}
