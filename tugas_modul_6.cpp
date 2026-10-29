
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// Fungsi untuk mengubah kata menjadi huruf kecil
string hurufKecil(string kata) {
    for (char &c : kata) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return kata;
}

// Fungsi untuk menampilkan seluruh kata
void tampilkanKata(const vector<string>& kata) {
    for (const string& s : kata) {
        cout << s << " ";
    }
    cout << endl;
}

// Fungsi Insertion Sort
void insertionSort(vector<string>& kata) {
    int n = kata.size();

    for (int i = 1; i < n; i++) {
        string key = kata[i];
        int j = i - 1;

        cout << "\nLangkah " << i << endl;
        cout << "Kata yang akan disisipkan: " << key << endl;

        // Menggeser kata yang lebih besar ke kanan
        while (j >= 0 &&
               hurufKecil(kata[j]) > hurufKecil(key)) {
            kata[j + 1] = kata[j];

            cout << "Pergeseran: ";
            tampilkanKata(kata);

            j--;
        }

        // Menempatkan kata pada posisi yang tepat
        kata[j + 1] = key;

        cout << "Setelah penyisipan: ";
        tampilkanKata(kata);
    }
}

int main() {
    int n;

    cout << "=== INSERTION SORT KATA ===" << endl;
    cout << "Masukkan jumlah kata: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah kata harus lebih dari 0!" << endl;
        return 0;
    }

    vector<string> kata(n);

    cout << "Masukkan " << n << " kata:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> kata[i];
    }

    cout << "\nData sebelum diurutkan: ";
    tampilkanKata(kata);

    insertionSort(kata);

    cout << "\nHasil akhir pengurutan A-Z: ";
    tampilkanKata(kata);

    return 0;
}
