#include <stdio.h>

int soma_divisores(int);
char confere_colegas(int, int, int, int);

int main() {
	int A, B, div_A, div_B;
	char resultado;
	
	scanf("%d %d", &A, &B);
	
	div_A = soma_divisores(A);
	div_B = soma_divisores(B);
	resultado = confere_colegas(div_A, div_B, A, B);
	
	printf("%c", resultado);
	
	return 0;
}

int soma_divisores(int numero) {
	int i;
	int soma = 0;
	
	for (i = 1; i <= numero/2; i++) {
		if (numero % i == 0) {
			soma += i;
		}
	}
	
	return soma;
}

char confere_colegas(int div_A, int div_B, int A, int B) {
	int modulo_1, modulo_2;
	
	modulo_1 = abs(div_A - B);
	modulo_2 = abs(div_B - A);
	
	if (modulo_1 <= 2 && modulo_2 <= 2) {
		return 'S';
	}
	else {
		return 'N';
	}
}