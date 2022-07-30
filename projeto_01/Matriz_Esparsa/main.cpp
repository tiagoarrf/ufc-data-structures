// Tiago A. Fontenele
// Data: 27/2021
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include "mat.h"

using namespace std;

int main(void)
{
    vector<Matriz *> matrizes;
    cout << "P R O G R A M A    I N I C I A D O !\n\n";
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

        if (tokens[0] == "ext")
        {
            for (int i = 0; i < matrizes.size(); ++i)
            {
                delete matrizes[i];
                matrizes[i] = nullptr;
                cout << "Matriz " << i + 1 << " liberada! \n\n";
            }
            matrizes.clear();
            cout << "Até logo!!!\n\n";
            break;
        }

        // cria uma Matriza
        else if (tokens[0] == "nvm")
        {
            Matriz *l = new (std::nothrow) Matriz();
            matrizes.push_back(l);
            if (l != nullptr)
                cout << "Matriza " << matrizes.size() << " criada" << endl
                     << endl;
        }

        // carrega uma matriz a partir de um arquivo passado
        else if (tokens[0] == "ler")
        {
            string file = std::string(tokens[1]);
            int k = std::stoi(tokens[3]);
            matrizes[k - 1]->lerMatriz(file);
        }

        // adiciona um elemento em uma posição vazia da matriz
        else if (tokens[0] == "add")
        {
            int l = std::stoi(tokens[1]);
            int c = std::stoi(tokens[2]);
            double v = std::stod(tokens[3]);
            int k = std::stoi(tokens[5]);

            matrizes[k - 1]->insere(l, c, v);
            cout << endl;
        }

        // soma a matriz A com a matriz B e armazena o resultado em uma terceira matriz C
        else if (tokens[0] == "sum")
        {
            int ma = std::stoi(tokens[2]);
            int mb = std::stoi(tokens[3]);
            Matriz *c = new (std::nothrow) Matriz();
            c = c->soma(matrizes[ma - 1], matrizes[mb - 1]);
            if (c != nullptr)
            {
                matrizes.push_back(c);
                cout << "\nMatriz C criada sob número " << matrizes.size() << ", para guardar a soma de A + B" << endl;
                cout << "Resultado de Mat " << ma << " + Mat " << mb << " (A + B): \n";
                matrizes[matrizes.size() - 1]->imprime();
                cout << endl
                     << endl;
            }
            else
            {
                cout << "A matriz C não foi criada. " << endl
                     << endl;
            }
        }

        // soma a matriz A com a matriz B e armazena o resultado em uma terceira matriz C
        else if (tokens[0] == "mtm")
        {
            cout << "A função de multiplicação não foi implementada ainda...\n";
            int ma = std::stoi(tokens[2]);
            int mb = std::stoi(tokens[3]);
            Matriz *m = new (std::nothrow) Matriz();
            m = m->multiplica(matrizes[ma - 1], matrizes[mb - 1]);
            if (m != nullptr)
            {
                matrizes.push_back(m);
                cout << "\nMatriz C criada sob número " << matrizes.size() << ", para guardar a soma de A + B" << endl;
                cout << "Resultado de Mat " << ma << " X Mat " << mb << " (A X B): \n";
                matrizes[matrizes.size() - 1]->imprime();
                cout << endl
                     << endl;
            }
            else
            {
                cout << "A matriz C não foi criada. " << endl
                     << endl;
            }
        }

        // retorna a quantidade atual de matrizes criadas
        else if (tokens[0] == "nma")
        {
            cout << "Quantidade atual de matrizes = " << matrizes.size() << endl
                 << endl;
        }

        // mostra na tela a matriz indicada
        else if (tokens[0] == "ptn")
        {
            int k = std::stoi(tokens[2]);
            std::cout << "Matriz " << k << ":\n";
            matrizes[k - 1]->imprime();
            cout << endl
                 << endl;
        }

        else
        {
            cout << "Comando inexistente" << endl
                 << endl;
        }
    }

    return 0;
}