#ifndef GLOBAL_H
#define GLOBAL_H

#include "livros.h"  // Inclui a definição da struct Livro e constantes relacionadas

// Declaração externa do vetor que armazena os livros cadastrados no sistema.
// A definição real desse vetor deve estar em um arquivo .c para evitar múltiplas definições.
extern Livro livros[MAX_LIVROS]; 

// Variável externa que controla o próximo ID único a ser atribuído a um livro novo.
// Geralmente incrementada a cada novo cadastro.
extern int id_atual;

// Variável externa que indica quantos livros já foram cadastrados no vetor livros.
// Usada para controlar a posição de inserção e o limite de livros cadastrados.
extern int indice_livros;

#endif
