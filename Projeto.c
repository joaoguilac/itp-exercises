#include <stdio.h>
#include <string.h>
#define MAX_LINE 200
#define ID_SIZE 10

typedef enum {
	2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A
} Value;



if (hand[i].value + 2 == topTrashCardValue &&
    hand[i + 1].value + 1 == topTrashCardValue) {

}

typedef enum {
	?, ?, ?, ?
} Suit;

typedef struct {
	Suit suit;
	Value value;
} Card;

void readline(char *line) {
  fgets(line, MAX_LINE, stdin);
  int l = strlen(line) - 1;
  if (line[l] == '\n') {
    line[l] = '\0';
}

//Função joaoguilac
void checkCommand(char *line, Card *TopOfTrash) {
  char* command;

  strncpy(command, line, 7);
  if (strcmp(command, "DISCARD") == 0){
    TopOfTrash
  }
}

void sort(Card hand[]) {
  int tam = 26;
  //Bubble Sort
	//Variável auxiliar para trocar os elementos de lugar
	Card aux;
	//Nós vamos percorrer o vetor comparando cada elemento i...
	for (i = 0; i < tam - 1; i++) {
		//... com os elementos j da frente
    for (j = i + 1; j < tam; j++){
      //Se o número de i for menor do que a de j...
      if (hand[i].value < hand[j].value) {
        aux = hand[i];
        hand[i] = hand[j];
        hand[j] = aux;
      }
    }
	}
	//Esse algoritmo então vai da posição 0, até a posição tam-1, colocando o maior
	//elemento existente nas posições iniciais. Ao terminar, o vetor estará ordenado
}

bool checkDiscard(char *line) {
  char *token = strtok(line, " ");
  if (*token == "DISCARD") {
    return true;
  }
  return false;
}

int main() {
  char line[MAX_LINE];
  char myId[ID_SIZE];

  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);

  readline(line);
  readline(line);
  strncpy(myId, line, ID_SIZE);
  readline(line);
  readline(line);

  Card TopOfTrash;
  while (1) {              
    do {
      readline(line);
      checkDiscard(line, &TopOfTrash); //Função joaoguilac
      if (checkDiscard(line)) {
        Card topTrashCard;
        token = strtok(line, " ");
        scanf("%c%s", &topTrashCard.value, topTrashCard.suit);
      }
      // fprintf(stderr, "%s\n", line);
    } while (strcmp(line, myId));

    printf("GET_STOCK\n");
    readline(line);
    printf("DISCARD %s\n", line);
  }

  return 0;
}