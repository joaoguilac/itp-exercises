#include <stdio.h>

int main() {
	int N, RESTO_1, RESTO_2, RESTO_3, QUOCIENTE = 0;
	int COUNT_1 = 2, COUNT_2 = 0, FIM = 1, i, j;
	char PRIMO_1 = 'S', PRIMO_2 = 'S';
	
	scanf("%d", &N);
	
	//Testa se é maior ou igual a 1
	if (N <= 1) {
		printf("Erro, número precisa ser maior do que 1!");
	} else {
		//Classifica em primo ou não primo
		for (i = 2; i <= N/2; i++) {
			RESTO_1 = N % i;
			if (RESTO_1 == 0) {
				PRIMO_1 = 'N';
				break;
			}
		}

		//Testa se é primo ou não
		if (PRIMO_1 == 'N') {
			//Divindo meu número não primo enquanto o quociente não seja 1
			while (FIM != 0) {
   	   	   		RESTO_2 = N % COUNT_1;
   	   	   		//Condição se o COUNT_1 divide ou não o N
   	   	   		//No IF: ele divide e eu testo se o divisor é um fator
   	   	   		//No ELSE: ele não divide e eu vou para o próximo número
				if (RESTO_2 == 0) {
					//Testar se o divisor (COUNT_1) é um fator
					for (j = 2; j <= COUNT_1/2; j++) {
						RESTO_3 = COUNT_1 % j;
						if (RESTO_3 == 0) {
							PRIMO_2 = 'N';
							break;
						}
					}
					//Condicional para divisor primo ou não
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
			//Imprime a fatoração do número primo
			printf("%d^1", N);
		}
	}
	
	return 0;
}