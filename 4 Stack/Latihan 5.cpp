#include <iostream> // Header untuk fungsi input-output (cout, endl)
#include <stack>    // Header untuk memanfaatkan struktur data stack dari STL
#include <string>   // Header untuk mengolah tipe data string
#include <cctype>   // Header untuk fungsi pengecekan karakter (isalpha)

using namespace std; // Menghindari penulisan std:: pada setiap fungsi

// Fungsi untuk membentuk ekspresi infix bertanda kurung dari dua operand dan satu operator
string gabungOp(string op1, string op2, char op) {
    return "(" + op1 + " " + op + " " + op2 + ")"; // Gabungkan operand1, operator, dan operand2 dengan tanda kurung
}

// Fungsi utama untuk mengevaluasi ekspresi Postfix berbasis simbolis
string evaluasiPostfixSimbolis(string exp) {
    stack<string> s; // Stack untuk menyimpan sub-ekspresi berbentuk string

    // Menampilkan baris judul tabel simulasi
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Char\t\tAksi\t\t\t\tStack" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // Perulangan untuk membaca setiap karakter dari ekspresi postfix
    for (size_t i = 0; i < exp.length(); i++) {
        char ch = exp[i]; // Ambil karakter pada indeks i

        // Jika karakter berupa spasi, abaikan
        if (ch == ' ') continue;

        // 1. Jika karakter adalah operand (huruf A, B, C, D), push ke dalam stack
        if (isalpha(ch)) {
            string op(1, ch); // Ubah karakter char menjadi string
            s.push(op);       // Masukkan operand ke stack

            cout << ch << "\t\tPush " << ch << " (operand)\t\t"; // Tampilkan aksi push
        }
        // 2. Jika karakter adalah operator (+, -, *, /)
        else {
            string op2 = s.top(); s.pop(); // Ambil elemen teratas (operand kedua)
            string op1 = s.top(); s.pop(); // Ambil elemen berikutnya (operand pertama)

            string hasil = gabungOp(op1, op2, ch); // Gabungkan menjadi bentuk ekspresi
            s.push(hasil);                         // Masukkan hasil penggabungan kembali ke stack

            cout << ch << "\t\tOperator " << ch << " Pop 2 & Push " << hasil << "\t"; // Tampilkan aksi operator
        }

        // Menyusun dan menampilkan kondisi stack saat ini (dari bawah ke atas)
        string tempStack = "";
        stack<string> copyStack = s;
        while (!copyStack.empty()) {
            tempStack = copyStack.top() + (tempStack.empty() ? "" : ", ") + tempStack;
            copyStack.pop();
        }
        cout << "[ " << tempStack << " ]" << endl;
    }

    return s.top(); // Hasil akhir penataan infix berada di top stack
}

int main() {
    string ekspresi = "AB+CD-*"; // Ekspresi postfix simbolis

    cout << "Ekspresi Postfix : " << ekspresi << endl << endl;
    string hasilInfix = evaluasiPostfixSimbolis(ekspresi); // Panggil fungsi evaluasi
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Bentuk Infix     : " << hasilInfix << endl; // Tampilkan bentuk ekspresi akhir

    return 0; // Tanda bahwa program berhasil dijalankan sampai selesai
}
