#ifndef ARV_BIN_H
    #define ARV_BIN_H

    #define FILHO_ESQ 0
    #define FILHO_DIR 1
    #define PRE_ORDEM -1
    #define EM_ORDEM 0
    #define POS_ORDEM 1

    #include <stdbool.h>
    #include "item.h"

    typedef struct arv_bin AB;

    int ab_qtd_nos(AB *ab);
#endif