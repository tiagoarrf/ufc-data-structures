   //#####################################//
  //####### By Tiago A. Fontenele #######//
 //############ 23/12/2020 #############//
//#####################################//
#include <iostream>
	
void move(char ini, char fim){
	std::cout << ini << " -> " << fim << "\n";
}

void torreHanoi(char ini, char aux, char fim, int n){
	if(n > 0){
		torreHanoi(ini, fim, aux, n - 1);
		move(ini, fim);
		torreHanoi(aux, ini, fim, n - 1);
	}
}

int main(void){
	int n = 0;
	std::cin >> n;
	
	torreHanoi('A', 'B', 'C', n);
	
	return 0;
}
