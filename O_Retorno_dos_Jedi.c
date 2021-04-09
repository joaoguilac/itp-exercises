#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** separa(char *str, int *quantidadeTextos){
	char **textoSeparado;
	int cont = 0, i = 0, tamanho = 0;
	
	//Usando alocação dinamica para o vetor textoSeparado
	while (i<strlen(str)){
		if (str[i] == ' ' || str[i] == '\n'){
			tamanho += 1;
		}
		i++;
	}
	textoSeparado = calloc(sizeof(char*), tamanho+1);
	
	char *texto = strtok(str," ");
	while(texto != NULL){		
		textoSeparado[cont] = texto;
		cont ++;
		texto = strtok(NULL," ");
	}
	*quantidadeTextos = cont;
	
	return textoSeparado;
}

char* juntar(char **vetor_strings, int tamanho_vetor){
	int tamanho_final = 0, i;
	char *strings_unidas;
	
	//Fazendo a alocação dinamica do vetor strings_unidas
	for(i=0; i<tamanho_vetor; i++)
		tamanho_final += strlen(vetor_strings[i])+1;
	strings_unidas = calloc(sizeof(char), tamanho_final+1);
	
	strings_unidas[0] = '\0'; //inicializa com uma string vazia
	for(i=0; i<tamanho_vetor; i++){
		strcat(strings_unidas,vetor_strings[i]);
		strcat(strings_unidas," ");
	}
	
	return strings_unidas;
}

char* embaralha(char T[]){
	int S = 5940, k = 0, N = 0, tam = 1, n, i;
	char **E;
	char **M = separa(T, &N);
	E = calloc(sizeof(char*), tam);
	int marcacao[N];
	
	for (i=0; i<N; i++){
		marcacao[i] = 0;
	}
	
	srand(S);
	
	int parar = 0;
	while(parar == 0){
		n = rand();
		E[k] = M[n % N];
		tam += 1;
		E = realloc(E, sizeof(char*) * tam);
		
		marcacao[n % N] += 1;
		
		parar = 1;
		for (i=0; i<N; i++){
			if (marcacao[i] == 0){
				parar = 0;
				break;
			}
		}
		k++;
	}
	
	char *R = juntar(E, k);
	free(M);
	free(E);
	
	return R;
}

int main(){
	char mensagem[502];
	
	scanf("%[^\n]", mensagem);
	
	char *mensagem_embaralhada = embaralha(mensagem);
	
	printf("%s", mensagem_embaralhada);
	
	free(mensagem_embaralhada);
	
	return 0;
}