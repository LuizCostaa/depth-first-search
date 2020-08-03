#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"
#include "Matriz.h"

int main(int argc, char *argv[]) {
	Matriz matrizAdjacencia;
	Pilha pilha;
	int *vetorStatus;
	int tam, verticeInicial, i, temp;
	
	printf("Digite o tamanho da matriz: ");
	scanf("%d", &tam);
	
	inicializa_matriz(&matrizAdjacencia, tam, tam);
	
	modifica_valor_matriz(&matrizAdjacencia, 0, 1, 1);
	modifica_valor_matriz(&matrizAdjacencia, 1, 0, 1);
	modifica_valor_matriz(&matrizAdjacencia, 1, 2, 1);
	modifica_valor_matriz(&matrizAdjacencia, 1, 5, 1);
	modifica_valor_matriz(&matrizAdjacencia, 2, 1, 1);
	modifica_valor_matriz(&matrizAdjacencia, 2, 4, 1);
	modifica_valor_matriz(&matrizAdjacencia, 2, 5, 1);
	modifica_valor_matriz(&matrizAdjacencia, 2, 6, 1);
	modifica_valor_matriz(&matrizAdjacencia, 3, 4, 1);
	modifica_valor_matriz(&matrizAdjacencia, 3, 7, 1);
	modifica_valor_matriz(&matrizAdjacencia, 4, 2, 1);
	modifica_valor_matriz(&matrizAdjacencia, 4, 3, 1);
	modifica_valor_matriz(&matrizAdjacencia, 4, 7, 1);
	modifica_valor_matriz(&matrizAdjacencia, 5, 1, 1);
	modifica_valor_matriz(&matrizAdjacencia, 5, 2, 1);
	modifica_valor_matriz(&matrizAdjacencia, 5, 6, 1);
	modifica_valor_matriz(&matrizAdjacencia, 6, 2, 1);
	modifica_valor_matriz(&matrizAdjacencia, 6, 5, 1);
	modifica_valor_matriz(&matrizAdjacencia, 7, 3, 1);
	modifica_valor_matriz(&matrizAdjacencia, 7, 4, 1);
	modifica_valor_matriz(&matrizAdjacencia, 7, 8, 1);
	modifica_valor_matriz(&matrizAdjacencia, 8, 7, 1);
	
	
	
	mostra_matriz(matrizAdjacencia);
	
	vetorStatus = malloc(sizeof(int) * tam);
	memset(vetorStatus, 0, sizeof(int) * tam);
	
	
	printf("Digite o vertice inicial de busca: ");
	scanf("%d", &verticeInicial);
	verticeInicial = verticeInicial - 1;
		
	inicializa_pilha(&pilha, tam);
	empilha(&pilha, verticeInicial);
	
	while (desempilha(&pilha, &temp) != ERRO_PILHA_VAZIA) {
		
		if (vetorStatus[temp] == 0)	{
			printf("%d \n", temp + 1);
			vetorStatus[temp] = 1;
			for(i=0; i<tam; i++) {
				int value;
				le_valor_matriz(matrizAdjacencia, temp, i, &value);
				
				if(value == 1) {
					if(vetorStatus[i] == 0) {
						empilha(&pilha, i);	
					}
				}
			}
		}		
	} 
	
	desaloca_matriz(&matrizAdjacencia);
	desaloca_pilha(&pilha);
	
	return 0;
}
