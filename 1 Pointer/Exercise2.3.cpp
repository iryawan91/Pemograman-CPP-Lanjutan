#include <iostream>
using namespace std;

int main() {
    // Inisialisasi awal
    int x = 5, y = 10; 
    int *p1, *p2; 

    // Soal 3
    p1 = &x;     // p1 menunjuk ke x 
    *p1 = y;     // nilai y (10) disalin ke lokasi x (*p1) 

    // Output Hasil
    cout << "=== HASIL SOAL 3 ===" << endl;
    cout << "Nilai x : " << x << endl;  // Output: 10 
    cout << "Nilai y : " << y << endl;  // Output: 10 
    cout << "*p1     : " << *p1 << endl; // Output: 10 

    return 0;
}
