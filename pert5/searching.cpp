#include <iostream>
using namespace std;

int main(){
    int angka[] = {5, 7, 8, 9, 10, 20, 24, 35};
    int lengh = sizeof(angka)/sizeof(*angka);
    int dtCari, hasilCari;

    cout << "Data yang tersedia : " << endl;
    for(int a = 0; a < lengh; a++){
        cout << "Index ke-" << a << ": " << angka[a] << endl;
    }

    cout << "Masukan data yang dicari: ";
    cin >> dtCari;

    for(int b = 0; b < lengh; b++){
        if(dtCari == angka[b]){
            hasilCari++;
        }
    }

    if(hasilCari == 0){
        cout << "Data tidak ditemukan";
    }else {
        cout << "Data " << dtCari << " ditemukan di ";
        for(int c = 0; c < lengh; c++){
            if(dtCari == angka[c]){
                cout << "index ke-" << c << endl;
            }
        }
    }
}