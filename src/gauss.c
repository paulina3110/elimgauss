#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int i, j, k;

    for (i = 0; i < mat->r - 1; i++) {
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
