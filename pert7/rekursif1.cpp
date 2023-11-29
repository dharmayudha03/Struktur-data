#include <iostream>
using namespace std;

int Faktorial(int n){
    if((n == 0) || (n == 1)){
        return (1);
    }else {
        return (n * Faktorial(n-1));
    }
}

void Kombinasi(int n, int r){
    int n;
    int r;
    if( n < r ){
        cout << 0;
    }else {
        cout << (Faktorial(n) / Faktorial(r) * Faktorial(n-r));
    }
}

int main(){
    int n;
    int r;
    cout << "Masukan nilai n: ";
    cin >> n;
    cout << "Masukan nilai r: ";
    cin >> r;

    cout << "Hasil Kombinasi = ";
    cout << Kombinasi(n, r) << endl;
    return 0;
}
