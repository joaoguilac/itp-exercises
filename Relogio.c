#include <stdio.h>

int main()
{
	int hour, minute;
	scanf("%i:%i", &hour, &minute);
	
	if (hour < 12 || (hour == 12 && minute == 0) ) {
		printf("Cedo demais!");
	}
	else {
		printf("Hora de acordar...");
	}
	
	return 0;
}