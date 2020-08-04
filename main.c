#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"
#include "Matriz.h"

int main(int argc, char *argv[]) {
	Matriz matrizAdjacencia;
	Pilha pilha;
	FILE *file;
	int *vetorStatus;
	int tam, verticeInicial, i, j, temp;
	
	printf("Digite o tamanho da matriz: ");
	scanf("%d", &tam);
	
	inicializa_matriz(&matrizAdjacencia, tam, tam);
	
	file = fopen("grafos.txt", "r");
	
	if(file == NULL) {
		printf("Arquivo nao pode ser aberto\n");
		return 0;
	}
	
	for(i=0; i<tam; i++) {
		for(j=0; j<tam; j++) {
			int valorCelula;
			fscanf(file, "%d", &valorCelula);
			if(valorCelula == 1) {
				modifica_valor_matriz(&matrizAdjacencia, i, j, valorCelula);
			}
		}
	}
	
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
