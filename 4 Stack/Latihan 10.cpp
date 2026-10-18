#include <iostream> // Header untuk fungsi input-output (cout, endl)
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
    Address top; // Pointer Top untuk menunjuk node teratas 
};

// Prosedur push untuk memasukkan node P ke dalam Stack S 
void push(Stack &S, Address P) {
    if (S.top == nullptr) { // Cek jika Stack S masih kosong (S.Top == NIL) 
        S.top = P;          // Pointer Top langsung menunjuk ke node P 
    } else {                // Jika Stack S sudah berisi elemen 
        P->next = S.top;    // Hubungkan pointer next dari P ke node teratas lama 
        S.top = P;          // Pindahkan pointer Top agar menunjuk ke node baru P 
    }
}

// Prosedur pendukung untuk menampilkan isi stack
void printStack(Stack S) {
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
    S.top = nullptr; // Inisialisasi stack awal dalam keadaan kosong

    // 1. Alokasi node pertama berisi 'A'
    Address P1 = new ElmtStack;
    P1->info = 'A';
    P1->next = nullptr;

    // Memasukkan node 'A' ke stack (Kondisi if: S.Top == NIL) 
    push(S, P1);
    cout << "Kondisi awal stack setelah push 'A':" << endl;
    printStack(S);

    cout << endl;

    // 2. Alokasi node kedua berisi 'W' (seperti pada ilustrasi gambar) 
    Address P2 = new ElmtStack;
    P2->info = 'W';
    P2->next = nullptr;

    // Memasukkan node 'W' ke stack (Kondisi else: P->next = S.Top & S.Top = P) 
    push(S, P2);
    cout << "Kondisi stack setelah push 'W' (Final State):" << endl;
    printStack(S);

    return 0; // Program selesai
}
