#ifndef DEQUE_H
    #define DEQUE_H

    #include "item.h"
    #include <stdbool.h>

    typedef struct deque_ DEQUE;

    DEQUE *deque_criar(void);
    void deque_apagar(DEQUE **dq);
    bool deque_inserir_inicio(DEQUE *dq, ITEM *it);
    bool deque_inserir_fim(DEQUE *dq, ITEM *it);
    ITEM *deque_remover_inicio(DEQUE *dq);
    ITEM *deque_remover_fim(DEQUE *dq);
    bool deque_cheio(DEQUE *dq);
    bool deque_vazio(DEQUE *dq);    

#endif