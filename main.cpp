#include "tubes.h"

int main() {
    ListP LP;
    CreateListP(LP);
    dummyData(LP);

    int pilihan = -1;

    while (pilihan != 0) {
        showMenu();
        cin >> pilihan;
        string merk;
        address_P merkP;
        string namaModel;
        string namaMerk;
        address_C modelP;


        if (pilihan == 1) { // Tambah Merk
            string merk;
            cout << "Masukkan nama merk: ";
            cin >> merk;
            insertParent(LP, alokasiP(merk));
            cout << "Merk berhasil ditambahkan." << endl;

        } else if (pilihan == 2) { // Tambah Model
            string merk, namaModel;
            int stok;
            cout << "Masukkan nama merk: ";
            cin >> merk;
            cout << "Masukkan nama model: ";
            cin >> namaModel;
            cout << "Masukkan stok: ";
            cin >> stok;
            insertChild(LP, alokasiC({namaModel, stok}), merk);
            cout << "Model berhasil ditambahkan." << endl;

        } else if (pilihan == 3) { // Hapus Merk
            string merk;
            cout << "Masukkan nama merk yang akan dihapus: ";
            cin >> merk;
            deleteParent(LP, merk);

        } else if (pilihan == 4) { // Hapus Model
            string merk, namaModel;
            cout << "Masukkan nama merk: ";
            cin >> merk;
            cout << "Masukkan nama model: ";
            cin >> namaModel;
            deleteChild(LP, merk, namaModel);
            cout << "Model berhasil dihapus." << endl;

        } else if (pilihan == 5) { // Update Merk
            string namaLama, namaBaru;
            cout << "Masukkan nama merk yang ingin diupdate: ";
            cin >> namaLama;
            address_P P = searchP(LP, namaLama);
            if (P != Nil) {
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                updateParent(LP, P, namaBaru);
                cout << "Merk berhasil diupdate." << endl;
            } else {
                cout << "Merk tidak ditemukan!" << endl;
            }

        } else if (pilihan == 6) { // Update Model
            string merk, namaModel, namaModelBaru;
            int stokBaru;
            cout << "Masukkan nama merk: ";
            cin >> merk;
            cout << "Masukkan nama model: ";
            cin >> namaModel;
            address_C C = searchC(LP, merk, namaModel);
            if (C != Nil) {
                cout << "Masukkan nama model baru: ";
                cin >> namaModelBaru;
                cout << "Masukkan stok baru: ";
                cin >> stokBaru;
                updateChild(LP, C, merk, namaModelBaru, stokBaru);
                cout << "Model berhasil diupdate." << endl;
            } else {
                cout << "Model tidak ditemukan!" << endl;
            }

        } else if (pilihan == 7) { // Tampilkan Semua Merk dan Model
            showChild(LP);

        } else if (pilihan == 8) { // Hitung Jumlah Model
            cout << "Jumlah total model: " << countChild(LP) << endl;

        } else if (pilihan == 0) { // Keluar
            cout << "Program selesai. Terima kasih!" << endl;

        } else if (pilihan == 9) {
            cout << "Masukkan Merk:" << endl;
            cin >> merk;
            merkP = searchP(LP, merk);
            if (findParent(merkP) == true){
                cout << "Merk Tersedia" << endl;
            }else{
                cout << "Merk Tidak Tersedia" << endl;
            }

        } else if (pilihan == 10) {
            cout << "masukkan Merek"<<endl;
            cin >> namaMerk;

            if (searchP(LP,namaMerk)==Nil){
                cout << "Merk TIdak di Temukan" << endl;
            }else{
                cout << "masukkan Model" << endl;
                cin >> namaModel;
                modelP = searchC(LP,namaMerk,namaModel);
                if (findChild(modelP)!= false){
                    cout << "Model Ditemukan" << endl;
                    cout << "stok: " << info(modelP).stok_model << endl;
                }else{
                    cout << "Model tidak ditemukan!!"<< endl;
                }
            }

        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
