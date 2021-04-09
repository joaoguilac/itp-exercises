#include <stdio.h>

int main() {
	float temperatura, C, F, K;
	char escala;
	
	scanf("%f %c", &temperatura, &escala);
	
	
	
	
	if (escala == 'C') {
		C = temperatura;
		F = C * 1.8 + 32;
		K = C + 273.15;		   	
	}
	else if (escala == 'F') {
		F = temperatura;
		C = (F - 32)/1.8;
		K = (F - 32)/1.8 + 273.15;
	}
	else {
		K = temperatura;
		C = K - 273.15;
		F = (K - 273.15) * 1.8 + 32;
	}
	
	printf("Celsius: %.2f \n", C);
	printf("Farenheit: %.2f \n", F);
	printf("Kelvin: %.2f", K);
	
	return 0;
}