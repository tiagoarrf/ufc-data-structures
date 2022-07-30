// TIAGO A. FONTENELE
// DATA: 27/02/2021
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include "List.h"

using namespace std;

int main(void)
{
    // vector que guarda todas as listas criadas
    vector<List *> listas;
    cout << "P R O G R A M A    I N I C I A D O !\n";
    while (true)
    {
        string cmd;
        getline(cin, cmd);
        std::stringstream ss{cmd};
        vector<string> tokens;
        string buffer;

        while (ss >> buffer)
        {
            tokens.push_back(buffer);
        }

        // sai do programa
        if (tokens[0] == "ext")
        {
            for (int i = 0; i < listas.size(); ++i)
            {
                delete listas[i];
                listas[i] = nullptr;
                cout << "lista " << i + 1 << " liberada \n\n";
            }
            listas.clear();
            cout << "Até logo!\n\n";
            break;
        }

        // cria uma lista
        else if (tokens[0] == "cnl")
        {
            List *l = new (std::nothrow) List();
            listas.push_back(l);
            if (l != nullptr)
                cout << "lista " << listas.size() << " criada" << endl
                     << endl;
        }

        // Deleta por completo uma lista “k” específica.
        else if (tokens[0] == "dln")
        {
            List *l = new (std::nothrow) List();
            int x = std::stoi(tokens[2]);
            delete listas[x - 1];
            listas.erase(listas.begin() + x - 1);
            listas[listas.size()] = nullptr;
            if (listas.size() > 1)
            {
                cout << "lista " << x << " liberada " << endl;
                cout << "lista " << x + 1 << " movida para a posição " << x << endl
                     << endl;
            }
            else
            {
                cout << "lista " << x << " liberada " << endl;
            }
        }

        // Adiciona o elemento “n” ao final da lista “l”.
        else if (tokens[0] == "adf")
        {
            int x = std::stoi(tokens[1]);
            int k = std::stoi(tokens[3]);
            listas[k - 1]->push_back(x);
            cout << x << " adicionado ao final da lista " << k << endl
                 << endl;
        }

        // Insere um novo nó com um valor “n” após o k-ésimo nó da lista “l” indicada.
        else if (tokens[0] == "adn")
        {
            int key = std::stoi(tokens[1]);
            int no = std::stoi(tokens[2]);
            int lst = std::stoi(tokens[4]);
            int s = listas[lst - 1]->size();
            listas[lst - 1]->insertAfter(key, no);
            if (listas[lst]->size() > s)
            {
                cout << "valor " << key << " adicionado após o nó " << no << " da lista " << lst << endl
                     << endl;
            }
            else
            {
                cout << "não foi possível adicionar " << key << " após o nó " << no << " da lista " << lst << endl
                     << endl;
            }
        }

        // Remove a primeira ocorrência do elemento “n” na lista “l”.
        else if (tokens[0] == "rmp")
        {
            int flag = 0;
            int x = std::stoi(tokens[1]);
            int k = std::stoi(tokens[3]);
            int s = listas[k-1]->size();
            listas[k - 1]->remove(x);
            int r = listas[k-1]->size();
            if (r < s)
            {
                flag = 1;
            }
            if (flag == 0)
            {
                cout << "não foi possível remover " << x << " da lista " << k << endl
                     << endl;
            }
            else{
                cout << "primeira ocorrência de " << x << " foi removida da lista " << k << endl << endl; 
            }
        }

        // Remove todas as ocorrências do elemento “n” na lista “l”.
        else if (tokens[0] == "rmt")
        {
            int flag = 0;
            int x = std::stoi(tokens[1]);
            int k = std::stoi(tokens[3]);
            int s = listas[k-1]->size();
            listas[k - 1]->removeAll(x);
            int r = listas[k-1]->size();
            if (r < s)
            {
                flag = 1;
            }
            if (flag == 0)
            {
                cout << "não foi possível remover " << x << " da lista " << k << endl
                     << endl;
            }
            else{
                cout << "todas as ocorrências de " << x << " foram removidas da lista " << k << endl << endl; 
            }
        }

        // Remove elemento do final da lista “l”.
        else if (tokens[0] == "rmf")
        {
            int k = std::stoi(tokens[2]);
            int v = listas[k - 1]->pop_back();
            if (v != INT32_MIN)
                cout << v << " removido do final lista " << k << endl
                     << endl;
            else
                cout << "nao foi possivel remover do final da lista " << k << endl
                     << endl;
        }

        // Verifica se uma lista “l” está ou não vazia.
        else if (tokens[0] == "vza")
        {
            int k = std::stoi(tokens[2]);
            if (listas[k - 1]->empty())
                cout << "lista " << k << " está vazia" << endl
                     << endl;
            else
                cout << "há elementos na lista " << k << endl
                     << endl;
        }

        // Retorna a quantidade atual de listas criadas.
        else if (tokens[0] == "nla")
        {
            cout << "quatidade atual de listas = " << listas.size() << endl
                 << endl;
        }

        // Retorna o número de nós na lista “l” (exceto o nó cabeça).
        else if (tokens[0] == "tmo")
        {
            int k = std::stoi(tokens[2]);
            cout << "tamanho atual da lista " << k << " = " << listas[k - 1]->size() << endl
                 << endl;
        }

        // Limpa(remove) todos elementos de uma lista “l”, exceto o nó de referência(cabeça).
        else if (tokens[0] == "clr")
        {
            int k = std::stoi(tokens[2]);
            listas[k - 1]->clear();
            cout << "lista " << k << " vazia" << endl
                 << endl;
        }

        // Mostra todos os elementos da lista “l”.
        else if (tokens[0] == "ptn")
        {
            int k = std::stoi(tokens[2]);
            std::cout << "lista " << k << " = ";
            listas[k - 1]->print();
            cout << endl;
        }

        // Mostra todos os elementos da lista “l” em ordem inversa.
        else if (tokens[0] == "pti")
        {
            int k = std::stoi(tokens[2]);
            std::cout << "lista " << k << " = ";
            listas[k - 1]->printReverse();
            cout << endl;
        }

        // concatena uma lista k na lista autal (ultima lista criada)
        else if (tokens[0] == "cna")
        {
            int l1 = std::stoi(tokens[2]);
            int l2 = listas.size();
            if (l1 == l2) // caso esteja concatenando com ela mesma
            {
                List *lcx = listas[l2 - 1]->copy();
                listas[l2 - 1]->concat(lcx);
                cout << "lista " << l1 << " concatenada à lista " << l2 << endl
                     << endl;
            }
            else
            {
                listas[l2 - 1]->concat(listas[l1 - 1]); // ok
                cout << "lista " << l1 << " concatenada à lista " << l2 << endl
                     << endl;
            }
        }

        // concatena uma lista a outra e limpa os elementos da segunda
        else if (tokens[0] == "cnt")
        {
            int l1 = std::stoi(tokens[1]);
            int l2 = std::stoi(tokens[3]);
            if (l1 == l2) // caso l1 == l2
            {
                List *lcy = listas[l2 - 1]->copy();
                listas[l2 - 1]->concat(lcy);
                cout << "lista " << l1 << " concatenada à lista " << l2 << endl
                     << endl;
            }
            else
            {
                listas[l2 - 1]->concat(listas[l1 - 1]);
                cout << "lista " << l1 << " concatenada à lista " << l2 << endl
                     << endl;
            }
        }

        // Cria uma cópia de uma lista “l” a partir de um ponteiro do tipo lista que foi retornado.
        else if (tokens[0] == "cpl")
        {
            int lx = std::stoi(tokens[2]);
            List *l = listas[lx - 1]->copy();
            listas.push_back(l);
            if (l != nullptr)
                cout << "lista " << listas.size() << " criada a partir de uma cópia da lista " << lx << endl
                     << endl;
        }

        // Copia todos elementos de um vetor “v” de tamanho “n” para uma lista “l”.
        else if (tokens[0] == "cpv")
        {
            // cpv n 1 2 3 list x
            int n = std::stoi(tokens[1]);
            int vec[n];
            int k = 2;
            int e = 0;
            for (int i = 0; i < n; i++)
            {
                e = std::stoi(tokens[k]);
                vec[i] = e;
                k++;
            }
            k++;
            int l = std::stoi(tokens[k]);
            listas[l - 1]->copyArray(n, vec);
            cout << "vetor adicionado na lista " << l << endl
                 << endl;
        }

        // Confere se duas listas, “l1” e “l2”, são exatamente iguais.
        else if (tokens[0] == "eql")
        {
            int l1 = std::stoi(tokens[1]);
            int l2 = std::stoi(tokens[3]);
            if (listas[l1 - 1]->equal(listas[l2 - 1]))
            {
                cout << "lista " << l1 << " é exatamente igual à lista " << l2 << endl
                     << endl;
            }
            else
            {
                cout << "lista " << l1 << " é diferente da lista " << l2 << endl
                     << endl;
            }
        }

        else
        {
            cout << "comando inexistente" << endl
                 << endl;
        }
    }

    return 0;
}