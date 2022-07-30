   //#####################################//
  //####### By Tiago A. Fontenele #######//
 //############ 23/12/2020 #############//
//#####################################//
#include <iostream>

void printVet(int v[], int n, int i = 0){
	(i < n-1)? std::cout << v[i] << ", ", printVet(v, n, i + 1), std::cout << "" : std::cout << v[n - 1];
	//ou ao contrário
	//(n > 0)? (n - 1 > 0? std::cout << v[n - 1] << ", " : std::cout << v[n - 1]), printVet(v, n - 1), std::cout <<"" : std::cout << "";
}
void sumTriangulo(int v[], int n){
	if(n > 0){
		int temp[n - 1];
		for(int i = 0; i < n; i ++){
			temp[i] = v[i] + v[i + 1];
		}
		sumTriangulo(temp, n - 1);
		std::cout << "[";
		printVet(v, n);
		std::cout << "]\n";
	}
}

int main(void){
	int n = 0;
	std::cin >> n;
	int t[n];
	for(int i = 0; i < n; i++){
		std::cin >> t[i];
	}
	sumTriangulo(t, n);
	

   return 0;
}
//EX:
// input
// 1 2 3
// output
//      8
//	  3   5
//	1   2   3

