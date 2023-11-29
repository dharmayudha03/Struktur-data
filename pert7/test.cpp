#include <iostream>
#include <iomanip>
#include <map>
#include <limits> // Diperlukan untuk membersihkan buffer input
#include <sstream> // Diperlukan untuk menggunakan ostringstream
using namespace std;

// Fungsi untuk menghitung gaji dan memformat hasil sesuai kebutuhan
string hitungGaji(int kehadiran, int grade, int jumlah_lemburan) {
    map<int, map<string, int>> data_gaji = {
        {1, {{"gapok", 4000000}, {"tunjangan", 100000}, {"transfortasi", 100000}, {"uang_makan", 250000}, {"lemburan", 15000}}},
        {2, {{"gapok", 5000000}, {"tunjangan", 200000}, {"transfortasi", 200000}, {"uang_makan", 250000}, {"lemburan", 20000}}},
        {3, {{"gapok", 6000000}, {"tunjangan", 300000}, {"transfortasi", 300000}, {"uang_makan", 250000}, {"lemburan", 25000}}}
    };

    int pemotongan = static_cast<int>(kehadiran) / 22;

    if (kehadiran <= 0) {
        return "Maaf, Anda tidak bekerja, maka tidak ada gaji";
    } else {
        if (data_gaji.find(grade) != data_gaji.end()) {
            map<string, int> gaji = data_gaji[grade];
            int gapok = gaji["gapok"];
            int tunjangan = gaji["tunjangan"];
            int transportasi = gaji["transfortasi"];
            int uang_makan = gaji["uang_makan"];
            int lemburan = gaji["lemburan"];

            lemburan = jumlah_lemburan * lemburan;

            int total_gaji = pemotongan * gapok + tunjangan + transportasi + uang_makan + lemburan;

            // Menghitung potongan pajak sebesar 5% dari total gaji
            // double potongan_pajak = 0.05 * total_gaji;
            
            // // Mengurangkan potongan pajak dari total gaji
            // total_gaji -= potongan_pajak;

            // Memformat jumlah gaji sesuai kebutuhan
            ostringstream formattedGaji;
            if (total_gaji >= 1000000) {
                formattedGaji << "Rp " << fixed << setprecision(0) << total_gaji / 1000000 << ",000,000";
            } else if (total_gaji >= 1000) {
                formattedGaji << "Rp " << fixed << setprecision(0) << total_gaji / 1000 << ",000";
            } else {
                formattedGaji << "Rp " << fixed << setprecision(0) << total_gaji;
            }

            return formattedGaji.str();
        } else {
            return "Grade tidak ditemukan";
        }
    }
}

// Fungsi untuk menanyakan apakah pengguna ingin mengulang
bool inginMengulang() {
    char pilihan;
    cout << "Apakah Anda ingin mengulang? (y/n): ";
    cin >> pilihan;

    // Membersihkan buffer input untuk menghindari masalah input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return (pilihan == 'y' || pilihan == 'Y');
}

int main() {
    do {
        cout << "Perhitungan Gaji" << endl;
        cout << string(43, '=') << endl;

        int kehadiran, grade, jumlah_lemburan;

        cout << "Jumlah kehadiran dalam 1 Bulan (*22 hari) = ";
        cin >> kehadiran;
        cout << "Grade (1 ~ 3) = ";
        cin >> grade;
        cout << "Jumlah jam lembur = ";
        cin >> jumlah_lemburan;

        // Memanggil fungsi hitungGaji dan menampilkan hasilnya
        cout << hitungGaji(kehadiran, grade, jumlah_lemburan) << endl;

    } while (inginMengulang()); // Melakukan perulangan selama pengguna ingin mengulang

    cout << "Terimakasih sudah bermain";

    return 0;
}
