#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct sBanda
{
    char nome[30], genero[30], anoCriacao[5];
    int id, status;
} BANDA;
//Define a estrutura banda

typedef struct sMusica
{
    char nome[30], compositor[30];
    float soma, nota, quantNotas; 
	int status;
} MUSICA;
//Define a estrutura musica

int menu(int qtdBandas, int qtdMusicas);

void seguraPrograma();

void cadastrarBanda(BANDA bandas[], int i)
{
    system("cls");
    //Limpa tela do prompt de comando

    printf("Digite o nome da banda: ");
    fflush(stdin);
    scanf("%[^\n]", bandas[i].nome);
    //Realiza a leitura do nome da banda

    printf("\nDigite o genero da banda: ");
    fflush(stdin);
    scanf("%[^\n]", bandas[i].genero);
    //Realiza a leitura do genero da banda

    printf("\nDigite o ano de criacao da banda: ");
    fflush(stdin);
    scanf("%[^\n]", bandas[i].anoCriacao);
    //Realiza a leitura do ano de criacao da banda

    bandas[i].id = i + 1;
    //A posicao banda eh posta como id, assim nenhuma tera o mesmo id

	bandas[i].status = 1;
    //Vai ser por essa variavel que vamos confirmar se a banda foi realmente cadastrada

	strupr(bandas[i].genero);
    //Coloca todos os caracteres maiusculo

    system("cls");
    //Limpa tela do prompt de comando

    printf("Banda inserida com sucesso!");
    //imprime que a banda foi inserida
    
    seguraPrograma();
    //Trava o programa ate o usuario digitar alguma coisa
}

void cadastrarMusica(MUSICA musicas[], int i)
{
    system("cls");
    //Limpa tela do prompt de comando

    printf("Digite o nome da musica: ");
    fflush(stdin);
    scanf("%[^\n]", musicas[i].nome);
    //Le nome da musica

    printf("\nDigite o compositor da musica: ");
    fflush(stdin);
    scanf("%[^\n]", musicas[i].compositor);
    //Le compositor da musica

    musicas[i].nota = 0;
    //Atribui 0 na nota
    musicas[i].quantNotas = 0;
    //Atribui 0 na quantidade de pessoas que deu nota na musica
    musicas[i].status = 1;
    //Atribui 1 no status, significando que esse espaco no array musicas[i] foi preenchido pelo usuario
    
    system("cls");
    //Limpa a tela

    printf("Sua musica foi cadastrada com sucesso!");

    seguraPrograma();
    //Trava o programa ate que o usuario digite alguma coisa
}

void avaliarMusica(MUSICA musicas[])
{	
	int i, verificar = 0, n;
	float notaSelecionada;
	system("cls");
    //Limpa tela do prompt de comando
    
	for(i = 0; i < 10; i++)
	{
		if(musicas[i].status == 1)  //mostra as musicas que foram criadas pelo usuario
		{
			printf("Musica numero %d: ", i);
			puts(musicas[i].nome);
		}
		else
		{
			verificar++;
		}
	}
	
    while(1){
        printf("Digite o numero da musica que deseja avaliar: ");
        scanf("%d", &n);
        //Pega a posicao do array musicas[n], onde vai ser avaliado pelo usuario
            
        if(musicas[n].status == 1)  //verifica se essa posicao tem uma musica criada pelo usuario
        {
            printf("De 0 a 5, avalie a musica: ");
            scanf("%f", &notaSelecionada);
            //pega a nota que o usuario deu
                
            while(notaSelecionada > 5 || notaSelecionada < 0)   //verifica se a nota esta entre 0 e 5, se nao estiver, pede outra nota
            {
                printf("\nNumero incorreto, digite um numero de 0 a 5: ");
                scanf("%f", &notaSelecionada);
            }
                
            musicas[n].quantNotas++;
            //Aumenta o numero de pessoas de deu uma nota nessa musica
            
            musicas[n].soma += notaSelecionada;
            printf("\n%f\n", musicas[n].soma);
            musicas[n].nota = (musicas[n].soma / musicas[n].quantNotas);
            printf("\n%f\n", musicas[n].nota);
            //Realiza o calculo da media das notas inseridas
            printf("A nota atual da musica eh: %.2f", musicas[n].nota);
            
            seguraPrograma();
            //Trava o programa ate que o usuario digite alguma coisa

            break;
        }
    }
	
}

void imprimirMusicaComMaiorNota(MUSICA musicas[])
{	
	int i, j, verificar = 0; 
	float notaMaior = -4;
	system("cls");
    //Limpa tela do prompt de comando

	for(i = 0; i < 10; i++) //Roda as posicoes do array
	{
		if(musicas[i].status == 1 && notaMaior < musicas[i].nota) //verifica se existe uma musica cadastrada pelo usuario nesta posicao e se a nota eh maior ate agora
		{
			notaMaior = musicas[i].nota;
            //Salva a nota maior 
			j = i;
            //Salva a posicao da nota maior
		}
		else
		{
			verificar++;
            //contador de quantas musicas não cadastradas pelo usuario possui 
		}
	}
	
    printf("Musica com maior nota eh: ");
	puts(musicas[j].nome);
	printf("Com uma nota de %.2f", notaMaior);
	//mostra o nome da musica com menor nota e a nota dela

    seguraPrograma();
    //Trava o programa ate que o usuario digite alguma coisa
}

