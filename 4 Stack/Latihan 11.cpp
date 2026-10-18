#include <iostream> // Header untuk operasi input-output (cout, endl)
using namespace std; // Menghindari penulisan std:: secara berulang

// Tipe data elemen stack berupa karakter
typedef char Infotype;

// Struktur node (ElmtStack)
struct ElmtStack {
    Infotype info;    // Menyimpan nilai data karakter
    ElmtStack* next;  // Pointer Address ke node berikutnya
};

typedef ElmtStack* Address; // Pointer Address menunjuk ke ElmtStack

// Struktur utama Stack
struct Stack {
    Address top; // Pointer Top menunjuk ke node teratas 
};

// Prosedur pop untuk mengeluarkan node teratas dari Stack S dan menyimpannya ke P 
void pop(Stack &S, Address &P) {
    if ((S.top)->next == nullptr) { // Cek jika hanya ada 1 node di stack (S.Top->next == NIL) 
        P = S.top;                  // Simpan alamat node teratas ke P 
        S.top = nullptr;            // Set Top menjadi NIL karena stack menjadi kosong ]
    } else {                        // Jika ada lebih dari 1 node di stack 
        P = S.top;                  // Simpan alamat node teratas ke P 
        S.top = (S.top)->next;      // Pindahkan Top ke node di bawahnya (node next) 
        P->next = nullptr;          // Putuskan hubungan node P dari stack (P->next = NIL) 
    }
}

// Prosedur pendukung untuk menampilkan isi stack
void printStack(Stack S) {
    if (S.top == nullptr) {
        cout << "Stack Kosong (Top -> NIL)" << endl;
        return;
    }
    Address p = S.top;
    cout << "Top -> ";
    while (p != nullptr) {
        cout << "[" << p->info << "]";
        if (p->next != nullptr) cout << " -> ";
        else cout << " -> NIL";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Stack S;
    
    // Membuat kondisi awal stack dengan 2 elemen: 'A' di Top dan 'B' di bawahnya 
    Address nodeB = new ElmtStack{'B', nullptr}; // Node B (elemen paling bawah) 
    Address nodeA = new ElmtStack{'A', nodeB};   // Node A (elemen teratas) 
    S.top = nodeA;

    cout << "Kondisi Stack Sebelum POP:" << endl;
    printStack(S); // Output: Top -> [A] -> [B] -> NIL 

    cout << endl;

    Address P = nullptr; // Variabel penampung elemen yang di-pop 

    // Memanggil prosedur pop (mengeksekusi blok else) 
    pop(S, P);

    cout << "Kondisi Stack Setelah POP (Final State):" << endl;
    printStack(S); // Output: Top -> [B] -> NIL 

    cout << endl;
    cout << "Elemen P yang dikeluarkan: [" << P->info << "] -> NIL" << endl; // Node 'A' terlepas 

    return 0; // Program selesai
}
