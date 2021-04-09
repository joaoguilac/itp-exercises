#include <stdio.h>
#include <string.h>

typedef struct {
   char NOME[20];
   int VALOR;
   int PESO;
   int MARCACAO;
} Item;

void tesouro_maximo(int Q, int pesoMAX, int pesoATUAL, int posicao, int *MAIOR, int *tam1, int *tam2, Item itens[Q], Item combinacao[Q], Item melhor_combinacao[Q]) {
	int i;
	int TOTAL = 0;
	
	//Não aguenta mais peso!
	if(pesoATUAL == pesoMAX || posicao == Q){		
		*tam1 = posicao;
		for(i=0; i<*tam1; i++){
			TOTAL += combinacao[i].VALOR;
		}
		
		if(TOTAL>*MAIOR){
			*tam2 = posicao;
			*MAIOR = TOTAL;
			for(i=0; i<*tam2; i++){
				melhor_combinacao[i] = combinacao[i];
			}
		}
	}
	//Ainda aguenta peso, vamos carregar mais um tesouro!
	else{
		for(i=0; i<Q; i++){
			if(itens[i].MARCACAO == 0 && pesoATUAL+itens[i].PESO <= pesoMAX){
				combinacao[posicao] = itens[i];
				itens[i].MARCACAO = 1;
				posicao++;
				tesouro_maximo(Q, pesoMAX, pesoATUAL+itens[i].PESO, posicao, MAIOR, tam1, tam2, itens, combinacao, melhor_combinacao);
				itens[i].MARCACAO = 0;
				posicao--;
			}
		}
		
		for(i=0; i<*tam1; i++){
			TOTAL += combinacao[i].VALOR;
		}
		
  	    if(TOTAL>*MAIOR){
			*MAIOR = TOTAL;
			for(i=0; i<*tam2; i++){
				melhor_combinacao[i] = combinacao[i];
			}
		}
	}
}

int main() {
	int Q, P, MAIOR = 0;
	
	scanf("%d %d", &Q, &P);
	
	Item itens[Q];
	Item combinacao[Q];
	Item melhor_combinacao[Q];
	
	memset(itens, 0, sizeof(itens));
	memset(combinacao, 0, sizeof(combinacao));
	memset(melhor_combinacao, 0, sizeof(melhor_combinacao));
	
	int i;
	for(i=0; i<Q; i++){
		scanf("%s %d %d", itens[i].NOME, &(itens[i].VALOR), &(itens[i].PESO));
	}
	
	int tam1 = Q, tam2 = Q;
	tesouro_maximo(Q, P, 0, 0, &MAIOR, &tam1, &tam2, itens, combinacao, melhor_combinacao);
	
	if (MAIOR == 0){
		printf("Nada para carregar...\n");
	}
	else {
		printf("Inventario final:\n");
		for(i=0; i<tam2; i++){
			printf("Item: %s\n", melhor_combinacao[i].NOME);
		}
		printf("Valor total: %d\n", MAIOR);
	}
	
	return 0;
}