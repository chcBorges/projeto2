#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int menu();

typedef struct sBanda
{
    char nome[30], genero[30], anoCriacao[4];
    int id, status;
} BANDA;

typedef struct sMusica
{
    char nome[30], compositor[30];
    float nota; 
	int quantNotas, status;
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

	bandas[i].status = 1;

    system("cls");      //Limpa tela do prompt de comando

	strupr(bandas[i].genero);

    printf("\nBanda inserida com sucesso!");    //imprime que a banda foi inserida
    sleep(2);   //espera dois segundos para retornar ao menu
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
    musicas[i].quantNotas = 0;
    //Atribui 0 na quantidade de pessoas que deu nota na musica
    musicas[i].status = 1;
    // Atribui 1 no status, significando que esse espaco no array musicas[i] foi preenchido pelo usuario
    printf("Sua musica foi cadastrada com sucesso! Aperte qualquer tecla para voltar ao menu...");
    getch();
    // Esse comando eh para pausar a tela, quando apertar alguma coisa ele continua o codigo
}

void avaliarMusica(MUSICA musicas[])
{	
	int i, verificar = 0, n;
	float notaSelecionada;
	system("cls");
    //Limpa tela do prompt de comando
    
	for(i = 0; i < 10; i++)
	{
		if(musicas[i].status == 1) //mostra as musicas que foram criadas pelo usuario
		{
			printf("Musica numero %d: ", i);
			puts(musicas[i].nome);
		}
		else
		{
			verificar++;
		}
	}
	if(verificar == 10) //verifica se nao ha musicas cadastradas
	{
		printf("\nNenhuma musica cadastrada.");
		printf("\nAperte qualquer tecla para voltar ao menu...");
		getch();
	}
	else
	{	
		printf("Digite o numero da musica que deseja avaliar: "); //pega a posicao do array musicas[n], onde vai ser alterado a nota
		scanf("%d", &n);
		
		if(musicas[n].status == 1) //verifica se essa posicao tem uma musica criada pelo usuario
		{
			
			
			printf("De 0 a 5, avalie a musica: "); //pega a nota que o usuario deu
			scanf("%f", &notaSelecionada);
			
			while(notaSelecionada > 5 || notaSelecionada < 0)  //verifica se a nota esta entre 0 e 5, se nao estiver, pede outra nota
			{
				printf("\nNumero incorreto, digite um numero de 0 a 5: ");
				scanf("%f", &notaSelecionada);
			}
			
			musicas[n].quantNotas++; // aumenta o numero de pessoas de deu uma nota nessa musica
			
			musicas[n].nota = (musicas[n].nota + notaSelecionada) / musicas[n].quantNotas; //realiza o calculo (ATENCAO, TEM QUE OLHAR SE ESSE CALCULO TA CERTO)
			printf("A nota atual da musica eh: %.2f", musicas[n].nota);
			printf("\nAperte qualquer tecla para voltar ao menu...");
			getch();
		}
		else //caso nao tenha musica cadastrada pelo usuario no array musicas[n]
		{
			printf("\nNenhuma musica cadastrada nesse numero.");
			printf("\nAperte qualquer tecla para voltar ao menu...");
			getch();
		}
		
	}
	
}

void imprimirMusicaComMaiorNota(MUSICA musicas[])
{	
	int i, j, verificar = 0; 
	float notaMaior = -4;
	system("cls");
    //Limpa tela do prompt de comand
	for(i = 0; i < 10; i++) //roda as posicoes do array
	{
		if(musicas[i].status == 1 && notaMaior < musicas[i].nota) //verifica se existe uma musica cadastrada pelo usuario nesta posicao e se a nota eh maior ate agora
		{
			notaMaior = musicas[i].nota; //salva a nota maior 
			j = i; // salva a posicao da nota maior
		}
		else
		{
			verificar++; //contador de quantas musicas não cadastradas pelo usuario possui 
		}
	}
	if(verificar != 10) // se o contador estiver em 10 quer dizer que não possui musicas cadastradas, se nao tiver em 10 ele entre nessa condicao 
	{
		printf("\nMusica com maior nota eh ");
		puts(musicas[j].nome);
		printf("com uma nota de %.2f", notaMaior);
		printf("\nAperte qualquer tecla para voltar ao menu...");
		getch();
		//mostra o nome da musica com maior nota e a nota dela		
	}
	else // mostra essa mensagem se nao possuir nenhuma musica cadastrada pelo usuario
	{
		printf("\nNenhuma musica cadastrada.");
		printf("\nAperte qualquer tecla para voltar ao menu...");
		getch();
	}
}
void imprimirMusicaComMenorNota(MUSICA musicas[])
{	
	int i, j, verificar = 0; 
	float notaMenor = 999;
	system("cls");
    //Limpa tela do prompt de comand
	for(i = 0; i < 10; i++) //roda as posicoes do array
	{
		if(musicas[i].status == 1 && notaMenor > musicas[i].nota) //verifica se existe uma musica cadastrada pelo usuario nesta posicao e se a nota eh menor ate agora
		{
			notaMenor = musicas[i].nota; //salva a nota menor
			j = i; // salva a posicao da nota menor
		}
		else
		{
			verificar++; //contador de quantas musicas não cadastradas pelo usuario possui
		}
	}
	if(verificar != 10) // se o contador estiver em 10 quer dizer que não possui musicas cadastradas, se nao tiver em 10 ele entre nessa condicao
	{
		printf("\nMusica com menor nota eh ");
		puts(musicas[j].nome);
		printf("com uma nota de %.2f", notaMenor);
		printf("\nAperte qualquer tecla para voltar ao menu...");
		getch();
		//mostra o nome da musica com menor nota e a nota dela		
	}
	else // mostra essa mensagem se nao possuir nenhuma musica cadastrada pelo usuario
	{
		printf("\nNenhuma musica cadastrada.");
		printf("\nAperte qualquer tecla para voltar ao menu...");
		getch();
	}
}

