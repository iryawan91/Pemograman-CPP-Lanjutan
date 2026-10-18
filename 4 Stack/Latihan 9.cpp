#include <iostream> // Header untuk operasi input-output (cout, endl)
using namespace std; // Menghindari penulisan std:: secara berulang

// Tipe data elemen stack berupa karakter
typedef char Infotype;

// Struktur node (elemen stack)
struct ElmtStack {
    Infotype info;    // Menyimpan data
    ElmtStack* next;  // Pointer ke node berikutnya
};

typedef ElmtStack* Address; // Pointer Address menunjuk ke ElmtStack

// Struktur utama Stack
struct Stack {
    Address top; // Pointer Top menunjuk elemen teratas
};

// Fungsi isEmpty untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == nullptr; // Mengembalikan true jika S.top bernilai NIL (nullptr)
}

int main() {
    Stack S1, S2; // Deklarasi stack S1 dan S2

    // Set S1 sebagai Stack Kosong (S1.top -> NIL)
    S1.top = nullptr;

    // Set S2 sebagai Stack Berisi Elemen (S2.top -> Node 'V')
    Address nodeV = new ElmtStack;
    nodeV->info = 'V';
    nodeV->next = nullptr;
    S2.top = nodeV;

    // Menguji fungsi isEmpty pada S1
    cout << "Pengecekan S1 (Kosong): " << (isEmpty(S1) ? "True (Kosong)" : "False (Berisi)") << endl;

    // Menguji fungsi isEmpty pada S2
    cout << "Pengecekan S2 (Berisi) : " << (isEmpty(S2) ? "True (Kosong)" : "False (Berisi)") << endl;

    return 0; // Program selesai
}
