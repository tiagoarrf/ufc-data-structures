#include <iostream>
#include <cmath>
//By Tiago A. Fontenele
//23/11/2020

bool primo(int p){
	int i = 0;
	int raiz_aprox = 0;
	int resto = 0;
	int qtd_div = 0;
	raiz_aprox = sqrt(p);
	if(p == 1){
		return false;
	}
	for(i = 2; i <= raiz_aprox; i++){
		resto = p % i;
		if(resto == 0){
			qtd_div ++;
		}
		if(qtd_div > 0){
			return false;
		}
	}
	return true;
}

void primos(){
	int num1 = 0;
	int num2 = 0;
	std::cin >> num1;
	std::cin >> num2;
	while(num1 <= num2){
		if(primo(num1) == true){
			std::cout << num1 << "\n";
		}
		num1++;
	}
}

int main(){
	primos();

	return 0;
}
