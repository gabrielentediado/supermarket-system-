//AUTHOR: GABRIEL CARDOSO   
//GITHUB: https://github.com/gabrielentediado

#include <complex.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/*

Professor, não se fiz o código do jeito certo, achei que ia ser legal se o usuário conseguisse adicionar mais de um item ao carrinho, 
mas tive que mudar algumas coisas do código para isso funcionar, acho que ia funcionar melhor se o N (do tamanho), fosse em alocação dinâmica

*/


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
int tamanho=0;
int quantidade_itens_carrinho=0;

/* Aqui na função main só chama o Switch case para o menu para o usuário */
int main(){
    /* AQUI CRIA A VARIÁVEL DE UM STRUCT, QUE SERÁ MUITO ÚTIL */
    Produto produtos[50];
    int N = 0;

    //iniciar o código e o preço em 0 
    for (int i=0; i<50; i++) {
        produtos[i].preco = 0; 
        produtos[i].codigo = 0;
    }/* COLOQUEI O I PARA SER O VALOR DO TAMANHO, POIS TODA VEZ QUE VOLTAR NESSA FUNÇÃO O I VAI RECEBER O VALOR DO TAMANHO, ASSIM NÃO SOBRESCREVE NO SISTEMA */
    
    printf("Iniciando o menu...\n");
    sleep(3); /* AQUI TEM UM DELAY DE 3 SEGUNDOS */
    menu(produtos, &N);

    return 0;
}
/* O menu instância ponteiros recebendo o array dos produtos de struct produto e o valor do tamanho */
void menu(Produto *prod_cadastrados, int *tamanho){

    int codigo;
    system(CLEAR);
    printf("Digite:\n");
    printf("1-Para cadastrar um novo produto\n2-listar produtos cadastrados\n3-adicionar ao carrinho\n4-visualizar carrinho\n5-fechar pedido\n6-pequisar por codigo\n-sair\n");
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
        case 5:
        fechar_pedido(tamanho);
        break;
        case 6:
       
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);
        Produto *produto = pegar_produto_por_codigo(prod_cadastrados, *tamanho, codigo);
        if (produto != NULL) {
            printf("Produto encontrado: %s\n", produto->nome);
        } else {
            printf("Produto não encontrado.\n");
        }
        sleep(2);
        
        break;
        
        default:
        menu(prod_cadastrados, tamanho);
        break;
    }
}

Produto* pegar_produto_por_codigo(Produto *produtos, int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (produtos[i].codigo == codigo) {
            return &produtos[i];
        }
    }
    return NULL;
}

/* AQUI TALVEZ SEJA A PARTE MAIS SIMPLES DO CÓDIGO, É SÓ UMA INTEIRAÇÃO NORMAL EM UM LOOP FOR */

void visualizar_carrinho(Produto *produtos_cadastrados, int *tamanho2){
    system(CLEAR);

    for (int i=0; i < quantidade_itens_carrinho; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Produto número: %d\n", i+1);
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, produtos_carrinho[i].produto.nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, produtos_carrinho[i].produto.codigo);
        printf("Quantida do produto no seu carrinho: %d \n", produtos_carrinho[i].quantidade+1); /*A QUANTIDADE TAVA COMEÇANDO EM 0, ENTÃO SÓ ADICIONEI +1, VISTO QUE O ARRAY COMEÇA EM 0*/
        printf("Preço do %d° produto cadastrado no sistema: %.2f \n", i+1, produtos_carrinho[i].produto.preco);
        printf("_____________________________________________________________________________\n");
        puts("");
    }
    sleep(10);
    menu(produtos_cadastrados, tamanho2);
}


void fechar_pedido(){
    system(CLEAR);

    for (int i=0; i < quantidade_itens_carrinho; i++) {
        printf("_____________________________________________________________________________\n\n");
        printf("Produto número: %d\n", i+1);
        printf("Nome do %d° produto cadastrado no sistema: %s \n", i+1, produtos_carrinho[i].produto.nome);
        printf("Código do %d° produto cadastrado no sistema: %d \n", i+1, produtos_carrinho[i].produto.codigo);
        printf("Quantida do produto no seu carrinho: %d \n", produtos_carrinho[i].quantidade+1);
        printf("Preço do %d° produto cadastrado no sistema: %.2f \n", i+1, produtos_carrinho[i].produto.preco);
        printf("_____________________________________________________________________________\n");
        puts("");
    }
    sleep(10);

    /* CALCULAR O VALOR DO PEDIDO, O ALGORITMO É ATÉ AUTOMATIZADO,  EX: SE COLOCAR 3 BANANAS, VAI FAZER (3 * PREÇO), DE CADA POSIÇÃO DO ARRAY*/

    /* E DEPOIS E SÓ SOMAR TUDO */
    float  somar=0;
    float multiplicações[50];
    int quantidade=0; 

    for (int i=0; i < quantidade_itens_carrinho; i++) {
        quantidade = quantidade + produtos_carrinho[i].quantidade+1; 
    }

    printf("Quantidade total de produtos no carrinho %d\n", quantidade);
    sleep(5);

    for (int i=0; i < quantidade_itens_carrinho; i++) {
        multiplicações[i] = produtos_carrinho[i].produto.preco * (produtos_carrinho[i].quantidade+1); 
        somar = somar + multiplicações[i]; 
    }

    printf("Total da compra: %.2f\n", somar);

    printf("Deseja finalizar compra? \n1-para sim\n2-para não\n");

    scanf("%d", &menuNav);
    printf("Preço total: %.2f", somar);
    sleep(5);

}


