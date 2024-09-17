//AUTHOR: GABRIEL CARDOSO   
//GITHUB: https://github.com/gabrielentediado

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "funcInit.h"

int main(){
    printf("Iniciando o menu\n");
    menu(NULL, NULL);
}

void menu(Produto *prod_cadastrados, int *tamanho){
    printf("Digite:\n");
    printf("1-Para cadastrar um novo produto\n2-listar produtos cadastrados\n3-adicionar produto ao carrinho\n4-visualizar carrinho\n5-sair");
    scanf("%d", &menuNav);
    getchar();
    switch (menuNav) {
        case 1:
        cadastrar_produtos();
        break;
        case 2: 
        listar_produtos(prod_cadastrados, tamanho);
        break;
        case 3: 
        comprar_produtos();
        break;
        case 4:
        visualizar_carrinho();
        break;

        case 5:
        printf("obrigado, volte sempre");
        break;

        default:
        menu(prod_cadastrados, tamanho);
        break;
    }
}

void comprar_produtos(){

    Carrinho carrinho[50]; 
    //adicionar ao carrinho só produtos cadastrados
    printf("Produtos que estão no supermecado: ");

}

void listar_produtos(Produto *produtos_cadastrados, int *tamanho){
    printf("listando produtos\n");

    for (int i=0; i<*tamanho; i++) {
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, (produtos_cadastrados+i)->nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, (produtos_cadastrados+i)->codigo);
        printf("Quantidade do %d° produto cadastrado no sistema: %f \n", i+1, (produtos_cadastrados+i)->preco);
        puts("");
    }
    printf("Todos produtos foram mostrados com sucesso");
    sleep(5);
    menu(produtos_cadastrados, tamanho);
}
void cadastrar_produtos(){
    //para cadastrar
    Produto produtos[50];
    int N;
    printf("Deseja cadastrar quantos produtos\n");
    scanf("%d", &N);
    char nome[20][N]; 
    
    for (int i=0; i<N; i++) {
        printf("Digite o codigo do %d° produto\n(limite de nome 20 letras)\n", i+1);
        scanf("%d", &produtos[i].codigo);   

        printf("Digite o nome do %d° produto\n", i+1);
        scanf("%20s", nome[i]);

        strcpy(produtos[i].nome, nome[i]);

        printf("Digite o  preço do %d° produto\n", i+1);
        scanf("%f", &produtos[i].preco);
       
    }
    sleep(5);
    printf("voltando para menu\n");
    menu(produtos, &N);
}