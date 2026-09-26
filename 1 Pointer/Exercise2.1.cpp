#include <iostream>
using namespace std;

int main() {
    // Inisialisasi awal
    int x = 5, y = 10; 
    int *p1, *p2; 

    // Soal 1
    p1 = &y;     // p1 menunjuk ke y 
    p2 = &x;     // p2 menunjuk ke x 
    *p1 = *p2;   // nilai x (*p2 = 5) disalin ke lokasi y (*p1) 

    // Output Hasil
    cout << "=== HASIL SOAL 1 ===" << endl;
    cout << "Nilai x : " << x << endl;  // Output: 5 
    cout << "Nilai y : " << y << endl;  // Output: 5 
    cout << "*p1     : " << *p1 << endl; // Output: 5 
    cout << "*p2     : " << *p2 << endl; // Output: 5 

    return 0;
}
