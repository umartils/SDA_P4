
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// deklarasi struct 
struct buah{
 string nama;
 string warna;
 float berat;
 int harga;
 string rasa;
 // pointer untuk menghubungkan node
 buah *next;
}; buah *head, *tail, *nodeSekarang, *nodeBaru, *temporaryNode;

// deklarasi array
const int MAX_SIZE = 100; // Batas maksimum jumlah elemen
string nama[MAX_SIZE];
string warna[MAX_SIZE];
float berat[MAX_SIZE];
int harga[MAX_SIZE];
string rasa[MAX_SIZE];
int currentSize = 0; // Jumlah elemen saat ini

// Prototype fungsi linked list
void buatSingleLinkedList(string, string, float, int, string);
void masukanNodeKeAwal(string, string, float, int, string);
void masukanNodeKeAkhir(string, string, float, int, string);
void rubahDataNodePertama(string, string, float, int, string);
void rubahDataNodeTerakhir(string, string, float, int, string);
void hapusNodePertama();
void hapusNodeTerakhir();
void cetakSingleLinkedList();
void cetakSeluruhAtributNode();
void cetakLinkedList();
void waktuLinkedList();

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
void ukurMemoriLinkedList();
void ukurMemoriArray();

int main(){
 cout << "\nHasil Linked List\n";
 cout << "====================================================";
 waktuLinkedList();
 cout << "====================================================";
 cout << "\n\nHasil Array\n";
 cout << "====================================================";
 waktuArray();
 return 0;
} 

void buatSingleLinkedList(string nama, string warna, float berat, int harga, string rasa){
 // membuat node pertama kali
 head = new buah();
 head->nama = nama;
 head->warna = warna;
 head->berat = berat;
 head->harga = harga;
 head->rasa = rasa;
 // maka node tersebut akan jadi head dan tail
 head->next = NULL;
 tail = head;
}
// fungsi membuat node di awal
void masukanNodeKeAwal(string nama, string warna, float berat, int harga, string rasa){
 // buat node baru
 nodeBaru = new buah();
 nodeBaru->nama = nama;
 nodeBaru->warna = warna;
 nodeBaru->berat = berat;
 nodeBaru->harga = harga;
 nodeBaru->rasa = rasa;
 // node baru di awal menunjuk ke head
 nodeBaru->next = head;
 // tukar head menjadi yang node baru
 // maka sekarang head adalah node baru
 head = nodeBaru;
}
// fungsi membuat node di akhir
void masukanNodeKeAkhir(string nama, string warna, float berat, int harga, string rasa){
 // membuat node baru
 nodeBaru = new buah();
 nodeBaru->nama = nama;
nodeBaru->warna = warna;
 nodeBaru->berat = berat;
 nodeBaru->harga = harga;
 nodeBaru->rasa = rasa;
 // node di akhir harus menunjuk null
 nodeBaru->next = NULL;
 // node yang sebelumnya tail harus ditunjuk ke node baru
 tail->next = nodeBaru;
 // maka sekarang tail adalah node baru
 tail = nodeBaru;
}
// fungsi rubah data node pertama
void rubahDataNodePertama(string nama, string warna, float berat, int harga, string rasa){
 head->nama = nama;
 head->warna = warna;
 head->berat = berat;
 head->harga = harga;
 head->rasa = rasa;
}
// fungsi rubah data node terakhir
void rubahDataNodeTerakhir(string nama, string warna, float berat, int harga, string rasa){
 // ubah data node terakhir
 tail->nama = nama;
 tail->warna = warna;
 tail->berat = berat;
 tail->harga = harga;
 tail->rasa = rasa;
}
// fungsi hapus node pertama
void hapusNodePertama(){
 // simpan node head ke node sementara
 temporaryNode = head;
 // node head diganti dengan node selanjutnya
 head = head->next;
 delete temporaryNode;
}
// fungsi hapus node terakhir
void hapusNodeTerakhir(){
 // simpan node tail ke node sementara
 temporaryNode = tail;
 // mencari nodetail
 // pencarian dimulai dari head
 nodeSekarang = head;
 while (nodeSekarang->next != NULL){
 // jika node sekarang itu next nodenya adalah tail
 // eksekusi
 if(nodeSekarang->next == tail){
 // node sekarang jadi tail
// dengan membuah next dari node sekarang menjadi null bukan ke node lain
 nodeSekarang->next = NULL;
 // maka tail dirubah node sekarang
 tail = nodeSekarang;
 } else {
 // jika tidak maka current Node diganti dengan node selanjutnya
 nodeSekarang = nodeSekarang->next;
 }
 }
 delete temporaryNode;
}
// fungsi cetak linked list
void cetakSingleLinkedList(){
 // dimulai dari node head
 nodeSekarang = head;
 while (nodeSekarang != NULL){
 cout << nodeSekarang->nama << " >> ";
 // geser ke node selanjutnya
 nodeSekarang = nodeSekarang->next;
 } cout << "!!\n";
}
// fungsi cetak seluruh data node linked list
void cetakSeluruhAtributNode(){
 // dimulai dari node head
 nodeSekarang = head;
 while (nodeSekarang != NULL){
 cout << "nama: " << nodeSekarang->nama << endl;
 cout << "warna: " << nodeSekarang->warna << endl;
 cout << "berat: " << nodeSekarang->berat << endl;
 cout << "harga: " << nodeSekarang->harga << endl;
 cout << "rasa: " << nodeSekarang->rasa << endl;
 cout << endl;
 nodeSekarang = nodeSekarang->next;
 }
}