void bandasCadastradas(BANDA bandas[])
{
	int i, verificar = 0;
	system("cls");
    //Limpa tela do prompt de comand
	for(i = 0; i < 10; i++) //roda o array
	{
		if(bandas[i].status == 1) // mostra as bandas que foram cadastradas pelo usuario
		{
			printf("\nNome da Banda: ");
			puts(bandas[i].nome);
			printf("\nGenero da Banda: ");
			puts(bandas[i].genero);
			printf("\nAno de criacao da banda: ");
			puts(bandas[i].anoCriacao);
			printf("\nId da banda: %d", bandas[i].id);
			printf("\n-------------------------------");
		}
		else
		{
			verificar++; //verifica se possui alguma banda cadastrada, se nao tiver, diz isso ao usuario
			if(verificar == 10)
			{
				printf("\nNenhuma banda cadastrada.");
				
			}
		}
	}
	printf("\nAperte qualquer tecla para voltar ao menu...");
	getch();
}
void imprimirBandasPorGenero(BANDA bandas[])
{
	int i, verificar = 0, compara;
	char generoEscolhido[30];
	
	system("cls");
    //Limpa tela do prompt de comand
    
	printf("\nDigite o genero que deseja pesquisar: ");
	scanf("%s", generoEscolhido); //pega o genero que o usuario digitar
	printf("\nNome das bandas com o genero: ");
	puts(generoEscolhido);
	for(i = 0; i < 10; i++) //roda o array 
	{	
		
		strupr(generoEscolhido); // transformar em maiusculo 
		compara = strcmp(generoEscolhido, bandas[i].genero); //realiza a comparação 
		if(compara == 0) // mostra o nome da banda se o genero bater com o escolhido
		{
			printf("\n");
			puts(bandas[i].nome);
		}
		else
		{
			verificar++; //contador para olhar se não bate com o genero
		}
	}
	if(verificar == 10) //verifica se não possui nenhuma banda com esse genero e diz ao usuario
	{
		printf("\nNenhuma banda cadastrada com esse genero.");
		
	}
	printf("\nAperte qualquer tecla para voltar ao menu...");
	getch();
		
}

int main()
{
    int opcao = 1;
    //Recebe a op??o digitada pelo usu?rio

    BANDA bandas[10];  //declara a espaco para 10 bandas na memoria
    int bandaIndx = 0; //declara um indice que sera passado junto com a banda

    MUSICA musicas[10];    // Define capacidade do sistema de armazenar as 10 musicas
    int posicaoMusica = 0; // E define uma variavel para colocar as posicoes das musicas na funcao
	
	while(opcao!= 0)
	{	
		opcao = menu();
    	if (opcao == 0)
    	{
    	    //Se a op??o 0 for digitada encerra o programa
    	    char a = '\0';
    	    printf("Encerrando o programa... Pressione qualquer coisa para sair: ");
    	    fflush(stdin);
    	    scanf("%c", &a);
    	    //Trava o programa at? que o usu?rio digite uma coisa qualquer
    	    return 0;
    	    //Retorna 1 s? pra diferenciar quando o programa termina aqui
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
    	    posicaoMusica++;							//Incrementa 1 a posicao das musicas
    	}
    	else if (opcao == 3)
    	{
        	bandasCadastradas(bandas);					//Chama a fun??o de imprimir todas as bandas cadastradas
    	}
    	else if (opcao == 4)
    	{
        	imprimirMusicaComMaiorNota(musicas);		//Chama a fun??o de imprimir a musica com a maior nota
    	}
    	else if (opcao == 5)
    	{
   	    	imprimirMusicaComMenorNota(musicas);		//Chama a fun??o de imprimir a musica com a menor nota
   		}
    	else if (opcao == 6)
    	{
    	    imprimirBandasPorGenero(bandas);			//Chama a fun??o de buscar a banda pelo genero
    	}
   		else if (opcao == 7)
   		{
   	    	avaliarMusica(musicas);	//Chama a fun??o de avaliar musica
    	}
	}
	return 0;
}

int menu()
{
    int opcao = 0;
    //Vari?vel que vai receber o que o usu?rio digitar
    //E posteriormente vai ser retornada
    char traco[15] = {205, 205, 205, 205, 205, 205, 205, 205, 205, 205};
    //Uma string para fins de estetica do programa. S?o 10 caracteres parecidos com o =

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
    //Apresenta as op??es disponiv?is

    printf("\n\nDigite uma opcao valida: ");
    scanf("%d", &opcao);
    //Recebe a op??o do usu?rio

    if ((opcao < 0) || (opcao > 7))
    {
        //Verifica se a op??o digitado pelo usu?rio est? de fora do intervalo permitido
        //Se estiver chama a fun??o menu novamente
        menu();
    }

    return opcao;
    //Retorna a op??o v?lida que foi digitada pelo usu?rio
}
