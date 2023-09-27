#include <iostream>
#include <time.h>
using namespace std;

struct buah {
    string nama;
    string warna;
    float berat;
    int harga;
    string rasa;
};

const int MAX_SIZE = 100; // Define the maximum size of the array
buah listBuah[MAX_SIZE];   // Array to store buah elements
int currentSize = 0;       // Current number of elements in the array

/*
 * Prototypes of functions
 */
void buatSingleArray(string, string, float, int, string);
void masukanElemenKeAwal(string, string, float, int, string);
void masukanElemenKeAkhir(string, string, float, int, string);
void rubahDataElemenPertama(string, string, float, int, string);
void rubahDataElemenTerakhir(string, string, float, int, string);
void hapusElemenPertama();
void hapusElemenTerakhir();
void cetakSingleArray();
void cetakSeluruhAtributElemen();
void cetakArray();

/*
 * Main function
 */
int main() {
    cetakArray();

    return 0;
} // end of main

/*
 * Functions
 */

void buatSingleArray(string nama, string warna, float berat, int harga, string rasa) {
    if (currentSize < MAX_SIZE) {
        listBuah[currentSize].nama = nama;
        listBuah[currentSize].warna = warna;
        listBuah[currentSize].berat = berat;
        listBuah[currentSize].harga = harga;
        listBuah[currentSize].rasa = rasa;
        currentSize++;
    }
}

void masukanElemenKeAwal(string nama, string warna, float berat, int harga, string rasa) {
    if (currentSize < MAX_SIZE) {
        for (int i = currentSize; i > 0; i--) {
            listBuah[i] = listBuah[i - 1];
        }
        listBuah[0].nama = nama;
        listBuah[0].warna = warna;
        listBuah[0].berat = berat;
        listBuah[0].harga = harga;
        listBuah[0].rasa = rasa;
        currentSize++;
    }
}

void masukanElemenKeAkhir(string nama, string warna, float berat, int harga, string rasa) {
    if (currentSize < MAX_SIZE) {
        listBuah[currentSize].nama = nama;
        listBuah[currentSize].warna = warna;
        listBuah[currentSize].berat = berat;
        listBuah[currentSize].harga = harga;
        listBuah[currentSize].rasa = rasa;
        currentSize++;
    }
}

void rubahDataElemenPertama(string nama, string warna, float berat, int harga, string rasa) {
    if (currentSize > 0) {
        listBuah[0].nama = nama;
        listBuah[0].warna = warna;
        listBuah[0].berat = berat;
        listBuah[0].harga = harga;
        listBuah[0].rasa = rasa;
    }
}

void rubahDataElemenTerakhir(string nama, string warna, float berat, int harga, string rasa) {
    if (currentSize > 0) {
        listBuah[currentSize - 1].nama = nama;
        listBuah[currentSize - 1].warna = warna;
        listBuah[currentSize - 1].berat = berat;
        listBuah[currentSize - 1].harga = harga;
        listBuah[currentSize - 1].rasa = rasa;
    }
}

void hapusElemenPertama() {
    if (currentSize > 0) {
        for (int i = 0; i < currentSize - 1; i++) {
            listBuah[i] = listBuah[i + 1];
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
        cout << listBuah[i].nama << " >> ";
    }
    cout << "!!\n";
}
void cetakArray(){
    cout <<"01. Creating the First Element:" << endl;
    buatSingleArray("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleArray(); // Display the elements

    /* Add an element at the beginning */
    cout <<"02. Adding an Element at the Beginning:" << endl;
    masukanElemenKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
    cetakSingleArray(); // Display the elements

    /* Add an element at the end */
    cout <<"03. Adding an Element at the End:" << endl;
    masukanElemenKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleArray(); // Display the elements

    /* Add an element at the beginning again */
    cout <<"04. Adding an Element at the Beginning Again:" << endl;
    masukanElemenKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleArray(); // Display the elements

    /* Remove the first element */
    cout <<"05. Removing the First Element:" << endl;
    hapusElemenPertama();
    cetakSingleArray();

    /* Add an element at the end */
    cout <<"03. Adding an Element at the End:" << endl;
    masukanElemenKeAkhir("Khuldi", "Merah", 2.1, 13000, "Manis");
    cetakSingleArray(); // Display the elements

    /* Remove the last element */
    cout <<"06. Removing the Last Element:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();

    /* Remove the last element again */
    cout <<"07. Removing the Last Element Again:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();
}
