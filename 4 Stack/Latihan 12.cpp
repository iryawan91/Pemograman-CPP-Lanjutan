#include <iostream> // Header untuk fungsi input-output (cout, endl)
using namespace std; // Menghindari penulisan std:: secara berulang

// Tipe data elemen stack berupa karakter
typedef char Infotype;

// Struktur node (ElmtStack)
struct ElmtStack {
    Infotype info;    // Menyimpan nilai data karakter
    ElmtStack* next;  // Pointer ke node berikutnya
};

typedef ElmtStack* Address; // Pointer Address menunjuk ke ElmtStack

// Struktur utama Stack
struct Stack {
    Address top; // Pointer Top menunjuk ke node teratas 
};

// Fungsi peek untuk melihat nilai elemen teratas tanpa menghapusnya 
Infotype peek(Stack S) {
    if (S.top != nullptr) {     // Memastikan stack tidak dalam kondisi kosong
        return (S.top)->info;   // Mengembalikan nilai field info dari node teratas (S.Top)->info 
    }
    return '\0';                // Mengembalikan karakter null jika stack kosong
}

// Prosedur pendukung untuk menambahkan elemen ke stack
void push(Stack &S, Infotype x) {
    Address P = new ElmtStack;
    P->info = x;
    P->next = S.top;
    S.top = P;
}

int main() {
    Stack S;
    S.top = nullptr; // Inisialisasi stack kosong

    // Menambahkan elemen ke dalam stack
    push(S, 'B'); // Elemen pertama (bawah)
    push(S, 'A'); // Elemen kedua (teratas / Top)

    // Memanggil fungsi peek untuk melihat data teratas 
    Infotype topValue = peek(S);

    cout << "Nilai elemen pada Top Stack saat ini: " << topValue << endl;

    // Membuktikan bahwa fungsi peek tidak menghapus elemen dari stack
    cout << "Pengecekan ulang dengan peek: " << peek(S) << endl;

    return 0; // Program selesai
}
