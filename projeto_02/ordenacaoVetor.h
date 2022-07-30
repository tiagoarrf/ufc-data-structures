// Tiago A. Fontenele
// 06/04/2021
#ifndef VETORDER_H
#define VETORDER_H

// função responsável por gerar os numéros aleatórios que serão armazenados em um arquivo .dat
// e posteriomente inseridos do vetor A[] através da função ler_dados
void gera_dados(int num_iteracoes, const int vetor_tam[]);

// Função que recebe um vetor de inteiros A[n] e o preenche
// com os n inteiros contidos no arquivo binario indicado
void ler_dados(int n, int A[], const char *nomeArquivo);

//Funções auxiliares:
void troca(int vet[], int a, int b);
void merge(int vet[], int p, int q, int r);
int particiona(int vet[], int l, int r);

// Funções de ordenação:
void insertionSort(int n, int vet[]);
void selectionSort(int n, int vet[]);
void mergeSort(int vet[], int l, int r);
void quickSort(int vet[], int low, int high);
void shellSort(int n, int vet[]);

// funções contêineres para as chamadas das funções necessárias para a execução da ordenação
// chamadas a partir da main, irão desencadear os processos de preenchimento e ordenação dos elementos.
void exeInsertionSortVet(int n, const int vec[]);
void exeSelectionSortVet(int n, const int vec[]);
void exeMergeSortVet(int n, const int vec[]);
void exeQuickSortVet(int n, const int vec[]);
void exeShellSortVet(int n, const int vec[]);

#endif