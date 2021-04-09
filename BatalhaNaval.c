#include <stdio.h>

int main(){
	char mapa[10][10];
	int i, j, linha, coluna;
	
	for (i=0; i<10; i++){
		for (j=0; j<10; j++){
			mapa[i][j] = '~';
		}	
	}
	
	for (i=0; i<10; i++){
		scanf(" %d %d", &linha, &coluna);
		switch (i) {
			case 0:
				mapa[linha][coluna] = '*';
				break;
			case 1:
				mapa[linha][coluna] = '^';
				break;
			case 2:
				if (mapa[linha-1][coluna] == '^'){
					mapa[linha][coluna] = 'v';
				}
				else {
					mapa[linha][coluna-1] = '<';
					mapa[linha][coluna] = '>';
				}
				break;
			case 3:
				mapa[linha][coluna] = '^';
				break;
			case 4:
				if (mapa[linha-1][coluna] == '^'){
					mapa[linha][coluna] = '|';
				}
				else {
					mapa[linha][coluna-1] = '<';
					mapa[linha][coluna] = '=';
				}
				break;
			case 5:
				if (mapa[linha-1][coluna] == '|'){
					mapa[linha][coluna] = 'v';
				}
				else {
					mapa[linha][coluna] = '>';
				}
				break;
			case 6:
				mapa[linha][coluna] = '^';
				break;
			case 7:
				if (mapa[linha-1][coluna] == '^'){
					mapa[linha][coluna] = '|';
				}
				else {
					mapa[linha][coluna-1] = '<';
					mapa[linha][coluna] = '=';
				}
				break;
			case 8:
				if (mapa[linha-1][coluna] == '|'){
					mapa[linha][coluna] = '|';
				}
				else {
					mapa[linha][coluna] = '=';
				}
				break;
			case 9:
				if (mapa[linha-1][coluna] == '|'){
					mapa[linha][coluna] = 'v';
				}
				else {
					mapa[linha][coluna] = '>';
				}
				break;			
		}
	}	
	
	for (i=0; i<10; i++){
		for (j=0; j<10; j++){
			printf("%c", mapa[i][j]);
			if (j == 9){
				printf("\n");
			}
		}
	}
	
	return 0;
}