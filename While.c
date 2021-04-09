#include <stdio.h>

int main()
{
	int somatorio, numero;
	
	somatorio = 0;
	
	scanf("%d", &numero);
	
	while (numero > 0) {
		somatorio = somatorio + numero;
		scanf("%d", &numero);
	}
	
	printf("A soma foi: %d\n", somatorio);
	
	return 0;
}