#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Batas maksimum jumlah elemen
string nama[MAX_SIZE];
string warna[MAX_SIZE];
float berat[MAX_SIZE];
int harga[MAX_SIZE];
string rasa[MAX_SIZE];
int currentSize = 0; // Jumlah elemen saat ini

void buatElemen(string, string, float, int, string);
void masukanElemenKeAwal(string, string, float, int, string);
void masukanElemenKeAkhir(string, string, float, int, string);
void rubahDataElemenPertama(string, string, float, int, string);
void rubahDataElemenTerakhir(string, string, float, int, string);
void hapusElemenPertama();
void hapusElemenTerakhir();
void cetakSingleArray();
void cetakSeluruhAtributElemen();

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
} 

void buatElemen(string a, string b, float c, int d, string e) {
    if (currentSize < MAX_SIZE) {
        nama[currentSize] = a;
        warna[currentSize] = b;
        berat[currentSize] = c;
        harga[currentSize] = d;
        rasa[currentSize] = e;
        currentSize++;
    }
}

void masukanElemenKeAwal(string a, string b, float c, int d, string e) {
    if (currentSize < MAX_SIZE) {
        for (int i = currentSize; i > 0; i--) {
            nama[i] = nama[i - 1];
            warna[i] = warna[i - 1];
            berat[i] = berat[i - 1];
            harga[i] = harga[i - 1];
            rasa[i] = rasa[i - 1];
        }
        nama[0] = a;
        warna[0] = b;
        berat[0] = c;
        harga[0] = d;
        rasa[0] = e;
        currentSize++;
    }
}

void masukanElemenKeAkhir(string a, string b, float c, int d, string e) {
    if (currentSize < MAX_SIZE) {
        nama[currentSize] = a;
        warna[currentSize] = b;
        berat[currentSize] = c;
        harga[currentSize] = d;
        rasa[currentSize] = e;
        currentSize++;
    }
}

void rubahDataElemenPertama(string a, string b, float c, int d, string e) {
    if (currentSize > 0) {
        nama[0] = a;
        warna[0] = b;
        berat[0] = c;
        harga[0] = d;
        rasa[0] = e;
    }
}

void rubahDataElemenTerakhir(string a, string b, float c, int d, string e) {
    if (currentSize > 0) {
        int lastIndex = currentSize - 1;
        nama[lastIndex] = a;
        warna[lastIndex] = b;
        berat[lastIndex] = c;
        harga[lastIndex] = d;
        rasa[lastIndex] = e;
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
