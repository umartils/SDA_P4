
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// deklarasi struct
struct buah
{
    string nama;
    string warna;
    float berat;
    int harga;
    string rasa;
    // pointer untuk menghubungkan node
    buah *next;
};
buah *head, *tail, *nodeSekarang, *nodeBaru, *temporaryNode;

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

int main()
{
    cout << "\nHasil Linked List\n";
    cout << "====================================================";
    waktuLinkedList();
    cout << "====================================================";

    return 0;
}

void buatSingleLinkedList(string nama, string warna, float berat, int harga, string rasa)
{
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
void masukanNodeKeAwal(string nama, string warna, float berat, int harga, string rasa)
{
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
void masukanNodeKeAkhir(string nama, string warna, float berat, int harga, string rasa)
{
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
void rubahDataNodePertama(string nama, string warna, float berat, int harga, string rasa)
{
    head->nama = nama;
    head->warna = warna;
    head->berat = berat;
    head->harga = harga;
    head->rasa = rasa;
}
// fungsi rubah data node terakhir
void rubahDataNodeTerakhir(string nama, string warna, float berat, int harga, string rasa)
{
    // ubah data node terakhir
    tail->nama = nama;
    tail->warna = warna;
    tail->berat = berat;
    tail->harga = harga;
    tail->rasa = rasa;
}
// fungsi hapus node pertama
void hapusNodePertama()
{
    // simpan node head ke node sementara
    temporaryNode = head;
    // node head diganti dengan node selanjutnya
    head = head->next;
    delete temporaryNode;
}
// fungsi hapus node terakhir
void hapusNodeTerakhir()
{
    // simpan node tail ke node sementara
    temporaryNode = tail;
    // mencari nodetail
    // pencarian dimulai dari head
    nodeSekarang = head;
    while (nodeSekarang->next != NULL)
    {
        // jika node sekarang itu next nodenya adalah tail
        // eksekusi
        if (nodeSekarang->next == tail)
        {
            // node sekarang jadi tail
            // dengan membuah next dari node sekarang menjadi null bukan ke node lain
            nodeSekarang->next = NULL;
            // maka tail dirubah node sekarang
            tail = nodeSekarang;
        }
        else
        {
            // jika tidak maka current Node diganti dengan node selanjutnya
            nodeSekarang = nodeSekarang->next;
        }
    }
    delete temporaryNode;
}
// fungsi cetak linked list
void cetakSingleLinkedList()
{
    // dimulai dari node head
    nodeSekarang = head;
    while (nodeSekarang != NULL)
    {
        cout << nodeSekarang->nama << " >> ";
        // geser ke node selanjutnya
        nodeSekarang = nodeSekarang->next;
    }
    cout << "!!\n";
}
// fungsi cetak seluruh data node linked list
void cetakSeluruhAtributNode()
{
    // dimulai dari node head
    nodeSekarang = head;
    while (nodeSekarang != NULL)
    {
        cout << "Nama: " << nodeSekarang->nama << endl;
        cout << "Warna: " << nodeSekarang->warna << endl;
        cout << "Berat: " << nodeSekarang->berat << endl;
        cout << "Harga: " << nodeSekarang->harga << endl;
        cout << "Rasa: " << nodeSekarang->rasa << endl;
        cout << endl;
        nodeSekarang = nodeSekarang->next;
    }
}

void cetakLinkedList()
{

    cout << endl
         << "01. Membuat Node Pertama:" << endl;
    buatSingleLinkedList("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleLinkedList(); // menampilkan node

    cout << endl
         << "02. Menambahkan node pada posisi awal:" << endl;
    masukanNodeKeAwal("Pisang", "Kuning", 1.3, 8000, "Manis");
    cetakSingleLinkedList(); // menampilkan node

    cout << endl
         << "03. Menambahkan node pada posisi akhir:" << endl;
    masukanNodeKeAkhir("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleLinkedList(); // menampilkan node

    cout << endl
         << "04. Menambahkan node pada posisi awal lagi:" << endl;
    masukanNodeKeAwal("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleLinkedList(); // menampilkan node

    cout << endl
         << "05. menghapus node pada posisi awal:" << endl;
    hapusNodePertama();
    cetakSingleLinkedList();

    cout << endl
         << "06. menghapus node pada posisi akhir:" << endl;
    hapusNodeTerakhir();
    cetakSingleLinkedList();

    cout << endl
         << "07. menghapus node pada posisi akhir:" << endl;
    hapusNodeTerakhir();
    cetakSingleLinkedList();

    cout << endl
         << "08. Menambahkan node pada posisi awal:" << endl;
    masukanNodeKeAwal("Apel", "Merah", 2.1, 13000, "Manis");
    cetakSingleLinkedList();

    cout << endl
         << "09. Merubah node pada posisi awal:" << endl;
    rubahDataNodePertama("Anggur", "Ungu", 1, 9000, "Manis");
    cetakSingleLinkedList();

    cout << endl
         << "10. Merubah node pada posisi akhir:" << endl;
    rubahDataNodeTerakhir("Mangga", "Jingga", 1.1, 10000, "Manis");
    cetakSingleLinkedList();

    cout << endl
         << "11. Mencetak seluruh atribut pada node:" << endl;
    cetakSeluruhAtributNode();
}

void waktuLinkedList()
{
    auto start_time_A = chrono::high_resolution_clock::now();
    cetakLinkedList();
    auto end_time_A = chrono::high_resolution_clock::now();
    auto duration_A = chrono::duration_cast<chrono::microseconds>(end_time_A - start_time_A);

    cout << "\nWaktu eksekusi linked list: " << duration_A.count() << " ms" << endl;
  
}
