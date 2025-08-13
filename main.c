#include <stdio.h> // Para printf, scanf

// Aqui você está incluindo arquivos .c diretamente.
// Geralmente o recomendado é incluir .h, mas como pediu para não mudar nada,
// vou apenas comentar que isso pode gerar redefinição de funções/variáveis
#include "util.c"              // Funções utilitárias: limpar_buffer_entrada, aguardar_tecla, limpar_tela, etc.
#include "global.c"            // Declaração e definição das variáveis globais
#include "livros.c"            // Funções relacionadas ao cadastro, exclusão e listagem de livros
#include "livros_relatorios.c" // Funções relacionadas a relatórios (ex.: livro mais caro)

void exibir_menu(); // Protótipo da função (OBS: cuidado com diferença entre 'exibir_menu' e 'exibi_menu')

int main()
{
    int opcao; // Guarda a escolha do usuário no menu
    do
    {
        exibi_menu(); // Exibe o menu principal
        scanf("%d", &opcao);
        limpar_buffer_entrada(); // Evita problemas com '\n' no buffer

        // Seleção da ação baseada na opção do menu
        switch (opcao)
        {
        case 1:
            incluir_livro();
            break;
        case 2:
            excluirLivro();
            break;
        case 3:
            listarLivros();
            break;
        case 4:
            atualizar_estoque();
            break;
        case 5:
            buscar_livro();
            break;
        case 6:
            calcular_valor_total();
            break;
        case 7:
            relatorio_estoque_baixo();
            break;
        case 8:
            livro_mais_caro();
            break;
        case 9:
            livro_maior_estoque();
            break;
        case 10:
            livro_acima_determinado_valor();
            break;
        case 11:
            mostrar_media_precos();
            break;
        case 12:
            printf("Encerrando o sistema. Ate logo!\n");
            break;
        default:
            printf("Opcao invalida! Por favor, tente novamente.\n");
            break;
        }

        // Aguarda o usuário pressionar Enter antes de voltar ao menu
        // OBS: Aqui você chamou aguardar_tecla() duas vezes seguidas,
        // isso fará com que precise pressionar Enter duas vezes.
        if (opcao != 12)
        {
            aguardar_tecla();
        }

    } while (opcao != 12); // Repete enquanto não escolher "Sair"

    return 0;
}

// Função que exibe o menu de opções para o usuário
void exibi_menu()
{
    limpar_tela(); // Limpa a tela do console

    printf("--- SISTEMA DE CONTROLE DE BIBLIOTECA ---\n");
    printf("1. Cadastrar Novo Livro\n");
    printf("2. Excluir livro\n");
    printf("3. Listar livros\n");
    printf("4. Atualizar estoque\n");
    printf("5. Buscar livro por NOME/ID\n");
    printf("6. Calcular valor total\n");
    printf("7. Relatorio de estoque baixo\n");
    printf("8. Livro mais caro\n");
    printf("9. Livro com maior estoque\n");
    printf("10. Livro acima de determinado valor\n");
    printf("11. Mostrar media dos precos e livros acima da media\n");
    printf("12. Sair\n");
    printf("---------------------------------------\n");
    printf("Escolha uma opcao: ");
}
