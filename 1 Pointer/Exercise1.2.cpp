#include <iostream>
using namespace std;

int main() {
    // Inisialisasi awal
    int x = 5, y = 10; 
    int *p1, *p2; 

    // Soal 2
    p2 = &y;     // p2 menyimpan alamat y 
    x = *p2;     // nilai y (*p2 = 10) disalin ke x 

    // Output Hasil
    cout << "=== HASIL SOAL 2 ===" << endl;
    cout << "Nilai x : " << x << endl;  // Output: 10 
    cout << "Nilai y : " << y << endl;  // Output: 10 
    cout << "*p2     : " << *p2 << endl; // Output: 10 

    return 0;
}
