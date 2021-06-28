#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int menu();

typedef struct sBanda
{
    char nome[30], genero[30], anoCriacao[4];
    int id;
} BANDA;

typedef struct smusica
{
    char nome[30], compositor[30];
    int nota;
} MUSICA;
// Define a estrutura musica

void cadastrarBanda(BANDA bandas[], int i)
{
    system("cls");      //Limpa tela do prompt de comando

    printf("\nDigite o nome da banda: ");
    scanf("%s", bandas[i].nome);    //realiza a leitura do nome da banda
    fflush(stdin);

    printf("\nDigite o genero da banda: ");
    scanf("%s", bandas[i].genero);  //realiza a leitura do genero da banda
    fflush(stdin);

    printf("\nDigite o ano de criacao da banda: ");
    scanf("%s", bandas[i].anoCriacao);  //realiza a leitura do ano de criacao da banda

    bandas[i].id = i + 1;     //a possicao banda eh posta como id, assim nenhuma tera o mesmo id


    system("cls");      //Limpa tela do prompt de comando

    printf("\nBanda inserida com sucesso!");    //imprime que a banda foi inserida
    sleep(2);   //espera dois segundos para retornar ao menu
    menu();
}

void cadastrarMusica(MUSICA musicas[], int i)
{
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

int main()
{
    int opcao = menu();
    //Recebe a op��o digitada pelo usu�rio

    BANDA bandas[10];  //declara a espaco para 10 bandas na memoria
    int bandaIndx = 0; //declara um indice que sera passado junto com a banda

    MUSICA musicas[10];    // Define capacidade do sistema de armazenar as 10 musicas
    int posicaoMusica = 0; // E define uma variavel para colocar as posicoes das musicas na funcao

    if (opcao == 0)
    {
        //Se a op��o 0 for digitada encerra o programa
        char a = '\0';
        printf("Encerrando o programa... Pressione qualquer coisa para sair: ");
        fflush(stdin);
        scanf("%c", &a);
        //Trava o programa at� que o usu�rio digite uma coisa qualquer
        return 0;
        //Retorna 1 s� pra diferenciar quando o programa termina aqui
        //de quando ele termina no fim do main
    }
    else if (opcao == 1)
    {
        cadastrarBanda(bandas, bandaIndx);          //Chama a funcao cadastrar banda
        bandaIndx++;                                //Incrementa 1 ao index das bandas 
    }
    else if (opcao == 2)
    {
        cadastrarMusica(musicas, posicaoMusica);    //Chama a funcao cadastra musica
        printf("%s", musicas[posicaoMusica].nome);
        posicaoMusica++;
        printf("\n**TESTE**  posicaoMusica = %d", posicaoMusica);
        getch();
        // esta parte nao esta pronta ainda, eh so pra eu observar o comportamento
    }
    else if (opcao == 3)
    {
        //Chama a fun��o de imprimir todas as bandas cadastradas
    }
    else if (opcao == 4)
    {
        //Chama a fun��o de imprimir a musica com a maior nota
    }
    else if (opcao == 5)
    {
        //Chama a fun��o de imprimir a musica com a menor nota
    }
    else if (opcao == 6)
    {
        //Chama a fun��o de buscar a banda pelo genero
    }
    else if (opcao == 7)
    {
        //Chama a fun��o de avaliar musica
    }

    return 0;
}

int menu()
{
    int opcao = 0;
    //Vari�vel que vai receber o que o usu�rio digitar
    //E posteriormente vai ser retornada
    char traco[15] = {205, 205, 205, 205, 205, 205, 205, 205, 205, 205};
    //Uma string para fins de estetica do programa. S�o 10 caracteres parecidos com o =

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
    //Apresenta as op��es disponiv�is

    printf("\n\nDigite uma opcao valida: ");
    scanf("%d", &opcao);
    //Recebe a op��o do usu�rio

    if ((opcao < 0) || (opcao > 7))
    {
        //Verifica se a op��o digitado pelo usu�rio est� de fora do intervalo permitido
        //Se estiver chama a fun��o menu novamente
        menu();
    }

    return opcao;
    //Retorna a op��o v�lida que foi digitada pelo usu�rio
}
