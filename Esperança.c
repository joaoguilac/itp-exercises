#include <stdio.h>
#include <string.h>

int main(){
	const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
	char K[5];
	char validador;
	
	fgets(K, 5, stdin);
	scanf("%c", &validador);
	/*Você pode ler com o fgets() uma variável com o tamanho máximo maior
	(10, por exemplo) e depois usar o strlen() para saber quantos caracteres tem.*/
 
	if (validador != '\n'){
		printf("Chave invalida!");
	}
	else {
		char P[201];
		int i, j, tam_S = 40, for_break = 0;
		
		fgets(P, 201, stdin);
		
		//Fazendo formatação
		if (P[strlen(P)-1] == '\n'){
			P[strlen(P)-1] = '\0';
		}
		
		for (i=0; i<strlen(P); i++){
			int cond = 0;
			for (j=0; j<tam_S; j++){
				if (P[i] == S[j]){
					cond = 1;
					break;
				}
				if (j == tam_S-1 && cond == 0){
					for_break = 1;
					break;
				}
			}
			if (for_break == 1){
				break;
			}
		}
		
		if (for_break == 1){
			printf("Caractere invalido na entrada!\n");
		}
		else {
			int tam_n = strlen(P);
			int n[tam_n];
			
			j = 0;
			for (i=0; i<tam_n; i++){
				if (j == strlen(K)){
					j = 0;
				}
				n[i] = K[j] - '0';
				j++;
			}
			
			int aux; 
			for (i=0; i<tam_n; i++){
				for (j=0; j<tam_S; j++){
					if (P[i] == S[j]){
						aux = j;
						break;
					}
				}

				int valor = aux + n[i];
				if (valor >= tam_S){
					while (valor >= tam_S){
						valor -= tam_S;
					}
				}
				printf("%c", S[valor]);
			}
		}
		
		
	}

	return 0;
}