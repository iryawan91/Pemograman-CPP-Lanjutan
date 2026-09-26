#include <iostream>
using namespace std;

int main() {
    // Inisialisasi awal
    int x = 5, y = 10; 
    int *p1, *p2; 

    // Soal 4
    p2 = &x;     // p2 menunjuk ke x
    p1 = p2;     // p1 menyalin isi p2 (p1 dan p2 sama-sama menunjuk ke x) 
    *p2 = 6;     // nilai x diubah menjadi 6 lewat p2 

    // Output Hasil
    cout << "=== HASIL SOAL 4 ===" << endl;
    cout << "Nilai x : " << x << endl;  // Output: 6 
    cout << "Nilai y : " << y << endl;  // Output: 10 
    cout << "*p1     : " << *p1 << endl; // Output: 6 
    cout << "*p2     : " << *p2 << endl; // Output: 6 

    return 0;
}
