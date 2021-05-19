#include <stdio.h>

typedef enum {
	Diamonds, Heart, Spades, Clubs
} Naipe;

typedef enum {
	Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace 
} Valor;

typedef enum {
	HighCard, Pair, TwoPair, ThreeOfAKind, Straight,
	Flush, FullHouse, FourOfAKind, StraightFlush, RoyalFlush
} PokerHand;

typedef struct {
	Naipe suit;
	Valor value;
} Card;

PokerHand checkHand(Card *cartas) {
	int i, j, tam = 5;
	
	//Bubble Sort
	//Variável auxiliar para trocar os elementos de lugar
	Card aux;
	//Nós vamos percorrer o vetor comparando cada elemento i...
	for(i=0; i<tam-1; i++) {
		//... com os elementos j da frente
	    for(j=i+1; j<tam; j++){
	        //Se o número de i for menor do que a de j...
	        if(cartas[i].value < cartas[j].value){
	            aux = cartas[i];
	            cartas[i] = cartas[j];
	            cartas[j] = aux;
	        }
	    }
	}
	//Esse algoritmo então vai da posição 0, até a posição tam-1, colocando o maior
	//elemento existente nas posições iniciais. Ao terminar, o vetor estará ordenado
	
	Naipe n[] = { cartas[0].suit, cartas[1].suit, cartas[2].suit, cartas[3].suit, cartas[4].suit };
	Valor v[] = { cartas[0].value, cartas[1].value, cartas[2].value, cartas[3].value, cartas[4].value };
	
	//Condicionais para saber qual mão o jogador tem
	if (n[0] == n[1] &&
		n[0] == n[2] &&
		n[0] == n[3] &&
		n[0] == n[4]) {
		if (v[0] == Ace &&
		   	v[1] == King && 
			v[2] == Queen && 
			v[3] == Jack &&
			v[4] == Ten) {
			return RoyalFlush;
		}
		else if (v[0] == v[1] + 1 && 
		 	 	 v[0] == v[2] + 2 && 
		   	 	 v[0] == v[3] + 3 && 
				 v[0] == v[4] + 4 && 
				 v[0] != Ace) {
			return StraightFlush;
		}
		else {
			return Flush;
		}
	}
	else if (v[0] == v[1] + 1 && 
			 v[0] == v[2] + 2 && 
		     v[0] == v[3] + 3 && 
			 v[0] == v[4] + 4) {
			return Straight;
	}
	else if ((v[0] == v[1] && v[0] == v[2] && v[0] == v[3] && v[0] != v[4]) ||
			 (v[0] != v[1] && v[1] == v[2] && v[1] == v[3] && v[1] == v[4])) {
			return FourOfAKind;
	}
	else if ((v[0] == v[2] && v[3] == v[4]) ||
			 (v[0] == v[1] && v[2] == v[4])) {
			return FullHouse;
	}
	else if (v[0] == v[2] || v[1] == v[3] || v[2] == v[4]) {
			return ThreeOfAKind;
	}
	else if ((v[0] == v[1] && v[2] == v[3]) ||
			 (v[0] == v[1] && v[3] == v[4]) ||
			 (v[1] == v[2] && v[3] == v[4])) {
			return TwoPair;
	}
	else if (v[0] == v[1] || v[1] == v[2] || v[2] == v[3] || v[3] == v[4]) {
			return Pair;
	}
	
	return HighCard;
}

int main() {
    Card hands[][5] = {
        {  // Royal Flush
            { Diamonds, Ace },
            { Diamonds, King },
            { Diamonds, Queen }, 
            { Diamonds, Jack }, 
            { Diamonds, Ten } 
        },
        { // Full house
          { Heart, Jack },   
          { Spades, Jack },   
          { Clubs, Jack },     
          { Spades, Two  },    
          { Heart, Two } 
        },   
        { // Three of a Kind
          { Diamonds, Ten }, 
          { Spades, Seven },  
          { Diamonds, Four },  
          { Spades, Four  },   
          { Heart, Four } 
        },  
        { // Pair
          { Spades, Ace  },  
          { Heart, Jack },    
          { Spades, Jack },    
          { Heart, Seven },    
          { Clubs, Four } 
        },  
        { // High Card (No pair)
          { Clubs, Nine },   
          { Heart, Seven },   
          { Diamonds, Six },   
          { Spades, Four  },   
          { Heart, Two } 
        },   
    };
    Card myCards[5];
    Card oponentCards[5];
    
    unsigned handIndex;
    int i;
    scanf("%u", &handIndex);
    for(i = 0; i < 5; i++) {
        myCards[i] = hands[handIndex][i];
        scanf("%u %u", &oponentCards[i].suit, &oponentCards[i].value);
    }
    PokerHand myHand = checkHand(myCards);
    PokerHand oponentHand = checkHand(oponentCards);
    if (myHand > oponentHand) {
        switch(myHand) {
            case RoyalFlush:
                printf("É... simplesmente não tinha como me bater!\n");
                break;
            case StraightFlush:
            case FourOfAKind:
            case FullHouse:
                printf("Já era! Você não tinha chance!\n");
                break;
            case Flush:
            case Straight:
            case ThreeOfAKind:
                printf("É boy! Quem sabe da próxima vez...\n");
                break;
            default:
                printf("Tive sorte!\n");
        }
    }
    else if (oponentHand > myHand) {
        printf("Não valeu! Cê tá roubando!!!\n");
    }
    else if (myCards[0].value > oponentCards[0].value) {
        printf("Ufa! Por pouco!");
    }
    else {
        printf("Nan!! Bicho melado da gota!\n");
    }
    return 0;
}