int tem_no_carrinho(int codigo, int * tamanho){
    int i; 
    int verificar;
    for (i = 0; i < *tamanho; i++) {
        if (codigo == produtos_carrinho[i].produto.codigo) {
            verificar = 1; 
            break;
        }
    
    }
    if (verificar == 1) {
        return i; 
    }else {
        return -1;
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
            int verificar;
            int numero;
            printf("\nDigite\n 1- Para adiconar produto pelo NÚMERO\n2- Para adicionar pelo CÓDIGO \n");
            scanf("%d", &menuNav);
            if (menuNav == 1) {
                printf("Digite o numero \n"); 
                scanf("%d", &numero);
            }else {
                int codigo;
                printf("Digite o código do produto\n"); 
                scanf("%d", &codigo);
                for (int i = 0; i<50; i++) {
                    int prod_codigo = (produtos_cadastrados+i)->codigo;
                    if (prod_codigo == codigo) {
                        verificar = 1;
                        break;
                    }else {
                        printf("Código inválido\n");
                        sleep(2);
                        comprar_produtos(produtos_cadastrados, tamanho);
                    }
                }
                if (verificar == 1) {
                        if ((produtos_cadastrados+i)->codigo != 0 && tem_no_carrinho((produtos_cadastrados+i)->codigo, tamanho) == -1) {    /* ISSO AQUI É PARA EVITAR DELE CONSEGUIR ADICIONAR ITENS REPETIDOS, EM NOVAS POCIÇÕES, VAI "ADICIONAR" O ITEM REPETIDO NA POSIÇÃO DO QUE SE REPETE */
                        strcpy(produtos_carrinho[i].produto.nome, (produtos_cadastrados+i)->nome);
                        produtos_carrinho[i].produto.codigo = (produtos_cadastrados+i)->codigo;
                        produtos_carrinho[i].produto.preco = (produtos_cadastrados+i)->preco;   
                        produtos_carrinho[i].quantidade += i;
                        quantidade_itens_carrinho++;
                        i++;
                    }else{
                        produtos_carrinho[tem_no_carrinho((produtos_cadastrados+i)->codigo, tamanho)].quantidade++; /* COLOQUEI O RETORNO DA FUNÇÃO QUE É O INDICE DENTRO DO ARRAY , CASO O PRODUTO TENHA NO CARRINHO, A ADIÇÃO VAI SER FEITA NA POCIÇÃO DE QUANTIDADE QUE A FUNÇÃO RETORNOU*/
                    }
                }
                printf("Produto cadastrado\n");
                sleep(5);
                menu(produtos_cadastrados, tamanho);
            }
    
            getchar(); //LIMPAR BUFFER, ESSE PROBLEMA É MEIO CHATO
            //aqui só copia os valores, só se o valor do código for diferente de 0 (ENTÃO O PRODUTO TEM QUE EXISITIR NO MERCADO)
            if ((produtos_cadastrados+numero-1)->codigo != 0 && tem_no_carrinho((produtos_cadastrados+numero-1)->codigo, tamanho) == -1) {    /* ISSO AQUI É PARA EVITAR DELE CONSEGUIR ADICIONAR ITENS REPETIDOS, EM NOVAS POCIÇÕES, VAI "ADICIONAR" O ITEM REPETIDO NA POSIÇÃO DO QUE SE REPETE */
                strcpy(produtos_carrinho[i].produto.nome, (produtos_cadastrados+numero-1)->nome);
                produtos_carrinho[i].produto.codigo = (produtos_cadastrados+numero-1)->codigo;
                produtos_carrinho[i].produto.preco = (produtos_cadastrados+numero-1)->preco;   
                produtos_carrinho[i].quantidade += i;
                quantidade_itens_carrinho++;
                i++;
            }else{
                produtos_carrinho[tem_no_carrinho((produtos_cadastrados+numero-1)->codigo, tamanho)].quantidade++; /* COLOQUEI O RETORNO DA FUNÇÃO QUE É O INDICE DENTRO DO ARRAY , CASO O PRODUTO TENHA NO CARRINHO, A ADIÇÃO VAI SER FEITA NA POCIÇÃO DE QUANTIDADE QUE A FUNÇÃO RETORNOU*/
            }

            printf("Digite\n1- para adicionar outro produto\n2 ou qualquer outra número - para sair\n");
            scanf("%d", &sair);

        }while (sair==1);
        printf("Produtos adicionados, voltando para o menu\n");
        sleep(2);
        menu(produtos_cadastrados, tamanho);
        
        break; 

        case 2:
        menu(produtos_cadastrados, tamanho);
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

//int tam_aux=0;   
void cadastrar_produtos(Produto * produtos, int * N){
    system(CLEAR);
    printf("Deseja cadastrar quantos produtos? (limite de 50 produtos)\n");
    scanf("%d", N);

    getchar(); // limpa o buffer do newline

    if (*N > 50) {
        printf("númeoro inválido\nreiniciando probrama\n"); //coloquei isso porque sem querer eu digitava um numero muito alto quando ia testar sem querer kkkkkk 
        cadastrar_produtos(produtos, N);
        sleep(1);
    }


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

        printf("Digite o preço do %d° produto: (por segurança, digte dessa forma, ex: 20)\n", i + 1);
        scanf("%2f", &produtos[i].preco);
        getchar(); // limpa o buffer do newline 

    }

    printf("Cadastrado, voltando para menu\n");
    
    tamanho += *N; //tive uma sacada não tão boa aqui, o tamanho tá adicionando o valor dele mais ao tamanho que o usuário digitou, mas o problema é que cria mais uma variável
    //tam_aux = tam_aux + (*N); a ideia nessa parte era colocar no loop, para toda vez que o usuário retornar na função os valores não serem sobrescritos, mas não funcionou

    sleep(5);
    menu(produtos, N);
}