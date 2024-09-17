#ifndef FUNCINIT_H
#define FUNCINIT_H

typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct{
    Produto produto; 
    int quantidade; 
}Carrinho;


void menu(Produto *prod_cadastrados, int *tamanho);
void listar_produtos(Produto *produtos_cadastrados, int *tamanho);

void cadastrar_produtos();
void comprar_produtos();
void visualizar_carrinho();
void fechar_pedido();
void tem_no_carrinho();
void pegar_preoduto_por_codigo();

extern int menuNav;

#endif