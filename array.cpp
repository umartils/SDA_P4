#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Batas maksimum jumlah elemen
string nama[MAX_SIZE];
string warna[MAX_SIZE];
float berat[MAX_SIZE];
int harga[MAX_SIZE];
string rasa[MAX_SIZE];
int currentSize = 0; // Jumlah elemen saat ini

/*
 * Prototipe Fungsi
 */
void buatElemen(string, string, float, int, string);
void masukanElemenKeAwal(string, string, float, int, string);
void masukanElemenKeAkhir(string, string, float, int, string);
void rubahDataElemenPertama(string, string, float, int, string);
void rubahDataElemenTerakhir(string, string, float, int, string);
void hapusElemenPertama();
void hapusElemenTerakhir();
void cetakSingleArray();
void cetakSeluruhAtributElemen();

/*
 * Fungsi Utama
 */
int main() {
    /* Membuat elemen pertama */
    cout << endl << "01. Membuat Elemen Pertama:" << endl;
    buatElemen("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleArray(); // Menampilkan elemen

    /* Menambahkan elemen di awal */
    cout << endl << "02. Menambahkan elemen di awal:" << endl;
    masukanElemenKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
    cetakSingleArray(); // Menampilkan elemen

    /* Menambahkan elemen di akhir */
    cout << endl << "03. Menambahkan elemen di akhir:" << endl;
    masukanElemenKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleArray(); // Menampilkan elemen

    /* Menambahkan elemen di awal lagi */
    cout << endl << "04. Menambahkan elemen di awal lagi:" << endl;
    masukanElemenKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleArray(); // Menampilkan elemen

    /* Menghapus elemen di awal */
    cout << endl << "05. Menghapus elemen di awal:" << endl;
    hapusElemenPertama();
    cetakSingleArray();

    /* Menghapus elemen di akhir */
    cout << endl << "06. Menghapus elemen di akhir:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();

    /* Menghapus elemen di akhir lagi */
    cout << endl << "07. Menghapus elemen di akhir lagi:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();

    return 0;
} // Akhir dari main

/*
 * Fungsi
 */

void buatElemen(string n, string w, float b, int h, string r) {
    if (currentSize < MAX_SIZE) {
        nama[currentSize] = n;
        warna[currentSize] = w;
        berat[currentSize] = b;
        harga[currentSize] = h;
        rasa[currentSize] = r;
        currentSize++;
    }
}

void masukanElemenKeAwal(string n, string w, float b, int h, string r) {
    if (currentSize < MAX_SIZE) {
        for (int i = currentSize; i > 0; i--) {
            nama[i] = nama[i - 1];
            warna[i] = warna[i - 1];
            berat[i] = berat[i - 1];
            harga[i] = harga[i - 1];
            rasa[i] = rasa[i - 1];
        }
        nama[0] = n;
        warna[0] = w;
        berat[0] = b;
        harga[0] = h;
        rasa[0] = r;
        currentSize++;
    }
}

void masukanElemenKeAkhir(string n, string w, float b, int h, string r) {
    if (currentSize < MAX_SIZE) {
        nama[currentSize] = n;
        warna[currentSize] = w;
        berat[currentSize] = b;
        harga[currentSize] = h;
        rasa[currentSize] = r;
        currentSize++;
    }
}

void rubahDataElemenPertama(string n, string w, float b, int h, string r) {
    if (currentSize > 0) {
        nama[0] = n;
        warna[0] = w;
        berat[0] = b;
        harga[0] = h;
        rasa[0] = r;
    }
}

void rubahDataElemenTerakhir(string n, string w, float b, int h, string r) {
    if (currentSize > 0) {
        int lastIndex = currentSize - 1;
        nama[lastIndex] = n;
        warna[lastIndex] = w;
        berat[lastIndex] = b;
        harga[lastIndex] = h;
        rasa[lastIndex] = r;
    }
}

void hapusElemenPertama() {
    if (currentSize > 0) {
        for (int i = 0; i < currentSize - 1; i++) {
            nama[i] = nama[i + 1];
            warna[i] = warna[i + 1];
            berat[i] = berat[i + 1];
            harga[i] = harga[i + 1];
            rasa[i] = rasa[i + 1];
        }
        currentSize--;
    }
}

void hapusElemenTerakhir() {
    if (currentSize > 0) {
        currentSize--;
    }
}

void cetakSingleArray() {
    for (int i = 0; i < currentSize; i++) {
        cout << nama[i] << " >> ";
    }
    cout << "!!\n";
}
