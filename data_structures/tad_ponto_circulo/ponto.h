#ifndef PONTO_H
    #define PONTO_H
	#include <stdbool.h>
	
    typedef struct ponto_ PONTO;
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y);

    //explicação para escolha de implementação no arquivo ponto.c no mesmo
    float get_ponto_x(PONTO *p);
    //explicação para escolha de implementação no arquivo ponto.c no mesmo
    float get_ponto_y(PONTO *p);

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif





