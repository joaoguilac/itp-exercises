#include <stdio.h>
#include <string.h>

void descobrir_chave(char [], char [], int []);
void decifrar_mensagem(char [], int []);

int main(){
	char C[201];
	char KP[] = "QUE A FORCA ESTEJA COM VOCE";
	int K[4];
	
	fgets(C, 201, stdin);
	
	//Fazendo formatação
	if (C[strlen(C)-1] == '\n'){
		C[strlen(C)-1] = '\0';
	}
	
	//Iniciando elemento do vetor da chave com -1
	K[0] = -1;
	
	descobrir_chave(C, KP, K);
	decifrar_mensagem(C, K);
	
	return 0;
}

void descobrir_chave(char C[], char KP[], int K[4]){
	const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};  
	int i, j, k, i_aux, num_C, num_KP, valor;
	int tam_C = strlen(C), tam_KP = 27, tam_S = 40;
	char K_aux[tam_KP];
		
	for (i=0; i<tam_C; i++){
		i_aux = i;
		for (j=0; j<tam_KP; j++){
			//Calculando o número do caracter da mensagem cifrada
			for (k=0; k<tam_S; k++){
				if (C[i_aux] == S[k]){
					num_C = k;
					break;
				}
			}
			
			//Calculando o número do caracter do fragmento
			for (k=0; k<tam_S; k++){
				if (KP[j] == S[k]){
					num_KP = k;
					break;
				}
			}
			
			//Fazendo subtração dos valores
			valor = num_C - num_KP;
			if (valor < 0){
				valor += 40;
			}
			valor %= 40;

			if (valor > 9 || valor < 0){
				break;
			}
			else {
				K_aux[j] = valor;
				i_aux++;
			}
			
		}
		
		//Armazenando e imprimindo os valores da chave no vetor K[]
		if (j == tam_KP){
			int m;
			i %= 4;
			
			//Armazenando
			for (m=0; m<4; m++){
				K[m] = K_aux[i];
				i++;
			}
			
			//Imprimindo
			for (m=0; m<4; m++){
				printf("%d", K[m]);
			}
			printf("\n");
			
			break;
		}
		
	}

}

void decifrar_mensagem(char C[], int K[]){
	const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
	int i, j, aux, tam_S = 40;
	
	if (K[0] == -1){
		printf("Mensagem nao e da Resistencia!");
	}
	else {
		int tam_n = strlen(C);
		int n[tam_n];
		
		j = 0;
		for (i=0; i<tam_n; i++){
			if (j == 4){
				j = 0;
			}
			n[i] = K[j];
			j++;
		}
		
		for (i=0; i<tam_n; i++){
			for (j=0; j<tam_S; j++){
				if (C[i] == S[j]){
					aux = j;
					break;
				}
			}
	
			int valor = aux - n[i];
			if (valor < 0){
				valor += 40;
			}
			valor %= 40;
			printf("%c", S[valor]);
		}
	}

}