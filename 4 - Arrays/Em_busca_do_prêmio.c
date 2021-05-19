#include <stdio.h>

int main(){
	//S = Símbolos total | N = Quantidade de amigos para juntar os símbolos
	//M = Número de símbolos coletados por um dos amigos
	//C = Símbolos coletados
	int S, N, M, C, i, j, format = 0;
	
	scanf("%d %d", &S, &N);
	
	int total[S];

	for (i=0; i<N; i++) {
		scanf(" %d", &M);
		
		for (j=0; j<M; j++) {
			scanf(" %d", &C);
			if (total[C] != 1){
				total[C] = 1;
			}
		}
	}
	
	printf("[");
	for (i=0; i<S; i++) {
		if (total[i] != 1 && format == 0) {
			printf(" %d", i);
			format = 1;
		}
		else if (total[i] != 1 && format != 0) {
			printf(", %d", i);
		}	
	}
	printf(" ]");	
	
	return 0;
}