#include <iostream>
using namespace std;

int main(){
    int A[3][2][4][2] = {{{{1,4}, {2,5}, {3,7}, {4,8}}, {{5,4}, {6,7}, {7,3}, {8,2}}},
                        {{{11,22}, {12,23}, {13,24}, {14,25}}, {{15,26}, {16,27}, {17,28}, {18,29}}},
                        {{{21,31}, {22,32}, {23,33}, {24,34}}, {{23,35}, {26,36}, {27,37}, {28,38}}}
    };

    int r;
    int c;
    int d;
    int dd;

    for (r = 0; r < 3; r++){
        for (c = 0; c < 2; c++){
            for (d = 0; d < 4; d++){
                for (dd = 0; dd < 2; dd++){
                    printf("Elemen Row[%d], Col[%d], Depth[%d], DepthinDepth[%d] = [%d]\n", r, c, d, dd, A[r][c][d][dd]);
                }
            }
        }
    }
}