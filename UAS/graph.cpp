#include <iostream>
// #include <stdio.h>
using namespace std;

typedef struct tipeS {
    struct tipeS *Left;
    int INFO;
    struct tipeS *Right;
}simpul;

simpul *P, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;
simpul *PointS[5];

int main() {
    int A[10][10] = {
    {0,6,0,0,0,3,4,0,0,0},
    {0,0,7,0,0,0,0,0,0,4},
    {0,0,0,2,0,0,0,0,0,2},
    {0,0,0,0,3,0,0,4,2,0},
    {0,0,0,0,0,5,0,0,0,0},
    {5,0,0,3,4,0,5,0,0,0},
    {0,0,0,0,6,2,0,3,0,0},
    {0,0,3,3,0,0,0,0,4,5},
    {0,0,0,0,5,0,0,0,0,0},
    {0,0,3,0,0,0,0,0,0,0}
};
    char NmS[11] = "ABCDEFGHIJ";
    int I, J;

    //Simpul Vertex yang pertama
    I=0;J=0;
    P=new simpul;
    P->INFO = NmS[0];
    FIRST = P;
    LAST = P;
    P->Left = NULL;
    P->Right = NULL;
    PointS[0] = P;
    printf("%c", P->INFO);
    printf(" alamat %p", (void*)PointS[0]);

    //Simpul Vertex yang berikutnya
    for (I=1; I<=9; I++) {
        P = new simpul;
        P->INFO = NmS[I];
        LAST->Left = P;
        LAST = LAST->Left;
        P->Left = NULL;
        P->Right = NULL;
        PointS[I] = P;
        printf("\n%c", P->INFO);
        printf(" alamat %p", (void*)PointS[I]);
    }
    
    //Simpul Edge untuk semua Vertex
    printf("\n");
    Q = FIRST;
    for (I=0; I<=9; I++) {
        R=Q;
        printf("\nVertex %c", Q->INFO);
        for (J=0; J<=9; J++) {
            if (A[I][J] !=0) {
                P = new simpul;
                P->INFO = A[I][J];
                R->Right = P;
                P->Left = PointS[J];
                printf(" berhubungan dengan %c dengan ", P->Left->INFO);
                printf("bobot = %d,", P->INFO);
                P->Right = NULL;
                R = P;
            }
        } 
        Q = Q->Left;
    }
    return 0;
}