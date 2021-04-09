#include <stdio.h>
#include <stdlib.h>

/*
@brief gera um número aleatório no intervalo [min,max]
@param min o número minimo no range
@param max o número máximo no range
@return um número aleatório no intervalo [min,max]
*/
int rand_int_range(int min, int max){
   int range = max - min + 1;
   return min + rand()%range;
}

int* criarVetorAleatorio(int tam, int min, int max){
	int *vetor_val, i;
	
	vetor_val = calloc(sizeof(int), tam+3);
	
	vetor_val[0] = tam;
	vetor_val[1] = min;
	vetor_val[2] = max;
	
	for (i=3; i<tam+3; i++){
		vetor_val[i] = rand_int_range(min, max);
	}	
	
	return vetor_val;
}

int* criarHistograma(int *vetor_val){
	int *vetor_hist, cont1 = vetor_val[1], tam_aux = 1, i, j;
	
	while (cont1 != vetor_val[2]){
		cont1++;
		tam_aux++;
	}
	
	vetor_hist = calloc(sizeof(int), tam_aux+2);
	
	vetor_hist[0] = vetor_val[1];
	vetor_hist[1] = vetor_val[2];
	
	int vetor_aux[tam_aux];
	cont1 = vetor_val[1];
	for (i=0; i<tam_aux; i++){
		vetor_aux[i] = cont1;
		cont1++;
	}
	
	int pos_hist = 2, tam_val = vetor_val[0]+3;
	for (i=0; i<tam_aux; i++){
		int cont2 = 0;
		
		for (j=3; j<tam_val; j++){
			if (vetor_aux[i] == vetor_val[j]){
				cont2++;
			}
		}
		
		vetor_hist[pos_hist] = cont2;
		pos_hist++;
	}
	
	return vetor_hist;
}

float* criarPorcentagens(int *vetor_hist){
	float *vetor_porcentagem;
	int cont = vetor_hist[0], tam_perc = 1, total = 0, i;
	
	while (cont != vetor_hist[1]){
		cont++;
		tam_perc++;
	}
	
	vetor_porcentagem = calloc(sizeof(float), tam_perc);
	
	for (i=2; i<tam_perc+2; i++){
		total += vetor_hist[i];
	}
	
	int pos_perc = 0;
	for (i=2; i<tam_perc+2; i++){
		vetor_porcentagem[pos_perc] = (float)(vetor_hist[i]*100) / total;
		pos_perc++;
	}
	
	return vetor_porcentagem;
}

void imprimePorcentagens(float *vetor_porcentagem, int *vetor_hist){
	int cont = vetor_hist[0], pos_hist = 2, pos_perc = 0;
	
	printf("Valor |Qtdade |Porcent\n");
	
	while (cont != vetor_hist[1]+1){
		printf("%d |%d |%.2f%%\n", cont, vetor_hist[pos_hist], vetor_porcentagem[pos_perc]);
		cont++;
		pos_perc++;
		pos_hist++;
	}
}

void liberar(int *vetor_val, float *vetor_porcentagem, int *vetor_hist){
	free(vetor_val);
	free(vetor_porcentagem);
	free(vetor_hist);
}

int main(){
   int tamanho, maximo, minimo;
   scanf("%d", &tamanho);
   scanf("%d %d", &minimo, &maximo);
   int *valores = criarVetorAleatorio(tamanho, minimo, maximo);
   int *histograma = criarHistograma(valores);
   float *porcentagens = criarPorcentagens(histograma);
   imprimePorcentagens(porcentagens, histograma);
   liberar(valores, porcentagens, histograma);
   return 0;
}