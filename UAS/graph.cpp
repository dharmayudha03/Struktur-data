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
    int A[5][5] = {{0,5,0,2,0},{6,0,3,0,0},{0,0,0,0,9},{0,0,12,0,7},{0,14,0,0,0}};
    char NmS[6] = "ABCDE";
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
    for (I=1; I<=4; I++) {
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
    Q = FIRST;
    for (I=0; I<=4; I++) {
        R=Q;
        printf("\nVertex %c ....", Q->INFO);
        for (J=0; J<=4; J++) {
            if (A[I][J] !=0) {
                P = new simpul;
                P->INFO = A[I][J];
                R->Right = P;
                P->Left = PointS[J];
                printf(" berhubungan dengan %c :", P->Left->INFO);
                printf("bobot %d :", P->INFO);
                P->Right = NULL;
                R = P;
            }
        } 
        Q = Q->Left;
    }
    return 0;
}