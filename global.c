#include "global.h"

// Aqui são **definidas** (alocadas de fato) as variáveis globais
// que foram apenas **declaradas com extern** no arquivo global.h.

// Vetor que armazena os livros cadastrados no sistema, com tamanho máximo definido em MAX_LIVROS
Livro livros[MAX_LIVROS];

// Índice que indica a quantidade atual de livros cadastrados no vetor 'livros'.
// Começa em 0, pois inicialmente não há livros cadastrados.
int indice_livros = 0;

// Variável que controla o próximo ID único a ser atribuído a um novo livro.
// Começa em 1 para o primeiro livro cadastrado receber o ID 1.
int id_atual = 1;
