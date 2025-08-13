#include "util.h"
#include <stdio.h>
#include <stdlib.h>

// Função para limpar a tela, dependendo do sistema operacional
void limpar_tela()
{
#ifdef _WIN32
    system("cls"); // Comando do Windows
#else
    system("clear"); // Comando do Linux/Mac
#endif
}

// Função que aguarda o usuário pressionar Enter
void aguardar_tecla()
{
    printf("\n\nPressione Enter para continuar...");
    getchar();
}

// Função que verifica se um nome é válido (não vazio ou só espaços)
int nome_valido(char nome[])
{
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] != ' ' && nome[i] != '\t')
        {
            return 1; // nome válido (tem caractere não branco)
        }
    }
    return 0; // inválido (vazio ou só espaços)
}

// Função para limpar o buffer do teclado (stdin), evitando problemas em entradas futuras
void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ; // descarta todos os caracteres até o fim da linha
    }
}