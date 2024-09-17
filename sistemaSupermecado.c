//AUTHOR: GABRIEL CARDOSO   
//GITHUB: https://github.com/gabrielentediado

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "funcInit.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int menuNav = 0; 

int main(){
    Produto produtos[50];
    int N = 0;

    printf("Iniciando o menu:\n");
    sleep(3);
    menu(produtos, &N);

    return 0;
}

void menu(Produto *prod_cadastrados, int *tamanho){
    
    printf("Digite:\n");
    printf("1-Para cadastrar um novo produto\n2-listar produtos cadastrados\n3-ir para sessão de compras\n4-visualizar carrinho\n5-sair\n");
    scanf("%d", &menuNav);
    getchar();

    switch (menuNav) {
        case 1:
        cadastrar_produtos(prod_cadastrados, tamanho);   
        break;
        case 2: 
        listar_produtos(prod_cadastrados, tamanho);
        break;
        comprar_produtos(prod_cadastrados, tamanho);
        break;

        default:
        menu(prod_cadastrados, tamanho);
        break;
    }
}

void comprar_produtos(Produto *produtos_cadastrados, int *tamanho){
    Carrinho produtos_carrinho[50];

    printf("Mostrando todos os produtos do supermecado \n");
    
    for (int i=0; i<*tamanho; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, (produtos_cadastrados+i)->nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, (produtos_cadastrados+i)->codigo);
        printf("Quantidade do %d° produto cadastrado no sistema: %2f \n", i+1, (produtos_cadastrados+i)->preco);
        printf("_____________________________________________________________________________\n");
        puts("");
    }

}


void listar_produtos(Produto *produtos_cadastrados, int *tamanho){
    printf("listando produtos\n");

    for (int i=0; i<*tamanho; i++) {
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, (produtos_cadastrados+i)->nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, (produtos_cadastrados+i)->codigo);
        printf("Quantidade do %d° produto cadastrado no sistema: %2f \n", i+1, (produtos_cadastrados+i)->preco);
        puts("");
    }
    printf("Todos produtos foram mostrados com sucesso");
    sleep(5);
    menu(produtos_cadastrados, tamanho);
}

void cadastrar_produtos(Produto * produtos, int * N){
    //para cadastrar
   
    printf("Deseja cadastrar quantos produtos?\n");
    scanf("%d", N);
    getchar();
    
    for (int i=0; i<*N; i++) {

        system(CLEAR);
        printf("__________________________________________________________________________\n\n");
        printf("Digite o codigo do %d° produto: \n", i+1);
        scanf("%d", &produtos[i].codigo);   

        printf("Digite o nome do %d° produto (limite de letras 20): \n", i+1);
        scanf("%19s", produtos[i].nome);

        printf("Digite o  preço do %d° produto: \n", i+1);
        scanf("%f", &produtos[i].preco);

    }
    sleep(5);
    printf("voltando para menu\n");

    menu(produtos, N);
}