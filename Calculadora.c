#include <stdio.h>
#include <math.h>

int main()
{
	double numero1, numero2, potencia;
	int expoente, i;
	char operacao;
	
	scanf(" %c", &operacao);
	
	while (operacao != 'e') {
		if (operacao != '^') {
			scanf(" %lf %lf", &numero1, &numero2);
			switch(operacao) {
				case '+':
					printf("%.3lf+%.3lf=%.3lf\n", numero1, numero2, numero1 + numero2);
					break;
				case '-':
					printf("%.3lf-%.3lf=%.3lf\n", numero1, numero2, numero1 - numero2);
					break;
				case '*':
					printf("%.3lf*%.3lf=%.3lf\n", numero1, numero2, numero1 * numero2);
					break;
				case '/':
					if (numero2 == 0) {
						printf("Erro! Divisao por zero!\n");
					} else {
						printf("%.3lf/%.3lf=%.3lf\n", numero1, numero2, numero1 / numero2);
					}
					break;
			}
		} else if (operacao == '^') {
			scanf("%lf %d", &numero1, &expoente);
			potencia = numero1;
			for (i = 2; i <= expoente; i++) {
				potencia *= numero1;
			}
			printf("%.3lf^%d=%.3lf", numero1, expoente, round(potencia));
			
		} else {
			break;
		}
		scanf(" %c", &operacao);
	}
	
	return 0;
}