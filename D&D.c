#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Enumeração representando itens do jogo
enum item{
	cura = 1,
	dinheiro,
	vigor
};

//Enumeração representando as armadilhas
enum trap{
	buraco = 1,
	espinhos,
	ladrao
};

//Tipo Personagem, contendo vida e ataque. Usado para definir os inimigos e parte do Jogador
typedef struct person{
	int life, attack;
} Personagem;

//Tipo Jogador. Contém um Personagem com informações de vida e ataque, além de uma posição x,y e informações de dinheiro (loot) e se está equipado com escudo ou não.
typedef struct player{
	Personagem p; 
	
	int x, y, escudo, loot;
}Jogador;

//Tipo de dado Sala, representa uma casa do mapa. Pode conter um personagem inimigo, um tesouro e/ou uma armadilha
typedef struct room{
	Personagem p;
	int tesouro;
	int armadilha;
} Sala;

Sala** cria_mapa(int lin, int col, Jogador* player){
	int i, j, inimigos, tesouros, armadilhas;
	Sala **map;
	
	map = calloc(lin, sizeof(Sala*));
	for(i=0; i<lin; i++){
		map[i] = calloc(col, sizeof(Sala));
	}
	
	//Zerando os inimigos
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			map[i][j].p.life = 0;
			map[i][j].p.attack = 0;
		}
	}
	
	//Declarações para a leitura
	char tipo[9];
	int linha, coluna, vida_inimigo, ataque_inimigo;
	
	player->escudo = 0;
	player->loot = 0;
	scanf(" (%d %d) - %d %d", &linha, &coluna, &(player->p.life), &(player->p.attack));
	player->x = linha-1, player->y = coluna-1;
	scanf("%d %d %d", &inimigos, &tesouros, &armadilhas);
	
	//Leitura dos inimigos
	for(i=0; i<inimigos; i++){
		scanf(" (%d %d) - %d %d", &linha, &coluna, &vida_inimigo, &ataque_inimigo);
		linha -= 1, coluna -= 1;
		map[linha][coluna].p.life = vida_inimigo;
		map[linha][coluna].p.attack = ataque_inimigo;
	}
	
	//Leitura dos tesouros
	for(i=0; i<tesouros; i++){
		scanf(" %s %d %d", tipo, &linha, &coluna);
		linha -= 1, coluna -= 1;
		if (strcmp(tipo, "cura") == 0){
			map[linha][coluna].tesouro = cura;
		}
		else if (strcmp(tipo, "dinheiro") == 0){
			map[linha][coluna].tesouro = dinheiro;
		}
		else if (strcmp(tipo, "escudo") == 0){
			map[linha][coluna].tesouro = vigor;
		}
	}
	
	//Leitura das armadilhas
	for(i=0; i<armadilhas; i++){
		scanf(" %s %d %d", tipo, &linha, &coluna);
		linha -= 1, coluna -= 1;
		if (strcmp(tipo, "buraco") == 0){
			map[linha][coluna].armadilha = buraco;
		}
		else if (strcmp(tipo, "espinhos") == 0){
			map[linha][coluna].armadilha = espinhos;
		}
		else if (strcmp(tipo, "ladrao") == 0){
			map[linha][coluna].armadilha = ladrao;
		}
	}
	
	//Inicialização do mapa
	printf("Mapa inicializado!\n");
	printf("Jogador na posicao %d,%d\n", (player->x)+1, (player->y)+1);
	
	return map;
}

