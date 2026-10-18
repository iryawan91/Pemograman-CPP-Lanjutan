#include <iostream> // Header untuk operasi input-output (cout, endl)
#include <stack>    // Header untuk memanfaatkan struktur data stack dari STL
#include <string>   // Header untuk mengolah tipe data string
#include <cctype>   // Header untuk fungsi pengecekan angka (isdigit)

using namespace std; // Menghindari penulisan std:: pada setiap fungsi

// Fungsi untuk melakukan operasi aritmatika dasar
int hitung(int a, int b, char op) {
    if (op == '+') return a + b; // Penjumlahan
    if (op == '-') return a - b; // Pengurangan
    if (op == '*') return a * b; // Perkalian
    if (op == '/') return a / b; // Pembagian
    return 0;                    // Nilai default jika operator tidak dikenal
}

// Fungsi utama untuk mengevaluasi ekspresi Postfix
int evaluasiPostfix(string exp) {
    stack<int> s; // Stack khusus untuk menyimpan nilai operand (angka)

    // Menampilkan baris judul tabel simulasi
    cout << "---------------------------------------------------------" << endl;
    cout << "Expression\t\tAksi\t\t\tStack" << endl;
    cout << "---------------------------------------------------------" << endl;

    // Perulangan untuk membaca setiap karakter dari ekspresi
    for (size_t i = 0; i < exp.length(); i++) {
        char ch = exp[i]; // Ambil karakter pada indeks i

        // Jika karakter berupa spasi, abaikan dan lanjut ke karakter berikutnya
        if (ch == ' ') continue;

        // 1. Jika karakter adalah operand (angka), push ke dalam stack
        if (isdigit(ch)) {
            int val = ch - '0'; // Mengonversi tipe char ke angka (int)
            s.push(val);        // Masukkan angka ke stack

            cout << ch << "\t\t\tPush " << val << "\t\t\t";
        }
        // 2. Jika karakter adalah operator (+, -, *, /)
        else {
            int val2 = s.top(); s.pop(); // Ambil angka teratas (operand kedua)
            int val1 = s.top(); s.pop(); // Ambil angka berikutnya (operand pertama)

            int hasil = hitung(val1, val2, ch); // Hitung hasil operasi
            s.push(hasil);                      // Masukkan hasil perhitungan kembali ke stack

            cout << ch << "\t\t\tPop " << val2 << " & " << val1 
                 << ", Hitung " << val1 << ch << val2 << " = " << hasil << "\t";
        }

        // Menyusun dan menampilkan kondisi stack saat ini (dari bawah ke atas)
        string tempStack = "";
        stack<int> copyStack = s;
        while (!copyStack.empty()) {
            tempStack = to_string(copyStack.top()) + " " + tempStack;
            copyStack.pop();
        }
        cout << "[ " << tempStack << "]" << endl;
    }

    return s.top(); // Hasil akhir berada di posisi paling atas stack
}

int main() {
    string ekspresi = "4 5 + 7 2 - *"; // Ekspresi postfix yang dievaluasi

    cout << "Ekspresi Postfix : " << ekspresi << endl << endl;
    int hasilAkhir = evaluasiPostfix(ekspresi); // Panggil fungsi evaluasi
    cout << "---------------------------------------------------------" << endl;
    cout << "Hasil Akhir      : " << hasilAkhir << endl; // Tampilkan hasil akhir (45)

    return 0; // Tanda bahwa program berhasil dijalankan sampai selesai
}
