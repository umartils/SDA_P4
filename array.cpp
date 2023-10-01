
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// deklarasi array
const int MAX_SIZE = 100; // Batas maksimum jumlah elemen
string nama[MAX_SIZE];
string warna[MAX_SIZE];
float berat[MAX_SIZE];
int harga[MAX_SIZE];
string rasa[MAX_SIZE];
int currentSize = 0; // Jumlah elemen saat ini

// Prototype fungsi array
void buatElemen(string, string, float, int, string);
void masukanElemenKeAwal(string, string, float, int, string);
void masukanElemenKeAkhir(string, string, float, int, string);
void rubahDataElemenPertama(string, string, float, int, string);
void rubahDataElemenTerakhir(string, string, float, int, string);
void hapusElemenPertama();
void hapusElemenTerakhir();
void cetakSingleArray();
void cetakSeluruhAtributElemen();
void cetakArray();
void waktuArray();

int main()
{
    cout << "\nHasil Array\n";
    cout << "====================================================";
    waktuArray();
    return 0;
}
// fungsi array
void buatElemen(string a, string b, float c, int d, string e)
{
    if (currentSize < MAX_SIZE)
    {
        nama[currentSize] = a;
        warna[currentSize] = b;
        berat[currentSize] = c;
        harga[currentSize] = d;
        rasa[currentSize] = e;
        currentSize++;
    }
}

void masukanElemenKeAwal(string a, string b, float c, int d, string e)
{
    if (currentSize < MAX_SIZE)
    {
        for (int i = currentSize; i > 0; i--)
        {
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

void masukanElemenKeAkhir(string a, string b, float c, int d, string e)
{
    if (currentSize < MAX_SIZE)
    {
        nama[currentSize] = a;
        warna[currentSize] = b;
        berat[currentSize] = c;
        harga[currentSize] = d;
        rasa[currentSize] = e;
        currentSize++;
    }
}

void rubahDataElemenPertama(string a, string b, float c, int d, string e)
{
    if (currentSize > 0)
    {
        nama[0] = a;
        warna[0] = b;
        berat[0] = c;
        harga[0] = d;
        rasa[0] = e;
    }
}

void rubahDataElemenTerakhir(string a, string b, float c, int d, string e)
{
    if (currentSize > 0)
    {
        int lastIndex = currentSize - 1;
        nama[lastIndex] = a;
        warna[lastIndex] = b;
        berat[lastIndex] = c;
        harga[lastIndex] = d;
        rasa[lastIndex] = e;
    }
}

void hapusElemenPertama()
{
    if (currentSize > 0)
    {
        for (int i = 0; i < currentSize - 1; i++)
        {
            nama[i] = nama[i + 1];
            warna[i] = warna[i + 1];
            berat[i] = berat[i + 1];
            harga[i] = harga[i + 1];
            rasa[i] = rasa[i + 1];
        }
        currentSize--;
    }
}

void hapusElemenTerakhir()
{
    if (currentSize > 0)
    {
        currentSize--;
    }
}

void cetakSingleArray()
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << nama[i] << " >> ";
    }
    cout << "!!\n";
}

void cetakSeluruhAtributElemen()
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << "Elemen ke-" << i + 1 << ":\n";
        cout << "Nama: " << nama[i] << endl;
        cout << "Warna: " << warna[i] << endl;
        cout << "Berat: " << berat[i] << endl;
        cout << "Harga: " << harga[i] << endl;
        cout << "Rasa: " << rasa[i] << endl
             << endl;
    }
}

void cetakArray()
{
    cout << endl
         << "01. Membuat Elemen Pertama:" << endl;
    buatElemen("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleArray();

    cout << endl
         << "02. Menambahkan elemen di awal:" << endl;
    masukanElemenKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
    cetakSingleArray();

    cout << endl
         << "03. Menambahkan elemen di akhir:" << endl;
    masukanElemenKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleArray();

    cout << endl
         << "04. Menambahkan elemen di awal lagi:" << endl;
    masukanElemenKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleArray();

    cout << endl
         << "05. Menghapus elemen di awal:" << endl;
    hapusElemenPertama();
    cetakSingleArray();

    cout << endl
         << "06. Menghapus elemen di akhir:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();

    cout << endl
         << "07. Menghapus elemen di akhir lagi:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();

    cout << endl
         << "08. Menambahkan elemen pada posisi awal:" << endl;
    masukanElemenKeAwal("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleArray();

    cout << endl
         << "09. Merubah elemen pada posisi awal:" << endl;
    rubahDataElemenPertama("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleArray();

    cout << endl
         << "10. Merubah elemen pada posisi akhir:" << endl;
    rubahDataElemenTerakhir("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleArray();

    cout << endl
         << "11. Mencetak seluruh atribut pada elemen:" << endl;
    cetakSeluruhAtributElemen();
}

void waktuArray()
{
    auto start_time_B = chrono::high_resolution_clock::now();
    cetakArray();
    auto end_time_B = chrono::high_resolution_clock::now();
    auto duration_B = chrono::duration_cast<chrono::microseconds>(end_time_B - start_time_B);

    cout << "\nWaktu eksekusi Array: " << duration_B.count() << " ms" << endl;
}
