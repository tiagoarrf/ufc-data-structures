// Tiago A. Fontenele
// Data: 27/2021
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "mat.h"
using namespace std;

struct Node
{
    Node *direita;
    Node *abaixo;
    int linha;
    int coluna;
    double valor = -77777; // simboliza os nós cabeças
    // o nó cabeça principal é simbolizado pelo - 99999
    ~Node() { std::cout << "No com valor " << valor << " liberado" << std::endl; }
};

Matriz::Matriz()
{
    head = new Node;
    head->direita = head;
    head->abaixo = head;
    head->linha = -1;
    head->coluna = -1;
    head->valor = -99999; // simboliza o nó cabeça
}

Matriz::~Matriz()
{
    // deletando os nos com  valores
    Node *lin = head->abaixo;
    Node *aux = new Node;
    for (int i = 1; i < head->linha + 1; i++)
    {
        aux = lin->direita;
        Node *temp = aux;
        for (int j = 1; j < head->coluna + 1; j++)
        {
            if (aux->linha == i && aux->coluna == j)
            {
                aux = aux->direita;
                delete temp;
                temp = aux;
            }
        }
        lin = lin->abaixo;
    }
    cout << "Todos os nós que guardavam os valores foram liberados!\n";
    if (head->direita != head)
    {
        Node *auxc = head->direita;
        Node *tempc = auxc;
        while (auxc != head)
        {
            auxc = auxc->direita;
            delete tempc;
            tempc = auxc;
        }
    }
    cout << "Nós cabeças liberados!\n";
    delete head;
    cout << "Nó cabeça principal liberado!\n";
}

void Matriz::headsInitial(int dml, int dmc)
{
    // criando a estrutura coluna
    for (int i = 1; i < dmc + 1; i++)
    {
        Node *novoc = new Node;
        novoc->coluna = i;
        novoc->linha = -1;
        novoc->direita = head;
        if (head->direita == head) // criação dos heads direita
        {
            head->direita = novoc;
            novoc->abaixo = novoc;
            head->linha = dml; // guardando a quantidade de linhas da matriz no head para facilitar o print
            head->coluna = dmc;
        }
        else
        {
            Node *auxc = head;
            while (auxc->direita != head)
            {
                auxc = auxc->direita;
            }
            auxc->direita = novoc;
            novoc->abaixo = novoc;
        }
    }
    for (int i = 1; i < dml + 1; i++) // criação dos heads linhas
    {
        Node *novol = new Node;
        novol->linha = i;
        novol->coluna = -1;
        novol->abaixo = head;
        if (head->abaixo == head)
        {
            head->abaixo = novol;
            novol->direita = novol;
        }
        else
        {
            Node *auxl = head;
            while (auxl->abaixo != head)
            {
                auxl = auxl->abaixo;
            }
            auxl->abaixo = novol;
            novol->direita = novol;
        }
    }
}

void Matriz::lerMatriz(std::string arquivo)
{
    ifstream f(arquivo, ios::in);
    if (!f.is_open())
    {
        cout << "Erro ao tentar abrir o arquivo: " << arquivo << endl
             << endl;
    }
    else
    {
        int qtdLin = 0;
        string itr;
        while (getline(f, itr, '\n'))
        {
            qtdLin++;
        }
        f.close();
        ifstream file(arquivo, ios::in);
        int lin;
        int col;
        int dml;
        int dmc;
        string del;
        float vlr;

        int flagc = 0;
        int flagl = 0;

        if (file >> lin >> del >> col)
        {
            dml = lin;
            dmc = col;
        }
        for (int i = 0; i < qtdLin - 1; i++)
        {
            if (file >> lin >> del >> col >> del >> vlr)
            {
                this->headsInitial(dml, dmc);
                this->insere(lin, col, vlr);
            }
        }
        cout << "Matriz carregada atraves do arquivo: " << arquivo << endl
             << endl;
    }
}

void Matriz::imprime() // por linha
{
    Node *lin = head->abaixo;
    if (lin != head)
    {
        Node *aux = new Node;
        for (int i = 1; i < head->linha + 1; i++)
        {
            aux = lin->direita;
            for (int i = 0; i < head->coluna * 2; i++)
            {
                cout << "--------";
            }
            cout << "\n";
            for (int j = 1; j < head->coluna + 1; j++)
            {
                cout << "|";
                if (aux->linha == i && aux->coluna == j)
                {
                    cout << "\t" << aux->valor << "\t";
                    aux = aux->direita;
                }
                else
                {
                    cout << "\t"
                         << "x"
                         << "\t";
                }
            }
            lin = lin->abaixo;
            cout << "|\n";
        }
        for (int i = 0; i < head->coluna * 2; i++)
        {
            cout << "--------";
        }
    }
    else
    {
        cout << "matriz vazia\n";
    }
}