int executa_passo(int N, int M, Sala** mapa, char step, Jogador* p){
	//Muda posição do jogador
	if (step == 'W'){
		(p->x)--;
		printf("Avancando para %d, %d...\n", (p->x)+1, (p->y)+1);
		if (p->x < 0){
			printf("Movimento Ilegal!\n");
			(p->x)++;
		}
	}
	else if (step == 'S'){
		(p->x)++;
		printf("Avancando para %d, %d...\n", (p->x)+1, (p->y)+1);
		if (p->x >= N){
			printf("Movimento Ilegal!\n");
			(p->x)--;
		}
	}
	else if (step == 'A'){
		(p->y)--;
		printf("Avancando para %d, %d...\n", (p->x)+1, (p->y)+1);
		if (p->y < 0){
			printf("Movimento Ilegal!\n");
			(p->y)++;
		}
	}
	else if (step == 'D'){
		(p->y)++;
		printf("Avancando para %d, %d...\n", (p->x)+1, (p->y)+1);
		if (p->y >= M){
			printf("Movimento Ilegal!\n");
			(p->y)--;
		}
	}
	
	int lin = p->x, col = p->y;
	int ataque_jogador=p->p.attack, ataque_inimigo=mapa[lin][col].p.attack;
	int vida_jogador, vida_inimigo;
	//Caso tenha um inimigo na posição
	if (mapa[lin][col].p.life > 0){
		printf("Um inimigo!!!\n");
		while(1) {
			//Ataque do jogador
			printf("Jogador ataca!\n");
			printf("Dano de %d\n", ataque_jogador);
			vida_inimigo = mapa[lin][col].p.life -= ataque_jogador;
			printf("Vida do inimigo: %d\n", vida_inimigo);
			//Se o inimigo estiver morto
			if (vida_inimigo <= 0) {
				break;
			}
			//Se o jogador tiver um escudo
			if (p->escudo > 0){
				printf("Defendeu o golpe!\n");
				p->escudo -= 1;
			}
			//Ataque do inimigo
			else {		
				printf("Inimigo ataca!\n");
				printf("Dano de %d\n", ataque_inimigo);
				vida_jogador = p->p.life -= ataque_inimigo;
				printf("Vida do jogador: %d\n", vida_jogador);
			}
			//Se o jogador estiver morto
			if (vida_jogador <= 0) {
				break;
			}
		}
	}
	
	//Caso tenha um tesouro
	if (mapa[lin][col].tesouro == cura){
		printf("Um tesouro!\n");
		printf("Jogador coleta: pocao de cura!\n");
		p->p.life += 10;
	}
	else if (mapa[lin][col].tesouro == dinheiro){
		printf("Um tesouro!\n");
		printf("Jogador coleta: dinheiro!\n");
		p->loot += 10;
	}
	else if (mapa[lin][col].tesouro == vigor){
		printf("Um tesouro!\n");
		printf("Jogador coleta: um escudo!\n");
		p->escudo += 1;
	}
	
	//Caso tenha uma armadilha
	if (mapa[lin][col].armadilha == buraco){
		printf("Armadilha: buraco! Jogador se machuca!\n");
		p->p.life -= 10;
	}
	else if (mapa[lin][col].armadilha == espinhos){
		printf("Armadilha: espinhos! Jogador se machuca!\n");
		p->p.life -= 5;
	}
	else if (mapa[lin][col].armadilha == ladrao){
		printf("Armadilha: ladrao! Jogador perde dinheiro!\n");
		p->loot -= 10;
		if (p->loot < 0){
			p->loot = 0;
		}
	}
	
	//Confere se o jogador está vivo ou não
	if (p->p.life > 0){
		return 1;
	}
	else {
		return -1;
	}
}

void imprime_status_personagem(Jogador p){
	printf("Terminou na posicao (%d, %d)\n", (p.x)+1, (p.y)+1);
	printf("Vida: %d\n", p.p.life);
	printf("Dinheiro: %d\n", p.loot);
}

//Função principal
int main(){
	int i, n, m, movimentos, res;
	char passo;
	Jogador player;
	Sala** mapa;
	
	//Leitura do tamanho do mapa
	scanf("%d %d", &n, &m);
	
	//Função que cria o mapa e inicializa o Jogador de acordo com os dados da entrada
	mapa = cria_mapa(n, m, &player);
	
	//Leitura dos movimentos da simulação
	scanf("%d", &movimentos);
	
	//Para cada movimento do jogador...
	for(i=0; i<movimentos; i++){
	//Lê o movimento
	scanf(" %c", &passo);
	
	//Executa a simulação do passo. Se o retorno for -1, o jogador morreu e encerra a simulação
	res = executa_passo(n, m, mapa, passo, &player);
	if(res == -1) break;
	}
	
	//Testa pra ver se o jogador terminou vivo
	res < 0 ? printf("You died...\n"): printf("Vitoria!\n");
	
	//Imprime as informações finais do jogador
	imprime_status_personagem(player);
	
	return 0;
}