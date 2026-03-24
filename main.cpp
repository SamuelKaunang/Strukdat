#include "tubes.h"

int main() {
    ListP LP;
    CreateListP(LP);
    dummyData(LP);

    int pilihan = -1;

    while (pilihan != 0) {
        showMenu();
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        string merk, namaModel, namaMerk;
        address_P merkP;
        address_C modelP;

        if (pilihan == 1) { 
            cout << "Masukkan nama merk: ";
            cin >> ws; getline(cin, merk);
            insertParent(LP, alokasiP(merk));
            cout << "Merk berhasil ditambahkan." << endl;

        } else if (pilihan == 2) { 
            int stok;
            cout << "Masukkan nama merk: ";
            cin >> ws; getline(cin, merk);
            cout << "Masukkan nama model: ";
            cin >> ws; getline(cin, namaModel);
            cout << "Masukkan stok: ";
            cin >> stok;
            insertChild(LP, alokasiC({namaModel, stok}), merk);
            cout << "Model berhasil ditambahkan." << endl;

        } else if (pilihan == 3) { 
            cout << "Masukkan nama merk yang akan dihapus: ";
            cin >> ws; getline(cin, merk);
            deleteParent(LP, merk);

        } else if (pilihan == 4) { 
            cout << "Masukkan nama merk: ";
            cin >> ws; getline(cin, merk);
            cout << "Masukkan nama model: ";
            cin >> ws; getline(cin, namaModel);
            deleteChild(LP, merk, namaModel);
            cout << "Eksekusi hapus selesai." << endl;

        } else if (pilihan == 5) { 
            string namaLama, namaBaru;
            cout << "Masukkan nama merk yang ingin diupdate: ";
            cin >> ws; getline(cin, namaLama);
            address_P P = searchP(LP, namaLama);
            if (P != Nil) {
                cout << "Masukkan nama baru: ";
                cin >> ws; getline(cin, namaBaru);
                updateParent(LP, P, namaBaru);
                cout << "Merk berhasil diupdate." << endl;
            } else {
                cout << "Merk tidak ditemukan!" << endl;
            }

        } else if (pilihan == 6) { 
            string namaModelBaru;
            int stokBaru;
            cout << "Masukkan nama merk: ";
            cin >> ws; getline(cin, merk);
            cout << "Masukkan nama model: ";
            cin >> ws; getline(cin, namaModel);
            address_C C = searchC(LP, merk, namaModel);
            if (C != Nil) {
                cout << "Masukkan nama model baru: ";
                cin >> ws; getline(cin, namaModelBaru);
                cout << "Masukkan stok baru: ";
                cin >> stokBaru;
                updateChild(LP, C, merk, namaModelBaru, stokBaru);
                cout << "Model berhasil diupdate." << endl;
            } else {
                cout << "Model tidak ditemukan!" << endl;
            }

        } else if (pilihan == 7) { 
            showChild(LP);

        } else if (pilihan == 8) { 
            cout << "Jumlah total model: " << countChild(LP) << endl;

        } else if (pilihan == 9) {
            cout << "Masukkan Merk: ";
            cin >> ws; getline(cin, merk);
            merkP = searchP(LP, merk);
            if (findParent(merkP)) {
                cout << "Merk Tersedia" << endl;
            } else {
                cout << "Merk Tidak Tersedia" << endl;
            }

        } else if (pilihan == 10) {
            cout << "Masukkan Merek: ";
            cin >> ws; getline(cin, namaMerk);

            if (searchP(LP, namaMerk) == Nil) {
                cout << "Merk Tidak di Temukan" << endl;
            } else {
                cout << "Masukkan Model: ";
                cin >> ws; getline(cin, namaModel);
                modelP = searchC(LP, namaMerk, namaModel);
                if (findChild(modelP)) {
                    cout << "Model Ditemukan" << endl;
                    cout << "Stok: " << info(modelP).stok_model << endl;
                } else {
                    cout << "Model tidak ditemukan!!" << endl;
                }
            }
        } else if (pilihan == 0) {
            cout << "Program selesai. Terima kasih!" << endl;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
