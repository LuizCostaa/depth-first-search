#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"
#include "Matriz.h"

int main(int argc, char *argv[]) {
	Matriz matrizAdjacencia;
	Pilha pilha;
	int *vetorStatus;
	int tam, verticeInicial, i;
	
	printf("Digite o tamanho da matriz: ");
	scanf("%d", &tam);
	
	inicializa_matriz(&matrizAdjacencia, tam, tam);
	
	modifica_valor_matriz(&matrizAdjacencia, 1, 2, 1);
	modifica_valor_matriz(&matrizAdjacencia, 2, 1, 1);
	modifica_valor_matriz(&matrizAdjacencia, 2, 3, 1);
	modifica_valor_matriz(&matrizAdjacencia, 2, 6, 1);
	modifica_valor_matriz(&matrizAdjacencia, 3, 2, 1);
	modifica_valor_matriz(&matrizAdjacencia, 3, 5, 1);
	modifica_valor_matriz(&matrizAdjacencia, 3, 6, 1);
	modifica_valor_matriz(&matrizAdjacencia, 3, 7, 1);
	modifica_valor_matriz(&matrizAdjacencia, 4, 5, 1);
	modifica_valor_matriz(&matrizAdjacencia, 4, 8, 1);
	modifica_valor_matriz(&matrizAdjacencia, 5, 3, 1);
	modifica_valor_matriz(&matrizAdjacencia, 5, 4, 1);
	modifica_valor_matriz(&matrizAdjacencia, 5, 8, 1);
	modifica_valor_matriz(&matrizAdjacencia, 6, 2, 1);
	modifica_valor_matriz(&matrizAdjacencia, 6, 3, 1);
	modifica_valor_matriz(&matrizAdjacencia, 6, 7, 1);
	modifica_valor_matriz(&matrizAdjacencia, 7, 3, 1);
	modifica_valor_matriz(&matrizAdjacencia, 7, 6, 1);
	modifica_valor_matriz(&matrizAdjacencia, 8, 4, 1);
	modifica_valor_matriz(&matrizAdjacencia, 8, 5, 1);
	modifica_valor_matriz(&matrizAdjacencia, 8, 9, 1);
	modifica_valor_matriz(&matrizAdjacencia, 9, 8, 1);
	
	mostra_matriz(matrizAdjacencia);
	
	
	
	return 0;
}
