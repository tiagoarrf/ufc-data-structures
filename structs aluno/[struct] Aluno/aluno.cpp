   //#####################################//
  //####### By Tiago A. Fontenele #######//
 //############ 01/12/2020 #############//
//#####################################//
#include <iostream>

struct Aluno{
	char nome[100];
    int matricula = 0;
    char disciplina[50];
    float nota = 0;
};

Aluno regAluno(){
	Aluno alu ;
	std::cin >> alu.nome;
	std::cin >> alu.matricula;
	std::cin >> alu.disciplina;
	std::cin >> alu.nota;
	
	return alu;
}

void medAluno(Aluno a){
	if(a.nota >= 7){
		std::cout << a.nome << " aprovado(a) em " << a.disciplina;
	}
	else{
		std::cout << a.nome << " reprovado(a) em " << a.disciplina;
	}
}
int main(void){
	Aluno a1;
	a1 = regAluno();
	medAluno(a1);
	
	return 0;
}
