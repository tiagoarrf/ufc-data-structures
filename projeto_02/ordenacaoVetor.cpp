// Tiago A. Fontenele
// 06/04/2021
#include <iostream>
#include <fstream>
#include <chrono>
#include "ordenacaoVetor.h"
using namespace std;

// Geração randômica dos números que serão
// inseridos nos vetores e nas listas
void gera_dados(int num_iteracoes, const int vetor_tam[])
{
    for (int n = 0; n < num_iteracoes; n++)
    {
        for (int semente = 0; semente < 5; semente++)
        {
            std::string nome_arquivo = "temp/random" + std::to_string(n) + "_" + std::to_string(semente) + ".dat";
            ofstream fout(nome_arquivo.c_str(), ios::binary);
            srand(time(NULL));
            int r;
            int tamanho_vetor = vetor_tam[n];
            for (int i = 0; i < tamanho_vetor; i++)
            {
                r = rand();
                // Exemplo de outro intervalo aleatório abaixo [0... 99]
                //r = rand() % 100;
                fout.write((char *)&r, sizeof(r));
            }
            fout.close();
        }
    }
}

// Realiza a leitura dos números aleatórios(inteiros) salvos no arquivo anteriormente e
// os adiciona ao vetor A[].
void ler_dados(int n, int A[], const char *nomeArquivo)
{
    ifstream fin(nomeArquivo, ios::binary);
    for (int i = 0; i < n; i++)
    {
        fin.read((char *)&A[i], sizeof(int));
    }
    fin.close();
}

// Realiza a troca de posição entre dois inteiros "std::swap caseira".
void troca(int vet[], int a, int b)
{
    int temp = vet[a];
    vet[a] = vet[b];
    vet[b] = temp;
}

// Realiza a inserção ordenada n vezes até todos
// os elementos do vetor, encontrarem-se ordenados.
void insertionSort(int n, int vet[])
{
    int i = 0;
    int j = 0;
    int aux = 0;
    for (i = 1; i < n; i++)
    {
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > aux)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}

// Seleciona o menor elemento colocando-o na primeira posição
// seleciona o segundo menor element colocando-o na segunda posição
// e assim por diante até o último elemento do vetor.
void selectionSort(int n, int vet[])
{
    int min = 0;
    int aux = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = vet[i];
        aux = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > vet[j])
            {
                min = vet[j];
                aux = j;
            }
        }
        troca(vet, i, aux);
    }
}

// Realiza a mesclagem de dois vetores
// O primeiro indicado por A[p até q]
// O segundo indicado por A[q + 1 até r]
void merge(int vet[], int p, int q, int r)
{
    int i = 0;
    int j = 0;
    int k = 0;

    // Vetor auxiliar
    int *aux = new int[r - p + 1];
    i = p;
    j = q + 1;

    // Intercala A[p..q] e A[q +1.. r]
    while (i <= q && j <= r)
    {
        if (vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            k++;
            i++;
        }
        else
        {
            aux[k] = vet[j];
            k++;
            j++;
        }
    }
    while (i <= q)
    {
        aux[k] = vet[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        aux[k] = vet[j];
        k++;
        j++;
    }

    // Copia vetor ordenado aux[] para o vetor vet[]
    for (i = p; i <= r; i++)
        vet[i] = aux[i - p];
    delete[] aux;
}

// Executa a chamada recursiva
void mergeSort(int vet[], int p, int r)
{
    if (p >= r)
    {
        return;
    }
    int q = p + (r - p) / 2;
    mergeSort(vet, p, q);
    mergeSort(vet, q + 1, r);
    merge(vet, p, q, r);
}

// Pega-se o último elemento como pivo.
// Feito isso, colocasse os elementos menores do que o pivô à esquerda e
// os elementos maiores que o pivô a direita.
int particiona(int vet[], int ini, int ultimo)
{
    int pivo = vet[ultimo];
    int i = (ini - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = ini; j <= ultimo - 1; j++)
    {
        // se o elentos em questão fora menor que o pivo
        if (vet[j] < pivo)
        {
            i++; // increment index of smaller element
            //std::swap(arr[i], arr[j]);
            troca(vet, i, j);
        }
    }
    //std::swap(vet[i + 1], vet[maior]);
    troca(vet, i + 1, ultimo);
    return (i + 1);
}

// Executa a chamada recursiva para a ordenação do quick sort
void quickSort(int vet[], int ini, int ultimo)
{
    if (ini < ultimo)
    {
        int pi = particiona(vet, ini, ultimo);
        quickSort(vet, ini, pi - 1);
        quickSort(vet, pi + 1, ultimo);
    }
}

// Realiza ordenação por inserção, só que, baseada em dividir para conquistar.
// Em vez de compara elementos do lado, o vetor inicialmente é fragmentado
// pelo fator "H", tamanho x (3 x salto) + 1, e arredondado para um valor inteiro.
// Em outras palavras, as comparações começam entre elementos distantes e
// na medida que são realizadas as comparações, essa distancia é reduzida até H = 1.
// Na ultima iteração é aplicado o método insertion sort normal, já que todo o vetor
// se encontra em uma condição "pré-ordenada".
void shellSort(int n, int vet[])
{
    int i = 0;
    int j = 0;
    int aux = 0;
    int salto = 1;

    while (salto < n)
    {
        salto = 3 * salto + 1;
    }
    while (salto > 0)
    {
        for (i = salto; i < n; i++)
        {
            aux = vet[i];
            j = i;
            while (j > salto - 1 && aux <= vet[j - salto])
            {
                vet[j] = vet[j - salto];
                j -= salto;
            }
            vet[j] = aux;
        }
        salto /= 3;
    }
}

// A partir daqui, nas funções seguintes, será feita as chamada de todos os métodos necessários
// para a execução de cada algoritmo de ordenação implementado e a contagem de tempo de execução.
// Os arquivos criados anteriormente com os inteiros aleatórios serão lidos e
// carregados nos respectivos vetores a serem ordenados.
// Feita a inserção dos valores, dar-se incio a contagem de tempo e
// e execução do algoritmo de ordenação. Após isso, a contagem de tempo é interrompida e
// os resultados salvos em arquivo para a posterior ploategm do gráficos referentes a cada método de ordenação.
// A única mudaça entre as funções containers abaixo será o algoritmo chamado para ordenar os vetorres.

void exeInsertionSortVet(int total_n, const int tam[])
{
    // Abre arquivo de resultados referente ao algoritmo desejado.
    std::ofstream ofs2("resultados/vet_insertion.txt", std::ofstream::out);

    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_insertionSort = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];

        // Para cada tamanho de vetor, foram criados 5 vetores diferentes.
        // Com isso, será feita a leitura(inserção dos valores) via arquivos .dat para cada um dos vetores.
        for (int semente = 0; semente < 5; semente++)
        {
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";

            // Realiza a leitura dos inteiros aleatórios do arquivo para os vetores.
            ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

            // Obtendo o tempo inicial para contagem do otempo de execução do algoritmo de ordenação.
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Insertion Sort para ordenar o vetor.
            insertionSort(tamanho_vetor, vetor);

            // Obtendo o tempo final de ordenação.
            auto tempo_final = std::chrono::high_resolution_clock::now();

            // Obtendo a duracao total do tempo de ordenação do algoritmo.
            auto duracao_insertionSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_insertionSort += duracao_insertionSort;
        }

        // Obtendo a média de 5 referente a duração de execução do algoritmo.
        duracao_media_insertionSort = duracao_media_insertionSort / 5.0;
        cout << "  [Insertion Sort Vector] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertionSort << " microssegundos" << endl;

        // Grava o resultado no arquivo, que será utilizado para a plotagem do gráfico.
        ofs2 << tamanho_vetor << " " << duracao_media_insertionSort << "\n";
    }

    // Fecha arquivo de resultados referente ao algoritmo.
    ofs2.close();
    cout << endl;
}

