#include <iostream>
using namespace std;

int main(){
    int a[] = {5, 6, 7, 9, 10, 15, 17};
    int l, r, mid, ketemu, x, i;

    cout << "Masukan nilai x: ";
    cin >> x;

    ketemu = 0;
    l = 0;
    r = 6;

    while((l <= r) && (x >= a[l]) && (x <= a[r]) && (ketemu == 0)){
        mid = (l + r)/2;
        if(x < a[mid]){
            r = mid;
        }else if (x > a[mid]){
            l = mid;
        }else{
            ketemu = 1;
        }  
    }
    if(ketemu == 1){
        cout << "Ditemukan nilai x : " << x;
    }else {
        cout << "Tidak Ditemukan";
    }


}