#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 301

typedef struct {
	unsigned int *array;
	unsigned int size;
} IntArray;

typedef struct {
	IntArray integer;
	IntArray fractional;
	int signal;
	unsigned int exp;
} BigFloat;

void readline(char line[MAX_LINE]) {
	fgets(line, 301, stdin);
	
	if (line[strlen(line)-1] == '\n'){
		line[strlen(line)-1] = '\0';
	}
}

BigFloat strToBigFloat(char line[MAX_LINE]) {
	int i, j, tam_int=1, tam_frac=1, parar;
	char *parte, aux[10] = {0};
	BigFloat retorno;
	
	retorno.integer.array = calloc(sizeof(unsigned int), tam_int);
	retorno.fractional.array = calloc(sizeof(unsigned int), tam_frac);
	
	//Armazenando o sinal do número
	if (line[0] == '-'){
		retorno.signal = -1;
	}
	else {
		retorno.signal = 1;
	}
	
	//Caso não tenha a parte inteira do número da entrada
	parte = strtok(line, "-");
	if (parte[0] == '.'){
		char zero1[strlen(parte)+1];
		strcpy(zero1, "0");
		strcat(zero1, parte);
		strcpy(line, zero1);
	}
	
	//Caso não tenha a parte fracionária do número da entrada
	if (line[strlen(line)-1] == '.'){
		strcat(line, "0");
	}
	
	parte = strtok(line, "-.");
	i=strlen(parte), j=0, parar=0;
	//Armazenando o vetor da parte inteira
	while(parar == 0) {
		i -= 9;
		if (i <= 0){
			i=0;
			parar=1;
		}
		strncpy(aux, &parte[i], 9);
		retorno.integer.array[j] = atoi(aux);
		parte[i] = '\0';
		j++;
		
		tam_int++;
		retorno.integer.array = realloc(retorno.integer.array, sizeof(unsigned int) * tam_int);		
	}
	retorno.integer.size = tam_int-1;
	
	for(i=0; i<10; i++){
		aux[i] = '\0';
	}
	
	parte = strtok(NULL, "-.");
	i=0, retorno.exp = 0;
	//Contando o valor do expoente do número fracionário
	if (strlen(parte) > 1){
		while(parte[i] == '0') {
			retorno.exp++;
			i++;
		}
	}
	
	i=strlen(parte), j=0, parar=0;
	//Armazenando o vetor da parte fracionária
	while(parar == 0) {
		i -= 9;
		if (i <= 0){
			i=0;
			parar=1;
		}
		strncpy(aux, &parte[i], 9);
		//Tirando os zeros do final da parte fracionária
		if (j == 0){
			int k = strlen(aux)-1;
			while(1) {
				if (aux[k] == '0'){
					aux[k] = '\0';
					k--;
				}
				else {
					break;
				}
			}
		}
		retorno.fractional.array[j] = atoi(aux);
		parte[i] = '\0';
		j++;
		
		tam_frac++;
		retorno.fractional.array = realloc(retorno.fractional.array, sizeof(unsigned int) * tam_frac);
	}
	retorno.fractional.size = tam_frac-1;
	
	return retorno;
}

void printBigFloat(BigFloat bf) {
	int i, tam_int = bf.integer.size, tam_frac = bf.fractional.size, expo = bf.exp;
	
	//Impressão do sinal
	if (bf.signal == -1){
		printf("-");
	}
	//Impressão da parte inteira
	printf("%u", bf.integer.array[tam_int-1]);
	for(i=tam_int-2; i>=0; i--){
		printf("%09u", bf.integer.array[i]);
	}
	//Separação da parte inteira da parte fracionária
	printf(".");
	//Impressão da parte fracionária
	for(i=0; i<expo; i++){
		printf("0");
	}
	printf("%u", bf.fractional.array[tam_frac-1]);
	for(i=tam_frac-2; i>=0; i--){
		printf("%09u", bf.fractional.array[i]);
	}
	printf("\n");
}

int main() {
    char line[MAX_LINE];
    readline(line);
    BigFloat bf = strToBigFloat(line);
    printBigFloat(bf);
    printf("%i %u %u %u\n",
        bf.signal,
        bf.exp,
        bf.integer.array[bf.integer.size - 1],
        bf.fractional.array[bf.fractional.size - 1]
    );
    return 0;
}