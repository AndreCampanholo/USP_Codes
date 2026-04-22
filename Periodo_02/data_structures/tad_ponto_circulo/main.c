#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"
#include <math.h>

int main() {
    float ponto_x, ponto_y, circ_x, circ_y, circ_raio;

    scanf("%f %f", &ponto_x, &ponto_y);
    scanf("%f %f %f", &circ_x, &circ_y, &circ_raio);

    PONTO *p = ponto_criar(ponto_x, ponto_y);
    PONTO *centro = ponto_criar(circ_x, circ_y);
    CIRCULO *circ = circulo_criar(centro, circ_raio);

    float dist = distancia(p, circ);

    if(dist > circ_raio) {
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    } else if(fabs(dist - circ_raio) < 1e-6) {
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
    } else {
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    }

    ponto_apagar(p);
    circulo_apagar(circ);

    return 0;
}