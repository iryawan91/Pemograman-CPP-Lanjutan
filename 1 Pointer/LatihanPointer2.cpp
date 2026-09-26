#include <iostream>
using namespace std;

int main() {
    // 1. Deklarasi Variabel  
    char a, b;                  // Variabel biasa bertipe char
    char *p1, *p2;              // Pointer khusus tipe char 

    cout << "=== SIMULASI OPERASI POINTER ===" << endl << endl;

    // Langkah 1: a <- 'c'
    a = 'c'; 
    cout << "1. Nilai variabel a awal : " << a << endl; 

    // Langkah 2: p1 <- &a
    p1 = &a;                    
    cout << "2. p1 menunjuk ke a (*p1) : " << *p1 << endl; 

    // Langkah 3: p2 <- p1
    p2 = p1;                   
    cout << "3. p2 menyalin p1 (*p2)   : " << *p2 << endl; 

    // Langkah 4: b <- *p1
    b = *p1;                   
    cout << "4. Nilai variabel b      : " << b << endl; 

    // Langkah 5: *p2 <- 'x'
    *p2 = 'x';                 
    cout << "5. Setelah *p2 :" << *p2 << endl; 
   

    return 0;
}
