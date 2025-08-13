#include "livros.h"
#include "stdio.h"
#include "global.h"
#include "util.h"
#include <string.h>

/**
 * Função: incluir_livro
 * ---------------------
 * Cadastra um novo livro no sistema, garantindo:
 * - ID único
 * - Nome e autor válidos
 * - Preço e quantidade não negativos
 * - Não permitir nomes ou autores duplicados
 */
void incluir_livro()
{
    limpar_tela();
    printf("--- 1. Cadastro de Novo Livro ---\n");

    if (indice_livros < MAX_LIVROS) // Verifica se há espaço no vetor de livros
    {
        livros[indice_livros].id = id_atual++; // Define ID sequencial
        livros[indice_livros].ativo = 1;       // Marca como ativo

        int nome_existente;
        int autor_existente;

        do
        {
            // Entrada e validação do nome do livro
            printf("Digite o nome do livro: ");
            fgets(livros[indice_livros].nome, TAM_MAX_NOME, stdin);
            livros[indice_livros].nome[strcspn(livros[indice_livros].nome, "\n")] = '\0';

            if (!nome_valido(livros[indice_livros].nome))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
                continue;
            }

            // Entrada e validação do nome do autor
            printf("Digite o nome do autor: ");
            fgets(livros[indice_livros].autor, TAM_MAX_NOME, stdin);
            livros[indice_livros].autor[strcspn(livros[indice_livros].autor, "\n")] = '\0';

            if (!nome_valido(livros[indice_livros].autor))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
                continue;
            }

            // Verifica duplicidade de nome ou autor
            nome_existente = 0;
            autor_existente = 0;

            for (int i = 0; i < indice_livros; i++)
            {
                if (strcmp(livros[i].nome, livros[indice_livros].nome) == 0 ||
                    strcmp(livros[i].autor, livros[indice_livros].autor) == 0)
                {
                    nome_existente = 1;
                    autor_existente = 1;
                    printf("Erro: Nome do livro ou autor ja cadastrados. Escolha outro nome ou autor.\n");
                    break;
                }
            }

        } while (nome_existente != 0 && autor_existente != 0);

        // Entrada e validação de quantidade e preço
        do
        {
            printf("\nDigite a quantidade inicial: ");
            scanf("%d", &livros[indice_livros].quantidade);
            limpar_buffer_entrada();

            printf("\nDigite o preco unitario (R$): ");
            scanf("%f", &livros[indice_livros].preco);
            limpar_buffer_entrada();

            if (livros[indice_livros].quantidade < 0 || livros[indice_livros].preco < 0)
            {
                printf("\nErro: Preco ou quantidade nao pode ser negativo.\n");
            }
            else
            {
                printf("\nLivro '%s' cadastrado com sucesso! ID: %d\n",
                       livros[indice_livros].nome, livros[indice_livros].id);
                indice_livros++;
            }
        } while (livros[indice_livros].quantidade < 0 || livros[indice_livros].preco < 0);
    }
}

/**
 * Função: listarLivros
 * --------------------
 * Exibe todos os livros cadastrados com status de disponibilidade.
 * - Indica "Esgotado" se quantidade = 0
 * - Indica "Inativo" se o livro foi removido
 */
void listarLivros()
{
    limpar_tela();
    printf("--- 2. Lista de Livros Cadastrados ---\n");

    if (indice_livros == 0)
    {
        printf("Nenhum Livro cadastrado ainda.\n");
    }
    else
    {
        printf("\n%-4s | %-30s | %-20s | %-10s | %-6s\n",
               "ID", "Titulo", "Autor", "Qtd", "Status");
        printf("-------------------------------------------------------------------------------\n");

        for (int i = 0; i < indice_livros; i++)
        {
            if (livros[i].ativo == 1)
            {
                if (livros[i].quantidade == 0)
                {
                    printf("%-4d | %-30s | %-20s | Esgotado   | Ativo\n",
                           livros[i].id, livros[i].nome, livros[i].autor);
                }
                else
                {
                    printf("%-4d | %-30s | %-20s | %-10d | Ativo\n",
                           livros[i].id, livros[i].nome, livros[i].autor, livros[i].quantidade);
                }
            }
            else
            {
                printf("%-4d | %-30s | %-20s | %-10s | Inativo\n",
                       livros[i].id, "Removido", "-", "-");
            }
        }
    }
}

/**
 * Função: atualizar_estoque
 * -------------------------
 * Permite adicionar ou remover exemplares de um livro.
 * Não permite estoque negativo.
 */
