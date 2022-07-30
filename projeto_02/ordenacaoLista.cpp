// Tiago A. Fontenele
// 06/04/2021
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "ordenacaoLista.h"

using namespace std;

// Estrutura do nó
struct Node
{
    Node *prox;
    Node *ant;
    int valor;

    // Descomentar a linha abaixo caso queira ver os nos sendo liberados.
    // ~Node() { std::cout << " no com valor " << valor << " liberado\n"; }
};

// Contrutor.
List::List()
{
    head = new Node;
    tail = new Node;
    head->ant = nullptr;
    tail->prox = nullptr;
    head->prox = tail;
    tail->ant = head;

    // Valores dados aos nós de referência.
    head->valor = INT32_MIN;
    tail->valor = INT32_MAX;
}

// Destrutor.
List::~List()
{
    cout << " Liberando os nós da lista...\n";
    if (!this->vazia())
    {
        Node *aux = head->prox;
        Node *temp = aux;
        while (aux != tail)
        {
            aux = aux->prox;
            delete temp;
            temp = aux;
        }
    }
    delete head;
    delete tail;
    cout << " Lista liberada.\n";
}

// FUNÇÕES PRIVADAS:

// Realiza a leitura dos números aleatórios(inteiros) salvos no arquivo anteriormente e
// os adiciona à lista correspondente.
void List::ler_dados(List *lista, int n, const char *nomeArquivo)
{
    int valor;
    ifstream fin(nomeArquivo, ios::binary);
    for (int i = 0; i < n; i++)
    {
        fin.read((char *)&valor, sizeof(int));
        lista->insere(valor);
    }
    fin.close();
}

// Realiza a troca de posição entre dois valores
void List::troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Função de ordenação do insertion sort
// Realiza a ordenação por inserção.
void List::insertionSort()
{
    // Nós auxiliares utilizados para percorrear a lista e guardar posições,
    // já que não há indices definidos como nos vetores.
    Node *aux, *aux_ant, *aux_prox, *j;

    for (Node *i = head->prox; i != tail; i = i->prox)
    {
        aux = i;
        j = i->ant;
        while (j->prox != tail && j->valor > aux->valor)
        {
            aux_ant = j->ant;
            aux_prox = aux->prox;
            aux_ant->prox = aux;
            aux->prox = j;
            j->prox = aux_prox;
            aux_prox->ant = j;
            j->ant = aux;
            aux->ant = aux_ant;
            j = aux;
            aux = j->prox;

            if (aux == tail)
            {
                head = j;
            }
            j = j->ant;
            aux = aux->ant;
        }
    }
}

// Versão do Insertion Sort por trocas de valores:
// void List::insertionSort()
// {
//     // Nós auxiliares utilizados para percorrear a lista e guardar posições,
//     // já que não há indices definidos como nos vetores.
//     Node *j;
//     Node *i = head->prox;
//     int aux;

//     for(i = i->prox ; i != tail; i = i->prox)
//     {
//         aux = i->valor;
//         j = i->ant;
//         while (j != head && j->valor > aux)
//         {
//             j->prox->valor = j->valor;
//             j = j->ant;
//         }
//         j->prox->valor = aux;
//     }
// }

// Função de ordenação do selection sort.
void List::selectionSort()
{
    Node *i = head->prox;

    // Laço para percorrer a lista até o final.
    while (i != tail)
    {
        Node *menor = i;
        Node *j = i->prox;

        // Laço que percorre a segunda lista.
        while (j != tail)
        {
            if (menor->valor > j->valor)
                menor = j;

            j = j->prox;
        }

        // Efetua a troca dos valores comparados
        this->troca(&menor->valor, &i->valor);
        i = i->prox;
    }
}

// Função auxiliar do merge sort.
// Relaliza a divisão da lista passada pelo nó head
// em duas metades.
Node *List::divide(Node *head_list)
{
    Node *aux_p = head_list;
    Node *aux_r = head_list;
    while (aux_r->prox != tail->prox && aux_r->prox->prox != tail->prox)
    {
        aux_r = aux_r->prox->prox;
        aux_p = aux_p->prox;
    }
    Node *temp = aux_p->prox;
    aux_p->prox = tail->prox;
    return temp;
}

// Função auxiliar do merge sort.
// Realiza a intercalação/mesclagem de duas listas
// para a ordenação pelo merge sort.
Node *List::merge(Node *primeira, Node *segunda)
{
    // Caso a primeira lista esteja vazia
    if (!primeira)
        return segunda;

    // Caso a segunda lista esteja vazia
    if (!segunda)
        return primeira;

    // seleçao do menor valor
    if (primeira->valor < segunda->valor)
    {
        primeira->prox = merge(primeira->prox, segunda);
        primeira->prox->ant = primeira;
        primeira->ant = head->ant;
        return primeira;
    }
    else
    {
        segunda->prox = merge(primeira, segunda->prox);
        segunda->prox->ant = segunda;
        segunda->ant = head->ant;
        return segunda;
    }
}

