#include <stdio.h>

int MDC(int number1, int number2) {
	//Corrigindo quem vai ser o divisor e quem vai ser o dividendo
	if (number1 < number2){
		int aux = number1;
		number1 = number2;
		number2 = aux;
	}
	
	if (number1%number2 == 0){
		return number2;
	}
	else {
		return MDC(number2, number1%number2);
	}
}

int main() {
	int A, B, C;
	
	scanf("%d %d %d", &A, &B, &C);
	int mdc1 = MDC(A, B);
	int resultado = MDC(mdc1, C);
	
	printf("MDC de %d, %d e %d: %d", A, B, C, resultado);
	
	return 0;
}