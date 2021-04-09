#include <stdio.h>
#include <string.h>

int clica(int N, int M, char campo_front[N+2][M+2], char campo_back[N+2][M+2], int jafoi[N+2][M+2], int x, int y) {	
	if (campo_back[x][y] == 'B'){
		campo_back[x][y] = 'X';
		return 0;
	}
	
	if (campo_back[x][y] != '0'){
		campo_front[x][y] = campo_back[x][y];
		jafoi[x][y] = 1;
	}
	else {
		if (!(jafoi[x][y])){
			campo_front[x][y] = campo_back[x][y];
			jafoi[x][y] = 1;
		}
		if (!(jafoi[x-1][y-1])){
			campo_front[x-1][y-1] = campo_back[x-1][y-1];
			jafoi[x-1][y-1] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x-1, y-1);
		}
		if (!(jafoi[x-1][y])){
			campo_front[x-1][y] = campo_back[x-1][y];
			jafoi[x-1][y] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x-1, y);
		}
		if (!(jafoi[x-1][y+1])){
			campo_front[x-1][y+1] = campo_back[x-1][y+1];
			jafoi[x-1][y+1] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x-1, y+1);
		}
		if (!(jafoi[x][y-1])){
			campo_front[x][y-1] = campo_back[x][y-1];
			jafoi[x][y-1] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x, y-1);
		}
		if (!(jafoi[x][y+1])){
			campo_front[x][y+1] = campo_back[x][y+1];
			jafoi[x][y+1] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x, y+1);
		}
		if (!(jafoi[x+1][y-1])){
			campo_front[x+1][y-1] = campo_back[x+1][y-1];
			jafoi[x+1][y-1] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x+1, y-1);
		}
		if (!(jafoi[x+1][y])){
			campo_front[x+1][y] = campo_back[x+1][y];
			jafoi[x+1][y] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x+1, y);
		}
		if (!(jafoi[x+1][y+1])){
			campo_front[x+1][y+1] = campo_back[x+1][y+1];
			jafoi[x+1][y+1] = 1;
			clica(N, M, campo_front, campo_back, jafoi, x+1, y+1);
		}		 		
	}
	
	return 1;
}

void marca(int N, int M, char campo_front[N+2][M+2], int x, int y) {
	int i, j;
	
	campo_front[x][y] = 'B';
	
	for(i=0; i<M+2; i++){
		printf("=");
	}
	printf("\n");
	for(i=1; i<=N; i++){
		for(j=1; j<=M; j++){
			printf("%c", campo_front[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int N, M, B, J;
	
	//Leitura do tamanho do campo
	scanf("%d %d", &N, &M);
	char campo_front[N+2][M+2];
	char campo_back[N+2][M+2];
	int revelado[N+2][M+2];
	memset(campo_front, '*', sizeof(campo_front));
	memset(campo_back, '|', sizeof(campo_back));
	memset(revelado, 0, sizeof(revelado));
	
	//Leitura das bombas
	scanf("%d", &B);
	
	int i, j, linha, coluna;
	for(i=0; i<B; i++){
		scanf("%d %d", &linha, &coluna);
		campo_back[linha][coluna] = 'B';
	}
	
	//Definindo quantas bombas tem ao redor de cada casa
	for(i=1; i<=N; i++){
		for(j=1; j<=M; j++){
			int cont = 0;
			
			if (campo_back[i-1][j-1] == 'B'){
				cont++;
			}
			if (campo_back[i-1][j] == 'B'){
				cont++;
			}
			if (campo_back[i-1][j+1] == 'B'){
				cont++;
			}
			if (campo_back[i][j-1] == 'B'){
				cont++;
			}
			if (campo_back[i][j+1] == 'B'){
				cont++;
			}
			if (campo_back[i+1][j-1] == 'B'){
				cont++;
			}
			if (campo_back[i+1][j] == 'B'){
				cont++;
			}
			if (campo_back[i+1][j+1] == 'B'){
				cont++;
			}
			
			if (campo_back[i][j] != 'B'){
				campo_back[i][j] = cont + '0';
			}
		}
	}
	
	//Leitura das jogadas
	scanf("%d", &J);
	
	int retorno = 1;
	char entrada[15], movimento[6];
	for(i=0; i<J; i++){
		scanf(" %[^\n]", entrada);
		sscanf(entrada, "%s %d %d", movimento, &linha, &coluna);
		
		if (strcmp(movimento, "Clica") == 0){
			retorno = clica(N, M, campo_front, campo_back, revelado, linha, coluna);
			if (!retorno){
				break;
			}
			else {
				int j, k;
				for(j=0; j<M+2; j++){
					printf("=");
				}
				printf("\n");
				for(j=1; j<=N; j++){
					for(k=1; k<=M; k++){
						printf("%c", campo_front[j][k]);
					}
					printf("\n");
				}
			}
		}
		else if (strcmp(movimento, "Marca") == 0){
			marca(N, M, campo_front, linha, coluna);
		}
	}
	
	//Fim do jogo
	if (retorno == 1){
		printf("Você sobreviveu!\n");
	}
	else if (retorno == 0){
		printf("CABUUUUM!\n");
		printf("Game Over....\n");
	}
	//Impressão do Mapa
	for(i=0; i<M+2; i++){
		printf("=");
	}
	printf("\n");
	for(i=1; i<=N; i++){
		for(j=1; j<=M; j++){
			printf("%c", campo_back[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}