// Função de ordenação do merge sort.
// Reaaliza as chamadas recursivas do merge sort
Node *List::mergeSort(Node *primeira)
{
    if (!primeira->prox)
    {
        return primeira;
    }

    // Becebe a segunda metade da divisão da lista passada.
    Node *segunda = divide(primeira);

    // Chamada recursiva para as duas metades.
    primeira = mergeSort(primeira);
    segunda = mergeSort(segunda);

    // Intercala as duas listas
    return merge(primeira, segunda);
}

// Função auxiliar do quick sort.
// Assim como na implementação com vetor,
// pega-se o último elemento como pivô.
// Feito isso, colocasse os elementos menores do que o pivô à esquerda e
// os elementos maiores que o pivô a direita.
Node *List::particiona(Node *ini, Node *ultimo)
{
    // Define-se o pivô
    int pivo = ultimo->valor;
    Node *i = ini->ant;
    for (Node *j = ini; j != ultimo; j = j->prox)
    {
        if (j->valor <= pivo)
        {
            if (i == head->ant)
            {
                i = ini;
            }
            else
            {
                i = i->prox;
            }
            troca(&(i->valor), &(j->valor));
        }
    }
    if (i == tail->prox)
    {
        i = ini;
    }
    else
    {
        i = i->prox;
    }
    troca(&(i->valor), &(ultimo->valor));
    return i;
}

// Função de ordenação do quick sort.
// Realiza as chamadas recursivas do quick sort.
void List::quickSort(Node *l, Node *h)
{
    if (h != nullptr && l != h && l != h->prox)
    {
        Node *p = particiona(l, h);
        quickSort(l, p->ant);
        quickSort(p->prox, h);
    }
}

// Função de ordenação do shell sort
// Assim como no modelo por vetores, a ideia aqui é
// o uso da dideia de "divisão para conquistar", ou em outras palavras, a comparação de elementos distantes entre sí e
// ir diminuindo essadistância até h = 1;
// Ou seja, tal distancia será reduzida até a comparação ser feita com o seu elemento adjacente.
// Infelezmente por não termos a ideia de índices como nos vetores convencionais e para sabermos o
// tamanho da lista ser necessário percorré-la toda, o desempenho do algoritmo com listas fica prejudicado.
void List::shellSort()
{
    int tam_list = size();
    if (!this->vazia())
    {
        int salto = 1;
        int cont = 0;
        int temp = 0;
        Node *aux1;

        // Definindo o tamanho do "salto"
        while (salto < tam_list)
        {
            salto = salto * 3 + 1;
        }
        while (salto > 0)
        {
            for (int i = salto; i > 0; i--)
            {
                for (int j = salto - i; j < tam_list; j += salto)
                {
                    aux1 = head->prox;
                    for (cont = 0; cont < j; cont++)
                    {
                        aux1 = aux1->prox;
                    }
                    temp = cont + salto;
                    for (Node *aux2 = aux1; aux2 != tail; temp += salto)
                    {
                        while (cont < temp)
                        {
                            if (aux2 != tail)
                            {
                                aux2 = aux2->prox;
                                cont++;
                            }
                            else
                                cont = temp;
                        }
                        // Compara-se os elementos dos saltos
                        if (aux1->valor > aux2->valor)
                        {
                            this->troca(&aux1->valor, &aux2->valor);
                        }
                    }
                }
            }
            // Na última iteração, quando salto for equivalente a 1,
            // será aplicado o insertion sort normal.
            salto /= 3;
        }
    }
}

// Nas funções seguintes, será feita as chamada de todos os métodos necessários
// para a execução de cada algoritmo de ordenação implementado e a contagem de tempo de execução.
// Os arquivos criados anteriormente com os inteiros aleatórios serão lidos e
// carregados nas respectivas listas a serem ordenadas.
// Feita a inserção dos valores, dar-se incio a contagem de tempo e
// e execução do algoritmo de ordenação. Após isso, a contagem de tempo é interrompida e
// os resultados salvos em arquivo para a posterior ploategm do gráficos referentes a cada método de ordenação.
// A única mudaça entre as funções containers abaixo será o algoritmo chamado para ordenar as listas.

