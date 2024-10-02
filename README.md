# Sistema Supermercado

Este é um programa simples para gerenciar um supermercado, escrito em C. O sistema permite cadastrar produtos, listar produtos cadastrados, adicionar produtos ao carrinho, visualizar o carrinho, fechar pedido e pesquisar produtos por código.

## Funcionalidades

- **Cadastro de Produtos**: Permite cadastrar novos produtos no sistema.
- **Listar Produtos**: Exibe todos os produtos cadastrados.
- **Adicionar ao Carrinho**: Adiciona produtos ao carrinho de compras.
- **Visualizar Carrinho**: Mostra os produtos atualmente no carrinho.
- **Fechar Pedido**: Calcula o valor total do pedido e exibe as informações finais.
- **Pesquisar por Código**: Permite encontrar um produto específico pelo código.

## Como Compilar e Executar

### Pré-requisitos

1. **Compilador C**: Instale um compilador C, como GCC.
2. **Editor de Texto ou IDE**: Utilize um editor de texto ou IDE para editar o código.

### Passos para Compilar e Executar

1. **Clone o Repositório**

```bash
git clone https://github.com/gabrielentediado/supermarket-system-
cd sistemaSupermercado


gcc -o sistemaSupermercado sistemaSupermercado.c

./sistemaSupermercado   # No Linux/MacOS
sistemaSupermercado.exe # No Windows
```

# Estrutura do Projeto

O projeto é composto por várias funções que realizam operações específicas:

    **menu(Produto prod_cadastrados, int tamanho):

        Exibe um menu de opções para o usuário escolher a operação que deseja realizar.

    **listar_produtos(Produto produtos_cadastrados, int tamanho):

        Lista todos os produtos cadastrados no sistema.

    **cadastrar_produtos(Produto produtos, int N):

        Permite ao usuário cadastrar novos produtos no sistema.

    **comprar_produtos(Produto produtos_cadastrados, int tamanho):

        Adiciona produtos ao carrinho de compras.

    **visualizar_carrinho(Produto produtos_cadastrados, int tamanho2):

        Mostra os produtos atualmente no carrinho de compras.

    *tem_no_carrinho(int codigo, int tamanho):

        Verifica se um produto está no carrinho com base no código do produto.

    fechar_pedido():

        Calcula o valor total do pedido e exibe as informações finais.

    *pegar_produto_por_codigo(Produto produtos, int tamanho, int codigo):

        Permite encontrar um produto específico pelo código.

#Desenvolvimento

O sistema foi desenvolvido seguindo boas práticas de programação em C, com atenção especial à modularidade e clareza do código. As structs Produto e Carrinho foram criadas para armazenar informações sobre os produtos e o carrinho de compras, respectivamente. As funções foram organizadas em um arquivo header (funcinit.h) para manter o código limpo e organizado.

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests.
