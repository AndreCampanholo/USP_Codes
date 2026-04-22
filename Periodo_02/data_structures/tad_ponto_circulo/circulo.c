#include "circulo.h"
#include "ponto.h"
#include <stdlib.h>
#include <math.h>

struct circulo_ {
    PONTO *centro;
    float raio;
};

CIRCULO *circulo_criar(PONTO *p, float raio) {
    CIRCULO *circ = (CIRCULO *)malloc(1 * sizeof(CIRCULO));
    circ->centro = p;
    circ->raio = raio;
    return circ;
};

void circulo_apagar(CIRCULO *circ) {
    ponto_apagar(circ->centro);
    free(circ);
};

float circulo_area(CIRCULO *circ) {
    return (3.1415 * circ->raio * circ->raio);
};

//optei por implementar a função distância neste arquivo pois é necessário acessar os valores de x e y do centro do circulo, as quais
//podem ser acessadas através deste arquivo diretamente
float distancia(PONTO *p, CIRCULO *circ) {
    float x_ponto = get_ponto_x(p);
    float y_ponto = get_ponto_y(p);
    float x_circ = get_ponto_x(circ->centro);
    float y_circ = get_ponto_y(circ->centro);
    return sqrt(pow((x_ponto - x_circ), 2) + pow((y_ponto - y_circ), 2));
};