#include <iostream>
using namespace std;

int main() {
    // Inisialisasi awal
    int x = 5, y = 10; 
    int *p1, *p2; 

    // Soal 2
    p2 = &x;     // p2 menunjuk ke x 
    *p2 = 7;     // nilai x diubah menjadi 7 lewat p2 
    p1 = p2;     // p1 menyalin p2 (keduanya menunjuk ke x) 

    // Output Hasil
    cout << "=== HASIL SOAL 2 ===" << endl;
    cout << "Nilai x : " << x << endl;  // Output: 7 
    cout << "Nilai y : " << y << endl;  // Output: 10 
    cout << "*p1     : " << *p1 << endl; // Output: 7 
    cout << "*p2     : " << *p2 << endl; // Output: 7 

    return 0;
}
