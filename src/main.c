#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL){
		fprintf(stderr, "Blad wczytania macierzy A.\n");
		return -1;
	}

	if (b == NULL){
	       	fprintf(stderr, "Blad wczytania macierzy A.\n");
		return -2;
	}

	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	if (res == 0){
		x = createMatrix(b->r, 1);

		if (x != NULL) {
			res = backsubst(x,A,b);
			if (res == 0) {
				printToScreen(x);
		  		freeMatrix(x);
			} else {
				fprintf(stderr, "Błąd! Wsteczne podstawienie zakończone niepowodzeniem.\n");
			}
		}else{
			fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
		}
	} else {
		fprintf(stderr, "Błąd! Eliminacja zakończona niepowodzeniem.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return res;
}
