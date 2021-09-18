#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
   char nome[201];
   int pontos, jogos, vitorias, empates, derrotas, gols_feitos, gols_sofridos, gols_saldo;
} Time;

Time* leitura_dos_times(int tam) {
	int i;
	char linha[217], *parte;
	Time *times;
	
	times = calloc(sizeof(Time), tam);
	
	for (i=0; i<tam; i++){
		 fgets(linha, 217, stdin);
		 
		 parte = strtok(linha, ";");
		 strcpy(times[i].nome, parte);
		 parte = strtok(NULL, "\n");
		 
		 sscanf(parte, " %d %d %d %d %d", &(times[i].vitorias), &(times[i].empates), &(times[i].derrotas), &(times[i].gols_feitos), &(times[i].gols_sofridos));
		 
		 times[i].pontos = 3*times[i].vitorias + 1*times[i].empates;
		 times[i].jogos = times[i].vitorias + times[i].empates + times[i].derrotas;
		 times[i].gols_saldo = times[i].gols_feitos - times[i].gols_sofridos;
	}
	
	return times;
}

//Bubblesort no vetor
void ordenar_tabela(Time *times, int tam) {
    //Variável auxiliar para trocar os elementos de lugar
    Time aux;
    //Nós vamos percorrer o vetor comparando cada elemento i...
    int i, j;
    for(i=0; i<tam-1; i++)
        //... com os elementos j da frente
        for(j=i+1; j<tam; j++){
            //Se os pontos de i forem menos do que a de j...
            if(times[i].pontos < times[j].pontos){
                aux = times[i];
                times[i] = times[j];
                times[j] = aux;
            }
            //Ou se elas forem iguais, mas o número de vitórias em i for menor do que j...
            else if(times[i].pontos == times[j].pontos && times[i].vitorias < times[j].vitorias){
                aux = times[i];
                times[i] = times[j];
                times[j] = aux;
            }
            //Ou se elas tiverem o mesmo número de pontos e vitórias, mas o saldo de gols de i for menor do que j...
            else if(times[i].pontos == times[j].pontos && times[i].vitorias == times[j].vitorias && times[i].gols_saldo < times[j].gols_saldo){
				aux = times[i];
                times[i] = times[j];
                times[j] = aux;
			}
        }
        //Esse algoritmo então vai da posição 0, até a posição tam-1, colocando o maior
        //elemento existente nas posições iniciais. Ao terminar, o vetor estará ordenado
}

void impressao_da_tabela(Time *times, int tam) {
	int i;
	
	//Impressão da tabela
	printf("Tabela do campeonato:\n");
	printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
	for (i=0; i<tam; i++){
		printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", times[i].nome, times[i].pontos, times[i].jogos, times[i].vitorias, times[i].empates, times[i].derrotas, times[i].gols_feitos, times[i].gols_sofridos, times[i].gols_saldo);
	}
	
	//Times na libertadores
	printf("\nTimes na zona da libertadores:\n");
	for (i=0; i<6; i++){
		printf("%s\n", times[i].nome);
	}
	
	//Times na zona de rebaixamento
	printf("\nTimes rebaixados:\n");
	for (i=tam-1; i>tam-5; i--){
		printf("%s\n", times[i].nome);
	}
	
	free(times);
}

int main() {
	int T;
	
	scanf("%d\n", &T);
	
	Time *times = leitura_dos_times(T);
	
	ordenar_tabela(times, T);
	
	impressao_da_tabela(times, T);
	
	return 0;
}