void List::insertionSortList(int total_n, const int tam[])
{
    // Abre arquivo de resultados referente ao algoritmo desejado.
    std::ofstream ofs2("resultados/list_insertion.txt", std::ofstream::out);

    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_insertionSort = 0.0;
        int tamanho_lista = tam[iteracao];

        // Para cada tamanho de vetor criado na main, foram criados 5 listas diferentes (por vez).
        // Com isso, será feita a leitura(inserção dos valores) via arquivos .dat para cada um dos lista.
        for (int semente = 0; semente < 5; semente++)
        {
            // Verifica-se se a lista encontra-se vazia, do contrário será esvaziada.
            // Isso é uma forma de evitar inserção em uma lista com valores inseridos anteriomente.
            this->clearList();

            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";

            // Realiza a leitura dos inteiros aleatórios do arquivo para a lista.
            this->ler_dados(this, tamanho_lista, nome_arquivo.c_str());

            // Obtendo o tempo inicial para contagem do otempo de execução do algoritmo de ordenação.
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Insertion Sort para ordenar a lista.
            this->ordenaInsertion();

            // Obtendo o tempo final de ordenação.
            auto tempo_final = std::chrono::high_resolution_clock::now();

            // Obtendo a duracao total do tempo de ordenação do algoritmo.
            auto duracao_insertionSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_insertionSort += duracao_insertionSort;
        }

        // Obtendo a média de 5 referente a duração de execução do algoritmo.
        duracao_media_insertionSort = duracao_media_insertionSort / 5.0;
        cout << "  [Insertion Sort List] N = " << tamanho_lista << ", tempo médio de execução = " << duracao_media_insertionSort << " microssegundos" << endl;

        // Grava o resultado no arquivo, que será utilizado para a plotagem do gráfico.
        ofs2 << tamanho_lista << " " << duracao_media_insertionSort << "\n";
    }

    // Fecha arquivo de resultados referente ao algoritmo.
    ofs2.close();
    cout << endl;
}

// OBSERVAÇÃO: como dito anteriomente, as próximas funções abaixo são identicas, diferindo apenas o
// algoritmo de ordenação a ser chamado para a ordenação, desse modo, acho desnecessário a repetição das
// das descrições acima em todas abaixo.
// Isso tem como propósito reduzir comentários repetitivos e desnecessários em todo o código.

void List::selectionSortList(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/list_selection.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_selectionSort = 0.0;
        int tamanho_lista = tam[iteracao];
        for (int semente = 0; semente < 5; semente++)
        {
            this->clearList();
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";
            this->ler_dados(this, tamanho_lista, nome_arquivo.c_str());
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Selection Sort para ordenar a lista.
            this->ordenaSelection();

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_selectionSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_selectionSort += duracao_selectionSort;
        }
        duracao_media_selectionSort = duracao_media_selectionSort / 5.0;
        cout << "  [Selection Sort List] N = " << tamanho_lista << ", tempo médio de execução = " << duracao_media_selectionSort << " microssegundos" << endl;
        ofs2 << tamanho_lista << " " << duracao_media_selectionSort << "\n";
    }
    ofs2.close();
    cout << endl;
}

void List::mergeSortList(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/list_merge.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_mergeSort = 0.0;
        int tamanho_lista = tam[iteracao];
        for (int semente = 0; semente < 5; semente++)
        {
            this->clearList();
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";
            this->ler_dados(this, tamanho_lista, nome_arquivo.c_str());
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Merge Sort para ordenar a lista.
            this->ordenaMergeSort();

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_mergeSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_mergeSort += duracao_mergeSort;
        }
        duracao_media_mergeSort = duracao_media_mergeSort / 5.0;
        cout << "  [Merge Sort List] N = " << tamanho_lista << ", tempo médio de execução = " << duracao_media_mergeSort << " microssegundos" << endl;
        ofs2 << tamanho_lista << " " << duracao_media_mergeSort << "\n";
    }
    ofs2.close();
    cout << endl;
}

void List::quickSortList(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/list_quick.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_quickSort = 0.0;
        int tamanho_lista = tam[iteracao];
        for (int semente = 0; semente < 5; semente++)
        {
            this->clearList();
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";
            this->ler_dados(this, tamanho_lista, nome_arquivo.c_str());
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Quick Sort para ordenar a lista.
            this->ordenaQuickSort();

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_quickSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_quickSort += duracao_quickSort;
        }
        duracao_media_quickSort = duracao_media_quickSort / 5.0;
        cout << "  [Quick Sort List] N = " << tamanho_lista << ", tempo médio de execução = " << duracao_media_quickSort << " microssegundos" << endl;
        ofs2 << tamanho_lista << " " << duracao_media_quickSort << "\n";
    }
    ofs2.close();
    cout << endl;
}

