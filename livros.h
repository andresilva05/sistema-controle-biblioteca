#ifndef LIVROS_H
#define LIVROS_H

// Constantes do sistema
#define MAX_LIVROS 50    // Limite máximo de livros que o sistema pode armazenar
#define TAM_MAX_NOME 100 // Quantidade máxima de caracteres para nome de livro ou autor

// Estrutura que representa um Livro no sistema
typedef struct
{
    int id;                   // Identificador único do livro
    char nome[TAM_MAX_NOME];  // Nome/título do livro
    char autor[TAM_MAX_NOME]; // Nome do autor
    int quantidade;           // Quantidade de exemplares disponíveis
    float preco;              // Preço unitário do livro
    int ativo;                // Status do livro: 1 = ativo / 0 = removido
} Livro;

// Função para incluir um novo livro no sistema
void incluir_livro();

// Função para listar todos os livros cadastrados
void listarLivros();

// Função para atualizar o estoque de um livro existente
void atualizar_estoque();

// Função para buscar um livro pelo nome ou ID
void buscar_livro();

// Função para calcular o valor total do estoque (quantidade × preço unitário)
void calcular_valor_total();

// Função para gerar um relatório com livros que possuem baixo estoque
void relatorio_estoque_baixo();

// Função para excluir (desativar) um livro do sistema
void excluirLivro();

#endif
