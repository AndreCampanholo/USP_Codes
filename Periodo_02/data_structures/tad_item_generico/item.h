#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdbool.h>

	typedef struct item ITEM;

	ITEM *item_criar(void *dado);
	bool item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	void *item_get_dados(ITEM *item);
	bool item_set_dados(ITEM *item, int chave);

#endif