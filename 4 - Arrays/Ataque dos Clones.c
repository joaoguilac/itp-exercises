#include <stdio.h>

int main(){
	int N, M, c1, c2, i, j, rad, count = 1, sobrev = 1;
		
	scanf("%d %d", &N, &M);
	
	int mapa[N+2][M+2];
	
	scanf(" %d %d", &c1, &c2);
	
	for (i=0 ; i<N+2; i++){
		for (j=0; j<M+2; j++){
			mapa[i][j] = 0;
		}
	}
	
	for (i=1; i<=N; i++){
		for (j=1; j<=M; j++){
			scanf(" %d", &rad);
			mapa[i][j] = rad;
		}
	}
	
	for (i=1; i<=N; i++){
		for (j=1; j<=M; j++){
			int bomba = 0;
			
			if (mapa[i][j] > mapa[i+1][j] && mapa[i][j] > mapa[i-1][j]){
				if (mapa[i][j] > mapa[i][j+1] && mapa[i][j] > mapa[i][j-1]){
					if (mapa[i][j] > mapa[i-1][j-1] && mapa[i][j] > mapa[i+1][j+1]){
						if (mapa[i][j] > mapa[i-1][j+1] && mapa[i][j] > mapa[i+1][j-1]){
							bomba = 1;
						}	
					}	
				}		
			}			
						
			if (bomba) {
				printf("Local %d: %d %d\n", count, i, j);
				if (i == c1 && j == c2)
					sobrev = 0;
				++count;
			}
		}
	}
	
	if (sobrev) {
		printf("Ao resgate!\n");
	}
	else {
		printf("Descanse na Força...\n");
	}
	
	return 0;
}