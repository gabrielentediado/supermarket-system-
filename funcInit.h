#ifndef FUNCINIT_H
#define FUNCINIT_H

/* 
CRIEI UM ARQUIVO HEADER SÓ PARA FICAR ORGANIZADO O CÓDIGO
*/


/* STRUCT DO PRODUTO, COM OS REGISTROS DE CODIGO, NOME, E PREÇO COM SEUS RESPECTIVOS TIPOS DE DADOS */
typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

/* STRUCT DO CARRINHO COM UMA STRUCT PRODUTO ANINHADA */
typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

/* HEADERS PARA AS FUNÇÕES, PARA NÃO FICAR AQUELA LINHA AMARELA DEBAIXO DO CÓDIGO */

void menu(Produto *prod_cadastrados, int *tamanho);
void listar_produtos(Produto *produtos_cadastrados, int *tamanho);
void cadastrar_produtos(Produto *produtos, int *N);
void comprar_produtos(Produto *produtos_cadastrados, int *tamanho);
void visualizar_carrinho(Produto *produtos_cadastrados, int *tamanho2);
int tem_no_carrinho(int codigo, int * tamanho); //Carrinho *carrinho, int tamanho, int codigo


void fechar_pedido();

Produto* pegar_produto_por_codigo(Produto *produtos, int tamanho, int codigo); //Produto *produtos, int tamanho, 

extern int menuNav;

#endif
