#include <iostream>
#include <string>
using namespace std;

// Struktur untuk node dalam linked list
struct Mahasiswa
{
    string NIM;
    string nama;
    float nilai;
    Mahasiswa *lanjutkanBOSSSS;
};

// Fungsi untuk menambah data ke linked list secara terurut
void tambahMahasiswa(Mahasiswa *&head, string NIM, string nama, float nilai)
{
    Mahasiswa *newNode = new Mahasiswa{NIM, nama, nilai, nullptr};

    // Jika list kosong atau nilai lebih kecil dari nilai head, maka jadi head baru
    if (!head || nilai < head->nilai)
    {
        newNode->lanjutkanBOSSSS = head;
        head = newNode;
    }
    else
    {
        Mahasiswa *temp = head;
        while (temp->lanjutkanBOSSSS && temp->lanjutkanBOSSSS->nilai < nilai)
        {
            temp = temp->lanjutkanBOSSSS;
        }
        newNode->lanjutkanBOSSSS = temp->lanjutkanBOSSSS;
        temp->lanjutkanBOSSSS = newNode;
    }
}

// Fungsi untuk menampilkan data dengan nilai tertentu
void tampilkanDataDenganNilai(Mahasiswa *head, float nilai)
{
    Mahasiswa *temp = head;
    bool found = false;
    while (temp)
    {
        if (temp->nilai == nilai)
        {
            cout << "NIM: " << temp->NIM << ", Nama: " << temp->nama << ", Nilai: " << temp->nilai << endl;
            found = true;
        }
        temp = temp->lanjutkanBOSSSS;
    }
    if (!found)
    {
        cout << "Tidak ada data dengan nilai " << nilai << endl;
    }
}

// Fungsi untuk menampilkan seluruh data
void tampilkanSeluruhData(Mahasiswa *head)
{
    Mahasiswa *temp = head;
    while (temp)
    {
        cout << "NIM: " << temp->NIM << ", Nama: " << temp->nama << ", Nilai: " << temp->nilai << endl;
        temp = temp->lanjutkanBOSSSS;
    }
}

// Fungsi untuk menghapus data dengan NIM tertentu
void hapusDataDenganNIM(Mahasiswa *&head, string NIM)
{
    Mahasiswa *temp = head;
    Mahasiswa *prev = nullptr;

    while (temp && temp->NIM != NIM)
    {
        prev = temp;
        temp = temp->lanjutkanBOSSSS;
    }

    if (!temp)
    {
        cout << "Data dengan NIM " << NIM << " tidak ditemukan." << endl;
        return;
    }

    if (!prev)
    {
        head = temp->lanjutkanBOSSSS;
    }
    else
    {
        prev->lanjutkanBOSSSS = temp->lanjutkanBOSSSS;
    }

    delete temp;
    cout << "Data dengan NIM " << NIM << " berhasil dihapus." << endl;
}

// Fungsi untuk menghitung nilai rata-rata kelas
float hitungRataRata(Mahasiswa *head)
{
    Mahasiswa *temp = head;
    float totalNilai = 0;
    int jumlahMahasiswa = 0;

    while (temp)
    {
        totalNilai += temp->nilai;
        jumlahMahasiswa++;
        temp = temp->lanjutkanBOSSSS;
    }

    if (jumlahMahasiswa == 0)
        return 0;
    return totalNilai / jumlahMahasiswa;
}

// Program utama
int main()
{
    Mahasiswa *head = nullptr;
    int pilihan;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data dengan Nilai 90\n";
        cout << "3. Tampilkan Seluruh Data\n";
        cout << "4. Hapus Data dengan NIM 2007140022\n";
        cout << "5. Hitung Rata-Rata Kelas\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            string NIM, nama;
            float nilai;
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            tambahMahasiswa(head, NIM, nama, nilai);
        }
        else if (pilihan == 2)
        {
            tampilkanDataDenganNilai(head, 90);
        }
        else if (pilihan == 3)
        {
            tampilkanSeluruhData(head);
        }
        else if (pilihan == 4)
        {
            hapusDataDenganNIM(head, "2007140022");
        }
        else if (pilihan == 5)
        {
            float rataRata = hitungRataRata(head);
            cout << "Nilai rata-rata kelas: " << rataRata << endl;
        }
    } while (pilihan != 6);

    return 0;
}
