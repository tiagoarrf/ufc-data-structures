// Instituição: Universidade Federal do Ceará - Campus Quixadá
// Curso: Sistemas de Informação
// Disciplina: Estruturas de Dados
// Docente: Atílio Gomes
// Discente: Tiago A. Fontenele
// Data: 06/04/2021
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ordenacaoVetor.h"
#include "ordenacaoLista.h"
using namespace std;

// Observação:
// Para não deixar o código com excesso de comentários desnecessários, evitarei descrever o
// funcinamentos das bibliotecas/funções/metódos nativas do C++. Pois todas as informações bem detalhadas podem
// ser consultadas na documentação, fóruns e comunidades da linguagem com maior riqueza de detalhes.

// Funcao Principal
int main(void)
{
	// Os tamanhos dos vetores a serem testados:
	const int tam[] = {500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000,
	11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000, 24000, 25000};
	int total_n = sizeof(tam) / sizeof(tam[0]); // determina tamanho do vetor 'tam'
	gera_dados(total_n, tam);

	// COM VETORES - IMPLEMENTAÇÃO ESTRUTURADA
	cout << " **************************** INÍCIO DA ORDENAÇÃO COM VETORES ****************************\n\n";
	exeInsertionSortVet(total_n, tam);
	exeSelectionSortVet(total_n, tam);
	exeMergeSortVet(total_n, tam);
	exeQuickSortVet(total_n, tam);
	exeShellSortVet(total_n, tam);
	cout << " ****************************** FIM DA ORDENAÇÃO COM VETORES *****************************\n\n\n";

	// COM LISTAS - IMPLEMENTAÇÃO ORIENTADA A OBJETOS
	cout << " ***************************** INÍCIO DA ORDENAÇÃO COM LISTAS ****************************\n\n";
	List *l = new List();
	l->exeInsertionSortList(total_n, tam);
	l->exeSelectionSortList(total_n, tam);
	l->exeMergeSortList(total_n, tam);
	l->exeQuickSortList(total_n, tam);
	l->exeShellSortList(total_n, tam);
	// cout << " ******************************* FIM DA ORDENAÇÃO COM LISTAS *****************************\n\n";

	while (true)
	{
		cout << " Digite (exit) para liberar os nós(poderá demorar um pouco) e sair do progrma: ";
		string cmd;
		getline(cin, cmd);
		if (cmd == "exit")
		{
			cout << endl;
			l->~List();
			free(l);
			break;
		}
		else
		{
			cout << " Opção inválida!\n";
		}
	}

	return 0;
}