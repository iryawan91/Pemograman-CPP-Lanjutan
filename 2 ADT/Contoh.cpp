#include <iostream>

using namespace std;

// ========================================================
// 1. Definisi/Spesifikasi Type dan Header Fungsi (.h)
// ========================================================

// Definisi Struktur Data ADT Mahasiswa
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

// Deklarasi Protokol / Header Fungsi & Prosedur
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

// ========================================================
// 2. Program Utama / Driver Main Function
// ========================================================
int main()
{
    mahasiswa mhs;
    
    // Memanggil prosedur input data
    inputMhs(mhs);
    
    // Memanggil fungsi hitung rata-rata dan menampilkannya
    cout << "rata-rata = " << rata2(mhs);
    
    return 0;
}

// ========================================================
// 3. Body / Realisasi dari Primitif (.cpp / .c)
// ========================================================

// Realisasi Prosedur Input Data
void inputMhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> m.nim;
    cout << "input nilai = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

// Realisasi Fungsi Hitung Rata-Rata
float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
