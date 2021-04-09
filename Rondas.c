#include <stdio.h>

int escreve_hora(int, int, int, int);

int main() {
	int h, m, s, i = 1;
	int ronda_1, ronda_2, ronda_3, ronda_4;
	
	scanf("%d %d %d", &h, &m, &s);
	ronda_1 = escreve_hora(h, m, s, i);
	ronda_2 = escreve_hora(h, m, s, ronda_1);
	ronda_3 = escreve_hora(h, m, s, ronda_2);
	ronda_4 = escreve_hora(h, m, s, ronda_3);
	
	return 0;
}

int escreve_hora(int h, int m, int s, int i) {	
	if (i == 1) {
		h += 1;
		while (h > 23 || m > 59 || s > 59) {
			if (s > 59) {
				s -= 60;
				m++;
			}
			else if (m > 59) {
				m -= 60;
				h++;
			}
			else if (h > 23) {
				h -= 24;
			}
		}
		
		printf("%02d:%02d:%02d\n", h, m, s);
	}
	else if (i == 2) {
		h += 2;
		m += 10;
		s += 30;
		while (h > 23 || m > 59 || s > 59) {
			if (s > 59) {
				s -= 60;
				m++;
			}
			else if (m > 59) {
				m -= 60;
				h++;
			}
			else if (h > 23) {
				h -= 24;
			}
		}		
		
		printf("%02d:%02d:%02d\n", h, m, s);
	}
	else if (i == 3) {
		h += 4;
		m += 40;
		s += 50;
		while (h > 23 || m > 59 || s > 59) {
			if (s > 59) {
				s -= 60;
				m++;
			}
			else if (m > 59) {
				m -= 60;
				h++;
			}
			else if (h > 23) {
				h -= 24;
			}
		}
		
		printf("%02d:%02d:%02d\n", h, m, s);
	}
	else if (i == 4) {
		h += 12;
		m += 5;
		s += 5;
		while (h > 23 || m > 59 || s > 59) {
			if (s > 59) {
				s -= 60;
				m++;
			}
			else if (m > 59) {
				m -= 60;
				h++;
			}
			else if (h > 23) {
				h -= 24;
			}
		}
		
		printf("%02d:%02d:%02d\n", h, m, s);
	}
	
	return ++i;
}