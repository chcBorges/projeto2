#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();

typedef struct smusica{
	char nome[30], compositor[30];
	int nota;
}MUSICA;
// Define a estrutura musica

void cadastrarMusica(MUSICA musicas[], int i){
	system("cls");
    //Limpa tela do prompt de comando
    
	printf("\nDigite o nome da musica: ");
	scanf("%s", musicas[i].nome);
	// Le nome da musica
	fflush(stdin);
	printf("\nDigite o compositor da musica: ");
	scanf("%s", musicas[i].compositor);
	// Le compositor da musica
	fflush(stdin);
	musicas[i].nota = 0;
	//Atribui 0 na nota
	printf("Sua musica foi cadastrada com sucesso! Aperte qualquer tecla para voltar ao menu...");
	getch();
	// Esse comando eh para pausar a tela, quando apertar alguma coisa ele continua o codigo
}

int main(){
    int opcao = menu();
    //Recebe a opção digitada pelo usuário
    
    MUSICA musicas[10];
    int posicaoMusica = 0;
    // Define capacidade do sistema de armazenar as 10 musicas
	// E define uma variavel para colocar as posicoes das musicas na funcao
	
    if(opcao == 0){
    //Se a opção 0 for digitada encerra o programa
        char a = '\0';
        printf("Encerrando o programa... Pressione qualquer coisa para sair: ");
        fflush(stdin);
        scanf("%c", &a);
        //Trava o programa até que o usuário digite uma coisa qualquer
        return 1;
        //Retorna 1 só pra diferenciar quando o programa termina aqui
        //de quando ele termina no fim do main
    }
    else if(opcao == 1){
    //Chama a função cadastra banda
    }
    else if(opcao == 2){
    //Chama a função cadastra musica
    	cadastrarMusica(musicas, posicaoMusica);
    	printf("%s", musicas[posicaoMusica].nome);
    	posicaoMusica++;
    	printf("\n**TESTE**  posicaoMusica = %d", posicaoMusica);
    	getch();
    	// esta parte nao esta pronta ainda, eh so pra eu observar o comportamento 
    }
    else if(opcao == 3){
    //Chama a função de imprimir todas as bandas cadastradas
    }
    else if(opcao == 4){
    //Chama a função de imprimir a musica com a maior nota
    }
    else if(opcao == 5){
    //Chama a função de imprimir a musica com a menor nota
    }
    else if(opcao == 6){
    //Chama a função de buscar a banda pelo genero
    }
    else if(opcao == 7){
    //Chama a função de avaliar musica
    }

    return 0;
}

int menu(){
    int opcao = 0;
    //Variável que vai receber o que o usuário digitar
    //E posteriormente vai ser retornada
    char traco[15] = {205, 205, 205, 205, 205, 205, 205, 205, 205, 205};
    //Uma string para fins de estetica do programa. São 10 caracteres parecidos com o =

    system("cls");
    //Limpa tela do prompt de comando
    printf("%s%sMENU%s%s", traco, traco, traco, traco);
    printf("\n0 - Sair do programa");
    printf("\n1 - Cadastrar banda");
    printf("\n2 - Cadastrar musica");
    printf("\n3 - Bandas cadastradas");
    printf("\n4 - Musica com maior nota");
    printf("\n5 - Musica com menor nota");
    printf("\n6 - Buscar banda pelo genero");
    printf("\n7 - Avaliar uma musica");
    //Apresenta as opções disponivéis

    printf("\n\nDigite uma opcao valida: ");
    scanf("%d", &opcao);
    //Recebe a opção do usuário

    if((opcao < 0) || (opcao > 7)){
    //Verifica se a opção digitado pelo usuário está de fora do intervalo permitido
    //Se estiver chama a função menu novamente
        menu();
    }

    return opcao;
    //Retorna a opção válida que foi digitada pelo usuário
}


