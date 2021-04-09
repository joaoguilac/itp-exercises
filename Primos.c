#include <stdio.h>

int main() {
	int N, RESTO_1, RESTO_2, RESTO_3, QUOCIENTE = 0;
	int COUNT_1 = 2, COUNT_2 = 0, FIM = 1, i, j;
	char PRIMO_1 = 'S', PRIMO_2 = 'S';
	
	scanf("%d", &N);
	
	//Testa se � maior ou igual a 1
	if (N <= 1) {
		printf("Erro, n�mero precisa ser maior do que 1!");
	} else {
		//Classifica em primo ou n�o primo
		for (i = 2; i <= N/2; i++) {
			RESTO_1 = N % i;
			if (RESTO_1 == 0) {
				PRIMO_1 = 'N';
				break;
			}
		}

		//Testa se � primo ou n�o
		if (PRIMO_1 == 'N') {
			//Divindo meu n�mero n�o primo enquanto o quociente n�o seja 1
			while (FIM != 0) {
   	   	   		RESTO_2 = N % COUNT_1;
   	   	   		//Condi��o se o COUNT_1 divide ou n�o o N
   	   	   		//No IF: ele divide e eu testo se o divisor � um fator
   	   	   		//No ELSE: ele n�o divide e eu vou para o pr�ximo n�mero
				if (RESTO_2 == 0) {
					//Testar se o divisor (COUNT_1) � um fator
					for (j = 2; j <= COUNT_1/2; j++) {
						RESTO_3 = COUNT_1 % j;
						if (RESTO_3 == 0) {
							PRIMO_2 = 'N';
							break;
						}
					}
					//Condicional para divisor primo ou n�o
					if (PRIMO_2 == 'S') {
						QUOCIENTE = N/COUNT_1;
						N = QUOCIENTE;
						COUNT_2++;
					} else {
						COUNT_1++;
						PRIMO_2 = 'S';
					}
				} else {
					if (QUOCIENTE != 1 && COUNT_2 > 0){
						printf("%d^%d*", COUNT_1, COUNT_2);
					}
					if (QUOCIENTE == 1 && COUNT_2 > 0) {
						printf("%d^%d", COUNT_1, COUNT_2);
						FIM = 0;
					}
					COUNT_1++;
					COUNT_2 = 0;
					PRIMO_2 = 'S';
				}
			}
		} else {
			//Imprime a fatora��o do n�mero primo
			printf("%d^1", N);
		}
	}
	
	return 0;
}