#include "gauss.h"
#include <math.h>
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int i, j, k;

    for( int i= 0; k < mat->r - 1; i++) {
        int max = i;

        for (int w = i + 1; w < mat->r; w++)
            if (fabs(mat->data[w][i]) > fabs(mat->data[max][i]))
                max = w;

        if (max != i) {
            double *tmp = mat->data[i];
            mat->data[i] = mat->data[max];
            mat->data[max] = tmp;
            double bt = b->data[max][0];
            b->data[max][0] = b->data[i][0];
            b->data[i][0] = bt;
        }

        for (k = i + 1; k < mat->r; k++) {
            double factor = mat->data[k][i] / mat->data[i][i];
            for (j = i; j < mat->c; j++) {
                mat->data[k][j] -= factor * mat->data[i][j];
            }
            b->data[k][0] -= factor * b->data[i][0];
        }
        for (i = 0; i < mat->r; i++) {
            if (fabs(mat->data[i][i]) < 1e-10) {
                fprintf(stderr, "Macierz osobliwa, dzielenie przez 0\n");
                return 1;
            }
        }
    }
    return 0;
}
