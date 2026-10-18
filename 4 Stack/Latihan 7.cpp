#include <iostream> // Header untuk operasi input-output (cout, endl)
using namespace std; // Menghindari penulisan std:: pada setiap fungsi

// 1. Tipe Data Infotype berupa karakter (char)
typedef char Infotype; // Tipe data nilai elemen stack

// 2. Deklarasi Struktur Node (ElmtStack)
struct ElmtStack {
    Infotype info;     // Menyimpan data berjenis char
    ElmtStack* next;   // Pointer Address yang menunjuk ke elemen berikutnya
};

typedef ElmtStack* Address; // Pointer Address menunjuk ke ElmtStack

// 3. Deklarasi Tipe Stack
struct Stack {
    Address top; // Stack memiliki pointer Top bertipe Address
};

// Prosedur untuk menginisialisasi Stack Kosong
void createStack(Stack &S) {
    S.top = nullptr; // Mengatur Top bernilai NULL (seperti pada S1)
}

// Fungsi untuk membuat node baru di memori
Address alokasi(Infotype x) {
    Address P = new ElmtStack; // Alokasi memori dinamis
    if (P != nullptr) {
        P->info = x;            // Isi data dengan nilai x
        P->next = nullptr;      // Set pointer next ke NULL
    }
    return P;
}

// Prosedur Push (menambahkan elemen ke stack)
void push(Stack &S, Infotype x) {
    Address P = alokasi(x); // Buat node baru
    if (P != nullptr) {
        P->next = S.top;    // Sambungkan node baru ke node lama
        S.top = P;          // Pindahkan Top ke node baru
    }
}

// Prosedur untuk menampilkan kondisi Stack
void printStack(Stack S) {
    if (S.top == nullptr) { // Kondisi Stack S1 (Kosong)
        cout << "Stack Kosong (Top -> NULL)" << endl;
    } else {                // Kondisi Stack S2 (Berisi elemen)
        cout << "Top -> ";
        Address P = S.top;
        while (P != nullptr) {
            cout << "[" << P->info << "]";
            if (P->next != nullptr) cout << " -> ";
            else cout << " -> NULL";
            P = P->next;
        }
        cout << endl;
    }
}

int main() {
    Stack S1, S2; // Deklarasi dua buah stack: S1 dan S2

    cout << "=== SIMULASI LINKED LIST STACK ===" << endl << endl;

    // Menyimulasikan kondisi S1 (Stack Kosong)
    createStack(S1);
    cout << "Kondisi Stack S1: ";
    printStack(S1); // Output: Stack Kosong

    // Menyimulasikan kondisi S2 (Berisi 1 elemen 'V')
    createStack(S2);
    push(S2, 'V');
    cout << "Kondisi Stack S2: ";
    printStack(S2); // Output: Top -> [V] -> NULL

    return 0; // Program selesai
}
