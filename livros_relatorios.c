#include <stdio.h>
#include "util.h"
#include "global.h"
#include <string.h> // Para usar funções como strcmp e strcpy

// Função que exibe o livro mais caro cadastrado e ativo
void livro_mais_caro()
{
    limpar_tela();
    printf("\n--- 8. Relatorio do livro mais caro ---\n");
    int indice_maior = -1; // Índice do livro mais caro encontrado (-1 significa nenhum encontrado ainda)
    int i;

    if (indice_livros > 0) // Verifica se existe pelo menos um livro cadastrado
    {
        // Percorre todos os livros cadastrados
        for (i = 0; i < indice_livros; i++)
        {
            // Considera somente livros ativos e atualiza o índice do mais caro
            if (livros[i].ativo == 1 && (indice_maior == -1 || livros[i].preco > livros[indice_maior].preco))
            {
                indice_maior = i;
            }
        }

        // Se algum livro ativo foi encontrado, exibe suas informações
        if (indice_maior != -1)
        {
            printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                   livros[indice_maior].id, livros[indice_maior].nome, livros[indice_maior].quantidade, livros[indice_maior].preco);
        }
        else // Se não encontrou nenhum livro ativo
        {
            printf("\nNao ha livros ativos.");
        }
    }
    else // Se não há nenhum livro cadastrado
    {
        printf("\nNao ha livros cadastrados.");
    }
}

// Função que exibe o livro com maior quantidade em estoque e ativo
void livro_maior_estoque()
{
    limpar_tela();
    printf("\n--- 9. Relatorio do livro com maior estoque ---\n");
    int i, indice_maior = -1; // Índice do livro com maior estoque

    if (indice_livros > 0) // Verifica se existem livros cadastrados
    {
        for (i = 0; i < indice_livros; i++)
        {
            // Verifica se o livro está ativo e se tem estoque maior que o atual maior
            if (livros[i].ativo == 1 && (indice_maior == -1 || livros[i].quantidade > livros[indice_maior].quantidade))
            {
                indice_maior = i;
            }
        }

        // Se algum livro ativo foi encontrado, exibe suas informações
        if (indice_maior != -1)
        {
            printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                   livros[indice_maior].id, livros[indice_maior].nome, livros[indice_maior].quantidade, livros[indice_maior].preco);
        }
        else // Caso nenhum livro ativo encontrado
        {
            printf("\nNao ha livros ativos.");
        }
    }
    else // Caso não haja livros cadastrados
    {
        printf("\nNao ha livros cadastrados.");
    }
}

// Função que lista livros com preço acima de um valor informado pelo usuário
void livro_acima_determinado_valor()
{
    limpar_tela();
    printf("--- 10. Relatorio: Livros acima de determinado valor ---");

    float value_minimo;
    int i, livro_encontrados = 0; // Contador de livros que atendem ao filtro

    if (indice_livros > 0) // Verifica se existem livros cadastrados
    {
        printf("\nDigite o valor minimo: \n");
        scanf("%f", &value_minimo);
        limpar_buffer_entrada(); // Limpa o buffer para evitar problemas com entradas futuras

        // Percorre todos os livros cadastrados
        for (i = 0; i < indice_livros; i++)
        {
            // Verifica se o livro está ativo e seu preço é maior que o valor mínimo
            if (livros[i].ativo == 1 && livros[i].preco > value_minimo)
            {
                // Exibe as informações do livro que atende ao critério
                printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                       livros[i].id, livros[i].nome, livros[i].quantidade, livros[i].preco);
                livro_encontrados++;
            }
        }
        // Caso nenhum livro encontrado com preço acima do valor informado
        if (livro_encontrados == 0)
        {
            printf("\nNenhum livro encontrado com valor superior a R$ %.2f\n", value_minimo);
        }
    }
    else // Caso não haja livros cadastrados
    {
        printf("\nNenhum livro está disponivel no momento.\n");
    }

    aguardar_tecla(); // Pausa para o usuário visualizar o resultado
}

// Função que calcula a média dos preços dos livros ativos e lista os livros com preço acima da média
void mostrar_media_precos()
{
    limpar_tela();
    printf("--- 12. Mostra media dos precos e livros acima da media ---\n");

    int livros_ativo = 0, i;
    float media = 0.0, preco_livros_ativos = 0.0;

    if (indice_livros > 0) // Verifica se há livros cadastrados
    {
        // Soma os preços dos livros ativos e conta quantos estão ativos
        for (i = 0; i < indice_livros; i++)
        {
            if (livros[i].ativo == 1)
            {
                preco_livros_ativos += livros[i].preco;
                livros_ativo++;
            }
        }

        if (livros_ativo == 0) // Nenhum livro ativo encontrado
        {
            printf("\nNenhum livro esta disponivel no momento.\n");
        }
        else
        {
            // Calcula a média dos preços dos livros ativos
            media = preco_livros_ativos / livros_ativo;
            printf("\nMedia dos precos dos livros ativos: R$ %.2f\n\n", media);

            // Lista os livros cujo preço é maior que a média calculada
            for (i = 0; i < indice_livros; i++)
            {
                if (livros[i].preco > media && livros[i].ativo == 1)
                {
                    printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                           livros[i].id, livros[i].nome, livros[i].quantidade, livros[i].preco);
                }
            }
        }
    }
    else // Caso não haja livros cadastrados
    {
        printf("\nNao ha livros cadastrados.");
    }
    aguardar_tecla(); // Pausa para o usuário visualizar o resultado
}
