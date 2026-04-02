#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


int main (void){
	//definindo o item
	ITEM *item;
	
	//Definindo o dado
	int dado;
	/*typedef struct pessoa{
		int idade;
		char nome[50];
	}Pessoa;*/

	//Dados
	dado = 10;

	/*Pessoa *dado = (Pessoa *) malloc(sizeof(Pessoa));
	dado->idade = 32;
	strcpy(dado->nome,"Eu");*/
	

	//criando o item: chave e componente. O tratamento do item
	//é responsabilidade do cliente.
	item = item_criar(&dado);
	//item = item_criar(dado); // para Pessoa

	//Imprimindo o componente. O cliente é quem decide e sabe
	//o que ele é e como tratá-lo.
	
	int *dados = item_get_dados(item);
	printf("componente: %d", *dados);

	/*Pessoa *pessoa = item_get_dados(item);
	printf("\n=> %s", pessoa->nome);
	printf("\n=> %d", pessoa->idade);*/
	

	
	item_apagar(&item);
	
	return(0);
}