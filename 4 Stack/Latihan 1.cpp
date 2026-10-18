#include <iostream> // Header untuk operasi input-output (cout, endl)
using namespace std; // Agar tidak perlu menulis std:: sebelum cout

#define MAX 10 // Menentukan kapasitas maksimum stack yaitu 10 elemen

// Struktur data untuk Stack
struct Stack {
    int data[MAX]; // Array untuk menyimpan angka di dalam stack
    int top = -1;  // Posisi teratas stack (diinisialisasi -1 berarti kosong)
};

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack &S) {
    return S.top == -1; // Mengembalikan true jika top bernilai -1
}

// Prosedur untuk menambah elemen ke dalam stack (push)
void push(Stack &S, int val) {
    if (S.top < MAX - 1) { // Cek apakah stack belum penuh
        S.top++;            // Naikkan indeks top sejumlah 1
        S.data[S.top] = val; // Simpan nilai baru ke indeks top
        cout << "push " << val << " \t-> "; // Tampilkan pesan push ke layar
    }
}

// Prosedur untuk mengeluarkan elemen dari stack (pop)
void pop(Stack &S) {
    if (!isEmpty(S)) { // Cek apakah stack tidak kosong
        int poppedVal = S.data[S.top]; // Ambil nilai paling atas
        S.top--;                       // Turunkan indeks top sejumlah 1
        cout << "pop (" << poppedVal << ") \t-> "; // Tampilkan nilai yang di-pop
    }
}

// Prosedur untuk menampilkan seluruh isi stack saat ini
void printStack(Stack S) {
    cout << "Isi Stack: [";
    for (int i = 0; i <= S.top; i++) { // Perulangan dari elemen terbawah hingga teratas
        cout << S.data[i];             // Tampilkan nilai elemen
        if (i < S.top) cout << ", ";  // Tambahkan koma pemisah antar elemen
    }
    cout << "]" << endl; // Tutup kurung siku dan buat baris baru
}

// Fungsi utama program
int main() {
    Stack S; // Deklarasi variabel S bertipe Stack

    cout << "=== SIMULASI OPERASI STACK ===" << endl << endl;

    // 1. Memasukkan angka 10 ke stack
    push(S, 10);
    printStack(S); // Tampilkan isi stack: [10]

    // 2. Memasukkan angka 5 ke stack
    push(S, 5);
    printStack(S); // Tampilkan isi stack: [10, 5]

    // 3. Mengeluarkan elemen teratas (5)
    pop(S);
    printStack(S); // Tampilkan isi stack: [10]

    // 4. Memasukkan angka 15 ke stack
    push(S, 15);
    printStack(S); // Tampilkan isi stack: [10, 15]

    // 5. Memasukkan angka 7 ke stack
    push(S, 7);
    printStack(S); // Tampilkan isi stack: [10, 15, 7]

    // 6. Mengeluarkan elemen teratas (7)
    pop(S);
    printStack(S); // Tampilkan isi stack akhir: [10, 15]

    return 0; // Mengembalikan nilai 0 tanda program selesai dengan sukses
}