void atualizar_estoque()
{
    limpar_tela();
    printf("--- 4. Atualizar Estoque ---\n");

    int livro_para_atualizar, quantidade_movimento;
    int encontrado = 0;

    if (indice_livros > 0)
    {
        printf("\nDigite o ID do livro que deseja atualizar: ");
        scanf("%d", &livro_para_atualizar);
        limpar_buffer_entrada();

        for (int i = 0; i < indice_livros; i++)
        {
            if (livros[i].id == livro_para_atualizar && livros[i].ativo == 1)
            {
                printf("Digite a quantidade a ser adicionada (ex: 10) ou removida (ex: -5): ");
                scanf("%d", &quantidade_movimento);
                limpar_buffer_entrada();

                if ((livros[i].quantidade + quantidade_movimento) >= 0)
                {
                    livros[i].quantidade += quantidade_movimento;
                    printf("\nEstoque atualizado com sucesso! Novo estoque: %d\n",
                           livros[i].quantidade);
                }
                else
                {
                    printf("\nErro: Estoque não pode ficar negativo.\n");
                }
                encontrado = 1;
                break;
            }
        }
        if (!encontrado)
        {
            printf("\nErro: Livro com ID %d nao encontrado ou deletado.\n", livro_para_atualizar);
        }
    }
    else
    {
        printf("\nNao ha livros cadastrados no momento, cadastre um e tente novamente!");
    }
}

/**
 * Função: buscar_livro
 * --------------------
 * Busca livro pelo ID ou parte do nome.
 * Exibe resultado detalhado ou mensagem de não encontrado.
 */
void buscar_livro()
{
    limpar_tela();
    printf("--- 5. Buscar Livro ---\n");
    int id_busca, encontrado = 0;
    char termo_busca[TAM_MAX_NOME];

    printf("Digite o ID ou parte do nome do Livro: ");
    fgets(termo_busca, TAM_MAX_NOME, stdin);
    termo_busca[strcspn(termo_busca, "\n")] = 0;

    // Busca por ID
    if (sscanf(termo_busca, "%d", &id_busca) == 1)
    {
        for (int i = 0; i < indice_livros; i++)
        {
            if (livros[i].id == id_busca)
            {
                if (livros[i].ativo == 1)
                {
                    printf("\n--- Livro Encontrado por ID ---\n");
                    printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                           livros[i].id, livros[i].nome, livros[i].quantidade, livros[i].preco);
                }
                else
                {
                    printf("\nLivro com ID %d foi deletado.\n", id_busca);
                }
                encontrado = 1;
                break;
            }
        }
    }

    // Busca por nome (substring)
    if (!encontrado)
    {
        printf("\n--- Resultados da Busca por Nome '%s' ---\n", termo_busca);
        for (int i = 0; i < indice_livros; i++)
        {
            if (livros[i].ativo == 1 && strstr(livros[i].nome, termo_busca) != NULL)
            {
                printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                       livros[i].id, livros[i].nome, livros[i].quantidade, livros[i].preco);
                encontrado = 1;
            }
        }
    }

    if (!encontrado)
    {
        printf("Nenhum Livro encontrado com o termo '%s'.\n", termo_busca);
    }
}

/**
 * Função: calcular_valor_total
 * ----------------------------
 * Calcula o valor total do estoque considerando
 * apenas os livros ativos.
 */
void calcular_valor_total()
{
    limpar_tela();
    printf("--- 6. Calcular valor total do estoque ---\n");
    float value_total = 0.0;

    if (indice_livros > 0)
    {
        for (int i = 0; i < indice_livros; i++)
        {
            if (livros[i].ativo == 1)
            {
                value_total += livros[i].preco * livros[i].quantidade;
            }
        }
        printf("\nValor total do estoque: R$ %.2f\n", value_total);
    }
    else
    {
        printf("\nNao ha livros cadastrados no momento, cadastre um e tente novamente!");
    }
}

/**
 * Função: relatorio_estoque_baixo
 * -------------------------------
 * Exibe todos os livros ativos com estoque inferior a 5 unidades.
 */
void relatorio_estoque_baixo()
{
    limpar_tela();
    printf("--- 7. Relatorio de livros com estoque baixo ---\n");
    int encontrou = 0;

    if (indice_livros > 0)
    {
        for (int i = 0; i < indice_livros; i++)
        {
            if (livros[i].quantidade < 5 && livros[i].ativo == 1)
            {
                printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                       livros[i].id, livros[i].nome, livros[i].quantidade, livros[i].preco);
                encontrou = 1;
            }
        }
        if (encontrou == 0)
        {
            printf("\nNenhum livro com estoque baixo encontrado.");
        }
    }
    else
    {
        printf("\nNao ha livros cadastrados no momento, cadastre um e tente novamente!");
    }
}

/**
 * Função: excluirLivro
 * --------------------
 * Marca o livro como inativo, desde que não possua
 * exemplares no estoque.
 */
void excluirLivro()
{
    limpar_tela();
    printf("\nDigite o ID do livro que deseja excluir: ");

    int livroExcluido, encontrado = 0;
    scanf("%d", &livroExcluido);
    limpar_buffer_entrada();

    for (int i = 0; i < indice_livros; i++)
    {
        if (livroExcluido == livros[i].id)
        {
            encontrado = 1;
            if (livros[i].quantidade > 0)
            {
                printf("\nAinda existem %d exemplares deste livro no estoque. Retire-os antes de excluir.",
                       livros[i].quantidade);
            }
            else
            {
                if (livros[i].ativo == 1)
                {
                    livros[i].ativo = 0;
                    printf("\nLivro excluido com sucesso.");
                }
                else
                {
                    printf("\nLivro com ID %d ja foi removido do sistema.", livroExcluido);
                }
            }
            break;
        }
    }
    if (!encontrado)
    {
        printf("\nLivro com o ID informado nao foi encontrado.");
    }
}
