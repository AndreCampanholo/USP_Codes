#ifndef LISTA_H
    #define LISTA_H

    #include "item.h"

    typedef struct lista LISTA;

    LISTA *lista_criar(bool ordenada);
    void lista_apagar(LISTA **l);
    bool lista_inserir(LISTA *l, ITEM *it);
    

#endif