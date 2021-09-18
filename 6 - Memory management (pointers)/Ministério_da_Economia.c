#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int adicionarLinhas(int N, char *linha[N], char string[]){
	int i;
	
	for (i=0; i<N; i++){
		if (linha[i] == NULL){
			linha[i] = malloc(sizeof(char) * strlen(string));
			strcpy(linha[i], string);
			return 1;
		}
		else if (linha[i][strlen(linha[i]) - 1] != '\n'){
			linha[i] = realloc(linha[i], sizeof(char) * (strlen(linha[i]) + 10));
			strcat(linha[i], string);
			return 1;
		}
	}
	
	return 0;
}

void imprimirLinhas(int N, char *linha[]){
	int i;
	
	for (i=0; i<N; i++)
		printf("%s", linha[i]);
}

void liberarLinhas(int N, char *linha[]){
	int i;
	
	for (i=0; i<N; i++)
		free(linha[i]);
}

int main(){
  char str[10];
  int N, i;
  scanf("%d\n", &N);
  char *linhas[N];
  
  for(i=0; i<N; i++)
    linhas[i]=NULL;
  
  do{
    fgets(str,10,stdin);
  }while(adicionarLinhas(N, linhas, str));

  printf("Texto liberado pelo Ministro\n");
  imprimirLinhas(N, linhas);
  
  liberarLinhas(N, linhas);
  return 0;
}