#include <stdio.h>
#include <stdlib.h>

int menu();

int main(){
    int opcao = menu();
    //Recebe a opção digitada pelo usuário

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