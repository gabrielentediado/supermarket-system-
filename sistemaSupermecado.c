//AUTHOR: GABRIEL CARDOSO   
//GITHUB: https://github.com/gabrielentediado

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "funcInit.h"

/* Aqui é só para definir o sistema, se é linux ou windows, pois o comando de limpar tela é diferente */
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

//variaveis globais
int menuNav = 0; 
Carrinho produtos_carrinho[50];

/* Aqui na função main só chama o Switch case para o menu para o usuário */
int main(){
    /* AQUI CRIA A VARIÁVEL DE UM STRUCT, QUE SERÁ MUITO ÚTIL */
    Produto produtos[50];
    int N = 0;

    //iniciar o código e o preço em 0 
    for (int i=0; i<50; i++) {
        produtos[i].preco = 0; 
        produtos[i].codigo = 0;
    }
    printf("Iniciando o menu...\n");
    sleep(3); /* AQUI TEM UM DELAY DE 3 SEGUNDOS */
    menu(produtos, &N);

    return 0;
}
/* O menu instância ponteiros recebendo o array dos produtos de struct produto e o valor do tamanho */
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

/* AQUI TALVEZ SEJA A PARTE MAIS SIMPLES DO CÓDIGO, É SÓ UMA INTEIRAÇÃO NORMAL EM UM LOOP FOR */

void visualizar_carrinho(Produto *produtos_cadastrados, int *tamanho2){
    system(CLEAR);

    for (int i=0; i < produtos_carrinho[0].quantidade; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Produto número: %d\n", i+1);
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, produtos_carrinho[i].produto.nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, produtos_carrinho[i].produto.codigo);
        printf("Quantida do produto no seu carrinho: %d \n", produtos_carrinho[i].quantidade);
        printf("Preço do %d° produto cadastrado no sistema: %.2f \n", i+1, produtos_carrinho[i].produto.preco);
        printf("_____________________________________________________________________________\n");
        puts("");
    }
    sleep(10);
    menu(produtos_cadastrados, tamanho2);
}



int tem_no_carrinho(int codigo, int * tamanho){

    int verificar;
    for (int i = 0; i < *tamanho; i++) {
    
        if (codigo == produtos_carrinho[i].produto.codigo) {
            verificar = 1; 
            break;
        }
    
    }
    if (verificar == 1) {
        return 1; 
    }else {
        return 0;
    }
}

/* 

AQUI E PARA ADICIONAR AO CARRINHO SÓ PENSEI EM COLOCAR O VALOR DOS PRODUTOS CADASTRADOS NA STRUCT ANINHADA
AÍ CRIEI UM ARRAY GLOBAL PARA FICAR MAIS FÁCIL DE MANIPULAR

"Carrinho produtos_carrinho[50];"

 */

