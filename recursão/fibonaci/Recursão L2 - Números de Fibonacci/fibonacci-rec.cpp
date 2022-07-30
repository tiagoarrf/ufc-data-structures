   //#####################################//
  //####### By Tiago A. Fontenele #######//
 //############ 23/12/2020 #############//
//#####################################//
#include <iostream>

using namespace std;
int fibRec(int n){                                         
	return (n == 1 || n == 2)? 1 : (n == 0)? 0: fibRec(n - 1) + fibRec(n - 2); 
}

int main(void){
	int n = 0;
	cin >> n;
	cout << fibRec(n);
   return 0;
}
