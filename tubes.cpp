#include "tubes.h"

void CreateListP(ListP &LP) {
    first(LP) = Nil;
    last(LP) = Nil;
}

address_P alokasiP(infotypeP X) {
    address_P p = new elemen_P;
    info(p) = X;
    firstC(p) = Nil;
    next(p) = Nil;
    prev(p) = Nil;
    return p;
}

address_C alokasiC(infotypeC X) {
    address_C p = new elemen_C;
    info(p) = X;
    next(p) = Nil;
    return p;
}

address_P searchP(ListP LP, string namaMerk) {
    address_P PParent = first(LP);
    while (PParent != Nil) {
        if (info(PParent) == namaMerk) {
            return PParent;
        }
        PParent = next(PParent);
    }
    return Nil;
}

address_C searchC(ListP LP, string namaMerk, string namaModel) {
    address_P PParent = searchP(LP, namaMerk);
    if (PParent == Nil) {
        return Nil;
    } else {
        address_C PChild = firstC(PParent);
        while (PChild != Nil) {
            if (info(PChild).nama_model == namaModel) {
                return PChild;
            }
            PChild = next(PChild);
        }
        return Nil;
    }
}

bool findParent(address_P PParent) {
    return PParent != Nil;
}

bool findChild(address_C PChild) {
    return PChild != Nil;
}

void insertParent(ListP &LP, address_P PParent) {
    if (searchP(LP, info(PParent)) == Nil) {
        if (first(LP) == Nil) {
            first(LP) = PParent;
            last(LP) = PParent;
        } else {
            next(PParent) = first(LP);
            prev(first(LP)) = PParent;
            first(LP) = PParent;
        }
    } else {
        cout << "Merk sudah tersedia" << endl;
    }
}

void insertChild(ListP &LP, address_C PChild, string merk) {
    address_P PParent = searchP(LP, merk);
    if (PParent != Nil) {
        if (searchC(LP, merk, info(PChild).nama_model) == Nil) {
            if (firstC(PParent) == Nil) {
                firstC(PParent) = PChild;
            } else {
                next(PChild) = firstC(PParent);
                firstC(PParent) = PChild;
            }
        } else {
            cout << "Model sudah tersedia" << endl;
        }
    } else {
        cout << "Merk tidak ditemukan" << endl;
    }
}

void deleteParent(ListP &LP, infotypeP x) {
    address_P PParent = searchP(LP, x);
    if (PParent == Nil) {
        cout << "Merk tidak ditemukan!" << endl;
    } else {
        deleteAllChild(LP, PParent); 
        if (PParent == first(LP) && PParent == last(LP)) {
            first(LP) = Nil;
            last(LP) = Nil;
        } else if (PParent == first(LP)) {
            first(LP) = next(PParent);
            prev(first(LP)) = Nil;
        } else if (PParent == last(LP)) {
            last(LP) = prev(PParent);
            next(last(LP)) = Nil;
        } else {
            next(prev(PParent)) = next(PParent);
            prev(next(PParent)) = prev(PParent);
        }
        delete PParent;
        cout << "Merk berhasil dihapus." << endl;
    }
}

// 🧠 LOGIC YANG GUE IMPROVE: Two-Pointer Traversal
void deleteChild(ListP &LP, string merk, string model) {
    address_P PParent = searchP(LP, merk);
    if (PParent == Nil || firstC(PParent) == Nil) {
        cout << "Merk atau Model Kosong" << endl;
        return;
    }

    address_C curr = firstC(PParent);
    address_C prev = Nil;

    // Jalan nyari nodenya
    while (curr != Nil && info(curr).nama_model != model) {
        prev = curr;
        curr = next(curr);
    }

    if (curr == Nil) {
        cout << "Model tidak ditemukan di merk ini!" << endl;
        return;
    }

    // Kalau nodenya ketemu di paling depan
    if (prev == Nil) {
        firstC(PParent) = next(curr);
    } else {
        // Kalau nodenya di tengah atau belakang
        next(prev) = next(curr);
    }

    next(curr) = Nil;
    delete curr;
}

void deleteAllChild(ListP &LP, address_P PParent) {
    address_C QChild = firstC(PParent);
    while (QChild != Nil) {
        address_C PChild = QChild;
        QChild = next(QChild);
        delete PChild;
    }
    firstC(PParent) = Nil;
}

void showParent(ListP LP) {
    address_P PParent = first(LP);
    if (PParent == Nil) {
        cout << "List Parent Kosong!" << endl;
    } else {
        cout << "Daftar Merk (Parent):" << endl;
        while (PParent != Nil) {
            cout << "- " << info(PParent) << endl;
            PParent = next(PParent);
        }
    }
}

void showChild(ListP LP) {
    address_P PParent = first(LP);
    if (PParent == Nil) {
        cout << "List Kosong!" << endl;
    } else {
        while (PParent != Nil) {
            cout << "Merk: " << info(PParent) << endl;
            address_C PChild = firstC(PParent);
            if (PChild == Nil) {
                cout << "   - Tidak ada model" << endl;
            } else {
                cout << "   Daftar Model:" << endl;
                while (PChild != Nil) {
                    cout << "   - " << info(PChild).nama_model
                         << " | Stok: " << info(PChild).stok_model << endl;
                    PChild = next(PChild);
                }
            }
            PParent = next(PParent);
        }
    }
}

void updateParent(ListP &LP, address_P PParent, string merkBaru) {
    info(PParent) = merkBaru;
}

void updateChild(ListP &LP, address_C PChild, string merk, string namaModelBaru, int stokBaru) {
    info(PChild).nama_model = namaModelBaru;
    info(PChild).stok_model = stokBaru;
}

int countChild(ListP LP) {
    address_P PParent = first(LP);
    int i = 0;
    while (PParent != Nil) {
        address_C PChild = firstC(PParent);
        while (PChild != Nil) {
            i++;
            PChild = next(PChild);
        }
        PParent = next(PParent);
    }
    return i;
}

void dummyData(ListP &LP) {
    insertParent(LP, alokasiP("Samsung"));
    insertParent(LP, alokasiP("Apple"));
    insertParent(LP, alokasiP("LG"));
    insertParent(LP, alokasiP("Nvidia"));
    insertParent(LP, alokasiP("Ambatron"));

    insertChild(LP, alokasiC({"S_22_Ultra", 10}), "Samsung");
    insertChild(LP, alokasiC({"Fold_X", 20}), "Samsung");
    insertChild(LP, alokasiC({"Iphone_16_Pro_Max", 99}), "Apple");
    insertChild(LP, alokasiC({"Model_Z1", 25}), "LG");
    insertChild(LP, alokasiC({"Model_Z2", 30}), "LG");
    insertChild(LP, alokasiC({"Model_Z3", 35}), "LG");
    insertChild(LP, alokasiC({"Ngawi_001", 911}), "Ambatron");
}

void showMenu() {
    cout << "\n========= WELCOME TO KURNIA SARI SHOP =========" << endl;
    // Bye bye Tahu Isi dan Bakwan wkwk
    cout << "1. Tambah Merk" << endl; 
    cout << "2. Tambah Model" << endl;
    cout << "3. Hapus Merk" << endl;
    cout << "4. Hapus Model" << endl;
    cout << "5. Update Merk" << endl;
    cout << "6. Update Model" << endl;
    cout << "7. Tampilkan Semua Merk dan Model" << endl;
    cout << "8. Hitung Jumlah Seluruh Model" << endl;
    cout << "9. Mencari Merk" << endl;
    cout << "10. Mencari Model" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
}
