#ifndef FUNCINIT_H
#define FUNCINIT_H

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

void menu(Produto *prod_cadastrados, int *tamanho);
void listar_produtos(Produto *produtos_cadastrados, int *tamanho);
void cadastrar_produtos(Produto *produtos, int *N);
void comprar_produtos(Produto *produtos_cadastrados, int *tamanho);
void visualizar_carrinho();

void fechar_pedido(Carrinho *carrinho, int tamanho);
int tem_no_carrinho(Carrinho *carrinho, int tamanho, int codigo);

Produto* pegar_produto_por_codigo(Produto *produtos, int tamanho, int codigo);

extern int menuNav;

#endif