void imprimirMusicaComMenorNota(MUSICA musicas[])
{	
	int i, j, verificar = 0; 
	float notaMenor = 999;
	system("cls");
    //Limpa tela do prompt de comando

	for(i = 0; i < 10; i++) //Roda as posicoes do array
	{
		if(musicas[i].status == 1 && notaMenor > musicas[i].nota) //Verifica se existe uma musica cadastrada pelo usuario nesta posicao e se a nota eh menor ate agora
		{
			notaMenor = musicas[i].nota;
            //Salva a nota menor
			j = i;
            //Salva a posicao da nota menor
		}
		else
		{
			verificar++;
            //Contador de quantas musicas não cadastradas pelo usuario possui
		}
	}
	
    printf("Musica com menor nota eh: ");
	puts(musicas[j].nome);
	printf("Com uma nota de %.2f", notaMenor);
	//Mostra o nome da musica com menor nota e a nota dela

    seguraPrograma();
    //Trava o programa ate que o usuario digite alguma coisa
}

void bandasCadastradas(BANDA bandas[])
{
	int i, verificar = 0;
	system("cls");
    //Limpa tela do prompt de comando

	for(i = 0; i < 10; i++) //Roda o array
	{
		if(bandas[i].status == 1) //Mostra as bandas que foram cadastradas pelo usuario
		{
			printf("Nome da Banda: ");
			puts(bandas[i].nome);
			printf("\nGenero da Banda: ");
			puts(bandas[i].genero);
			printf("\nAno de criacao da banda: ");
			puts(bandas[i].anoCriacao);
			printf("\nId da banda: %d", bandas[i].id);
			printf("\n-------------------------------\n\n");
		}
	}
    
    seguraPrograma();
    //Trava o programa ate que o usuario digite alguma coisa
}

void imprimirBandasPorGenero(BANDA bandas[])
{
	int i, verificar = 0, compara;
	char generoEscolhido[30];
	
	system("cls");
    //Limpa tela do prompt de comand
    
	printf("Digite o genero que deseja pesquisar: ");
    fflush(stdin);
	scanf("%[^\n]", generoEscolhido);
    //Pega o genero que o usuario digitar

	printf("\nNome das bandas com o genero: ");
	puts(generoEscolhido);
	for(i = 0; i < 10; i++) //Roda o array 
	{	
		
		strupr(generoEscolhido);
        //Transformar em maiusculo 
		compara = strcmp(generoEscolhido, bandas[i].genero);
        //Realiza a comparação 
		if(compara == 0) //Mostra o nome da banda se o genero bater com o escolhido
		{
			printf("\n");
			puts(bandas[i].nome);
		}
		else
		{
			verificar++;
            //Contador para olhar se não bate com o genero
		}
	}
	if(verificar == 10) //Verifica se não possui nenhuma banda com esse genero e diz ao usuario
	{
		printf("\nNenhuma banda cadastrada com esse genero.");
		
	}

    seguraPrograma();
    //Trava o programa ate que o usuario digite alguma coisa	
}