void comprar_produtos(Produto *produtos_cadastrados, int *tamanho){
    system(CLEAR);
    printf("Mostrando todos os produtos do supermecado: \n");
    
    for (int i=0; i<*tamanho; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("NÚMERO DO PRODUTO: %d\n", i+1);
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, (produtos_cadastrados+i)->nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, (produtos_cadastrados+i)->codigo);
        printf("Preço do %d° produto cadastrado no sistema: R$%.2f \n", i+1, (produtos_cadastrados+i)->preco);
        printf("_____________________________________________________________________________\n");
        puts("");
    }
    int sair=1;
    int i=0; 

    printf("Digite\n1-para adicionar produtos ao carrinho\n2-para cancelar e sair\n");
    scanf("%d", &menuNav);
    switch (menuNav) {
        case 1:
        /*
            O FUNCIONAMENTO DESSE DO E WHILE TÁ PARECENDO UM FOR, MAS EU QUERIA QUE O USUÁRIO FICASSE PRESO DENTRO DA PARTE DE ADICIONAR UM PRODUTO NO CARRINHO
            SE A VARIÁVEL 'SAIR' FOR DIFERENTE DE 1 O LOOP QUEBRA, E A VARIÁVEL i VAI INCREMENTANDO PARA COLOCAR EM ORDEM NO ARRAY DO CARRINHO
        */
        do {
            int numero;
            printf("Digite o número do produto para adicionar \n");
            scanf("%d", &numero);
    
            getchar(); //LIMPAR BUFFER, ESSE PROBLEMA É MEIO CHATO
            //aqui só copia os valores, só se o valor do código for diferente de 0 
            if ((produtos_cadastrados+numero-1)->codigo != 0 && tem_no_carrinho((produtos_cadastrados+numero-1)->codigo, tamanho) == 1) {    /* ISSO AQUI É PARA EVITAR DELE CONSEGUIR ADICIONAR ITENS REPETIDOS, AÍ SÓ VAI AUMENTA A QUANTIDADE DE PRODUTOS  */
                strcpy(produtos_carrinho[i].produto.nome, (produtos_cadastrados+numero-1)->nome);
                produtos_carrinho[i].produto.codigo = (produtos_cadastrados+numero-1)->codigo;
                produtos_carrinho[i].produto.preco = (produtos_cadastrados+numero-1)->preco;   
                produtos_carrinho[i].quantidade += i;
                i++;
            }else if(tem_no_carrinho((produtos_cadastrados+numero-1)->codigo, tamanho) == 0){
                produtos_carrinho[i].quantidade += i;
            }

            printf("digite\n1- para adicionar outro produto\n2 ou qualquer outra número - para sair\n");
            scanf("%d", &sair);

        }while (sair==1);
        printf("Produtos adicionados, voltando para o menu\n");
        sleep(2);
        menu(produtos_cadastrados, tamanho);
        
        break; 

        case 2:
        break;
    }
}

/* AQUI LISTA OS PRODUTOS, CRIEI OUTRO PONTEIRO PARA APONTAR PARA O ARRAY DE STRUCT  */
void listar_produtos(Produto *produtos_cadastrados, int *tamanho){
    system(CLEAR);
    printf("listando produtos\n");

    for (int i=0; i<*tamanho; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, (produtos_cadastrados+i)->nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, (produtos_cadastrados+i)->codigo);
        printf("Quantidade do %d° produto cadastrado no sistema: %.2f \n", i+1, (produtos_cadastrados+i)->preco);
        printf("_____________________________________________________________________________\n\n");
        puts("");
    }
    printf("Todos produtos foram mostrados com sucesso\n");
    sleep(5);
    menu(produtos_cadastrados, tamanho);
}

void cadastrar_produtos(Produto * produtos, int * N){
    //para cadastrar
    system(CLEAR);
    printf("Deseja cadastrar quantos produtos?\n");
    scanf("%d", N);
    getchar();

    /* AQUI FOI A PRIMEIRA PARTE QUE FIZ DO CÓDIGO, A FUNÇÃO DE CADASTRO */
    /* A FUNÇÃO INSTÂNCIA UM PONTEIRO PARA O TIPO DE DADO STRUCT, (A VARIÁVEL ESTÁ LÁ NA MAIN, E É UM ARRAY DE STRUCT) ENTÂO PARA ATRIBUIR VALOR: */
    /* É SÓ COLOCAR A VARIÁVEL COM UM . (dot) E ESPECIFICAR*/
    
    for (int i=0; i<*N; i++) {
       system(CLEAR);
        printf("__________________________________________________________________________\n\n");
        printf("Digite o codigo do %d° produto: \n", i + 1);

        scanf("%d", &produtos[i].codigo);
        getchar(); // limpa o buffer do newline

        printf("Digite o nome do %d° produto (limite de letras 20): \n", i + 1);
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        strtok(produtos[i].nome, "\n"); // remove o newline do final

        printf("Digite o preço do %d° produto: \n", i + 1);
        scanf("%2f", &produtos[i].preco);
        getchar(); // limpa o buffer do newline 

    }

    printf("Cadastrado, voltando para menu\n");
    
    int tamanho;
    tamanho += *N; //tive uma sacada não tão boa aqui, o tamanho tá adicionando o valor dele mais ao tamanho que o usuário digitou, mas o problema é que cria mais uma variável

    sleep(5);
    menu(produtos, &tamanho);
}