void Matriz::insere(int i, int j, double v)
{
    if (head->abaixo != head)
    {
        Node *novo = new Node;
        novo->linha = i;
        novo->coluna = j;
        novo->valor = v;
        Node *lin = head->abaixo;

        // percorrendo nas possições da matriz
        for (int i = 1; i < head->linha + 1; i++)
        {
            if (i == novo->linha)
            {
                break;
            }
            else
            {
                lin = lin->abaixo;
            }
        }

        Node *col = head->direita;
        for (int i = 1; i < head->coluna + 1; i++)
        {
            if (i == novo->coluna)
            {
                break;
            }
            else
            {
                col = col->direita;
            }
        }

        // verificados onde os elementos serão adicionados
        Node *aux;
        if (lin->direita == lin)
        {
            lin->direita = novo;
            novo->direita = lin;
        }
        else
        {
            aux = lin;
            while (aux->direita != lin)
            {
                if (aux->direita->coluna < novo->coluna)
                {
                    aux = aux->direita;
                }
                if (aux->direita == lin)
                {
                    aux->direita = novo;
                    novo->direita = lin;
                    break;
                }
                else if (aux->direita->coluna > novo->coluna)
                {
                    Node *temp = aux->direita;
                    aux->direita = novo;
                    novo->direita = temp;
                    break;
                }
            }
        }
        cout << "Valor " << v << " inserido na posição [L: " << i << ", C: " << j << "]" << endl;
    }
    else
    {
        cout << "Erro ao inserir! A estrutura da matriz não foi definida a partir de um arquivo!!!\n\n";
    }
}

Matriz *Matriz::soma(Matriz *A, Matriz *B)
{
    Matriz *C = new Matriz;
    int dmca = A->head->coluna;
    int dmla = A->head->linha;
    int dmcb = B->head->coluna;
    int dmlb = B->head->linha;
    // verifica se tem as mesmas dimensoes
    if (dmca == dmcb && dmla == dmlb)
    {
        // cirando os heads de C
        C->headsInitial(dmla, dmca);

        // buscando elemento de A e B
        Node *linA = A->head->abaixo;
        Node *linB = B->head->abaixo;
        if (linA != A->head)
        {
            double valA = 0;
            double valB = 0;
            double sumAB = 0;
            int falgA = 0;
            int flagB = 0;
            Node *auxA = new Node; // percorre A
            Node *auxB = new Node;
            for (int ia = 1, ib = 1; ia < A->head->linha + 1; ib++, ia++)
            {
                auxA = linA->direita;
                auxB = linB->direita;
                for (int ja = 1, jb = 1; ja < A->head->coluna + 1; jb++, ja++)
                {
                    if (auxA->linha == ia && auxA->coluna == ja)
                    {
                        valA = auxA->valor; // valor de a encontrado
                        falgA = 1;
                        auxA = auxA->direita;
                    }
                    else
                    {
                        valA = 0;
                    }
                    if (auxB->linha == ib && auxB->coluna == jb) // valor encontrado de b
                    {
                        valB = auxB->valor;
                        flagB = 1;
                        auxB = auxB->direita;
                    }
                    else
                    {
                        valB = 0;
                    }
                    if (falgA == 1 && flagB == 0)
                    {
                        C->insere(ia, ja, valA);
                        falgA = 0;
                    }
                    if (falgA == 0 && flagB == 1)
                    {
                        C->insere(ib, jb, valB);
                        flagB = 0;
                    }
                    if (falgA == 1 && flagB == 1)
                    {
                        sumAB = valA + valB;
                        C->insere(ib, jb, sumAB);
                        falgA = 0;
                        flagB = 0;
                    }
                }
                linA = linA->abaixo;
                linB = linB->abaixo;
            }
        }
        return C;
    }
    else
    {
        cout << "Impossível efetuar a soma. As matrizes não tem as mesmas dimenções!!!\n";
        C = nullptr;
    }
    return C;
}

Matriz *Matriz::multiplica(Matriz *A, Matriz *B)
{ // falta implentar
    int dmca = A->head->coluna;
    int dmlb = B->head->linha;
    Matriz *C = new Matriz;
    if (dmca == dmlb) // verifica a condição para a multiplicação
    {
        C = A;
        return C;
    }
    else
    {
        cout << "Impossível efetuar a soma. As matrizes não tem as mesmas dimenções!!!\n";
        C = nullptr;
    }
    return C;
}