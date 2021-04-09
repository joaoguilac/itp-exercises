#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *str;
	int capacity;
	int length;
} string;

void set_str(string *ponteiro, char *texto) {
	int k = 16, tam = strlen(texto)+1;
	
	while (tam > k){
		k += 16;
	}
	
	ponteiro->str = calloc(sizeof(char), k);
	strcpy(ponteiro->str, texto);
	ponteiro->capacity = k;
	ponteiro->length = tam-1;
}

void read_str(string *ponteiro) {
	char linha[36];
	
	fgets(linha, 36, stdin);
	
	if (linha[strlen(linha)-1] == '\n'){
		linha[strlen(linha)-1] = '\0';
	}
	
	int k = 16, tam = strlen(linha)+1;
	
	while (tam > k){
		k += 16;
	}
	
	ponteiro->str = calloc(sizeof(char), k);
	strcpy(ponteiro->str, linha);
	ponteiro->capacity = k;
	ponteiro->length = tam-1;
}

void concat_str(string *string1, string *string2) {
	int k = 16;
	int tam = strlen(string1->str) + strlen(string2->str) + 1;
	string1->length = strlen(string1->str) + strlen(string2->str);
	
	while (tam > k){
		k += 16;
	}
	
	if (k != string1->capacity){
		string1->str = realloc(string1->str, sizeof(char) * k);
		string1->capacity = k;
	}
	
	strcat(string1->str, string2->str);
}

void clear_str(string *ponteiro) {
	free(ponteiro->str);
	ponteiro->str = NULL;
	ponteiro->capacity = 0;
	ponteiro->length = 0;
}

int main() {
    string greeting;
    string name;
    set_str(&greeting, "Oi ");
    read_str(&name);
    concat_str(&greeting, &name);
    printf("%s\n", greeting.str);
    printf("%i %i\n", greeting.capacity, greeting.length);
    clear_str(&greeting);
    clear_str(&name);
    return 0;
}