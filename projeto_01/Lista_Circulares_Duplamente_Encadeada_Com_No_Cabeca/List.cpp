// TIAGO A. FONTENELE
// DATA: 27/02/2021
#include <iostream>
#include "List.h"

struct Node
{
    Node *prox;
    Node *ant;
    int valor;
    ~Node() { std::cout << "no com valor " << valor << " liberado\n"; }
};

List::List()
{
    head = new Node;
    head->prox = head;
    head->ant = head;
    head->valor = INT32_MIN;
}

List::~List()
{
    if (!this->empty())
    {
        Node *aux = head->prox;
        Node *temp = aux;
        while (aux != head)
        {
            aux = aux->prox;
            delete temp;
            temp = aux;
        }
    }
    delete head;
}

void List::push_back(int key)
{
    Node *novo = new Node;
    Node *final = head->ant;
    novo->valor = key;
    final->prox = novo;
    novo->ant = final;
    novo->prox = head;
    head->ant = novo;
}

int List::pop_back()
{
    int valor = INT32_MIN;
    if (!this->empty())
    {
        Node *final = head->ant;
        Node *temp = final;
        valor = final->valor;
        final = final->ant;
        final->prox = head;
        head->ant = final;
        delete temp;
        return valor;
    }
    return valor;
}

void List::insertAfter(int key, int k)
{
    Node *novo = new Node;
    novo->valor = key;
    if (this->empty())
    {
        head->prox = novo;
        novo->ant = head;
        head->ant = novo;
        novo->prox = head;
    }
    Node *aux = head->prox;
    int flag = 0;
    for (int i = 1; i <= this->size() && flag == 0; i++)
    {
        if (k == 0)
        {
            novo->ant = head;
            head->prox = novo;
            novo->prox = aux;
            aux->ant = novo;
            flag = 1;
        }
        else if (i == k)
        {
            novo->prox = aux->prox;
            aux->prox = novo;
            novo->ant = aux;
            novo->prox->ant = novo;
            flag = 1;
        }
        else{
        aux = aux->prox;
        }
    }
}

void List::remove(int key)
{
    if (!this->empty())
    {
        Node *aux = head->prox;
        int flag = 0;
        while (aux != head && flag == 0)
        {
            if (aux->valor == key)
            {
                Node *temp = aux;
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                delete temp;
                flag = 1;
            }
            aux = aux->prox;
        }
    }
}

void List::removeAll(int key)
{
    if (!this->empty())
    {
        Node *aux = head->prox;
        Node *temp = new Node;
        int flag = 0;
        while (aux != head)
        {
            if (aux->valor == key)
            {
                temp = aux;
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                aux = temp->prox;
                delete temp;
                flag = 1;
            }
            else
            {
                aux = aux->prox;
            }
        }
    }
}

void List::print()
{
    std::cout << "[";
    if (!this->empty())
    {
        Node *aux = new Node;
        aux = head->prox;
        while (aux != head)
        {
            if (aux->prox != head)
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

void List::printReverse()
{
    std::cout << "[";
    if (!this->empty())
    {
        Node *aux = new Node;
        aux = head->ant;
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

bool List::empty()
{
    if (head->prox == head)
    {
        return true;
    }
    return false;
}

int List::size()
{
    int tam = 0;
    if (!this->empty())
    {
        Node *aux = head->prox;
        while (aux != head)
        {
            tam++;
            aux = aux->prox;
        }
    }
    return tam;
}

void List::clear()
{
    if (!this->empty())
    {
        Node *aux = head->prox;
        Node *temp = aux;
        while (aux != head)
        {
            aux = aux->prox;
            delete temp;
            temp = aux;
        }
        head->prox = head;
        head->ant = head;
    }
}

void List::concat(List *lst)
{
    Node *aux = lst->head->prox;
    while (aux != lst->head)
    {
        this->push_back(aux->valor);
        aux = aux->prox;
    }
    lst->clear();
}

List *List::copy()
{
    Node *aux = head->prox;
    List *lx = new List;
    while (aux != head)
    {
        lx->push_back(aux->valor);
        aux = aux->prox;
    }
    return lx;
}

void List::copyArray(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        this->push_back(arr[i]);
    }
    std::cout << "\n";
}

bool List::equal(List *lst)
{
    if (this->size() == lst->size())
    {
        Node *aux1 = head->prox;
        Node *aux2 = lst->head->prox;
        for (int i = 0; i < this->size(); i++)
        {
            if (aux1->valor != aux2->valor)
            {
                return false;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        return true;
    }
    return false;
}
