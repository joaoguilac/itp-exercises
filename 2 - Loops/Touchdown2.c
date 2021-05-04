#include <stdio.h>

int main() {
	int TD, FG, PAT;
	int TD_quant1 = 0, FG_quant1 = 0, PAT_quant1 = 0;
	int TD_quant2 = 0, FG_quant2 = 0, PAT_quant2 = 0;
	int time1, time2;
	int vencedor;
	int N, T;
	int i;
	
	scanf("%d", &N);
	T = 2 * N;
	
	for (i = 0; i < T; i++) {
		scanf("%d %d %d", &TD, &FG, &PAT);
		if (i % 2 == 0) {
			//Saints
			TD_quant1 += TD;
			FG_quant1 += FG;
			PAT_quant1 += PAT;
		} else {
			//Bucaneers
			TD_quant2 += TD;
			FG_quant2 += FG;
			PAT_quant2 += PAT;  
		}
	}
	
	time1 = TD_quant1 * 6 + FG_quant1 * 3 + PAT_quant1 * 1;
	time2 = TD_quant2 * 6 + FG_quant2 * 3 + PAT_quant2 * 1;
	
	if (time1 > time2) {
		printf("Saints é o campeão na série histórica! \n");
		vencedor = 1; 
	} else if (time2 > time1) {
		printf("Bucaneers é o campeão na série histórica! \n");
		vencedor = 2;		   	
	} else {
		printf("Série histórica empatada em %d pontos! \n", time1);
	}
	
	if (time1 != time2) {
		if (vencedor == 1) {
			printf("Placar: %d x %d \n", time1, time2);
		} else {
			printf("Placar: %d x %d \n", time2, time1);
		}
	}
	
	if (TD_quant1 > TD_quant2) {
		printf("Saints marcou mais Touch Downs(%d) \n", TD_quant1);
	} else if (TD_quant2 > TD_quant1) {
		printf("Bucaneers marcou mais Touch Downs(%d) \n", TD_quant2);
	} else {
		printf("Número de Touch Downs empatado(%d) \n", TD_quant1);
	}
	
	if (FG_quant1 > FG_quant2) {
		printf("Saints marcou mais Field Goals(%d) \n", FG_quant1);
	} else if (FG_quant2 > FG_quant1) {
		printf("Bucaneers marcou mais Field Goals(%d) \n", FG_quant2);
	} else {
		printf("Número de Field Goals empatado(%d) \n", FG_quant1);
	}
	
	if (PAT_quant1 > PAT_quant2) {
		printf("Saints marcou mais Pontos Extras(%d)", PAT_quant1);
	} else if (PAT_quant2 > PAT_quant1) {
		printf("Bucaneers marcou mais Pontos Extras(%d)", PAT_quant2);
	} else {
		printf("Número de Pontos Extras empatado(%d)", PAT_quant1);
	}	
	
	return 0;
}