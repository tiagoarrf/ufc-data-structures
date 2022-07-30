   //#####################################//
  //####### By Tiago A. Fontenele #######//
 //############ 01/12/2020 #############//
//#####################################//
#include <iostream>
#include <iomanip>

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

void maiorNota(Aluno a1, Aluno a2){
	if(a1.nota > a2.nota){
		std::cout << a1.nome << " , " << a1.nota;
	}
	else if(a1.nota < a2.nota){
		std::cout << a2.nome << " , " << a2.nota;
	}
	else{
		std::cout << a1.nome << " e " << a2.nome << " , "<< a2.nota;
	}
}
int main(void){
	std::cout << std::fixed << std::setprecision(1);
	Aluno a1, a2;
	a1 = regAluno();
	a2 = regAluno();
	maiorNota(a1, a2);
	
	return 0;
}

