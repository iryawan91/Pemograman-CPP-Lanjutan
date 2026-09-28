#include <iostream>

using namespace std;

// ========================================================
// 1. DEFINISI TYPE & HEADER (Spesifikasi ADT Kerucut)
// ========================================================

// Bentuk Data Kerucut
struct Kerucut {
    float r; // Jari-jari
    float t; // Tinggi
    float s; // Sisi Miring (Garis Pelukis)
};

// Daftar Fungsi
void inputKerucut(Kerucut &k);
float hitungVolume(Kerucut k);
float hitungLuas(Kerucut k);

// ========================================================
// 2. PROGRAM UTAMA (Driver)
// ========================================================
int main()
{
    Kerucut krc;

    // Memanggil prosedur input
    inputKerucut(krc);

    // Menampilkan hasil
    cout << "\n--- HASIL ---" << endl;
    cout << "Volume         = " << hitungVolume(krc) << endl;
    cout << "Luas Permukaan = " << hitungLuas(krc) << endl;

    return 0;
}

// ========================================================
// 3. BODY / REALISASI (Cara Kerja Fungsi)
// ========================================================

// Prosedur Input
void inputKerucut(Kerucut &k) {
    cout << "Masukkan jari-jari   : ";
    cin >> k.r;
    cout << "Masukkan tinggi      : ";
    cin >> k.t;
    cout << "Masukkan sisi miring : ";
    cin >> k.s;
}

// Fungsi Hitung Volume: (3.14 * r * r * t) / 3
float hitungVolume(Kerucut k) {
    return (3.14 * k.r * k.r * k.t) / 3;
}

// Fungsi Hitung Luas Permukaan: (3.14 * r * r) + (3.14 * r * s)
float hitungLuas(Kerucut k) {
    float luasAlas = 3.14 * k.r * k.r;
    float luasSelimut = 3.14 * k.r * k.s;
    return luasAlas + luasSelimut;
}
