#include <iostream>
using namespace std;

// 1. Deklarasi Konstanta dan Tipe Data sesuai Pseudocode
const int MAXSIZE = 4; // Kapasitas maksimal stack = 4
typedef char Infotype; // Tipe data elemen stack berupa karakter (char)
typedef int Index;     // Tipe data penunjuk posisi top

// 2. Deklarasi Tipe Stack
struct Stack {
    Infotype info[MAXSIZE + 1]; // Array 1..MAXSIZE (indeks 1 sampai 4)
    Index top;                  // Penunjuk elemen teratas
};

// Fungsi untuk membuat stack kosong awal
void createStack(Stack &S) {
    S.top = 0; // Top = 0 menandakan stack masih kosong
}

// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == 0;
}

// Fungsi untuk memeriksa apakah stack penuh
bool isFull(Stack S) {
    return S.top == MAXSIZE;
}

// Prosedur memasukkan elemen (Push)
void push(Stack &S, Infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh! Tidak dapat menambahkan '" << x << "'" << endl;
    } else {
        S.top = S.top + 1;  // Naikkan indeks top
        S.info[S.top] = x;  // Simpan karakter ke posisi top
        cout << "Berhasil Push: " << x << endl;
    }
}

// Prosedur mengeluarkan elemen (Pop)
void pop(Stack &S, Infotype &x) {
    if (isEmpty(S)) {
        cout << "Stack Kosong! Tidak ada elemen yang di-pop." << endl;
    } else {
        x = S.info[S.top];  // Ambil elemen di posisi top
        S.top = S.top - 1;  // Kurangi penunjuk top
        cout << "Berhasil Pop: " << x << endl;
    }
}

// Prosedur untuk menampilkan isi stack dari bawah ke atas
void printStack(Stack S) {
    if (isEmpty(S)) {
        cout << "Isi Stack: []" << endl;
    } else {
        cout << "Isi Stack: [ ";
        for (int i = 1; i <= S.top; i++) {
            cout << S.info[i] << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Stack S;
    Infotype elemenHapus;

    cout << "=== SIMULASI STACK (MAXSIZE = 4) ===" << endl << endl;

    // Inisialisasi stack kosong
    createStack(S);
    printStack(S);

    // Memasukkan 4 karakter
    push(S, 'A');
    push(S, 'B');
    push(S, 'C');
    push(S, 'D');
    printStack(S);

    // Menguji batas penuh (Overflow)
    push(S, 'E');

    cout << endl;

    // Mengeluarkan 2 elemen teratas
    pop(S, elemenHapus);
    pop(S, elemenHapus);
    printStack(S);

    return 0;
}
