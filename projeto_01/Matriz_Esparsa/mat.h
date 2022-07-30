// Tiago A. Fontenele
// Data: 27/2021
#ifndef MATRIX_H
#define MATRIX_H
#include <string>

struct Node;

class Matriz
{
private:
    Node *head;

public:
    // Construtor: cria uma lista simplesmente encadeada circular
    // com no cabeca. O no cabeca eh obrigatorio na implementacao desta lista
    Matriz();

    // Destrutor: libera toda memsoria que foi alocada
    ~Matriz();
    // Esse método lÊ, de um arquivo de entrada, os elementos diferentes de zero de uma
    // matriz e monta a estrutura
    void lerMatriz(std::string arquivo);

    // Esse método imprime (uma linha da matriz por linha na saída) a matriz A, inclusive
    // os elementos iguais a zero.
    void imprime();

    // Esse método insere o valor v na linha i, coluna j da matriz A.
    void insere(int i, int j, double v);

    // Essa funcão recebe como parˆametro as matrizes A e B, devolvendo uma matriz C
    // que é a soma de A com B.

    // Lembre que a soma de uma matriz A com uma matriz B so eh possivel
    // se o numero de linhas e de colunas de A for igual ao numero de
    // linhas e de colunas de B, respectivamente.
    Matriz *soma(Matriz *A, Matriz *B);

    // Esse método recebe como parâmetro as matrizes A e B, devolvendo uma matriz C
    // que é o produto de A por B.
    // Recebe o ponteiro para o objeto B do tipo Matriz que possui
    // l linhas e c colunas e multiplica a matriz que chamar essa funcao-membro pela matriz B.
    // Lembre que a multiplicacao de uma matriz A por uma matriz B so eh possivel
    // se o numero de colunas de A for igual ao numero de linhas de B.
    // Se for possivel fazer a multiplicacao, um ponteiro para uma nova matriz C
    // contendo o resultado da multiplicacao deve ser retornado (note que a matriz C
    // deve ser alocada dinamicamente dentro da funcao-membro).
    // Caso contrario, retorna nullptr indicando que nao foi possivel
    // fazer a multiplicacao das matrizes.
    Matriz *multiplica(Matriz *A, Matriz *B);

    // função utilisada apenas para iniciar a matris com os heads
    void headsInitial(int hl, int hc);
};

#endif