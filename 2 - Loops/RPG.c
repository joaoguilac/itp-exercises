#include <stdio.h>

int main() {
	int N, V, AT;
	char J;
	char CONTROLE;
	int A = 10, I = 10, R = 6, W = 8, S = 4, C = 1;
	int i = 0;
	
	scanf(" %d %d", &N, &V);
	
	while (i < N && V > 0) {
		scanf(" %c %d", &J, &AT);
		if (AT > 14) {
			switch (J) {
				case 'A':
					V -= A;
					CONTROLE = 'A';
					break;
				case 'I':
					V -= I;
					CONTROLE = 'I';
					break;
				case 'R':
					V -= R;
					CONTROLE = 'R';
					break;
				case 'W':
					V -= W;
					CONTROLE = 'W';
					break;
				case 'S':
					V -= S;
					CONTROLE = 'S';
					break;
				case 'C':
					V -= C;
					CONTROLE = 'C';
					break;
			}
		}
		i++;
	}
	
	if (V <= 0) {
		switch (CONTROLE) {
			case 'A':
				printf("Alyson derrotou o dragão!");
				break;
			case 'I':
				printf("Isaac derrotou o dragão!");
				break;
			case 'R':
				printf("Rafaela derrotou o dragão!");
				break;
			case 'W':
				printf("Wellington derrotou o dragão!");
				break;
			case 'S':
				printf("Salgado derrotou o dragão!");
				break;
			case 'C':
				printf("Careca derrotou o dragão!");
				break;															
		}
	} else {
		printf("Casa caiu!");
	}
	
	return 0;
}