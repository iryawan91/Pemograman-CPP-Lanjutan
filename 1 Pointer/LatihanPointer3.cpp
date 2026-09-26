#include <iostream>
using namespace std;

int main() {
    // 1. Deklarasi Variabel & Pointer (Dictionary)
    int a, b, c, d;                           // Variabel integer biasa
    int *p1, *p2, *p3, *p4;                   // Pointer khusus tipe integer

    // 2. Inisialisasi Nilai Awal
    a = 1; b = 2; c = 3; d = 4; 
    p1 = &a;                                  // p1 menunjuk ke a
    p2 = &b;                                  // p2 menunjuk ke b
    p3 = &c;                                  // p3 menunjuk ke c
    p4 = &d;                                  // p4 menunjuk ke d

    cout << "=== KONDISI AWAL ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl << endl;

    // 3. Eksekusi Algoritma Langkah demi Langkah
    
    // Langkah 1: p2 <- p1
    p2 = p1;                                  // p2 beralih menunjuk ke a

    // Langkah 2: *p4 <- *p1
    *p4 = *p1;                                // Mengubah nilai d (*p4) menjadi nilai a (*p1), d menjadi 1

    // Langkah 3: p3 <- &b
    p3 = &b;                                  // p3 beralih menunjuk ke b

    // Langkah 4: *p4 <- b
    *p4 = b;                                  // Mengubah nilai d (*p4) menjadi nilai b, d menjadi 2

    // 4. Output Hasil Akhir
    cout << "=== HASIL AKHIR NILAI VARIABEL ===" << endl;
    cout << "Nilai a : " << a << endl;         // Output: 1[cite: 13]
    cout << "Nilai b : " << b << endl;         // Output: 2[cite: 13]
    cout << "Nilai c : " << c << endl;         // Output: 3[cite: 13]
    cout << "Nilai d : " << d << endl << endl;  // Output: 2[cite: 13]


    return 0;
}
