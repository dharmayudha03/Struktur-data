#include <stdio.h>
using namespace std;

int main(){
    int n = 0;
    int *p = NULL;
    n = 10;

    printf("Alamat n = %p", &n);
    printf("\nNilai n = %d", n);
    printf("\nAlamat p = %p", &p);
    printf("\nNilai p = %p", p);

}