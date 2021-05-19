#include <stdio.h>
#include <string.h>

int main(){
	int i, tamanho_A, tamanho_B, condicao;
	char A[41];
	char B[41];
	
	fgets(A, 41, stdin);
	fgets(B, 41, stdin);
	
	tamanho_A = strlen(A) - 1;
	tamanho_B = strlen(B) - 1;
	
	if (tamanho_A >= tamanho_B){
		condicao = tamanho_A;
	}
	else {
		condicao = tamanho_B;
	}
	
	for (i=0; i<condicao; i++){
		if (i < tamanho_A){
			printf("%c", A[i]);
		}
		if (i < tamanho_B){
			printf("%c", B[i]);
		}
	}
	
	return 0;
}