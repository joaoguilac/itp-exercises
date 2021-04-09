#include <stdio.h>

int main(){
	int L, C, I, J, M;
	int i, j;
	char D, frente;
	
	scanf("%d %d", &L, &C);
	
	char mapa[L+2][C+2];
	
	for (i=0; i<L+2; i++){
		for (j=0; j<C+2; j++){
			mapa[i][j] = '#';
		}
	}
	
	for (i=1; i<=L; i++){
		for (j=1; j<=C; j++){
			scanf(" %c", &mapa[i][j]);
		}
	}
	
	scanf(" %d %d %c", &I, &J, &D);
	
	scanf(" %d", &M);
	
	for (i=0; i<M; i++){
		//Definição da frente dependendo de sua direção
		switch (D) {
			case 'N':
				frente = mapa[I-1][J];
				break;
			case 'S':
				frente = mapa[I+1][J];		
				break;
			case 'L':
				frente = mapa[I][J+1];		
				break;
			case 'O':
				frente = mapa[I][J-1];	
				break;
		}	
			
		//ir para frente
		if (frente == '.') {
			switch (D) {
				case 'N':
					--I;
					break;
				case 'S':
					++I;
					break;
				case 'L':
					++J;
					break;
				case 'O':
					--J;
					break;
			}
		}
		//virar a direita
		else if (frente == '_' || frente == '|' || frente == '#') {
			switch (D) {
				case 'N':
					D = 'L';
					break;
				case 'S':
					D = 'O';
					break;
				case 'L':
					D = 'S';
					break;
				case 'O':
					D = 'N';
					break;
			}					
		}
		//virar a esquerda
		else if (frente == '*') {
			switch (D) {
				case 'N':
					D = 'O';
					break;
				case 'S':
					D = 'L';
					break;
				case 'L':
					D = 'N';
					break;
				case 'O':
					D = 'S';
					break;
			}			
		}

	}
	
	printf("Posição final: %d %d\n", I, J);

	return 0;
}