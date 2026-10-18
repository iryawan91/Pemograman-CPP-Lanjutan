#include <iostream> // Header untuk fungsi input-output (cout, endl)
#include <stack>    // Header untuk menggunakan pustaka standar stack
#include <string>   // Header untuk mengolah tipe data string
#include <cctype>   // Header untuk fungsi pengecekan karakter (isalnum)

using namespace std; // Agar tidak perlu menulis std:: di setiap perintah

// Fungsi untuk menentukan tingkat prioritas (precedence) operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1; // Prioritas rendah (tingkat 1)
    if (op == '*' || op == '/') return 2; // Prioritas tinggi (tingkat 2)
    return 0;                             // Tanda kurung atau karakter lain (tingkat 0)
}

// Fungsi utama untuk mengubah ekspresi Infix menjadi Postfix
string infixToPostfix(string infix) {
    stack<char> s;  // Deklarasi stack untuk menyimpan sementara operator
    string output = ""; // String untuk menampung hasil akhir postfix

    // Menampilkan header tabel simulasi
    cout << "---------------------------------------------------------" << endl;
    cout << "Char\t\tStack\t\tOutput" << endl;
    cout << "---------------------------------------------------------" << endl;

    // Perulangan untuk membaca setiap karakter dari ekspresi infix
    for (size_t i = 0; i < infix.length(); i++) {
        char ch = infix[i]; // Ambil satu karakter berdasarkan indeks i

        // 1. Jika karakter adalah operand (angka/huruf), langsung tambahkan ke output
        if (isalnum(ch)) {
            output += ch;
        }
        // 2. Jika karakter adalah kurung buka '(', masukkan (push) ke stack
        else if (ch == '(') {
            s.push(ch);
        }
        // 3. Jika karakter adalah kurung tutup ')', keluarkan isi stack sampai bertemu '('
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                output += s.top(); // Pindahkan operator ke output
                s.pop();           // Hapus operator dari stack
            }
            if (!s.empty()) s.pop(); // Hapus tanda kurung buka '(' dari stack
        }
        // 4. Jika karakter adalah operator (+, -, *, /)
        else {
            // Keluarkan operator dari stack jika prioritasnya lebih tinggi atau sama
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                output += s.top(); // Pindahkan operator lama ke output
                s.pop();           // Hapus operator lama dari stack
            }
            s.push(ch); // Masukkan operator baru ke dalam stack
        }

        // Menyusun isi stack saat ini untuk ditampilkan di layar
        string tempStack = "";
        stack<char> copyStack = s; // Salin stack agar tidak merusak data asli
        while (!copyStack.empty()) {
            tempStack = copyStack.top() + tempStack; // Urutkan dari bawah ke atas
            copyStack.pop();
        }

        // Tampilkan proses per langkah ke tabel
        cout << ch << "\t\t" << (tempStack.empty() ? "Empty" : tempStack) << "\t\t" << output << endl;
    }

    // Mengeluarkan sisa operator yang masih ada di dalam stack setelah perulangan selesai
    while (!s.empty()) {
        output += s.top(); // Pindahkan sisa operator ke output
        s.pop();           // Hapus operator dari stack

        // Tampilkan kondisi stack saat pengosongan akhir
        string tempStack = "";
        stack<char> copyStack = s;
        while (!copyStack.empty()) {
            tempStack = copyStack.top() + tempStack;
            copyStack.pop();
        }
        cout << "End\t\t" << (tempStack.empty() ? "Empty" : tempStack) << "\t\t" << output << endl;
    }

    return output; // Mengembalikan hasil konversi postfix
}

// Fungsi utama program
int main() {
    string infix = "2*3/(2-1)+5*3"; // Soal ekspresi infix yang akan dikonversi

    cout << "Ekspresi Infix  : " << infix << endl << endl;
    string postfix = infixToPostfix(infix); // Panggil fungsi konversi
    cout << "---------------------------------------------------------" << endl;
    cout << "Hasil Postfix   : " << postfix << endl; // Tampilkan hasil akhir

    return 0; // Mengembalikan nilai 0 tanda program selesai dengan sukses
}
