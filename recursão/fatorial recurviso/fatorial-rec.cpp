   //#####################################//
  //####### By Tiago A. Fontenele #######//
 //############ 23/12/2020 #############//
//#####################################//
#include <iostream>

int calFat(int num){
	return num == 0? 1 : num * calFat(num-1);
}

int main(void){
	int num=0;
	std::cin >> num;
	std::cout << calFat(num);
	
	return 0;
}
