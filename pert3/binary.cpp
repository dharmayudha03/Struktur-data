#include <iostream>
#include <vector>

using namespace std; // Menambahkan using namespace std;

int binarySearch(const vector<int> & arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Return -1 jika elemen tidak ditemukan
}

int main() {
    vector<int> arr = {5, 6, 7, 9, 10, 15, 17};
    int target;
    cout << "Masukan data yang dicari : ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Elemen " << target << " ditemukan di indeks ke-" << result << "." << endl;
    } else {
        cout << "Elemen " << target << " tidak ditemukan dalam array." << endl;
    }

    return 0;
}
