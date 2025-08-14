#ifndef UTIL_H
#define UTIL_H

// Declaração da função que limpa a tela do terminal/console.
void limpar_tela();

// Declaração da função que pausa a execução até o usuário pressionar alguma tecla.
// Útil para dar tempo do usuário ler mensagens antes de prosseguir.
void aguardar_tecla();

// Declaração da função que verifica se o nome passado como parâmetro é válido.
// Retorna um inteiro indicando se o nome atende aos critérios definidos.
int nome_valido(char nome[]);

// Declaração da função que limpa o buffer de entrada do teclado.
// Evita problemas com entradas anteriores que ficaram no buffer, como restos de '\n'.
void limpar_buffer_entrada();

#endif
