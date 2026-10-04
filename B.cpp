#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
};
struct Node {
    Mahasiswa info;
    Node *next;
};

typedef Node* address;

struct List {
    address First;
};

void createList(List &L);
address createNode(string nim, string nama, float persentase);
void insertLast(List &L, address P);
address searchByNIM(List L, string nim);
bool updateKehadiran(address P, float persentaseBaru);
void printList(List L);


void createList(List &L) {
    L.First = nullptr;
}

address createNode(string nim, string nama, float persentase) {
    address P = new Node;
    P->info.nim = nim;
    P->info.nama = nama;
    P->info.persentaseKehadiran = persentase;
    P->next = nullptr;
    return P;
}
void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
    } else {
        address Last = L.First;
        while (Last->next != nullptr) {
            Last = Last->next;
        }
        Last->next = P;
    }
}
address searchByNIM(List L, string nim) {
    address P = L.First;
    address found = nullptr;
    
    while (P != nullptr && found == nullptr) {
        if (P->info.nim == nim) {
            found = P;
        } else {
            P = P->next;
        }
    }
    return found;
}
bool updateKehadiran(address P, float persentaseBaru) {
    if (P != nullptr) {
        P->info.persentaseKehadiran = persentaseBaru;
        return true;
    }
    return false;
}
void printList(List L) {
    address P = L.First;
    int i = 1; 
    cout << "=== DAFTAR MAHASISWA (SINGLE LINKED LIST) ===" << endl;
    while (P != nullptr) {
        cout << i++ << ". " << P->info.nim << " | " 
             << P->info.nama << " | " 
             << P->info.persentaseKehadiran << "%" << endl;
        P = P->next;
    }
    cout << "Total Mahasiswa: " << i - 1 << endl << endl;
}
int main() {
    List L;
    createList(L);
    Mahasiswa dataMhs[] = {
        {"103012400196", "ZHAFRAN LINKY SISWARA", 100},
        {"103012400278", "GANDA SETYA RAMADHANA", 50},
        {"103012400406", "MUHAMMAD ABRAR SINURAT", 100},
        {"103012500025", "FARID ALVARO SITEPU", 100},
        {"103012500037", "CHARLES NATHAN MARCELINO", 100},
        {"103012500038", "ARYA AWAL ADRIANSYAH", 100},
        {"103012500044", "MUHAMMAD ANDHIKA BAGASKOR", 100},
        {"103012500055", "MOCHAMAD RIZKYKA ZAINAL R", 100},
        {"103012500071", "NAYLA FAUZYA KHAIRUNNISA", 100},
        {"103012500072", "NAYAGA RADITHYA", 100},
        {"103012500078", "RILLO RAIHAN DWI SATRIA", 100},
        {"103012500088", "AL FATHIR ABIMANYU GAZAAL", 100},
        {"103012500092", "MUHAMMAD DZAKI LUKMANUL H", 100},
        {"103012500099", "SAMUEL DIPTA YOGI TARUNA", 100},
        {"103012500104", "AHMAD DHANI NUR RIDWAN", 100},
        {"103012500158", "MUHAMMAD RAFIKI HANNAN", 100},
        {"103012500217", "AHMAD RADHIN PRADITYA", 100},
        {"103012500226", "MAULANA NAUFAL MAHRUS", 100},
        {"103012500236", "NABILA NURUL ALIFAH", 50},
        {"103012500243", "ABIDZAR ALGHIFARI", 100},
        {"103012500266", "REVAN PUTRA ANDRIAN", 100},
        {"103012500276", "TSANIA RAHMA HALIZA", 100},
        {"103012500295", "LAZHI NADRI RAMADHAN", 100},
        {"103012500304", "MUHAMMAD ZEIN", 50},
        {"103012500315", "NABILA SYAKIRA ANDRIANI S", 100},
        {"103012500325", "MUHAMMAD GHASSAN FIRDIAN", 100},
        {"103012500331", "NUGRAHA AKMAL YOGA", 100},
        {"103012500339", "RIFQI BHADRIKA ADWITIYA", 100},
        {"103012500349", "FAUZAN NUR ABDILLAH", 100},
        {"103012500389", "ANINDA MARETHANINGTYAS CE", 100},
        {"103012500397", "LUKMAN HAKIM", 100},
        {"103012530009", "RAYYA IZZATUL MILA", 100},
        {"103012530017", "RADEN HASBI RADHITYA NATA", 100},
        {"103012530021", "RAYHAN MUZAB FAUZAN", 100},
        {"103012530033", "GAZA RAUSHAN FIKRI", 50},
        {"103012530040", "RAYYAN NAKHLAH PRAYATA", 100},
        {"103012530045", "IMAN ABDI ILAHI", 100},
        {"103012530055", "DUNCAN AGASTYA KURNIAWAN", 100},
        {"1301213218",   "ADAM TEGUH MAULAANAA", 50},
        {"1301223394",   "RAFLI NUJJIYA MAULANA", 50}
    };
    for (int i = 0; i < 40; i++) {
        address P = createNode(dataMhs[i].nim, dataMhs[i].nama, dataMhs[i].persentaseKehadiran);
        insertLast(L, P);
    }
    printList(L);
    string cariNIM;
    cout << "--- PENCARIAN MAHASISWA ---" << endl;
    cout << "Masukkan NIM yang dicari: ";
    cin >> cariNIM;
    address ptrMahasiswa = searchByNIM(L, cariNIM);
    if (ptrMahasiswa != nullptr) {
        cout << "\n[Data Ditemukan di Linked List]" << endl;
        cout << "NIM       : " << ptrMahasiswa->info.nim << endl;
        cout << "Nama      : " << ptrMahasiswa->info.nama << endl;
        cout << "Kehadiran : " << ptrMahasiswa->info.persentaseKehadiran << "%" << endl << endl;
        cout << "UPDATE DATA MAHASISWA" << endl;
        float persentaseBaru;
        cout << "Masukkan persentase kehadiran baru: ";
        cin >> persentaseBaru;
        updateKehadiran(ptrMahasiswa, persentaseBaru);
        cout << "Update data berhasil!" << endl << endl;
        cout << "=== DATA SETELAH UPDATE ===" << endl;
        cout << "NIM       : " << ptrMahasiswa->info.nim << endl;
        cout << "Nama      : " << ptrMahasiswa->info.nama << endl;
        cout << "Kehadiran : " << ptrMahasiswa->info.persentaseKehadiran << "%" << endl;
    } else {
        cout << "\nMahasiswa dengan NIM " << cariNIM << " tidak ditemukan!" << endl;
    }
    return 0;
}