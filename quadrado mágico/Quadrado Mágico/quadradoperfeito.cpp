//By Tiago A. Fontenele
//24/11/2020
#include <iostream>
int main(void){
    int mat[3][3];
    int d1 = 0;
    int d2 = 0;
    int cl = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> mat[i][j];
            if(i == j){
                d1 += mat[i][j];
            }
            if(i + j == 2){
                d2 += mat[i][j];
            }
            cl += mat[i][j];
        }
    }
    if(d1 == d2 && cl == d1 * 3){
        std::cout << "sim";
    }
    else{
        std::cout << "nao";
    }
    return 0;
}
