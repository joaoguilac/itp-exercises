#include <stdio.h>

int main() {
	int saque;
	int valor;
	int notas;
	
	/* Notas: 100, 50, 20, 10, 5, 2
	Moeda: 1 */
	
	scanf("%i", &saque);
	valor = saque;
	
	if (valor >= 100) {
		notas = valor/100;
		printf("%i nota(s) de 100 \n", notas);
		valor = valor - notas * 100;
	}
	if (valor >= 50) {
		notas = valor/50;
		printf("%i nota(s) de 50 \n", notas);
		valor = valor - notas * 50;
	}
	if (valor >= 20) {
		notas = valor/20;
		printf("%i nota(s) de 20 \n", notas);
		valor = valor - notas * 20;
	}
	if (valor >= 10) {
		notas = valor/10;
		printf("%i nota(s) de 10 \n", notas);
		valor = valor - notas * 10;
	}
	if (valor >= 5) {
		notas = valor/5;
		printf("%i nota(s) de 5 \n", notas);
		valor = valor - notas * 5;
	}
	if (valor >= 2) {
		notas = valor/2;
		printf("%i nota(s) de 2 \n", notas);
		valor = valor - notas * 2;
	}
	if (valor >= 1) {
		printf("1 moeda(s) de 1");
	}		
	
	return 0;
}