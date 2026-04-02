#include "ponto.h"
#include <stdlib.h>

struct  ponto_ {
    float x, y;
};

PONTO *ponto_criar(float x, float y) {
    PONTO *p = (PONTO *)malloc(1 * sizeof(PONTO)); 
    p->x = x;
    p->y = y;
    return p;
};

void ponto_apagar(PONTO *p) {
    free(p);
}

//função implementada para obter o x do ponto desejado
float get_ponto_x(PONTO *p) {
    return p->x;
};

//função implementada para obter o y do ponto desejado
float get_ponto_y(PONTO *p) {
    return p->y;
}

//ambas as funções get_ponto são utilizadas na função distância que está no arquivo circulo.c, 
//portanto foi adicionado o include do ponto.h no mesmo

