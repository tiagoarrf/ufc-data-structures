// Tiago A. Fontenele
// 06/04/2021
#ifndef LIST_H
#define LIST_H

// Estrutura do tipo nó.
struct Node;

// Classe List
class List
{
private:

  // Nós referentes ao nó cabeça e nó calda respectivamente.
  Node *head;
  Node *tail;

  // Realiza a leitura dos números inteiros aleatórios
  // contidos no arquivo indicado.
  void ler_dados(List *lista, int n, const char *nomeArquivo);

  // Realiza a troca de posição entre dois valores.
  // Mesma função da std::swap
  void troca(int *a, int *b);


  // Segue abaixo as funções privadas de cada algoritmo de ordenação:

  void insertionSort();
  void selectionSort();

  // Funções de uso do algoritmo merge sort.
  Node *divide(Node *head);
  Node *merge(Node *first, Node *second);
  Node *mergeSort(Node *head);

  // Funções de uso do algoritmo quick sort.
  Node *particiona(Node *l, Node *h);
  void quickSort(Node *l, Node *h);

  void shellSort();

  // Funções contêineres para a execução de todos os processos necessários.
  // Tais funções, realizam chamadas para as demais funçãoes.
  void insertionSortList(int total_n, const int tam[]);
  void selectionSortList(int total_n, const int tam[]);
  void mergeSortList(int total_n, const int tam[]);
  void quickSortList(int total_n, const int tam[]);
  void shellSortList(int total_n, const int tam[]);

public:

  // Construtor da classe.
  List();

  // Destrutor da classe.
  // Libera memória que foi previamente alocada.
  ~List();

  // Funções públicas dos algoritmos de ordenação:
  void ordenaInsertion();
  void ordenaSelection();
  void ordenaMergeSort();
  void ordenaQuickSort();
  void ordenaShellSort();

  // Funções públicas para as chamadas das funções contêineres,
  // que por sua vez, executam as demais funções.
  void exeInsertionSortList(int total_n, const int tam[]);
  void exeSelectionSortList(int total_n, const int tam[]);
  void exeMergeSortList(int total_n, const int tam[]);
  void exeQuickSortList(int total_n, const int tam[]);
  void exeShellSortList(int total_n, const int tam[]);

  // Funções auxiliares/extras:
  // Em alguns momentos do decorrer das implmentações, fiz uso de algunmas para testes de ordenação e
  // integridade das listas, como por exemplo, as funções print() e printReverso();
  // Para velificação da ordenação, nos momentos de testes utilizei a função equal(L1, L2).

  // Função que insere um valor ao final de
  // uma lista duplamente encadeada com nós cabeça e calda.
  void insere(int valor);

  // Retorna o tamanho da lista.
  int size();

  // Compara duas listas.
  void equal(List *a, List *b);

  // Limpa a lista, deixando-a vazia.
  void clearList();

  // Retorna true caso a lista encontre-se vazia.
  bool vazia();

  // Mostra todos os elementos da lista na tela.
  void print();

  // Mostra todos os elementos da lista na tela em ordem contrária.
  void printReverso();
  
};

#endif
