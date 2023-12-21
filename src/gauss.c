#include "gauss.h"
#include <math.h>
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b) {
    int i, j, k, maxRow;
    double maxElem, temp;

if (mat->r != mat->c || mat->r != b->r || b->c != 1) {
        fprintf(stderr, "Błąd nieprawidłowych rozmiarów macierzy\n");
	return 2;
    }

    for (i = 0; i < mat->r - 1; i++) {
        maxRow = i;
        maxElem = fabs(mat->data[i][i]);
        for (k = i + 1; k < mat->r; k++) {
            if (fabs(mat->data[k][i]) > maxElem) {
                maxElem = fabs(mat->data[k][i]);
                maxRow = k;
            }
        }

        if (maxRow != i) {
            for (j = i; j < mat->c; j++) {
                temp = mat->data[i][j];
                mat->data[i][j] = mat->data[maxRow][j];
                mat->data[maxRow][j] = temp;
            }
            temp = b->data[i][0];
            b->data[i][0] = b->data[maxRow][0];
            b->data[maxRow][0] = temp;
        }

        for (k = i + 1; k < mat->r; k++) {
            double factor = mat->data[k][i] / mat->data[i][i];
            for (j = i; j < mat->c; j++) {
                mat->data[k][j] -= factor * mat->data[i][j];
            }
            b->data[k][0] -= factor * b->data[i][0];
        }
    }

    for (i = 0; i < mat->r; i++) {
        if (fabs(mat->data[i][i]) < 1e-10) {
            return 1;
        }
    }

    return 0;
}
