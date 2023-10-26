#include <iostream>
using namespace std;

int main(){
    int x;
    int *a;

    x = 7;
    a = &x;

    printf("Alamat x adalah %p", &x);
    printf("\nNilai x adalah %d", x);
    printf("\nAlamat a adalah %p", &a);
    printf("\nNilai a adalah %p", a);
    printf("\nNilai *a adalah %d", *a);

    return 0;
    
}