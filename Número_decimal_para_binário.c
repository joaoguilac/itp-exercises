#include <stdio.h>

void conversao(unsigned number) {	
	if (number/2 != 0){
		conversao(number/2);
	}
	
	printf("%u", number%2);
}

int main() {
	unsigned numero;
	
	scanf("%u", &numero);
	conversao(numero);
	
	return 0;
}