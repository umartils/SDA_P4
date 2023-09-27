#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct buah {
    string nama;
    string warna;
    float berat;
    int harga;
    string rasa;
}; 
struct buah1 {
    string nama1;
    string warna1;
    float berat1;
    int harga1;
    string rasa1;
    buah1 *next;
}; buah1 *head, *tail, *nodeSekarang, *nodeBaru, *temporaryNode;

void buatSingleLinkedList(string, string, float, int, string);
void masukanNodeKeAwal(string, string, float, int, string);
void masukanNodeKeAkhir(string, string, float, int, string);
void rubahDataNodePertama(string, string, float, int, string);
void rubahDataNodeTerakhir(string, string, float, int, string);
void hapusNodePertama();
void hapusNodeTerakhir();
void cetakSingleLinkedList();
void cetakSeluruhAtributNode();
void cetakLinked();
void waktuLinked();

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
void waktuArray();

/*
 * Main function
 */
int main() {
    
    /* Create the first element */
    cout << "Hasil Array\n";
    cout <<"=================================================\n";
    waktuArray();
    cout <<"=================================================\n";
    cout << "\nHasil Linked\n";
    cout <<"=================================================\n";
    waktuLinked();
    cout <<"=================================================\n";
    

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
void waktuArray(){
    auto start_time = chrono::high_resolution_clock::now();
    cetakArray();
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Waktu eksekusi linked list: " << duration.count() << " mikrodetik" << endl;
}

void buatSingleLinkedList(string nama, string warna, float berat, int harga, string rasa){
 // membuat node pertama kali
 head = new buah1();
 head->nama1 = nama;
 head->warna1 = warna;
 head->berat1 = berat;
 head->harga1 = harga;
 head->rasa1 = rasa;
 // maka node tersebut akan jadi head dan tail
 head->next = NULL;
 tail = head;
}
// fungsi membuat node di awal
void masukanNodeKeAwal(string nama, string warna, float berat, int harga, string rasa){
 // buat node baru
 nodeBaru = new buah1();
 nodeBaru->nama1 = nama;
 nodeBaru->warna1 = warna;
 nodeBaru->berat1 = berat;
 nodeBaru->harga1 = harga;
 nodeBaru->rasa1 = rasa;
 // node baru di awal menunjuk ke head
 nodeBaru->next = head;
 // tukar head menjadi yang node baru
 // maka sekarang head adalah node baru
 head = nodeBaru;
}
// fungsi membuat node di akhir
void masukanNodeKeAkhir(string nama, string warna, float berat, int harga, string rasa){
 // membuat node baru
 nodeBaru = new buah1();
 nodeBaru->nama1 = nama;
 nodeBaru->warna1 = warna;
 nodeBaru->berat1 = berat;
 nodeBaru->harga1 = harga;
 nodeBaru->rasa1 = rasa;
 // node di akhir harus menunjuk null
 nodeBaru->next = NULL;
 // node yang sebelumnya tail harus ditunjuk ke node baru
 tail->next = nodeBaru;
 // maka sekarang tail adalah node baru
 tail = nodeBaru;
}
// fungsi rubah data node pertama
void rubahDataNodePertama(string nama, string warna, float berat, int harga, string rasa){
 head->nama1 = nama;
 head->warna1 = warna;
 head->berat1 = berat;
 head->harga1 = harga;
 head->rasa1 = rasa;
}
// fungsi rubah data node terakhir
void rubahDataNodeTerakhir(string nama, string warna, float berat, int harga, string rasa){
 // ubah data node terakhir
 tail->nama1 = nama;
 tail->warna1 = warna;
 tail->berat1 = berat;
 tail->harga1 = harga;
 tail->rasa1 = rasa;
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
 cout << nodeSekarang->nama1 << " >> ";
 // geser ke node selanjutnya
 nodeSekarang = nodeSekarang->next;
 } cout << "!!n";
}
// fungsi cetak seluruh data node linked list
void cetakSeluruhAtributNode(){
 // dimulai dari node head
 nodeSekarang = head;
 while (nodeSekarang != NULL){
 cout << "nama: " << nodeSekarang->nama1 << endl;
 cout << "warna: " << nodeSekarang->warna1 << endl;
 cout << "berat: " << nodeSekarang->berat1 << endl;
 cout << "harga: " << nodeSekarang->harga1 << endl;
 cout << "rasa: " << nodeSekarang->rasa1 << endl;
 cout << endl;
 nodeSekarang = nodeSekarang->next;
 }
}
void cetakLinked(){
    cout <<"01. Membuat Node Pertama:" << endl;
 buatSingleLinkedList("Mangga", "Jingga", 1.1, 10000, "Manis");
 cetakSingleLinkedList(); // menampilkan node
 /* menambahkan node di awal*/
 cout <<"\n02. Menambahkan node pada posisi awal:" << endl;
 masukanNodeKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
 cetakSingleLinkedList(); // menampilkan node
 /* menambahkan node di akhir*/
 cout <<"\n03. Menambahkan node pada posisi akhir:" << endl;
 masukanNodeKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
 cetakSingleLinkedList(); // menampilkan node
 /* menambahkan node di awal*/
 cout <<"\n04. Menambahkan node pada posisi awal lagi:" << endl;
 masukanNodeKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
 cetakSingleLinkedList(); // menampilkan node
 /* menghapus node di awal*/
 cout <<"\n05. menghapus node pada posisi awal:" << endl;
hapusNodePertama();
 cetakSingleLinkedList();
 /* menghapus node di akhir*/
 cout <<"\n06. menghapus node pada posisi akhir:" << endl;
 hapusNodeTerakhir();
 cetakSingleLinkedList();
 /* menghapus node di akhir*/
 cout <<"\n07. menghapus node pada posisi akhir:" << endl;
 hapusNodeTerakhir();
 cetakSingleLinkedList();
}
void waktuLinked(){
    auto start_time = chrono::high_resolution_clock::now();
    cetakLinked();
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "\nWaktu eksekusi linked list: " << duration.count() << " mikrodetik" << endl;
}