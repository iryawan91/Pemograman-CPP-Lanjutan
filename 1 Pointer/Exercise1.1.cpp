#include <iostream>
using namespace std;

int main() {
    // Inisialisasi awal
    int x = 5, y = 10; 
    int *p1, *p2; 

    // Soal 1.1
    p1 = &x;     // p1 menyimpan alamat x 
    *p1 = 7;     // nilai x diubah menjadi 7 lewat p1

    // Output Hasil
    cout << "=== HASIL SOAL 1 ===" << endl;
    cout << "Nilai x : " << x << endl;  // Output: 7
    cout << "Nilai y : " << y << endl;  // Output: 10
    cout << "*p1     : " << *p1 << endl; // Output: 7

    return 0;
}