int main()
{
    BANDA bandas[10];
    //Declara a espaco para 10 bandas na memoria
    int bandaIndx = 0;
    //Declara um indice que sera passado junto com a banda

    MUSICA musicas[10];
    //Define capacidade do sistema de armazenar as 10 musicas
    int posicaoMusica = 0;
    //E define uma variavel para colocar as posicoes das musicas na funcao
	
    int opcao = menu(bandaIndx, posicaoMusica);
    //Recebe a opcao digitada pelo usu?rio

	while(opcao != 0)
	{
    	if (opcao == 1) //Se a opcao for 1 entao chama a funcao cadastra musica
    	{
    	    cadastrarMusica(musicas, posicaoMusica);
            //Chama a funcao cadastra musica
    	    posicaoMusica++;
            //Incrementa em 1 a posicao das musicas
    	}
        else if(posicaoMusica > 0){ //Se tiver musica cadastrada executa esse bloco de codigo
            if(opcao == 2){ //Se a opcao for 2 chama a funca de imprimir a musica com maior nota
                imprimirMusicaComMaiorNota(musicas);
                //Chama a funcao de imprimir a musica com a maior nota
            }
            else if(opcao == 3){    //Se a opcao for 3 chama a funcao de imprimir a musica com menor nota
                imprimirMusicaComMenorNota(musicas);
                //Chama a funcao de imprimir a musica com a menor nota
            }
            else if(opcao == 4){    //Se a opcao for 4 chama a funcao de avaliar musica
                avaliarMusica(musicas);
                //Chama a funcao de avaliar musica
            }
            else if(opcao == 5){    //Se a opcao for 5 chama a funcao de cadastrar banda
                cadastrarBanda(bandas, bandaIndx);
                //Chama a funcao cadastrar banda
    	        bandaIndx++;
                //Incrementa em 1 a posicao das bandas
            }
            else if(opcao == 6){    //Se a opcao for 6 chama a funcao de imprimir bandas cadastradas
                bandasCadastradas(bandas);
                //Chama a funcao de imprimir bandas cadastradas
            }
            else{   //Se a opcao for 7 chama a funcao de buscar banda pelo
                imprimirBandasPorGenero(bandas);
                //Chama a funcao de buscar banda pelo genero
            }
        }
        else{   //Se nao tem musica cadastrada executa esse bloco de codigo
            if(opcao == 2){ //Se a opcao for 2 chama a funcao de cadastrar banda
                cadastrarBanda(bandas, bandaIndx);
                //Chama a funcao de cadastrar bandas
                bandaIndx++;
                //Incrementa em 1 a posicao das bandas
            }
            else if(opcao == 3){    //Se a opcao for 3 chama a funcao de imprimir bandas cadastradas
                bandasCadastradas(bandas);
                //Chama a funcao de imprimir bandas cadastradas
            }
            else{    //Se a opcao for 4 chama a funcao de buscar banda pelo genero
                imprimirBandasPorGenero(bandas);
                //Chama a funcao de buscar banda pelo genero
            }
        }

        opcao = menu(bandaIndx, posicaoMusica);
        //Apresenta o menu ao usuario para que ele posso escolher para onde quer ir
	}
    
    printf("Encerrando o programa...");
    
    seguraPrograma();
    //Trava o programa ate que o usuario digite alguma coisa
    
	return 0;
}

void seguraPrograma(){
    char a = '\0';
    //Cria uma variavel so pra receber o que o usuario vai digitar

    printf("\n\nPressione qualquer coisa para continuar");
    fflush(stdin);
    scanf("%c", &a);
    //Trava o programa ate que o usuario digite algo
}

int menu(int qtdBandas, int qtdMusicas)
{
    int opcao = (-1);
    //Variavel que vai receber o que o usuario digitar
    //E posteriormente vai ser retornada
    char traco[15] = {205, 205, 205, 205, 205, 205, 205, 205, 205, 205};
    //Uma string para fins de estetica do programa. Sao 10 caracteres parecidos com o =
    int inicioIntervalo = 0;
    //Define um o inicio do intervalo aceito nas opcoes do menu
    int fimIntervalo = 2;
    //Define, parcialmente, o fim do intervalo ecito nas opcoes do menu

    if((qtdMusicas == 0) && (qtdBandas == 0)){
        fimIntervalo = 2;
    }
    else if((qtdMusicas == 0) && (qtdBandas > 0)){
        fimIntervalo = 4;
    }
    else if((qtdMusicas > 0) && (qtdBandas == 0)){
        fimIntervalo = 5;
    }
    else{
        fimIntervalo = 7;
    }

    while((opcao < inicioIntervalo) || (opcao > fimIntervalo)){
        system("cls");
        //Limpa tela do prompt de comando

        printf("%s%sMENU%s%s", traco, traco, traco, traco);
        printf("\n0 - Sair do programa");

        if(qtdMusicas > 0){     //Se tem musica cadastrada apresenta o menu com as opcoes que envolve as musicas
            printf("\n1 - Cadastrar musica");
            printf("\n2 - Musica com maior nota");
            printf("\n3 - Musica com menor nota");
            printf("\n4 - Avaliar uma musica");
            printf("\n5 - Cadastrar banda");
            
            if(qtdBandas > 0){  //E ainda se tem banda cadastrada apresenta o menu com as opcoes que envolve as bandas
                printf("\n6 - Bandas cadastradas");
                printf("\n7 - Buscar banda pelo genero");
            }
        }
        else{                   //Se nao tem musica cadastra executa esse bloco de código
            if(qtdBandas > 0){  //Se tem banda cadastrada apresenta o menu com as opcoes que envolve a banda
                printf("\n1 - Cadastrar musica");
                printf("\n2 - Cadastrar banda");
                printf("\n3 - Bandas cadastradas");
                printf("\n4 - Buscar banda pelo genero");
            }
            else{               //Se nao tem banda cadastrada apresenta o menu com a opcao de cadastrar musica e banda
                printf("\n1 - Cadastrar musica");
                printf("\n2 - Cadastrar banda");
            }
        }
        //Apresenta as opcoes disponiveis

        printf("\n\nDigite uma opcao valida: ");
        scanf("%d", &opcao);
        //Recebe a opcao do usuario
    }

    return opcao;
    //Retorna a opcao valida que foi digitada pelo usuario
}
