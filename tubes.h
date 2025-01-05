#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define firstC(P) (P)->firstC
#define lastC(P) (P)->lastC
#define first(L) ((L).first)
#define last(L) ((L).last)

using namespace std;

struct model{
    string nama_model;
    int stok_model;
};

typedef model infotypeC;
typedef string infotypeP;
typedef struct elemen_P *address_P;
typedef struct elemen_C *address_C;


struct elemen_C{
/* struct ini untuk menyimpan elemen anak dan pointer penunjuk
 elemen tetangganya */
    infotypeC info;
    address_C next;
};

struct elemen_P{
/* struct ini untuk menyimpan elemen induk dan pointer penunjuk
 elemen tetangganya */
    infotypeP info;
    address_C firstC;
    address_P next;
    address_P prev;
};

struct ListP{
/* struct ini digunakan untuk menyimpan list induk itu sendiri */
    address_P first;
    address_P last;
};

void CreateListP(ListP &LP);

address_P alokasiP(infotypeP X);

address_C alokasiC(infotypeC X);

address_P searchP(ListP LP, string namaMerk);

address_C searchC(ListP LP, string namaMerk, string namaModel);

bool findParent(address_P PParent);

bool findChild(address_C PChild);

void insertParent(ListP &LP, address_P PParent);

void insertChild(ListP &LP, address_C PChild, string merk);

void deleteParent(ListP &LP, infotypeP x);

void deleteChild(ListP &LP, string merk, string model);

void deleteAllChild(ListP &LP, address_P PParent);

void showParent(ListP LP);

void showChild(ListP LP);

void updateParent(ListP &LP, address_P PParent, string merkBaru);

void updateChild(ListP &LP, address_C PChild, string merk, string namaModelBaru, int stokBaru);

int countChild(ListP LP);

void dummyData(ListP &LP);

void showMenu();

#endif // TUBES_H_INCLUDED
