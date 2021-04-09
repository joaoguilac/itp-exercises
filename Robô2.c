#include <stdio.h>

int main(){
	int L, C, I, J, M;
	int i, j;
	char D, frente;
	
	scanf("%d %d", &L, &C);
	
	char mapa[L][C];
	
	for (i=0; i<L; i++){
		for (j=0; j<C; j++){
			scanf(" %c", &mapa[i][j]);
		}
	}
	
	scanf(" %d %d %c", &I, &J, &D);
	
	--I;
	--J;
	
	scanf(" %d", &M);
	
	for (i=0; i<M; i++){
		int x, y;
		//Definição da frente dependendo de sua direção
		switch (D) {
			case 'N':
				x = I-1;
				y = J;
				frente = mapa[I-1][J];
				break;
			case 'S':
				x = I+1;
				y = J;
				frente = mapa[I+1][J];		
				break;
			case 'L':
				x = I;
				y = J+1;
				frente = mapa[I][J+1];		
				break;
			case 'O':
				x = I;
				y = J-1;
				frente = mapa[I][J-1];	
				break;
		}	
		
		//virar a direita - saindo da borda	
		if (x < 0 || x > L-1 || y > C-1 || y < 0) {
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
		//ir para frente
		else if (frente == '.') {
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
		//virar a direita - parede
		else if (frente == '_' || frente == '|') {
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
	
	++I;
	++J;
	
	printf("Posição final: %d %d\n", I, J);

	return 0;
}