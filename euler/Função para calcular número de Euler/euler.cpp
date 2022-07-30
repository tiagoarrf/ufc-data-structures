#include <iostream>
#include <iomanip>
// By Tiago A. Fontenele
// 23/11/2020

double fat(double f){
	double resul = f;
	if(resul == 0){
		resul = 1;
	}
	while(f > 1){
		resul *= (--f);
	}
	return resul;
}

double euler(double n){
	double euler = 1;
	while(n > 0){
		euler += 1/fat(n--);
	}	
	return euler;
}
	
int main(){
	std::cout << std::fixed << std::setprecision(6);
	double num;
	std::cin >> num;
	std::cout << euler(num);
	
	return 0;
}
