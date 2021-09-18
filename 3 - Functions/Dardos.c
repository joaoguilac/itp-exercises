#include <stdio.h>

double calcula_distancia(double, double, double, double);
int calcula_pontuacao(double, double, int);

int main() {
	double p_x, p_y, q_x, q_y, distancia_1, distancia_2;
	double aux_1, aux_2;
	int i, pontuacao = 0;
	
	for (i = 0; i < 10; i++) {
		scanf(" %lf %lf", &p_x, &p_y);
		distancia_1 = calcula_distancia(p_x, p_y, 0, 0);
		if (i == 0) {
			distancia_2 = 4;
		}
		else {
			distancia_2 = calcula_distancia(p_x, p_y, aux_1, aux_2);
		}
		pontuacao += calcula_pontuacao(distancia_1, distancia_2, i);
		aux_1 = p_x;
		aux_2 = p_y;
	}
	
	printf("%d\n", pontuacao);
	
	return 0;
}

double calcula_distancia(double p_x, double p_y, double q_x, double q_y) {
	return sqrt((p_x - q_x)*(p_x - q_x) + (p_y - q_y)*(p_y - q_y)); 
}  

int calcula_pontuacao(double distancia_1, double distancia_2, int i) {
	int retorno;
	
	//Cálculo das distâncias para o centro do dardo. (PONTUAÇÃO PRINCIPAL)
	if (distancia_1 >= 0 && distancia_1 <= 1) {
		retorno = 10; 
	}
	else if (distancia_1 > 1 && distancia_1 <= 2) {
		retorno = 6;
	}
	else if (distancia_1 > 2 && distancia_1 <= 3) {
		retorno = 4;
	}
	else {
		retorno = 0;
	}
	
	//Cálculo das distâncias para a última jogada. (PONTUAÇÃO BÔNUS)
	if (distancia_2 >= 0 && distancia_2 <= 1) {
		retorno += 5; 
	}
	else if (distancia_2 > 1 && distancia_2 <= 2) {
		retorno += 3;
	}
	else if (distancia_2 > 2 && distancia_2 <= 3) {
		retorno += 2;
	}
	else {
		retorno += 0;
	}
	
	return retorno;
}