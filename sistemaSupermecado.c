//AUTHOR: GABRIEL CARDOSO   
//GITHUB: https://github.com/gabrielentediado

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "funcInit.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int menuNav = 0; 
Carrinho produtos_carrinho[50];

int main(){
    Produto produtos[50];
    int N = 0;

    printf("Iniciando o menu...\n");
    sleep(3);
    menu(produtos, &N);

    return 0;
}

void menu(Produto *prod_cadastrados, int *tamanho){
    system(CLEAR);
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
        case 3:
        comprar_produtos(prod_cadastrados, tamanho);
        break;
        case 4:
        visualizar_carrinho(prod_cadastrados, tamanho);
        break;
        default:
        menu(prod_cadastrados, tamanho);
        break;
    }
}

void visualizar_carrinho(Produto *produtos_cadastrados, int *tamanho2){
    system(CLEAR);

    for (int i=0; i < produtos_carrinho[0].quantidade; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Produto número: %d\n", i+1);
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, produtos_carrinho[i].produto.nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, produtos_carrinho[i].produto.codigo);
        printf("Preço do %d° produto cadastrado no sistema: %2f \n", i+1, produtos_carrinho[i].produto.preco);
        printf("_____________________________________________________________________________\n");
        puts("");
    }
    sleep(10);
    menu(produtos_cadastrados, tamanho2);
}

void comprar_produtos(Produto *produtos_cadastrados, int *tamanho){
    system(CLEAR);
    printf("Mostrando todos os produtos do supermecado: \n");
    
    for (int i=0; i<*tamanho; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Produto número: %d\n", i+1);
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, (produtos_cadastrados+i)->nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, (produtos_cadastrados+i)->codigo);
        printf("Preço do %d° produto cadastrado no sistema: %2f \n", i+1, (produtos_cadastrados+i)->preco);
        printf("_____________________________________________________________________________\n");
        puts("");
    }
    int sair=1;
    int i=0; 

    printf("Digite\n1-para adicionar produtos ao carrinho\n2-para cancelar e sair\n");
    scanf("%d", &menuNav);
    switch (menuNav) {
        case 1:
        do {
            int numero;
            printf("Digite o número do produto para adicionar\n");
            scanf("%d", &numero);

            if ((produtos_cadastrados+numero-1) != NULL) {    
                strcpy(produtos_carrinho[i].produto.nome, (produtos_cadastrados+numero-1)->nome);
                produtos_carrinho[i].produto.codigo = (produtos_cadastrados+numero-1)->codigo;
                produtos_carrinho[i].produto.preco = (produtos_cadastrados+numero-1)->preco;   
            }else {
                printf("Produto não encontrado, tente novamente\n");
            }
            i++;

            produtos_carrinho[0].quantidade = i;

            printf("digite\n1- para adicionar outro produto\n2-para sair\n");
            scanf("%d", &sair);

        }while (sair==1);
        printf("Produtos adicionados, voltando para o menu\n");
        menu(produtos_cadastrados, tamanho);
        
        break; 

        case 2:
        break;
    }
}
void listar_produtos(Produto *produtos_cadastrados, int *tamanho){
    system(CLEAR);
    printf("listando produtos\n");

    for (int i=0; i<*tamanho; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, (produtos_cadastrados+i)->nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, (produtos_cadastrados+i)->codigo);
        printf("Quantidade do %d° produto cadastrado no sistema: %2f \n", i+1, (produtos_cadastrados+i)->preco);
        printf("_____________________________________________________________________________\n\n");
        puts("");
    }
    printf("Todos produtos foram mostrados com sucesso");
    sleep(5);
    menu(produtos_cadastrados, tamanho);
}

void cadastrar_produtos(Produto * produtos, int * N){
    //para cadastrar
    system(CLEAR);
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
        scanf("%2f", &produtos[i].preco);

    }
    printf("Cadastrado, voltando para menu\n");
    
    sleep(5);
    menu(produtos, N);
}