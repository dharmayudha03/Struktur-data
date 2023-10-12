#include <iostream>
using namespace std;

int main(){
    int B[4][3] = {
        {7,8,9},
        {1,2,3},
        {4,5,6},
        {10,11,12}
    };
    int r; //row
    int c; //coloum

    // penjumlahan
    B[1][1] = B[2][2] + B[0][1];

    // perkalian
    

    for (r = 0; r < 4; r++){
        for (c = 0; c < 3; c++){
            printf("Elemen Row [%d], Col [%d] = %d \n", r, c, B[r][c]);
        }
    }



}