// OBSERVAÇÃO: como dito anteriomente, as próximas funções abaixo são identicas, diferindo apenas o
// algoritmo de ordenação a ser chamado para a ordenação, desse modo, acho desnecessário a repetição das
// das descrições acima em todas abaixo.
// Isso tem como propósito reduzir comentários repetitivos e desnecessários em todo o código.

void exeSelectionSortVet(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/vet_selection.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_selectionSort = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];

        for (int semente = 0; semente < 5; semente++)
        {
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";
            ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Selection Sort para ordenar o vetor
            selectionSort(tamanho_vetor, vetor);

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_selectionSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_selectionSort += duracao_selectionSort;
        }
        duracao_media_selectionSort = duracao_media_selectionSort / 5.0;
        cout << "  [Selection Sort Vector] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selectionSort << " microssegundos" << endl;
        ofs2 << tamanho_vetor << " " << duracao_media_selectionSort << "\n";
    }
    ofs2.close();
    cout << endl;
}

void exeMergeSortVet(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/vet_merge.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_mergeSort = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];

        for (int semente = 0; semente < 5; semente++)
        {
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";
            ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Merge Sort para ordenar o vetor
            mergeSort(vetor, 0, tamanho_vetor - 1);

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_mergeSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_mergeSort += duracao_mergeSort;
        }
        duracao_media_mergeSort = duracao_media_mergeSort / 5.0;
        cout << "  [Merge Sort Vector] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_mergeSort << " microssegundos" << endl;
        ofs2 << tamanho_vetor << " " << duracao_media_mergeSort << "\n";
    }
    ofs2.close();
    cout << endl;
}

void exeQuickSortVet(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/vet_quick.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_quickSort = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];

        for (int semente = 0; semente < 5; semente++)
        {
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";

            ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Quick Sort para ordenar o vetor
            quickSort(vetor, 0, tamanho_vetor - 1);

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_mergeSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_quickSort += duracao_mergeSort;
        }

        duracao_media_quickSort = duracao_media_quickSort / 5.0;
        cout << "  [Quick Sort Vector] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quickSort << " microssegundos" << endl;
        ofs2 << tamanho_vetor << " " << duracao_media_quickSort << "\n";
    }
    ofs2.close();
    cout << endl;
}

void exeShellSortVet(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/vet_shell.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_shellSort = 0.0;
        int tamanho_vetor = tam[iteracao];
        int vetor[tamanho_vetor];

        for (int semente = 0; semente < 5; semente++)
        {
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";
            ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Shell Sort para ordenar o vetor
            shellSort(tamanho_vetor, vetor);

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_shellSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_shellSort += duracao_shellSort;
        }
        duracao_media_shellSort = duracao_media_shellSort / 5.0;
        cout << "  [Shell Sort Vector] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_shellSort << " microssegundos" << endl;
        ofs2 << tamanho_vetor << " " << duracao_media_shellSort << "\n";
    }
    ofs2.close();
    cout << endl;
}