void List::shellSortList(int total_n, const int tam[])
{
    std::ofstream ofs2("resultados/list_shell.txt", std::ofstream::out);
    for (int iteracao = 0; iteracao < total_n; iteracao++)
    {
        long double duracao_media_shellSort = 0.0;
        int tamanho_lista = tam[iteracao];
        for (int semente = 0; semente < 5; semente++)
        {
            this->clearList();
            string nome_arquivo = "temp/random" + std::to_string(iteracao) + "_" + std::to_string(semente) + ".dat";
            this->ler_dados(this, tamanho_lista, nome_arquivo.c_str());
            auto tempo_ini = std::chrono::high_resolution_clock::now();

            // Chama o algoritmo de ordenação Shell Sort para ordenar a lista.
            this->ordenaShellSort();

            auto tempo_final = std::chrono::high_resolution_clock::now();
            auto duracao_shellSort = std::chrono::duration_cast<std::chrono::microseconds>(tempo_final - tempo_ini).count();
            duracao_media_shellSort += duracao_shellSort;
        }
        duracao_media_shellSort = duracao_media_shellSort / 5.0;
        cout << "  [Shell List] N = " << tamanho_lista << ", tempo médio de execução = " << duracao_media_shellSort << " microssegundos" << endl;
        ofs2 << tamanho_lista << " " << duracao_media_shellSort << "\n";
    }
    ofs2.close();
    cout << endl;
}

// FUNÇÕES PÚBLICAS:

// Função pública do insertion sort.
void List::ordenaInsertion()
{
    this->insertionSort();
}

// Função pública do selection sort.
void List::ordenaSelection()
{
    this->selectionSort();
}

// Função publica do merge sort.
void List::ordenaMergeSort()
{
    this->mergeSort(head);
}

// Função pública do quick sort.
void List::ordenaQuickSort()
{
    this->quickSort(head, tail);
}

// Função publica do shell sort
void List::ordenaShellSort()
{
    this->shellSort();
}

// Logo abaixo, temos as funções públicas que serão chamadas a partir da main para
// executar o processo de ordenação correspondente a cada algoritmo
// de ordenação:

void List::exeInsertionSortList(int total_n, const int tam[])
{
    this->insertionSortList(total_n, tam);
}

void List::exeSelectionSortList(int total_n, const int tam[])
{
    this->selectionSortList(total_n, tam);
}

void List::exeMergeSortList(int total_n, const int tam[])
{
    this->mergeSortList(total_n, tam);
}

void List::exeQuickSortList(int total_n, const int tam[])
{
    this->quickSortList(total_n, tam);
}

void List::exeShellSortList(int total_n, const int tam[])
{
    this->shellSortList(total_n, tam);
}

// Funções públicas extras e auxiliares:

// Insere um elemento no final da lista.
void List::insere(int key)
{
    Node *novo = new Node;
    Node *final = tail;
    novo->valor = key;
    novo->ant = final->ant;
    final->ant->prox = novo;
    novo->prox = final;
    final->ant = novo;
}

// Retorna true, caso a lista esteja vazia.
bool List::vazia()
{
    if (head->prox == tail)
    {
        return true;
    }
    return false;
}

// Mostra os valores contidos na lista.
void List::print()
{
    std::cout << "[";
    if (!this->vazia())
    {
        Node *aux = head->prox;
        while (aux != tail)
        {
            if (aux->prox != tail)
            {
                std::cout << aux->valor << ", ";
                aux = aux->prox;
            }
            else
            {
                std::cout << aux->valor;
                aux = aux->prox;
            }
        }
    }
    std::cout << "]\n";
}

// Mostra os valores contidos na lista em ordem contrária.
void List::printReverso()
{
    std::cout << "[";
    if (!this->vazia())
    {
        Node *aux = tail->ant;
        while (aux != head)
        {
            if (aux->ant != head)
            {
                std::cout << aux->valor << ", ";
                aux = aux->ant;
            }
            else
            {
                std::cout << aux->valor;
                aux = aux->ant;
            }
        }
    }
    std::cout << "]\n";
}

// Libera todos os nós da lista
// exceto nó cabeça e calda;
void List::clearList()
{
    if (!this->vazia())
    {
        Node *temp = head;
        Node *aux = temp->prox;
        while (aux != tail->prox)
        {
            if (temp != head)
                delete temp;
            temp = aux;
            aux = temp->prox;
        }
        head->prox = tail;
        tail->ant = head;
    }
}

// Retorna o tamanho da lista
int List::size()
{
    int tam = 0;
    if (!this->vazia())
    {
        Node *aux = head->prox;
        while (aux != tail)
        {
            tam++;
            aux = aux->prox;
        }
    }
    return tam;
}

// Verifica de duas listas são exatamente iguais.
void List::equal(List *a, List *b)
{
    int flag = 1;
    if (a->size() == b->size())
    {
        Node *aux1 = a->head->prox;
        Node *aux2 = b->head->prox;
        while (aux1 != a->tail && flag == 1)
        {
            if (aux1->valor != aux2->valor)
            {
                flag = 0;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
    }
    if (flag == 0)
    {
        cout << "as listas são diferentes!\n";
    }
    else
    {
        cout << "as listas são iguais!\n";
    }
}