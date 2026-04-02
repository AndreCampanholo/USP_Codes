#include <stdio.h>
#include <stdlib.h>

double *alocar(int dimensao) {
    double *p;
    p = (double *)calloc(dimensao, sizeof(double));

    return p;
}

int main() {
    int dimensao;
    scanf("%d", &dimensao);
    double *n;
    n = alocar(dimensao);

    for(int i = 0; i < dimensao; i++) {
        scanf("%lf", &n[i]);
    }

    for(int j = 0; j < dimensao; j++) {
        printf("%lf ", n[j]);
    }
    printf("\n");


    free(n);
    n = NULL;
}