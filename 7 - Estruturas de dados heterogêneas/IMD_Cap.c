#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_cartela;
    int tam_cartela;
    int *numeros;
    int *marcacao;
} Cartela;

void inicializar_cartela(Cartela* endereco, int T, int N, int M) {
	int i, j, numero;
	
	endereco->numeros = calloc(N, sizeof(int));
	endereco->marcacao = calloc(N, sizeof(int));
	srand(T);
	
	for(i=0; i<N; i++){
		int repeat=0;
		numero = rand()%M + 1;
		
		for(j=0; j<N; j++){
			if (numero == endereco->numeros[j]){
				repeat=1;
				break;
			}
		}
		
		if (repeat == 1){
			i--;
		}
		else {
			endereco->numeros[i] = numero;
		}
	}
}

int numero_sorteado(Cartela* endereco, int number) {
	int i, tam = endereco->tam_cartela, bingo=1;
	
	for(i=0; i<tam; i++){
		if (endereco->numeros[i] == number){
			endereco->marcacao[i] = 1;
		}
	}
	
	for(i=0; i<tam; i++){
		if (endereco->marcacao[i] == 0){
			bingo = 0;
			break;
		}
	}
	
	if (bingo == 0){
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int N, M, S, id, player=0;
	char entrada[16];
	Cartela *cartela = NULL;
	
	scanf("%d %d %d", &N, &M, &S);
	//Inicialização das cartelas
	while(1){
		fgets(entrada, 16, stdin);
		if (entrada[strlen(entrada)-1] == '\n'){
			entrada[strlen(entrada)-1] = '\0';
		}
		
		//Se o jogo tiver começado
		if (strcmp(entrada, "Comecou o jogo!") == 0){
			break;
		}
		//Senão, continua "criando" cartelas
		else {
			player++;
			cartela = realloc(cartela, sizeof(Cartela) * player);
			id = atoi(entrada);
			cartela[player-1].id_cartela = id;
			cartela[player-1].tam_cartela = N;
			
			inicializar_cartela(&cartela[player-1], id, N, M);
		}
	}
	//Bingo
	int i, j, k, numero, bingo=0, sorteados[M];
	srand(S);
	//Zerando o vetor dos números sorteados
	for(i=0; i<M; i++){
		sorteados[i] = 0;
	}
	//Sorteando os números
	for(i=0; i<M; i++){
		int repeat=0;
		numero = rand()%M + 1;
		
		for(j=0; j<M; j++){
			if (numero == sorteados[j]){
				repeat=1;
			}
		}
		
		if (repeat == 1){
			i--;
		}
		else {
			sorteados[i] = numero;
			for(j=0; j<player; j++){
				bingo = numero_sorteado(&cartela[j], numero);
				if (bingo == 1){
					//Impressão dos números sorteados
					for(k=0; k<=i; k++){
						printf("%d ", sorteados[k]);
					}
					printf("\n");
					//Impressão da cartela
					printf("Bingo! Cartela %d:", cartela[j].id_cartela);
					for(k=0; k<N; k++){
						printf(" %d", cartela[j].numeros[k]);
					}
					break;
				}
			}
			
			if (bingo == 1){
				break;
			}
		}
	}
	
	return 0;
}