#include <iostream>
using namespace std;

int main(){
    int x[3][2][4] = {{{1,2,3,4}, {5,6,7,8}},
                      {{11,12,13,14}, {15,16,17,18}},
                      {{21,22,23,24}, {25,26,27,28}}};
    int r;
    int c;
    int d;

    // Penjumlahan
    x[1][1][1] = x[0][0][0] + x[0][1][0] + x[1][0][0];

    for (r = 0; r < 3; r++){
        for (c = 0; c < 2; c++){
            for (d = 0; d < 4; d++){
                printf("Elemen Row [%d], Col [%d], Depth [%d] = [%d] \n", r, c, d, x[r][c][d]);
            }
        }
    }


}