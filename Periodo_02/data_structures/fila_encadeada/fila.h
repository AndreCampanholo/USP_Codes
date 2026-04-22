#ifndef FILA_h
    #define FILA_H

    #include "item.h"

    typedef struct fila FILA;
    typedef struct no NO;
    
    FILA *fila_criar(void);
    bool fila_inserir(FILA *f, ITEM *it);
    ITEM *fila_remover(FILA *f);
    ITEM *fila_frente(FILA *f);
    ITEM *fila_atras(FILA *f);
    int fila_tamanho(FILA *f);
    bool fila_vazia(FILA *f);
    bool fila_cheia(FILA *f);
    void fila_apagar(FILA **f);
    void fila_imprimir(FILA *f);

#endif