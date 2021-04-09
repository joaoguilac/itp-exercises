#include <stdio.h>

int main(){
    int i, alternativa;
    char nome[20];
    FILE *arquivo = fopen( "respostas", "w" ); //Abre um novo arquivo para escrita

    if( arquivo == NULL ){
	printf( "Erro na abertura do arquivo" );
    }
    else{
	printf("Digite seu nome: ");
        scanf("%s", nome);
        fprintf(arquivo, "Aluno: %s\n", nome); //Escreve uma linha com o nome do aluno
        for(i=0; i<10; i++){
            printf("Questão %d: ", i+1);
            scanf("%d", &alternativa);
            fprintf(arquivo, "Resposta %d: %d\n", i+1, alternativa); //Escreve uma resposta por linha
        }
        fclose( arquivo ); //fecha o arquivo
    }
    return 0;
}