#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "heap.h"

struct heap_sequencial {
    ITEM *vetor[TAM];
    int fim;
};

HEAP *criar_heap(void) {
    HEAP *h = (HEAP *)malloc(sizeof(HEAP));
    if(h != NULL) {
        h->fim = -1;
    }
    return h;
}

bool heap_cheia(HEAP *h) {
    if(h->fim == TAM - 1) return true;
    return false;
}

bool heap_vazia(HEAP *h) {
    if(h->fim == -1) return true;
    return false;
}

void heap_swap(HEAP *h, int i, int j) {
    ITEM *temp = h->vetor[i];
    h->vetor[i] = h->vetor[j];
    h->vetor[j] = temp;
}

void heap_fix_up(HEAP *h) {
    int w = h->fim;
    int pai = (w - 1) / 2;

    while(w > 0 && item_get_chave(h->vetor[w]) > item_get_chave(h->vetor[pai])) {
        heap_swap(h, w, pai);
        w = pai;
        pai = (w - 1) / 2;
    }
}

bool heap_inserir(HEAP *h, ITEM *it) {
    if(h == NULL || it == NULL || heap_cheia(h)) return false;

    h->fim++;
    h->vetor[h->fim] = it;
    
    heap_fix_up(h);

    return true;
}

void heap_fix_down(HEAP *h) {
    int w = 0;
    int x = 2 * w + 1, y = 2 * w + 2;

    while(x <= h->fim) {
        int indice_max = x;
        if(y <= h->fim && item_get_chave(h->vetor[y]) > item_get_chave(h->vetor[x])) {
            indice_max = y;
        }
        if(item_get_chave(h->vetor[w]) >= item_get_chave(h->vetor[indice_max])) break;
        heap_swap(h, w, indice_max);
        w = indice_max;
        x = 2 * w + 1;
        y = 2 * w + 2;
    }
}

ITEM *heap_remover(HEAP *h) {
    if(h == NULL || heap_vazia(h)) return NULL;

    ITEM *it = h->vetor[0];
    
    h->vetor[0] = h->vetor[h->fim];
    h->fim--;
    
    if(h->fim >= 0) {
        heap_fix_down(h);
    }
    
    return it;
}
