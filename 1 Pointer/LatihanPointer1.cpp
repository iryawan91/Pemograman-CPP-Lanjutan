#include <iostream>
using namespace std;

int main() {
	// Deklarasi variabel 
    char a = 'u';    
    int j = 15;         
    char arr[6] = {'t', 'u', 'm', 'b', 'u', 'h'}; 

    // Deklarasi variabel pointer
    char *p_char;            
    int *p_int;          

    cout << "=== BUKTI OPERASI POINTER ===" << endl << endl;

    // Langkah 1: p_char <- &a
    p_char = &a;               
    cout << "output( *p_char ) : " << *p_char << endl;

    // Langkah 2: p_char <- &arr[3
    p_char = &arr[3];          
    cout << "output( *p_char ) : " << *p_char << endl; 

    // Langkah 3: a <- *p_char
    a = *p_char;               
    cout << "output( a )        : " << (void*)&a << endl << endl; 
    
    


    return 0;
}
