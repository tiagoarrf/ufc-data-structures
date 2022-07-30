  // By Tiago A. Fontenele
 // Universidade Federal do Ceara
//  Date: 09/02/2021

#include <iostream>
#include <string>
#include <climits>
#include "List.h"

struct Node
{
    int value;
    Node *next;
    ~Node() { std::cout << "no com valor " << value << " liberado" << std::endl; }
};

List::List()
{
    head = new Node;
    head->next = head;
    head->value = 77777777;
}

List::~List()
{
    if (!this->empty())
    {
        Node *aux = head->next;
        Node *temp = aux;
        while (aux != head)
        {
            aux = aux->next;
            delete temp;
            temp = aux;
        }
    }
    delete head;
    std::cout << "lista liberada\n";
}

//ok
bool List::contains(int x)
{
    Node *aux = new Node;
    aux = head->next;
    if (!this->empty())
    {
        while (aux != head)
        {
            if (aux->value == x)
            {
                return true;
            }
            aux = aux->next;
        }
    }
    return false;
}

//ok
bool List::empty()
{
    return head->next == head;
}

//ok
int List::size()
{
    int tam = 0;
    if (!this->empty())
    {
        Node *aux = head->next;
        while (aux != head)
        {
            aux = aux->next;
            tam++;
        }
    }
    return tam;
}

//ok
void List::clear()
{
    if (!this->empty())
    {
        Node *aux = head->next;
        Node *temp = aux;
        while (aux != head)
        {
            aux = aux->next;
            delete temp;
            temp = aux;
        }
        head->next = head;
    }
}

//ok
void List::add_back(int x)
{
    Node *novo = new Node;
    novo->value = x;
    novo->next = head;
    if (this->empty())
    {
        head->next = novo;
    }
    else
    {
        Node *aux = head;
        while (aux->next != head)
        {
            aux = aux->next;
        }
        aux->next = novo;
    }
}

//ok
void List::add_front(int x)
{
    Node *novo = new Node;
    Node *aux = new Node;
    aux = head->next;
    novo->value = x;
    head->next = novo;
    novo->next = aux;
}

//ok
int List::remove_front()
{
    int valor = INT_MIN;
    if (!this->empty())
    {
        Node *aux = new Node; 
        if (this->size() <= 1)
        {
            this->clear();
        }
        else
        {
            aux = head->next;
            head->next = head->next->next;
            valor = head->next->value;
            delete aux;
            return valor;
        }
    }
    return valor;
}

//ok
int List::remove_back()
{
    int valor = INT_MIN;
    if (!this->empty())
    {
        if (this->size() <= 1)
        {
            ///// 00000000000
            Node *temp = head->next;
            Node *aux = temp;
            head->next = head;
            valor = temp->value;
            delete temp;
            aux = head;
            return valor;
        }
        else
        {
            Node *aux = new Node;
            Node *temp = new Node;
            aux = head->next;
            while (aux->next != head)
            {
                temp = aux;
                aux = aux->next;
            }
            valor = temp->value;
            delete aux;
            temp->next = head;
            return valor;
        }
    }
    return valor;
}

//ok
void List::remove(int x)
{
    if (!this->empty())
    {
        if (this->size() <= 1 && head->next->value == x)
        {
            this->clear();
            // lllllllllllllllllllllllllllllllllllllll
            delete head->next;
        }
        else
        {
            int flag = 0;
            Node *aux = new Node;
            Node *temp = new Node;
            aux = head;
            while (flag != 1 && aux->next != head)
            {
                if (aux->next->value == x)
                {
                    flag = 1;
                    temp = aux->next;
                    aux->next = aux->next->next;
                    delete temp;
                }
                else
                    aux = aux->next;
            }
            //llllllllllll
        }
    }
}

void List::removeAll(int x)
{
    if (!this->empty())
    {
        if (this->size() <= 1 && head->next->value == x)
        {
            this->clear();
            delete head->next;
        }
        else
        {
            Node *aux = new Node;
            Node * temp = new Node;
            aux = head;
            while (aux->next != head)
            {
                if (aux->next->value == x)
                {
                    temp = aux->next;
                    aux->next = aux->next->next;
                    delete temp;
                }
                else
                    aux = aux->next;
            }
        }
    }
}

std::string List::toString()
{
    std::string print = "[";
    if (!this->empty())
    {
        Node *aux = new Node;
        aux = head->next;
        while (aux != head)
        {
            if (aux->next != head)
            {
                print += (std::to_string(aux->value));
                print += ',';
                aux = aux->next;
            }
            else
            {
                print += (std::to_string(aux->value));
                aux = aux->next;
            }
        }
    }
    print += ']';
    return print;
}

Node *search(int x);


// The End...