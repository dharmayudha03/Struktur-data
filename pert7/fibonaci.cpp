#include <iostream>
using namespace std;

int Fibonaci(int n){
    if((n == 1) || (n == 2)){
        return(1);
    }else {
        return (Fibonaci(n-1) + Fibonaci(n-2));
    }
}
int main(){
    int n;

    cout << "Masukan angka fibonaci: ";
    cin >> n;
    cout << "Nilai fibonaci " << Fibonaci(n-1) << " + " << Fibonaci(n-2) << " = ";
    cout << Fibonaci(n);

    return 0;
}