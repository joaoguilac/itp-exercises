#include <stdio.h>

int main()
{
	int TD_1, FG_1, PAT_1;
	int TD_2, FG_2, PAT_2;
	
	scanf("%i %i %i", &TD_1, &FG_1, &PAT_1);
	scanf("%i %i %i", &TD_2, &FG_2, &PAT_2);
	
	int time1 = 6 * TD_1 + 3 * FG_1 + PAT_1;
	int time2 = 6 * TD_2 + 3 * FG_2 + PAT_2;
	printf("Placar: Saints %i x %i Bucaneers \n", time1, time2);
	
	if (time1 == time2) {
		printf("Empate!");
	}
	else if (time1 > time2) {
		printf("Saints venceu!");
	}
	else {
		printf("Bucaneers venceu!");
	}
	
	return 0;
}