void cetakLinkedList(){


 cout << endl << "01. Membuat Node Pertama:" << endl;
 buatSingleLinkedList("Mangga", "Jingga", 1.1, 10000, "Manis");
 cetakSingleLinkedList(); // menampilkan node
 
 cout << endl << "02. Menambahkan node pada posisi awal:" << endl;
 masukanNodeKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
 cetakSingleLinkedList(); // menampilkan node

 cout << endl << "03. Menambahkan node pada posisi akhir:" << endl;
 masukanNodeKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
 cetakSingleLinkedList(); // menampilkan node
 
 cout << endl << "04. Menambahkan node pada posisi awal lagi:" << endl;
 masukanNodeKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
 cetakSingleLinkedList(); // menampilkan node

 cout << endl << "05. menghapus node pada posisi awal:" << endl;
 hapusNodePertama();
 cetakSingleLinkedList();
 
 cout << endl << "06. menghapus node pada posisi akhir:" << endl;
 hapusNodeTerakhir();
 cetakSingleLinkedList();
 
 cout << endl << "07. menghapus node pada posisi akhir:" << endl;
 hapusNodeTerakhir();
 cetakSingleLinkedList();

}

void waktuLinkedList(){
    auto start_time = chrono::high_resolution_clock::now();
    cetakLinkedList();
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "\nWaktu eksekusi linked list: " << duration.count() << " mikrodetik" << endl;
}


// fungsi array
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

void cetakArray(){
    cout << endl << "01. Membuat Elemen Pertama:" << endl;
    buatElemen("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleArray(); 
     
    cout << endl << "02. Menambahkan elemen di awal:" << endl;
    masukanElemenKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
    cetakSingleArray(); 
    
    cout << endl << "03. Menambahkan elemen di akhir:" << endl;
    masukanElemenKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleArray(); 
    
    cout << endl << "04. Menambahkan elemen di awal lagi:" << endl;
    masukanElemenKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleArray(); 
    
    cout << endl << "05. Menghapus elemen di awal:" << endl;
    hapusElemenPertama();
    cetakSingleArray();
     
    cout << endl << "06. Menghapus elemen di akhir:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();
    
    cout << endl << "07. Menghapus elemen di akhir lagi:" << endl;
    hapusElemenTerakhir();
    cetakSingleArray();

}

void waktuArray(){
    auto start_time = chrono::high_resolution_clock::now();
    cetakArray();
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "\nWaktu eksekusi linked list: " << duration.count() << " mikrodetik" << endl;
}
