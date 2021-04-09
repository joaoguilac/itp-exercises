#include <stdio.h>

/**
 * Cria um histograma H com C categorias a partir de uma sequência de valores lidos da entrada-padrão.
 * A entrada a ser lida contém um valor inteiro N seguido de uma sequência de N valores reais.
 * 
 * Os valores lidos estarão entre na faixa de 0 a 10 (incluindo estes) e serão contabilizados no histograma
 * de acordo com o intervalo a qual pertence, levando em conta que haverá C categorias entre 0 e 10.
 * 
 * Por exemplo, se C for 5, teremos os intervalos [0; 2[, [2; 4[, [4; 6[, [6; 8[ e [8; 10]. Portanto, se o
 * valor 3.0 for lido, a 2ª categoria terá um elemento a mais no histograma. Se C for 3, os intervalos
 * seriam [0; 3.333...[, [3.333...; 6.666...[ e [6.666...;10]. Portanto, a 1ª categoria será atualizada.
 * 
 * @param c Número de categorias do histograma
 * @param h Array do histograma cujos valores serão atualizados a partir de dados lidos da entrada-padrão.
 */
void createHistogram(int c, int h[c]) {
	int alunos, i;
	double intervalo, nota;
	
	//Determinar quantas notas de aluno vamos ler
    scanf(" %d", &alunos);
    
    //Determinar de quanto em quanto vai ser cada intervalo
    intervalo = (double)10/c;
    
    //Iniciar cada intervalo com 0 ocorr�ncias
    for (i=0; i<c; i++){
		h[i] = 0;
	}
    
 	//Dizer de qual intervalo cada nota vai ser
	for (i=0; i<alunos; i++){
		int aux = 1;
		int multi = 1;
		
		scanf(" %lf", &nota);
		
		while (aux){
			if (nota < intervalo * multi){
				h[multi-1] += 1;
				aux = 0;
			}
			else if (multi == c && aux == 1){
				h[multi-1] += 1;
				aux = 0;
			}
			else {
				++multi;
			}
		}
	}
}

/**
 * Junta os valores de dois histogramas em um terceiro histograma.
 * 
 * @param c  Número de categorias do histograma.
 * @param h1 Array com os dados do 1ª histograma.
 * @param h2 Array com os dados do 2ª histograma.
 * @param joint Array do histograma cujos valores serão atualizados a partir dos dois primeiros.
 */
void joinHistograms(int c, int h1[c], int h2[c], int joint[c]) {
    int i;
	
	for (i=0; i<c; i++){
		joint[i] = h1[i] + h2[i];
	}
}

/**
 * Imprime um histograma em modo textual. A altura do histograma (quantidade de linhas a
 * serem impressas) corresponde ao maior valor de seu array.
 * 
 * @param c Número de categorias do histograma.
 * @param h Array com os dados do histograma a imprimir.
 */
void printHistogram(int c, int h[c]) {
    int i, j, maior = 0;
    
    for (i=0; i<c; i++){
		if (h[i] > maior){
			maior = h[i];
		}
	}
	
	for (i=maior; i>0; i--){
		for (j=0; j<c; j++){
			printf("_");
			if (h[j] >= i){
				printf("##");
			}
			else {
				printf("__");
			}
			printf("_");
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
    int numCateg;
    scanf("%i", &numCateg);

    int histA[numCateg];
    int histB[numCateg];
    int histAll[numCateg];

    createHistogram(numCateg, histA);
    createHistogram(numCateg, histB);
    joinHistograms(numCateg, histA, histB, histAll);

    printHistogram(numCateg, histA);
    printHistogram(numCateg, histB);
    printHistogram(numCateg, histAll);

    return 0;
}