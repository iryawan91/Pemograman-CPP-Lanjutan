#include <iostream>
using namespace std;

int main() {
    // Inisialisasi awal
    int x = 5, y = 10; 
    int *p1, *p2; 

    // Soal 3
    x = y;       // nilai y (10) disalin ke x 
    p1 = &y;     // p1 menunjuk ke y 
    p2 = &x;     // p2 menunjuk ke x 

    // Output Hasil
    cout << "=== HASIL SOAL 3 ===" << endl;
    cout << "Nilai x : " << x << endl;  // Output: 10 
    cout << "Nilai y : " << y << endl;  // Output: 10 
    cout << "*p1     : " << *p1 << endl; // Output: 10 
    cout << "*p2     : " << *p2 << endl; // Output: 10 

    return 0;
}
