#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* fromJsonString_int(char vetor_json[], int *tam){
	int *vetor;
	char *numero;
	vetor_json++;
	numero = strtok(vetor_json, ",");
	
	vetor = calloc(sizeof(int), 100);
	
	*tam = 0;
	while(numero != NULL){
		sscanf(numero, "%d", &vetor[*tam]);
		(*tam)++;	
		
		numero = strtok(NULL, ",");
	}	
	
	return vetor;	
}

double* fromJsonString_double(char vetor_json[], int *tam){
	double *vetor;
	char *numero;
	vetor_json++;
	numero = strtok(vetor_json, ",");
		
	vetor = calloc(sizeof(double), 100);

	*tam = 0;
	while(numero != NULL){
		sscanf(numero, "%lf", &vetor[*tam]);
		(*tam)++;	
		
		numero = strtok(NULL, ",");
	}
	
	return vetor;
}

int main(){
	int N, i, j, k;
	char vetor_json[201];
	int *tamanho;
	
	tamanho = calloc(sizeof(int), 1);
	
	scanf("%d\n", &N);
	
	for (i=0; i<N; i++){
		
		fgets(vetor_json, 201, stdin);
		
		if (vetor_json[strlen(vetor_json)-1] == '\n'){
			vetor_json[strlen(vetor_json)-1] = '\0';
		}
		
		int tipo_double = 0;
		for (j=0; j<strlen(vetor_json); j++){
			if (vetor_json[j] == '.'){
				tipo_double = 1;
				break;
			}
		}
		
		if (tipo_double == 1){
			int vazio;
			
			vazio = strcmp(vetor_json, "[]");
			
			if (vazio == 0){
				printf("vetor vazio\n");
			}
			else {
				double *vetor_C = fromJsonString_double(vetor_json, tamanho);
				for (k=0; k<*tamanho; k++){
					printf("%lf ", vetor_C[k]);
				}
				printf("\n");
				free(vetor_C);	
			}
		}
		else {
			int vazio;
			
			vazio = strcmp(vetor_json, "[]");
			
			if (vazio == 0){
				printf("vetor vazio\n");
			}
			else {
				int *vetor_C = fromJsonString_int(vetor_json, tamanho);
				for (k=0; k<*tamanho; k++){
					printf("%d ", vetor_C[k]);
				}
				printf("\n");
				free(vetor_C);	
			}
		}
	}
	
	return 0;
}