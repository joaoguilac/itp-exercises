#include <stdio.h>

int main(){
	int N, i, j, distancia = 0, maior = 0;
	
	scanf("%d", &N);

	int predio[N];
		
	for (i=0; i<N; i++){
		scanf(" %d", &predio[i]);
	}
	
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			if (i != j) {
				distancia = predio[i] + abs(i-j) + predio[j];
				//printf("Distancia: %d e (predio[i]=%d, j=%d, predio[j]=%d\n", distancia, predio[i], j, predio[j]);
				if (distancia > maior) {
					maior = distancia;
					//printf("Maior: %d\n", maior);
				}
			}
		}
	}
	
	printf("%d", maior);
	
	return 0;
}