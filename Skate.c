#include <stdio.h>

//int score(int, int, int);

int main() {
	int valor_1, valor_2, valor_3;
	int dia_1, dia_2, dia_3;
	int i, final_A, final_B;
	
	//Score skatista A
	for (i = 0; i < 3; i++) {
		scanf(" %d %d %d", &valor_1, &valor_2, &valor_3);
		if (i == 0) {
			dia_1 = score(valor_1, valor_2, valor_3);
		}
		else if (i == 1) {
			dia_2 = score(valor_1, valor_2, valor_3);
		}
		else {
			dia_3 = score(valor_1, valor_2, valor_3);
		}
	}
	final_A = score(dia_1, dia_2, dia_3);
	
	//Score skatista B
	for (i = 0; i < 3; i++) {
		scanf(" %d %d %d", &valor_1, &valor_2, &valor_3);
		if (i == 0) {
			dia_1 = score(valor_1, valor_2, valor_3);
		}
		else if (i == 1) {
			dia_2 = score(valor_1, valor_2, valor_3);
		}
		else {
			dia_3 = score(valor_1, valor_2, valor_3);
		}
	}
	final_B = score(dia_1, dia_2, dia_3);
	
	//Definição de quem ganhou
	if (final_A > final_B) {
		printf("A");
	}
	else if (final_A < final_B) {
		printf("B");
	}
	else {
		printf("empate");
	}
}

int score(int valor_1, int valor_2, int valor_3) {
	int medio;
	
	if ((valor_1 < valor_3 && valor_1 > valor_2) || (valor_1 > valor_3 && valor_1 < valor_2)) {
		medio = valor_1;
	}
	else if ((valor_2 < valor_3 && valor_2 > valor_1) || (valor_2 > valor_3 && valor_2 < valor_1)) {
		medio = valor_2;
	}
	else if ((valor_3 < valor_1 && valor_3 > valor_2) || (valor_3 > valor_1 && valor_3 < valor_2)) {
		medio = valor_3;
	}
	else if (valor_1 == valor_2 || valor_1 == valor_3) {
		medio = valor_1;
	}
	else if (valor_2 == valor_1 || valor_2 == valor_3) {
		medio = valor_2;
	}
	else if (valor_3 == valor_1 || valor_3 == valor_2) {
		medio = valor_3;
	}
	
	return medio;
}