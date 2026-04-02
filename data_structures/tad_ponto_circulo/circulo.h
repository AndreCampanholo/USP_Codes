#ifndef CIRCULO_H
    #define CIRCULO_H

    #include "ponto.h"

    typedef struct circulo_ CIRCULO;
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ);

    //explicação para escolha de implementação no arquivo circulo.c no mesmo
    float distancia(PONTO *p, CIRCULO *circ);

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif


