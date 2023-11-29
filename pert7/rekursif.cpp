#include <iostream>
using namespace std;

int Faktorial(int n){
    if((n == 0) || (n == 1)){
        return (1);
    }else {
        return (n * Faktorial(n-1));
    }
}

void Rekursif(){
    for (int a = 5; a >= 1; a--) {
        cout << a << endl;
    }
}

int main(){
    int n;
    cout << "masukan nilai : ";
    cin >> n;
    cout << "Nilai perkalian dari " << n << " adalah: " << Faktorial(n) << endl;

    cout << "Nilai dari 5 ke 1:\n";
    Rekursif();

    return 0;
}