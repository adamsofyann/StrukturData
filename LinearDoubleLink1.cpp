#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string NIM;
    char gender;
    float nilai;
    Mahasiswa* next;
};

// Fungsi untuk menambah data ke circular linked list secara terurut berdasarkan NIM
void insertData(Mahasiswa*& head, string nama, string NIM, char gender, float nilai) {
    Mahasiswa* newNode = new Mahasiswa{nama, NIM, gender, nilai, nullptr};

    // Jika list kosong, newNode menjadi node pertama dan menunjuk ke dirinya sendiri
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else if (NIM < head->NIM) { // Jika NIM baru lebih kecil dari head, newNode menjadi head
        Mahasiswa* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    } else { // Sisipkan newNode di posisi yang sesuai
        Mahasiswa* current = head;
        while (current->next != head && current->next->NIM < NIM) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Fungsi untuk menghapus data berdasarkan NIM
void hapusData(Mahasiswa*& head, string NIM) {
    if (!head) {
        cout << "List kosong. Tidak ada data yang dapat dihapus.\n";
        return;
    }

    Mahasiswa* current = head;
    Mahasiswa* prev = nullptr;

    // Cari node dengan NIM yang sesuai
    do {
        if (current->NIM == NIM) break;
        prev = current;
        current = current->next;
    } while (current != head);

    if (current->NIM != NIM) { // Jika tidak ditemukan
        cout << "Data dengan NIM " << NIM << " tidak ditemukan.\n";
        return;
    }

    // Hapus node
    if (current == head && current->next == head) { // Hanya ada satu node
        head = nullptr;
    } else if (current == head) { // Hapus head
        Mahasiswa* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
    } else { // Hapus node selain head
        prev->next = current->next;
    }
    delete current;
    cout << "Data dengan NIM " << NIM << " berhasil dihapus.\n";
}

// Fungsi untuk mencetak seluruh data dalam linked list
void cetakData(Mahasiswa* head) {
    if (!head) {
        cout << "List kosong.\n";
        return;
    }
    Mahasiswa* temp = head;
    do {
        cout << "NIM: " << temp->NIM << ", Nama: " << temp->nama
             << ", Gender: " << temp->gender << ", Nilai: " << temp->nilai << endl;
        temp = temp->next;
    } while (temp != head);
}

// Program utama dengan menu
int main() {
    Mahasiswa* head = nullptr;
    int pilihan;

    do {
        cout << "\n     CIRCULAR LINKED LIST     \n";
        cout << "==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1 – 4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama, NIM;
            char gender;
            float nilai;
            cout << "Masukkan Nama: "; cin.ignore(); getline(cin, nama);
            cout << "Masukkan NIM: "; cin >> NIM;
            cout << "Masukkan Gender (L/P): "; cin >> gender;
            cout << "Masukkan Nilai: "; cin >> nilai;
            insertData(head, nama, NIM, gender, nilai);
        } else if (pilihan == 2) {
            string NIM;
            cout << "Masukkan NIM yang akan dihapus: "; cin >> NIM;
            hapusData(head, NIM);
        } else if (pilihan == 3) {
            cetakData(head);
        }
    } while (pilihan != 4);

    cout << "Program selesai.\n";
    return 0;
}
