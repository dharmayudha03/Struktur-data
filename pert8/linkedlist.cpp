#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct TNode {
    int nim;
    string nama;
    TNode* next;
};

int main() {
    TNode* baru = new TNode;

    // Meminta pengguna untuk memasukkan nilai nim
    cout << "Masukkan NIM: ";
    cin >> baru->nim;

    // Membersihkan karakter newline yang masih tersisa di buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Meminta pengguna untuk memasukkan nilai nama
    cout << "Masukkan Nama: ";
    getline(cin, baru->nama);

    baru->next = NULL;

    // Menampilkan nilai nim dan nama yang telah diinputkan
    cout << "\nData yang diinputkan:" << endl;
    cout << "NIM: " << baru->nim << endl;
    cout << "Nama: " << baru->nama << endl;

    // Jangan lupa untuk menghapus memori yang dialokasikan menggunakan new
    delete baru;

    return 0;
}
