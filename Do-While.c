#include <stdio.h>

int main()
{
	int numero1, numero2;
	char operacao;
	
	do {
		printf("Digite a conta digitada (Valor Operador Valor):\n");
		scanf("%d %c %d", &numero1, &operacao, &numero2);
		
		switch(operacao) {
			case '+':
				printf("%d\n", numero1 + numero2);
				break;
			case '-':
				printf("%d\n", numero1 - numero2);
				break;
			case '*':
				printf("%d\n", numero1 * numero2);
				break;
			case '/':
				if (numero2 == 0) {
					printf("Erro! Divisao por zero!\n");
				} else {
					printf("%d\n", numero1 / numero2);
				}
				break;
		}
	} while (operacao != 'F');
	
	return 0;
}