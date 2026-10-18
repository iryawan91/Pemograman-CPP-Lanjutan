#include <iostream> // Header untuk fungsi input-output (cout, endl)
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
    Address top; // Pointer Top untuk menunjuk elemen teratas
};

// Fungsi createStack untuk membuat dan mengembalikan stack kosong
Stack createStack() {
    Stack S;        // Deklarasi variabel S bertipe Stack
    S.top = nullptr; // Set S.top ke NIL (nullptr) penanda stack kosong
    return S;       // Mengembalikan objek stack S yang baru dibuat
}

int main() {
    // Memanggil fungsi createStack untuk membuat stack baru
    Stack S = createStack();

    // Memeriksa apakah stack berhasil diinisialisasi sebagai stack kosong
    if (S.top == nullptr) {
        cout << "Stack S berhasil dibuat dan saat ini KOSONG (S.top -> NIL)" << endl;
    } else {
        cout << "Stack berisi elemen" << endl;
    }

    return 0; // Program selesai
}
