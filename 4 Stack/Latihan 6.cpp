#include <iostream> // Header untuk fungsi input-output (cout, endl)
#include <stack>    // Header untuk memanfaatkan fungsi stack
#include <string>   // Header untuk manipulasi tipe data string
#include <cctype>   // Header untuk fungsi pengecekan huruf (isalpha)

using namespace std; // Menghindari penggunaan std:: secara berulang

// Fungsi untuk menggabungkan dua operand dan satu operator menjadi bentuk infix
string gabungOp(string op1, string op2, char op) {
    return "(" + op1 + " " + op + " " + op2 + ")"; // Contoh: (A + B)
}

// Fungsi utama konversi Prefix ke Infix (membaca dari kanan ke kiri)
string evaluasiPrefixKeInfix(string prefix) {
    stack<string> s; // Stack untuk menyimpan elemen string/sub-ekspresi

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Char\t\tAksi\t\t\t\tStack" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // Perulangan dibaca dari KANAN ke KIRI (right to left)
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i]; // Ambil karakter dari indeks paling belakang

        // Jika ada spasi, dilewati
        if (ch == ' ') continue;

        // 1. Jika karakter adalah operand (huruf A, B, C, D), push ke stack
        if (isalpha(ch)) {
            string op(1, ch); // Ubah char menjadi string
            s.push(op);       // Masukkan ke stack

            cout << ch << "\t\tPush " << ch << " (operand)\t\t";
        }
        // 2. Jika karakter adalah operator (+, -, *, /)
        else {
            // Pada Prefix (kanan ke kiri): operand1 diambil pertama, operand2 diambil kedua
            string op1 = s.top(); s.pop(); // Pop elemen teratas (operand pertama)
            string op2 = s.top(); s.pop(); // Pop elemen kedua (operand kedua)

            string hasil = gabungOp(op1, op2, ch); // Gabungkan menjadi (op1 operator op2)
            s.push(hasil);                         // Masukkan kembali hasil gabungan ke stack

            cout << ch << "\t\tOperator " << ch << " Pop 2 & Push " << hasil << "\t";
        }

        // Tampilkan isi stack saat ini dari bawah ke atas
        string tempStack = "";
        stack<string> copyStack = s;
        while (!copyStack.empty()) {
            tempStack = copyStack.top() + (tempStack.empty() ? "" : ", ") + tempStack;
            copyStack.pop();
        }
        cout << "[ " << tempStack << " ]" << endl;
    }

    return s.top(); // Hasil akhir berupa bentuk Infix utuh berada di top stack
}

int main() {
    string prefix = "*+AB-CD"; // Ekspresi Prefix sesuai gambar

    cout << "Ekspresi Prefix  : " << prefix << endl << endl;
    string hasilInfix = evaluasiPrefixKeInfix(prefix); // Panggil fungsi konversi
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Bentuk Infix     : " << hasilInfix << endl; // Tampilkan hasil bentuk infix

    return 0; // Menandakan program berhasil dijalankan sampai selesai
}
