#include <stdio.h>
#include "backsubst.h"


/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int r = mat->r;
	int c = mat->c;

    	if (r != c) {
        	fprintf(stderr, "Blad: Macierz nie jest kwadratowa.\n");
        	return 2;
    	}

    	for (int i = r-1; i >= 0; i--){

        	if (mat->data[i][i] == 0) {
        	    fprintf(stderr, "Blad: Dzielenie przez 0 (element na diagonali = 0).\n");
        	    return 1;
       	 	}

	        double s = 0;
	        for (int j = i+1; j < r; j++) {
        	    s += mat->data[i][j] * x->data[j][0];
       	 	}
        	x->data[i][0] = (b->data[i][0] - s) / mat->data[i][i];
	}

	return 0;
}


