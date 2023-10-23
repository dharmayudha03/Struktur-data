#include <iostream>
using namespace std;

int sequentialSearch(int angka[], int lengh, int dtCari){
    for(int i = 0; i < lengh; i++){
        if(dtCari == angka[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int angka[] = {5, 7, 8, 9, 10, 20, 24, 35};
    int lengh = sizeof(angka) / sizeof(angka[0]);

    int dtCari;
    
    cout << "Data yang tersedia : " << endl;
    for(int a = 0; a < lengh; a++){
        cout << "Index ke-" << a << " : " << angka[a] << endl;
    }

    cout << "Masukan data yang dicari: ";
    cin >> dtCari;

    int result = sequentialSearch(angka, lengh, dtCari);

    if(result != -1){
        cout << "Data ditemukan di index ke-" << result << endl;
    }else {
        cout << "Data tidak ditemukan";
    }
}