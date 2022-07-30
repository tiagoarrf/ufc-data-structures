// TIAGO A. FONTENELE
// DATA: 27/02/2021
#ifndef LIST_H
#define LIST_H

struct Node;

class List
{
private:
    Node *head;

public:

// Construtor da classe.
// Deve iniciar todos os atributos da classe com valores válidos
List();

// Destrutor da classe. Libera memória previamente alocada.
~List();

// Insere um inteiro key ao final da lista.
void push_back(int key);

// Remove elemento do final da lista e retorna seu valor.
int pop_back();

// Insere um novo nó com valor key apóss o k-ésimo nó da lista.
void insertAfter(int key, int k);

// Remove da lista a primeira ocorrência do inteiro key
void remove(int key);

// Remove da lista todas as ocorrências do inteiro key.
void removeAll(int key);

// Imprime os elementos da lista.
void print();

// Imprime os elementos da lista em ordem reversa.
void printReverse();

// Retorna true se a lista estiver vazia e false caso contrário.
bool empty();

// Retorna o número de nós da lista (exceto o nó cabeça).
int size();

// Remove todos os elementos da lista e deixa apenas o nó cabeca.
void clear();

// Concatena a lista atual com a lista lst passada por
// parâmetro. Após essa operação ser executada, lst será uma lista vazia, ou seja, o
// único nó de lst será o nó cabeçaa.
void concat(List *lst);

// Retorna um ponteiro para uma cópia desta lista.
List *copy();

// Copia os elementos do array arr para a
// lista. O array arr tem n elementos. Todos os elementos anteriores da lista são
// mantidos e os elementos do array arr devem ser adicionados após os elementos originais.
void copyArray(int n, int arr[]);

// Determina se a lista passada por parâmetro é igual à
// lista em questão. Duas listas são iguais se elas possuem o mesmo tamanho e o valor
// do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista.
bool equal(List *lst);

};

#endif