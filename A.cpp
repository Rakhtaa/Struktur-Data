#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const int N = 40;

    // 1. Inisialisasi Data 40 Mahasiswa
    string nama[N] = {
        "ZHAFRAN LINKY SISWARA", "GANDA SETYA RAMADHANA", "MUHAMMAD ABRAR SINURAT", "FARID ALVARO SITEPU", "CHARLES NATHAN MARCELINO",
        "ARYA AWAL ADRIANSYAH", "MUHAMMAD ANDHIKA BAGASKOR", "MOCHAMAD RIZKYKA ZAINAL R", "NAYLA FAUZYA KHAIRUNNISA", "NAYAGA RADITHYA",
        "RILLO RAIHAN DWI SATRIA", "AL FATHIR ABIMANYU GAZAAL", "MUHAMMAD DZAKI LUKMANUL H", "SAMUEL DIPTA YOGI TARUNA", "AHMAD DHANI NUR RIDWAN",
        "MUHAMMAD RAFIKI HANNAN", "AHMAD RADHIN PRADITYA", "MAULANA NAUFAL MAHRUS", "NABILA NURUL ALIFAH", "ABIDZAR ALGHIFARI",
        "REVAN PUTRA ANDRIAN", "TSANIA RAHMA HALIZA", "LAZHI NADRI RAMADHAN", "MUHAMMAD ZEIN", "NABILA SYAKIRA ANDRIANI S",
        "MUHAMMAD GHASSAN FIRDIAN", "NUGRAHA AKMAL YOGA", "RIFQI BHADRIKA ADWITIYA", "FAUZAN NUR ABDILLAH", "ANINDA MARETHANINGTYAS CE",
        "LUKMAN HAKIM", "RAYYA IZZATUL MILA", "RADEN HASBI RADHITYA NATA", "RAYHAN MUZAB FAUZAN", "GAZA RAUSHAN FIKRI",
        "RAYYAN NAKHLAH PRAYATA", "IMAN ABDI ILAHI", "DUNCAN AGASTYA KURNIAWAN", "ADAM TEGUH MAULAANAA", "RAFLI NUJJIYA MAULANA"
    };
    
    string nim[N] = {
        "103012400196", "103012400278", "103012400406", "103012500025", "103012500037",
        "103012500038", "103012500044", "103012500055", "103012500071", "103012500072",
        "103012500078", "103012500088", "103012500092", "103012500099", "103012500104",
        "103012500158", "103012500217", "103012500226", "103012500236", "103012500243",
        "103012500266", "103012500276", "103012500295", "103012500304", "103012500315",
        "103012500325", "103012500331", "103012500339", "103012500349", "103012500389",
        "103012500397", "103012530009", "103012530017", "103012530021", "103012530033",
        "103012530040", "103012530045", "103012530055", "1301213218",   "1301223394"
    };


    float persentaseKehadiran[N] = {
        100, 50, 100, 100, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 100, 100, 100, 100, 50, 100,
        100, 100, 100, 50, 100, 100, 100, 100, 100, 100,
        100, 100, 100, 100, 50, 100, 100, 100, 50, 50
    };

    // 2. Traversal/Tampilkan Data
    cout << "=== DAFTAR MAHASISWA (ARRAY BIASA) ===" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << nim[i] << " | " << nama[i] << " | " << persentaseKehadiran[i] << "%" << endl;
    }
    cout << "Total Mahasiswa: " << N << endl << endl;

    // 3. Fitur Pencarian berdasarkan NIM
    string cariNIM;
    cout << "--- PENCARIAN MAHASISWA ---" << endl;
    cout << "Masukkan NIM yang dicari: ";
    cin >> cariNIM;

    int idxKetemu = -1;
    for (int i = 0; i < N; i++) {
        if (nim[i] == cariNIM) {
            idxKetemu = i;
            break;
        }
    }

    if (idxKetemu != -1) {
        cout << "Data Ditemukan:" << endl;
        cout << "NIM        : " << nim[idxKetemu] << endl;
        cout << "Nama       : " << nama[idxKetemu] << endl;
        cout << "Kehadiran  : " << persentaseKehadiran[idxKetemu] << "%" << endl << endl;

        // 4. Fitur Update Data
        cout << "--- UPDATE DATA MAHASISWA ---" << endl;
        float persentaseBaru;
        cout << "Masukkan persentase kehadiran baru: ";
        cin >> persentaseBaru;

        persentaseKehadiran[idxKetemu] = persentaseBaru;
        cout << "Update berhasil!" << endl << endl;

        // 5. Tampilkan Data Setelah Update
        cout << "=== DATA SETELAH UPDATE ===" << endl;
        cout << idxKetemu + 1 << ". " << nim[idxKetemu] << " | " << nama[idxKetemu] << " | " << persentaseKehadiran[idxKetemu] << "%" << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << cariNIM << " tidak ditemukan!" << endl;
    }

    return 0;
}