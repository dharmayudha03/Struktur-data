#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

// Fungsi untuk menghitung gaji
void hitungGaji(int kehadiran, int jumlah_lemburan, int grade) {
    map<int, map<string, int>> data_gaji = {
        {1, {{"gapok", 4000000}, {"tunjangan", 100000}, {"transfortasi", 100000}, {"uang_makan", 250000}, {"lemburan", 15000}}},
        {2, {{"gapok", 5000000}, {"tunjangan", 300000}, {"transfortasi", 300000}, {"uang_makan", 250000}, {"lemburan", 30000}}},
        {3, {{"gapok", 6000000}, {"tunjangan", 300000}, {"transfortasi", 300000}, {"uang_makan", 250000}, {"lemburan", 25000}}}
    };

    double pemotongan = static_cast<double>(kehadiran) / 22;

        if (kehadiran <= 0) {
            cout << "Maaf, Anda tidak bekerja, maka tidak ada gaji" << endl;
        } else {
            if (data_gaji.find(grade) != data_gaji.end()) {
                map<string, int> gaji = data_gaji[grade];
                int gapok = gaji["gapok"];
                int tunjangan = gaji["tunjangan"];
                int transportasi = gaji["transfortasi"];
                int uang_makan = gaji["uang_makan"];
                int lemburan = gaji["lemburan"];

                lemburan = jumlah_lemburan * lemburan;

                double total_gaji = pemotongan * gapok + tunjangan + transportasi + uang_makan + lemburan;

                cout << string(43, '=') << endl;
                cout << "Total gaji Anda: Rp." << fixed << setprecision(0) << total_gaji << endl;
                cout << string(43, '=') << endl;
            } else {
                cout << "Grade tidak ditemukan" << endl;
            }
        }
}

int main() {
    cout << "Perhitungan Gaji" << endl;
    cout << string(43, '=') << endl;
    
    int kehadiran, grade, jumlah_lemburan;
    char inginMengulang;

    do {
        cout << "Jumlah kehadiran dalam 1 Bulan (*22 hari) = ";
        cin >> kehadiran;
        cout << "Grade (1 ~ 10) = ";
        cin >> grade;
        cout << "Jumlah jam lembur = ";
        cin >> jumlah_lemburan;

    // Memanggil fungsi hitungGaji
    hitungGaji(kehadiran, jumlah_lemburan, grade);

    // Tanya apakah ingin menghitung gaji lagi
        cout << "Apakah ingin menghitung gaji karyawan lagi? (y/n): ";
        cin >> inginMengulang;

    } while (inginMengulang == 'y' || inginMengulang == 'Y');

    cout << "Terimakasih sudah bermain";
    return 0;
}

