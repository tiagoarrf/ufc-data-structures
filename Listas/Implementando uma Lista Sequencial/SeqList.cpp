// Implementacao da classe SeqList
// Tiago A. Fontenele
// 06/02/2021
#include "SeqList.h"
#include <vector>
#include <iostream>
#include <string>


//COMPLICADO... NO WINDOWS DÁ UMA SAÍDA CORRETA E AQUI NÃO! DÁ INVERTIDA... 

SeqList::SeqList(int n)
{
    capacity_vec = n;
    size_vec = 0;
    vec = new int[capacity_vec];
}

SeqList::~SeqList()
{
    delete vec;
    std::cout << "lista removida \n";
}

bool SeqList::add(int x)
{
    if (!isFull())
    {
        vec[size_vec] = x;
        size_vec++;
        //  std::cout << x << " foi adicionado \n";
        return true;
    }
    else
    {
        // std::cout << "lista cheia\n";
        return false;
    }
}

// remove trocando a posicão do ultimo pelo removido
// bool SeqList::remove(int x){
//     if(size_vec > 0){
//         if(search(x) != -999){
//             vec[search(x)] = vec[size_vec - 1];
//             size_vec --;
//             return true;
//         }
//     }
//         return false;
// }

// remove o primeiro x da linha
bool SeqList::remove(int x)
{
    int index = search(x);
    if (index != -1)
    {
        for (int i = index; i <= size_vec - 2; i++)
        {
            vec[i] = vec[i + 1];
        }
        size_vec--;
        return true;
    }
    return false;
}

int SeqList::search(int x)
{
    if (size_vec > 0)
    {
        for (int i = 0; i < size_vec; i++)
        {
            if (x == vec[i])
            {
                return i;
            }
        }
    }
    //std::cout << "valor " << x << " não encontrado! \n";
    return -1;
}

int SeqList::at(int k)
{
    return vec[k];
}

int SeqList::size()
{
    return size_vec;
}

bool SeqList::isFull()
{
    return size_vec == capacity_vec;
}

void SeqList::clear()
{
    if (size_vec > 0)
    {
        size_vec = 0;
    }
}

void SeqList::print(int i)
{
    (i < size_vec-1)? std::cout << vec[i] << ", ", print(i+1), std::cout << "" : std::cout << vec[size_vec - 1];
}

std::string SeqList::toString()
{
    std::cout << "[";
    this->print(0);
    std::cout << "]";
    return "";
}

bool SeqList::replaceAt(int x, int k)
{
    if (k >= 0 && k < size_vec)
    {
        vec[k] = x;
        return true;
    }
    return false;
}


bool SeqList::removeAt(int k)
{
    int index = k;
    if (0 <= k && k < size())
    {
        for (int i = index; i <= size_vec - 2; i++)
        {
            vec[i] = vec[i + 1];
        }
        size_vec--;
        return true;
    }
    return false;
}

bool SeqList::insertAt(int x, int k)
{
   // std::cout << "VALOR DE K = " << k << "\n\n\n";
    if (!isFull() && k > 0 && k < capacity_vec - 1)
    {
        for (int i = capacity_vec - 1; i > k; i--)
        {
            vec[i] = vec[i - 1];
        }
        vec[k] = x;
        size_vec++;
        return true;
    }
    if (size_vec == 0)
    {
        vec[0] = x;
        size_vec++;
        return true;
    }
    else
    {
        return false;
    }
}

// remove all
void SeqList::removeAll(int x)
{
    if (remove(x))
    {
        removeAll(x);
    }
}
