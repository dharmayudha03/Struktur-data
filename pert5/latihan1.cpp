#include <iostream>
using namespace std;

int pencaharian(string buah[], int lengh, string dtCari){
    for(int i = 0; i < lengh; i++){
        if(dtCari == buah[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    string buah[] = {"nangka", "semangka", "mangga", "anggur"};
    int lengh = sizeof(buah) / sizeof(buah[0]);

    string dtCari;

    cout << "Data yang tersedia : " << endl;
    for(int a = 0; a < lengh; a++){
        cout << "Index ke-" << a << " : " << buah[a] << endl;
    }

    cout << "Masukan data yang di cari : ";
    cin >> dtCari;

    int result = pencaharian(buah, lengh, dtCari);

    if(result != -1){
        cout << "Data ditemukan di index ke-" << result << endl;
    }else {
        cout << "Data tidak ditemukan";
    }
}