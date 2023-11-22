#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

void hitungGaji(int kehadiran, int jumlah_lembur, int grade){
    map<int, map<string, int>> data_gaji = {
        {1, {{"gapok", 4000000}, {"tunjangan", 200000}, {"uang_makan", 250000}, {"transfortasi", 300000}, {"lemburan", 25000}}},
        {2, {{"gapok", 5000000}, {"tunjangan", 300000}, {"uang_makan", 250000}, {"transfortasi", 400000}, {"lemburan", 30000}}},
        {3, {{"gapok", 6000000}, {"tunjangan", 400000}, {"uang_makan", 250000}, {"transfortasi", 500000}, {"lemburan", 35000}}}
    };

    double pemotongan = static_cast<double>(kehadiran) / 22;

    if(kehadiran <= 0){
        cout << "Anda tidak bekerja, maka anda tidak ada gaji bulan ini" << endl;
    }else {
        if(data_gaji.find(grade) != data_gaji.end()){
            map<string, int> gaji = data_gaji[grade];
            int gapok = gaji["gapok"];
            int tunjangan = gaji["tunjangan"];
            int uang_makan = gaji["uang_makan"];
            int transfortasi = gaji["transfortasi"];
            int lemburan = gaji["lemburan"];

            lemburan = jumlah_lembur * lemburan;

            double total_gaji = pemotongan * gapok + tunjangan + uang_makan + transfortasi + lemburan;

            cout << string(43, '=') << endl;
            cout << "Total Gaji Anda = Rp." << fixed << setprecision(0) << total_gaji << endl;
            cout << string(43, '=') << endl;

        }else{
            cout << "Grade tidak ditemukan" << endl;
        }
    }
}

int main(){
    cout << "Program Menghitung Data Gaji Karyawan" << endl;
    cout << string(43, '=') << endl;

    int kehadiran, jumlah_lembur, grade;
    char mengulang;

    do {
        cout << "Masukan jumlah kehadiran selama 1 bulan (*22 hari) = ";
        cin >> kehadiran;
        cout << "Grade (1 ~ 3) = ";
        cin >> grade;
        cout << "Masukan jumlah lembur (jam) = ";
        cin >> jumlah_lembur;

        hitungGaji(kehadiran, jumlah_lembur, grade);

        cout << "Apakah anda ingin menghitung data gaji lagi? (y/n): ";
        cin >> mengulang;
    }while( mengulang == 'y' || mengulang == 'Y');
    return 0;
}